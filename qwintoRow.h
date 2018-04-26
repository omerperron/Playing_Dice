#ifndef QWINTOROW
#define QWINTOROW

#include <iostream>
using namespace std;
#include <stdlib.h>

#include "rollOfDice.h"; 

//template T is a non type template which takes a Colour
//QwintoRow has all information about a row in QwintoScoreSheet.
template<Colour T>
class QwintoRow{
private:
	//an array of size 10 to store all the values of the row
	int row[10] = {0}; 
public:
	//overriding the insertion operator lets us write to a stream.
	template<Colour U>
	friend ostream& operator<<(ostream &output, QwintoRow<U> &r);

	bool validate(RollOfDice dice, int index); //checks if a input is valid
	int& operator[](int index); //overrides the [] operator to retrive values in row
	int calcTotal(); //calculates the current score of the player in the current row


};

//prints the row of Colour T and its information to an output stream
template<Colour T>
ostream& operator<<(ostream &output, QwintoRow<T> &r){

	char *pointer; //pointer to the correct row we need to print
	string gap = "       ";
	int numIndents = 0;

	//if colour is red
	if(T == Colour::RED){
		numIndents = 2;
		char red[] = "  %  %  |XX|  %  %  |  |  |  |";
		pointer = red;
		//print line on top since it is the first row
		output << gap << "      -------------------------------" << endl;
		output << "RED    ";
	//if colour is yellow
	}else if(T == Colour::YELLOW){
		numIndents = 1;
		output << "YELLOW ";
		char yellow[] = "  |  |  |  |  |XX|  %  %  |  |";
		pointer = yellow;
	//if colour is blue
	}else if(T == Colour::BLUE){
		output << "BLUE   ";
		char blue[] = "  |  %  %  |XX|  |  |  |  %  %";
		pointer = blue;
	}
	//for each element in the row, check if it is not empty
	//and if it is not then set write it to the char array.
	for(int i = 0; i < 10; i++){
		if(r[i] == 0) continue;

		int strIndex = i*3;
		if(r[i] < 10){  //if the value is smaller then ten write the value
			*(pointer + strIndex + 1) = '0' + r[i];
	    }else { //if the value is bigger then ten write 1 and then the value - 10 
	    	*(pointer + strIndex) = '1';
	    	int c = r[i] - 10;
	    	*(pointer + strIndex + 1) = '0' + c;
	    }
	}
	//indent it correctly depending on the row
	string indent = "";
	for (int i = 0; i < numIndents ; i ++){
		indent = indent + "   ";
	}
	//insert row to output stream and return
	output << indent << "|" << pointer << endl;
	if(T == Colour::RED) cout << "   ";
	output << gap << "-------------------------------" << endl;
	return output;
}

//overloads the [] operator so we can access values of row easily
template<Colour T>
int& QwintoRow<T>::operator[](int index){
	return row[index];
}


//checks if a user input is valid. the input index must be bigger
//the the previous input index
template<Colour T>
bool QwintoRow<T>::validate(RollOfDice dice, int index){
	int lastIndex = -1;
	//loop through row and get the right most input
	for(int i = 0; i < 10; i++)
		if(row[i] != 0) lastIndex = i;

	if(index > lastIndex)
		if(lastIndex == -1 || row[lastIndex] < dice) return true;
	

	cout << "invalid position in row was given";
	return false;
}

//calculates the total of the current row.
template<Colour T>
int QwintoRow<T>::calcTotal(){
	if(row[9] != 0) return row[9]; //if the last element is not zero return it
	
	//otherwise get the sum of all values in the row and return the sum
	int total = 0;
	for(int i = 0; i < 10; i++) total += row[i];
	return total;

}

#endif






















