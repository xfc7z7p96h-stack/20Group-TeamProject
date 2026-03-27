#include "Player.h"
#include "Logger.h"
#include <iostream>
#include <string>

Player::Player()
	: Character("Leon Scott Kennedy", 200, 200, 30), level(1), maxLevel(10), exp(0), expToNextLevel(100), gold(0)
{

}
Player::~Player()
{

}

void Player::ShowStatus() const
{
	std::cout << "==================== Status ====================" << std::endl;
	std::cout << "Player : " << name << std::endl;
	std::cout << "Level : " << level << std::endl;
	std::cout << "HP : " << hp << " / " << maxHp << std::endl;
	std::cout << "공격력 : " << attack << std::endl;
	std::cout << "경험치 : " << exp << " / " << expToNextLevel << std::endl;
	std::cout << "Gold : " << gold << std::endl;
	std::cout << "================================================" << std::endl;
}

void Player::LevelUp()
{
	if (level >= maxLevel)
	{
		exp = 0;
		std::cout << "최대 레벨에 도달했습니다.\n";
		return;
	}

	while (level < maxLevel && exp >= expToNextLevel)
	{
		exp -= expToNextLevel;
		level++;

		maxHp += level * 20;
		attack += level * 5;
		hp = maxHp;

		std::cout << "레벨 업! 현재 레벨: " << level << "\n";

		if (level >= maxLevel)
		{
			exp = 0;
			std::cout << "최대 레벨에 도달했습니다.\n";
			break;
		}
	}
}

void Player::GainExp(int amount)
{
	if (level >= maxLevel)
	{
		std::cout << name << "님은 이미 최대 레벨입니다.\n";
		return;
	}

	exp += amount;
	std::cout << name << "님이 경험치를 " << amount << " 획득하였습니다.\n";

	LevelUp();

	if (level >= maxLevel)
	{
		exp = 0;
	}
}

void Player::Heal(int value)
{
	hp += value;

	if (hp> maxHp)
	{
		hp = maxHp;

	}
}


void Player::IncreaseAttack(int value)
{
	attack += value;
}

void Player::AddGold(int amount)
{
	gold += amount;
}