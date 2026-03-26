#pragma once
#include "Player.h"
#include "Item.h"
#include "Zombie.h"
#include <memory>
#include "Inventory.h"

class Battle
{
	int turn;


	void Start(Player& player,Inventory inven );
	int Random_();
	Item RandomItem(int r);
	int RandomGold(int r);
};



