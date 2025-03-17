#ifndef FLIGHT_H
#define FLIGHT_H
#include "User.h"
#include<string>
class Flight
{
	public:
		Flight() {}
		int flightID;
		string destination, departureTime;
		int availableSeats;
		float fare;
		
		Flight(int id, string dest, string time, int seat, float fare);
		void displayFlight();
		
};
#endif