#include "Battle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



// 수정한 랜덤 함수에 대한 설명입니다.

Battle::Battle() // 생성자가 호출될 때 랜덤 시드값을 초기화하고, 그 값으로 랜덤 생성 엔진을 초기화합니다.
{ // **주의** Battle 생성자는 프로그램이 시작될 때 한 번만 호출되어야 합니다. 안그러면 랜덤값이 매번 똑같이 나올 수도 있음.
    std::random_device rd; // 시드값을 랜덤하게 초기화
    gen = std::mt19937(rd()); // 랜덤 생성 엔진 초기화
	// 여기서 랜덤 시드값 변수인 rd때문에 gen의 값이 완전히 랜덤하게 초기화됩니다. 만약 rd가 없다면, gen은 항상 같은 시드값으로 초기화되어 매번 같은 랜덤값이 나오게 됩니다.
}

int Battle::RandomRange(int min, int max) // min ~ max 범위의 랜덤 정수값을 반환하는 함수입니다.
{
    std::uniform_int_distribution<int> dist(min, max); // min ~ max까지 모든 숫자가 균등하게 나오게 하는 랜덤 규칙을 생성합니다.
	return dist(gen); // 랜덤 생성 엔진 gen을 사용해서 dist 규칙에 따라 랜덤값을 생성하여 반환합니다.

	// 즉, dist는 gen의 '최대값'을 min ~ max 범위로 변환하는 역할을 합니다.
   
    // 예를 들어 이 함수에서 dist의 범위를 1(min), 2(max)로 설정했다고 가정해보겠습니다.(1 ~ 2)
    // gen의 최대값은 4294967295입니다.(그렇게 정해져 있음)
    // 그러므로 gen은 0 ~ 4294967295 사이의 랜덤값을 생성합니다.
    // dist는 gen의 최대값을 정확히 반반 나눠서 각 덩어리에 1이라는 번호와 2라는 번호를 붙입니다.(범위를 1~2로 설정했기 떄문에)
	// gen이 0 ~ 2147483647 사이의 랜덤값을 생성했다면 dist는 1을 반환하고, 2147483648 ~ 4294967295 사이의 랜덤값을 생성했다면 2를 반환합니다.
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
    int playerAnswer;
    std::cout << "\n[1.맨손 공격 " << " /" << "2.인벤토리 " << " /" << "3.총으로 공격]" << std::endl;

    std::cin >> playerAnswer;
    switch (playerAnswer)
    {
    case 1:
    {
        monster->TakeDamage(player.GetAttack()); // 맨손 떄리기
        break;
    }
    case 2:
    {
        if (inven.GetSize < 0)
        {
            std::cout << "\n인벤토리가 비었습니다\n";
        }
        else
        {
            inven.ShowInventory();
            std::cout << "\n몇번쨰 아이템을 사용하시겠습니다??" << "\nanswer:";
            std::cin >> playerAnswer;
            inven.UseItem(playerAnswer, player);
        }
    }

    case 3:
    {
        if()// 총 구현
    }
    }


    std::cout << "\n공격!" << std::endl;
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
    std::cout << "\n" << monster->GetName() << "의 반격!" << std::endl;
    player.TakeDamage(monster->GetAttack());

    std::cout << "남은 HP: " << player.GetHp() << "/" << player.GetMaxHp() << std::endl;

    if (player.IsDead())
    {
        std::cout << "당신은 사망했습니다." << std::endl;
    }
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