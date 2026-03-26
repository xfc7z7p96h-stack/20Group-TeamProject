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

public:
	Player();

	~Player();

	int LevelUp();
	void GainExp(int amount);
	void Heal(int value);
	void IncreaseAttack(int value);
	void AddGold(int amount);
	void ShowStatus() const;

};

