#include "ChatClient.h"
#include <QDebug>

ChatClient::ChatClient(QObject *parent) : QObject(parent), socket(new QTcpSocket(this)) {
    connect(socket, &QTcpSocket::connected, this, &ChatClient::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &ChatClient::onDisconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, &ChatClient::onErrorOccurred);  // 오류 처리 연결
}

ChatClient::~ChatClient() {
    socket->close();  // 클라이언트 종료 시 소켓을 닫음
}

void ChatClient::connectToServer(const QString &host, int port) {
    socket->connectToHost(host, port);  // 서버에 연결
}

void ChatClient::sendMessage(const QString &message) {
    if (socket->state() == QTcpSocket::ConnectedState) {
        socket->write(message.toUtf8());  // 서버로 메시지 전송
    } else {
        qDebug() << "서버에 연결되지 않았습니다.";
    }
}

void ChatClient::onConnected() {
    qDebug() << "서버에 연결되었습니다.";
}

void ChatClient::onReadyRead() {
    QByteArray data = socket->readAll();  // 서버로부터 수신한 데이터
    qDebug() << "서버로부터 받은 메시지: " << data;
}

void ChatClient::onDisconnected() {
    qDebug() << "서버와의 연결이 종료되었습니다.";
}

void ChatClient::onErrorOccurred(QAbstractSocket::SocketError socketError) {
    qDebug() << "서버 연결 오류: " << socketError;
    switch (socketError) {
    case QAbstractSocket::HostNotFoundError:
        qDebug() << "서버를 찾을 수 없습니다.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug() << "서버가 연결을 거부했습니다.";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        qDebug() << "원격 호스트가 연결을 종료했습니다.";
        break;
    default:
        qDebug() << "기타 오류 발생";
    }
}
