#include "Seat.h"
#include "Constant.h"
#pragma once
class Plane {

public:

	void readSeatChart();
	void displaySeatChart();
	void reserveSeat();
	void cancelReservation();
	void statistics();
	void saveChart();

private:
	int rowNumber = 0;
	int columnNumber = 0;
	string Letters[26] = { "A","B","C","D","E","F","G","H","I","J","K",
	"L","M","N","O","P","Q","R","S","T","U","V","W","X", "Y","Z" };
	Seat seatChart[ROWTOTAL][COLUMNTOTAL];
};

