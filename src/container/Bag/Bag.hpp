#ifndef BAG
#define BAG

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

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;

// ---------------------------
// Bag Class Declaration
// ---------------------------

class Bag 
{
    protected:
        MORTISInvariant* arr;  // Array to store elements (MORTISInvariant array)
        int top;               // Index of the last element (-1 if empty)
        int capacity;          // Current capacity of the bag
        int size = top + 1;    // Number of elements in the Bag

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

        // PrintBag: Print all the elements in a bag (using output streams of each elements)
        void PrintBag() const;

        // Template member functions for multiplicity & isBelong
        template <class U>
        int  Multiplicity(const U& x) const;

        // isBelong: Check if an element x is present in the bag
        template <class U>
        bool isBelong(const U& x) const;
};

// 變動陣列大小的函式
void ChangeSize1D(MORTISInvariant*& a, const int oldSize, const int newSize);

#endif
