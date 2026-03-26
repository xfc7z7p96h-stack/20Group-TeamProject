#include "Battle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int Battle::Random_()
{
	srand(time(0));

	int random = rand() % 10; // 0 ~ 9

	return random;
}
void Battle::Start(Player& player, Inventory inven)
{


	if (player.GetHp() >= 0)
	{
		int RandomMonster = Random_() % 3; // 0 ~ 2


		std::unique_ptr<Zombie> monster;
		switch (RandomMonster)
		{
		case 0:
		{
			monster = std::make_unique<ArmoredZombie>();
			break;
		}
		case 1:
		{
			monster = std::make_unique<NormalZombie>();
			break;
		}
		case 2:
		{
			monster = std::make_unique<FastZombie>();
			break;
		}
		}


		//«√∑π¿ÃæÓ ∞¯∞›



		if (monster->IsDead() == false)
		{
			int randomItem = Random_();
			int randomItemAmount = Random_() % 3;

			inven.AddItem(RandomItem(Random_())); // ∑£¥˝ æ∆¿Ã≈€ √ﬂ∞°
			
			inven.AddGold(RandomGold(Random_())); // ∑£¥˝ ∞ÒµÂ




			//∞Ê«Ëƒ° »πµÊ, æ∆¿Ã≈€ »πµÊ
			return;
		}
		else
		{

		}

	}
}

Item Battle::RandomItem(int r)
{
	r % 4; // 0 ~ 1
	switch (r)
	{
	case 0:
	{
		Item HpPotion("HP Potion", 50, ItemType::HP_POTION);
		return HpPotion;
	}
	case 1:
		Item AttackPotion("Attack Potion", 10, ItemType::ATTACK_POTION);
		return AttackPotion;
	}
}
int Battle::RandomGold(int r)
{
	r + 3;
	if (r < 8)
	{
		r * 2; // ∞ÒµÂ √÷º“ µÂ∂¯æÁ 6up 15down
	}
	if (r > 15)
	{
		r = 15;
	}
	return r;
	
}