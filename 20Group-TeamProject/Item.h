// Item.h
#pragma once
#include <string>

class Player;

enum class ItemType
{
	HP_POTION,
	ATTACK_POTION,
	PISTOL,
	SHOTGUN,
	PISTOL_AMMO,
	SHOTGUN_AMMO,
	KNIFE
};

class Item
{
private:
	std::string name;
	int value; // 회복량,공격력증가량,총알의 수
	ItemType type;

public:
	Item(std::string name, int value, ItemType type);

	std::string GetName() const;
	ItemType GetType() const;
	int GetValue() const; //남은 총알 확인용
	void SetValue(int newValue); //총알 사용 시 호출

	bool IsConsumable() const;		// 사용 후 사라지는 아이템인지
	bool CanUse() const;			// 인벤토리에서 직접 사용 가능한지
	bool Use(Player& player);		// 성공하면 true
};

//객체 생성 시(아이템 획득)
//Item("권총", 0, ItemType::PISTOL);
//Item("샷건", 0, ItemType::SHOTGUN);
//Item("권총총알집", 10, ItemType::PISTOL_AMMO);
//Item("샷건총알집", 5, ItemType::SHOTGUN_AMMO);