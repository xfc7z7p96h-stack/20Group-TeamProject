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
	std::cout << "?¬Ô??? :" << nick_name << std::endl;
	std::cout << "??? ??? :" << maxHp << std::endl;
	std::cout << "???? ??? :" << hp << std::endl;
	std::cout << "????? :" << damage << std::endl;
	std::cout << "????? :" << exp << std::endl;
}