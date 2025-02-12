#ifndef SPARSEMATRIX
#define SPARSEMATRIX
#include <iostream>
#include <math.h>
#include <variant>
#include <algorithm>
#include <vector>
using namespace std;

// Forward declaration of SparseMatrix
class SparseMatrix;

// MatrixTerm represents a nonzero element in the sparse matrix.
// It stores the row, column, and value (which can be an int or a float).
class MatrixTerm {
    friend class SparseMatrix;
private:
    int row, col;                      // Row and column indices
    std::variant<int, float> value;    // The value at that position
public:
    // Getters for row, col, and value.
    int get_row() const { return row; }
    int get_col() const { return col; }
    std::variant<int, float> get_value() const { return value; }
    
    // write_term overwrites the current term with new row, column, and value.
    void write_term(int r, int c, const std::variant<int, float>& v) {
        row = r;
        col = c;
        value = v;
    }
};

// SparseMatrix class representing a sparse matrix.
class SparseMatrix {
private:
    int rows, cols;    // Matrix dimensions
    int terms;         // Number of nonzero terms
    int capacity;      // Capacity of the internal array
    MatrixTerm *smArray; // Array of nonzero terms
public:
    // Constructor: r (# rows), c (# columns), t (initial number of nonzero terms)
    SparseMatrix(int r, int c, int t);
    
    // Copy constructor
    SparseMatrix(const SparseMatrix &b);
    
    // Destructor
    ~SparseMatrix();
    
    // StoreSum: If sum is nonzero, add a new term at (r, c) with value sum.
    void StoreNum(const std::variant<int, float>& num, const int r, const int c);
    
    // ChangeSize1D: Change the size of the internal term array.
    void ChangeSize1D(const int newSize);
    
    // printMatrix: (Optional) Print the matrix in dense form.
    void printMatrix() const;
    
    // get_terms: Returns the number of nonzero terms.
    int get_terms() const;
    
    // FastTranspose: Returns the transpose of the matrix.
    SparseMatrix FastTranspose();
    
    // Add: Returns the sum of this matrix and matrix b.
    SparseMatrix Add(SparseMatrix b);
    
    // Multiply: Returns the product of this matrix and matrix b.
    SparseMatrix Multiply(SparseMatrix b);
    
    // Multiply (overloaded): Returns this matrix raised to the power n (placeholder).
    SparseMatrix Multiply(SparseMatrix b, int n);

    // ScalarProduct: Returns a new matrix that is the current matrix multiplied by scalar n.
    SparseMatrix ScalarProduct(std::variant<int, float> n);
    
    // setTerm: Public accessor to set the term at the given index.
    // This method allows test code to set matrix terms without directly accessing the private array.
    void setTerm(int index, int r, int c, const std::variant<int, float>& v);
    
    // Overloaded input operator: Reads the matrix terms in (row col value) format.
    friend istream& operator>>(istream& in, const SparseMatrix& b);
    
    // Overloaded output operator: Prints the matrix terms in (row, col, value) format.
    friend ostream& operator<<(ostream& out, const SparseMatrix& b);
};

istream& operator>>(istream& in, const SparseMatrix& b);
ostream& operator<<(ostream& out, const SparseMatrix& b);

#endif
