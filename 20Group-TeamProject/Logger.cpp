#include <thread>
#include <chrono>
#include <conio.h>   // 키 입력 감지
#include "Logger.h"
#include <iostream>

// 기본 로그
void Logger::Log(const std::string& message)
{
    std::cout << message << std::endl;
}

void Logger::Line()
{
    std::cout << "==================================================" << std::endl;
}

void Logger::Space()
{
    std::cout << std::endl;
}

// ================================
// 게임 이벤트 로그 함수들
// ================================

// 공격 이벤트
void Logger::Attack(const std::string& attacker,
    const std::string& target,
    int damage)
{
    Log("[ATTACK] " + attacker + " → "
        + target + " (" + std::to_string(damage) + " 피해)");
}

// 피해 이벤트
void Logger::Damage(const std::string& target,
    int damage)
{
    Log("[DAMAGE] " + target + "이(가) "
        + std::to_string(damage) + " 피해를 입었다.");
}

// 아이템 사용
void Logger::ItemUse(const std::string& user,
    const std::string& itemName)
{
    Log("[ITEM] " + user + "이(가) "
        + itemName + "을(를) 사용했다.");
}

// 골드 획득
void Logger::GoldGain(const std::string& receiver,
    int gold)
{
    Log("[GOLD] " + receiver + "이(가) "
        + std::to_string(gold) + " 골드를 획득했다.");
}

// ================================
// 타이핑 출력 (아무 키 입력 시 스킵)
// ================================
void Logger::TypeLine(const std::string& text, int delay)
{
    for (size_t i = 0; i < text.size(); ++i)
    {
        // 키 입력 감지
        if (_kbhit())
        {
            _getch(); // 입력 버퍼 제거

            // 남은 문자열 즉시 출력
            std::cout << text.substr(i);
            break;
        }

        // 한 글자씩 출력
        std::cout << text[i] << std::flush;

        // 타이핑 딜레이
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delay)
        );
    }

    std::cout << std::endl;
}