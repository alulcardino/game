#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <ctime>

Enemy::Enemy()
{
	damage = 1;
	treasure = 1;
}

Enemy::~Enemy()
{
}

void Enemy::defineEnemy(int count)
{
	srand(time(NULL));
	damage = count*5 + rand() % 10;

}

void Enemy::defineTreasure(int count, Player &player)
{
	treasure = count + rand() % 10;
	srand(time(NULL));
	switch (rand() % 6)
	{
	case 1:
		std::cout << "Congratulations, you improved your brain + " << treasure;
		player.setHead(player.getHead() + treasure);
		break;
	case 2:
		std::cout << "Congratulations, you improved your armor + " << treasure;
		player.setBody(player.getBody() + treasure);
		break;
	case 3:
		std::cout << "Congratulations, you improved your left hand + " << treasure;
		player.setLeftHand(player.getLeftHand() + treasure);
		break;
	case 4:
		std::cout << "Congratulations, you improved your right hand + " << treasure;
		player.setRightHand(player.getRightHand() + treasure);
		break;
	case 5:
		std::cout << "Congratulations, you improved your legs + " << treasure;
		player.setLegs(player.getLegs() + treasure);

		break;
	default:
		break;
	}

	std::cout << "\nYou've reached next level!";
	player.level++;

}
