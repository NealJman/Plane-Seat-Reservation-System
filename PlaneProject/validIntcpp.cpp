#include "validInt.h"
#include <iostream>
#include <string>
using namespace std;

int validInt() {

	bool error = false;

	//Number Selection
	cout << "Please Enter Your Choice (1-7) : ";
	string menuSelection;



	cin >> menuSelection;
	//Checks if input is valid

	int menuNumber = 0;

	try {

		menuNumber = stoi(menuSelection);

		if (menuSelection.size() > 1)
			throw runtime_error("Too big");

		if (menuNumber > 7 || menuNumber <= 0) {
			throw runtime_error("Not in range");
		}


	}

	catch (...) {

		cout << "Invalid Selection";
		error = true;
	}



	if (error == false)
		return menuNumber;

	else
		return 0;








}