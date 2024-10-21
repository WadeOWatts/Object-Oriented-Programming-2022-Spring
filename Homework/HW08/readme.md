# Homework 8 Description

## Problem Description
An airline booking system stores information about tickets sold to passengers. Write a class called `BasicTicket` that stores a passenger's name, departure city, arrival city, flight number, and ticket price. Write a constructor to set the fields and include a method called `getPrice()` which returns the price of the ticket.

### Derived Class: `PremiumTicket`
Write a derived class called `PremiumTicket` that inherits all the details from `BasicTicket` but also stores the passenger's seat number. Write a constructor which sets all the `BasicTicket` information and the seat number. The price for `PremiumTickets` is 10% more than the price of a `BasicTicket`. Write a function which redefines the `getPrice()` method in `PremiumTicket` to return the price of the `PremiumTicket` by calling `BasicTicket`'s `getPrice()` method and multiplying the result by 10%.

### Driver Program Requirements
- Write a driver program which creates a `BasicTicket` object and a `PremiumTicket` object, and prints out the price of both.

### Additional Requirements
- Write a driver program which contains a vector of pointers to `BasicTicket` objects. Create some `BasicTicket` and `PremiumTicket` objects and add them into the vector. Write a simple function to add the cost of all the tickets in the vector. Manually compute and ensure that the sum returned by your function is correct.

