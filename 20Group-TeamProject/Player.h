#pragma once
#include "Character.h"
#include "Inventory.h"
#include <string>

class Player : public Character
{
private:
	std::string weapon;
	int level;
	int maxLevel;
	int exp;
	int expToNextLevel;
	int gold;
	Inventory pistol;
	Inventory shotgun;
	bool pistolIsArmed;
	bool shotgunIsArmed;

public:
	Player();

	~Player();
	void Rest();
	void LevelUp();
	void GainExp(int amount);
	void Heal(int value);
	void IncreaseAttack(int value);
	void AddGold(int amount);
	void ShowStatus() const;
	void WeaponType() const;
	std::string ChangeName(Character& name);
};