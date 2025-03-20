#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

QMap<QString, QString> DatabaseManager::getUserInfo(const QString &username) {
    QMap<QString, QString> userInfo;
    QSqlQuery query;

    query.prepare("SELECT nickname, birth_date, gender FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString nickname = query.value("nickname").toString();
        QString birthDate = query.value("birth_date").toString();
        QString gender = query.value("gender").toString();

        // Calculate age
        QDate birth = QDate::fromString(birthDate, "yyyy-MM-dd");
        int age = QDate::currentDate().year() - birth.year();
        if (QDate::currentDate() < birth.addYears(age)) {
            age--;
        }

        userInfo["nickname"] = nickname;
        userInfo["age"] = QString::number(age);
        userInfo["gender"] = gender;
    }

    return userInfo;
}


DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {
    qDebug() << "DatabaseManager 생성됨.";
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();  // 데이터베이스 연결 종료
    }
}

bool DatabaseManager::createTable() {
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS "users" (
            "id" INTEGER PRIMARY KEY AUTOINCREMENT,
            "username" TEXT NOT NULL,
            "password" TEXT NOT NULL,
            "nickname" TEXT NOT NULL,
            "birth_date" TEXT,
            "gender" TEXT,
            "preferred_destinations" TEXT,
            "travel_style" TEXT,
            "mbti" TEXT
        );
    )";
    QSqlQuery query;
    if (!query.exec(createTableQuery)) {
        qDebug() << "테이블 생성 실패:" << query.lastError().text();
        return false;
    }
    qDebug() << "테이블 생성 성공.";
    return true;
}

bool DatabaseManager::connectToDatabase() {
    if (!db.isOpen()) {
        db.setDatabaseName("meeither.db");  // 데이터베이스 파일 지정
        if (!db.open()) {
            qDebug() << "데이터베이스 열기 실패:" << db.lastError().text();
            return false;
        }
        qDebug() << "데이터베이스 연결 성공.";
    }
    return true;
}

bool DatabaseManager::insertUser(const QString &username, const QString &password, const QString &nickname,
                                 const QString &birthDate, const QString &gender, const QString &preferredDestinations,
                                 const QString &travelStyle, const QString &mbti) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, nickname, birth_date, gender, preferred_destinations, travel_style, mbti) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(nickname);
    query.addBindValue(birthDate);
    query.addBindValue(gender);
    query.addBindValue(preferredDestinations);
    query.addBindValue(travelStyle);
    query.addBindValue(mbti);

    qDebug() << "쿼리 준비 완료, 실행 중...";

    if (!query.exec()) {
        qDebug() << "사용자 삽입 실패:" << query.lastError().text();
        return false;
    }

    qDebug() << "사용자 삽입 성공";
    return true;
}


bool DatabaseManager::validateLogin(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        qDebug() << "로그인 쿼리 실행 실패:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        return true;  // 로그인 성공
    }
    return false;  // 로그인 실패
}

bool DatabaseManager::checkDuplicateUsername(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "중복 확인 쿼리 실행 실패:" << query.lastError().text();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();
    return count > 0;  // 아이디가 이미 존재하면 true 반환
}

bool DatabaseManager::createChatRoom(const QString &roomName, const QString &continent) {
    QSqlQuery query;
    query.prepare("INSERT INTO rooms (room_name, continent) VALUES (:room_name, :continent)");
    query.bindValue(":room_name", roomName);
    query.bindValue(":continent", continent);

    if (query.exec()) {
        qDebug() << "채팅방 생성 성공";
        return true;
    } else {
        qDebug() << "채팅방 생성 실패:" << query.lastError().text();
        return false;
    }
}


bool DatabaseManager::isRoomExist(const QString &roomName) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM rooms WHERE room_name = :room_name");
    query.bindValue(":room_name", roomName);

    if (!query.exec()) {
        qDebug() << "채팅방 확인 실패:" << query.lastError().text();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();
    qDebug() << "채팅방 존재 여부:" << (count > 0);
    return count > 0;
}



