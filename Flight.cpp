#include<iostream>
#include "Flight.h"
using namespace std;
Flight::Flight(int id, string dest, string time, int seat, float fare)
{
	this->flightID = id;
	this->destination = dest;
	this->departureTime = time;
	this->availableSeats = seat;
	this->fare = fare;
}

void Flight::displayFlight()
{
	cout << "Flight ID: " << flightID << ", Destination: " << destination << ", Departure: " << departureTime << ", Available Seats: " << availableSeats << ", Fare: " << fare << endl;
}