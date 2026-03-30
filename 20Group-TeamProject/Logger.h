#pragma once
#include <string>

class Logger
{
public:
    static void Log(const std::string& message);
    static void Line();
    static void Space();

    // ===== 타이핑 출력 =====
    static void TypeLine(const std::string& text, int delay = 30);

    // 이벤트 로그
    static void Attack(const std::string& attacker,
        const std::string& target,
        int damage);

    static void Damage(const std::string& target,
        int damage);

    static void ItemUse(const std::string& user,
        const std::string& itemName);

    static void GoldGain(const std::string& receiver,
        int gold);
};