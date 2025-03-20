#ifndef CHATROOMLIST_H
#define CHATROOMLIST_H

#include <QDialog>
#include <QString>
#include <QTcpSocket>  // QTcpSocket 헤더 추가

namespace Ui {
class ChatRoomList;
}

class ChatRoomList : public QDialog
{
    Q_OBJECT

public:
    explicit ChatRoomList(const QString &continent, QWidget *parent = nullptr); // 생성자에서 대륙 이름을 받음
    ~ChatRoomList();

    void addChatRoom(const QString &roomName); // 채팅방을 추가하는 함수


private slots:
    void onCreateRoomButtonClicked(); // 채팅방 생성 버튼 처리
    void onJoinRoomButtonClicked();
     void onViewProfileButtonClicked();
       void onReadyRead();


private:
    Ui::ChatRoomList *ui;
    QString continent; // 대륙 이름을 저장할 변수
    QTcpSocket *socket; // 서버와 통신할 소켓
     QString myNickname;
    void requestUserInfo();  // 사용자 정보를 서버에 요청하는 함수
    void updateUserInfoTable(const QStringList &userList);
    void initializeUserInfoTable();
    void displayContinent(); // 선택된 대륙을 표시하는 함수

};

#endif // CHATROOMLIST_H
