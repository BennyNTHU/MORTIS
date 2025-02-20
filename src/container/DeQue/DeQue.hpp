#ifndef DEQUE
#define DEQUE

#include <iostream>
#include <variant>
#include <string>
#include "../Bag/Bag.hpp"

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;

template <typename T>
class DeQue : public Bag<T>
{
    private:
        int front; // Tracks the front of the queue
        int rear;  // Tracks the rear of the queue
        int size;

    public:
        // Constructor and Destructor
        DeQue(int initial_capacity = 10);
        ~DeQue();   // Destructor
    
        // DeQue operations
        void PushFront(const T& x);
        void PushBack(const T& x);
        void PopFront();
        void PopBack();

        // Getters
        int getFront() const;   // Getters for front index
        int getRear() const;    // Getters for rear index
        T Front() const;
        T Back() const;

        // Properties
        bool IsEmpty() const;
    
        // Overloading operator
        template <typename U> friend std::ostream& operator<<(std::ostream& os, const DeQue<U>& s); // Prints the DeQue elements in a readable format
};

#endif
