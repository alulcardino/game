#include "Player.h"
#include"logic.h"
#include"conio.h"
#include"conio.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string> 
#include <iomanip>



move controlDir()
{
	char enter;
	enter = _getch();
	switch (enter)
	{
	case 'a':
		return LEFT;
		break;
	case 'A':
		return LEFT;
		break;
	case 's':
		return DOWN;
		break;
	case 'S':
		return DOWN;
		break;
	case 'w':
		return UP;
		break;
	case 'W':
		return UP;
		break;
	case 'd':
		return RIGHT;
		break;
	case 'D':
		return RIGHT;
		break;
	case 13:
		return ENTER;
		break;
	case ' ':
		return SPACE;
		break;
	case 27:
		return ESC;
		break;
	default:
		controlDir();
		break;
	}
}


void recordTabble()
{
	std::vector<Player> gamer;
	Player player;
	readTabble(gamer);
	int i;
	std::cout << "----------------------\n" ;
	std::cout << "|   Name    |  Score |\n";
	std::cout << "----------------------\n";

	for (i = 0; i < gamer.size(); i++)
	{
		std::cout << "|" << std::setw(10) << gamer[i].getName()<< " | " <<std::setw(6)<< gamer[i].getScore() << " |" << std::endl;
	}
	std::cout << "----------------------\n";
	std::cout << "Press any key to continue\n";
	controlDir();
	system("cls");



}

bool draw(int &position, int &distance, bool &meet)
{
	
	for (int i = 0; i < 120; i++)
		std::cout << "=";

	switch (position)
	{
	case 1:
		std::cout << " ";
		for (int j = 0; j < 20 - distance; j++)
		{
			if (j == 0 && distance <= 18)
				std::cout << "%";
			else if (j == (20 - distance - 1))
				std::cout << "?";
			else std::cout << " ";
			if (distance == 18)
				meet = true;
		}

		std::cout<< std::endl;


		for (int j = 0; j < 20 - distance; j++)
			std::cout << " ";

		std::cout << "?" << std::endl;

		for (int j = 0; j < 20 - distance; j++)
			std::cout << " ";

		std::cout << "?" << std::endl;

		break;
	case 2:
		for (int j = 0; j < 20 - distance; j++)
			std::cout << " ";

		std::cout << "?" << std::endl;


		std::cout << " ";
		for (int j = 0; j < 20 - distance; j++)
		{
			if (j == 0 && distance <= 18)
				std::cout << "%";
			else if (j == (20 - distance - 1))
				std::cout << "?";
			else std::cout << " ";
			if (distance == 18)
				meet = true;

		}

		std::cout << std::endl;



		for (int j = 0; j < 20 - distance; j++)
			std::cout << " ";

		std::cout << "?" << std::endl;

		break;
	case 3:
		for (int j = 0; j < 20 - distance; j++)
			std::cout << " ";
		
		std::cout << "?" << std::endl;

		for (int j = 0; j < 20 - distance; j++)
			std::cout << " ";

		std::cout << "?" << std::endl;

		std::cout << " ";
		for (int j = 0; j < 20 - distance; j++)
		{
			if (j == 0 && distance <= 18)
				std::cout << "%";
			else if (j == (20 - distance - 1))
				std::cout << "?";
			else std::cout << " ";
			if (distance == 18)
				meet = true;
		}

		std::cout << std::endl;

		break;
	default:
		break;
	}

	for (int i = 0; i < 120; i++)
		std::cout << "=";

	std::cout << std::endl;

	move dir;
	std::cout << "Prees ESC to exit\n";
	dir = controlDir();
	if (dir == UP)
		position--;
	else if (dir == DOWN)
		position++;
	else if (dir == RIGHT)
		distance++;
	else if (dir == ESC)
		return true;

	if (position >= 3)
		position = 3;
	if (position <= 1)
		position = 1;
	system("cls");
	return false;
}

void sortTabble(Player player)
{
	std::vector<Player> gamer;
	readTabble(gamer);
	int i = 0;
	std::vector<Player>::iterator it;
	it = gamer.begin();
	while  (i < gamer.size() &&  gamer[i].getScore() >= player.getScore())
	{
		i++;
	}
	it = i + gamer.begin();
	gamer.insert(it, player);

	std::fstream file;
	try
	{
		file.open("records.txt");
	}
	catch (const std::exception& ex)
	{
		std::cout << e	x.what() << std::endl;
	}

	for (i = 0; i < gamer.size(); i++)
		file << gamer[i].getName() << " " << gamer[i].getScore() << "\n";

	file.close();


}

void readTabble(std::vector<Player> &gamer)
{
	int i = 1;
	std::fstream file;
	std::string buffer;
	Player current;
	try
	{
		file.open("records.txt");
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	bool flag = false;
	while (!file.eof())
	{
		if (i % 2 == 1)
		{
			std::getline(file, buffer, ' ');
			current.copyName(buffer);
		}
		else
		{
			std::getline(file, buffer, '\n');
			current.readScoreFromTabble(buffer);
			gamer.push_back(current);
		}
		i++;
	}
}

