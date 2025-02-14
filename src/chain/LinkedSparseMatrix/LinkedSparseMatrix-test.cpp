// g++ -std=c++17 LinkedSparseMatrix.cpp LinkedMatrixTerm.cpp LinkedSparseMatrix-test.cpp\
    ../DLIterator/DLIterator.cpp ../DoubleNode/DoubleNode.cpp\
    ../Node/Node.cpp ../ChainIterator/ChainIterator.cpp -o test

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
    LinkedSparseMatrix C = A.Add(B);
    std::cout << "Result (C = A + B):\n" << C << "\n\n";

    // Test Transpose
    std::cout << "Test: Transposing A...\n";
    LinkedSparseMatrix AT = A.FastTranspose();
    std::cout << "Transposed A:\n" << AT << "\n\n";

    // Test Multiplication
    std::cout << "Test: Matrix Multiplication A * B...\n";
    try {
        LinkedSparseMatrix D = A.Multiply(B);
        std::cout << "Result (D = A * B):\n" << D << "\n\n";
    } catch (const std::exception& e) {
        std::cout << "Multiplication error: " << e.what() << "\n\n";
    }

    // Test Scalar Multiplication
    std::cout << "Test: Scalar Multiplication A * 2...\n";
    LinkedSparseMatrix E = A.ScalarProduct(2);
    std::cout << "Result (E = A * 2):\n" << E << "\n\n";

    // Test Input
    std::cout << "Test: Matrix Input...\n";
    std::istringstream input("3 3 3\n0 0 3.5\n1 2 -1\n2 1 4");
    LinkedSparseMatrix F(3, 3, 3);
    input >> F;
    std::cout << "Inputted Matrix F:\n" << F << "\n\n";

    std::cout << "=== All Tests Completed ===\n";

    return 0;
}
