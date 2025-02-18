# LinkedPolynomial Documentation

## Overview
The `LinkedPolynomial` class implements a polynomial data structure using a **doubly linked list**. It supports basic polynomial operations, including addition, multiplication, differentiation, evaluation, and input/output operations.

This document provides a detailed guide on how to use the APIs with example programs.

---

## Class API

### 1. **Constructors & Destructor**
```cpp
LinkedPolynomial();  // Default constructor
LinkedPolynomial(const LinkedPolynomial& other);  // Copy constructor
LinkedPolynomial& operator=(const LinkedPolynomial& other);  // Copy assignment
~LinkedPolynomial();  // Destructor
```
#### Example:
```cpp
LinkedPolynomial poly1;
LinkedPolynomial poly2(poly1); // Copy constructor
LinkedPolynomial poly3 = poly1; // Copy assignment
```

### 2. **Basic Polynomial Operations**
#### a) Insert a term
```cpp
void InsertLinkedTerm(double coef, int exp);
```
**Example:**
```cpp
LinkedPolynomial poly;
poly.InsertLinkedTerm(3, 4); // 3x^4
poly.InsertLinkedTerm(5, 2); // 5x^2
```

#### b) Delete a term
```cpp
void DeleteLinkedTerm(int exp);
```
**Example:**
```cpp
poly.DeleteLinkedTerm(4); // Remove term with exponent 4
```

#### c) Get coefficient of a term
```cpp
double Coef(int exp) const;
```
**Example:**
```cpp
double coefficient = poly.Coef(2); // Returns coefficient of x^2
```

#### d) Get leading exponent (degree of the polynomial)
```cpp
int LeadExp() const;
```
**Example:**
```cpp
int degree = poly.LeadExp(); // Returns highest exponent in the polynomial
```

#### e) Evaluate the polynomial
```cpp
double Evaluate(double x) const;
```
**Example:**
```cpp
double value = poly.Evaluate(2.0); // Evaluates polynomial at x=2
```

### 3. **Polynomial Arithmetic Operations**
#### a) Addition
```cpp
LinkedPolynomial operator+(const LinkedPolynomial& other) const;
```
**Example:**
```cpp
LinkedPolynomial poly1, poly2, sum;
poly1.InsertLinkedTerm(3, 2);
poly2.InsertLinkedTerm(4, 2);
sum = poly1 + poly2; // (3x^2 + 4x^2) = 7x^2
```

#### b) Multiplication
```cpp
LinkedPolynomial operator*(const LinkedPolynomial& other) const;
```
**Example:**
```cpp
LinkedPolynomial poly1, poly2, product;
poly1.InsertLinkedTerm(2, 1);
poly2.InsertLinkedTerm(3, 2);
product = poly1 * poly2; // (2x^1 * 3x^2) = 6x^3
```

#### c) Differentiation
```cpp
LinkedPolynomial Differentiate() const;
```
**Example:**
```cpp
LinkedPolynomial poly;
poly.InsertLinkedTerm(5, 3); // 5x^3
LinkedPolynomial derivative = poly.Differentiate(); // Result: 15x^2
```

### 4. **Iterator Support**
```cpp
DLIterator<LinkedTerm> begin() const;
DLIterator<LinkedTerm> end() const;
```
**Example:**
```cpp
for (auto it = poly.begin(); it != poly.end(); ++it) {
    std::cout << it->getData().get_coef() << "x^" << it->getData().get_exp() << " ";
}
```

### 5. **I/O Operations**
#### a) Input (from LaTeX format)
```cpp
friend std::istream& operator>>(std::istream& in, LinkedPolynomial& poly);
```
**Example:**
```cpp
LinkedPolynomial poly;
std::cin >> poly; // Example input: "5x^3 + 2x^2 - 7"
```

#### b) Output (formatted polynomial display)
```cpp
friend std::ostream& operator<<(std::ostream& out, const LinkedPolynomial& poly);
```
**Example:**
```cpp
std::cout << poly; // Output: "5x^3 + 2x^2 - 7"
```

---

## Full Example Program

```cpp
#include <iostream>
#include "LinkedPolynomial.hpp"

int main() {
    LinkedPolynomial poly1, poly2, result;
    poly1.InsertLinkedTerm(3, 4);
    poly1.InsertLinkedTerm(2, 2);
    
    poly2.InsertLinkedTerm(5, 3);
    poly2.InsertLinkedTerm(-1, 2);
    
    result = poly1 + poly2;
    std::cout << "Sum: " << result << std::endl;
    
    result = poly1 * poly2;
    std::cout << "Product: " << result << std::endl;
    
    LinkedPolynomial derivative = result.Differentiate();
    std::cout << "Derivative: " << derivative << std::endl;
    
    double value = result.Evaluate(2.0);
    std::cout << "Evaluation at x=2: " << value << std::endl;
    
    return 0;
}
```

---

## Conclusion
This documentation provides a comprehensive guide to using `LinkedPolynomial`, including its API methods, example programs, and expected outputs. The class is designed for efficient manipulation of polynomials using a doubly linked list structure.

