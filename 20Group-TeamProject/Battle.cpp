#include "Battle.h"
#include "Logger.h"
#include "Random.h"
#include <windows.h>
#include <iostream>
#include <memory>
#include <conio.h>
#include <cstdlib>

void ClearKeyBuffer()
{
    while (_kbhit())
    {
        _getch();
    }
}

int Battle::AttackDamage(Player& player, AttackType attackType)      ////////////공격 데미지 결정
{
    if (attackType == AttackType::Pistol)
    {
        return player.GetAttack() + 30 * player.GetLevel();
    }
    else if (attackType == AttackType::Shotgun)
    {
        return player.GetAttack() + 70 * player.GetLevel();
    }

    return player.GetAttack();
}

bool Battle::UseAmmo(Inventory& inven, AttackType attackType)       ///////////총알 사용
{
    if (attackType == AttackType::Pistol)
    {
        if (inven.GetPistolAmmo() <= 0)
        {
            std::cout << "\n권총 탄약이 없습니다.\n";
            return false;
        }

        inven.ConsumePistolAmmo();
        return true;
    }
    else if (attackType == AttackType::Shotgun)
    {
        if (inven.GetShotgunAmmo() <= 0)
        {
            std::cout << "\n샷건 탄약이 없습니다.\n";
            return false;
        }

        inven.ConsumeShotgunAmmo();
        return true;
    }

    return true;
}

void Battle::AttackMessage(AttackType attackType)                 //////////////공격 메세지
{
    if (attackType == AttackType::Pistol)
    {
        std::cout << "\n권총 사격!\n\n";
    }
    else if (attackType == AttackType::Shotgun)
    {
        std::cout << "\n샷건 발사!\n\n";
    }
    else
    {
        std::cout << "\n칼로 찔렀다!\n\n";
    }

    Sleep(500);
}

void Battle::MonsterStatus(const Zombie& monster)                         //////////////몬스터 정보 함수
{
    std::cout << "\n[ " << monster.GetName() << " ]\n";
    std::cout << "체력 " << monster.GetHp() << "/" << monster.GetMaxHp() << "\n";
    std::cout << "공격력 " << monster.GetAttack() << "\n";
    std::cout << monster.GetSpecialText() << "\n\n";
}

bool Battle::PlayerAttack(Player& player, Zombie& monster, AttackType attackType) /////////////// 플레이어 공격 함수
{
    int damage = AttackDamage(player, attackType);

    bool critical = Random::Chance(10);            /////////////// 크리티컬 확률 10%, 3배 데미지
    if (critical)
    {
        std::cout << "\n...본의 아니게 머리를 정확히 노렸다!(X 3)\n\n";
        Sleep(500);

        damage = static_cast<int>(damage * 3.0f);
    }

    if (monster.TryDodge(attackType))
    {
        std::cout << "\n" << monster.GetName() << "가 공격을 회피했다...\n";
        return false;
    }

    monster.TakeDamage(damage);

    Logger::Damage(monster.GetName(), damage);
    Logger::Space();

    if (monster.IsDead())
    {
        std::cout << monster.GetName() << "가 쓰러졌다...\n\n";
        Sleep(500);
        return true;
    }

    MonsterCounter(player, monster, attackType);
    return false;
}

void Battle::MonsterCounter(Player& player, Zombie& monster, AttackType attackType)       //////////////몬스터 반격 함수
{
    if (!monster.CanCounter(attackType))
    {
        return;
    }

    int monsterDamage = monster.GetAttack();

    Sleep(500);
    std::cout << "\n" << monster.GetName() << "가 달려들어 반격했다..!\n\n";
    Sleep(500);

    player.TakeDamage(monsterDamage);
    Logger::Damage(player.GetName(), monsterDamage);

    monster.OnSuccessfulCounter(monsterDamage);

    NormalZombie* normalZombie = dynamic_cast<NormalZombie*>(&monster);
    if (normalZombie != nullptr)
    {
        std::cout << "\n" << monster.GetName() << "가 피를 마셔 체력을 회복했다...\n";
        std::cout << monster.GetName() << " HP : " << monster.GetHp() << "/" << monster.GetMaxHp() << "\n";
        Sleep(500);
    }

    if (player.IsDead())
    {
        std::cout << "\n당신은 사망했습니다.\n";
        std::cout << "게임 오버.\n";
        std::exit(0);
    }
}

void Battle::BattleReward(Player& player, Inventory& inven) /////////////////////////// 전투 보상 함수
{
    Item rewardItem = RandomItem();
    int rewardGold = RandomGold();

    player.GainExp(100);
    Sleep(500);

    inven.AddItem(rewardItem);
    Sleep(500);

    inven.AddGold(rewardGold);
    Sleep(500);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Battle::Encounter(Player& player, Inventory& inven)        /////////////////////////// 인카운터 본문
{
    if (player.IsDead())
    {
        std::cout << "이미 사망한 상태입니다.\n";
        _getch();
        std::exit(0);
    }

    int randomMonster = Random::Range(0, 4);           /////////////// 출현 확률 피좀비 60%, 갑옷좀비 20%, 재빠른 좀비 20%
    std::unique_ptr<Zombie> monster;

    switch (randomMonster)
    {
    case 0:
        monster = std::make_unique<ArmoredZombie>();
        break;
    case 1:
        monster = std::make_unique<NormalZombie>();
        break;
    case 2:
        monster = std::make_unique<FastZombie>();
        break;
    case 3:
        monster = std::make_unique<NormalZombie>();
        break;
    case 4:
        monster = std::make_unique<NormalZombie>();
        break;
    }

    int playerLevel = player.GetLevel();
    monster->AddMaxHp(playerLevel * 20);
    monster->AddAttack(playerLevel * 5);

    if (!monster)
    {
        std::cout << "적 생성에 실패했습니다.\n";
        _getch();
        return;
    }

    while (true)
    {
        system("cls");

        player.ShowStatus();
        MonsterStatus(*monster);

        std::cout << "================================================\n";
        std::cout << "[Q] 공격   [W] 인벤토리   [E] 도망\n";

        ClearKeyBuffer();
        char input = _getch();

        if (input >= 'a' && input <= 'z')
        {
            input = input - 32;
        }

        if (input == 'Q')
        {
            Player::WeaponType weapon = player.GetArmedWeapon();
            AttackType attackType = AttackType::Knife;

            if (weapon == Player::WeaponType::pistol)
            {
                attackType = AttackType::Pistol;
            }
            else if (weapon == Player::WeaponType::shotgun)
            {
                attackType = AttackType::Shotgun;
            }

            if (!UseAmmo(inven, attackType))
            {
                ClearKeyBuffer();
                _getch();
                continue;
            }

            AttackMessage(attackType);

            bool battleEnd = PlayerAttack(player, *monster, attackType);

            if (battleEnd)
            {
                BattleReward(player, inven);
                ClearKeyBuffer();
                _getch();
                return;
            }

            ClearKeyBuffer();
            _getch();
        }
        else if (input == 'W')
        {
            system("cls");
            inven.OpenInventory(player);
        }
        else if (input == 'E')
        {
            std::cout << "\n도망을 시도합니다...\n\n";
            Sleep(500);

            bool runSuccess = Random::Chance(50);

            if (runSuccess)
            {
                std::cout << "\n도망에 성공했습니다.\n\n";
                ClearKeyBuffer();
                _getch();
                return;
            }
            else
            {
                int monsterDamage = monster->GetAttack();

                std::cout << "\n도망에 실패했습니다!\n\n";
                Sleep(500);

                player.TakeDamage(monsterDamage);

                std::cout << "\n" << monster->GetName() << "에게 붙잡혀 공격당했다...\n\n";
                Logger::Damage(player.GetName(), monsterDamage);

                if (player.IsDead())
                {
                    std::cout << "\n당신은 사망했습니다.\n";
                    std::cout << "게임 오버.\n";
                    std::exit(0);
                }

                ClearKeyBuffer();
                _getch();
            }
        }
    }
}

Item Battle::RandomItem()
{
    switch (Random::Range(1, 4))
    {
    case 1:
        return Item("샷건 탄약", Random::Range(1, 2), ItemType::SHOTGUN_AMMO);
    case 2:
        return Item("권총 탄약", Random::Range(2, 3), ItemType::PISTOL_AMMO);
    case 3:
        return Item("권총 탄약", Random::Range(2, 3), ItemType::PISTOL_AMMO);
    case 4:
        return Item("권총 탄약", Random::Range(2, 3), ItemType::PISTOL_AMMO);
    }

    return Item("권총 탄약", 1, ItemType::PISTOL_AMMO);
}

int Battle::RandomGold()
{
    return Random::Range(50, 100);
}