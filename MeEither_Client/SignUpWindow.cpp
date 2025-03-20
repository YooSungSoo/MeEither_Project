#include "SignUpWindow.h"
#include <QMessageBox>
#include <QTcpSocket>

SignUpWindow::SignUpWindow(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);

    connect(ui.signUpButton, &QPushButton::clicked, this, &SignUpWindow::onSignUpButtonClicked);
    connect(ui.conform, &QPushButton::clicked, this, &SignUpWindow::onCheckDuplicate);  // 중복확인 버튼 연결
}

SignUpWindow::~SignUpWindow() {}

void SignUpWindow::onCheckDuplicate() {
    QString username = ui.usernameLineEdit->text();

    // 아이디가 비어있지 않은지 확인
    if (username.isEmpty()) {
        QMessageBox::warning(this, "중복 확인 실패", "아이디를 입력해주세요.");
        return;
    }

    // 서버에 아이디 중복 확인 요청
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 8888);

    if (!socket->waitForConnected()) {
        QMessageBox::critical(this, "연결 실패", "서버와 연결할 수 없습니다.");
        return;
    }

    // 중복 확인 요청 데이터 전송
    QByteArray data;
    data.append("CHECK_DUPLICATE|");
    data.append(username.toUtf8());

    socket->write(data);
    socket->flush();
    socket->waitForBytesWritten();

    // 서버로부터 응답을 기다림
    socket->waitForReadyRead();
    QByteArray response = socket->readAll();
    QString responseStr = QString::fromUtf8(response);

    if (responseStr == "아이디가 이미 존재합니다.") {
        QMessageBox::warning(this, "중복된 아이디", "이미 존재하는 아이디입니다.");
    } else if (responseStr == "아이디 사용 가능") {
        QMessageBox::information(this, "아이디 사용 가능", "사용 가능한 아이디입니다.");
    }

    socket->close();
}

void SignUpWindow::onSignUpButtonClicked() {
    QString username = ui.usernameLineEdit->text();
    QString password = ui.passwordLineEdit->text();
    QString nickname = ui.nickName->text();
    QString birthDate = ui.birthDateEdit->text();
    QString gender = ui.checkBoxM->isChecked() ? "남자" : "여자";

    // 여행 선호 지역 (체크된 항목만 전송)
    QStringList preferredDestinationsList;
    if (ui.northEU->isChecked()) preferredDestinationsList.append("북유럽");
    if (ui.westEU->isChecked()) preferredDestinationsList.append("서유럽");
    if (ui.centralAsia->isChecked()) preferredDestinationsList.append("중앙 아시아");
    if (ui.eastsouthAsia->isChecked()) preferredDestinationsList.append("동남 아시아");
    if (ui.eastEU->isChecked()) preferredDestinationsList.append("동유럽");
    if (ui.northAmerica->isChecked()) preferredDestinationsList.append("북아메리카");
    if (ui.southAmerica->isChecked()) preferredDestinationsList.append("남아메리카");
    if (ui.africa->isChecked()) preferredDestinationsList.append("아프리카");
    if (ui.oseania->isChecked()) preferredDestinationsList.append("오세아니아");
    if (ui.arctic->isChecked()) preferredDestinationsList.append("남극");
    if (ui.antArctic->isChecked()) preferredDestinationsList.append("북극");
    if (ui.eastAsia->isChecked()) preferredDestinationsList.append("동아시아");

    // 여행 스타일 (체크된 항목만 전송)
    QStringList travelStyleList;
    if (ui.rest->isChecked()) travelStyleList.append("휴양");
    if (ui.cityRest->isChecked()) travelStyleList.append("도심 휴식");
    if (ui.shopping->isChecked()) travelStyleList.append("쇼핑");
    if (ui.foodSearch->isChecked()) travelStyleList.append("맛집 탐방");
    if (ui.activity->isChecked()) travelStyleList.append("액티비티");
    if (ui.cultureLife->isChecked()) travelStyleList.append("문화생활");
    if (ui.leisurely->isChecked()) travelStyleList.append("여유롭게");
    if (ui.busy->isChecked()) travelStyleList.append("바쁘게");
    if (ui.trifity->isChecked()) travelStyleList.append("알뜰하게");
    if (ui.luxury->isChecked()) travelStyleList.append("사치스럽게");
    if (ui.sports->isChecked()) travelStyleList.append("스포츠");
    if (ui.nature->isChecked()) travelStyleList.append("자연");

    // 간단한 회원가입 검증
    if (username.isEmpty() || password.isEmpty() || nickname.isEmpty()) {
        QMessageBox::warning(this, "회원가입 실패", "모든 필드를 채워주세요.");
        return;
    }

    // 서버에 회원가입 요청
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 8888);

    if (!socket->waitForConnected()) {
        QMessageBox::critical(this, "연결 실패", "서버와 연결할 수 없습니다.");
        return;
    }

    // 서버로 데이터 전송
    QByteArray data;
    data.append("SIGNUP|");
    data.append(username.toUtf8() + "|");
    data.append(password.toUtf8() + "|");
    data.append(nickname.toUtf8() + "|");
    data.append(birthDate.toUtf8() + "|");
    data.append(gender.toUtf8() + "|");

    // preferredDestinations와 travelStyle을 각각 쉼표로 구분된 문자열로 전송
    data.append(preferredDestinationsList.join(",").toUtf8() + "|");
    data.append(travelStyleList.join(",").toUtf8() + "|");

    // MBTI
    data.append(ui.comboBox->currentText().toUtf8());

    socket->write(data);
    socket->flush();
    socket->waitForBytesWritten();
    socket->close();

    // 서버로부터 응답을 기다림
    QMessageBox::information(this, "회원가입 성공", "회원가입이 성공했습니다!");
    this->close();  // 회원가입 완료 후 창 닫기
}
