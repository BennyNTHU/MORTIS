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

using MORTISInvariant = std::variant<
    int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String
>;

class DeQue : public Bag {
public:
    DeQue(int capacity) : Bag(capacity) {}  // Constructor
    ~DeQue();

    void PushFront(const MORTISInvariant& x);   // Insert at front
    void PopFront();    // Remove from front
    MORTISInvariant Front() const;  // Get front element

    void PushBack(const MORTISInvariant& x);    // Insert at back (same as Bag::Push)
    void PopBack(); // Remove from back (same as Bag::Pop)
    MORTISInvariant Back() const;   // Get BACK element
};

#endif
