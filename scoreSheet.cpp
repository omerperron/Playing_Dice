#include "scoreSheet.h" 


//gets name of player this scorsheet belongs to.
string ScoreSheet::getName(){
	return name;
}

//checks if a score is valid
bool ScoreSheet::score(RollOfDice dice, Colour colour, int position){
	return validate(dice, colour, position);
}

//calculates and sets the totalScore and then returns it
int ScoreSheet::setTotal(){
	totalScore = calcTotal();
	return totalScore;
}



