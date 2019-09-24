#pragma once
#include<iostream>


class Player
{
private:
	int score;
	std::string name;
	int head;
	int leftHand;
	int rightHand;
	int body;
	int legs;
	int heart;
	int level;
public:
	Player();
	~Player();
	int getScore() { return score; };
	std::string getName() { return name; };
	int getHead() { return head; };
	int getLeftHand() { return leftHand; };
	int getRightHand() { return rightHand; };
	int getBody() { return body; };
	int getLegs() { return legs; };
	int getHeart() { return heart; };
	int getLevel() { return level; };
	void setScore(int score);
	bool checkSpace();
	void setName();
	void copyName(std::string buffer);
	void readScoreFromTabble(std::string buffer);
	void setLeftHand(int leftHand);
	void setRightHand(int rightHand);
	void setBody(int body);
	void setLegs(int legs);
	void setHeart(int heart);
	void setLevel(int level);
	void setHead(int head);
	friend class Enemy;


};

