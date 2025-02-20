// g++ -std=c++17 LinkedSparseMatrix.cpp LinkedSparseMatrix-test.cpp\
    LinkedMatrixTerm.cpp\
    ../Node/Node.cpp\
    ../DoubleNode/DoubleNode.cpp\
    ../ChainIterator/ChainIterator.cpp\
    ../DLIterator/DLIterator.cpp\
    ../DoublyLinkedList/DoublyLinkedList.cpp -o test

#include <iostream>
#include <sstream>
#include "LinkedSparseMatrix.hpp"

int main() 
{
    std::cout << "=== LinkedSparseMatrix Unit Tests ===\n\n";

    // Test Matrix Construction & Basic Properties
    std::cout << "Test: Constructing matrices...\n";
    LinkedSparseMatrix A(3, 3, 0);
    LinkedSparseMatrix B(3, 3, 0);
    std::cout << "A and B constructed successfully.\n\n";
    std::cout << "Test: print matrix A...\n";
    A.printMatrix();
    std::cout << std::endl;

    // Test StoreNum
    std::cout << "Test: Inserting elements...\n";
    A.StoreNum(5, 0, 1);
    A.StoreNum(8.2, 1, 2);
    A.StoreNum(-3, 2, 0);
    
    B.StoreNum(4, 0, 1);
    B.StoreNum(2.3, 1, 2);
    B.StoreNum(7, 2, 2);
    
    std::cout << "A:\n" << A << "\n";
    std::cout << "B:\n" << B << "\n\n";

    // Test Addition
    std::cout << "Test: Matrix Addition A + B...\n";
    LinkedSparseMatrix C = A + B;  // using the overloaded operator
    std::cout << "Result (C = A + B):\n" << C << "\n\n";

    // Test Matrix Subtraction
    std::cout << "Test: Matrix Subtraction A - B...\n";
    LinkedSparseMatrix F = A - B;  // using the overloaded operator
    std::cout << "Result (F = A - B):\n" << F << "\n\n";

    // Test Matrix-Vector Multiplication
    std::cout << "Test: Matrix-Vector Multiplication A * vec...\n";
    std::vector<double> vec = {1, 2, 3};
    try 
    {
        LinkedSparseMatrix result = A * vec;  // using the overloaded operator
        std::cout << "Result of A * vec:\n" << result << "\n\n";
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Matrix-Vector Multiplication error: " << e.what() << "\n\n";
    }

    // Test Scalar Multiplication
    std::cout << "Test: Scalar Multiplication A * 2...\n";
    LinkedSparseMatrix E = A * 2;  // using the overloaded operator
    std::cout << "Result (E = A * 2):\n" << E << "\n\n";

    // Test Input
    std::cout << "Test: Matrix Input...\n";
    std::istringstream input("3 3 3\n0 0 3.5\n1 2 -1\n2 1 4");
    LinkedSparseMatrix G(3, 3, 3);
    input >> G;
    std::cout << "Inputted Matrix G:\n" << G << "\n\n";

    // Test Equality and Inequality
    std::cout << "Test: Equality and Inequality...\n";
    bool areEqual = (A == B); // testing equality operator
    bool areNotEqual = (A != B); // testing inequality operator
    std::cout << "A == B: " << areEqual << "\n";
    std::cout << "A != B: " << areNotEqual << "\n\n";

    // Test Norm
    std::cout << "Test: Norm of A...\n";
    double norm = A.Norm();  // testing Norm function
    std::cout << "Frobenius Norm of A: " << norm << "\n\n";

    std::cout << "=== All Tests Completed ===\n";

    return 0;
}

