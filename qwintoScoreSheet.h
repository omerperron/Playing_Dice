#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET

#include <iostream>
#include "scoreSheet.h";
#include "qwintoRow.h";
#include "rollOfDice.h"; //again, including this to have access to colour, necessary?
using namespace std; 


class QwintoScoreSheet : public ScoreSheet{


public:
	QwintoRow<Colour::RED> redRow; //red row
	QwintoRow<Colour::YELLOW> yellowRow; //yellow row
	QwintoRow<Colour::BLUE> blueRow; //blue row

	QwintoScoreSheet(string _name = "unknown") : ScoreSheet(_name){} 
	bool validate(RollOfDice dice, Colour colour, int position); //checks if score is valid
	bool operator !(); //checks if game is over
	int calcTotal(); //calculate total
	friend ostream& operator<<(ostream &output, QwintoScoreSheet &scoreSheet);

};

#endif