// Bag-test.cpp
// Extended Test Program for the Bag (multiset) data structure.
//
// This program tests the following functions:
//   - Constructor, IsEmpty, Element, and getCapacity
//   - Push (inserts an element and automatically resizes when full)
//   - Multiplicity: counts occurrences of an element
//   - isBelong: checks whether an element exists in the bag
//   - Pop: removes the last element
//   - Overloaded << operator to print bag contents
//   - Equality (==) and Inequality (!=) operators
//
// This test also demonstrates that a Bag can store various data types using std::variant.
// Compile with C++17:
//   g++ -std=c++17 Bag.cpp Bag-test.cpp ../../array/GeneralArray/GeneralArray.cpp\
//   ../../array/Polynomial/Polynomial.cpp ../../array/SparseMatrix/SparseMatrix.cpp\
//   ../../array/String/String.cpp -o test

#include <iostream>
#include "Bag.hpp"
#include <string>
#include <vector>

using namespace std;

int main() 
{
    cout << "=== Bag Test Program ===" << endl;
    
    // Create a Bag with an initial capacity of 5.
    Bag<MORTISInvariant> b(5);
    
    // Create a SparseMatrix for testing.
    SparseMatrix A(4, 5, 3); // Assuming SparseMatrix is properly implemented.
    
    // Polynomial
    Polynomial poly;
    poly.NewTerm(2, 3); // 3x^2

    // String
    char init1[] = "Yeah Tiger";
    String str(init1, 100);

    GeneralArray<MIXED_TYPE> arrInt(1, {5}, 0);
    arrInt = {1, 2, 3, 4, 5};

    double pi = 3.14159;

    // Test initial state.
    cout << "\nInitial bag state:" << endl;
    cout << "  IsEmpty? " << (b.IsEmpty() ? "Yes" : "No") << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity: " << b.getCapacity() << endl;
    cout << "  Bag contents: " << b << endl; // Empty bag should print correctly

    // Push various types into the bag.
    b.Push(10);                         // int
    b.Push(pi);                          // SparseMatrix
    b.Push('c');                        // char
    b.Push(pi);                         // double
    b.Push("Hello");                    // const char* (converted to std::string)
    b.Push(A);
    b.Push(poly);
    b.Push(str);
    b.Push(arrInt);

    cout << "\nAfter pushing 5 elements:" << endl;
    cout << b << endl;
    cout << "  IsEmpty? " << (b.IsEmpty() ? "Yes" : "No") << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity: " << b.getCapacity() << endl;
    
    // Test Multiplicity and isBelong.
    cout << "\nTesting Multiplicity and isBelong:" << endl;
    cout << "  Multiplicity of 10: " << b.Multiplicity(10) << endl;
    cout << "  Multiplicity of 'c': " << b.Multiplicity('c') << endl;
    cout << "  Multiplicity of \"Hello\": " << b.Multiplicity(std::string("Hello")) << endl;
    cout << "  Does 20 belong? " << (b.isBelong(20) ? "Yes" : "No") << endl;
    cout << "  Does 'c' belong? " << (b.isBelong('c') ? "Yes" : "No") << endl;
    
    // Push additional elements to force capacity doubling.
    b.Push(40);
    b.Push(50);
    b.Push(60);
    cout << "\nAfter pushing 3 additional elements:" << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity (should be doubled): " << b.getCapacity() << endl;
    cout << b << endl;

    // Test Pop: Remove one element.
    b.Pop();
    cout << "\nAfter popping one element:" << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity remains: " << b.getCapacity() << endl;
    cout << b << endl;

    // Final multiplicity check.
    cout << "\nFinal Multiplicity of 10: " << b.Multiplicity(10) << endl;

    // ------------------------------------------------------
    // Testing Equality and Inequality Operators
    // ------------------------------------------------------

    cout << "\n=== Testing Equality and Inequality ===" << endl;
    
    Bag<MORTISInvariant> b2(5);
    
    // Copy elements from b to b2
    b2.Push(10);
    b2.Push(A);
    b2.Push('c');
    b2.Push(pi);
    b2.Push("Hello");

    cout << "\nBag 1 contents: " << b << endl;
    cout << "Bag 2 contents: " << b2 << endl;
    /*
    // Test equality
    cout << "Are b and b2 equal? " << (b == b2 ? "Yes" : "No") << endl;
    cout << "Are b and b2 different? " << (b != b2 ? "Yes" : "No") << endl;

    // Modify b2 slightly
    b2.Push(100);
    cout << "\nBag 2 after pushing 100: " << b2 << endl;
    cout << "Are b and b2 still equal? " << (b == b2 ? "Yes" : "No") << endl;

    // Create an empty bag and test equality
    Bag<MORTISInvariant> emptyBag(5);
    cout << "\nEmpty Bag: " << emptyBag << endl;
    cout << "Is b equal to emptyBag? " << (b == emptyBag ? "Yes" : "No") << endl;
    */
    cout << "\n=== End of Bag Test Program ===" << endl;

    return 0;
}
