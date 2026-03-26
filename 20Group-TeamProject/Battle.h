#pragma once
#include "Player.h"
#include "Item.h"
#include "Zombie.h"
#include <memory>

class Battle
{
	int turn;


	ReturnValue Start(Player& player);
	int Random_();
};

struct ReturnValue
{
	Item item;
	int level;
	int hp;
};

