#include "ChooseLand.h"
#include "ui_ChooseLand.h"
#include "ChatRoomList.h"

ChooseLand::ChooseLand(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ChooseLand) {
    ui->setupUi(this);

    // 각 대륙 버튼 클릭 시 처리
    connect(ui->northEuropeButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->westEuropeButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->eastEuropeButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->eurasiaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->centralAsiaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->eastAsiaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->southEastAsiaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->oceaniaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->northAmericaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->southAmericaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->antarcticaButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
    connect(ui->arcticButton, &QPushButton::clicked, this, &ChooseLand::onContinentClicked);
}

ChooseLand::~ChooseLand() {
    delete ui;
}

void ChooseLand::onContinentClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString continent = button->text();

    auto *chatRoomList = new ChatRoomList(continent);
    chatRoomList->setAttribute(Qt::WA_DeleteOnClose);
    chatRoomList->show();

    this->close(); // ChooseLand 닫기
}
