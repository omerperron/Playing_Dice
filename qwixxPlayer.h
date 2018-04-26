#ifndef QWIXXPLAYER
#define QWIXXPLAYER

#include <iostream>
#include "player.h";
#include "rollOfDice.h"
#include "qwixxScoreSheet.h"
using namespace std;

class QwixxPlayer: public Player{
	QwixxScoreSheet scoreSheet; //score sheet of player
public:
	QwixxPlayer(string _name = "unknown") : 
		Player(_name),
		scoreSheet(QwixxScoreSheet(_name))  //initialise score sheet
		{}
	void inputBeforeRoll(RollOfDice &dice); //get input before roll
	void inputAfterRoll(RollOfDice &dice); //get input after roll
	void printScoreSheet(bool gameOver = false); //print information
	bool checkGameOver(); //checks if conditions are true for the game to be over

};

#endif