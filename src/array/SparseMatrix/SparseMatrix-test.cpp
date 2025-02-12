// SparseMatrix-test.cpp
// Comprehensive test program for the SparseMatrix data structure.
// This program tests all functions declared in SparseMatrix.h, including:
//   - Constructors (regular and copy constructor)
//   - setTerm() to set nonzero terms
//   - get_terms() to get the number of nonzero terms
//   - printMatrix() to print the full (dense) matrix form
//   - FastTranspose() to compute the transpose
//   - Add() to add two matrices
//   - Multiply() to multiply matrices
//   - ScalarProduct() to multiply the matrix by a scalar
//   - Overloaded input (>>) and output (<<) operators
//
// Compile with C++17:
//   g++ -std=c++17 SparseMatrix.cpp SparseMatrix-test.cpp -o test

#include <iostream>
#include "SparseMatrix.hpp"
using namespace std;

int main() {
    cout << "=== SparseMatrix Test Program ===" << endl;
    
    // Test 1: Constructor and setTerm()
    // Create a 4x5 sparse matrix A with 3 nonzero terms.
    SparseMatrix A(4, 5, 3);
    // Set nonzero terms using setTerm(index, row, col, value)
    A.setTerm(0, 0, 1, 5);         // Term: (0,1) = 5 (integer)
    A.setTerm(1, 2, 3, 3.14f);       // Term: (2,3) = 3.14 (float)
    A.setTerm(2, 3, 0, -2);          // Term: (3,0) = -2 (integer)
    cout << "\nMatrix A (nonzero terms):" << endl;
    cout << A << endl;
    
    // Test 2: get_terms() and dense printMatrix()
    cout << "Number of nonzero terms in A: " << A.get_terms() << endl;
    cout << "\nDense form of matrix A:" << endl;
    A.printMatrix();
    
    // Test 3: FastTranspose()
    SparseMatrix AT = A.FastTranspose();
    cout << "\nTranspose of matrix A (nonzero terms):" << endl;
    cout << AT << endl;
    cout << "Dense form of transpose A:" << endl;
    AT.printMatrix();
    
    // Test 4: Copy constructor
    SparseMatrix B = A; // Use copy constructor to create B as a copy of A.
    cout << "\nMatrix B (copy of A):" << endl;
    cout << B << endl;
    
    // Test 5: Add()
    // Create another matrix C (same dimensions) with 2 nonzero terms.
    SparseMatrix C(4, 5, 2);
    C.setTerm(0, 0, 1, 10.5f);       // Term: (0,1) = 10.5 (float)
    C.setTerm(1, 2, 3, -3);          // Term: (2,3) = -3 (integer)
    cout << "\nMatrix C:" << endl;
    cout << C << endl;
    SparseMatrix Sum = A.Add(C);
    cout << "\nA + C (nonzero terms):" << endl;
    cout << Sum << endl;
    cout << "Dense form of (A + C):" << endl;
    Sum.printMatrix();
    
    // Test 6: Multiply()
    // Create matrix D with dimensions 5x3 and 2 nonzero terms.
    SparseMatrix D(5, 3, 2);
    D.setTerm(0, 1, 0, 2);           // Term: (1,0) = 2 (integer)
    D.setTerm(1, 3, 2, 4.5f);         // Term: (3,2) = 4.5 (float)
    cout << "\nMatrix D:" << endl;
    cout << D << endl;
    // Multiply A (4x5) by D (5x3) to obtain matrix E (4x3).
    SparseMatrix E = A.Multiply(D);
    cout << "\nA * D (nonzero terms):" << endl;
    cout << E << endl;
    cout << "Dense form of (A * D):" << endl;
    E.printMatrix();
    
    // Test 7: ScalarProduct()
    // Multiply matrix A by an integer scalar 3.
    SparseMatrix F = A.ScalarProduct(3);
    cout << "\nScalar product of A with 3:" << endl;
    cout << F << endl;
    cout << "Dense form:" << endl;
    F.printMatrix();
    
    // Multiply matrix A by a float scalar 2.5.
    SparseMatrix G = A.ScalarProduct(2.5f);
    cout << "\nScalar product of A with 2.5:" << endl;
    cout << G << endl;
    cout << "Dense form:" << endl;
    G.printMatrix();
    
    // Test 8: Overloaded input operator (>>)
    // Create a 3x3 matrix H with 2 nonzero terms.
    SparseMatrix H(3, 3, 2);
    cout << "\nEnter 2 terms for matrix H in the format: row col value" << endl;
    // Example input:
    // 0 0 7
    // 1 2 3.5
    cin >> H;
    cout << "\nMatrix H (nonzero terms):" << endl;
    cout << H << endl;
    cout << "Dense form of matrix H:" << endl;
    H.printMatrix();
    
    return 0;
}
