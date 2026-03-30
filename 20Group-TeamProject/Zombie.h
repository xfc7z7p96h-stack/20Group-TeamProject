#pragma once
#include "Character.h"

enum class AttackType
{
    Knife,
    Pistol,
    Shotgun
};

class Zombie : public Character
{
public:
    Zombie(std::string name, int hp, int maxHP, int attack)
        : Character(name, hp, maxHP, attack)
    {
    }

    void AddMaxHp(int value);
    void AddAttack(int value);

    virtual bool TryDodge(AttackType attackType) const;
    virtual bool CanCounter(AttackType attackType) const;
    virtual void OnSuccessfulCounter(int damageDealt);
    virtual const char* GetSpecialText() const;
};

class NormalZombie : public Zombie
{
public:
    NormalZombie()
        : Zombie("피좀비", 180, 180, 5)
    {
    }

    void OnSuccessfulCounter(int damageDealt) override;
    const char* GetSpecialText() const override;
};

class ArmoredZombie : public Zombie
{
public:
    ArmoredZombie()
        : Zombie("갑옷 좀비", 300, 300, 10)
    {
    }

    bool CanCounter(AttackType attackType) const override;
    const char* GetSpecialText() const override;
};

class FastZombie : public Zombie
{
public:
    FastZombie()
        : Zombie("재빠른 좀비", 200, 200, 20)
    {
    }

    bool TryDodge(AttackType attackType) const override;
    const char* GetSpecialText() const override;
};