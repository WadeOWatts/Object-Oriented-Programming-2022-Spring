# Homework 6 Description

## Problem Statement
Using dynamic arrays, implement a polynomial class with polynomial addition, subtraction, and multiplication.

### Discussion
A variable in a polynomial does very little other than act as a placeholder for the coefficients. Hence, the only interesting thing about polynomials is the array of coefficients and the corresponding exponent. Think about the polynomial:

```
x * x * x + x + 1
```

One simple way to implement the polynomial class is to use an array of `doubles` to store the coefficients. The index of the array is the exponent of the corresponding term. Where is the term in `x * x` in the previous example? If a term is missing, then it simply has a zero coefficient.

There are techniques for representing polynomials of high degree with many missing terms. These use so-called sparse polynomial techniques. Unless you already know these techniques, or learn very quickly, don't use them.

### Requirements
Provide a default constructor, a copy constructor, and a parameterized constructor that enables an arbitrary polynomial to be constructed. Also supply an overloaded operator `=` and a destructor.

### Provide These Operations:
- [x] `polynomial + polynomial`
- [x] `constant + polynomial`
- [ ] `polynomial + constant`
- [ ] `polynomial - polynomial`
- [ ] `constant - polynomial`
- [x] `polynomial - constant`
- [x] `polynomial * polynomial`
- [ ] `constant * polynomial`
- [ ] `polynomial * constant`

### Additional Requirements
- Supply functions to assign and extract coefficients, indexed by exponent.
- Supply a function to evaluate the polynomial at a value of type `double`.

### Implementation Details
You should decide whether to implement these functions as members, friends, or stand-alone functions.
