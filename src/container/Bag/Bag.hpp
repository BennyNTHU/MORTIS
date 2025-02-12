#ifndef BAG_HPP
#define BAG_HPP

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <variant>
#include <string>

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

// 例如先定義一個簡單的 MIXED_TYPE，用來示範一個 GeneralArray<T> 的 T
using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

// 接著，我們要在 Bag 中使用一個 variant，能夠容納多種型別資料結構
using MORTISInvariant = std::variant<
    int,                              // 基本型別
    char,
    float,
    bool,
    double,
    std::string,                     // 字串
    GeneralArray<MIXED_TYPE>,        // 各種已實作的陣列
    Polynomial,
    SparseMatrix,
    String
>;

// ---------------------------
// Bag Class Declaration
// ---------------------------
class Bag {
protected:
    MORTISInvariant* arr;  // Array to store elements (MORTISInvariant array)
    int top;          // Index of the last element (-1 if empty)
    int capacity;     // Current capacity of the bag

public:
    Bag(int c);       // Constructor
    ~Bag();           // Destructor

    int  Size()     const; // Return capacity
    bool IsEmpty()  const; // Return true if bag is empty
    int  Element()  const; // Return number of elements

    // Push: add an element x
    void Push(const MORTISInvariant& x);

    // Pop: remove the last element
    void Pop();

    // Template member functions for multiplicity & isBelong
    template <class U>
    int  Multiplicity(const U& x) const;

    template <class U>
    bool isBelong(const U& x) const;
};

// 變動陣列大小的函式
void ChangeSize1D(MORTISInvariant*& a, const int oldSize, const int newSize);

#endif  // BAG_HPP
