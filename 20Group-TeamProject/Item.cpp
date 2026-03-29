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
    }

    return false;
}