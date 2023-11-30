#include "Seat.h"


	void Seat:: setSeat(string seatLetter) {
		seatColumn = seatLetter;
	}

	string Seat ::  getSeat() {
		return seatColumn;
	}

	void Seat:: setReserved(bool reservedStatus) {
		reserved = reservedStatus;
	}

	bool Seat :: getReserved() {
		return reserved;
	}
