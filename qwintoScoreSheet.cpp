#include "qwintoScoreSheet.h";

	//check if a score is valid
	bool QwintoScoreSheet::validate(RollOfDice dice, Colour col, int position){
		//check if the row colour the user wants to score corresponds
		//to the colour the user rolled
		bool correctColour = false;
		for(Dice d: dice){
			if(d.col == col) correctColour = true;
		}
		//if they did not roll the correct dice return false
		if(!correctColour){
			cout << "Invalid dice colour was given!" << endl;
			return false;
		}

		if(col == Colour::RED){
			if(position == 3) return false; //invalid index (XX)
			//cannot score the same value in the same col
			if(yellowRow[position] == dice || blueRow[position] == dice) return false;
			//check if the row constraints are valid
			return redRow.validate(dice, position);
		}else if(col == Colour::YELLOW){

			if(position == 5) return false; //invalid index (XX)
			//cannot score the same value in the same col
			if(redRow[position] == dice || blueRow[position] == dice) return false;
			//check if the row constraints are valid
			return yellowRow.validate(dice, position);
		}else if(col == Colour::BLUE){

			if(position == 4) return false; //invalid index (XX)
			//cannot score the same value in the same col
			if(yellowRow[position] == dice || redRow[position] == dice) return false;
			//check if the row constraints are valid
			return blueRow.validate(dice, position);
			
		}
		cout << "invalid Colour was given";
		return false;
	}



	//calculates the total score. this includes:
	//the score from the row its self calculated in QwintoRow::calcTotal();
	//the bonus from a whole column being complete where one row has a bonus
	//negative points from failed throws
	int QwintoScoreSheet::calcTotal(){

		//total from rows
		int redTotal = redRow.calcTotal(); 
		int yellowTotal = yellowRow.calcTotal(); 
		int blueTotal = blueRow.calcTotal(); 
		int total = redTotal + yellowTotal + blueTotal;

		//bonus points from red row
		if(redRow[1] != 0 && yellowRow[2] != 0 && blueRow[3] != 0) total += redRow[1];
		if(redRow[5] != 0 && yellowRow[6] != 0 && blueRow[7] != 0) total += redRow[5];

		//bonus points from yellow row
		if(redRow[6] != 0 && yellowRow[7] != 0 && blueRow[8] != 0) total += yellowRow[7];

		//bonus points from blue row
		if(redRow[0] != 0 && yellowRow[1] != 0 && blueRow[2] != 0) total += blueRow[2];
		if(redRow[7] != 0 && yellowRow[8] != 0 && blueRow[8] != 0) total += blueRow[9];

		//negative points for failed throws
		total -= (5*failedAttempts);

		return total;
	}


	//prints information of scoresheet to output stream.
	ostream& operator<<(ostream &output, QwintoScoreSheet &scoreSheet) { 

		output << scoreSheet.redRow;
		output << scoreSheet.yellowRow;
		output << scoreSheet.blueRow;
		output << "Failed throws: " << scoreSheet.failedAttempts << endl; //is this what we are supposed to do?
		output << endl;
		return output;
	}

	//checks if game over which is true if:
	//more then one row is complete or there has been 4 failed attempts
	bool QwintoScoreSheet::operator !(){
		int completedRows = 0;
		if(redRow[9] != 0) completedRows++;
		if(yellowRow[9] != 0) completedRows++;
		if(blueRow[9] != 0) completedRows++;
		
		if(completedRows > 1 || failedAttempts > 3) return true;
		return false;
	}


