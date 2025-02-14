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

class LinkedSparseMatrix {
private:
    int rows, cols;  // Matrix dimensions
    int terms;       // Number of nonzero terms
    DoubleNode<LinkedMatrixTerm>* head; // Head of the linked list

public:
    // Constructors and Destructor
    LinkedSparseMatrix(int r, int c, int t=0);
    LinkedSparseMatrix(const LinkedSparseMatrix &b);
    ~LinkedSparseMatrix();

    // Store a number in the matrix
    void StoreNum(const std::variant<int, double>& num, const int r, const int c);

    // Print the matrix in dense format
    void printMatrix() const;

    // Get number of nonzero terms
    int get_terms() const;

    // Fast transpose of the matrix
    LinkedSparseMatrix FastTranspose() const;

    // Addition of two matrices
    LinkedSparseMatrix Add(const LinkedSparseMatrix& b) const;

    // Multiplication of two matrices
    LinkedSparseMatrix Multiply(const LinkedSparseMatrix& b) const;

    // Scalar multiplication
    LinkedSparseMatrix ScalarProduct(std::variant<int, double> n) const;

    // Overloaded input and output operators
    friend std::istream& operator>>(std::istream& in, LinkedSparseMatrix& b);
    friend std::ostream& operator<<(std::ostream& out, const LinkedSparseMatrix& b);
};

#endif // LINKEDSPARSEMATRIX
