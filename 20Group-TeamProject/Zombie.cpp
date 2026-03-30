#include "Zombie.h"
#include "Random.h"

void Zombie::AddMaxHp(int value)
{
    maxHp += value;
    hp += value;

    if (hp > maxHp)
    {
        hp = maxHp;
    }
}

void Zombie::AddAttack(int value)
{
    attack += value;
}

bool Zombie::TryDodge(AttackType attackType) const
{
    return false;
}

bool Zombie::CanCounter(AttackType attackType) const
{
    return attackType == AttackType::Knife;
}

void Zombie::OnSuccessfulCounter(int damageDealt)
{
}

const char* Zombie::GetSpecialText() const
{
    return "없음";
}

void NormalZombie::OnSuccessfulCounter(int damageDealt)
{
    Heal(damageDealt / 2);
}

const char* NormalZombie::GetSpecialText() const
{
    return "플레이어에게 입힌 피해량의 50%만큼 회복";
}

bool ArmoredZombie::CanCounter(AttackType attackType) const
{
    return true;
}

const char* ArmoredZombie::GetSpecialText() const
{
    return "모든 공격에 반격";
}

bool FastZombie::TryDodge(AttackType attackType) const
{
    if (attackType == AttackType::Pistol || attackType == AttackType::Shotgun)
    {
        return Random::Chance(30);
    }

    return false;
}

const char* FastZombie::GetSpecialText() const
{
    return "권총/샷건 30% 확률로 회피";
}