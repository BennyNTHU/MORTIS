# Polynomial Data Structure Documentation

This document provides a detailed guide on how to use the Polynomial data structure, including a complete API description, usage examples, and compilation instructions. The Polynomial class is used to represent polynomials, where each term consists of a coefficient (which can be an integer or a floating-point number) and an integer exponent. Both input and output use LaTeX syntax, and the output automatically determines whether to display coefficients as integers (e.g., if the coefficient is effectively an integer, it will not display a decimal point).

---

## Table of Contents

- [Polynomial Data Structure Documentation](#polynomial-data-structure-documentation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Key Features](#key-features)
  - [API Description](#api-description)
    - [Constructors and Destructors](#constructors-and-destructors)
    - [Member Functions](#member-functions)
    - [Operator Overloading](#operator-overloading)
  - [Usage Examples](#usage-examples)
  - [Compilation and Execution](#compilation-and-execution)
  - [Notes](#notes)

---

## Overview

The Polynomial class provides a flexible data structure for polynomials, allowing users to:
- Input polynomials in LaTeX syntax format (e.g., `3x^{3}+2x^{2}+0.5x+1`).
- Output polynomials in LaTeX syntax format, automatically determining the coefficient display format:
  - If the coefficient is effectively an integer (within a tolerance), it is displayed as an integer;
  - Otherwise, the original floating-point precision is retained (no trailing zeros).
- Perform addition, subtraction, multiplication, and evaluation of polynomials.
- Support deep copying, assignment, and equality comparison.

---

## Key Features

- **Flexible Coefficient Format:** Coefficients can be either integers or floating-point numbers. During output, integer coefficients are displayed as integers, while floating-point coefficients retain their input precision.
- **LaTeX Syntax Input and Output:** Input format is like `3x^{3}+2x^{2}+0.5x+1`, and the output format is similar, making it easy for users to read and format.
- **Basic Operations:** Supports addition, subtraction, multiplication, and polynomial evaluation. Division is currently commented out and not handled.
- **Dynamic Storage:** Internally uses a dynamic array to store terms, automatically expanding when the number of terms exceeds the current capacity.

---

## API Description

### Constructors and Destructors

- **`Polynomial()`**  
  Constructs a zero polynomial *p(x) = 0*.  
  _Usage:_
  ```cpp
  Polynomial P; // P(x) = 0
  ```

- **`Polynomial(Term* t, int degree)`**  
  Constructs a polynomial from a given array of Term objects and the number of terms. The input array is copied and then released.  
  _Note:_ This constructor is typically used internally and is rarely called directly.

- **`Polynomial(const Polynomial &poly)`**  
  Copy constructor, performs a deep copy of the polynomial.

- **`~Polynomial()`**  
  Destructor, releases internally allocated memory.

### Member Functions

- **`float Coef(int e)`**  
  Returns the coefficient of the term with exponent `e`; returns 0 if the term does not exist.  
  _Usage:_
  ```cpp
  float c = P.Coef(2);  // Get the coefficient of the x^2 term
  ```

- **`int LeadExp()`**  
  Returns the highest exponent in the polynomial (i.e., the degree of the polynomial).  
  _Usage:_
  ```cpp
  int degree = P.LeadExp();
  ```

- **`float Eval(float x)`**  
  Evaluates the polynomial at the specified value of `x`.  
  _Usage:_
  ```cpp
  float result = P.Eval(2.0f);
  ```

- **`void NewTerm(const float theCoeff, const int theExp)`**  
  Adds a new term with coefficient `theCoeff` and exponent `theExp`. Automatically expands the internal array if capacity is insufficient.  
  _Usage:_
  ```cpp
  P.NewTerm(4, 4);  // Add the term 4x^4
  ```

- **`Polynomial Add(Polynomial poly)`**  
  Returns a new polynomial that is the sum of this polynomial and `poly`.  
  _Usage:_
  ```cpp
  Polynomial Sum = P.Add(Q);
  ```

- **`Polynomial Sub(Polynomial poly)`**  
  Returns a new polynomial that is the result of subtracting `poly` from this polynomial.  
  _Usage:_
  ```cpp
  Polynomial Diff = P.Sub(Q);
  ```

- **`Polynomial Mult(Polynomial poly)`**  
  Returns a new polynomial that is the product of this polynomial and `poly`.  
  _Usage:_
  ```cpp
  Polynomial Prod = P.Mult(Q);
  ```

- **Division**  
  Currently, the `Quotient` and `Remainder` functions are commented out because the results of division may be affected by computer arithmetic. If needed, please be aware of numerical issues.

### Operator Overloading

- **`istream& operator>>(istream& in, Polynomial& poly)`**  
  Reads a polynomial in LaTeX syntax format from the input stream. The input string should not contain spaces, e.g.,  
  `3x^{3}+2x^{2}+0.5x+1`  
  _Usage:_
  ```cpp
  cin >> P;
  ```

- **`ostream& operator<<(ostream& out, const Polynomial& poly)`**  
  Outputs the polynomial in LaTeX syntax format, with coefficients automatically formatted as integers or floating-point numbers (retaining original precision).  
  _Usage:_
  ```cpp
  cout << P;
  ```

- **`Polynomial& operator=(const Polynomial &)`**  
  Assignment operator, performs a deep copy.
  
- **`bool operator==(const Polynomial &) const`**  
  Checks if two polynomials are equal.

---

## Usage Examples

Below is a complete example demonstrating how to use the Polynomial class for various operations:

```cpp
#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    // Create polynomial P, defaulting to 0
    Polynomial P;
    cout << "Default polynomial P: " << P << endl;

    // Read polynomial P from input (enter in LaTeX format, e.g., 3x^{3}+2x^{2}+0.5x+1)
    cout << "\nEnter polynomial P in LaTeX format (e.g., 3x^{3}+2x^{2}+0.5x+1):" << endl;
    cin >> P;
    cout << "Polynomial P: " << P << endl;

    // Get the coefficient of the x^2 term in P
    cout << "\nCoefficient of x^2 in P: " << P.Coef(2) << endl;
    // Get the highest exponent in P
    cout << "Highest exponent in P: " << P.LeadExp() << endl;
    // Evaluate P at x = 2
    cout << "P evaluated at x = 2: " << P.Eval(2.0f) << endl;

    // Add a new term 4x^4 to P
    cout << "\nAdding new term: 4x^4" << endl;
    P.NewTerm(4, 4);
    cout << "Updated polynomial P: " << P << endl;

    // Test copy constructor and assignment operator
    Polynomial Q = P;  // Use copy constructor
    cout << "\nCopied polynomial Q (via copy constructor): " << Q << endl;
    Polynomial R;
    R = P;           // Use assignment operator
    cout << "Assigned polynomial R (via operator=): " << R << endl;

    // Test equality operator
    if (P == Q)
        cout << "P equals Q" << endl;
    else
        cout << "P does not equal Q" << endl;

    // Input another polynomial Q (e.g., 2x^{2}+1)
    cout << "\nEnter another polynomial Q in LaTeX format (e.g., 2x^{2}+1):" << endl;
    cin >> Q;
    cout << "Polynomial Q: " << Q << endl;

    // Test polynomial addition and subtraction
    Polynomial Sum = P.Add(Q);
    cout << "P + Q: " << Sum << endl;
    Polynomial Diff = P.Sub(Q);
    cout << "P - Q: " << Diff << endl;

    // Test polynomial multiplication
    Polynomial Prod = P.Mult(Q);
    cout << "P * Q: " << Prod << endl;

    // Division is currently commented out
    // if (Q.LeadExp() > 0 || Q.Coef(0) != 0) {
    //     Polynomial Quot = P.Quotient(Q);
    //     Polynomial Rem = P.Remainder(Q);
    //     cout << "P / Q: " << Quot << endl;
    //     cout << "P % Q: " << Rem << endl;
    // } else {
    //     cout << "Cannot perform division: Q is the zero polynomial." << endl;
    // }

    return 0;
}
```

---

## Compilation and Execution

Assuming the following files are in the same directory:
- `Polynomial.h`
- `Polynomial.cpp`
- `Polynomial-test.cpp`

Use the following command to compile and generate the executable (using g++ as an example):

```bash
g++ -std=c++11 Polynomial.cpp Polynomial-test.cpp -o polyTest
```

Then run the generated executable:

- **Linux/macOS:**
  ```bash
  ./polyTest
  ```
- **Windows:**
  ```bash
  polyTest.exe
  ```

During execution, follow the prompts to enter a polynomial in LaTeX syntax, for example:
```
Enter polynomial P in LaTeX format (e.g., 3x^{3}+2x^{2}+0.5x+1):
3x^{3}+2x^{2}+0.5x+1
```

The program will display the results of various polynomial operations, formatting the output appropriately based on the numerical properties of the coefficients.

---

## Notes

- **Division:** Due to potential issues with computer arithmetic precision, the division functions (`Quotient` and `Remainder`) are currently commented out and not handled.
- **Coefficient Format:** When the input coefficient is an integer, it is displayed as an integer; if it has a decimal, the original precision is retained without trailing zeros. This ensures consistency between input and output.
- **Input Format:** Ensure that the input polynomial string follows LaTeX syntax, e.g., `3x^{3}+2x^{2}+0.5x+1`. The system will automatically remove whitespace and parse the string.

---

This concludes the detailed documentation for the Polynomial data structure. If you have any questions or suggestions, please feel free to contact us!