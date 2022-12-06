#include "Seat.h"
#include "Constant.h"

class Plane {

public:

	void readSeatChart();
	Seat seatChart[ROWTOTAL][COLUMNTOTAL];
	void displaySeatChart();
	void reserveSeat();
	void cancelReservation();
	void statistics();
	void saveChart();

private:
	int row = 0;
	int column = 0;
	string Letters[26] = { "A","B","C","D","E","F","G","H","I","J","K",
	"L","M","N","O","P","Q","R","S","T","U","V","W","X", "Y","Z" };
};