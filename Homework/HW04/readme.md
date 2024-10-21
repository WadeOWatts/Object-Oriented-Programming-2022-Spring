# Homework 4 Description

rite rational numbers in the form 2/3 or 37/51 to or from the keyboard (and to or from a file).
- Provide member functions `add`, `sub`, `mul`, and `div` that return a rational value.
- Provide a function `less` that returns a `bool` value. These functions should perform the corresponding operations as indicated by their names.
- Provide a member function `neg` that has no parameters and returns the negative of the calling object.

### Main Function
Provide a main function that thoroughly tests your class implementation.

### Useful Formulas for Defining Functions
- **Addition**: 
  ```
  a/b + c/d = (a * d + b * c) / (b * d)
  ```
- **Subtraction**: 
  ```
  a/b - c/d = (a * d - b * c) / (b * d)
  ```
- **Multiplication**: 
  ```
  (a/b) * (c/d) = (a * c) / (b * d)
  ```
- **Division**: 
  ```
  (a/b) / (c/d) = (a * d) / (c * b)
  ```
- **Negation**: 
  ```
  -(a/b) = (-a/b)
  ```
- **Comparison**: 
  - `(a/b) < (c/d)` means `(a * d) < (c * b)`
  - `(a/b) == (c/d)` means `(a * d) == (c * b)`

### Additional Notes
- Let any sign be carried by the numerator; keep the denominator positive.
