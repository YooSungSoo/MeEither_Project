#include <QApplication>
#include "LoginWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 로그인 창 생성 및 실행
    LoginWindow loginWindow;
    loginWindow.show();  // 모달이 아닌 비모달로 표시

    return a.exec();  // QApplication 이벤트 루프 실행
}
