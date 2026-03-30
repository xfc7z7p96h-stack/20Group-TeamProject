#include "Player.h"
#include "Logger.h"
#include <iostream>
#include <string>
#include <windows.h>

Player::Player()
	: Character("Leon Scott Kennedy", 200, 200, 30), level(1), maxLevel(10), exp(0), expToNextLevel(100), gold(0)
{

}
Player::~Player()
{

}

void PrintStatChange(const std::string& name, int oldValue, int newValue)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::cout << name << " : " << oldValue << " → " << newValue << " (";

	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "▲ " << newValue - oldValue;

	SetConsoleTextAttribute(hConsole, 7);

	std::cout << ")\n";
}

void Player::ShowExpBar() const
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int barWidth = 20;

	if (expToNextLevel <= 0)
	{
		std::cout << "[--------------------] 0/0 (0%)\n";
		return;
	}

	int filled = (exp * barWidth) / expToNextLevel;

	if (filled > barWidth)
	{
		filled = barWidth;
	}
	int percent = (exp * 100) / expToNextLevel;

	if (percent > 100)
	{
		percent = 100;
	}

	std::cout << "[";
	for (int i = 0; i < barWidth; i++)
	{
		if (i < filled)
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "#";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 8);
			std::cout << "-";
		}
	}

	SetConsoleTextAttribute(hConsole, 7);

	std::cout << "] "
		<< exp << "/" << expToNextLevel
		<< " (" << percent << "%)\n";
}

void Player::LevelUp()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (level >= maxLevel)
	{
		exp = 0;
		std::cout << "최대 레벨에 도달했습니다.\n";
		return;
	}

	while (level < maxLevel && exp >= expToNextLevel)
	{
		exp -= expToNextLevel;

		int oldLevel = level;
		int oldMaxHp = maxHp;
		int oldAttack = attack;

		level++;

		maxHp += level * 20;
		attack += level * 5;
		hp = maxHp;


		SetConsoleTextAttribute(hConsole, 9);
		std::cout << "Level Up!\n";
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << "====== Stat Increase ======\n";
		PrintStatChange("Level", oldLevel, level);
		PrintStatChange("HP", oldMaxHp, maxHp);
		PrintStatChange("Attack", oldAttack, attack);
		std::cout << "===========================\n";

		if (level >= maxLevel)
		{
			exp = 0;
			std::cout << "최대 레벨에 도달했습니다.\n";
			break;
		}
	}
}

void Player::ShowStatus() const
{
	std::cout << "==================== Status ====================" << std::endl;
	std::cout << "Player : " << name << std::endl;
	std::cout << "무기 : " << myWeapon << std::endl;
	std::cout << "Level : " << level << std::endl;
	std::cout << "HP : " << hp << " / " << maxHp << std::endl;
	std::cout << "공격력 : " << attack << std::endl;
	std::cout << "경험치 : ";
	ShowExpBar();
	std::cout << "================================================" << std::endl;
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

	if (hp > maxHp)
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

void Player::ResetNickName()
{
	std::string rename;
	std::cout << "이름을 다시 설정해 주세요" << std::endl;
	std::cin >> rename;
	name.assign(rename);
}
void Player::GetRest()
{
	std::cout << "휴식을 취했습니다" << std::endl;
	hp = maxHp;
	std::cout << "[현재 체력 :" << hp << "/ 최대 체력 :" << maxHp << "]" << std::endl;
}
void Player::SetArmedWeapon(int value)
{
	currentWeapon = static_cast<WeaponType>(value);
}

Player::WeaponType Player::GetArmedWeapon()
{
	return currentWeapon;
}

void Player::WeaponName()
{

	if (currentWeapon == WeaponType::non)
	{
		myWeapon = "맨손";
	}
	else if (currentWeapon == WeaponType::pistol)
	{
		myWeapon = "권총";
	}
	else if (currentWeapon == WeaponType::shotgun)
	{
		myWeapon = "샷건";
	}
	else
	{
		myWeapon = "보급형 서바이벌 나이프";
	}
}
void Player::CurrentWeaponType()
{
	//인벤토리에서 무기를 소유중인지 받아오고 소유중이 아니면 소유중이 아님을 출력하는 함수를 선언하려고했는데 "Inventory.h" 헤더파일을 가져오면 Inventory 헤더에 있는 Item 헤더에서 Player 헤더를 사용중이라 문제가 발생함
	//Inventory pistol = HasPistol();
	//if(pistol == false)
	//{
	//	std::cout << "권총을 소유중이지 않습니다." << std::endl;
	//}
	//weapon을 enum클래스로 만드는걸 고려해봐야 할 듯
	//char Input = _getch();
	//Input = std::tolower(Input);

	//while()
	//switch (Input)
	//{
	//case '1':
	if (pistolIsArmed == false)
	{
		std::cout << "권총을 장착했습니다." << std::endl;
		pistolIsArmed = true;
		shotgunIsArmed = false;
	}
	else
	{
		std::cout << "이미 장착중입니다." << std::endl;
		//_getch();
		//break;
	}
	//case '2':
	if (shotgunIsArmed == false)
	{
		std::cout << "샷건을 장착했습니다." << std::endl;
		shotgunIsArmed = true;
		pistolIsArmed = false;
	}
	else
	{
		std::cout << "이미 장착중입니다." << std::endl;
	}
	//case '3':
}