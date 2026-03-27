// Item.cpp
#include "Item.h"
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

void Item::Use(Player& player)
{
    if (type == ItemType::HP_POTION)
    {
        player.Heal(value);
        std::cout << "허브를 사용했다! 체력 +" << value << "\n";
    }
    else if (type == ItemType::ATTACK_POTION)
    {
        player.IncreaseAttack(value);
        std::cout << "연마제를 사용했다! 공격력 +" << value << "\n";
    }
}