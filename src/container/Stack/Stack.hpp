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

template <typename T>
class Stack: public Bag<T>
{
    public:
        // Constructor
        explicit Stack(int initial_capacity = 10);  // Constructor: Initialize the stack with a given capacity
    
        // Manipulation
        void Push(const T& x);  // Push an element onto the stack (overrides Bag's Push)
        void Pop(); // Pop an element from the stack
    
        // Getters
        T Top() const;  // Get the top element of the stack
    
        // overloading operator
        template <typename U> friend std::ostream& operator<<(std::ostream& os, const Stack<U>& s);
};

#endif