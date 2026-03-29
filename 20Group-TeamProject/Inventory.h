//Inventory.h
#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Player;

class Inventory
{
private:
    std::vector<Item> items;
    const int maxSize = 10;
    int gold = 0;

public:
    Inventory();

    bool AddItem(const Item& item);
    bool UseItem(int index, Player& target);

    void ShowInventory() const;
    void ShowInventory(int selectedIndex) const;
    bool OpenInventory(Player& target);

    void AddGold(int value);

    bool HasItem(ItemType type) const;
    bool HasPistol() const;
    bool HasShotgun() const;
    bool ConsumePistolAmmo();
    bool ConsumeShotgunAmmo();

    int GetPistolAmmo() const;
    int GetShotgunAmmo() const;
    int GetGold() const;
    int GetSize() const;
};