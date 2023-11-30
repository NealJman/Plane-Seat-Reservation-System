#pragma once
#include <string>

using namespace std;

class Seat {

public:
	void setSeat(string seatLetter);


	string getSeat();


	void setReserved(bool reservedStatus);


	bool getReserved();

private:
	string seatColumn;
	bool reserved = false;

};

