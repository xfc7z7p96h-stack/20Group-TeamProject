#pragma once
#include <iostream>
#include <string>

class Character
{
protected:
    std::string name;
    int hp;
    int maxHp;
    int attack;

public:
    Character(std::string inName, int inHp, int inMaxHp, int inAttack);

    virtual ~Character()
    { }

    std::string GetName() const;
    int GetHp() const;
    int GetMaxHp() const;
    int GetAttack() const;
    bool IsDead() const;

    virtual void Heal(int value);
    virtual void IncreaseAttack(int value);
    virtual void TakeDamage(int damage);
    virtual void ShowStatus() const;
};