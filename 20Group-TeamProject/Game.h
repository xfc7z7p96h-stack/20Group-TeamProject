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
    bool secretRoom;
    bool secretRoomQuest;
    bool secretRoomKey;
    int corridorCount;
	int storageCount;
	int corridorEndCount;

public:
    Game();

    void Run();
    void ShowStatus();
    void ShowHelp();

    void FirstFloor();
    void FirstFloor_Corridor();
    void FirstFloor_storage();
    void FirstFloor_CorridorEnd();

	void SecondFloor();
    void SecondFloor_Lobby();
    void SecondFloor_Restroom();
    void SecondFloor_Meetingroom();
    void SecondFloor_Secretroom();

};


