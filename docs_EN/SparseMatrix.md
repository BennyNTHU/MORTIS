# `SparseMatrix.hpp` Documentation

## Overview

The `SparseMatrix.hpp` header file defines a `SparseMatrix` class that models a sparse matrix using an array of `MatrixTerm` objects. This class provides methods for matrix operations, access, and manipulation, such as addition, subtraction, multiplication, transpose, and norm calculation. The matrix elements are stored efficiently to conserve memory, as only non-zero elements are represented.

---

## Key Components

### `MatrixTerm` Class

A `MatrixTerm` represents a single non-zero element in the sparse matrix. Each term stores:
- **`row`**: The row index of the matrix term.
- **`col`**: The column index of the matrix term.
- **`value`**: The value of the term, which can be either an `int` or a `double` (using `std::variant`).

#### Methods:
- **`get_row()`**: Returns the row index of the term.
- **`get_col()`**: Returns the column index of the term.
- **`get_value()`**: Returns the value of the term, which is stored as a `std::variant<int, double>`.
- **`write_term(int r, int c, const std::variant<int, double>& v)`**: Updates the term with a new row, column, and value.
- **Operator Overloads**:
  - **`operator->()`**: Overloads the pointer operator to return a pointer to the current term.
  - **`operator*()`**: Overloads the dereference operator to return the current term.
  - **`operator==(const MatrixTerm& other)`**: Compares two matrix terms for equality.
  - **`operator!=(const MatrixTerm& other)`**: Compares two matrix terms for inequality.

---

### `SparseMatrix` Class

The `SparseMatrix` class represents a sparse matrix using a dynamically allocated array of `MatrixTerm` objects. It stores only the non-zero elements of the matrix, significantly reducing memory usage for large matrices with many zero values.

#### Member Variables:
- **`rows`**: The number of rows in the matrix.
- **`cols`**: The number of columns in the matrix.
- **`terms`**: The number of non-zero terms in the matrix.
- **`capacity`**: The capacity of the array used to store matrix terms.
- **`smArray`**: A pointer to a dynamically allocated array of `MatrixTerm` objects.

#### Constructors & Destructor:
- **`SparseMatrix()`**: Default constructor that initializes an empty sparse matrix.
- **`SparseMatrix(int r, int c, int t = 0)`**: Constructor that initializes a sparse matrix with a specified number of rows `r`, columns `c`, and optionally the number of non-zero terms `t`.
- **`SparseMatrix(const SparseMatrix& b)`**: Copy constructor that creates a deep copy of another sparse matrix.
- **`~SparseMatrix()`**: Destructor that frees the dynamically allocated memory for the matrix terms.

#### Member Functions:
- **`get_rows()`**: Returns the number of rows in the matrix.
- **`get_cols()`**: Returns the number of columns in the matrix.
- **`get_terms()`**: Returns the number of non-zero terms in the matrix.
- **`get_capacity()`**: Returns the capacity of the term array.
- **`get_smArray()`**: Returns a pointer to the array of matrix terms.

- **`StoreNum(const std::variant<int, double>& num, int r, int c)`**: Stores a non-zero value `num` at the specified row `r` and column `c`. If `num` is zero, the term is not stored.
  
- **`ChangeSize1D(int newSize)`**: Changes the size of the term array.
  
- **`printMatrix()`**: Prints the matrix in dense format for debugging purposes.

- **`FastTranspose()`**: Returns a new sparse matrix that is the transpose of the current matrix, computed using an efficient algorithm for sparse matrices.

- **`Norm()`**: Returns the Frobenius norm of the matrix, which is calculated as the square root of the sum of the squares of all non-zero elements.

#### Operator Overloads:
- **`operator+(const SparseMatrix& b)`**: Adds two sparse matrices and returns the result.
- **`operator-(const SparseMatrix& b)`**: Subtracts one sparse matrix from another and returns the result.
- **`operator*(const SparseMatrix& b)`**: Multiplies two sparse matrices and returns the result.
- **`operator*(const std::vector<double>& vec)`**: Multiplies the sparse matrix by a dense vector and returns the result.
- **`operator*(std::variant<int, double> scalar)`**: Multiplies the matrix by a scalar and returns the result.

- **`operator=(const SparseMatrix& other)`**: Assignment operator to copy the contents of another sparse matrix.
- **`operator==(const SparseMatrix& other)`**: Checks if two sparse matrices are equal (same terms, same values).
- **`operator!=(const SparseMatrix& other)`**: Checks if two sparse matrices are not equal.
- **`operator[](int index)`**: Returns the value of the term at index `i` in the matrix's internal term array.

#### Input/Output Operators:
- **`operator<<(std::ostream& out, const SparseMatrix& mat)`**: Outputs the sparse matrix in a readable format.
- **`operator>>(std::istream& in, SparseMatrix& mat)`**: Reads a sparse matrix from an input stream.

---

## Example Usage

```cpp
#include "SparseMatrix.hpp"

int main() {
    // Create a 3x3 sparse matrix with 2 non-zero terms
    SparseMatrix mat(3, 3, 2);
    
    // Store terms in the matrix
    mat.StoreNum(3.5, 0, 1);  // Set element at (0, 1) to 3.5
    mat.StoreNum(4.2, 2, 2);  // Set element at (2, 2) to 4.2
    
    // Print the matrix
    mat.printMatrix();

    // Get the Frobenius norm of the matrix
    double norm = mat.Norm();
    std::cout << "Frobenius Norm: " << norm << std::endl;

    // Transpose the matrix
    SparseMatrix transposed = mat.FastTranspose();
    std::cout << "Transposed Matrix: " << transposed << std::endl;

    // Add another sparse matrix
    SparseMatrix mat2(3, 3, 1);
    mat2.StoreNum(1.5, 1, 1);
    SparseMatrix result = mat + mat2;
    std::cout << "Result of Addition: " << result << std::endl;

    return 0;
}
```

---

## Potential Errors & Edge Cases

1. **Zero Terms**: Ensure that when adding or subtracting matrices, both matrices have the same number of non-zero terms or handle cases where one matrix has more non-zero terms than the other.
2. **Out of Bounds Access**: Always check that row and column indices used in `StoreNum` and other functions are within valid ranges.
3. **Empty Matrix**: Make sure to handle edge cases where a matrix might be empty (e.g., zero rows or columns).
4. **Large Matrices**: For very large sparse matrices, ensure that the matrix is properly resized, and handle any memory allocation failures.

---

## Dependencies

- **C++ Standard Library**: The class uses standard C++ libraries such as `<iostream>`, `<vector>`, `<cmath>`, and `<algorithm>`.
- **C++17 or higher**: Required for `std::variant`.
