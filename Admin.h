#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include<string>
class Admin:public User
{
	public:
		Admin(string n, string e, string p);
		void approveBooking(int bookingID);
		
};
#endif