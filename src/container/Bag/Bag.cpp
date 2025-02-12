#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include "Bag.hpp"

using namespace std;

// Constructor: Initialize the bag with capacity c.
Bag::Bag(int c) {
    if (c < 1)
        throw "Bag capacity must be > 0";
    arr = new MORTISInvariant[c];  // Allocate memory for c elements.
    top = -1;                   // Bag is initially empty.
    capacity = c;
}

// Destructor: Free the allocated memory.
Bag::~Bag() {
    delete[] arr;
}

// Returns the capacity of the bag.
int Bag::Size() const {
    return capacity;
}

// Returns true if the bag is empty.
bool Bag::IsEmpty() const {
    return (top == -1);
}

// Returns the number of elements in the bag.
int Bag::Element() const {
    return top + 1;
}

// Push: Adds an element x to the bag. If full, resizes the array.
void Bag::Push(const MORTISInvariant& x) {
    if (top == capacity - 1) {
        ChangeSize1D(arr, capacity, 2 * capacity);
        capacity *= 2;
    }
    arr[++top] = x;
}

// Pop: Removes the last element from the bag.
void Bag::Pop() {
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    top--;  // Remove the last element logically.
}

// ChangeSize1D: Resizes the array 'a' from oldSize to newSize.
void ChangeSize1D(MORTISInvariant*& a, const int oldSize, const int newSize) {
    if (newSize < 0)
        throw "New length must be >= 0";
    MORTISInvariant* temp = new MORTISInvariant[newSize]; // Allocate new array.
    int number = min(oldSize, newSize);               // Number of elements to copy.
    copy(a, a + number, temp);                        // Copy elements.
    delete [] a;                                      // Delete old array.
    a = temp;                                         // Update pointer.
}

// -------------------------------------------------------------------
// The following template functions are defined here and explicitly instantiated
// for common types. They use a helper function variantEquals.
// -------------------------------------------------------------------

// Helper function: Compares the variant with a value of type U.
template<typename U>
bool variantEquals(const MORTISInvariant &var, const U &x) {
    if (std::holds_alternative<U>(var))
         return std::get<U>(var) == x;
    else
         return false;
}

// Template member function: Returns the multiplicity of element x.
template <class U>
int Bag::Multiplicity(const U& x) const {
    int count = 0;
    for (int i = 0; i <= top; i++) {
        if (variantEquals(arr[i], x))
            count++;
    }
    return count;
}

// Template member function: Returns true if element x exists in the bag.
template <class U>
bool Bag::isBelong(const U& x) const {
    for (int i = 0; i <= top; i++) {
        if (variantEquals(arr[i], x))
            return true;
    }
    return false;
}

// Explicit instantiation for common types.
template int Bag::Multiplicity<int>(const int&) const;
template int Bag::Multiplicity<char>(const char&) const;
template int Bag::Multiplicity<double>(const double&) const;
template int Bag::Multiplicity<std::string>(const std::string&) const;

template bool Bag::isBelong<int>(const int&) const;
template bool Bag::isBelong<char>(const char&) const;
template bool Bag::isBelong<double>(const double&) const;
template bool Bag::isBelong<std::string>(const std::string&) const;
