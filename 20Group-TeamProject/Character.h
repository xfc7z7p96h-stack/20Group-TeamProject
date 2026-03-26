#pragma once
#include <iostream>
#include <string>

class Character
{
protected:
    std::string name;
    int hp;
    int maxHP;
    int attack;

public:
    Character(std::string InName = "Unknown", int InHP = 200, int InAttack = 30);
    virtual ~Character();

    std::string GetName() const;
    int GetHP() const;
    int GetMaxHP() const;
    int GetAttack() const;
    bool IsDead() const;

    virtual void TakeDamage(int Damage);
    virtual void ShowStatus() const;
};
