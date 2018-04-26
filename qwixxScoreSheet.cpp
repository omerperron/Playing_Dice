#include "qwixxScoreSheet.h";


//checks if a score is valid.

bool QwixxScoreSheet::validate(RollOfDice dice, Colour col, int position){
	bool colourInDice = false;
	bool nonWhite = false;
	//loop through each dice and check if a coloured dice was rolled.
	//if it has, we can only score in the row colour, otherwise we 
	//can score in any row.
	for(Dice d: dice){
		if(d.col != Colour::WHITE) nonWhite = true;
		if(d.col == col) colourInDice = true;
	}
	//if the chosen colour was not in the dice, return false
	if(!colourInDice && nonWhite) {
		cout << "chosen colour was not rolled!" << endl;
		return false;
	}
	

	if(col == Colour::RED){
		return redRow.validate(dice); //check if red row is valid
	}else if (col == Colour::YELLOW){
		return yellowRow.validate(dice); //check if yellow row is valid
	}else if (col == Colour::GREEN){
		return greenRow.validate(dice); //check if green row is valid
	}else if (col == Colour::BLUE){
		return blueRow.validate(dice); //check if blue row is valid
	}
	//otherwise invalid colour was given
	cout << "invalid colour was given " << endl;
	return false;

}

//calculates the total which is the total from each row - the failed attemps
int QwixxScoreSheet::calcTotal(){
	int redScore = redRow.getTotal();
	int yellowScore = yellowRow.getTotal();
	int greenScore = greenRow.getTotal();
	int blueScore = blueRow.getTotal();
	int failed = 5 * failedAttempts;
	return redScore + yellowScore + greenScore + blueScore - failed;
}

//prints the information of the score sheet to an output stream
ostream& operator<<(ostream &output, QwixxScoreSheet &scoreSheet) { 
	
	output << "        ------------------------------------" << endl;
	output << scoreSheet.redRow;
	output << scoreSheet.yellowRow;
	output << scoreSheet.greenRow;
	output << scoreSheet.blueRow;

	output << "Failed throws: " << scoreSheet.failedAttempts << endl; //is this what we are supposed to do?
	output << endl;
	return output;            
}


//checks if the game is over which is true if number of failed attempts
//is 4 or the number of locked rows is 2
bool QwixxScoreSheet::operator !(){
	int numLockedRows = 0;
	if(redRow[10] == 1) numLockedRows++;
	if(yellowRow[10] == 1) numLockedRows++;
	if(greenRow[10] == 1) numLockedRows++;
	if(blueRow[10] == 1) numLockedRows++;

	if(failedAttempts > 3 || numLockedRows > 1) return true;
	return false;	
}









