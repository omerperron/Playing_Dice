#include "dice.h"

//sets face to be random number between 1 and 6
// and returns it
int Dice::roll(){
	face = RandomDice::getRandomNumber();
	return face;
}

//given an integer value, returns the
//corresponding Colour.
Colour Dice::getColour(int i){
	switch(i){
		case 0: return RED;
		case 1: return YELLOW;
		case 2: return GREEN;
		case 3: return BLUE;
		case 4: return WHITE;
	}
}

//get colour given a string
Colour Dice::getColour(string i){
	if(i == "red") return RED;
	if(i == "yellow") return YELLOW;
	if(i == "green") return GREEN;
	if(i == "blue") return BLUE;
	if(i == "white") return WHITE;

}

//get string given an integer colour
string Dice::getColourName(int i){
	switch(i){
		case 0: return "RED";
		case 1: return "YELLOW";
		case 2: return "GREEN";
		case 3: return "BLUE";
		case 4: return "WHITE";
	}
}

//overloads the insertion operator and inserts
//the dice colour and face to given ostream.
ostream& operator<<(ostream &output, Dice &dice) { 
     output << "dice colour: " << dice.col << ", face: " << dice.face << endl;
     return output;            
}