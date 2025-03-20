#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include "DatabaseManager.h"

class ChatServer : public QObject {
    Q_OBJECT

public:
    explicit ChatServer(QObject *parent = nullptr);
    ~ChatServer();

    void start();

private slots:
    void onNewConnection();
    void onReadyRead();
    void onDisconnected();

private:
    QTcpServer *server;
    QList<QTcpSocket *> clients;
    QStringList chatRooms;
    DatabaseManager *dbManager;
      QMap<QString, QList<QTcpSocket *>> chatRoomsClients;
       QMap<QTcpSocket *, QMap<QString, QString>> clientsInfo;

       void handleChatMessage(QTcpSocket *sender, const QStringList &fields); // 채팅 메시지 처리
 void broadcastClientsInfo();

    // 새로 추가된 핸들러 선언
    void handleLogin(QTcpSocket *clientSocket, const QStringList &fields);
    void handleSignup(QTcpSocket *clientSocket, const QStringList &fields);
    void handleCheckDuplicate(QTcpSocket *clientSocket, const QStringList &fields);
    void handleCreateRoom(QTcpSocket *clientSocket, const QStringList &fields);
    void handleJoinRoom(QTcpSocket *clientSocket, const QStringList &fields);

    void handleGetRooms(QTcpSocket *clientSocket);

     void broadcastChatRooms();
};

#endif // CHATSERVER_H
