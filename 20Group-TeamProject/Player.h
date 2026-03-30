#pragma once
#include "Character.h"
#include <string>

class Player : public Character
{
private:
	enum WeaponType
	{
		non,
		knife,
		pistol,
		shotgun,

	};
	int level;
	int maxLevel;
	int exp;
	int expToNextLevel;
	int gold;
	WeaponType currentWeapon;
	std::string myWeapon;
	bool pistolIsArmed;
	bool shotgunIsArmed;
public:
	Player();

	~Player();
	void ArmedWeapon();
	WeaponType GetArmedWeapon();
	void SetArmedWeapon(int value);
	void WeaponName();
	void LevelUp();
	void GainExp(int amount);
	void Heal(int value);
	void IncreaseAttack(int value);
	void AddGold(int amount);
	void ShowStatus() const;
	void ResetNickName();
	void GetRest();
	void CurrentWeaponType();
	void ShowExpBar() const;
};