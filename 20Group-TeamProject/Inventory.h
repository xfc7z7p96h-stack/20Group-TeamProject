#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item> items;
	const int maxSize = 10;

public:
	void AddItem(const Item& item);
	void UseItem(int index, Character& target);
	void ShowInventory() const;

};

