#pragma once
#include "Player.h"
#include "Item.h"
#include "Zombie.h"
#include "Inventory.h"
#include <memory>
#include <random>

class Battle
{
private:
    int turn = 0;

public:

    void Encounter(Player& player, Inventory& inven);

    Item RandomItem();
    int RandomGold();
};


