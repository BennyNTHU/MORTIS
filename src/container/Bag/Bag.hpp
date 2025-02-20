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

template <class T>
class Bag 
{
    protected:
        T* arr;                // Array to store elements (MORTISInvariant array)
        int top;               // Index of the last element (-1 if empty)
        int capacity;          // Current capacity of the bag
        int size = top + 1;    // Number of elements in the Bag

    public:
        //  Consructors and destructors
        Bag();                    // Default constructor
        Bag(int c);               // Constructor
        Bag(const Bag<T>& other); // copy constructor
        ~Bag();                   // Destructor

        // Getters
        int getCapacity() const;  // Return capacity
        int getTop() const;       // Return top
        T* getArr() const;        // Return arr
        int  Element()  const;    // Return number of elements

        // Properties
        bool IsEmpty()  const;                                  // Return true if bag is empty
        template <class U> int Multiplicity(const U& x) const;  // multiplicity
        template <class U> bool isBelong(const U& x) const;     // isBelong: Check if an element x is present in the bag
        
        // Manioulations
        void Push(const T& x);           // Push: add an element x
        void Pop();                      // Pop: remove the last element
        void Unify();                    // cancel out all the multiple items
        Bag<T> Union(const Bag<T>& b2);  // return the a Bag contains all the element and in Bag 1 and Bag 2

        // overloading operator
        Bag<T>& operator=(const Bag<T>& other);       // overload assignment
        bool operator==(const Bag<T>& other) const;   // equality test, we "CARE" about order
        bool operator!=(const Bag<T>& other) const;   // inequality test
        template <typename U> friend std::ostream& operator<<(std::ostream& os, const Bag<U>& b);
};

// Other helper functions
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize);

#endif
