#include "qwintoPlayer.h"


//gets the input of the player before the dice is rolled.
//reference to dice is given as a parameter
void QwintoPlayer::inputBeforeRoll(RollOfDice &dice){
	//clear dice so player can choose which dice to roll.
	dice.clearDice();

	//get input before roll. player can choose to roll
	//red, yellow or blue dice.
	cout << "input before roll for: ";
	if(!getIsActive()) cout << "player " << getName() << endl;
	else cout << "active player " << getName() <<  endl;
	
	bool redDice;
	bool yellowDice;
	bool blueDice;
	cout << "would you like to throw the red dice? yes(1) no(0)	";
	cin >> redDice;
	cout << "would you like to throw the yellow dice? yes(1) no(0)	";
	cin >> yellowDice;
	cout << "would you like to throw the blue dice?	yes(1) no(0)";
	cin >> blueDice;

	//add dice to roll of dice if the player chose to roll the,
	if(redDice) dice.addDice(Dice(Colour::RED));
	if(yellowDice)dice.addDice(Dice(Colour::YELLOW));
	if(blueDice) dice.addDice(Dice(Colour::BLUE));

}


void QwintoPlayer::inputAfterRoll(RollOfDice &dice){

	//player chooses a row to score dice
	cout << "choose a row - red(0), yellow(1), blue(2):" <<endl;
	int input;
	cin >> input;
	Colour col;
	//get Colour of row
	if(input == 0) col = Colour::RED;
	else if(input == 1) col = Colour::YELLOW;
	else if(input == 2) col = Colour::BLUE;
	
	//choose an index in the row to score
	int index;
	cout << "choose an index:    ";
	cin >> index; 
	
	//check if it is valid to score this roll of dice
	bool scored = scoreSheet.score(dice, col , index);
	//if it is not valid, give option to roll again or fail throw.
	if(!scored){
		cout << "\nAn invalid input was given. " << endl;
		cout << "Would you like to try again(0) or fail throw(1):" << endl;
		bool failThrow; cin >> failThrow;
		//if failing throw, increment failed throws and return so next
		//player can have a turn
		if(failThrow){
			scoreSheet.incrementFailedAttempts();
			cout << "throw failed, num failed throws: " << scoreSheet.failedAttempts << endl;

			return;
		}
		//otherwise recursively call this function until the player 
		//decides to fail the throw or successfully scores a throw.
		inputAfterRoll(dice);
		
	}

	//score the dice into the corect row.
	if(col == Colour::RED) scoreSheet.redRow[index] = dice;
	else if(col == Colour::YELLOW) scoreSheet.yellowRow[index] = dice;
	else if(col == Colour::BLUE) scoreSheet.blueRow[index] = dice;
	

}

//prints the score sheet of the player. takes game over
//as an argument so it knows if we need to display the final score
void QwintoPlayer::printScoreSheet(bool gameOver){
	cout << endl;
	cout << "Player name: " << scoreSheet.getName();
	if(gameOver) cout << "            Points: " << scoreSheet.setTotal() << endl;
	else cout <<endl;
	cout << scoreSheet;
}


bool QwintoPlayer::checkGameOver(){
	return !scoreSheet;
}










