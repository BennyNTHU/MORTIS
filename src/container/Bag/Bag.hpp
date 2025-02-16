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

template <typename T>
class Bag 
{
    protected:
        T* arr;  // Array to store elements (MORTISInvariant array)
        int top;               // Index of the last element (-1 if empty)
        int capacity;          // Current capacity of the bag
        int size = top + 1;    // Number of elements in the Bag

    public:
        //  Consructors and destructors
        Bag(int c);       // Constructor
        ~Bag();           // Destructor

        // Properties
        int getCapacity() const;  // Return capacity
        int getTop() const;       // Return top
        T* getArr() const;        // Return arr
        bool IsEmpty()  const;    // Return true if bag is empty
        int  Element()  const;    // Return number of elements
        template <class U> int Multiplicity(const U& x) const;  // multiplicity & isBelong
        template <class U> bool isBelong(const U& x) const;     // isBelong: Check if an element x is present in the bag

        // Manioulations
        void Push(const T& x);  // Push: add an element x
        void Pop(); // Pop: remove the last element

        // overloading operator
        template <typename U> friend std::ostream& operator<<(std::ostream& os, const Bag<U>& b);

};

// 變動陣列大小的函式
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize);

#endif
