#ifndef PASSENGER_H
#define PASSENGER_H
#include "User.h"
#include<string>
class Passenger:public User
{
	private:
		static int passengerCount;
	public: 
		Passenger() {}
		Passenger(string n, string e, string p);
		void bookFlight(int FlightID);
};
#endif