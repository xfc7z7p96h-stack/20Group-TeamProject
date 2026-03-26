// Inventory.cpp
#include "Inventory.h"
#include <iostream>

void Inventory::AddItem(const Item& item)
{
    if (items.size() >= maxSize)
    {
        std::cout << "인벤토리에 자리가 없다.\n";
        return;
    }

    items.push_back(item);
    std::cout << item.GetName() << "를 획득했다!\n";
}

void Inventory::UseItem(int index, Character& target)
{
    if (index < 0 || index >= items.size())
    {
        std::cout << "잘못 선택했다.\n";
        return;
    }

    items[index].Use(target);
    items.erase(items.begin() + index);
}

void Inventory::ShowInventory() const
{
    std::cout << "\n===== 인벤토리 =====\n";

    if (items.empty())
    {
        std::cout << "아이템이 없다.\n";
    }
    else
    {
        for (int i = 0; i < items.size(); i++)
        {
            std::cout << i + 1 << ". " << items[i].GetName() << "\n";
        }
    }

    std::cout << "\n골드 : " << gold << "\n";
    std::cout << "0. 나가기\n";
}