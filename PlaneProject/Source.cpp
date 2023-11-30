
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
#include "Menu.h"
using namespace std;

//   Purpose: Carry out Plane reservation system
//   Author: Neal Jayaraman
//   Creation Date: 12/1/22
//   Last Modification Date: 12/4/22
int main() {


	//Exiting progrma bool
	bool Quit = false;

	//Creates small plane object
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
			//Displays Thank you message and quits program
			cout << setfill('-') << setw(65) << "" << endl;
			cout << right << setfill(' ') << setw(43) << "Thank you, Safe Travels" << endl;
			cout << setfill('-') << setw(65) << "" << endl;

			//Exits Menu
			Quit = true;
		}

	}

}