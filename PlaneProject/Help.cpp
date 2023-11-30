
using namespace std;
#include <iostream>

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