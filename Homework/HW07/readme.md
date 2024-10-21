# Homework 7 Description

## Program 2 from Chapter 11
Redo Practice Programs 2 from Chapter 11, but this time define the `Pairs` ADT class in separate files for the interface and implementation so that the implementation can be compiled separately from any application program.

## Exercise 17 from Chapter 11
Self-Test Exercise 17 asked you to overload the operator `>>` and the operator `<<` for a class `Pairs`. Complete and test this exercise. Implement the default constructor and the constructors with one and two `int` parameters. The one-parameter constructor should initialize the first member of the pair; the second member of the pair is to be 0.

### Operations to Implement:
- **Overload binary operator +** to add pairs according to the rule:  
  `(a, b) + (c, d) = (a + c, b + d)`
- **Overload operator -** analogously.
- **Overload operator \*** on `Pairs` and `int` according to the rule:  
  `(a, b) * c = (a * c, b * c)`

Write a program to test all the member functions and overloaded operators in your class definition.

## Additional Details for Exercise 17
Here is a definition of a class called `Pairs`. Objects of type `Pairs` can be used in any situation where ordered pairs are needed. Your task is to write implementations of the overloaded operator `>>` and the overloaded operator `<<` so that objects of class `Pairs` are to be input and output in the form `(5,6) (5,-4) (-5,4) or (-5,-6)`. You need not implement any constructor or other member, and you need not do any input format checking.

### Code Snippet
```cpp
#include <iostream>
using namespace std;

class Pairs {
public:
    Pairs();  // Default constructor
    Pairs(int first, int second);  // Parameterized constructor
    
    // Other members and friends
    friend istream& operator>>(istream& ins, Pairs& second);
    friend ostream& operator<<(ostream& outs, const Pairs& second);
    
private:
    int f;  // First element of the pair
    int s;  // Second element of the pair
};
```