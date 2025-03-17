#include "passenger.h"
#include <iostream>
using namespace std;
int Passenger::passengerCount = 1; 
Passenger::Passenger(string n, string e, string p) : User(n, e, p) {
	userId = passengerCount++;
}

