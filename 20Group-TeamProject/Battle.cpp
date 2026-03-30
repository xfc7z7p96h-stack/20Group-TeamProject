#include "Battle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Random.h"


// 수정한 랜덤 함수에 대한 설명입니다.

Battle::Battle() // 생성자가 호출될 때 랜덤 시드값을 초기화하고, 그 값으로 랜덤 생성 엔진을 초기화합니다.
{ // **주의** Battle 생성자는 프로그램이 시작될 때 한 번만 호출되어야 합니다. 안그러면 랜덤값이 매번 똑같이 나올 수도 있음.
    std::random_device rd; // 시드값을 랜덤하게 초기화
    gen = std::mt19937(rd()); // 랜덤 생성 엔진 초기화
	// 여기서 랜덤 시드값 변수인 rd때문에 gen의 값이 완전히 랜덤하게 초기화됩니다. 만약 rd가 없다면, gen은 항상 같은 시드값으로 초기화되어 매번 같은 랜덤값이 나오게 됩니다.
}




void Battle::Encounter(Player& player, Inventory& inven)
{
    if (player.IsDead())
    {
        std::cout << "사망한 상태입니다." << std::endl;
        return;
    }

    int randomMonster = RandomRange(0, 2); // 0 ~ 2 사이의 랜덤값 생성
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
    }

    if (!monster)
    {
        std::cout << "좀비 생성 실패" << std::endl;
        return;
    }

    std::cout << "\n===== 전투 시작 =====" << std::endl;
    std::cout << monster->GetName() << std::endl;
    std::cout << "HP: " << monster->GetHp() << "/" << monster->GetMaxHp() << std::endl;
    std::cout << "공격력: " << monster->GetAttack() << std::endl;

    // 플레이어 공격
    int end = 1;
    bool pass = false;
    do
    {
        std::string playerAnswer;
        int manager0 = 0;
        player.ShowStatus();
        monster->ShowStatus();
        do
        {
            std::cout << "\n[Q.공격! " << " /" << "W.인벤토리 " << " /" << "E.도망!]" << std::endl;

            std::cin >> playerAnswer;
            if(playerAnswer == "Q")
            {
                Player::WeaponType weapon = player.GetArmedWeapon();
                if (weapon == Player::WeaponType::pistol) //플레이어가 총을 창착하고 있는지 없는지 판단으로 바꿔야함
                {
                    if (inven.GetPistolAmmo())
                    {
                        int gunDamage = player.GetAttack() + 10; // 총대미지 기본 설정 벨런스 조절시ㅣ 여기 조정
                        monster->TakeDamage(gunDamage);
                        monster->ShowStatus();
                        inven.ConsumePistolAmmo();
                        pass = true;
                        std::cout << "\n권총으로";
                        manager0 = 0;
                    }
                    else
                    {
                        std::cout << "\n총알이 없습니다!!";
                        manager0 = 1;
                    }
                }
                else if (weapon == Player::WeaponType::shotgun)
                {
                    if (inven.GetShotgunAmmo() > 0)
                    {
                        int gunDamage = player.GetAttack() + 25; // 총대미지 기본 설정 벨런스 조절시ㅣ 여기 조정
                        monster->TakeDamage(gunDamage);
                        monster->ShowStatus();
                        inven.ConsumeShotgunAmmo();
                        pass = true;
                        std::cout << "\n샷건으로";
                        manager0 = 0;
                    }
                    else
                    {
                        std::cout << "\n샷건 총알이 없습니다";
                    }
                }
                else
                {
                    std::cout << "\n총을 장착하고 있지 않습니다!!";
                    manager0 = 1;
                }
                if (inven.HasPistol() && inven.HasShotgun())
                {
                    monster->TakeDamage(player.GetAttack()); // 칼로 찌르기
                    monster->ShowStatus();
                    std::cout << "\n칼로";
                    manager0 = 0;
                }
                break;
            }
            else if (playerAnswer == "W")
            {
                inven.ShowInventory();
                int manager1;
                int playerAnswer;
                do
                {
                    std::cout << "\n몇번쨰 아이템을 사용하시겠습니다??" << "\nanswer:";
                    std::cin >> playerAnswer;
                    if (playerAnswer  > inven.GetSize() && playerAnswer < 0)
                    {
                        manager1 = 1;
                    }
                    else
                    {
                        manager1 = 0;
                    }
                } while (manager1);
                inven.UseItem(playerAnswer -1, player);
                manager0 = 1;

                break;
            }
            else if (playerAnswer == "E")
            {
                int randomRun = RandomRange(0, 1);

                if (randomRun == 0)
                {
                    std::cout << "\n도망 성공!! 전투 종료";
                    return;
                }
                if (randomRun == 1)
                {
                    std::cout << "\n도망 실패... 대가를 치를 차례입니다...";
                }
                manager0 = 0;
           
            }
        } while (manager0);



        std::cout << "공격!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기


        std::cout << monster->GetName() << "의 남은 HP: " << monster->GetHp() << "/" << monster->GetMaxHp() << std::endl;

        // 몬스터 처치 시
        if (monster->IsDead())
        {
            Item rewardItem = RandomItem();
            int rewardGold = RandomGold();

            std::cout << "\n처치 성공!" << std::endl;
            std::cout << "획득 아이템: " << rewardItem.GetName() << std::endl;
            std::cout << "획득 골드: " << rewardGold << std::endl;

            inven.AddItem(rewardItem);
            player.AddGold(rewardGold);

            return;
        }

        // 몬스터 반격
        if (pass = true)
        {
            std::cout << "\n좀비팔이 총보다 짧다,,!";
        }
        while (pass)
        {
            std::cout << "\n" << monster->GetName() << "의 반격!" << std::endl;
            player.TakeDamage(monster->GetAttack());

            std::cout << "남은 HP: " << player.GetHp() << "/" << player.GetMaxHp() << std::endl;

            if (player.IsDead())
            {
                std::cout << "당신은 사망했습니다." << std::endl;
                end = 0;
            }
        }
    }while (end);
}

Item Battle::RandomItem()
{
	switch (RandomRange(0, 3)) // 0 ~ 1 사이의 랜덤값 생성
    {
    case 0:
        return Item("HP Potion", 50, ItemType::HP_POTION);
    case 1:
        return Item("Attack Potion", 10, ItemType::ATTACK_POTION);
    case 2:
        return Item("Shotgun Ammo", RandomRange(1, 3), ItemType::SHOTGUN_AMMO);
    case 3:
        return Item("Pistol Ammo", RandomRange(2, 3), ItemType::PISTOL_AMMO);
    }
}


//Item Battle::RandomItem(int r)
//{
//	r % 4; // 0 ~ 1
//	switch (r)
//	{
//	case 0:
//	{
//		Item HpPotion("HP Potion", 50, ItemType::HP_POTION);
//		return HpPotion;
//	}
//	case 1:
//		Item AttackPotion("Attack Potion", 10, ItemType::ATTACK_POTION);
//		return AttackPotion;
//	}
//}

int Battle::RandomGold()
{
    return RandomRange(6, 15); // 6 ~ 15 사이의 랜덤값을 반환
}

//int Battle::RandomGold(int r)
//{
//    r = r + 3;
//
//    if (r < 8)
//    {
//        r = r * 2; // 골드 최소 드랍양 6up 15down
//    }
//
//    if (r > 15)
//    {
//        r = 15;
//    }
//
//    return r;
//}