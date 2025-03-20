#include "ChatWindow.h"
#include "ui_ChatWindow.h"
#include <QMessageBox>
#include "ChatWindow.h"
#include "ui_ChatWindow.h"
#include <QDebug>
#include <QMessageBox>

ChatWindow::ChatWindow(const QString &roomName, QTcpSocket *existingSocket, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ChatWindow),
    roomName(roomName),
    socket(existingSocket) {
    qDebug() << "ChatWindow 생성자 호출됨 - 방 이름:" << roomName;

    ui->setupUi(this);
    ui->headerLabel->setText("채팅방: " + roomName);

    connect(ui->sendButton, &QPushButton::clicked, this, &ChatWindow::onSendButtonClicked);
    connect(ui->leaveRoomButton, &QPushButton::clicked, this, &ChatWindow::onLeaveRoomButtonClicked);
    connect(socket, &QTcpSocket::readyRead, this, &ChatWindow::onReadyRead);

    qDebug() << "신호 연결 완료";
}


ChatWindow::~ChatWindow() {
    delete ui;
    if (socket) {
        socket->disconnectFromHost();
        socket->deleteLater();
    }
}


void ChatWindow::onSendButtonClicked() {
    QString message = ui->messageLineEdit->text().trimmed();
    if (message.isEmpty()) {
        return;
    }

    qDebug() << "채팅 메시지 전송 - 방 이름:" << roomName << ", 메시지:" << message;

    QByteArray data;
    data.append("CHAT|");
    data.append(roomName.toUtf8() + "|");
    data.append(message.toUtf8() + "\n");  // 줄바꿈 추가

    socket->write(data);
    socket->flush();

    // 전송한 메시지를 UI에 표시
    ui->chatMessagesList->addItem("나: " + message);
    ui->messageLineEdit->clear();
}

void ChatWindow::onLeaveRoomButtonClicked()
{
    // 서버에 채팅방 나가기 메시지 전송
    QByteArray data;
    data.append("LEAVE_ROOM|");
    data.append(roomName.toUtf8());
    socket->write(data);
    socket->flush();

    // 소켓 연결 종료
    socket->disconnectFromHost();
    QMessageBox::information(this, "채팅방 나가기", "채팅방에서 나왔습니다.");

    // 창 닫기
    this->close();
}
void ChatWindow::onReadyRead() {
    static QByteArray buffer;  // 이전에 수신된 데이터를 저장
    buffer.append(socket->readAll());  // 새로 수신된 데이터 추가

    while (true) {
        // 구분자 기준으로 메시지 찾기
        int separatorIndex = buffer.indexOf("CHAT|");
        if (separatorIndex == -1) {
            break;  // CHAT|로 시작하는 메시지가 없으면 대기
        }

        // 구분자 이후의 메시지를 추출
        QByteArray singleMessage = buffer.mid(separatorIndex);
        int endIndex = singleMessage.indexOf('|', separatorIndex + 5);  // 방 이름 뒤의 구분자 찾기

        if (endIndex == -1) {
            break;  // 메시지가 완전하지 않음
        }

        int messageStartIndex = endIndex + 1;
        QByteArray messageContent = singleMessage.mid(messageStartIndex);
        buffer.remove(0, messageStartIndex + messageContent.length());  // 처리된 메시지 제거

        QString response = QString::fromUtf8(messageContent).trimmed();
        qDebug() << "처리된 서버 응답:" << response;

        if (response.startsWith("CHAT|")) {
            QStringList fields = response.split("|");
            if (fields.size() == 3) {
                QString senderRoomName = fields[1].trimmed();
                QString message = fields[2].trimmed();

                qDebug() << "채팅 메시지 수신 - 방 이름:" << senderRoomName << ", 메시지:" << message;

                if (senderRoomName == roomName) {
                    ui->chatMessagesList->addItem(message);
                } else {
                    qDebug() << "다른 방의 메시지, 무시됨.";
                }
            } else {
                qDebug() << "잘못된 메시지 형식:" << response;
            }
        } else {
            qDebug() << "예상치 못한 응답:" << response;
        }
    }
}
