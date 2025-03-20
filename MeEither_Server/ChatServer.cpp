 #include "ChatServer.h"
#include "DatabaseManager.h"
#include <QDebug>
#include <QTcpSocket>
#include <QThread>
#include <QMap>


ChatServer::ChatServer(QObject *parent)
    : QObject(parent), server(new QTcpServer(this)), dbManager(new DatabaseManager()) {
    connect(server, &QTcpServer::newConnection, this, &ChatServer::onNewConnection);
    QMap<QString, QList<QTcpSocket *>> chatRoomsClients;
    QMap<QTcpSocket *, QMap<QString, QString>> clientsInfo;

}

ChatServer::~ChatServer() {
    qDeleteAll(clients);
    delete dbManager;
}

void ChatServer::start() {
    if (!server->isListening()) {
        if (!server->listen(QHostAddress::Any, 8888)) {
            qDebug() << "서버 시작 실패!";
        } else {
            qDebug() << "서버 시작됨. 포트 8888에서 대기 중...";
        }
    } else {
        qDebug() << "서버가 이미 시작되어 있습니다.";
    }
}

void ChatServer::onNewConnection() {
    QTcpSocket *clientSocket = server->nextPendingConnection();
    clients.append(clientSocket);

    connect(clientSocket, &QTcpSocket::readyRead, this, &ChatServer::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &ChatServer::onDisconnected);

    qDebug() << "새로운 클라이언트 연결됨.";
}

void ChatServer::onReadyRead() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    QByteArray data = clientSocket->readAll();

    qDebug() << "서버에서 받은 데이터:" << data;

    QStringList fields = QString(data).split("|");
    qDebug() << "파싱된 필드:" << fields;

    if (fields.size() == 3 && fields[0] == "LOGIN") {
        handleLogin(clientSocket, fields);
    } else if (fields.size() == 9 && fields[0] == "SIGNUP") {
        handleSignup(clientSocket, fields);
    } else if (fields.size() == 2 && fields[0] == "CHECK_DUPLICATE") {
        handleCheckDuplicate(clientSocket, fields);
    } else if (fields.size() == 3 && fields[0] == "CREATE_ROOM") {
        handleCreateRoom(clientSocket, fields);
    } else if (fields.size() == 2 && fields[0] == "JOIN_ROOM") {
        handleJoinRoom(clientSocket, fields);
    } else if (fields.size() == 1 && fields[0] == "GET_ROOMS") { // 채팅방 목록 요청 처리
        handleGetRooms(clientSocket);
    } else if (fields.size() >= 3 && fields[0] == "CHAT") {
        handleChatMessage(clientSocket, fields);
    } else {
        qDebug() << "잘못된 요청:" << data;
        clientSocket->write("INVALID_REQUEST");
        clientSocket->flush();
    }
}

void ChatServer::handleLogin(QTcpSocket *clientSocket, const QStringList &fields) {
    QString username = fields[1];
    QString password = fields[2];

    if (dbManager->validateLogin(username, password)) {
        clientSocket->write("로그인 성공");
        clientSocket->flush();

        // Retrieve client info from the database
        QMap<QString, QString> userInfo = dbManager->getUserInfo(username);
        clientsInfo[clientSocket] = userInfo;

        // Broadcast updated client info
        broadcastClientsInfo();
    } else {
        clientSocket->write("로그인 실패");
        clientSocket->flush();
    }
}

void ChatServer::broadcastClientsInfo() {
    QString message = "UPDATE_CLIENTS|";

    for (auto it = clientsInfo.begin(); it != clientsInfo.end(); ++it) {
        QMap<QString, QString> userInfo = it.value();
        message += userInfo["nickname"] + "," +
                   userInfo["age"] + "," +
                   userInfo["gender"] + ";";
    }

    for (QTcpSocket *client : clients) {
        if (client->state() == QTcpSocket::ConnectedState) {
            client->write(message.toUtf8());
            client->flush();
        }
    }
}

void ChatServer::handleSignup(QTcpSocket *clientSocket, const QStringList &fields) {
    QString username = fields[1];
    QString password = fields[2];
    QString nickname = fields[3];
    QString birthDate = fields[4];
    QString gender = fields[5];
    QString preferredDestinations = fields[6];
    QString travelStyle = fields[7];
    QString mbti = fields[8];

    if (dbManager->insertUser(username, password, nickname, birthDate, gender, preferredDestinations, travelStyle, mbti)) {
        clientSocket->write("회원가입 성공");
    } else {
        clientSocket->write("회원가입 실패");
    }
    clientSocket->flush();
}

void ChatServer::handleCheckDuplicate(QTcpSocket *clientSocket, const QStringList &fields) {
    QString username = fields[1];

    if (dbManager->checkDuplicateUsername(username)) {
        clientSocket->write("아이디가 이미 존재합니다.");
    } else {
        clientSocket->write("아이디 사용 가능");
    }
    clientSocket->flush();
}

void ChatServer::handleCreateRoom(QTcpSocket *clientSocket, const QStringList &fields) {
    QString roomName = fields[1];
    QString continent = fields[2];

    qDebug() << "받은 방 이름:" << roomName;
    qDebug() << "받은 대륙 정보:" << continent;

    bool success = dbManager->createChatRoom(roomName, continent);
    if (success) {
        qDebug() << "채팅방 생성 성공, 클라이언트로 성공 메시지 전송";
        clientSocket->write("CREATE_ROOM_SUCCESS");
        clientSocket->flush();

        // 채팅방 목록에 추가
        chatRooms.append(roomName);

        // 모든 클라이언트에 업데이트 전송
        broadcastChatRooms();  // <-- 브로드캐스트 호출
    } else {
        qDebug() << "채팅방 생성 실패, 클라이언트로 실패 메시지 전송";
        clientSocket->write("CREATE_ROOM_FAILURE");
        clientSocket->flush();
    }
}

void ChatServer::broadcastChatRooms() {
    QString roomList = chatRooms.join(";");
    QString message = "UPDATE_ROOMS|" + roomList;

    // 모든 연결된 클라이언트에게 채팅방 목록 전송
    for (QTcpSocket *client : clients) {
        if (client->state() == QTcpSocket::ConnectedState) {
            client->write(message.toUtf8());
            client->flush();
        }
    }
}



void ChatServer::handleJoinRoom(QTcpSocket *clientSocket, const QStringList &fields) {
    QString roomName = fields[1].trimmed();
    qDebug() << "채팅방 입장 요청, 방 이름:" << roomName;

    if (chatRooms.contains(roomName)) {
        clientSocket->write("JOIN_ROOM_SUCCESS\n");
        clientSocket->flush();

        // 채팅방에 소켓 추가
        if (!chatRoomsClients.contains(roomName)) {
            chatRoomsClients[roomName] = QList<QTcpSocket *>();
        }

        if (!chatRoomsClients[roomName].contains(clientSocket)) {  // 중복 추가 방지
            chatRoomsClients[roomName].append(clientSocket);
        }

        qDebug() << "현재 " << roomName << " 방 클라이언트 목록: " << chatRoomsClients[roomName].size();
    } else {
        clientSocket->write("JOIN_ROOM_FAILURE\n");
        clientSocket->flush();
    }
}


void ChatServer::handleGetRooms(QTcpSocket *clientSocket) {
    QString roomList = chatRooms.join(";");
    clientSocket->write("UPDATE_ROOMS|" + roomList.toUtf8());
    clientSocket->flush();
}


void ChatServer::onDisconnected() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (!clientSocket) return;

    // 모든 채팅방에서 클라이언트 제거
    for (auto it = chatRoomsClients.begin(); it != chatRoomsClients.end(); ++it) {
        if (it->removeOne(clientSocket)) {
            qDebug() << "클라이언트가 채팅방에서 제거됨:" << it.key();
        }
    }

    // 전체 클라이언트 리스트에서 제거
    clients.removeOne(clientSocket);
    clientSocket->deleteLater();

    qDebug() << "클라이언트 연결 종료.";
}


void ChatServer::handleChatMessage(QTcpSocket *sender, const QStringList &fields) {
    if (fields.size() < 3) {
        qDebug() << "잘못된 메시지 형식:" << fields;
        return;
    }

    QString roomName = fields[1].trimmed();
    QString message = fields[2].trimmed();

    qDebug() << "채팅 메시지 수신 - 방 이름:" << roomName << ", 메시지:" << message;

    if (!chatRoomsClients.contains(roomName)) {
        qDebug() << "채팅방 존재하지 않음.";
        return;
    }

    for (QTcpSocket *client : chatRoomsClients[roomName]) {
        if (client != sender && client->state() == QAbstractSocket::ConnectedState) {
            QByteArray data;
            data.append("CHAT|");
            data.append(roomName.toUtf8() + "|");
            data.append(message.toUtf8());
            client->write(data);
            client->flush();
            qDebug() << "메시지 브로드캐스트 성공: " << data;
        }
    }
}
