#include"logic.h"
#include"interface.h"
#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
#include <iomanip>





void setColor(int text) 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(text));
}

int firstWindow(int position)
{
	setColor(6);
	std::cout << "\n\n\n\n\n\t\t\t\t\tUse w,s to move. Press Enter to continue";

	switch (position)
	{
		case 1:
		{
			setColor(4);
			std::cout << "\n\n\n\t\t\t\t\t\tStart a new game";
			setColor(15);
			std::cout << "\n\n\n\t\t\t\t\t\tTabble of records";
			std::cout << "\n\n\n\t\t\t\t\t\tExit";
			return 1;
			break;
		}
		case 2:
		{
			setColor(15);
			std::cout << "\n\n\n\t\t\t\t\t\tStart a new game";
			setColor(4);
			std::cout << "\n\n\n\t\t\t\t\t\tTabble of records";
			setColor(15);
			std::cout << "\n\n\n\t\t\t\t\t\tExit";
			return 2;
			break;

		}
		case 3:
		{
			setColor(15);
			std::cout << "\n\n\n\t\t\t\t\t\tStart a new game";
			std::cout << "\n\n\n\t\t\t\t\t\tTabble of records";
			setColor(4);
			std::cout << "\n\n\n\t\t\t\t\t\tExit";
			setColor(15);
			return 3;
			break;
		default:
			break;

		}
	}

}

void newGame(Player &current)
{
	
	std::cout << "Hello, what is your name?(without spaces): ";
	current.setName();

	while (current.checkSpace())
	{
		rewind(stdin);
		std::cout << "Sorry, but can you say your name WITHOUT spaces: ";
		current.setName();
	}
}

void showCharacter(Player player)
{
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "|Name: " << std::setw(26) <<player.getName() << "|" << std::endl;
	std::cout << "|Health: " << std::setw(24) << player.getHeart() << "|" << std::endl;
	std::cout << "|Level: " << std::setw(25) << player.getLevel() << "|" << std::endl;
	std::cout << "|Brain size: " << std::setw(20) << player.getHead()  << "|" << std::endl;
	std::cout << "|Quality of armor: " << std::setw(14) << player.getBody()  << "|" << std::endl;
	std::cout << "|Bonus of the left hand: " << std::setw(8) << player.getLeftHand()  << "|" << std::endl;
	std::cout << "|Damage of the right hand: " << std::setw(6) << player.getRightHand()  << "|" << std::endl;
	std::cout << "|Power of legs: " << std::setw(17) << player.getLegs() << "|" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}