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
    std::mt19937 gen; // 랜덤 생성 엔진 변수 선언. 초기화는 cpp파일에서 합니다.

public:
    Battle();

    void Encounter(Player& player, Inventory& inven);

	int RandomRange(int min, int max); // min ~ max 범위의 랜덤 정수값을 반환하는 함수
    Item RandomItem();
    int RandomGold();
};


