#include <stdexcept>
#include <iostream>
#include <variant>
#include <utility>   // for std::move

#include "Bag.hpp"
#include "../../tree/BinaryTreeNode/BinaryTreeNode.hpp"

// =========================================
// Constructors and destrouctors
// =========================================

// Default constructor: uses a default capacity of 10.
template <class T>
Bag<T>::Bag() : arr(new T[10]), top(-1), capacity(10) {}

template <class T>
Bag<T>::Bag(int c) 
{
    if (c < 1) throw std::runtime_error("Bag capacity must be > 0");
    arr = new T[c];
    top = -1;
    capacity = c;
}

// copy constructor
template <class T>
Bag<T>::Bag(const Bag<T>& other) 
{
    capacity = other.capacity;
    top = other.top;
    arr = new T[capacity];

    for (int i = 0; i <= top; i++) 
    {
        arr[i] = other.arr[i];
    }
}


template <class T>
Bag<T>::~Bag() 
{
    delete[] arr;
}

// =========================================
// Getters
// =========================================

template <class T>
int Bag<T>::getCapacity() const 
{
    return capacity;
}

template <class T>
int Bag<T>::getTop() const 
{
    return top;
}

template <class T>
T* Bag<T>::getArr() const 
{
    return arr;
}

template <class T>
int Bag<T>::Element() const 
{
    return top + 1;
}

// =========================================
// Properties
// =========================================

template <class T>
bool Bag<T>::IsEmpty() const 
{
    return (top == -1);
}

// Fix: Ensure `Multiplicity` and `isBelong` use proper equality checks
template <class T>
template <class U>
int Bag<T>::Multiplicity(const U& x) const 
{
    int count = 0;
    for (int i = 0; i <= top; i++)
    {
        if constexpr (std::is_same_v<T, MORTISInvariant>) 
        {
            if (MORTISInvariantEquals(arr[i], x)) 
                count++;
        } 
        else 
        {
            if (arr[i] == x) 
                count++;
        }
    }
    return count;
}

template <class T>
template <class U>
bool Bag<T>::isBelong(const U& x) const 
{
    for (int i = 0; i <= top; i++) 
    {
        if constexpr (std::is_same_v<T, MORTISInvariant>) 
        {
            if (MORTISInvariantEquals(arr[i], x)) 
                return true;
        } 
        else 
        {
            if (arr[i] == x) 
                return true;
        }
    }
    return false;
}

// =========================================
// Manioulations
// =========================================

template <class T>
void Bag<T>::Push(const T& x) 
{
    if (top == capacity - 1) 
    {
        ChangeSize1D(arr, capacity, capacity * 2);
        capacity *= 2;
    }
    arr[++top] = x;
}

template <class T>
void Bag<T>::Pop() 
{
    if (IsEmpty())
        throw std::runtime_error("Bag is empty, cannot pop.");
    top--;
}

// Unify: remove duplicates (keep one copy of each item)
template <class T>
void Bag<T>::Unify() 
{
    Bag<T> uniqueBag(capacity);

    for (int i = 0; i <= top; i++) 
    {
        bool found = false;
        // Check if the element already exists in uniqueBag
        for (int j = 0; j <= uniqueBag.top; j++) 
        {
            if (arr[i] == uniqueBag.arr[j]) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
            uniqueBag.Push(arr[i]);
    }

    *this = uniqueBag; // Use the assignment operator to copy unique items
}


// Union: returns a new Bag that is the union (non-unique items)
template <class T>
Bag<T> Bag<T>::Union(const Bag<T>& b2) 
{
    // Create a bag with capacity enough for both bags.
    Bag<T> result(this->capacity + b2.capacity);

    // Add all items from the current bag.
    for (int i = 0; i <= this->getTop(); i++)
        result.Push(this->getArr()[i]);
    
    // Add all items from b2.
    for (int i = 0; i <= b2.getTop(); i++)
        result.Push(b2.getArr()[i]);

    return result;
}

// =========================================
// overloading operator
// =========================================

// Assignment operator (deep copy)
template <class T>
Bag<T>& Bag<T>::operator=(const Bag<T>& other) 
{
    // Check for self-assignment
    if (this != &other) 
    {
        // First, delete any existing memory
        delete[] arr;

        // Perform a deep copy of the other Bag
        capacity = other.capacity;
        top = other.top;
        arr = new T[capacity];

        // Copy the elements from the other Bag
        for (int i = 0; i <= top; i++) 
            arr[i] = other.arr[i];  // T's assignment operator should be correctly defined
    }
    return *this;
}


// Equality operator: Compares *this with another Bag<T>
// It creates sorted copies of the underlying arrays and compares them.
template <class T>
bool Bag<T>::operator==(const Bag<T>& other) const 
{
    // First, check if both bags have the same number of elements.
    if (this->Element() != other.Element())
        return false;
    
    // Compare elements in order.
    for (int i = 0; i < this->Element(); i++)
        if (!(arr[i] == other.arr[i]))
            return false;
    
    return true;
}

// Inequality operator: defined as the logical negation of operator==
template <class T>
bool Bag<T>::operator!=(const Bag<T>& other) const 
{
    return !(*this == other);
}

// Overloaded output operator for Bag<T>
template <class T>
std::ostream& operator<<(std::ostream& os, const Bag<T>& b) 
{
    if (b.IsEmpty()) 
    {
        os << "The bag is empty.";
        return os;
    }
    
    os << "Bag contents: ";
    T* temp = b.getArr();

    for (int i = 0; i <= b.getTop(); i++) 
    {
        if constexpr (std::is_same_v<T, MORTISInvariant>) 
            std::visit([&os](const auto& val) { os << val << " "; }, temp[i]);
        else 
            os << temp[i] << " ";
    }

    return os;
}

// =========================================
// Other helper functions
// =========================================

template <typename U, typename = void>
struct has_equality_operator : std::false_type {};

template <typename U>
struct has_equality_operator<U, std::void_t<decltype(std::declval<U>() == std::declval<U>())>> : std::true_type {};

template<class U>
bool MORTISInvariantEquals(const MORTISInvariant& var, const U& x) 
{
    if constexpr (has_equality_operator<U>::value) 
        if (std::holds_alternative<U>(var)) 
            return std::get<U>(var) == x;

    return false;
}

// Fix: The resizing function ensures correct construction
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) 
{
    if (newSize <= 0) throw std::invalid_argument("New size must be > 0");

    T* temp = new(std::nothrow) T[newSize];
    if (!temp) 
        throw std::runtime_error("Memory allocation failed in ChangeSize1D.");

    for (int i = 0; i < oldSize && i < newSize; ++i) 
    {
        temp[i] = std::move(a[i]);
    }

    for (int i = oldSize; i < newSize; ++i) 
    {
        if constexpr (std::is_default_constructible<T>::value) 
            temp[i] = T();  // Ensure default initialization
        else 
            throw std::runtime_error("Cannot resize: No default constructor.");
    }

    delete[] a;
    a = temp;
}

// =========================================
// Explicit instantiations to prevent linker errors
// =========================================

template class Bag<int>;
template class Bag<bool>;
template class Bag<char>;
template class Bag<float>;
template class Bag<double>;
template class Bag<std::string>;
template class Bag<GeneralArray<MIXED_TYPE>>;
template class Bag<Polynomial>;
template class Bag<SparseMatrix>;
template class Bag<String>;
template class Bag<MIXED_TYPE>;
template class Bag<MORTISInvariant>;

template std::ostream& operator<<(std::ostream& os, const Bag<int>&);
template std::ostream& operator<<(std::ostream& os, const Bag<bool>&);
template std::ostream& operator<<(std::ostream& os, const Bag<char>&);
template std::ostream& operator<<(std::ostream& os, const Bag<float>&);
template std::ostream& operator<<(std::ostream& os, const Bag<double>&);
template std::ostream& operator<<(std::ostream& os, const Bag<std::string>&);
template std::ostream& operator<<(std::ostream& os, const Bag<MORTISInvariant>&);
// Note: Other types such as GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, and String DO NOT NEED explicitly instantiated!!
// Otherwise the output stream cannot found the correct operator<< for these types!!!

template int Bag<MORTISInvariant>::Multiplicity<int>(const int&) const;
template int Bag<MORTISInvariant>::Multiplicity<bool>(const bool&) const;
template int Bag<MORTISInvariant>::Multiplicity<char>(const char&) const;
template int Bag<MORTISInvariant>::Multiplicity<float>(const float&) const;
template int Bag<MORTISInvariant>::Multiplicity<double>(const double&) const;
template int Bag<MORTISInvariant>::Multiplicity<std::string>(const std::string&) const;
template int Bag<MORTISInvariant>::Multiplicity<GeneralArray<MIXED_TYPE>>(const GeneralArray<MIXED_TYPE>&) const;
template int Bag<MORTISInvariant>::Multiplicity<Polynomial>(const Polynomial&) const;
template int Bag<MORTISInvariant>::Multiplicity<SparseMatrix>(const SparseMatrix&) const;
template int Bag<MORTISInvariant>::Multiplicity<String>(const String&) const;
// template int Bag<MORTISInvariant>::Multiplicity<MIXED_TYPE>(const MIXED_TYPE&) const;
// template int Bag<MORTISInvariant>::Multiplicity<MORTISInvariant>(const MORTISInvariant&) const;

template bool Bag<MORTISInvariant>::isBelong<int>(const int&) const;
template bool Bag<MORTISInvariant>::isBelong<bool>(const bool&) const;
template bool Bag<MORTISInvariant>::isBelong<char>(const char&) const;
template bool Bag<MORTISInvariant>::isBelong<float>(const float&) const;
template bool Bag<MORTISInvariant>::isBelong<double>(const double&) const;
template bool Bag<MORTISInvariant>::isBelong<std::string>(const std::string&) const;
template bool Bag<MORTISInvariant>::isBelong<GeneralArray<MIXED_TYPE>>(const GeneralArray<MIXED_TYPE>&) const;
template bool Bag<MORTISInvariant>::isBelong<Polynomial>(const Polynomial&) const;
template bool Bag<MORTISInvariant>::isBelong<SparseMatrix>(const SparseMatrix&) const;
template bool Bag<MORTISInvariant>::isBelong<String>(const String&) const;
// template bool Bag<MORTISInvariant>::isBelong<MIXED_TYPE>(const MIXED_TYPE&) const;
// template bool Bag<MORTISInvariant>::isBelong<MORTISInvariant>(const MORTISInvariant&) const;

// for trees
template class Bag<BinaryTreeNode<int>*>;
template class Bag<BinaryTreeNode<char>*>;
template class Bag<BinaryTreeNode<float>*>;
template class Bag<BinaryTreeNode<bool>*>;
template class Bag<BinaryTreeNode<double>*>;
template class Bag<BinaryTreeNode<std::string>*>;