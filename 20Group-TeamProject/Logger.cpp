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