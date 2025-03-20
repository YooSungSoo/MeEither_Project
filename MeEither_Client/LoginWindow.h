#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>  // QWidget -> QDialog로 변경
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTcpSocket>
#include "ui_LoginWindow.h"  // 자동 생성된 UI 파일

class LoginWindow : public QDialog {  // QWidget -> QDialog로 변경
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void onLoginButtonClicked();  // 로그인 버튼 클릭 시
    void onSignUpButtonClicked(); // 회원가입 버튼 클릭 시

private:
    Ui::LoginWindow ui;  // 자동 생성된 UI 객체
    QTcpSocket *socket; // QTcpSocket 멤버 변수 추가
};

#endif // LOGINWINDOW_H
