#include <iostream>
#include<vector>
#include<map>
#include<fstream>
#include "Passenger.h"
#include "Admin.h"
#include "Flight.h"
#include "Booking.h"
#include "Payment.h"
//global
vector<Admin> admins;
vector<Passenger> passengers;
vector<Flight> flights;
vector<Booking> bookings;
map<int, Payment> payments;

//helper fn
void loadDataFromFile() {
    // Load Passengers
    ifstream passengerFile("passengers.txt");
    string name, email, pass;
    while (passengerFile >> name >> email >> pass) {
        passengers.push_back(Passenger(name, email, pass));
    }
    passengerFile.close();

    // Load Flights
    ifstream flightFile("flights.txt");
    int flightID, availableSeats;
    string destination, departureTime;
    float fare;
    while (flightFile >> flightID >> destination >> departureTime >> availableSeats >> fare) {
        flights.push_back(Flight(flightID, destination, departureTime, availableSeats, fare));
    }
    flightFile.close();

    // Load Bookings
    ifstream bookingFile("bookings.txt");
    int bookingID, passengerID;
    string status;
    bool paymentStatus;
    while (bookingFile >> bookingID >> passengerID >> flightID >> status >> paymentStatus) {
        Booking b(passengerID, flightID);
        b.bookingID = bookingID; // Restore booking ID
        b.status = status;
        b.paymentStatus = paymentStatus;
        bookings.push_back(b);
    }
    bookingFile.close();

    // Load Payments
    ifstream paymentFile("payments.txt");
    int paymentID;
    float amount;
    while (paymentFile >> bookingID >> paymentID >> amount >> paymentStatus) {
        Payment p(paymentID, amount);
        p.paymentStatus = paymentStatus;
        payments[bookingID] = p;
    }
    paymentFile.close();
}

void saveDataToFile() {
    // Save Passengers
    ofstream passengerFile("passengers.txt");
    for (Passenger &p : passengers) {
        passengerFile << p.getName() << " " << p.getEmail() << " " << p.getPassword() << endl;
    }
    passengerFile.close();

    // Save Flights
    ofstream flightFile("flights.txt");
    for (Flight &f : flights) {
        flightFile << f.flightID << " " << f.destination << " " << f.departureTime << " " 
                   << f.availableSeats << " " << f.fare << endl;
    }
    flightFile.close();

    // Save Bookings
    ofstream bookingFile("bookings.txt");
    for (Booking &b : bookings) {
        bookingFile << b.getBookingID() << " " << b.passengerID << " " << b.flightID << " " 
                    << b.status << " " << b.paymentStatus << endl;
    }
    bookingFile.close();

    // Save Payments
    ofstream paymentFile("payments.txt");
    for (auto &p : payments) {
        paymentFile << p.first << " " << p.second.paymentID << " " << p.second.amount 
                    << " " << p.second.paymentStatus << endl;
    }
    paymentFile.close();
    
    cout << "----- Saved successfully! -----\n";
}


void viewFlights() {
	if(flights.size() > 0) {
	    cout << "Available Flights:" << endl;
	    for (Flight &flight : flights) {
	        flight.displayFlight();
	    }
	}
	else cout << "No flights found!" << endl;
}

void viewAllPassengers()
{
	if(passengers.size() > 0)
	{
		cout << "Passengers:" << endl;
		for(Passenger &p : passengers)
		{
			p.displaydetails();
		}
	}
	else cout << "No Passengers found!\n";
}

void viewAllBookings()
{
	if(bookings.size() > 0)
	{
		cout << "All Bookings:\n";
		for(Booking &b : bookings)
		{
			b.displayBooking();
		}
	}
	else cout << "No bookings!\n";
}

void viewAllPayments()
{
	if(payments.size() > 0)
	{
		cout << "All Bookings:\n";
		for(const auto &p : payments)
		{
			int bookingID = p.first;
    		const Payment &payment = p.second;
    		cout << "Booking ID: " << bookingID << ", Payment ID: " << payment.paymentID << ", Amount: " << payment.amount << ", Status: " 
         	<< (payment.paymentStatus ? "Paid" : "Pending") << endl;
		}
	}
	else cout << "No Payments!\n";
}

void myTicket(int user_id)
{
	bool f = true;
	for(Booking &b : bookings)
	{
		if(b.passengerID == user_id)
		{
			f = false;
			b.displayBooking();
		}
	}
	if(f) cout << "No booking found for Passenger ID: " << user_id << endl;
}

void approveBooking(int user_id)
{
	bool f = true;
	for(Booking &b : bookings)
	{
		if(b.passengerID == user_id)
		{
			f = false;
			b.approveBooking();
			cout << "Booking Approved for Passenger ID: " << user_id << " for booking id: " << b.getBookingID() << endl;
		}
	}
	if(f) cout << "No booking found for Passenger ID: " << user_id << endl;
}

void Passenger::bookFlight(int FlightID)
{
	bool flightFound = false;
    for (Flight &flight : flights) {
        if (flight.flightID == FlightID && flight.availableSeats > 0) {
            flightFound = true;
            flight.availableSeats--;
            Booking newBooking(this->userId, FlightID); //current passenger user id
            bookings.push_back(newBooking);
            Payment newPayment(newBooking.getBookingID() ,flight.fare);
            payments[newBooking.getBookingID()] = newPayment;
            cout << "Flight booked successfully! Booking ID: " << newBooking.getBookingID() << endl;
            cout << "Processing payment of Rs." << flight.fare << "..." << endl;
            newPayment.processPayment();
            break;
        }
    }
    if (!flightFound) cout << "Flight not available!" << endl;
}

int main(int argc, char** argv) {	
	admins.push_back(Admin("admin", "a", "1"));
	loadDataFromFile();
	int choice;
	do {
		cout << "\n--- Flight Booking System ---\n";
        cout << "1. Register Passenger\n";
        cout << "2. Login as Passenger\n";
        cout << "3. Login as Admin\n";
        cout << "4. Save data in file\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1) {
        	string name, email, pass;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Password: ";
            cin >> pass;
            passengers.push_back(Passenger(name, email, pass));
            cout << "Registration successful!" << endl;
		}
		else if(choice == 2)
		{
			string email, pass;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Password: ";
            cin >> pass;
			for(Passenger &p : passengers){
				if(p.getEmail() == email && p.getPassword() == pass)
				{
					int option;
					do {
						cout << "\n1.View Flights\n2.Book Flight\n3.My Tickets\n4.Logout\n";
						cin >> option;
						if(option == 1)
						{
							viewFlights();
						}
						else if(option == 2)
						{
							int flightID;
                            cout << "Enter Flight ID: ";
                            cin >> flightID;
                            p.bookFlight(flightID);
						}
						else if(option == 3)
						{
							myTicket(p.userId);
						}
					}while(option!=4);
				}
            }
		}
		else if(choice == 3)
		{
			string email, pass;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Password: ";
            cin >> pass;
            for(Admin &a : admins)
            {
            	if(a.getEmail() == email && a.getPassword() == pass)
            	{
            		int option;
					do {
						cout << "\n1.Add Flights\n2.View All Flight\n3.View All Passengers\n4.View All Bookings\n5.All Payments\n6.Approve Booking\n7.Logout\n";
						cin >> option;
						if(option == 1)
						{
							int flightID;
							string destination, departureTime;
							int availableSeats;
							float fare;
							cout << "Flight id:";
							cin >> flightID;
							cout << "destination:";
							cin >> destination;
							cout << "departure time:";
							cin >> departureTime;
							cout << "total seats:";
							cin >> availableSeats;
							cout << "fare:";
							cin >> fare;	
							flights.push_back(Flight(flightID,destination,departureTime,availableSeats,fare));
							cout << "Added Successfully!" << endl;
						}
						else if(option == 2) viewFlights();
						else if(option == 3) viewAllPassengers();
						else if(option == 4) viewAllBookings();
						else if(option == 5) viewAllPayments();
						else if(option == 6) 
						{
							int id;
							cout << "Passenger id: ";
							cin >> id;
							approveBooking(id);
						}
					}while(option!=7);
				}
			}
		}
		else if(choice == 4) saveDataToFile();	
	}while(choice != 5);
	
	return 0;
}