#pragma once
#include "Player.h"
#include <iostream>
#include <string>

Player::Player()
{

}

Player::Player(std::string Innick_name) : nick_name(Innick_name), level(1), maxHp(200), hp(200), damage(30), exp(0)
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