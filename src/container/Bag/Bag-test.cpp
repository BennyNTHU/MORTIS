// Bag-test.cpp
// Test program for the Bag (multiset) data structure.
// This program tests the following functions:
//   - Constructor, IsEmpty, Element, and Size
//   - Push (inserts an element and automatically resizes when full)
//   - Multiplicity: counts occurrences of an element
//   - isBelong: checks whether an element exists in the bag
//   - Pop: removes the last element
// This test also demonstrates that a Bag can store various data types using std::variant.
// Compile with C++17:
//   g++ -std=c++17 Bag.cpp Bag-test.cpp ../../MORTISInvariant.hpp -o bagTest

#include <iostream>
#include "Bag.hpp"
#include <string>
using namespace std;

int main() {
    cout << "=== Bag Test Program ===" << endl;
    
    // Create a Bag with an initial capacity of 5.
    Bag b(5);
    
    // Create a SparseMatrix for testing.
    SparseMatrix A(4, 5, 3);
    // (Assume SparseMatrix is properly implemented.)
    
    double pi = 3.14159;
    
    // Test initial state.
    cout << "Initial bag:" << endl;
    cout << "  IsEmpty? " << (b.IsEmpty() ? "Yes" : "No") << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity: " << b.Size() << endl;
    
    // Push various types into the bag.
    b.Push(10);                         // int
    b.Push(A);                          // SparseMatrix
    b.Push('c');                        // char
    b.Push(pi);                         // double
    b.Push("Hello");                    // const char* (converted to std::string)
    
    cout << "\nAfter pushing 5 elements:" << endl;
    cout << "  IsEmpty? " << (b.IsEmpty() ? "Yes" : "No") << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity: " << b.Size() << endl;
    
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
    cout << "  Capacity (should be doubled): " << b.Size() << endl;
    
    // Test Pop: Remove one element.
    b.Pop();
    cout << "\nAfter popping one element:" << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity remains: " << b.Size() << endl;
    
    // Final multiplicity check.
    cout << "\nFinal Multiplicity of 10: " << b.Multiplicity(10) << endl;
    
    return 0;
}
