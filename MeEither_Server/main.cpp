#include <QCoreApplication>
#include "ChatServer.h"
#include "DatabaseManager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[]) {
    // QCoreApplication 객체 생성 (이벤트 루프 활성화)
    QCoreApplication a(argc, argv);

    // 데이터베이스 연결 시도
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // SQLite 드라이버 추가
    db.setDatabaseName("meeither.db");  // 데이터베이스 파일 지정

    // 데이터베이스 연결 시도
    if (!db.open()) {
        qCritical() << "데이터베이스 열기 실패:" << db.lastError().text();
        return -1;  // 데이터베이스 연결 실패 시 종료
    }
    qDebug() << "데이터베이스 연결 성공.";

    // DatabaseManager 객체 생성 후 테이블 생성
    DatabaseManager dbManager;
    dbManager.createTable();  // 테이블 생성

    // 서버 객체 생성 및 시작
    ChatServer server;
    server.start();  // 서버 시작

    // 이벤트 루프 실행
    return a.exec();  // 이벤트 루프 실행
}
