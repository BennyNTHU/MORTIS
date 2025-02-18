# SparseMatrix Data Structure Documentation

This document provides a detailed guide on how to use the **SparseMatrix** data structure. The SparseMatrix class is designed to efficiently represent matrices with many zero elements. In this implementation, each nonzero element is stored as a **MatrixTerm**, and the element value can be either an integer or a floating-point number using `std::variant<int, float>`. The class supports common operations such as transposition, addition, multiplication, and scalar multiplication. It also provides both dense and sparse printing methods, as well as overloaded input/output operators.

---

## Table of Contents

- [SparseMatrix Data Structure Documentation](#sparsematrix-data-structure-documentation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Key Features](#key-features)
  - [API Documentation](#api-documentation)
    - [Constructors and Destructor](#constructors-and-destructor)
    - [Member Functions](#member-functions)
    - [Overloaded Operators](#overloaded-operators)
  - [Usage Examples](#usage-examples)
  - [Compilation and Execution](#compilation-and-execution)
  - [Notes](#notes)

---

## Overview

The **SparseMatrix** class efficiently stores and operates on matrices that contain many zeros by only storing the nonzero terms. Each nonzero term is represented by a **MatrixTerm** which holds:
- **Row index**
- **Column index**
- **Value**: This is stored as a `std::variant<int, float>`, so it can represent either an integer or a float.

---

## Key Features

- **Efficient Storage:** Only nonzero elements are stored, reducing memory usage for large sparse matrices.
- **Mixed Data Types:** Elements can be integers or floating-point numbers. When printing, integer values are shown as integers while floats retain their original precision.
- **Dense and Sparse Printing:**  
  - The overloaded `<<` operator prints the nonzero terms in a sparse format.
  - The `printMatrix()` function outputs the complete dense matrix form.
- **Matrix Operations:**  
  - **FastTranspose()**: Compute the transpose of the matrix.
  - **Add()**: Sum of two matrices.
  - **Multiply()**: Product of two matrices.
  - **ScalarProduct()**: Multiply every nonzero element by a scalar value.
- **Overloaded Input/Output Operators:**  
  - `operator>>` reads matrix terms in the format `(row col value)`.
  - `operator<<` outputs the matrix terms in `(row, col, value)` format.
- **Dynamic Resizing:** The internal array automatically expands if additional nonzero elements need to be stored.

---

## API Documentation

### Constructors and Destructor

- **`SparseMatrix(int r, int c, int t)`**  
  Constructs a sparse matrix with `r` rows, `c` columns, and an initial capacity for `t` nonzero terms.

  ```cpp
  // Example: Create a 4x5 sparse matrix with space for 3 nonzero terms.
  SparseMatrix A(4, 5, 3);
  ```

- **`SparseMatrix(const SparseMatrix &b)`**  
  Copy constructor that creates a deep copy of matrix `b`.

- **`~SparseMatrix()`**  
  Destructor that frees allocated memory.

### Member Functions

- **`void setTerm(int index, int r, int c, const std::variant<int, float>& v)`**  
  Public method to set a nonzero term at the given index. This is used to avoid direct access to the private `smArray`.

- **`int get_terms() const`**  
  Returns the number of nonzero terms stored in the matrix.

- **`void ChangeSize1D(const int newSize)`**  
  Changes the size of the internal array to `newSize`. Throws an exception if `newSize` is less than the current number of terms.

- **`void StoreNum(const std::variant<int, float>& num, const int r, const int c)`**  
  Adds a new term at position `(r, c)` if `num` is nonzero.

- **`SparseMatrix FastTranspose()`**  
  Returns a new SparseMatrix that is the transpose of the current matrix.

- **`SparseMatrix Add(SparseMatrix b)`**  
  Returns a new matrix that is the sum of the current matrix and matrix `b`. Throws an exception if dimensions do not match.

- **`SparseMatrix Multiply(SparseMatrix b)`**  
  Returns the product of the current matrix and matrix `b`. Throws an exception if the matrices have incompatible dimensions.

- **`SparseMatrix Multiply(SparseMatrix b, int n)`**  
  Placeholder for matrix exponentiation. (Not implemented.)

- **`SparseMatrix ScalarProduct(std::variant<int, float> n)`**  
  Returns a new matrix that is the current matrix scaled by the scalar `n`. If both the element and scalar are integers, the result remains an integer; otherwise, it is computed as a float.

- **`void printMatrix() const`**  
  Prints the matrix in its dense form. Each element is printed in its appropriate format (integer or float). Zeros are printed where no nonzero term exists.

### Overloaded Operators

- **`friend istream& operator>>(istream& in, const SparseMatrix& b)`**  
  Reads matrix terms from the input stream. The user is prompted to enter terms in the format:  
  ```
  row col value
  ```
  The value is interpreted as an integer if it does not contain a decimal point, or as a float otherwise.

- **`friend ostream& operator<<(ostream& out, const SparseMatrix& b)`**  
  Outputs the sparse matrix in a sparse format, printing each nonzero term in the format:  
  ```
  (row, col, value)
  ```

---

## Usage Examples

Below is an example program demonstrating how to use the SparseMatrix class:

```cpp
// SparseMatrix-test.cpp
// Comprehensive test for SparseMatrix functionalities.
// Compile with C++17:
//   g++ -std=c++17 SparseMatrix.cpp SparseMatrix-test.cpp -o sparseTest

#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main() {
    cout << "=== SparseMatrix Test Program ===" << endl;
    
    // Test 1: Create a 4x5 sparse matrix A with 3 nonzero terms.
    SparseMatrix A(4, 5, 3);
    // Set nonzero terms using setTerm():
    A.setTerm(0, 0, 1, 5);         // Term: (0,1) = 5 (integer)
    A.setTerm(1, 2, 3, 3.14f);       // Term: (2,3) = 3.14 (float)
    A.setTerm(2, 3, 0, -2);          // Term: (3,0) = -2 (integer)
    cout << "\nMatrix A (sparse form):" << endl;
    cout << A << endl;
    
    // Test 2: Dense printing of matrix A.
    cout << "Dense form of matrix A:" << endl;
    A.printMatrix();
    
    // Test 3: FastTranspose of A.
    SparseMatrix AT = A.FastTranspose();
    cout << "\nTranspose of matrix A (sparse form):" << endl;
    cout << AT << endl;
    cout << "Dense form of transpose A:" << endl;
    AT.printMatrix();
    
    // Test 4: Copy constructor.
    SparseMatrix B = A; // Create B as a copy of A.
    cout << "\nMatrix B (copy of A):" << endl;
    cout << B << endl;
    
    // Test 5: Addition.
    SparseMatrix C(4, 5, 2);
    C.setTerm(0, 0, 1, 10.5f);       // Term: (0,1) = 10.5 (float)
    C.setTerm(1, 2, 3, -3);          // Term: (2,3) = -3 (integer)
    cout << "\nMatrix C:" << endl;
    cout << C << endl;
    SparseMatrix Sum = A.Add(C);
    cout << "\nA + C (sparse form):" << endl;
    cout << Sum << endl;
    cout << "Dense form of (A + C):" << endl;
    Sum.printMatrix();
    
    // Test 6: Multiplication.
    SparseMatrix D(5, 3, 2);
    D.setTerm(0, 1, 0, 2);           // Term: (1,0) = 2 (integer)
    D.setTerm(1, 3, 2, 4.5f);         // Term: (3,2) = 4.5 (float)
    cout << "\nMatrix D:" << endl;
    cout << D << endl;
    SparseMatrix E = A.Multiply(D);
    cout << "\nA * D (sparse form):" << endl;
    cout << E << endl;
    cout << "Dense form of (A * D):" << endl;
    E.printMatrix();
    
    // Test 7: ScalarProduct.
    SparseMatrix F = A.ScalarProduct(3);
    cout << "\nScalar product of A with 3:" << endl;
    cout << F << endl;
    cout << "Dense form:" << endl;
    F.printMatrix();
    
    SparseMatrix G = A.ScalarProduct(2.5f);
    cout << "\nScalar product of A with 2.5:" << endl;
    cout << G << endl;
    cout << "Dense form:" << endl;
    G.printMatrix();
    
    // Test 8: Overloaded input operator.
    // Create a 3x3 matrix H with 2 nonzero terms.
    SparseMatrix H(3, 3, 2);
    cout << "\nEnter 2 terms for matrix H in the format: row col value" << endl;
    // Example input:
    // 0 0 7
    // 1 2 3.5
    cin >> H;
    cout << "\nMatrix H (sparse form):" << endl;
    cout << H << endl;
    cout << "Dense form of matrix H:" << endl;
    H.printMatrix();
    
    return 0;
}
```

---

## Compilation and Execution

Assuming you have the following files in the same directory:

- `SparseMatrix.h`
- `SparseMatrix.cpp`
- `SparseMatrix-test.cpp`

Compile using g++ with C++17 support:

```bash
g++ -std=c++17 SparseMatrix.cpp SparseMatrix-test.cpp -o sparseTest
```

Then run the executable:

- **On Linux/macOS:**
  ```bash
  ./sparseTest
  ```
- **On Windows:**
  ```bash
  sparseTest.exe
  ```

When prompted for input (for matrix H), enter each term as three space-separated values (row, col, value). For example:

```
0 0 7
1 2 3.5
```

The program will then display the results of all operations, including both the sparse and dense representations of each matrix.

---

## Notes

- **Mixed Element Types:**  
  The implementation uses `std::variant<int, float>` to store values. Arithmetic operations are performed in such a way that if both operands are integers, the result remains an integer; otherwise, the result is computed as a float.

- **Dense Printing:**  
  The `printMatrix()` function iterates over every position in the matrix and prints the corresponding value (or zero if no nonzero term exists).

- **Scalability:**  
  The internal array resizes dynamically if additional nonzero terms are added.

- **Input Format:**  
  When using the overloaded input operator (`>>`), you must enter the terms in the following format (one term per line):
  ```
  row col value
  ```
  The value is interpreted as an integer if it does not contain a decimal point, or as a float otherwise.

---

This documentation should help you understand and effectively use the **SparseMatrix** data structure. If you have any further questions or need additional modifications, please let me know!