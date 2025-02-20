#ifndef LINKEDSPARSEMATRIX
#define LINKEDSPARSEMATRIX

#include "LinkedMatrixTerm.hpp"
#include "../Node/Node.hpp"
#include "../Node/Node.cpp"
#include "../DoubleNode/DoubleNode.hpp"
#include "../DoubleNode/DoubleNode.cpp"
#include "../ChainIterator/ChainIterator.hpp"
#include "../ChainIterator/ChainIterator.cpp"
#include "../DLIterator/DLIterator.hpp"
#include "../DLIterator/DLIterator.cpp"

class LinkedSparseMatrix 
{
    private:
        int rows, cols;                     // Matrix dimensions
        int terms;                          // Number of nonzero terms
        DoubleNode<LinkedMatrixTerm>* head; // Head of the linked list

    public:
        // Constructors and Destructor
        LinkedSparseMatrix();
        LinkedSparseMatrix(int r, int c, int t=0);
        LinkedSparseMatrix(const LinkedSparseMatrix &b);
        ~LinkedSparseMatrix();
        
        // Getters
        int get_rows() const;
        int get_cols() const;
        int get_terms() const;      // Get number of nonzero terms

        // Other functions
        void StoreNum(const std::variant<int, double>& num, const int r, const int c);  // Store a number in the matrix    
        void printMatrix() const;   // Print the matrix in dense format
        void Clear();

        // Matrix operation
        LinkedSparseMatrix FastTranspose() const;   // Fast transpose of the matrix
        double Norm() const;                        // Norm: returns the Frobenius norm of the matrix.

        // Operator overloads for arithmetic:
        LinkedSparseMatrix operator+(const LinkedSparseMatrix& b) const;
        LinkedSparseMatrix operator-(const LinkedSparseMatrix& b) const;
        LinkedSparseMatrix operator*(const LinkedSparseMatrix& b) const;
        LinkedSparseMatrix operator*(const std::vector<double>& vec) const;
        LinkedSparseMatrix operator*(std::variant<int, double> scalar) const;

        // Other overloads
        LinkedSparseMatrix& operator=(const LinkedSparseMatrix& other); // Assignment operator
        bool operator==(const LinkedSparseMatrix& other) const;         // Equality 
        bool operator!=(const LinkedSparseMatrix& other) const;         // Inequality
        std::variant<int, double> operator[](int index) const;          // Subscript operator: returns the value of term i.

        // Overloaded input and output operators
        friend std::istream& operator>>(std::istream& in, LinkedSparseMatrix& b);
        friend std::ostream& operator<<(std::ostream& out, const LinkedSparseMatrix& b);
};

#endif // LINKEDSPARSEMATRIX
