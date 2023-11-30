
#include <iostream>
#include <iomanip>
#include <string>
#include "Help.h"
#include "Plane.h"
#include <stdexcept>
#include <cctype>
#include "Menu.h"
#include "validInt.h"

int Menu() {

	// Displays Menu line 
	cout << endl;

	cout << setfill('-') << setw(33);
	cout << "Menu";
	cout << setfill('-') << setw(33) << "";
	cout << endl;


	//Displays Menu choices
	cout << "1.  Display Seat Chart" << endl;
	cout << "2.  Reserve Seat" << endl;
	cout << "3.  Cancel Reservation" << endl;
	cout << "4.  Save Seat Chart to File" << endl;
	cout << "5.  Statistics" << endl;
	cout << "6.  Help" << endl;
	cout << "7.  Quit" << endl;


	cout << setfill('-') << setw(65) << "" << endl;


	//Validaters the selection and returns it
	return validInt();
}