#include "ClientProfile.h"
#include "ui_ClientProfile.h"

ClientProfile::ClientProfile(const QString &username, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::ClientProfile),
    username(username) {
    ui->setupUi(this);

    // 프로필 데이터 로드
    loadProfile();

    // 닫기 버튼 연결
    connect(ui->closeButton, &QPushButton::clicked, this, &QWidget::close);
}

ClientProfile::~ClientProfile() {
    delete ui;
}

void ClientProfile::loadProfile() {
    // 예제 데이터 - 실제 구현에서는 서버와의 통신으로 데이터 로드
    ui->nicknameLabel->setText("닉네임: " + username);
    ui->ageLabel->setText("나이: 25");
    ui->genderLabel->setText("성별: 남성");
    ui->mbtiLabel->setText("MBTI: INTJ");
    ui->travelStyleLabel->setText("혼자 여행, 모험 좋아함");
    ui->preferredDestinationsLabel->setText("유럽, 동남아시아");
}
