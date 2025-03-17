#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
using namespace std;

class Payment {
private:
    static int paymentCounter; 
public:
    int paymentID;
    float amount;
    bool paymentStatus;
    int bookingID;
	
	Payment() : paymentID(0), amount(0.0), paymentStatus(false), bookingID(0) {}
    Payment(int bID, float amt);
    void processPayment();
};

#endif
