#ifndef CLIENTPROFILE_H
#define CLIENTPROFILE_H

#include <QWidget>
#include <QString>

namespace Ui {
class ClientProfile;
}

class ClientProfile : public QWidget {
    Q_OBJECT

public:
    explicit ClientProfile(const QString &username, QWidget *parent = nullptr);
    ~ClientProfile();

private:
    Ui::ClientProfile *ui;
    QString username;

    void loadProfile();  // 프로필 로드 함수
};

#endif // CLIENTPROFILE_H
