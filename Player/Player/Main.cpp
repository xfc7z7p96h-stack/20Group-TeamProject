#include "Player.h"
#include <iostream>
#include <string>
int main()
{
	Player* player = nullptr;
	std::string nickname;
	std::cout << "닉네임을 입력하세요 :" << std::endl;
	std::cin >> nickname;
	player = new Player(nickname);
	player->PlayerStatus();

	player->SetDamage(100);
	player->PlayerStatus();

	delete player;
	player = nullptr;
	return 0;
}