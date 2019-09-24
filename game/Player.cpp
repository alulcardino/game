#include "Player.h"
#include <iomanip>
#include <iostream>
#include"conio.h"
#include <string> 



Player::Player()
{
	heart = 3;
	head = 1;
	body = 0;
	rightHand = 1;
	leftHand = 0;
	legs = 1;
	level = 2;
	name = "";
	score = 0;
}

Player::~Player()
{

}

void Player::setScore(int score)
{
	this->score = score;
}

bool Player::checkSpace()
{
	if (name.find(' ') != std::string::npos)
		return true;
	else return false;
}


void Player::setName()
{
	std::getline(std::cin, name);
}

void Player::copyName(std::string buffer)
{
	name = buffer;
}

void Player::readScoreFromTabble(std::string buffer)
{
	score = stoi(buffer);
}

void Player::setLeftHand(int leftHand)
{
	this->leftHand = leftHand;
}

void Player::setRightHand(int rightHand)
{
	this->rightHand = rightHand;
}

void Player::setBody(int body)
{
	this->body = body;
}

void Player::setLegs(int legs)
{
	this->legs = legs;
}

void Player::setHeart(int heart)
{
	this->heart = heart;

}

void Player::setLevel(int level)
{
	this->level = level;
}

void Player::setHead(int head)
{
	this->head = head;
}

