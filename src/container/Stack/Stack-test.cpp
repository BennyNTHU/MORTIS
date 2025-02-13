// g++ -std=c++17 Stack.cpp Stack-test.cpp ../../array/GeneralArray/GeneralArray.cpp\
     ../../array/Polynomial/Polynomial.cpp ../../array/SparseMatrix/SparseMatrix.cpp\
     ../../array/String/String.cpp ../Bag/Bag.cpp -o test

#include "Stack.hpp"
#include <iostream>

int main() {
    std::cout << "=== Stack Test Program ===" << std::endl;

    // Create a stack with an initial capacity of 5
    Stack s(10);

    // Test if the stack is empty
    std::cout << "IsEmpty? " << (s.IsEmpty() ? "Yes" : "No") << std::endl;

    // Push different types into the stack
    s.Push(25);              // int
    s.Push(3.14159);         // double
    s.Push('A');             // char
    s.Push("Hello");         // String
    s.Push(true);            // Polynomial

    // Print stack after pushing elements
    std::cout << "\nStack after pushing elements:\n";
    s.PrintStack();

    // Check the top element
    std::cout << "\nTop element: ";
    std::visit([](auto&& arg) { std::cout << arg; }, s.Top());
    std::cout << std::endl;

    // Pop the top element
    s.Pop();
    std::cout << "\nStack after popping top element:\n";
    s.PrintStack();

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
    char init1[] = "Yeah Tiger";
    String str(init1, 100);
    s.Push(str);

    std::cout << "\nDeQue contents after inserting all types:\n";
    s.PrintStack();

    // 測試 Top
    std::cout << "\nTop element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, s.Top());

    // 測試 PopFront & PopBack
    s.Pop();
    s.Pop();
    
    std::cout << "\nDeQue after popping front and back:\n";
    s.PrintStack();

    std::cout << "\nTest completed successfully!\n";

    return 0;
}
