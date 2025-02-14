#include "Bag.hpp"
#include <iostream>
#include <algorithm>  // For std::copy, std::min, etc.
#include <stdexcept>  // For exceptions

using namespace std;

// Constructor
Bag::Bag(int c) 
{
    if (c < 1)
        throw runtime_error("Bag capacity must be > 0");
    arr = new MORTISInvariant[c];
    top = -1;
    capacity = c;
}

// Destructor
Bag::~Bag() 
{
    delete[] arr;
}

// Return capacity
int Bag::Size() const 
{
    return capacity;
}

// Return true if bag is empty
bool Bag::IsEmpty() const 
{
    return (top == -1);
}

// Return number of elements in bag
int Bag::Element() const 
{
    return top + 1;
}

// Push element x
void Bag::Push(const MORTISInvariant& x) 
{
    // If full, resize
    if (top == capacity - 1) 
    {
        ChangeSize1D(arr, capacity, capacity * 2);
        capacity *= 2;
    }
    arr[++top] = x;
}

// Pop last element
void Bag::Pop() 
{
    if (IsEmpty()) 
    {
        throw runtime_error("Bag is empty, cannot pop.");
    }
    top--;
}

void ChangeSize1D(MORTISInvariant*& a, const int oldSize, const int newSize) {
    if (newSize <= 0) {
        throw std::invalid_argument("New size must be positive.");
    }

    MORTISInvariant* temp = new(std::nothrow) MORTISInvariant[newSize];
    if (!temp) {
        throw std::runtime_error("Memory allocation failed in ChangeSize1D.");
    }

    for (int i = 0; i < oldSize && i < newSize; ++i) {
        temp[i] = std::move(a[i]);  // 使用 `std::move()` 提高效能
    }

    delete[] a;  // 釋放舊記憶體
    a = temp;    // 更新指標
}

// -------------------------------------------------------------------
// Helpers for Multiplicity / isBelong
// -------------------------------------------------------------------

// A small helper to see if arr[i] and x are the same type & value
template<typename U>
bool MORTISInvariantEquals(const MORTISInvariant& var, const U& x) 
{
    // 簡易判斷：若 variant 中 holds_alternative<U>()，再比較 std::get<U>() == x
    if (std::holds_alternative<U>(var)) 
    {
        return (std::get<U>(var) == x);
    }
    return false;
}

// Template member function: Returns multiplicity of x
template <class U>
int Bag::Multiplicity(const U& x) const 
{
    int count = 0;

    for (int i = 0; i <= top; i++)
        if (MORTISInvariantEquals(arr[i], x))
            count++;

    return count;
}

// Template member function: Check if x is in bag
template <class U>
bool Bag::isBelong(const U& x) const 
{
    for (int i = 0; i <= top; i++)
        if (MORTISInvariantEquals(arr[i], x))
            return true;
            
    return false;
}

// Function to print all elements in the Bag
void Bag::PrintBag() const 
{
    // 使用 std::visit 來處理 std::variant，確保無論元素的類型為何，都能正確地輸出。
    // std::visit 會將 arr[i] 的內容傳遞給 lambda 表達式，並根據變數的型別自動選擇對應的 operator<< 來輸出。
    if (IsEmpty()) 
    {
        cout << "The bag is empty." << endl;
        return;
    }

    for (int i = 0; i <= top; i++) 
    {
        std::visit([](auto&& arg) {
            cout << arg << endl;
        }, arr[i]);
    }
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
