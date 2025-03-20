#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
#include "ui_SignUpWindow.h"

class SignUpWindow : public QDialog {
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private slots:
    void onSignUpButtonClicked();  // 회원가입 버튼 클릭 시
    void onCheckDuplicate();

private:
    Ui::SignUpWindow ui;  // 자동 생성된 UI 객체
};

#endif // SIGNUPWINDOW_H
