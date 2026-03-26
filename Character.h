#pragma once
#include <iostream>
#include <string>

class Character
{
protected:
    std::string name;
    int level;
    int hp;
    int maxHp;
    int attack;
    int exp;
    int gold;
    int expToNextLevel;

public:
    Character(std::string inName = "Unknown",
        int inLevel = 1,
        int inHp = 200,
        int inMaxHp = 200,
        int inAttack = 30,
        int inExp = 0,
        int inGold = 0,
        int inExpToNextLevel = 100);

    virtual ~Character();

    std::string GetName() const;
    int GetLevel() const;
    int GetHp() const;
    int GetMaxHp() const;
    int GetAttack() const;
    int GetExp() const;
    bool IsDead() const;

    void GainExp(int amount);
    void LevelUp();

    virtual void TakeDamage(int damage);
    virtual void ShowStatus() const;
};