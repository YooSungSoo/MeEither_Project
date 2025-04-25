<p align="center">
  <img src="https://raw.githubusercontent.com/YooSungSoo/MeEither_Project/master/assets/MeEither_Logo.jpg" width="400"/>
</p>

# 💬MeEither – Qt 기반 멀티스레드 채팅 프로그램

> **"Qt와 C++로 구현한 실시간 채팅 애플리케이션"**  
> `MeEither`는 C++ 및 Qt 프레임워크를 활용하여 제작된 TCP 기반 채팅 프로그램입니다.  
> **멀티스레드 기반 서버**가 다수의 클라이언트 연결을 안정적으로 처리하며,  
> **클라이언트는 GUI를 통해 실시간 채팅이 가능한 사용자 친화적인 인터페이스**를 제공합니다.

---

## 🛠 기술 스택

| 분야       | 기술 |
|------------|------|
| 언어       | C++17 |
| 프레임워크 | Qt 5.x (Widgets) |
| 네트워킹   | QTcpSocket, QTcpServer |
| 멀티스레드 | QThread |
| 비동기 처리 | Qt Signal & Slot |
| 빌드 도구  | qmake |

---

## 🔧 시스템 아키텍처

<p align="center">
    <img src="https://raw.githubusercontent.com/YooSungSoo/MeEither_Project/master/assets/architecture_diagram.jpg" width="600"/>
</p>

---

## ✨ 주요 기능

### ✅ 서버 (MeEither_Server)
- TCP 기반 서버 구축
- 클라이언트별 **QThread 기반 멀티스레드 처리**
- 실시간 채팅 메시지 중계
- 접속 및 종료 알림 처리

### ✅ 클라이언트 (MeEither_Client)
- Qt GUI 기반 채팅 인터페이스
- 실시간 메시지 송수신
- 사용자 닉네임 입력 기능
- 접속 상태 확인

---

## 🧠 핵심 클래스 설명

### 서버
| 클래스 | 설명 |
|--------|------|
| `Server` | QTcpServer 상속, 클라이언트 연결 관리 |
| `ClientThread` | QThread 상속, 클라이언트별 데이터 통신 처리 |

### 클라이언트
| 클래스 | 설명 |
|--------|------|
| `ClientSocket` | QTcpSocket 사용, 메시지 송수신 담당 |
| `ChatWindow` | 채팅 UI 구성 및 송수신 메시지 출력 |
| `LoginWindow` | 닉네임 입력 및 서버 연결 인터페이스 |

---

## 🙋 개발자

| 이름 | 역할 |
|------|------|
| 유성수 | 전체 설계, 네트워크 로직, 멀티스레딩, UI 구현 |

---

## 📌 참고사항

- 본 프로젝트는 개인 학습 및 포트폴리오 용도로 제작되었습니다.
- 향후 기능 확장 계획: 채팅 로그 저장, 파일 전송, 접속 클라이언트 목록 표시 등
