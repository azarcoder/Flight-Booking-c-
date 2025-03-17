#include "Payment.h"

int Payment::paymentCounter = 1000; 

Payment::Payment(int bID, float amt) : bookingID(bID), amount(amt), paymentStatus(false) {
    paymentID = ++paymentCounter;
}

void Payment::processPayment() {
    paymentStatus = true;
    cout << "Payment for Booking ID " << bookingID << " is successful." << endl;
}
