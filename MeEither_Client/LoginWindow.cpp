#include "LoginWindow.h"
#include "SignUpWindow.h"
#include "ChooseLand.h"
#include <QMessageBox>
#include <QTcpSocket>
#include <QPushButton>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), socket(new QTcpSocket(this)) {
    ui.setupUi(this);

    // 로그인 버튼 클릭 처리
    connect(ui.loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    // 회원가입 버튼 클릭 처리
    connect(ui.signUpButton, &QPushButton::clicked, this, &LoginWindow::onSignUpButtonClicked);

    // 서버 연결
    socket->connectToHost("127.0.0.1", 8888);
    if (!socket->waitForConnected(3000)) {
        QMessageBox::critical(this, "연결 실패", "서버와 연결할 수 없습니다.");
    }
}

LoginWindow::~LoginWindow() {
    if (socket->isOpen()) {
        socket->disconnectFromHost();
        socket->close();
    }
}

void LoginWindow::onLoginButtonClicked() {
    QString username = ui.usernameLineEdit->text().trimmed();
    QString password = ui.passwordLineEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "아이디와 비밀번호를 입력하세요.");
        return;
    }

    // 로그인 요청 메시지 작성
    QByteArray data;
    data.append("LOGIN|");
    data.append(username.toUtf8() + "|");
    data.append(password.toUtf8());

    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        QMessageBox::critical(this, "응답 오류", "서버로부터 응답이 없습니다.");
        return;
    }

    QByteArray response = socket->readAll();
    QString responseStr = QString::fromUtf8(response);

    if (responseStr == "로그인 성공") {
        QMessageBox::information(this, "로그인 성공", "로그인에 성공했습니다!");

        // 로그인 성공 후 대륙 선택 창 열기
        auto *chooseLandWindow = new ChooseLand(); // 독립적으로 생성
        chooseLandWindow->setAttribute(Qt::WA_DeleteOnClose); // 창 닫을 때 메모리 해제
        chooseLandWindow->show();  // 비모달 방식으로 실행

        this->close(); // LoginWindow 닫기
    } else if (responseStr == "로그인 실패") {
        QMessageBox::warning(this, "로그인 실패", "아이디 또는 비밀번호가 잘못되었습니다.");
    } else {
        QMessageBox::warning(this, "오류", "알 수 없는 오류가 발생했습니다.");
    }
}

void LoginWindow::onSignUpButtonClicked() {
    auto *signUpWindow = new SignUpWindow(this);  // 부모 설정
    signUpWindow->setAttribute(Qt::WA_DeleteOnClose); // 창 닫을 때 메모리 해제
    signUpWindow->exec();  // 회원가입 창 실행
}
