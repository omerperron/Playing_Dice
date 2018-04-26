#ifndef QWIXXSCORESHEET
#define QWIXXSCORESHEET

#include <iostream>
#include <list>

#include "scoreSheet.h";
#include "qwixxRow.h";
#include "rollOfDice.h";
using namespace std;


class QwixxScoreSheet : public ScoreSheet{
	
public:
	QwixxRow<list<int>, Colour::RED> redRow; //red row
	QwixxRow<list<int>, Colour::YELLOW> yellowRow; //yellow row
	QwixxRow<vector<int>, Colour::GREEN> greenRow; //green row
	QwixxRow<vector<int>, Colour::BLUE> blueRow; //blue row

	QwixxScoreSheet(string _name = "unknown") : ScoreSheet(_name){}
	bool validate(RollOfDice dice, Colour col, int position); //checks if score is valid
	bool operator !();//check if game is over
	int calcTotal(); //gets the current score of player
	//prints score sheet to output stream
	friend ostream& operator<<(ostream &output, QwixxScoreSheet &scoreSheet);

};

#endif