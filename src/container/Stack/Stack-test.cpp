// g++ -std=c++17 Stack.cpp Stack-test.cpp\
    ../../array/GeneralArray/GeneralArray.cpp\
    ../../array/Polynomial/Polynomial.cpp\
    ../../array/SparseMatrix/SparseMatrix.cpp\
    ../../array/String/String.cpp\
    ../Bag/Bag.cpp -o test

#include "Stack.hpp"
#include <iostream>

int main() 
{
    std::cout << "=== Stack Test Program ===" << std::endl;

    // Create a stack with an initial capacity of 5
    Stack<MORTISInvariant> s(10);

    // Test if the stack is empty
    std::cout << "IsEmpty? " << (s.IsEmpty() ? "Yes" : "No") << std::endl;

    // Push different types into the stack
    s.Push(25);              // int
    s.Push(3.14159);         // double
    s.Push('A');             // char
    s.Push(std::string("Hello"));         // string
    s.Push(true);            // Polynomial

    // Print stack after pushing elements
    std::cout << "\nStack after pushing elements:\n";
    cout << s << endl;

    // Pop the top element
    s.Pop();
    std::cout << "\nStack after popping top element:\n";
    cout << s << endl;

    // Check if the stack is empty
    std::cout << "IsEmpty? " << (s.IsEmpty() ? "Yes" : "No") << std::endl;

    // 插入 GeneralArray<MIXED_TYPE>
    GeneralArray<MIXED_TYPE> ga(1, {3}, MIXED_TYPE{});
    ga.Store({0}, 100);
    ga.Store({1}, std::string("Test"));
    ga.Store({2}, 'Z');
    s.Push(ga);

    // 插入 Polynomial
    Polynomial poly;
    poly.NewTerm(2, 3); // 3x^2
    poly.NewTerm(0, 1); // +1
    s.Push(poly);
    
    // 插入 SparseMatrix
    SparseMatrix sm(3, 3, 2);
    sm.StoreNum(0, 0, 5);
    sm.StoreNum(1, 1, -2);
    s.Push(sm);
    
    // 插入 String
    String str = "Yeah Tiger";
    s.Push(str);

    std::cout << "\nStack contents after inserting all types:\n";
    cout << s << endl;

    // 測試 PopFront & PopBack
    s.Pop();
    s.Pop();
    
    std::cout << "\nStack after popping front and back:\n";
    cout << s << endl;

     // Create a stack of integers
     Stack<int> intStack(5);

     // Push elements
     intStack.Push(10);
     intStack.Push(20);
     intStack.Push(30);
 
     // Check the top element
     if (intStack.Top() == 30) 
     {
         std::cout << "Test Passed: Top() correctly returns 30.\n";
     } 
     else 
     {
         std::cout << "Test Failed: Expected 30, but got " << intStack.Top() << "\n";
     }

    std::cout << "\nTest completed successfully!\n";

    return 0;
}
