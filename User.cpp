#include "user.h"
#include<iostream>
int User::userCount = 0;
User::User(string n, string e, string p)
{
    userId = ++userCount;
	name = n; 
    email = e;
    password = p;
}
void User::displaydetails() const {
    cout << "ID: " << userId << ", Name: " << name << ", Email: " << email << endl;
}