#include "qwixxPlayer.h"


//get input before roll
void QwixxPlayer::inputBeforeRoll(RollOfDice &dice){
	if(!getIsActive()) cout << "player " << getName();
	else cout << "active player " << getName();
	cout << "is rolling the dice!" << endl;

}


//get input after roll
void QwixxPlayer::inputAfterRoll(RollOfDice &dice){

	RollOfDice toScore; //the chosen dice to score

	if(getIsActive()){ //if the player is active

		//get player input
		cout << "which dice do you wanna score? red(0), yellow(1), green(2), blue(3), white1(4), white2(5), fail throw(6)" << endl;
		int diceChoiceA, diceChoiceB;
		cin >> diceChoiceA;
		//if not the correct input fail attempt and return
		if(diceChoiceA == 6) {
			scoreSheet.incrementFailedAttempts();
			return;
		}
		cin >> diceChoiceB;
		if(diceChoiceA != 4 && diceChoiceA != 5){
			if(diceChoiceB != 4 && diceChoiceB != 5) {
				scoreSheet.incrementFailedAttempts();
				return;
			}
		}
		toScore = RollOfDice::pair(dice[diceChoiceA], dice[diceChoiceB]);
	}else{
		//if not active player give option to roll white dice, else faile
		cout << "would you like to score the white dice? yes(1) no(0)" << endl;
		int scoreWhiteDice;
		cin >> scoreWhiteDice;
		if(scoreWhiteDice == 1) toScore = RollOfDice::pair(dice[4], dice[5]);
		else {
			scoreSheet.incrementFailedAttempts();
			return;
		}

	}

	
	//give option of which row to score
	cout << "which row would you like to score?" << endl;
	cout << "red (0), yellow (1), green (2), blue (3)";
	int row;
	cin >> row;
	Colour col;
	//get colour of chosen row
	if(row == 0) col = Colour::RED;
	else if(row == 1) col = Colour::YELLOW;
	else if(row == 2) col = Colour::GREEN;
	else if(row == 3) col = Colour::BLUE;

	//check if score is valid
	bool scored = scoreSheet.score(toScore, col);
	//if it is, get the row and apply the score.
	//then check if the row is locked and if it is, remove that dice.
	if(scored){
		if(row == 0){
			scoreSheet.redRow += toScore;
			if(scoreSheet.redRow.isLocked()) dice.removeColour(Colour::RED);
		}else if (row == 1){
			scoreSheet.yellowRow += toScore;
			if(scoreSheet.yellowRow.isLocked()) dice.removeColour(Colour::YELLOW);
		}else if (row == 2) {
			scoreSheet.greenRow += toScore;
			if(scoreSheet.greenRow.isLocked()) dice.removeColour(Colour::GREEN);
		}else if (row == 3) {
			scoreSheet.blueRow += toScore;
			if(scoreSheet.blueRow.isLocked()) dice.removeColour(Colour::BLUE);
		}
	}else{
	//if the score is not valid, increment failed attempts
		scoreSheet.incrementFailedAttempts();
	}
	
}


//prints the information of the player and score sheet.
//if the game is over, also print the score
void QwixxPlayer::printScoreSheet(bool gameOver){
	cout << endl;
	cout << "Player name: " << scoreSheet.getName();
	if(gameOver) cout << "            Points: " << scoreSheet.setTotal() << endl;
	else cout <<endl;
	cout << scoreSheet;}

bool QwixxPlayer::checkGameOver(){
	return !scoreSheet;
}




















