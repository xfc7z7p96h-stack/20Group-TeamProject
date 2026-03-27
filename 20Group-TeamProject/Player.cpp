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
	std::cout << "장착 중인 무기 : " << weapon << std::endl;
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

void Player::rest()
{
	hp = maxHp;
}
std::string Player::ChangeName(Character& name)
{
	std::cout << "이름을 입력해주세요" << std::endl;
	std::cin >> name;
	return name;
}
void Player::WeaponType()
{
	weapon = "보급형 서바이벌 나이프";
	if (pistol.HasPistol() == true)
	{
		std::cout << "권총을 장착했습니다." << std::endl;
		pistolIsArmed = true;
		shotgunIsArmed = false;
		weapon = "권총";
		return;
	}
	if (pistol.HasPistol() == false)
	{
		std::cout << "권총을 소유하고 있지 않습니다." << std::endl;
		pistolIsArmed = false;
		return;
	}
	if (shotgun.HasShotgun() == true)
	{
		std::cout << "샷건을 장착했습니다." << std::endl;
		shotgunIsArmed = true;
		pistolIsArmed = false;
		weapon = "샷건";
		return;
	}
	if (shotgun.HasShotgun() == false)
	{
		std::cout << "샷건을 소유하고 있지 않습니다." << std::endl;
		shotgunIsArmed = false;
		return;
	}
	if (pistol.HasPistol() == false && shotgun.HasShotgun() == false)
	{
		pistolIsArmed = false;
		shotgunIsArmed = false;
		weapon = "보급형 서바이벌 나이프";
		return;
	}
}