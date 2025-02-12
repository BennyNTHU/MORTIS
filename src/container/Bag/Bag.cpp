#include "Bag.hpp"
#include <algorithm>  // For std::copy, std::min, etc.
#include <stdexcept>  // For exceptions

using namespace std;

// Constructor
Bag::Bag(int c) {
    if (c < 1)
        throw runtime_error("Bag capacity must be > 0");
    arr = new MORTISInvariant[c];
    top = -1;
    capacity = c;
}

// Destructor
Bag::~Bag() {
    delete[] arr;
}

// Return capacity
int Bag::Size() const {
    return capacity;
}

// Return true if bag is empty
bool Bag::IsEmpty() const {
    return (top == -1);
}

// Return number of elements in bag
int Bag::Element() const {
    return top + 1;
}

// Push element x
void Bag::Push(const MORTISInvariant& x) {
    // If full, resize
    if (top == capacity - 1) {
        ChangeSize1D(arr, capacity, capacity * 2);
        capacity *= 2;
    }
    arr[++top] = x;
}

// Pop last element
void Bag::Pop() {
    if (IsEmpty()) {
        throw runtime_error("Bag is empty, cannot pop.");
    }
    top--;
}

// ChangeSize1D function
void ChangeSize1D(MORTISInvariant*& a, const int oldSize, const int newSize) {
    if (newSize < 0)
        throw runtime_error("New length must be >= 0");

    MORTISInvariant* temp = new MORTISInvariant[newSize];
    int number = std::min(oldSize, newSize);
    std::copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

// -------------------------------------------------------------------
// Helpers for Multiplicity / isBelong
// -------------------------------------------------------------------

// A small helper to see if arr[i] and x are the same type & value
template<typename U>
bool MORTISInvariantEquals(const MORTISInvariant& var, const U& x) {
    // 簡易判斷：若 variant 中 holds_alternative<U>()，再比較 std::get<U>() == x
    if (std::holds_alternative<U>(var)) {
        return (std::get<U>(var) == x);
    }
    return false;
}

// Template member function: Returns multiplicity of x
template <class U>
int Bag::Multiplicity(const U& x) const {
    int count = 0;
    for (int i = 0; i <= top; i++) {
        if (MORTISInvariantEquals(arr[i], x)) {
            count++;
        }
    }
    return count;
}

// Template member function: Check if x is in bag
template <class U>
bool Bag::isBelong(const U& x) const {
    for (int i = 0; i <= top; i++) {
        if (MORTISInvariantEquals(arr[i], x)) {
            return true;
        }
    }
    return false;
}

// 顯式實例化 (common types)
template int  Bag::Multiplicity<int>(const int&) const;
template bool Bag::isBelong<int>(const int&) const;

template int  Bag::Multiplicity<char>(const char&) const;
template bool Bag::isBelong<char>(const char&) const;

template int  Bag::Multiplicity<double>(const double&) const;
template bool Bag::isBelong<double>(const double&) const;

template int  Bag::Multiplicity<std::string>(const std::string&) const;
template bool Bag::isBelong<std::string>(const std::string&) const;
