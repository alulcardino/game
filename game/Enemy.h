#pragma once
#include"Player.h"
class Enemy
{
private:
	int damage;
	int treasure;
public:
	Enemy();
	~Enemy();
	void defineEnemy(int count);
	void defineTreasure(int count, Player &player);
	int getDamage() { return damage; };
	friend class Player;
	

};

