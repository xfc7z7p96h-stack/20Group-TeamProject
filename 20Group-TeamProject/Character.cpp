#include "Character.h"
#include <iostream>

Character::Character(std::string inName, int inHp, int inMaxHp, int inAttack)
    : name(inName), hp(inHp), maxHp(inMaxHp), attack(inAttack)
{
}

std::string Character::GetName() const
{
    return name;
}

int Character::GetHp() const
{
    return hp;
}

int Character::GetMaxHp() const
{
    return maxHp;
}

int Character::GetAttack() const
{
    return attack;
}

bool Character::IsDead() const
{
    return hp <= 0;
}

void Character::TakeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}

void Character::Heal(int amount)
{
    hp += amount;

    if (hp > maxHp)
    {
        hp = maxHp;
    }
}

void Character::IncreaseAttack(int amount)
{
    attack += amount;
}

void Character::ShowStatus() const
{
    std::cout << "[" << name << "] "
        << "HP: " << hp << "/" << maxHp
        << ", Attack: " << attack << std::endl;
}