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
ReturnValue Battle::Start(Player& player)
{
	

	if (player.GetHp() >= 0)
	{
		int RandomMonster = Random_() %3; // 0 ~ 2


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
	
		
		//ÇÃ·¹ÀÌ¾î °ø°Ý

		

		if (monster->IsAlive()  == false)
		{
			int randomItem = Random_();
			int randomItemAmount = Random_() % 3;




			//°æÇèÄ¡ È¹µæ, ¾ÆÀÌÅÛ È¹µæ
			return;
		}
		else
		{
			monster.Attack(attack)->player;
		}

	}
}
