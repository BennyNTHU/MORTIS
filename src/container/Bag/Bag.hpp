#ifndef BAG
#define BAG

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <variant>
#include <string>
#include "../../MORTIS.hpp"  // Central header that defines MORTISInvariant
using namespace std;

// Use the common variant type.
using MORTISVariant = MORTISInvariant;

class Bag {
protected:
    MORTISVariant* arr;  // Array to store elements.
    int top;             // Index of the last element (-1 if bag is empty).
    int capacity;        // Current capacity of the bag.
    
public:
    // Constructor with initial capacity c.
    Bag(int c);
    
    // Destructor.
    ~Bag();
    
    // Returns the capacity of the bag.
    int Size() const;
    
    // Returns true if the bag is empty.
    bool IsEmpty() const;
    
    // Returns the number of elements currently in the bag.
    int Element() const;
    
    // Adds an element x to the bag.
    void Push(const MORTISVariant& x);
    
    // Removes the last element from the bag.
    void Pop();
    
    // Template member function declarations:
    // Returns the multiplicity (number of occurrences) of element x in the bag.
    template <class U>
    int Multiplicity(const U& x) const;
    
    // Returns true if element x exists in the bag.
    template <class U>
    bool isBelong(const U& x) const;
};

// Template function to change the size of an array.
// 'a' is the original array, oldSize is its current size, and newSize is the desired new size.
void ChangeSize1D(MORTISVariant*& a, const int oldSize, const int newSize);

#endif
