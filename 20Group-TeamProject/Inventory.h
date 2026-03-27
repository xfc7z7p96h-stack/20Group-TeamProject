// Inventory.h
#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item> items;
	const int maxSize = 10;
	int gold = 0;

public:
	void AddItem(const Item& item);
	void UseItem(int index, Player& target);
	void ShowInventory() const;
	void AddGold(int value);
};
