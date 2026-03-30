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
    void MonsterCounter(Player& player, Zombie& monster, AttackType attackType); //몬스터 반격 함수
    void BattleReward(Player& player, Inventory& inven); // 전투 보상 함수

    int AttackDamage(Player& player, AttackType attackType); // 데미지 결정 함수
    bool UseAmmo(Inventory& inven, AttackType attackType); // 탄약 소비 함수
    void AttackMessage(AttackType attackType); // 공격 메세지 함수
    void MonsterStatus(const Zombie& monster); // 몬스터 정보 함수

public:
    void Encounter(Player& player, Inventory& inven);

    Item RandomItem();
    int RandomGold();
};