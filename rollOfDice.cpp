#include "rollOfDice.h"

//rolls all dice in the container
void RollOfDice::roll(){
	for(Dice &d : (*this)){
		int num = d.roll();
	}
}

//prints the face and colour of every dice in the rollOfDice
//to an ostream.
ostream& operator<<(ostream &output, RollOfDice &dice) { 
	output << "dice in roll of dice:" << endl;
    for(Dice &d : dice){
		output << d; //print value of dice
	}           
	return output;
}

//adds a given Dice to the RollOfDice.
void RollOfDice::addDice(Dice dice){
	(*this).push_back(dice);
}

//removes all dice in this instance of RollOFDice
void RollOfDice::clearDice(){
	(*this).clear();
}

//given two Dice a and b, create a new RollOfDice
//with the two dice and return it.
RollOfDice RollOfDice::pair(Dice a, Dice b){
	RollOfDice newROD;
	newROD.addDice(a); //add dice a
	newROD.addDice(b); //add dice b
	return newROD;
}

//given the colour of a dice, remove that dice.
void RollOfDice::removeColour(Colour colour){
	int i = 0;
	while(i < size()){
		if((*this)[i].col == colour) break; //find the index of the colour
		i++;
	}
	//if the colour exists remove it.
	if(i != size()) erase (begin()+i);
}

//allows the ROD to perform operations with integer.
//the integer value of an instance of RollOfDice is 
//the sum of all of its faces.
RollOfDice::operator int(){
	int sum = 0;
	for(Dice d: (*this)) sum = sum + d.face;

	return sum;
}
