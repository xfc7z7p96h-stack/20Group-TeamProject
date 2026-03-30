#pragma once
#include "Player.h"
#include "Item.h"
#include "Zombie.h"
#include "Inventory.h"
#include <memory>

class Battle
{
private:
    int turn = 0;

    bool PlayerAttack(Player& player, Zombie& monster, AttackType attackType); //플레이어 공격 함수
    void MonsterCounter(Player& player, Zombie& monster, AttackType attackType);
    void BattleReward(Player& player, Inventory& inven);

    int AttackDamage(Player& player, AttackType attackType);
    bool UseAmmo(Inventory& inven, AttackType attackType);
    void AttackMessage(AttackType attackType);
    void MonsterStatus(const Zombie& monster);

public:
    void Encounter(Player& player, Inventory& inven);

    Item RandomItem();
    int RandomGold();
};