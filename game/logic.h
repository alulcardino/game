#pragma once
#include"Player.h"
#include<vector>
#include<string>
#include<iostream>



enum move
{
	RIGHT, UP, LEFT, DOWN, ENTER, SPACE, ESC
};

move controlDir();


void recordTabble();

bool draw(int& position, int &distance, bool &meet);

void sortTabble(Player player);

void readTabble(std::vector<Player>& gamer);