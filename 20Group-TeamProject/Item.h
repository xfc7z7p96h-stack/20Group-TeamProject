#pragma once
#include <string>
#include "Character.h"
class Item
{
private:
	std::string name;
	int value; // 회복량 or 공격력 증가 등

public:
	Item(std::string name, int value);

	void Use(Character& player);

};