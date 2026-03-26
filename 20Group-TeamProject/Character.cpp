#include "Character.h"

using namespace std;

Character::Character(string inName, int inLevel, int inHp, int inMaxHp, int inAttack, int inExp, int inGold, int inExpToNextLevel)
    : name(inName), level(inLevel), hp(inHp), maxHp(inMaxHp), attack(inAttack), exp(inExp), gold(inGold), expToNextLevel(inExpToNextLevel)
{
}

Character::~Character() {}

void Character::ShowStatus() const
{
}

void Character::GainExp(int amount)
{
    if (level >= 10)
    {
        cout << name << "님은 이미 최대 레벨입니다. 경험치를 추가로 획득하지 않습니다." << endl;
        return;
    }

    exp += amount;
    cout << name << "님이 경험치 " << amount << "를 획득했습니다. "
        << "(현재 EXP: " << exp << " / " << expToNextLevel << ")" << endl;

    while (level < 10 && exp >= expToNextLevel)
    {
        exp -= expToNextLevel;
        LevelUp();
    }

    if (level >= 10)
    {
        exp = 0;
    }
}

void Character::LevelUp()
{
    if (level >= 10)
    {
        cout << name << "님은 이미 최대 레벨입니다." << endl;
        return;
    }

    level++;

    maxHp += level * 20;
    attack += level * 5;
    hp = maxHp;

    cout << "레벨 업! " << name << "님이 레벨 " << level << "을 달성하셨습니다." << endl;
    cout << "레벨 업 보상으로 최대 체력과 공격력이 증가하고, 체력이 회복되었습니다." << endl;
}

string Character::GetName() const
{
    return name;
}

int Character::GetLevel() const
{
    return level;
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

int Character::GetExp() const
{
    return exp;
}

bool Character::IsDead() const
{
    return hp <= 0;
}