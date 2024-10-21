# Homework 5 Description

Non-fiction books in libraries are often ordered by a decimal classification system. Consider a simple decimal classification system. One such system contains a three-digit number which is the subject area code, and an index number which gives a more specific sub-category. For example, a geometry textbook may have the subject area code 516 and a subcategory code 3. This would be printed out to a user as the decimal number 516.3. 

Write a class called `DecimalBookInfo` which stores information about a book in a library. The class should store the name of the book, and its decimal classification number.

Your class should have a constructor which accepts the title of the book as a C++ string and its decimal classification code. Overload the `<`, `<=`, `>`, `>=` operators to allow comparison between different `DecimalBookInfo` objects so that the program can sort the books inside a container. 

Write a driver program to test each component of your class.

**Please also prepare another version that uses FRIEND functions to finish those operations.**
