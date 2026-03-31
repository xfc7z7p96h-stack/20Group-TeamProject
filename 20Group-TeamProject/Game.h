#pragma once
#include <iostream>
#include <string>
#include "Battle.h"

enum RoomState
{
    ROOM_OUTSIDE = 0,
    ROOM_FIRSTFLOOR_CORRIDOR,
    ROOM_FIRSTFLOOR_STORAGE,
    ROOM_FIRSTFLOOR_CORRIDOREND,

    ROOM_SECONDFLOOR_LOBBY,
    ROOM_SECONDFLOOR_RESTROOM,
    ROOM_SECONDFLOOR_MEETINGROOM,
    ROOM_SECONDFLOOR_SECRETROOM,

    ROOM_THIRDFLOOR_MAINHALL,
    ROOM_THIRDFLOOR_ISOLATIONROOM,
    ROOM_THIRDFLOOR_ARCHIVE,
    ROOM_THIRDFLOOR_GENERATORROOM,
    ROOM_THIRDFLOOR_CONTROLROOM,
    ROOM_THIRDFLOOR_SURGERYROOM
};

class Game
{
private:
    Battle battle;
    Player player;
    Inventory inven;

    bool inventoryOpen;
    RoomState CurrentRoom;
    bool FirstFloorIntro;
    bool SecondFloorIntro;
    bool ThirdFloorIntro;

    std::string CurrentPlace;
    int CurrentFloor;
    bool chaincutter;
    bool firstfloorclear;
    bool secretRoom;
    bool secretRoomQuest;
    bool secretRoomKey;
    int corridorCount;
    int storageCount;
    int corridorEndCount;
    bool storageWater;
    bool restroombread;
    bool generatorromm;
    bool generatorrommWater;
    bool controlroomWater;
    bool meetingroomBread;
    bool corridorBW;

    bool archivePuzzle;
    bool isolationRoomitem;
    bool isolationRoomitem2;
    bool archiveitem;
    bool sergeryRoomitem;
    bool secretPassage;
    int sergeryRoomCount;
    bool Opened;
    bool fuse;
    bool ending;

    int breadCount;
    int waterCount;

public:
    Game();

    void Run();
    void ShowStatus();
    void ShowHelp();

    void RandomEncounter();

    void ArchivePuzzle();
    void ControlRoomPuzzle();
    void Ending();
};