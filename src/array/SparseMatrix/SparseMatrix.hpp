#ifndef SPARSEMATRIX
#define SPARSEMATRIX

#include <variant>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// MatrixTerm represents a nonzero element in the sparse matrix.
// It stores the row, column, and value (which can be an int or a double).
class MatrixTerm 
{
    friend class SparseMatrix;

    private:
        int row, col;                      // Row and column indices
        std::variant<int, double> value;    // The value at that position

    public:
        // Default constructor
        MatrixTerm() : row(0), col(0), value(0) {}

        // Getters for row, col, and value.
        int get_row() const {return row;}
        int get_col() const {return col;}
        std::variant<int, double> get_value() const {return value;}
        
        // write_term overwrites the current term with new row, column, and value.
        void write_term(int r, int c, const std::variant<int, double>& v) 
        {
            row = r;
            col = c;
            value = v;
        }

        // Operator overloads
        MatrixTerm* operator->() // overload pointer operator 
        { 
            return this; 
        }   
        MatrixTerm& operator*() // overload dereference operator 
        { 
            return *this; 
        }   
        bool operator==(const MatrixTerm &other) const 
        {
            return (row == other.row) && (col == other.col) && (value == other.value);
        }
        bool operator!=(const MatrixTerm &other) const 
        {
            return !(*this == other);
        }
};

// SparseMatrix class declaration.
class SparseMatrix 
{
    private:
        int rows;     // number of rows
        int cols;     // number of columns
        int terms;    // number of nonzero terms
        int capacity; // capacity of the smArray
        MatrixTerm *smArray; // dynamically allocated array of MatrixTerm
    
    public:
        // Constructors and destructor
        SparseMatrix();
        SparseMatrix(int r, int c, int t = 0);
        SparseMatrix(const SparseMatrix &b);
        ~SparseMatrix();
    
        // Accessors
        int get_rows() const;
        int get_cols() const;
        int get_terms() const;
        int get_capacity() const;
        MatrixTerm* get_smArray() const;
    
        // Other functions
        void StoreNum(const std::variant<int, double>& num, int r, int c);   // Setter: if num is nonzero, store term (r, c, num)
        void ChangeSize1D(int newSize);
        void printMatrix() const;       // Print dense matrix form (for debugging)
    
        // Matrix operation
        SparseMatrix FastTranspose();   // Fast transpose
        double Norm() const;            // Norm: returns the Frobenius norm of the matrix.
    
        // Operator overloads for arithmetic:
        SparseMatrix operator+(const SparseMatrix& b) const;
        SparseMatrix operator-(const SparseMatrix& b) const;
        SparseMatrix operator*(const SparseMatrix& b) const;
        SparseMatrix operator*(const std::vector<double>& vec) const;
        SparseMatrix operator*(std::variant<int, double> scalar) const;
    
        // Other overloads
        SparseMatrix& operator=(const SparseMatrix& other);     // Assignment operator
        bool operator==(const SparseMatrix& other) const;       // Equality 
        bool operator!=(const SparseMatrix& other) const;       // Inequality
        std::variant<int, double> operator[](int index) const;   // Subscript operator: returns the value of term i.
    
        // Friend I/O operators.
        friend std::ostream& operator<<(std::ostream& out, const SparseMatrix& mat);
        friend std::istream& operator>>(std::istream& in, SparseMatrix& mat);
    };

#endif
