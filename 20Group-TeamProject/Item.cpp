// Item.cpp
#include "Item.h"
#include "Player.h"
#include <iostream>

Item::Item(std::string name, int value, ItemType type)
    : name(name), value(value), type(type)
{
}

std::string Item::GetName() const
{
    return name;
}

ItemType Item::GetType() const
{
    return type;
}

int Item::GetValue() const
{
    return value;
}

void Item::SetValue(int newValue)
{
    value = newValue;
}

bool Item::IsConsumable() const
{
    switch (type)
    {
    case ItemType::HP_POTION:
    case ItemType::ATTACK_POTION:
        return true;

    default:
        return false;
    }
}

bool Item::CanUse() const
{
    switch (type)
    {
    case ItemType::HP_POTION:
    case ItemType::ATTACK_POTION:
        return true;

    default:
        return false;
    }
}

bool Item::Use(Player& player)
{
    switch (type)
    {
    case ItemType::HP_POTION:
        std::cout << name << "을(를) 사용했습니다.\n";
        player.Heal(value);
        return true;

    case ItemType::ATTACK_POTION:
        std::cout << name << "을(를) 사용했습니다.\n";
        player.IncreaseAttack(value);
        return true;

    case ItemType::PISTOL:
        std::cout << "작동되는 게 신기할 정도로 심하게 오염되어 있는 권총이다.\n";
        return false;

    case ItemType::SHOTGUN:
        std::cout << "무겁지만 위력이 강력한 샷건이다. 반동을 잘 잡아야 된다.\n";
        return false;

    case ItemType::PISTOL_AMMO:
        std::cout << "권총 탄약이 " << value << "발 남아 있다.\n";
        return false;

    case ItemType::SHOTGUN_AMMO:
        std::cout << "샷건 탄약이 " << value << "발 남아 있다.\n";
        return false;

    case ItemType::KNIFE:
        std::cout << "경찰 임용 선물로 받은 보급형 서바이벌 나이프.\n";
        return false;

    case ItemType::NOTE_CONTROLROOM:
        std::cout << "비상 상황 발생 시를 대비해 감시실 금고 해제 순서를 기록해 둔다.\n\'L7 - R12 - L3\'\n";
        return false;

    case ItemType::NOTE_ARCHIVE:
        std::cout << "[ 바이러스 감염 후 단계별 증상 ]\n";
        std::cout << "1. 환청\n";
        std::cout << "2. 두통\n";
        std::cout << "3. 발작\n";
        std::cout << "4. 호흡곤란\n";
        std::cout << "5. 사망\n";
        return false;

    case ItemType::NOTE_ISOLATIONROOM_1:
        std::cout << "[ 환자 기록지 ]\n";
        std::cout << "- 강민석: 발작\n";
        std::cout << "- 이준호: 환청\n";
        std::cout << "- 박도윤: 두통\n";
        std::cout << "- 최현우: 호흡곤란\n";
        return false;

    case ItemType::NOTE_ISOLATIONROOM_2:
        std::cout << "[ 침대 메모 ]\n";
        std::cout << "'1번 강민석'  '2번 이준호'  '3번 박도윤'  '4번 최현우'\n";
        return false;

    case ItemType::BREAD:
        std::cout << "포장되어있는 딱딱한 돌빵. 그럭저럭 먹을 수 있을 것 같다.\n";
        return false;

    case ItemType::WATER:
        std::cout << "페트병에 담긴 물. 비상시에 유용할 것 같다.\n";
        return false;
    }

    return false;
}