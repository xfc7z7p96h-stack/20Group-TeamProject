#include "Player.h"
#include <iostream>
#include <string>

Player::Player()
{

}

Player::Player(std::string Innick_name) : nick_name(Innick_name), maxLevel(10), level(1), maxHp(200), hp(200), damage(30), exp(0)
{

}
Player::~Player()
{

}
void Player::SetNickName(std::string Innick_name)
{
	nick_name = Innick_name;
}
void Player::SetLevel(int Inlevel)
{
	level = Inlevel;
}
void Player::SetMaxHp(int InmaxHp)
{
	maxHp = InmaxHp;
}
void Player::SetHp(int Inhp)
{
	hp = Inhp;
}
void Player::SetDamage(int Indamage)
{
	damage = Indamage;
}
void Player::SetExp(int Inexp)
{
	exp = Inexp;
}
void Player::LevelUp()
{
	if (level >= 10)
	{
		cout << nick_name << "님은 이미 최대 레벨입니다." << endl;
		return;
	}

	level++;

	maxHp += level * 20;
	attack += level * 5;
	hp = maxHp;

	std::cout << "레벨 업! " << nick_name << "님이 레벨 " << level << "을 달성하셨습니다." << std::endl;
	std::cout << "레벨 업 보상으로 최대 체력과 공격력이 증가하고, 체력이 회복되었습니다." << std::endl;
}

void Heal(int value)
{
	if ((hp += value) >= maxHp)
	{
		hp = maxHp;
		std::cout << "체력이 가득 찼습니다" << std::endl;
	}
	else
	{
		hp += value;
	}
}

void Player::GainExp(int amount)
{
	if (level >= 10)
	{
		std::cout << nick_name << "님은 이미 최대 레벨입니다. 경험치를 추가로 획득하지 않습니다." << std::endl;
		return;
	}

	exp += amount;
	std::cout << nick_name << "님이 경험치를 획득하였습니다." << std::endl;

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

void IncreaseAttack(int value)
{
	damage += value;
}
std::string Player::GetNickName()
{
	return nick_name;
}
int Player::GetLevel()
{
	return level;
}
int Player::GetMaxHp()
{
	return maxHp;
}
int Player::GetHp()
{
	return hp;
}
int Player::GetDamage()
{
	return damage;
}
int Player::GetExp()
{
	return exp;
}

void Player::PlayerStatus() const
{
	std::cout << "닉네임 :" << nick_name << std::endl;
	std::cout << "최대 체력 :" << maxHp << std::endl;
	std::cout << "현재 체력 :" << hp << std::endl;
	std::cout << "공격력 :" << damage << std::endl;
	std::cout << "경험치 :" << exp << std::endl;
}