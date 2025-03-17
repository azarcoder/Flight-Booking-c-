# Flight Booking System

## Description

The Flight Booking System is a console-based C++ application that allows passengers to book flights and manage their bookings. Administrators can manage flights, approve bookings, and view passenger and payment details.

## Features

### Passenger Module

- Register a new account
- Login with email and password
- View available flights
- Book a flight (only if seats are available)
- View their own booked tickets

### Admin Module

- Login with email and password
- Add new flights
- View all flights
- View all registered passengers
- View all bookings
- View all payments
- Approve pending bookings

### Booking & Payment Module

- Booking system with unique booking ID
- Payment processing and tracking
- Saves and loads booking and payment data from files

## File Structure

- **main.cpp** - Main program logic and user interface
- **Passenger.h / Passenger.cpp** - Defines passenger attributes and methods
- **Admin.h / Admin.cpp** - Defines admin attributes and methods
- **Flight.h / Flight.cpp** - Handles flight details
- **Booking.h / Booking.cpp** - Handles flight booking logic
- **Payment.h / Payment.cpp** - Handles payment transactions
- **passengers.txt** - Stores registered passenger details
- **flights.txt** - Stores flight information
- **bookings.txt** - Stores booking details
- **payments.txt** - Stores payment records

## Installation & Usage

1. **Compile the Program**
   ```sh
   g++ main.cpp User.cpp Passenger.cpp Flight.cpp Admin.cpp Booking.h Payment.cpp -o flight.exe
   ```
2. **Run the Program**
   ```sh
   Flight.exe
   ```
3. Follow the on-screen menu to register, login, and manage flights.

## Data Storage

- Data is stored in text files (`passengers.txt`, `flights.txt`, `bookings.txt`, `payments.txt`).
- On program start, data is loaded from files.
- On exit, data is saved to files.

## Future Enhancements

- Implement a GUI using Qt for better user experience.
- Integrate a real database for better data management.
- Add password encryption for security.
- Implement flight search and filtering options.

## Author

- Developed by Azarudeen

