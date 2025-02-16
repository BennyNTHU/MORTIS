#ifndef SPARSEMATRIX
#define SPARSEMATRIX
#include <iostream>
#include <math.h>
#include <variant>
#include <algorithm>
#include <vector>
using namespace std;

// MatrixTerm represents a nonzero element in the sparse matrix.
// It stores the row, column, and value (which can be an int or a float).
class MatrixTerm 
{
    friend class SparseMatrix;

    private:
        int row, col;                      // Row and column indices
        std::variant<int, float> value;    // The value at that position

    public:
        // Default constructor
        MatrixTerm() : row(0), col(0), value(0) {}

        // Getters for row, col, and value.
        int get_row() const {return row;}
        int get_col() const {return col;}
        std::variant<int, float> get_value() const {return value;}
        
        // write_term overwrites the current term with new row, column, and value.
        void write_term(int r, int c, const std::variant<int, float>& v) 
        {
            row = r;
            col = c;
            value = v;
        }

        // Operator overloads
        MatrixTerm* operator->() { return this; }   // overload pointer operator
        MatrixTerm& operator*() { return *this; }   // overload dereference operator
};

// SparseMatrix class representing a sparse matrix.
class SparseMatrix 
{
    private:
        int rows, cols;         // Matrix dimensions
        int terms;              // Number of nonzero terms
        int capacity;           // Capacity of the internal array
        MatrixTerm *smArray;    // Array of nonzero terms

    public:
        // Constructors and destructor
        SparseMatrix() = default;               // Default constructor
        SparseMatrix(int r, int c, int t);      // Constructor: r (# rows), c (# columns), t (initial number of nonzero terms)   
        SparseMatrix(const SparseMatrix &b);    // Copy constructor
        ~SparseMatrix();    // Destructor

        // Setters
        void StoreNum(const std::variant<int, float>& num, const int r, const int c);   // If sum is nonzero, add a new term at (r, c) with value sum.
        void setTerm(int index, int r, int c, const std::variant<int, float>& v);       // Public accessor to set the term at the given index
        
        // Getters
        int get_terms() const;  // get_terms: Returns the number of nonzero terms.
        int get_rows() const;
        int get_cols() const;
        int get_capacity() const;
        MatrixTerm* get_smArray() const;
        
        // Other functions
        
        void ChangeSize1D(const int newSize);   // Change the size of the internal term array.
        void printMatrix() const;               // Print the matrix in dense form.
    
        // Oprerations
        SparseMatrix FastTranspose();                           // Returns the transpose of the matrix.
        SparseMatrix Add(SparseMatrix b);                       // Returns the sum of this matrix and matrix b.
        SparseMatrix Multiply(SparseMatrix b);                  // Returns the product of this matrix and matrix b.
        SparseMatrix Multiply(SparseMatrix b, int n);           // (overloaded) Returns this matrix raised to the power n (placeholder).
        SparseMatrix ScalarProduct(std::variant<int, float> n); // Returns a new matrix that is the current matrix multiplied by scalar n.

        // Operand overloading
        friend istream& operator>>(istream& in, const SparseMatrix& b);         // Reads the matrix terms in (row col value) format.
        friend ostream& operator<<(ostream& out, const SparseMatrix& b);        // Prints the matrix terms in (row, col, value) format.
        friend bool operator==(const SparseMatrix& a, const SparseMatrix& b);   // Compares two sparse matrices for equality.
};

istream& operator>>(istream& in, const SparseMatrix& b);
ostream& operator<<(ostream& out, const SparseMatrix& b);

#endif
