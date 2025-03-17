#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
using namespace std;
class Booking
{
	private:
		static int bookingCounter;
	public:
		 Booking() {}
		int bookingID;
		int passengerID;
		int flightID;
		string status;
		bool paymentStatus;
		
		//The constructor body {} runs after the member initializer list.
		// constructor after colon is a member initializer list
		Booking(int pID, int fID) : passengerID(pID), flightID(fID), paymentStatus(false) {
			bookingID = ++bookingCounter;
			status = "Pending";
		} 	
		
		//work as inline fn
		void approveBooking() { status = "Approved"; }

	    void displayBooking() {
	        cout << "Booking ID: " << bookingID << ", Passenger ID: " << passengerID
	             << ", Flight ID: " << flightID << ", Status: " << status << endl;
	    }
	    
	    int getBookingID() { return bookingID; }
};
int Booking::bookingCounter = 0;
#endif