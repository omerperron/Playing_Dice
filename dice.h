#ifndef DICE
#define DICE

#include <iostream>
#include "randomDice.h"
using namespace std;

enum Colour {RED, YELLOW, GREEN, BLUE, WHITE};

class Dice {

public:
	Colour col; //should this be private?
	int face = -1; //should this be private?

	friend ostream &operator<<(ostream &output, Dice &dice);
	Dice(Colour _colour) : col(_colour) {}
	int roll();
	static Colour getColour(int i);
	static Colour getColour(string i);
	static string getColourName(int i);

};


#endif