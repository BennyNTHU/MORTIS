# `LinkedSparseMatrix` Documentation

## Overview

The `LinkedSparseMatrix.hpp` defines the `LinkedSparseMatrix` class to manage sparse matrices, where only non-zero terms are stored, and these terms are represented as linked nodes. The `LinkedMatrixTerm` class is used to represent each term in the matrix, containing the row index, column index, and value (either integer or double).

## Key Components

### `LinkedMatrixTerm.hpp`

#### **Constructors & Destructor**
- **`LinkedMatrixTerm()`**: Default constructor.
  
  Example:
  ```cpp
  LinkedMatrixTerm term;  // Creates an empty LinkedMatrixTerm with default values
  ```

- **`LinkedMatrixTerm(int r, int c, std::variant<int, double> v)`**: Initializes a term with a specified row, column, and value.

  Example:
  ```cpp
  LinkedMatrixTerm term(0, 0, 5);  // Creates a term with row 0, column 0, and value 5
  ```

#### **Getters & Setters**
- **`getRow()`**: Returns the row index of the term.

  Example:
  ```cpp
  int row = term.getRow();  // Get the row of the term (returns 0)
  ```

- **`getCol()`**: Returns the column index of the term.

  Example:
  ```cpp
  int col = term.getCol();  // Get the column of the term (returns 0)
  ```

- **`getValue()`**: Returns the value of the term (either `int` or `double`).

  Example:
  ```cpp
  auto value = term.getValue();  // Get the value of the term (returns 5)
  ```

- **`setRow(int r)`**: Sets the row index of the term.

  Example:
  ```cpp
  term.setRow(1);  // Set the row of the term to 1
  ```

- **`setCol(int c)`**: Sets the column index of the term.

  Example:
  ```cpp
  term.setCol(2);  // Set the column of the term to 2
  ```

- **`setValue(std::variant<int, double> v)`**: Sets the value of the term.

  Example:
  ```cpp
  term.setValue(3.5);  // Set the value of the term to 3.5
  ```

#### **Stream Operators**
- **`operator<<`**: Overload for printing the term.

  Example:
  ```cpp
  std::cout << term;  // Prints the term, e.g., (0,0): 5
  ```

- **`operator>>`**: Overload for reading the term.

  Example:
  ```cpp
  std::cin >> term;  // Reads the term from input (e.g., "1 1 2.5")
  ```

---

### `LinkedSparseMatrix.hpp`

#### **Constructors & Destructor**
- **`LinkedSparseMatrix()`**: Initializes an empty sparse matrix.

  Example:
  ```cpp
  LinkedSparseMatrix matrix;  // Creates an empty sparse matrix
  ```

- **`LinkedSparseMatrix(int r, int c, int t=0)`**: Initializes a sparse matrix with specified dimensions and optionally a number of non-zero terms.

  Example:
  ```cpp
  LinkedSparseMatrix matrix(3, 3);  // Creates a 3x3 matrix
  ```

- **`LinkedSparseMatrix(const LinkedSparseMatrix &b)`**: Copy constructor that initializes a sparse matrix by copying another matrix.

  Example:
  ```cpp
  LinkedSparseMatrix matrix2 = matrix;  // Creates a copy of the matrix
  ```

- **`~LinkedSparseMatrix()`**: Destructor that cleans up the sparse matrix.

  Example:
  ```cpp
  // Automatically cleans up the matrix when it goes out of scope
  ```

#### **Getters**
- **`get_rows()`**: Returns the number of rows in the matrix.

  Example:
  ```cpp
  int rows = matrix.get_rows();  // Get the number of rows (returns 3)
  ```

- **`get_cols()`**: Returns the number of columns in the matrix.

  Example:
  ```cpp
  int cols = matrix.get_cols();  // Get the number of columns (returns 3)
  ```

- **`get_terms()`**: Returns the number of non-zero terms in the matrix.

  Example:
  ```cpp
  int terms = matrix.get_terms();  // Get the number of non-zero terms
  ```

#### **Matrix Operations**
- **`StoreNum(const std::variant<int, double>& num, const int r, const int c)`**: Stores a value `num` at position `(r, c)` in the matrix. If the value is non-zero, it adds a new term to the matrix.

  Example:
  ```cpp
  matrix.StoreNum(5, 0, 0);  // Stores 5 at position (0, 0)
  matrix.StoreNum(3.5, 1, 2);  // Stores 3.5 at position (1, 2)
  ```

- **`printMatrix()`**: Prints the matrix in dense format (useful for debugging).

  Example:
  ```cpp
  matrix.printMatrix();  // Prints the matrix in dense format
  ```

- **`Clear()`**: Clears the matrix by removing all non-zero terms.

  Example:
  ```cpp
  matrix.Clear();  // Clears the matrix
  ```

- **`FastTranspose()`**: Returns a transposed version of the matrix using an efficient algorithm for sparse matrices.

  Example:
  ```cpp
  LinkedSparseMatrix transposed = matrix.FastTranspose();  // Get the transpose
  ```

- **`Norm()`**: Computes the Frobenius norm of the matrix, which is the square root of the sum of the squares of all non-zero terms.

  Example:
  ```cpp
  double norm = matrix.Norm();  // Get the Frobenius norm of the matrix
  ```

#### **Operator Overloads**
- **`operator+`**: Adds two sparse matrices and returns the result.

  Example:
  ```cpp
  LinkedSparseMatrix result = matrix + matrix2;  // Adds matrix to matrix2
  ```

- **`operator-`**: Subtracts one sparse matrix from another and returns the result.

  Example:
  ```cpp
  LinkedSparseMatrix result = matrix - matrix2;  // Subtract matrix2 from matrix
  ```

- **`operator*` (Matrix Multiplication)**: Multiplies two sparse matrices and returns the result.

  Example:
  ```cpp
  LinkedSparseMatrix result = matrix * matrix2;  // Matrix multiplication
  ```

- **`operator*` (Vector Multiplication)**: Multiplies the sparse matrix with a dense vector and returns the result.

  Example:
  ```cpp
  std::vector<double> vec = {1.0, 2.0, 3.0};
  LinkedSparseMatrix result = matrix * vec;  // Multiply matrix with vector
  ```

- **`operator*` (Scalar Multiplication)**: Multiplies the sparse matrix by a scalar (either integer or double).

  Example:
  ```cpp
  LinkedSparseMatrix result = matrix * 2;  // Multiply matrix by scalar 2
  ```

- **`operator=`**: Assignment operator to copy another sparse matrix.

  Example:
  ```cpp
  matrix = matrix2;  // Copy the contents of matrix2 to matrix
  ```

- **`operator==`**: Compares two sparse matrices for equality (same dimensions and non-zero terms).

  Example:
  ```cpp
  if (matrix == matrix2) {
      // Matrices are equal
  }
  ```

- **`operator!=`**: Compares two sparse matrices for inequality.

  Example:
  ```cpp
  if (matrix != matrix2) {
      // Matrices are not equal
  }
  ```

---

## Potential Errors & Edge Cases

1. **Index Out of Bounds**: Ensure that when inserting values into the matrix using `StoreNum()`, the row and column indices are within the matrix bounds.

2. **Matrix Size Mismatch in Operations**: When performing matrix operations such as multiplication or addition, make sure the matrices are compatible (e.g., the number of columns in the first matrix must equal the number of rows in the second matrix for multiplication).

3. **Empty Matrix**: Handle operations on empty matrices carefully, such as during matrix addition, multiplication, or norm calculation. Ensure the matrix has non-zero terms before performing such operations.

4. **Memory Management**: Since the matrix uses dynamic memory (via linked nodes), ensure proper management of memory, especially when copying or deleting matrices.

---

## Dependencies

- **`LinkedMatrixTerm.hpp`**: The `LinkedSparseMatrix` class relies on the `LinkedMatrixTerm` class to represent non-zero terms in the matrix. Ensure that `LinkedMatrixTerm` is correctly implemented.
- **Other Includes**: The file includes `Node.hpp`, `DoubleNode.hpp`, and iterators (`ChainIterator`, `DLIterator`), which need to be defined and implemented for proper functionality.
