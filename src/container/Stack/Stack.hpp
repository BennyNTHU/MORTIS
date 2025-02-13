#ifndef STACK
#define STACK

#include <iostream>
#include <cstring>
#include "../Bag/Bag.hpp"

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using namespace std;

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;


class Stack : public Bag 
{
    public:
        // Constructor: Initialize the stack with a given capacity
        explicit Stack(int initial_capacity = 10);
    
        // Push an element onto the stack (overrides Bag's Push)
        void Push(const MORTISInvariant& x);
    
        // Pop an element from the stack
        void Pop();
    
        // Get the top element of the stack
        MORTISInvariant Top() const;
    
        // Print the entire stack (from top to bottom)
        void PrintStack() const;
};

#endif