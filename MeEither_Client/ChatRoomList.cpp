#include "ChatRoomList.h"
#include "ChatWindow.h"
#include "ui_ChatRoomList.h"
#include "ClientProfile.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTcpSocket>

ChatRoomList::ChatRoomList(const QString &continent, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ChatRoomList),
    continent(continent),
    socket(new QTcpSocket(this)) {
    ui->setupUi(this);
    displayContinent();
    initializeUserInfoTable();

    socket->connectToHost("127.0.0.1", 8888);
    if (!socket->waitForConnected(3000)) {
        QMessageBox::critical(this, "서버 연결 실패", "서버에 연결할 수 없습니다.");
        socket->deleteLater();
        return;
    }

    connect(ui->createRoomButton, &QPushButton::clicked, this, &ChatRoomList::onCreateRoomButtonClicked);
    connect(ui->joinRoomButton, &QPushButton::clicked, this, &ChatRoomList::onJoinRoomButtonClicked);
    connect(socket, &QTcpSocket::readyRead, this, &ChatRoomList::onReadyRead);

    // 초기 채팅방 목록 요청
    QByteArray request = "GET_ROOMS";
    socket->write(request);
    socket->flush();
}


ChatRoomList::~ChatRoomList() {
    delete ui;
}

void ChatRoomList::displayContinent() {
    ui->continentLabel->setText("서버: " + continent);
}

void ChatRoomList::addChatRoom(const QString &roomName) {
    ui->chatRoomListWidget->addItem(roomName);
}

void ChatRoomList::onCreateRoomButtonClicked() {
    bool ok;
    QString roomName = QInputDialog::getText(this, "채팅방 만들기", "채팅방 이름:", QLineEdit::Normal, "", &ok);

    if (!ok || roomName.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "채팅방 이름을 입력하세요.");
        return;
    }

    QByteArray data;
    data.append("CREATE_ROOM|");
    data.append(roomName.toUtf8() + "|");
    data.append(continent.toUtf8());

    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        QMessageBox::critical(this, "오류", "서버 응답 대기 중 오류가 발생했습니다.");
        return;
    }

    QByteArray response = socket->readAll();
    QString responseStr = QString::fromUtf8(response);

    if (responseStr == "CREATE_ROOM_SUCCESS") {
        QMessageBox::information(this, "성공", "채팅방이 성공적으로 생성되었습니다.");
        // 서버가 자동으로 브로드캐스트하므로 클라이언트는 별도 요청 없이 목록 갱신
    } else {
        QMessageBox::warning(this, "실패", "채팅방 생성에 실패했습니다.");
    }
}


void ChatRoomList::onJoinRoomButtonClicked() {
    QListWidgetItem *selectedItem = ui->chatRoomListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "선택 오류", "채팅방을 선택하세요.");
        return;
    }

    QString selectedRoomName = selectedItem->text();
    qDebug() << "선택된 채팅방 이름:" << selectedRoomName;

    QByteArray data;
    data.append("JOIN_ROOM|");
    data.append(selectedRoomName.toUtf8());
    socket->write(data);
    socket->flush();
    qDebug() << "JOIN_ROOM 메시지 전송 완료";

    if (!socket->waitForReadyRead(3000)) {
        QMessageBox::critical(this, "오류", "서버 응답 대기 중 오류가 발생했습니다.");
        return;
    }

    QByteArray response = socket->readAll();
    QString responseStr = QString::fromUtf8(response).trimmed();
    qDebug() << "서버 응답:" << responseStr;

    if (responseStr == "JOIN_ROOM_SUCCESS") {
        qDebug() << "채팅방 입장 성공. ChatWindow 생성 중...";
        auto *chatWindow = new ChatWindow(selectedRoomName, socket, this);  // 올바른 방 이름 전달
        chatWindow->setAttribute(Qt::WA_DeleteOnClose);
        chatWindow->show();
        qDebug() << "ChatWindow show() 호출 완료";
    } else if (responseStr == "JOIN_ROOM_FAILURE") {
        QMessageBox::warning(this, "오류", "채팅방 입장에 실패했습니다.");
    }
}






void ChatRoomList::onViewProfileButtonClicked() {
    QListWidgetItem *selectedItem = ui->chatRoomListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "선택 오류", "프로필을 확인할 사용자를 선택하세요.");
        return;
    }

    QString selectedUser = selectedItem->text();
    qDebug() << "선택된 사용자:" << selectedUser;

    // ClientProfile 창 열기
    auto *clientProfile = new ClientProfile(selectedUser, nullptr); // 독립된 창 생성
    clientProfile->setAttribute(Qt::WA_DeleteOnClose);  // 창 닫을 때 자동으로 메모리 해제
    clientProfile->show();  // 독립된 창으로 열기
}

void ChatRoomList::onReadyRead() {
    QByteArray data = socket->readAll();
    QString response = QString::fromUtf8(data);

    qDebug() << "서버 비동기 응답:" << response;

    // 응답 처리: 여러 메시지가 연결된 경우 분리
    QStringList responses = response.split("\n", Qt::SkipEmptyParts);
    for (const QString &resp : responses) {
        if (resp.startsWith("UPDATE_ROOMS|")) {
            QString roomList = resp.mid(QString("UPDATE_ROOMS|").length());
            QStringList rooms = roomList.split(";", Qt::SkipEmptyParts);

            // UI 채팅방 목록 업데이트
            ui->chatRoomListWidget->clear();
            for (const QString &room : rooms) {
                ui->chatRoomListWidget->addItem(room);
            }

            qDebug() << "채팅방 목록 업데이트:" << rooms;
        } else if (resp == "CREATE_ROOM_SUCCESS") {
            qDebug() << "채팅방 생성 성공 메시지 수신";
        } else if (resp == "JOIN_ROOM_SUCCESS") {
            qDebug() << "채팅방 입장 성공. ChatWindow 생성 중...";

            // 선택된 방 이름 가져오기
            QListWidgetItem *selectedItem = ui->chatRoomListWidget->currentItem();
            if (selectedItem) {
                QString selectedRoomName = selectedItem->text();
                auto *chatWindow = new ChatWindow(selectedRoomName, socket, this);  // 올바른 방 이름 전달
                chatWindow->setAttribute(Qt::WA_DeleteOnClose);
                chatWindow->show();
                qDebug() << "ChatWindow show() 호출 완료 - 방 이름:" << selectedRoomName;
            } else {
                qDebug() << "선택된 방 이름이 없습니다.";
            }
        } else if (resp == "JOIN_ROOM_FAILURE") {
            QMessageBox::warning(this, "오류", "채팅방 입장에 실패했습니다.");
        } else if (resp.startsWith("UPDATE_CLIENTS|")) {
            QString clientsList = resp.mid(QString("UPDATE_CLIENTS|").length());
            QStringList clients = clientsList.split(";", Qt::SkipEmptyParts);

            ui->userInfoTable->setRowCount(0); // Clear existing rows

            for (const QString &client : clients) {
                QStringList details = client.split(",", Qt::SkipEmptyParts);
                if (details.size() == 3) {
                    int row = ui->userInfoTable->rowCount();
                    ui->userInfoTable->insertRow(row);

                    QTableWidgetItem *nicknameItem = new QTableWidgetItem(details[0]);
                    QTableWidgetItem *ageItem = new QTableWidgetItem(details[1]);
                    QTableWidgetItem *genderItem = new QTableWidgetItem(details[2]);

                    ui->userInfoTable->setItem(row, 0, nicknameItem);
                    ui->userInfoTable->setItem(row, 1, ageItem);
                    ui->userInfoTable->setItem(row, 2, genderItem);
                }
            }
            qDebug() << "접속자 목록 업데이트:" << clients;
        }else {
            qDebug() << "예상치 못한 응답:" << resp;
        }
    }
}

void ChatRoomList::initializeUserInfoTable() {
    ui->userInfoTable->setColumnCount(3);
    QStringList headers = {"닉네임", "나이", "성별"};
    ui->userInfoTable->setHorizontalHeaderLabels(headers);

    // Optional: Adjust column widths
    ui->userInfoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->userInfoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->userInfoTable->setSelectionBehavior(QAbstractItemView::SelectRows);
}
