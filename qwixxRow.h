#ifndef QWIXXROW
#define QWIXXROW

#include <iostream>
#include <list>
#include "rollOfDice.h";
#include <array>
using namespace std;

//template class takes a list or a vector as the first parameter,
//and a Colour as a second parameter
template<class container, Colour T>

class QwixxRow{
private:
	container row;
public:
	QwixxRow(); 
	void printRow(); 
	int& operator[](int index); //allows easy access to row
	bool validate(RollOfDice dice); //checks if input is valid
	int getTotal(); //get current score of player
	void operator+=(RollOfDice &rhs); //adds a score to row
	//prints row information to stream
	template<class C, Colour U>
	friend ostream& operator<<(ostream &output, QwixxRow<C,U> &r);
	//checks if the row is locked
	bool isLocked();

};

//set the size of the list or vector to be 11
template<class container, Colour T>
QwixxRow<container, T>::QwixxRow(){
	row.resize(11);
}

//check if the user input is valid.
//it must be the right most input in the row.
template<class container, Colour T>
bool QwixxRow<container, T>::validate(RollOfDice dice){
	int lastIndex = -1;
	//get right most index
	for(int i = 0; i < 11; i++)
		if((*this)[i] != 0) lastIndex = i;
	//if this value is larger or it is the first input, return truel
	if(lastIndex == -1 || dice - 2 > lastIndex)return true;
	
	//otherwise return false
	cout << "invalid position in row was given";
	return false;
}


//adds a integer dice value to the row at the correct position
template<class container, Colour T>
void QwixxRow<container, T>::operator+=(RollOfDice &rhs){
   	try {
   		//get the correct position and set it to one
		auto front = row.begin();
		advance(front, rhs-2);
		*front = 1;
    }catch (const exception& e) {
    	//throw error if this doesnt work
		cout << "error in += operator of QwixxRow" << endl;
		cout << e.what() << endl;
	}
	
}


//check if the row is locked.
//this is true if there are 5 inputs and the last element is one of them
template <class container, Colour T>
bool QwixxRow<container, T>::isLocked(){
	int numEntries = 0;

	for(int i = 0; i < 11; i++){
		if((*this)[i] != 0){
			numEntries++;
		}
	}
	if(numEntries > 4 && (*this)[10] == 1) return true;
	return false;
}

//write row to output stream.
template<class container, Colour T>
ostream& operator<<(ostream &output, QwixxRow<container, T> &r){
	int numEntries = 0;
	char RY[] = " 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|";
	char GB[] = "12|11|10| 9| 8| 7| 6| 5| 4| 3| 2|";

	//if the row is red or yellow
	if(T == Colour::RED || T == Colour::YELLOW){
		if(T == Colour::RED) output << "Red     |";
		if(T == Colour::YELLOW) output << "Yellow  |";
		for(int i = 0; i < 11; i++){
			int strIndex = i*3;
			if(r[i] != 0){
				numEntries++;
				RY[strIndex] = 'X';
				RY[strIndex+1] = 'X';
			}
		}
		output << RY;

	//if it green or blue
	}else if(T == Colour::GREEN || T == Colour::BLUE){
		if(T == Colour::GREEN) output << "Green   |";
		if(T == Colour::BLUE) output << "Blue    |";
		for(int i = 0; i < 11; i++){
			int strIndex = i*3;
			if(r[i] != 0){
				numEntries++;
				GB[strIndex] = 'X';
				GB[strIndex+1] = 'X';
			}
		}
		output << GB;

	}
	//display if it is locked or unlocked
	if(r[10] == 1 && numEntries >= 5) output << " L" << endl;
	output << " U" << endl;
	output << "        ------------------------------------" << endl;
	return output;
}

//allows easy access to row information. return the value 
//at position index.
template<class container, Colour T>
int& QwixxRow<container, T>::operator[](int index){
	auto front = row.begin();
	advance(front, index);	
	return *front;// (*front);
}

//calculates the total of this row.
//the total is the number of entries in the row
//plus an extra entry if it is locked
template <class container, Colour T>
int QwixxRow<container, T>::getTotal(){
	int numEntries = 0;
	for(int i = 0; i < 11; i++){
		bool entry = (*this)[i];
		if(entry) numEntries++;
	}
	//if locked counts as an extra entry
	if((*this).isLocked()) numEntries++;
	//formula for the score depending on the numEntries.
	return numEntries * (1 + numEntries*0.5 - 0.5);
}





#endif