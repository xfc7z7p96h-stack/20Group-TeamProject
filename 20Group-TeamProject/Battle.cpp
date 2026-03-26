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
ReturnValue Battle::Start()
{
	

	if (Player.GetHp() > 0)
	{
		int RandomMonster = Random_() %3; // 0 ~ 2
		switch (RandomMonster)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		}
		//ÇÃ·¹ÀÌ¾î °ø°Ý

		

		if (monster.IsAlive == false)
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
