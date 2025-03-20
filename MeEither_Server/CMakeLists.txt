cmake_minimum_required(VERSION 3.5)

project(MeEither_Server)

set(CMAKE_CXX_STANDARD 14)

# Qt6 라이브러리 찾기 (Core, Network, Sql 포함)
find_package(Qt6 REQUIRED COMPONENTS Core Network Sql)

# 소스 파일 및 헤더 파일 추가
set(SOURCES
    ChatServer.cpp
    Main.cpp
    DatabaseManager.cpp
)

set(HEADERS
    ChatServer.h
    DatabaseManager.h
)

# Qt MOC 자동화 활성화
set(CMAKE_AUTOMOC ON)

# 실행 파일 생성
add_executable(MeEither_Server ${SOURCES} ${HEADERS})

# Qt6 라이브러리 연결
target_link_libraries(MeEither_Server Qt6::Core Qt6::Network Qt6::Sql)
