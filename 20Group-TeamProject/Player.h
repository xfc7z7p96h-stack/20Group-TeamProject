#pragma once
#include <string>
class Player
{
public:
	Player();
	Player(std::string nick_name);
	~Player();
	void SetNickName(std::string Innick_name);
	void SetLevel(int Inlevel);
	void SetMaxHp(int InmaxHp);
	void SetHp(int Inhp);
	void SetDamage(int Indamage);
	void SetExp(int Inexp);
	void PlayerStatus()const;
	std::string GetNickName();
	int GetLevel();
	int GetMaxHp();
	int GetHp();
	int GetDamage();
	int GetExp();
protected:
	std::string nick_name;
	int level;
	int maxHp;
	int hp;
	int damage;
	int exp;
};

