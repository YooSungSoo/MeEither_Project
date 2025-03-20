#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(const QString &roomName, QWidget *parent = nullptr);
    explicit ChatWindow(const QString &roomName, QTcpSocket *existingSocket, QWidget *parent = nullptr);  // 기존 소켓 추가
    ~ChatWindow();

private slots:
    void onSendButtonClicked();
    void onReadyRead();
    void onLeaveRoomButtonClicked();

private:
    Ui::ChatWindow *ui;
    QString roomName;
    QTcpSocket *socket;  // 서버와 통신할 소켓
};

#endif // CHATWINDOW_H
