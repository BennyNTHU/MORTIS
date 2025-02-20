# `Polynomial` Documentation

## Overview

`Polynomial.hpp` defines a `Polynomial` class for representing polynomials with integer exponents and floating-point coefficients. The class supports common polynomial operations like addition, subtraction, multiplication, and differentiation. It also provides functions to evaluate polynomials, retrieve coefficients, and handle terms.

---

## Key Components

### `Term` Structure

A `Term` represents a single term in the polynomial, consisting of:
- **`coef`**: The coefficient of the term (of type `float`).
- **`exp`**: The exponent of the term (of type `int`).

The `Term` structure includes the following methods:
- **`get_coef()`**: Returns the coefficient of the term.
- **`get_exp()`**: Returns the exponent of the term.

```cpp
struct Term
{
    float coef;
    int exp;

    float get_coef() const { return coef; }
    int get_exp() const { return exp; }
};
```

### `Polynomial` Class

The `Polynomial` class represents a polynomial as a collection of `Term` objects. It supports several constructors, member functions, and operator overloads to perform polynomial operations.

#### Member Variables
- **`terms`**: The number of non-zero terms in the polynomial.
- **`capacity`**: The capacity of the term array.
- **`termArray`**: A dynamic array of `Term` objects representing the terms of the polynomial.

#### Constructors & Destructor
- **`Polynomial()`**: Default constructor, initializes an empty polynomial.
- **`Polynomial(Term* t, int degree)`**: Constructor that initializes a polynomial from a given array of terms and a degree.
- **`Polynomial(const Polynomial& poly)`**: Copy constructor, creates a deep copy of another polynomial.
- **`~Polynomial()`**: Destructor, releases allocated memory for terms.

#### Member Functions

- **`Coef(int e)`**: Returns the coefficient of the term with exponent `e`. If no term with that exponent exists, it returns `0.0f`.
  
  Example:
  ```cpp
  float coef = poly.Coef(2);  // Get coefficient of x^2 term
  ```

- **`LeadExp()`**: Returns the exponent of the leading term (highest exponent).
  
  Example:
  ```cpp
  int leadExp = poly.LeadExp();  // Get leading exponent
  ```

- **`Eval(float x)`**: Evaluates the polynomial at a given value `x` using the polynomial's terms.
  
  Example:
  ```cpp
  float result = poly.Eval(2.0f);  // Evaluate polynomial at x = 2.0
  ```

- **`NewTerm(const float theCoeff, const int theExp)`**: Adds a new term with the given coefficient `theCoeff` and exponent `theExp` to the polynomial.
  
  Example:
  ```cpp
  poly.NewTerm(3.0f, 2);  // Add 3x^2 to the polynomial
  ```

- **`NewTerm(const std::string& latexTerm)`**: Adds a new term from a LaTeX-style string representation of the term.

  Example:
  ```cpp
  poly.NewTerm("3x^2");  // Add 3x^2 using LaTeX notation
  ```

- **`Differentiate()`**: Returns a new polynomial that is the derivative of the current polynomial.

  Example:
  ```cpp
  Polynomial derivative = poly.Differentiate();  // Differentiate the polynomial
  ```

#### Operator Overloads

- **`operator+(const Polynomial& poly)`**: Adds two polynomials and returns the result.
  
  Example:
  ```cpp
  Polynomial sum = poly1 + poly2;  // Add two polynomials
  ```

- **`operator-(const Polynomial& poly)`**: Subtracts one polynomial from another and returns the result.
  
  Example:
  ```cpp
  Polynomial difference = poly1 - poly2;  // Subtract two polynomials
  ```

- **`operator*(const Polynomial& poly)`**: Multiplies two polynomials and returns the result.
  
  Example:
  ```cpp
  Polynomial product = poly1 * poly2;  // Multiply two polynomials
  ```

- **`operator*(float constant)`**: Multiplies the polynomial by a constant and returns the result.
  
  Example:
  ```cpp
  Polynomial scaled = poly * 3.0f;  // Multiply polynomial by 3
  ```

- **`operator==(const Polynomial &poly)`**: Checks if two polynomials are equal (same terms and exponents).
  
  Example:
  ```cpp
  bool isEqual = (poly1 == poly2);  // Check if polynomials are equal
  ```

- **`operator!=(const Polynomial &poly)`**: Checks if two polynomials are not equal.
  
  Example:
  ```cpp
  bool isNotEqual = (poly1 != poly2);  // Check if polynomials are not equal
  ```

- **`operator=(const Polynomial &poly)`**: Assignment operator to copy the contents of another polynomial.
  
  Example:
  ```cpp
  poly1 = poly2;  // Copy contents of poly2 to poly1
  ```

#### Input/Output Operators

- **`operator<<(std::ostream& out, const Polynomial& poly)`**: Outputs the polynomial in LaTeX form.
  
  Example:
  ```cpp
  std::cout << poly;  // Print the polynomial in LaTeX format
  ```

- **`operator>>(std::istream& in, Polynomial& poly)`**: Reads a polynomial from an input stream in LaTeX form.
  
  Example:
  ```cpp
  std::cin >> poly;  // Read polynomial in LaTeX format
  ```

---

## Example Usage

```cpp
#include "Polynomial.hpp"

int main() {
    // Create a polynomial using terms
    Term terms[] = {{3.0f, 2}, {2.0f, 1}, {1.0f, 0}};
    Polynomial poly(terms, 2);  // Polynomial 3x^2 + 2x + 1

    // Add a new term
    poly.NewTerm(4.0f, 3);  // Add 4x^3

    // Evaluate the polynomial at x = 2
    float result = poly.Eval(2.0f);
    std::cout << "Evaluation at x=2: " << result << std::endl;

    // Differentiate the polynomial
    Polynomial derivative = poly.Differentiate();
    std::cout << "Derivative: " << derivative << std::endl;

    // Print the polynomial
    std::cout << "Polynomial: " << poly << std::endl;

    // Add two polynomials
    Polynomial poly2(terms, 2);
    Polynomial sum = poly + poly2;
    std::cout << "Sum of polynomials: " << sum << std::endl;

    return 0;
}
```

---

## Potential Errors & Edge Cases

1. **Empty Polynomial**: Ensure that polynomial operations handle cases where the polynomial has no terms.
2. **Incorrect LaTeX Format**: When using `NewTerm` with a LaTeX string, ensure that the string format is correct and valid for parsing.
3. **Exponent Conflicts**: When adding or subtracting polynomials, ensure that terms with the same exponent are combined correctly.

---

## Dependencies

- **C++ Standard Library**: The class uses standard C++ libraries such as `<iostream>`.
