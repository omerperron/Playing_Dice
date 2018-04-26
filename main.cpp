//Pierre Guilman and Omer Perron

#include <iostream>
#include <array>

#include "player.h"
#include "rollOfDice.h"
#include "qwintoPlayer.h"
#include "qwixxPlayer.h"

using namespace std;




//takes a vector of players of the type corresponding the game type
//(QwintoPlayer or QwixxPlayer) and a RollOfDice. The main game loop
//then begins and is only exited when the game is over. showResults()
//is called and the function is returned.

template <class type>
bool playersTurn(type player, RollOfDice &dice){
	if(player.getIsActive()){
		//get input of player and then roll the dice.
		player.inputBeforeRoll(dice);
		dice.roll();
		cout << dice; //print dice to user
	}

	//print score sheet of current player and then get input
	//after roll
	player.printScoreSheet();
	player.inputAfterRoll(dice);

	//check if game is over and if true, show results and return.
	if(player.checkGameOver()) return true;
	return false;
}



int setGameType(){
	string gameType;
	cout << "what game version would you like to play? (A or B)" << endl;
	cin >> gameType;
	if(gameType == "A" || gameType == "a"){
		cout << "You want to play Version A!" << endl;
		return 0;
	}else if(gameType == "B" || gameType == "b"){
		cout << "You want to play Version B!" << endl;
		return 1;
	}

}

template <class type>
vector<type> setPlayers(int &numPlayers){
	cout << "how many people are playing?" << endl;
	cin >> numPlayers;

	vector<type> players;
	for(int i = 0; i < numPlayers; ++i){
		string name;
		cout << "what is the name of player " << i + 1 << "?	";
		cin >> name;
		type player(name);
		players.push_back(player);

	}
	return players;
}


//prints the score sheet of every player to the screen.
template<class type>
void showResults(vector<type> players){
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "---------GAME OVER---------" << endl;
	cout << "---------------------------" << endl;
	//loop through each player
	for(type player: players){
		cout << endl;
		player.printScoreSheet(1); //print score sheet.
		cout <<  endl;
	}
	cout << "---------------------------" << endl;
	cout << "---------------------------" << endl;
}



//main game loop. loops through all players and gets their input
//until a players turn results in the game finishing.
template <class type>
void game(vector<type> players, RollOfDice dice){
	cout<< "the colours correspond to their respective numbers:" << endl;
	cout << "red (0), yellow(1), green(2), blue(3), white(4)" << endl;
	bool gameOver = false;
	int curPlayer = 0;

	while(true){
		//get current player and set to active
		type &activePlayer = players[curPlayer];
		activePlayer.setIsActive(true);

		//gets players turn and if they win, show results.
		if(playersTurn(activePlayer, dice)){
			showResults(players);
			return;
		}

		
		
		//loop through all other players.
		for(type &othPlayer: players){ 
			//skip player if it is the active player as they have 
			//already played their turn.
			if(!othPlayer.getIsActive()){
				//gets players turn and if they win, show results.
				if(playersTurn(othPlayer, dice)){
					showResults(players);
					return;
				}
			} 
			
		}

		//sets the last curent player to false and 
		//updates the index to the new current player
		curPlayer++;
		if(curPlayer == players.size()) curPlayer = 0;
		activePlayer.setIsActive(false);

		
	}

}



int main() {

	//set up game type
	int gameType = setGameType();
	RollOfDice dice;

	//set up players
	int numPlayers;

	//if gameType is Qwinto set up QwintoPlayers and begin game loop
	if(gameType == 0){
		vector<QwintoPlayer> players;
		players = setPlayers<QwintoPlayer>( numPlayers);
		game(players, dice);

	//if gameType is Qwixx set up QwintoPlayers and dice and begin game loop
	}else if(gameType == 1){

		//set up dice
		dice.addDice(Dice(Colour::RED));
		dice.addDice(Dice(Colour::YELLOW));
		dice.addDice(Dice(Colour::GREEN));
		dice.addDice(Dice(Colour::BLUE));
		dice.addDice(Dice(Colour::WHITE));
		dice.addDice(Dice(Colour::WHITE));
		
		vector<QwixxPlayer> players;
		players = setPlayers<QwixxPlayer>( numPlayers);
		
		game(players, dice);

	}

}












































