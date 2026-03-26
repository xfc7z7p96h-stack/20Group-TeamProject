#include "Logger.h"
#include <iostream>

/*
    Logger::Log
    --------------------------------------------------
    가장 기본적인 로그 출력 함수.
    전달받은 문자열을 콘솔에 한 줄로 출력한다.

    게임 내 모든 메시지는 가능하면
    std::cout 대신 이 함수를 통해 출력하도록 한다.
*/
void Logger::Log(const std::string& message)
{
    std::cout << message << std::endl;
}

/*
    Logger::Line
    --------------------------------------------------
    화면 구분용 구분선 출력 함수.
    전투 시작, 이벤트 전환, UI 구분 등에 사용한다.
*/
void Logger::Line()
{
    std::cout << "====================================" << std::endl;
}

/*
    Logger::Space
    --------------------------------------------------
    가독성을 위한 빈 줄 출력.
    로그 블록 사이 간격을 만들 때 사용한다.
*/
void Logger::Space()
{
    std::cout << std::endl;
}