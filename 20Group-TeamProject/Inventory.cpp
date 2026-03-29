// Inventory.cpp
#include "Inventory.h"
#include "Player.h"
#include <iostream>
//#include <limits>
#include <conio.h>
#include <cctype>
#include <cstdlib>

Inventory::Inventory()
{
    items.push_back(Item("칼", 0, ItemType::KNIFE));
}

int Inventory::GetGold() const
{
    return gold;
}

bool Inventory::AddItem(const Item& item)
{
    if (static_cast<int>(items.size()) >= maxSize)
    {
        std::cout << "인벤토리에 자리가 없다.\n";
        return false;
    }

    items.push_back(item);
    std::cout << item.GetName() << " 획득!\n";
    return true;
}

void Inventory::AddGold(int value)
{
    gold += value;
    std::cout << value << " 골드를 획득했다!\n";
}

bool Inventory::UseItem(int index, Player& target)
{
    if (index < 0 || index >= static_cast<int>(items.size()))
    {
        std::cout << "잘못 선택했다.\n";
        return false;
    }

    bool used = items[index].Use(target);

    if (used && items[index].IsConsumable())
    {
        items.erase(items.begin() + index);
    }

    return used;
}

int Inventory::GetSize() const
{
    return static_cast<int>(items.size());
}

bool Inventory::HasItem(ItemType type) const
{
    for (const auto& item : items)
    {
        if (item.GetType() == type)
        {
            return true;
        }
    }
    return false;
}

bool Inventory::HasPistol() const
{
    return HasItem(ItemType::PISTOL);
}

bool Inventory::HasShotgun() const
{
    return HasItem(ItemType::SHOTGUN);
}

int Inventory::GetPistolAmmo() const
{
    for (const auto& item : items)
    {
        if (item.GetType() == ItemType::PISTOL_AMMO)
        {
            return item.GetValue();
        }
    }
    return 0;
}

int Inventory::GetShotgunAmmo() const
{
    for (const auto& item : items)
    {
        if (item.GetType() == ItemType::SHOTGUN_AMMO)
        {
            return item.GetValue();
        }
    }
    return 0;
}                       

bool Inventory::ConsumePistolAmmo()
{
    for (int i = 0; i < static_cast<int>(items.size()); i++)
    {
        if (items[i].GetType() == ItemType::PISTOL_AMMO)
        {
            int currentAmmo = items[i].GetValue();

            if (currentAmmo <= 0)
            {
                items.erase(items.begin() + i);
                return false;
            }

            items[i].SetValue(currentAmmo - 1);

            if (items[i].GetValue() <= 0)
            {
                items.erase(items.begin() + i);
            }

            return true;
        }
    }

    return false;
}

bool Inventory::ConsumeShotgunAmmo()
{
    for (int i = 0; i < static_cast<int>(items.size()); i++)
    {
        if (items[i].GetType() == ItemType::SHOTGUN_AMMO)
        {
            int currentAmmo = items[i].GetValue();

            if (currentAmmo <= 0)
            {
                items.erase(items.begin() + i);
                return false;
            }

            items[i].SetValue(currentAmmo - 1);

            if (items[i].GetValue() <= 0)
            {
                items.erase(items.begin() + i);
            }

            return true;
        }
    }

    return false;
}

void Inventory::ShowInventory() const // 구버전 함수, Battle.cpp에서 기존 호출 중
{
    std::cout << "\n===== 인벤토리 =====\n";

    for (int i = 0; i < static_cast<int>(items.size()); ++i)
    {
        std::cout << i + 1 << ". " << items[i].GetName();

        ItemType type = items[i].GetType();
        if (type == ItemType::PISTOL_AMMO || type == ItemType::SHOTGUN_AMMO)
        {
            std::cout << " x" << items[i].GetValue();
        }

        std::cout << "\n";
    }

    std::cout << "\n골드 : " << gold << "\n";
}

void Inventory::ShowInventory(int selectedIndex) const  // 최신 함수, OpenInventory() 내부에서 사용
{
    std::cout << "\n===== 인벤토리 =====\n";
    std::cout << "[W/S] 이동  [E] 선택  [Q] 닫기\n\n";

    for (int i = 0; i < static_cast<int>(items.size()); ++i)
    {
        if (i == selectedIndex)
        {
            std::cout << "> ";
        }
        else
        {
            std::cout << "  ";
        }

        std::cout << items[i].GetName();

        ItemType type = items[i].GetType();
        if (type == ItemType::PISTOL_AMMO || type == ItemType::SHOTGUN_AMMO)
        {
            std::cout << " x" << items[i].GetValue();
        }

        std::cout << "\n";
    }

    std::cout << "\n골드 : " << gold << "\n";
}

bool Inventory::OpenInventory(Player& target)
{
    int selectedIndex = 0;

    while (true)
    {
        system("cls");
        ShowInventory(selectedIndex);

        char input = _getch();
        input = std::tolower(static_cast<unsigned char>(input));

        switch (input)
        {
        case 'w':
            if (selectedIndex > 0)
            {
                --selectedIndex;
            }
            break;

        case 's':
            if (selectedIndex < GetSize() - 1)
            {
                ++selectedIndex;
            }
            break;

        case 'e':
        {
            system("cls");
            bool used = UseItem(selectedIndex, target);

            std::cout << "\n(아무 키나 누르세요.)";
            _getch();

            if (selectedIndex >= GetSize())
            {
                selectedIndex = GetSize() - 1;
            }

            if (selectedIndex < 0)
            {
                selectedIndex = 0;
            }

            if (used)
            {
                return true;
            }

            break;
        }

        case 'q':
            return false;
        }
    }
}

//bool Inventory::OpenAndUse(Player& target)
//{
//    while (true)
//    {
//        ShowInventory();
//        std::cout << "사용할 아이템 번호를 입력하세요. (0: 나가기)\n";
//        std::cout << "입력: ";
//
//        int choice;
//        std::cin >> choice;
//
//        if (std::cin.fail())
//        {
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            std::cout << "숫자를 입력해주세요.\n";
//            continue;
//        }
//
//        if (choice == 0)
//        {
//            std::cout << "인벤토리를 닫습니다.\n";
//            return false;
//        }
//
//        if (choice < 1 || choice > static_cast<int>(items.size()))
//        {
//            std::cout << "손이 미끄러졌다. 다시 선택하자.\n";
//            continue;
//        }
//
//        bool used = UseItem(choice - 1, target);
//
//        if (used)
//        {
//            return true;
//        }
//    }
//}