// Item.h
#pragma once
#include <string>
#include "Character.h"

enum class ItemType
{
	HP_POTION,
	ATTACK_POTION
};

class Item
{
private:
	std::string name;
	int value; // 회복량 or 공격력 증가 등
	ItemType type;

public:
	Item(std::string name, int value, ItemType type);

	std::string GetName() const;

	void Use(Character& player);

};