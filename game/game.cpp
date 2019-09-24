#include"Enemy.h"
#include"Event.h"
#include"Player.h"
#include"interface.h"
#include"logic.h"
#include<iostream>
#include<string>
#include<conio.h>
#include<ctime>




int main()
{
	int countOfMonsters = 0;
	Event event;
	Player player;
	Enemy enemy;
	move dir;
	int position = 1, positionOfPlayer = 2, distance = 0;
	bool flag = true;
	bool meet = false;
	bool newGameBool = true;
	bool stopGame = false;
	setColor(6);
	std::cout << "\n\n\n\t\t\t\t\t\tHello. stranger! Welcome to my game.\n\n\t\t\t\t\t\tPress space to show menu";
	setColor(15);
	do
	{
		dir = controlDir();
		system("cls");
		if (flag == true)
		{
			while (dir != SPACE)
			{
				setColor(6);
				std::cout << "\n\n\n\t\t\t\t\t\tHello. stranger! Welcome to my game.\n\n\t\t\t\t\t\tPress space to show menu";
				dir = controlDir();
				system("cls");
				setColor(15);

			}
		}

		if (dir == DOWN)
			position++;
		else if (dir == UP)
			position--;

		if (position >= 3)
			position = 3;
		
		if (position <= 1)
			position = 1;

		firstWindow(position);
		flag = false;

	} while (dir != ENTER);
	system("cls");
	dir = ENTER;
	while (position != 3)
	{

		if (position == 1)
		{
			if (newGameBool == true)
			{
				newGame(player);
				newGameBool = false;
			}
			system("cls");
			showCharacter(player);
			std::cout << std::endl;
			stopGame = draw(positionOfPlayer, distance, meet);
			if (meet == true)
			{
				switch (event.defineEvent())
				{
				case 1:
					event.fight(player, enemy, countOfMonsters);
					break;
				case 2:
					event.firstAidKit(player);
					break;
				case 3:
					event.gift(player);
					break;
				case 4:
					event.mathTest(player);
					break;
				case 5:
					event.pit(player);
					break;
				case 6:
					event.profitableOffer(player);
					break;
				default:
					break;
				}
				meet = false;
				distance = 0;
			}

			if (player.getLevel() < 1 || player.getHeart() < 1 || stopGame == true)
			{
				system("cls");
				if ((player.getLevel() < 1))
					std::cout << "\nYour lost all the levels. Wish you luck next time!\n";
				else if(player.getHeart() < 1)
					std::cout << "\nYou died. Wish you luck next time!\n";

				std::cout << "Your name: " << player.getName() << "\n";
				player.setScore(countOfMonsters - 1);
				std::cout << "Your score: " << player.getScore() - 1 << "\n";
				sortTabble(player);
				position = 1;
				std::cout << "Press any key to continue ";
				controlDir();
				system("cls");
				newGameBool = true;
					do
					{
						firstWindow(position);
						dir = controlDir();
						if (dir == DOWN)
							position++;
						else if (dir == UP)
							position--;

						if (position >= 3)
							position = 3;

						if (position <= 1)
							position = 1;

						system("cls");
					} while (dir != ENTER);

			}

		}
		else if (position == 2)
		{
			recordTabble();
			position = 1;
			do
			{
				firstWindow(position);
				dir = controlDir();
				if (dir == DOWN)
					position++;
				else if (dir == UP)
					position--;

				if (position >= 3)
					position = 3;

				if (position <= 1)
					position = 1;

				system("cls");
			} while (dir != ENTER);
		}

	}


	return 0;
}