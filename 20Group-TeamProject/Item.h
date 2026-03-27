// Item.h
#pragma once
#include <string>
#include "Player.h"

enum class ItemType
{
	HP_POTION,
	ATTACK_POTION
};

class Item
{
private:
	std::string name;
	int value; // È¸º¹·® or °ø°Ý·Â Áõ°¡ µî
	ItemType type;

public:
	Item(std::string name, int value, ItemType type);

	std::string GetName() const;
	ItemType GetType() const;

	void Use(Player& player);

};