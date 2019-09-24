#pragma once
#include"Player.h"
#include"Enemy.h"

class Event
{
private:
	int  typeOfEvent;
public:
	Event();
	~Event();
	int defineEvent();
	void profitableOffer(Player &player);
	void mathTest(Player &player);
	void gift(Player &player);
	void fight(Player &player, Enemy enemy, int &countOfMonsters);
	void pit(Player &player);
	void firstAidKit(Player &player);

};



