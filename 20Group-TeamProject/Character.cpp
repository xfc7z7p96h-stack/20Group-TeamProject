#include "Character.h"

Character::Character(std::string InName, int InHP, int InAttack)
    : name(InName), hp(InHP), maxHP(InHP), attack(InAttack)
{
}

Character::~Character()
{
}

std::string Character::GetName() const
{
    return name;
}

int Character::GetHP() const
{
    return hp;
}

int Character::GetMaxHP() const
{
    return maxHP;
}

int Character::GetAttack() const
{
    return attack;
}

bool Character::IsDead() const
{
    return hp <= 0;
}

void Character::TakeDamage(int Damage)
{
    hp -= Damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

void Character::ShowStatus() const
{
    std::cout << "[" << name << "] "
        << "HP : " << hp << "/" << maxHP
        << " °ø°Ý·Â : " << attack << "\n";
}