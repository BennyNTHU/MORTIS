// SparseMatrixTest.cpp
// Compile with (for example):
// g++ -std=c++17 SparseMatrix.cpp SparseMatrix-test.cpp -o test

#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <cmath>
#include "SparseMatrix.hpp"

using namespace std;

int main() {
    cout << "=== SparseMatrix Test Program ===" << endl << endl;
    
    // --- Test Constructors and StoreNum ---
    // Create a 4x5 matrix with initially 0 nonzero terms.
    // We set an initial capacity by passing a positive number for t.
    SparseMatrix mat(4, 5, 0);
    // Store some nonzero values:
    // (0,1) = 3, (1,3) = 4.5, (2,2) = -2, (3,4) = 10.
    mat.StoreNum(3, 0, 1);
    mat.StoreNum(4.5, 1, 3);
    mat.StoreNum(-2, 2, 2);
    mat.StoreNum(10, 3, 4);
    
    cout << "Matrix mat (dense view):" << endl;
    mat.printMatrix();
    cout << "\nMatrix mat (sparse representation):" << endl;
    cout << mat << endl;
    
    // --- Test Input Operator (operator>>) ---
    // Simulate input using a stringstream.
    string inputStr = "0 0 1\n0 2 2\n1 1 3.5\n2 3 4\n";
    istringstream iss(inputStr);
    SparseMatrix mat2(4, 5, 0);
    iss >> mat2;
    cout << "\nMatrix mat2 (constructed from input):" << endl;
    cout << mat2 << endl;
    
    // --- Test Arithmetic Operators ---
    // Addition
    SparseMatrix sum = mat + mat2;
    cout << "\nSum of mat and mat2:" << endl;
    cout << sum << endl;
    
    // Subtraction
    SparseMatrix diff = mat - mat2;
    cout << "\nDifference (mat - mat2):" << endl;
    cout << diff << endl;
    
    // Multiplication (Matrix * Matrix)
    // Create two compatible matrices.
    // Let A be a 2x3 matrix and B be a 3x2 matrix.
    SparseMatrix A(2, 3, 0);
    A.StoreNum(1, 0, 0);
    A.StoreNum(2, 0, 1);
    A.StoreNum(3, 0, 2);
    A.StoreNum(4, 1, 0);
    A.StoreNum(5, 1, 1);
    A.StoreNum(6, 1, 2);
    SparseMatrix B(3, 2, 0);
    B.StoreNum(7, 0, 0);
    B.StoreNum(8, 0, 1);
    B.StoreNum(9, 1, 0);
    B.StoreNum(10, 1, 1);
    B.StoreNum(11, 2, 0);
    B.StoreNum(12, 2, 1);
    SparseMatrix C = A * B;
    cout << "\nMatrix A:" << endl << A << endl;
    cout << "Matrix B:" << endl << B << endl;
    cout << "Product (A * B):" << endl << C << endl;
    
    // Matrix-vector multiplication
    vector<double> vec = {1.0, 2.0, 3.0};
    SparseMatrix vecResult = A * vec;
    cout << "\nResult of A * vec (as a matrix):" << endl;
    vecResult.printMatrix();
    
    // Scalar multiplication
    SparseMatrix scalarProd = A * std::variant<int, double>(2);
    cout << "\nResult of A * 2:" << endl << scalarProd << endl;
    
    // --- Test Assignment, Equality and Subscript Operators ---
    SparseMatrix D = A; // use copy constructor
    assert(D == A);
    cout << "\nAssignment operator test passed: D equals A" << endl;
    
    // Test subscript operator (access the first nonzero term of A)
    std::variant<int, double> firstTerm = A[0];
    cout << "First term of A (via subscript, printed as variant): ";
    std::visit([](auto v){ cout << v; }, firstTerm);
    cout << endl;
    
    // --- Test Norm and FastTranspose ---
    double normVal = A.Norm();
    cout << "\nFrobenius norm of A: " << normVal << endl;
    
    SparseMatrix At = A.FastTranspose();
    cout << "\nTranspose of A:" << endl;
    cout << At << endl;
    
    // --- Test Assignment and Inequality Operators ---
    SparseMatrix E;
    E = A;
    if (E == A)
        cout << "\nE equals A (assignment operator and equality operator work)." << endl;
    else
        cout << "\nError: E does not equal A." << endl;
    
    if (E != B)
        cout << "E and B are not equal (inequality operator works)." << endl;
    else
        cout << "Error: E and B are equal (unexpected)." << endl;
    
    // --- Test Input/Output Overloads with user input ---
    // Uncomment the lines below to test interactive input.
    /*
    cout << "\nEnter a sparse matrix (each term as: row col value; end with EOF):" << endl;
    SparseMatrix mat3(3, 3, 0);
    cin >> mat3;
    cout << "You entered:" << endl << mat3 << endl;
    */
    
    cout << "\n=== End of SparseMatrix Test Program ===" << endl;
    return 0;
}
