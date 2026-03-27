// Inventory.cpp
#include "Inventory.h"
#include <iostream>

void Inventory::AddItem(const Item& item)
{
    std::string typeName;

    if (items.size() >= maxSize)
    {
        std::cout << "ÀÎº¥Åä¸®¿¡ ÀÚ¸®°¡ ¾ø´Ù.\n";
        return;
    }

    items.push_back(item);

    if (item.GetType() == ItemType::HP_POTION)
    {
        typeName = "Çãºê";
    }
    else if (item.GetType() == ItemType::ATTACK_POTION)
    {
        typeName = "¿¬¸¶Á¦";
    }
    else if (item.GetType() == ItemType::PISTOL)
    {
        typeName = "±ÇÃÑ";
    }
    else if (item.GetType() == ItemType::PISTOL_AMMO)
    {
        typeName = "±ÇÃÑ Åº¾ËÁý";
    }
    else if (item.GetType() == ItemType::SHOTGUN)
    {
        typeName = "¼¦°Ç";
    }
    else if (item.GetType() == ItemType::SHOTGUN_AMMO)
    {
        typeName = "¼¦°Ç Åº¾ËÁý";
    }
    std::cout << typeName << " È¹µæ!\n";
}

void Inventory::AddGold(int value)
{
    gold += value;
    std::cout << value << " °ñµå¸¦ È¹µæÇß´Ù!\n";
}

void Inventory::UseItem(int index, Player& target)
{
    if (index < 0 || index >= items.size())
    {
        std::cout << "Àß¸ø ¼±ÅÃÇß´Ù.\n";
        return;
    }

    ItemType type = items[index].GetType();

    if (type == ItemType::PISTOL)
    {
        std::cout << "±ÇÃÑÀº ÀüÅõ Áß »ç¿ëÇÒ ¼ö ÀÖ´Ù.\n";
        return;
    }

    if (type == ItemType::SHOTGUN)
    {
        std::cout << "¼¦°ÇÀº ÀüÅõ Áß »ç¿ëÇÒ ¼ö ÀÖ´Ù.\n";
        return;
    }

    if (type == ItemType::PISTOL_AMMO)
    {
        std::cout << "ÇöÀç ±ÇÃÑ Åº¾ËÁý ÀÜÅº: " << items[index].GetValue() << "¹ß\n";
        return;
    }

    if (type == ItemType::SHOTGUN_AMMO)
    {
        std::cout << "ÇöÀç ¼¦°Ç Åº¾ËÁý ÀÜÅº: " << items[index].GetValue() << "¹ß\n";
        return;
    }

    items[index].Use(target);
    items.erase(items.begin() + index);
}

int Inventory::GetSize() const
{
    return items.size();
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
    for (int i = 0; i < items.size(); i++)
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
    for (int i = 0; i < items.size(); i++)
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

void Inventory::ShowInventory() const
{
    std::cout << "\n===== ÀÎº¥Åä¸® =====\n";

    if (items.empty())
    {
        std::cout << "¾ÆÀÌÅÛÀÌ ¾ø´Ù.\n";
    }
    else
    {
        for (int i = 0; i < items.size(); i++)
        {
            std::cout << i + 1 << ". " << items[i].GetName() << "\n";
        }
    }

    std::cout << "\n°ñµå : " << gold << "\n";
    std::cout << "0. ³ª°¡±â\n";
}
