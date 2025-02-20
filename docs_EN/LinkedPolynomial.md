# LinkedPolynomial.hpp Documentation

## Overview

The `LinkedPolynomial.hpp` header file defines two classes: `LinkedTerm` and `LinkedPolynomial`. The `LinkedTerm` class represents a single term in a polynomial, while the `LinkedPolynomial` class represents a polynomial as a doubly linked list of `LinkedTerm` nodes. This implementation allows for efficient manipulation of polynomials, including addition, subtraction, multiplication, differentiation, and evaluation.

## Class: `LinkedTerm`

### Description
The `LinkedTerm` class represents a single term in a polynomial, consisting of a coefficient and an exponent.

### Constructors

#### `LinkedTerm()`
- **Description**: Default constructor. Initializes a term with a coefficient of 0 and an exponent of 0.
- **Usage**:
  ```cpp
  LinkedTerm term;
  ```

#### `LinkedTerm(double c, int e)`
- **Description**: Constructor. Initializes a term with a given coefficient and exponent.
- **Parameters**:
  - `c`: The coefficient of the term.
  - `e`: The exponent of the term.
- **Usage**:
  ```cpp
  LinkedTerm term(3.5, 2);  // Represents the term 3.5x^2
  ```

### Getter and Setter Methods

#### `double get_coef() const`
- **Description**: Returns the coefficient of the term.
- **Return Value**: The coefficient as a `double`.
- **Usage**:
  ```cpp
  LinkedTerm term(3.5, 2);
  double coef = term.get_coef();  // coef is 3.5
  ```

#### `int get_exp() const`
- **Description**: Returns the exponent of the term.
- **Return Value**: The exponent as an `int`.
- **Usage**:
  ```cpp
  LinkedTerm term(3.5, 2);
  int exp = term.get_exp();  // exp is 2
  ```

#### `double& get_coef_ref()`
- **Description**: Returns a reference to the coefficient of the term, allowing modification.
- **Return Value**: A reference to the coefficient.
- **Usage**:
  ```cpp
  LinkedTerm term(3.5, 2);
  term.get_coef_ref() = 4.0;  // The term is now 4.0x^2
  ```

#### `void set_coef(double new_coef)`
- **Description**: Sets the coefficient of the term.
- **Parameters**:
  - `new_coef`: The new coefficient value.
- **Usage**:
  ```cpp
  LinkedTerm term(3.5, 2);
  term.set_coef(4.0);  // The term is now 4.0x^2
  ```

### Overloaded Operators

#### `bool operator==(const LinkedTerm& other) const`
- **Description**: Equality operator. Checks if two terms are equal.
- **Parameters**:
  - `other`: The `LinkedTerm` to compare with.
- **Return Value**: `true` if the terms are equal, `false` otherwise.
- **Usage**:
  ```cpp
  LinkedTerm term1(3.5, 2);
  LinkedTerm term2(3.5, 2);
  bool equal = (term1 == term2);  // equal is true
  ```

## Class: `LinkedPolynomial`

### Description
The `LinkedPolynomial` class represents a polynomial as a doubly linked list of `LinkedTerm` nodes. It provides methods for polynomial manipulation, including addition, subtraction, multiplication, differentiation, and evaluation.

### Constructors and Destructors

#### `LinkedPolynomial()`
- **Description**: Default constructor. Initializes an empty polynomial.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  ```

#### `LinkedPolynomial(const LinkedPolynomial& other)`
- **Description**: Copy constructor. Initializes a new polynomial by copying elements from another polynomial.
- **Parameters**:
  - `other`: The `LinkedPolynomial` object to copy from.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2(poly1);
  ```

#### `~LinkedPolynomial()`
- **Description**: Destructor. Cleans up the polynomial by deleting all nodes.
- **Usage**: Automatically called when the object goes out of scope.

### Properties

#### `int LeadExp()`
- **Description**: Returns the highest exponent in the polynomial.
- **Return Value**: The highest exponent as an `int`.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  poly.InsertLinkedTerm(2.0, 3);
  int leadExp = poly.LeadExp();  // leadExp is 3
  ```

#### `double Coef(int e)`
- **Description**: Returns the coefficient of the term with the given exponent.
- **Parameters**:
  - `e`: The exponent of the term.
- **Return Value**: The coefficient as a `double`.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  double coef = poly.Coef(2);  // coef is 3.5
  ```

#### `DLIterator<LinkedTerm> begin() const`
- **Description**: Returns an iterator pointing to the first term in the polynomial.
- **Return Value**: A `DLIterator<LinkedTerm>` object.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  DLIterator<LinkedTerm> it = poly.begin();
  ```

#### `DLIterator<LinkedTerm> end() const`
- **Description**: Returns an iterator pointing to the end of the polynomial (nullptr).
- **Return Value**: A `DLIterator<LinkedTerm>` object.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  DLIterator<LinkedTerm> it = poly.end();
  ```

### Operations

#### `LinkedPolynomial operator+(const LinkedPolynomial& other) const`
- **Description**: Adds two polynomials.
- **Parameters**:
  - `other`: The `LinkedPolynomial` to add.
- **Return Value**: A new `LinkedPolynomial` representing the sum.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  LinkedPolynomial sum = poly1 + poly2;
  ```

#### `LinkedPolynomial operator-(const LinkedPolynomial& other) const`
- **Description**: Subtracts another polynomial from this polynomial.
- **Parameters**:
  - `other`: The `LinkedPolynomial` to subtract.
- **Return Value**: A new `LinkedPolynomial` representing the difference.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  LinkedPolynomial diff = poly1 - poly2;
  ```

#### `LinkedPolynomial operator*(float constant) const`
- **Description**: Multiplies the polynomial by a constant.
- **Parameters**:
  - `constant`: The constant to multiply by.
- **Return Value**: A new `LinkedPolynomial` representing the product.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial product = poly * 2.0;
  ```

#### `LinkedPolynomial operator*(const LinkedPolynomial& other) const`
- **Description**: Multiplies two polynomials.
- **Parameters**:
  - `other`: The `LinkedPolynomial` to multiply by.
- **Return Value**: A new `LinkedPolynomial` representing the product.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  LinkedPolynomial product = poly1 * poly2;
  ```

#### `LinkedPolynomial Differentiate() const`
- **Description**: Differentiates the polynomial.
- **Return Value**: A new `LinkedPolynomial` representing the derivative.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial derivative = poly.Differentiate();
  ```

#### `double Evaluate(double x) const`
- **Description**: Evaluates the polynomial at a given value of `x`.
- **Parameters**:
  - `x`: The value at which to evaluate the polynomial.
- **Return Value**: The result of the evaluation as a `double`.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  double result = poly.Evaluate(2.0);  // Evaluates 3.5 * (2.0)^2
  ```

### Other Functions

#### `void Clear()`
- **Description**: Clears the polynomial, removing all terms.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  poly.Clear();  // The polynomial is now empty
  ```

#### `void CopyFrom(const LinkedPolynomial& other)`
- **Description**: Copies the contents of another polynomial into this polynomial.
- **Parameters**:
  - `other`: The `LinkedPolynomial` to copy from.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.CopyFrom(poly1);
  ```

#### `void InsertLinkedTerm(double coef, int exp)`
- **Description**: Inserts a new term into the polynomial.
- **Parameters**:
  - `coef`: The coefficient of the term.
  - `exp`: The exponent of the term.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);  // Inserts the term 3.5x^2
  ```

#### `void InsertLinkedTerm(const std::string& term)`
- **Description**: Inserts a new term into the polynomial using a LaTeX-style input string.
- **Parameters**:
  - `term`: A string representing the term in LaTeX format (e.g., "3.5x^2").
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm("3.5x^2");  // Inserts the term 3.5x^2
  ```

#### `void DeleteLinkedTerm(int exp)`
- **Description**: Deletes the term with the given exponent from the polynomial.
- **Parameters**:
  - `exp`: The exponent of the term to delete.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  poly.DeleteLinkedTerm(2);  // Deletes the term 3.5x^2
  ```

### Overloaded Operators

#### `LinkedPolynomial& operator=(const LinkedPolynomial& other)`
- **Description**: Assignment operator. Assigns the contents of another polynomial to this polynomial.
- **Parameters**:
  - `other`: The `LinkedPolynomial` to assign from.
- **Return Value**: A reference to the current polynomial.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2 = poly1;  // poly2 now contains the term 3.5x^2
  ```

#### `bool operator==(const LinkedPolynomial& other) const`
- **Description**: Equality operator. Checks if two polynomials are equal.
- **Parameters**:
  - `other`: The `LinkedPolynomial` to compare with.
- **Return Value**: `true` if the polynomials are equal, `false` otherwise.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(3.5, 2);
  bool equal = (poly1 == poly2);  // equal is true
  ```

#### `bool operator!=(const LinkedPolynomial& other) const`
- **Description**: Inequality operator. Checks if two polynomials are not equal.
- **Parameters**:
  - `other`: The `LinkedPolynomial` to compare with.
- **Return Value**: `true` if the polynomials are not equal, `false` otherwise.
- **Usage**:
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  bool notEqual = (poly1 != poly2);  // notEqual is true
  ```

#### `friend std::ostream& operator<<(std::ostream& out, const LinkedPolynomial& poly)`
- **Description**: Overloaded `<<` operator for printing the polynomial in LaTeX style.
- **Parameters**:
  - `out`: The output stream.
  - `poly`: The `LinkedPolynomial` to print.
- **Return Value**: The output stream.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  std::cout << poly;  // Prints the polynomial in LaTeX style
  ```

#### `friend std::istream& operator>>(std::istream &in, LinkedPolynomial &poly)`
- **Description**: Overloaded `>>` operator for reading the polynomial in LaTeX style.
- **Parameters**:
  - `in`: The input stream.
  - `poly`: The `LinkedPolynomial` to read into.
- **Return Value**: The input stream.
- **Usage**:
  ```cpp
  LinkedPolynomial poly;
  std::cin >> poly;  // Reads the polynomial in LaTeX style
  ```

## Example Usage

```cpp
#include "LinkedPolynomial.hpp"
#include <iostream>

int main() {
    LinkedPolynomial poly1;
    poly1.InsertLinkedTerm(3.5, 2);
    poly1.InsertLinkedTerm(2.0, 3);

    LinkedPolynomial poly2;
    poly2.InsertLinkedTerm(1.5, 2);
    poly2.InsertLinkedTerm(4.0, 1);

    LinkedPolynomial sum = poly1 + poly2;
    std::cout << "Sum: " << sum << std::endl;

    LinkedPolynomial product = poly1 * poly2;
    std::cout << "Product: " << product << std::endl;

    LinkedPolynomial derivative = poly1.Differentiate();
    std::cout << "Derivative of poly1: " << derivative << std::endl;

    double result = poly1.Evaluate(2.0);
    std::cout << "Evaluation of poly1 at x=2.0: " << result << std::endl;

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Empty Polynomial**: Operations like `LeadExp()` or `Coef(int e)` on an empty polynomial may result in undefined behavior. Ensure the polynomial is not empty before performing these operations.
2. **Invalid Exponents**: When inserting or deleting terms, ensure the exponent is valid (non-negative) to avoid unexpected behavior.
3. **Memory Management**: Ensure proper memory management when dealing with large polynomials to avoid memory leaks.

## Dependencies

- `Node.hpp`: Defines the basic node structure.
- `DoubleNode.hpp`: Defines the doubly linked node structure.
- `ChainIterator.hpp`: Provides iterator functionality for the list.
- `DLIterator.hpp`: Provides iterator functionality for the doubly linked list.

Ensure these files are included and properly configured in your project to use `LinkedPolynomial.hpp`.
