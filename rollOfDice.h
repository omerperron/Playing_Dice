#ifndef ROLLOFDICE
#define ROLLOFDICE

#include <iostream>
#include "dice.h"
using namespace std;

class RollOfDice : public vector<Dice>{

public:
	
	operator int(); //allows the roll of dice to be compared with int

   	void addDice(Dice dice); //adds a given dice to the vector
	void roll(); //gets new random values for all dice in vector
	void clearDice(); //clears all dice from vector
	void removeColour(Colour colour); //removes specific dice from vector
	//prints all dice to output
	friend ostream& operator<<(ostream &output, RollOfDice &dice); 
	//given two dice as parameters, return a new RollOfDice with the 2 dice
	static RollOfDice pair(Dice a, Dice b); 


};

#endif