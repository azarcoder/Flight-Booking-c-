#include "Admin.h"
#include <iostream>
using namespace std;
Admin::Admin(string n, string e, string p) : User(n, e, p) {}
void Admin::approveBooking(int bookingID)
{
	cout << "booking approve fn called " << bookingID << endl;
}
