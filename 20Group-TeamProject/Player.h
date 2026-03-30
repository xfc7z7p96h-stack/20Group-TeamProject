#pragma once
#include "Character.h"
#include <string>

class Player : public Character
{
private:
	int level;
	int maxLevel;
	int exp;
	int expToNextLevel;
	int gold;
	std::string weapon;
	bool pistolIsArmed;
	bool shotgunIsArmed;
public:
	Player();

	~Player();

	void LevelUp();
	void GainExp(int amount);
	void Heal(int value);
	void IncreaseAttack(int value);
	void AddGold(int amount);
	void ShowStatus() const;
	void ResetNickName();
	void GetRest();
	void WeaponType();
};