#pragma once
#include "Character.h"
#include <string>

class Player : public Character
{
public:
	enum WeaponType
	{
		non,
		knife,
		pistol,
		shotgun,

	};
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
<<<<<<< HEAD
	void ShowExpBar() const;
=======

private:

	int level;
	int maxLevel;
	int exp;
	int expToNextLevel;
	int gold;
	WeaponType currentWeapon;
	std::string myWeapon;
	bool pistolIsArmed;
	bool shotgunIsArmed;

>>>>>>> 73e872cae6fc6943a290d3016eeb28c94bece624
};