
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Help.h"
#include "Plane.h"
#include "Seat.h"
#include <stdexcept>
#include <cctype>
#include "Constant.h"
using namespace std;

void Plane::readSeatChart() {



	//Opens file 
	ifstream Seatfile;

	Seatfile.open("chartIn.txt");

	//Check if file is opened
	if (!Seatfile.is_open()) {
		cout << "Couldn't open file chartIn.txt." << endl;

	}


	int j = 0;

	while (!Seatfile.eof()) {

		//Creates temporary variables to be stored into the array
		string seatRow;

		string seatA;
		string seatB;
		string seatC;
		string seatD;
		string seatE;
		string seatF;
		string seatG;
		string seatH;
		string seatI;
		string seatJ;
		string seatK;
		string seatL;
		string seatM;
		string seatN;
		string seatO;
		string seatP;
		string seatQ;
		string seatR;
		string seatS;
		string seatT;
		string seatU;
		string seatV;
		string seatW;
		string seatX;
		string seatY;
		string seatZ;


		string temporaryColumn[26] = { seatA, seatB,seatC,seatD,seatE,seatF,seatG,seatH,seatI,seatJ,
		seatK, seatL, seatM,seatN,seatO,seatP,seatQ,seatR,seatS,seatT, seatU, seatV, seatW,
			seatX,seatY,seatZ };


		Seatfile >> seatRow;


		
		for (int i = 0; i < COLUMNTOTAL; ++i) {
			Seatfile >> temporaryColumn[i];
		}


		//Reads file into array and sets if seat is reserved or not

		for (int i = 0; i < COLUMNTOTAL; ++i) {

			seatChart[j][i].setInput (temporaryColumn[i]);
			if (seatChart[j][i].getInput() == "X")
				seatChart[j][i].setReserved(true);

		}


		++j;
	}


	Seatfile.close();

}

void Plane::displaySeatChart() {


	for (int i = 0; i < ROWTOTAL; ++i) {

		if (i < 9)
			cout << i + 1 << "  ";

		else
			cout << i + 1 << " ";

		for (int j = 0; j < COLUMNTOTAL; ++j) {

			cout << seatChart[i][j].getInput() << " ";
		}
		cout << endl;
	}

}

void Plane::reserveSeat() {


	string rowString = "0";
	string columnString = "A";
	bool error = false;

	string userSeat;
	cout << "Enter desired seat" << endl;
	try {
		cin >> userSeat;

		//Error checking: checks if size if greater than what can be entered
		if (userSeat.size() >= 6 || userSeat.size() < 2) {
			throw runtime_error("Invalid Seat");
		}


		//Checks size of string entered to determine row and column
		if (userSeat.size() == 5) {

			rowString = userSeat.substr(0, 4);
			columnString = userSeat.at(4);
		}
		else if (userSeat.size() == 4) {

			rowString = userSeat.substr(0, 3);
			columnString = userSeat.at(3);
		}

		else if (userSeat.size() == 3) {

			rowString = userSeat.substr(0, 2);
			columnString = userSeat.at(2);
		}
		else {
			rowString = userSeat.at(0);
			columnString = userSeat.at(1);
		}

		//Error Checking: Checks if a valid Row number is put in
		if (stoi(rowString) <= 0 || stoi(rowString) > ROWTOTAL)
			throw runtime_error("Invalid Row ");

		//Error Checking: Checsk if a valid Column letter in put in
		char tempChar = columnString.at(0);
		if (!isalpha(tempChar)) {
			throw runtime_error("Invalid Column");
		}
		else {

			bool inRange = false;

			for (int i = 0; i < COLUMNTOTAL; ++i) {

				if (columnString == Letters[i])

					inRange = true;
			}
			//Error Checking: Checks if Column Letter is in the range
			if (inRange == false)
				throw runtime_error("Invalid ColumnLetter");


		}


	}

	//Outputs Error statements
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Cannot complete cancellation" << endl;
		error = true;
	}
	
	



	if (error == false) {
		//Sets letters to the columns

		for (int i = 0; i < COLUMNTOTAL; ++i) {

			if (columnString == Letters[i])
				column = i;

		}


		//Sets rows to proper number
		row = stoi(rowString) - 1;



		//Reserves the seats if availbe
		if (seatChart[row][column].getReserved() == true)
			cout << "This seat is not available";
		else
		{
			seatChart[row][column].setInput("X");
			cout << "This seat is now reserved";
			seatChart[row][column].setReserved (true);

		}
	}
}

void Plane::cancelReservation() {

	string rowString = "0";
	string columnString = "A";
	bool error = false;

	string userSeat;
	cout << "Enter desired seat" << endl;
	try {
		cin >> userSeat;

		//Error checking: checks if size if greater than what can be entered
		if (userSeat.size() >= 6 || userSeat.size() < 2) {
			throw runtime_error("Invalid Seat");
		}


		//Checks size of string entered to determine row and column
		if (userSeat.size() == 5) {

			rowString = userSeat.substr(0, 4);
			columnString = userSeat.at(4);
		}
		else if (userSeat.size() == 4) {

			rowString = userSeat.substr(0, 3);
			columnString = userSeat.at(3);
		}

		else if (userSeat.size() == 3) {

			rowString = userSeat.substr(0, 2);
			columnString = userSeat.at(2);
		}
		else {
			rowString = userSeat.at(0);
			columnString = userSeat.at(1);
		}

		//Error Checking: Checks if a valid Row number is put in
		if (stoi(rowString) <= 0 || stoi(rowString) > ROWTOTAL)
			throw runtime_error("Invalid Row ");

		//Error Checking: Checsk if a valid Column letter in put in
		char tempChar = columnString.at(0);
		if (!isalpha(tempChar)) {
			throw runtime_error("Invalid Column");
		}
		else {

			bool inRange = false;

			for (int i = 0; i < COLUMNTOTAL; ++i) {

				if (columnString == Letters[i])

					inRange = true;
			}
		//Error Checking: Checks if Column Letter is in the range
			if (inRange == false)
				throw runtime_error("Invalid ColumnLetter");


		}
		

	}

	//Outputs Error statements
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Cannot complete cancellation" << endl;
		error = true;
	}


	if (error == false) {

		//Sets letters to columns

		for (int i = 0; i < COLUMNTOTAL; ++i) {

			if (columnString == Letters[i])
				column = i;

		}



		//Sets rows to proper number

		row = stoi(rowString) - 1;




		// Cancels reservations 
		if (seatChart[row][column].getReserved() == true) {
			for (int i = 0; i < COLUMNTOTAL; ++i) {

				if (column == i)
					seatChart[row][column].setInput( Letters[i]);

			}

			seatChart[row][column].setReserved (false);

			cout << "This seat reservation has been cancelled";

		}
		else

		{
			cout << "Error: This seat has not been reserved";
		}
	}
}

void Plane::statistics() {


	//Counts how many seats are reserved
	double reservedCount = 0;

	for (int i = 0; i < ROWTOTAL; ++i) {
		for (int j = 0; j < COLUMNTOTAL; ++j) {

			if (seatChart[i][j].getReserved() == true)

				++reservedCount;
		}

	}
	//Displays seats available
	cout << "Seats avaialbe: " << (ROWTOTAL * COLUMNTOTAL) - reservedCount << endl;

	//Disaplys percentage of seats reserved
	cout << fixed << setprecision(2) << "Percentage of seats reserved: " << (reservedCount / (ROWTOTAL * COLUMNTOTAL)) * 100 << "%" << endl;


	//Displasy window seats available
	cout << "Window seats available: " << endl;


	for (int i = 0; i < ROWTOTAL; ++i) {

		if (seatChart[i][0].getReserved() == false) {

			cout << i + 1 << "A" << endl;

		}
	}

	for (int i = 0; i < ROWTOTAL; ++i) {

		if (seatChart[i][COLUMNTOTAL].getReserved() == false) {

			cout << i + 1 << Letters[COLUMNTOTAL - 1] << endl;

		}
	}

	//Displays aisle seats available
	cout << "Aisle seats available: " << endl;


	for (int i = 1; i < COLUMNTOTAL - 1; ++i) {


		for (int j = 0; j < ROWTOTAL; ++j) {

			if (seatChart[j][i].getReserved() == false) {

				cout << j + 1 << Letters[i] << endl;

			}
		}

	}


}

void Plane::saveChart() {

	//Get a user to enter a file name
	cout << "Enter file name: ";
	string fileName;
	cin >> fileName;

	//Creates file
	std::ofstream{ fileName };

	ofstream outFile;
	outFile.open(fileName);

	//Makes sure file can be opened
	if (!outFile.is_open()) {
		cout << "File not opened";
	}

	//Saves seat chart to file
	for (int i = 0; i < ROWTOTAL; ++i) {

		if (i < 9)
			outFile << i + 1 << " ";

		else
			outFile << i + 1;

		for (int j = 0; j < COLUMNTOTAL; ++j) {

			outFile << seatChart[i][j].getInput() << " ";
		}
		outFile << endl;
	}

}