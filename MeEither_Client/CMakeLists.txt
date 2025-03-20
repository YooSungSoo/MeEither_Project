cmake_minimum_required(VERSION 3.5)

project(MeEither_Client)

set(CMAKE_CXX_STANDARD 14)

# Qt6 라이브러리 찾기 (Core, Widgets, Network, Sql 포함)
find_package(Qt6 REQUIRED COMPONENTS Core Network Widgets Sql)

# 소스 파일 및 헤더 파일 추가
set(SOURCES
    ChatClient.cpp
    LoginWindow.cpp
    main.cpp
    SignUpWindow.cpp
    ChooseLand.cpp
    ChatRoomList.cpp
    ChatWindow.cpp
    ClientProfile.cpp

)

set(HEADERS
    ChatClient.h
    LoginWindow.h
    SignUpWindow.h
    ChooseLand.h
    ChatRoomList.h
    ChatWindow.h
    ClientProfile.h
)

# UI 파일 자동 생성
set(UI_FILES
    LoginWindow.ui
    SignUpWindow.ui
    ChooseLand.ui
    ChatRoomList.ui
    ChatWindow.ui
    ClientProfile.ui
)

# Qt MOC 및 UI 자동화 활성화
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# 실행 파일 생성
add_executable(MeEither_Client ${SOURCES} ${HEADERS} ${UI_FILES}
    SignUpWindow.ui
    SignUpWindow.h
    SignUpWindow.cpp
    ChooseLand.h
    ChooseLand.ui
    ChooseLand.cpp
    ChatRoomList.ui
    ChatRoomList.cpp
    ChatRoomList.h
    ChatWindow.ui
    LoginWindow.cpp
    LoginWindow.h
    ChatWindow.h
    ChatWindow.cpp
    ClientProfile.ui
    ClientProfile.h
    ClientProfile.cpp)

# Qt6 라이브러리 연결
target_link_libraries(MeEither_Client Qt6::Core Qt6::Network Qt6::Widgets Qt6::Sql)
