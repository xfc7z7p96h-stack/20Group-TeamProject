#include <iostream>
#include "Logger.h"
#include "Player.h"
#include "Battle.h"
#include "Inventory.h"
#include "Item.h"
#include "Game.h"


int main()
{
    Battle battle; // 생성자 호출용
    Game game;

    game.Run();
    return 0;
}