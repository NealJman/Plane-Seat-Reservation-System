/***************
 *Author:Neal Jayaraman
 *Creation Date:11/8/22
 *Modification Date:11/8/22
 *Purpose:
****************/
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int const ROW =3;
int const COLUMN = 8;







string Letters[26] = {"A","B","C","D","E","F","G","H","I","J","K",
	"L","M","N","O","P","Q","R","S","T","U","V","W","X", "Y","Z" };

/***************
 *Author:Neal Jayaraman
 *Creation Date:11/06/22
 *Modification Date:11/06/22
 *Purpose: Displays Menu & Returns selection
****************/
int Menu() {

	// Menu Display 
	cout << endl;

	cout << setfill('-') << setw(33);
	cout << "Menu";
	cout << "--------------------------------";
	cout << endl;



	cout << "1.  Display Seat Chart" << endl;
	cout << "2.  Reserve Seat" << endl;
	cout << "3.  Cancel Reservation" << endl;
	cout << "4.  Save Seat Chart to File" << endl;
	cout << "5.  Statistics" << endl;
	cout << "6.  Help" << endl;
	cout << "7.  Quit" << endl;


	cout << setfill('-') << setw(65) << "" << endl;



	//Number Selection
	cout << "Please Enter Your Choice (1-7) : ";
	int menuSelection;


	//Checks if input is valid

	while (!(cin >> menuSelection) || menuSelection > 7 || menuSelection <= 0) {
		cin.clear(); //must be before ignore
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer
		cout << "Invalid Selection, please select again :";
	}

	return menuSelection;
}


class Seat {

public:
	string input;
	bool reserved = false;
private:

};

class Plane {

public:

	void readSeatChart();
	Seat seatChart[3][9];
	void displaySeatChart();
	void reserveSeat();
	void cancelReservation();
	void statistics();
	void saveChart();

private:
	int row = 0;
	int column = 0;
};


void Plane::readSeatChart() {

	ifstream Seatfile;

	Seatfile.open("cric.txt");

	//Check if file is opened
	if (!Seatfile.is_open()) {
		cout << "Couldn't open file chartIn.txt." << endl;

	}

	int j = 0;

	while (!Seatfile.eof()) {

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

		string Array[26] = { seatA, seatB,seatC,seatD,seatE,seatF,seatG,seatH,seatI,seatJ,
		seatK, seatL, seatM,seatN,seatO,seatP,seatQ,seatR,seatS,seatT, seatU, seatV, seatW,
			seatX,seatY,seatZ };


		Seatfile >> seatRow;

		

		for (int i = 0; i < COLUMN; ++i) {
			Seatfile >> Array[i];
		}


		//Reads file into array and sets if seat is reserved or not
		//rowNumber[j] = seatRow;

		for (int i = 0; i < COLUMN; ++i) {
			
			seatChart[j][i + 1].input = Array[i];
			if (seatChart[j][i + 1].input == "X")
				seatChart[j][i + 1].reserved = true;

		}


		++j;
	}


	Seatfile.close();

}

void Plane::displaySeatChart() {


	for (int i = 0; i < ROW; ++i) {

		if (i < 9)
			cout << i + 1 << " ";

		else
			cout << i + 1;

		for (int j = 0; j < COLUMN +1; ++j) {

			cout << seatChart[i][j].input << " ";
		}
		cout << endl;
	}

}

void Plane::reserveSeat() {

	string userSeat;
	cout << "Enter desired seat" << endl;

	cin >> userSeat;


	string rowString;
	string columnString;

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

	//Sets letters to column numbers
	

	for (int i = 0; i < COLUMN; ++i) {

		if (columnString == Letters[i])
			column = i + 1;

	}


	//Sets rows to proper index

	row = stoi(rowString) - 1;




	if (seatChart[row][column].reserved == true)
		cout << "This seat is not available";
	else
	{
		seatChart[row][column].input = "X";
		cout << "This seat is now reserved";
		seatChart[row][column].reserved = true;

	}

}

void Plane::cancelReservation() {

	string userSeat;
	cout << "Enter seat to be cancelled" << endl;

	cin >> userSeat;


	string rowString;
	string columnString;
	
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




	//Sets letters to column numbers

	for (int i = 0; i < COLUMN; ++i) {

		if (columnString == Letters[i])
			column = i + 1;

	}

	//Sets rows to proper index

	row = stoi(rowString) - 1;





	if (seatChart[row][column].reserved == true) {
		for (int i = 0; i < COLUMN; ++i) {

			if (column == i + 1)
				seatChart[row][column].input = Letters[i];


		}

	


	/*if (seatChart[row][column].reserved == true) {
		if (column == 1)
			seatChart[row][column].input = "A";
		if (column == 2)
			seatChart[row][column].input = "B";
		if (column == 3)
			seatChart[row][column].input = "C";
		if (column == 4)
			seatChart[row][column].input = "D";*/

		seatChart[row][column].reserved = false;

		cout << "This seat reservation has been cancelled";

	}
	else

	{

		cout << "Error: This seat has not been reserved";
	}

}

void Plane::statistics() {

	double reservedCount = 0;

	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COLUMN; ++j) {

			if (seatChart[i][j].reserved == true)

				++reservedCount;
		}

	}
	cout << "Seats avaialbe: " << (ROW * COLUMN) - reservedCount << endl;

	cout << fixed << setprecision(2) << "Percentage of seats reserved: " << (reservedCount / (ROW * COLUMN)) * 100 << "%" << endl;


	cout << "Window seats available: " << endl;



	for (int i = 0; i < ROW; ++i) {

		if (seatChart[i][1].reserved == false) {

			cout << i + 1 << "A" << endl;

		}
	}

	for (int i = 0; i < ROW; ++i) {

		if (seatChart[i][COLUMN].reserved == false) {

			cout << i + 1 << Letters[COLUMN -1] << endl;

		}
	}

	cout << "Aisle seats available: " << endl;


	for (int i = 2; i < COLUMN ; ++i) {


		for (int j = 0; j < ROW; ++j) {

			if (seatChart[j][i].reserved == false) {

				cout << j + 1 << Letters[i-1] << endl;

			}
		}

	}


}

void Plane::saveChart() {

	cout << "Enter file name: ";
	string fileName;
	cin >> fileName;

	std::ofstream{ fileName };

	ofstream outFile;
	outFile.open(fileName);

	if (!outFile.is_open()) {
		cout << "FilenotCreated";
	}

	for (int i = 0; i < ROW; ++i) {

		if (i < 9)
			outFile << i + 1 << " ";

		else
			outFile << i + 1;

		for (int j = 0; j < COLUMN + 1; ++j) {

			outFile << seatChart[i][j].input << " ";
		}
		outFile << endl;
	}

}

void help();

void help() {
	cout << endl;

	cout << "Option 1 displays the rows and columns of seats on the plane." << endl;
	cout << "If the seat is not available, an X will be shown." << endl << endl;

	cout << "Option 2 will ask you to enter the row of your desired seat number followed immediatley by" << endl;
	cout << "the desired column letter. If its avalible it will reserve it for you otherwise it will let you know that it's not available" << endl << endl;

	cout << "Option 3 will ask you to enter the row followed by the column letter of the seat you would like to cancel." << endl;
	cout << "It will then cancel the seat, but if the seat was never reserved it will display an error." << endl << endl;

	cout << "Option 4 will ask you to enter a file name. The file will be created and the seat chart will be saved to that file" << endl << endl;

	cout << "Option 5 will display the number of seats available, percentage of seats reserved, will list the window seats available" << endl;
	cout << "and will also list the aisle seats available" << endl << endl;

	cout << "Option 6 will explain how to use each menu option and describe what it does." << endl << endl;

	cout << "Option 7 will thank you and quit out of the menu.";
}

int main() {

	bool Quit = false;

	Plane small;
	small.readSeatChart();


	while (Quit == false) {

		switch (Menu()) {

		case 1:

			small.displaySeatChart();
			break;

		case 2:
			small.reserveSeat();
			break;

		case 3:
			small.cancelReservation();
			break;

		case 4:
			small.saveChart();
			break;

		case 5:
			small.statistics();
			break;

		case 6:
			help();
			break;

		case 7:
			cout << setfill('-') << setw(65) << "" << endl;
			cout << right << setfill(' ') << setw(43) << "Thank you, Safe Travels" << endl;
			cout << setfill('-') << setw(65) << "" << endl;
			Quit = true;
		}

	}

}