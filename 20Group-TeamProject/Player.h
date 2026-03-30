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
<<<<<<< HEAD
<<<<<<< HEAD
	void ShowExpBar() const;
<<<<<<< HEAD

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
=======
>>>>>>> 61570c0e89c25a15c3a41b05a5887927dd308adc
=======
>>>>>>> parent of 8b5eba6 (Player 충돌 수정입니다)
=======
>>>>>>> parent of 157e15b (enum WeaponType 클래스를 public으로 변경했습니다)
};