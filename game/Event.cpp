#include "Event.h"
#include"Player.h"
#include"logic.h"
#include <dos.h>
#include <iostream>
#include <ctime>
#include <windows.h>




Event::Event()
{
	typeOfEvent = 0;
}

Event::~Event()
{
}

int Event::defineEvent()
{
	srand(time(NULL));
	int random = rand() % 101;
	if (random >= 0 && random <= 50)
		return 1;
	else if (random >= 50 && random <= 60)
		return 2;
	else if (random >= 60 && random <= 70)
		return 3;
	else if (random >= 70 && random <= 80)
		return 4;
	else if (random >= 80 && random <= 90)
		return 5;
	else if (random >= 90 && random <= 100)
		return 6;
}

void Event::profitableOffer(Player &player)
{
	move choise;
	srand(time(NULL));
	int degree = 1 + rand() % 4;
	switch (degree)
	{
	case 1:
		std::cout << "You can get 2 levels, but you will lose 1 hearts. Press Enter to agree, another key to refuse";
		break;
	case 2:
		std::cout << "You can get 4 levels, but you will lose 2 hearts. Press Enter to agree, another key to refuse";
		break;
	case 3:
		std::cout << "You can get 6 levels, but you will lose 3 hearts. Press Enter to agree, another key to refuse";
		break;
	case 4:
		std::cout << "You can get 8 levels, but you will lose 4 hearts. Press Enter to agree, another key to refuse";
		break;
	default:
		break;
	}
	choise = controlDir();
	if (choise == ENTER)
	{
		player.setHeart(player.getLevel() - degree);
		player.setLevel(player.getLevel() + (2 * degree));
	}
	std::cout << "\nPress any key to continue ";
	controlDir();

}

void Event::mathTest(Player &player)
{
	srand(time(NULL));
	int answer, first, second, third;
	std::cout << "I will show you math expression! \nIf you solve it, you will get 2 levels.\nOtherwise you will lose 4 levels.You have 7 second. Good luck.\n";
	first = 1 + rand() % 10;
	second = 1 + rand() % 7;
	third = 1 + rand() % 4;
	std::cout << "Press any key to continue ";
	controlDir();
	system("cls");
	
	std::cout << "Expression: " << first << " * " << second << " % " << third;
	Sleep(3000);
	system("cls");
	std::cout << "Your answer is ";
	std::cin >> answer;
	if (first * second % third == answer)
	{
		std::cout << "You gave a right answer. Take your reward.\n";
		player.setLevel(player.getLevel() + 2);
	}
	else
	{
		std::cout << "I am sorry, but you are wrong. You lost hearts\n";
		player.setLevel(player.getLevel() - 4);
	}
	std::cout << "\nPress any key to continue ";
	controlDir();

}

void Event::gift(Player &player)
{
	int bonus = 0;
	srand(time(NULL));
	bonus = 1 + rand() % 5;
	std::cout << "Wow, you are lucky person.\n";
	switch (1 + rand() % 5)
	{
	case 1:
		std::cout << "You became smarter. Brain + " << bonus;
		player.setHead(player.getHead() + bonus);
		break;

	case 2:
		std::cout << "You cleaned up armor. Armor + " << bonus;
		player.setBody(player.getBody() + bonus);
		break;

	case 3:
		std::cout << "You wrote all the lectures. Right hand + " << bonus;
		player.setRightHand(player.getRightHand() + bonus);
		break;

	case 4:
		std::cout << "I don't know how, but you improved your left hand. Left hand + " << bonus;
		player.setHead(player.getHead() + bonus);
		break;

	case 5:
		std::cout << "1000 km per day helped pump your legs. Legs + " << bonus;
		player.setHead(player.getHead() + bonus);
		break;

	default:
		break;
	}
	std::cout << "\nPress any key to continue ";
	controlDir();
}

void Event::fight(Player &player, Enemy enemy, int &countOfMonsters)
{
	int playerAll = player.getBody() + player.getHead() + player.getLeftHand() 
		+ player.getRightHand() + player.getLevel() + player.getLegs();

	enemy.defineEnemy(countOfMonsters);
	std::cout << "Your power: " << playerAll << "\n";
	std::cout << "Your enemy's power: " << enemy.getDamage() << "\n";

	if (playerAll > enemy.getDamage())
	{
		std::cout << "You beat this enemy!" << std::endl;
		enemy.defineTreasure(countOfMonsters, player);
	}
	else
	{
		std::cout << "Oops, you lost the battle :(" << std::endl;
		player.setLevel(player.getLevel() - 1);
		player.setHeart(player.getHeart() - 1); 

	}
	std::cout << "\nPress any key to continue ";
	controlDir();
	countOfMonsters++;
}

void Event::pit(Player &player)
{
	std::cout << "You fell down in the pit. \nIf you want to survive, you must lose 2 levels";
	player.setLevel(player.getLevel() - 2);
	std::cout << "\nPress any key to continue ";
	controlDir();
}

void Event::firstAidKit(Player &player)
{
	std::cout << "You found first aid kit. Take 3 hearts\n";
	player.setHeart(player.getHeart() + 3);
	std::cout << "\nPress any key to continue ";
	controlDir();
}


