#ifndef QWINTOPLAYER
#define QWINTOPLAYER

#include <iostream>
#include "player.h";
#include "rollOfDice.h";
#include "qwintoScoreSheet.h";
using namespace std;

class QwintoPlayer: public Player{
	QwintoScoreSheet scoreSheet; //QwintoScoreSheet of player
public:
	QwintoPlayer(string _name = "unknown") : 
		Player(_name),
		scoreSheet(QwintoScoreSheet(_name)) 
		{}
	void inputBeforeRoll(RollOfDice &dice); //input of player before roll
	void inputAfterRoll(RollOfDice &dice); //input of player after roll
	void printScoreSheet(bool gameOver = false); //prints the score sheet infromation
	bool checkGameOver(); //checks if the game is over

};

#endif