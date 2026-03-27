#pragma once
#include <iostream>
#include "string.h"

class Game
{
private:

    std::string CurrentPlace;
    int CurrentFloor;
    bool bchaincutter;
	bool firstfloorclear;

public:
    Game();

    void Run();
    void ShowStatus();

    void FirstFloor();
    void FirstFloor_Corridor();
    void FirstFloor_storage();
    void FirstFloor_CorridorEnd();
};


