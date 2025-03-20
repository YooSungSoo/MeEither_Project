#ifndef CHOOSELAND_H
#define CHOOSELAND_H

#include <QDialog>  // QDialog를 상속받도록 변경
#include "ui_ChooseLand.h"

class ChooseLand : public QDialog  // QDialog로 상속
{
    Q_OBJECT

public:
    explicit ChooseLand(QWidget *parent = nullptr);
    ~ChooseLand();

private slots:
    void onContinentClicked();  // 대륙 클릭 시 처리

private:
    Ui::ChooseLand *ui;
};

#endif // CHOOSELAND_H
