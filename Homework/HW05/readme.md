# Homework 5 Description

## Problem Description
Non-fiction books in libraries are often ordered by a decimal classification system. Consider a simple decimal classification system. One such system contains:
- A three-digit number which is the **subject area code**, and
- An **index number** which gives a more specific sub-category.

### Example
A geometry textbook may have the subject area code 516 and a subcategory code 3. This would be printed out to a user as the decimal number 516.3.

## Class Requirements
Write a class called `DecimalBookInfo` which stores information about a book in a library. The class should store:
- The **name of the book**
- Its **decimal classification number**

### Constructor Requirements
Your class should have a constructor which accepts:
- The **title** of the book as a C++ string
- Its **decimal classification code**

### Operator Overloading
- Overload the `<`, `<=`, `>`, `>=` operators to allow comparison between different `DecimalBookInfo` objects so that the program can sort the books inside a container.

### Driver Program
Write a driver program to test each component of your class.

### Additional Requirement
Please also prepare another version that uses **FRIEND** functions to finish those operations.
