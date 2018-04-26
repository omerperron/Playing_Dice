#ifndef SCORESHEET
#define SCORESHEET

#include <iostream>
using namespace std;
#include "rollOfDice.h";

class ScoreSheet{
	string name;


public:
	int failedAttempts = 0;
	int totalScore;

	ScoreSheet(string _name = "unknown"):
		name(_name)
		{}
	string getName();
	virtual bool score(RollOfDice dice, Colour colour, int position = -1);
	int setTotal(); //calls calcTotal(), sets and returns totalScore
	virtual bool validate(RollOfDice dice, Colour colour, int position = -1) = 0;
	virtual int calcTotal() = 0;
	virtual bool operator !() = 0;
	void incrementFailedAttempts(){failedAttempts++;};
};

#endif