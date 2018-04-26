#include "randomDice.h"


//gets a random number between 1 and 6
int RandomDice::getRandomNumber(){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
 
    //Use dis to transform the random unsigned int 
    //generated by gen into an int in [1, 6]
    return dis(gen) << ' ';
}