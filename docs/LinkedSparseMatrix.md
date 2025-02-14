# Linked Sparse Matrix Documentation

## Introduction
The **LinkedSparseMatrix** class is designed for efficient storage and manipulation of sparse matrices using linked structures. It supports matrix operations such as addition, multiplication, scalar multiplication, and transposition. Each nonzero element in the matrix is represented using the **LinkedMatrixTerm** class.

## Prerequisites
To use the **LinkedSparseMatrix** class, ensure that the following header files are included:

```cpp
#include "LinkedSparseMatrix.hpp"
#include "LinkedMatrixTerm.hpp"
```

## Class: `LinkedMatrixTerm`

### Description
This class represents a nonzero element in the sparse matrix, storing its row, column, and value (which can be an `int` or `double`).

### Public Methods

#### **Constructor**
```cpp
LinkedMatrixTerm(int r, int c, std::variant<int, double> v);
```
- Creates a term with row `r`, column `c`, and value `v`.

#### **Accessors**
```cpp
int getRow() const;
int getCol() const;
std::variant<int, double> getValue() const;
```
- Retrieve the row index, column index, and stored value of the matrix term.

#### **Mutators**
```cpp
void setRow(int r);
void setCol(int c);
void setValue(std::variant<int, double> v);
```
- Modify the row index, column index, or value of the matrix term.

#### **Operator Overloading**
```cpp
friend std::ostream& operator<<(std::ostream& out, const LinkedMatrixTerm& term);
friend std::istream& operator>>(std::istream& in, LinkedMatrixTerm& term);
```
- Overloaded operators for input/output of matrix terms.

### Example Usage
```cpp
LinkedMatrixTerm term(1, 2, 5.5);
std::cout << term;  // Output: (1, 2, 5.5)
```

---

## Class: `LinkedSparseMatrix`

### Description
This class represents a sparse matrix stored using a doubly linked list of `LinkedMatrixTerm` objects.

### Public Methods

#### **Constructor**
```cpp
LinkedSparseMatrix(int r, int c);
```
- Creates an empty matrix with `r` rows and `c` columns.

#### **Copy Constructor**
```cpp
LinkedSparseMatrix(const LinkedSparseMatrix &b);
```
- Creates a deep copy of another sparse matrix.

#### **Destructor**
```cpp
~LinkedSparseMatrix();
```
- Frees allocated memory.

#### **Matrix Operations**
```cpp
void StoreNum(const std::variant<int, double>& num, const int r, const int c);
```
- Inserts a nonzero value at position `(r, c)`.

```cpp
LinkedSparseMatrix Add(const LinkedSparseMatrix& b) const;
```
- Adds two matrices and returns the result.

```cpp
LinkedSparseMatrix Multiply(const LinkedSparseMatrix& b) const;
```
- Multiplies two matrices and returns the result.

```cpp
LinkedSparseMatrix ScalarProduct(std::variant<int, double> n) const;
```
- Multiplies each element by a scalar `n`.

```cpp
LinkedSparseMatrix FastTranspose() const;
```
- Returns the transposed matrix.

#### **Utility Functions**
```cpp
int get_terms() const;
```
- Returns the number of nonzero terms.

```cpp
void printMatrix() const;
```
- Prints the matrix in a readable format.

#### **Operator Overloading**
```cpp
friend std::istream& operator>>(std::istream& in, LinkedSparseMatrix& b);
friend std::ostream& operator<<(std::ostream& out, const LinkedSparseMatrix& b);
```
- Supports reading/writing matrices.

### Example Usage
#### **Creating and Displaying a Sparse Matrix**
```cpp
LinkedSparseMatrix mat(3, 3);
mat.StoreNum(5, 0, 0);
mat.StoreNum(10, 1, 1);
mat.StoreNum(15, 2, 2);
std::cout << mat;
```
**Output:**
```
(0, 0, 5)
(1, 1, 10)
(2, 2, 15)
```

#### **Adding Two Sparse Matrices**
```cpp
LinkedSparseMatrix A(3, 3);
LinkedSparseMatrix B(3, 3);
A.StoreNum(3, 0, 0);
B.StoreNum(2, 0, 0);
LinkedSparseMatrix C = A.Add(B);
std::cout << C;
```
**Output:**
```
(0, 0, 5)
```

#### **Multiplying Matrices**
```cpp
LinkedSparseMatrix A(2, 3);
A.StoreNum(1, 0, 1);
A.StoreNum(2, 1, 2);

LinkedSparseMatrix B(3, 2);
B.StoreNum(3, 1, 0);
B.StoreNum(4, 2, 1);

LinkedSparseMatrix C = A.Multiply(B);
std::cout << C;
```

#### **Transposing a Matrix**
```cpp
LinkedSparseMatrix A(3, 2);
A.StoreNum(7, 0, 1);
A.StoreNum(8, 1, 0);
A.StoreNum(9, 2, 1);

LinkedSparseMatrix AT = A.FastTranspose();
std::cout << AT;
```

#### **Scalar Multiplication**
```cpp
LinkedSparseMatrix A(2, 2);
A.StoreNum(5, 0, 0);
A.StoreNum(10, 1, 1);

LinkedSparseMatrix B = A.ScalarProduct(2);
std::cout << B;
```
**Output:**
```
(0, 0, 10)
(1, 1, 20)
```

---

## Conclusion
The **LinkedSparseMatrix** class provides an efficient way to manipulate sparse matrices using linked data structures. It supports key operations like addition, multiplication, transposition, and scalar multiplication, making it a powerful tool for handling large sparse datasets in computational applications.

