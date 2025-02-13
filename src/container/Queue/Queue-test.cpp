// g++ -std=c++17 Queue.cpp Queue-test.cpp ../../array/GeneralArray/GeneralArray.cpp\
     ../../array/Polynomial/Polynomial.cpp ../../array/SparseMatrix/SparseMatrix.cpp\
     ../../array/String/String.cpp ../Bag/Bag.cpp -o test

#include "Queue.hpp"
#include <iostream>

int main() 
{
    std::cout << "=== Queue Test Program ===" << std::endl;

    // Create a queue with an initial capacity of 10
    Queue q(10);

    // Check if the queue is initially empty
    std::cout << "IsEmpty? " << (q.IsEmpty() ? "Yes" : "No") << std::endl;

    // Push different types into the queue
    q.Push(25);              // int
    q.Push(3.14159);         // double
    q.Push('A');             // char
    q.Push("Hello");         // std::string
    q.Push(true);            // bool

    // Print queue after enqueuing elements
    std::cout << "\nQueue after enqueuing elements:\n";
    q.PrintQueue();

    // Check front and rear elements
    std::cout << "\nFront element: ";
    std::visit([](auto&& arg) { std::cout << arg; }, q.Front());
    std::cout << "\nRear element: ";
    std::visit([](auto&& arg) { std::cout << arg; }, q.Rear());
    std::cout << std::endl;

    // Pop an element
    q.Pop();
    std::cout << "\nQueue after dequeuing an element:\n";
    q.PrintQueue();

    // Insert GeneralArray<MIXED_TYPE>
    GeneralArray<MIXED_TYPE> ga(1, {3}, MIXED_TYPE{});
    ga.Store({0}, 100);
    ga.Store({1}, std::string("Test"));
    ga.Store({2}, 'Z');
    q.Push(ga);

    // Insert Polynomial
    Polynomial poly;
    poly.NewTerm(2, 3); // 3x^2
    poly.NewTerm(0, 1); // +1
    q.Push(poly);
    
    // Insert SparseMatrix
    SparseMatrix sm(3, 3, 2);
    sm.StoreNum(0, 0, 5);
    sm.StoreNum(1, 1, -2);
    q.Push(sm);
    
    // Insert String
    char init1[] = "Yeah Tiger";
    String str(init1, 100);
    q.Push(str);

    std::cout << "\nQueue contents after inserting all types:\n";
    q.PrintQueue();

    // Check front and rear after insertions
    std::cout << "\nFront element: ";
    std::visit([](auto&& arg) { std::cout << arg; }, q.Front());
    std::cout << "\nRear element: ";
    std::visit([](auto&& arg) { std::cout << arg; }, q.Rear());
    std::cout << std::endl;

    // Pop twice
    q.Pop();
    q.Pop();
    
    std::cout << "\nQueue after dequeuing twice:\n";
    q.PrintQueue();

    std::cout << "\nTest completed successfully!\n";

    return 0;
}
