#pragma once
#include "Character.h"
#include <string>

class Player : public Character
{
public:
    enum WeaponType
    {
        knife,
        pistol,
        shotgun,
    };

    Player();
    ~Player();

    WeaponType GetArmedWeapon() const;
    int GetLevel() const;
    void SetArmedWeapon(WeaponType value);
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
    std::string GetWeaponName() const;

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
};