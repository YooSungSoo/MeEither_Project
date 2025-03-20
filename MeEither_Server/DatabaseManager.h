#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>



class DatabaseManager : public QObject {
    Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();
QMap<QString, QString> getUserInfo(const QString &username);
    bool connectToDatabase();
    bool createTable();
    bool isRoomExist(const QString &roomName);
    bool insertUser(const QString &username, const QString &password, const QString &nickname,
                    const QString &birthDate, const QString &gender, const QString &preferredDestinations,
                    const QString &travelStyle, const QString &mbti);
    bool validateLogin(const QString &username, const QString &password);
    bool checkDuplicateUsername(const QString &username);  // 추가된 선언
      bool createChatRoom(const QString &roomName, const QString &continent);
private:
    QSqlDatabase db;  // 객체 단위로 QSqlDatabase 관리
};

#endif // DATABASEMANAGER_H
