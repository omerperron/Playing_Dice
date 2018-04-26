
#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "rollOfDice.h";
using namespace std;


class Player{
	string name;
	bool isActive = false;


public:
	

	Player(string _name = "unknown") : 
		name(_name)
		{};
	string getName(); //get name of player
	bool getIsActive(); //get if player is active
	void setIsActive(bool a); //set player activity
	virtual void inputBeforeRoll(RollOfDice &dice) = 0; //get input of player before roll
	virtual void inputAfterRoll(RollOfDice &dice) = 0; //get input of player after roll
	virtual void printScoreSheet(bool gameOver) = 0; //print the players score sheet
	virtual bool checkGameOver() = 0; //check if game is over


};

#endif