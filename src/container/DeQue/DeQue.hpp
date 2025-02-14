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

// 定義 DeQue 可容納的變數型別
using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;

class DeQue : public Bag 
{
    public:
        // Constructor
        DeQue(int initial_capacity = 10);
    
        // DeQue operations
        void PushFront(const MORTISInvariant& x);
        void PushBack(const MORTISInvariant& x);
        void PopFront();
        void PopBack();
        MORTISInvariant Front() const;
        MORTISInvariant Back() const;
        bool IsEmpty() const;
    
        // Print all elements
        void PrintBag() const;
    };

#endif
