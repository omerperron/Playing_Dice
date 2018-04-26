#include "player.h"

//get name of player
string Player::getName(){
	return name;
}

//get if player is active
bool Player::getIsActive(){
	return isActive;
}

//set player active or not active
void Player::setIsActive(bool a){
	isActive = a;
}

