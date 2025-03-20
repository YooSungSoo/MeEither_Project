#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QTcpSocket>
#include <QObject>

class ChatClient : public QObject {
    Q_OBJECT

public:
    explicit ChatClient(QObject *parent = nullptr);
    ~ChatClient();

    void connectToServer(const QString &host, int port);  // 서버 연결
    void sendMessage(const QString &message);  // 서버에 메시지 보내기

private slots:
    void onConnected();  // 연결 성공 시
    void onReadyRead();  // 서버로부터 데이터 수신 시
    void onDisconnected();  // 연결 종료 시
    void onErrorOccurred(QAbstractSocket::SocketError socketError);  // 오류 발생 시

private:
    QTcpSocket *socket;  // 서버와 연결된 소켓 객체
};

#endif // CHATCLIENT_H
