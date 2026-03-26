// Inventory.cpp
#include "Inventory.h"

void Inventory::AddItem(const Item& item)
{
	if (items.size() >= maxSize)
	{
		std::cout << "인벤토리에 자리가 없다.\n";
		return;
	}
	items.push_back(item);
}

void Inventory::UseItem(int index, Character& target)
{
	if (index < 0 || index >= items.size())
	{
		std::cout << "손에 잡히는게 없다. 다른 주머니를 볼까?" << std::endl;
		return;
	}
	items[index].Use(target);
	
	//UseItem 호출 시, Input값에 -1 하기
	items.erase(items.begin() + index);
}
