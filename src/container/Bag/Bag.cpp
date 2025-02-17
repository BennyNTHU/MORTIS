// Bag.cpp
#include "Bag.hpp"
#include <stdexcept>
#include <utility>   // for std::move
#include "../../tree/BinaryTreeNode/BinaryTreeNode.hpp"

template <class T>
Bag<T>::Bag(int c) 
{
    if (c < 1) throw std::runtime_error("Bag capacity must be > 0");
    arr = new T[c];
    top = -1;
    capacity = c;
}

template <class T>
Bag<T>::~Bag() 
{
    delete[] arr;
}

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
bool Bag<T>::IsEmpty() const 
{
    return (top == -1);
}

template <class T>
int Bag<T>::Element() const 
{
    return top + 1;
}

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

template <typename U, typename = void>
struct has_equality_operator : std::false_type {};

template <typename U>
struct has_equality_operator<U, std::void_t<decltype(std::declval<U>() == std::declval<U>())>> : std::true_type {};

template<class U>
bool MORTISInvariantEquals(const MORTISInvariant& var, const U& x) 
{
    if constexpr (has_equality_operator<U>::value) 
    {  
        if (std::holds_alternative<U>(var)) 
        {
            return std::get<U>(var) == x;
        }
    }

    return false;
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
            if (arr[i] == x) count++;
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

// Fix: Properly instantiate `operator<<`
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
        {
            std::visit([&os](const auto& val) { os << val << " "; }, temp[i]);
        } 
        else 
        {
            os << temp[i] << " ";
        }
    }

    return os;
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
        {
            temp[i] = T();  // Ensure default initialization
        } 
        else 
        {
            throw std::runtime_error("Cannot resize: No default constructor.");
        }
    }

    delete[] a;
    a = temp;
}

// Explicit instantiations to prevent linker errors
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

// for trees
template class Bag<BinaryTreeNode<int>*>;
template class Bag<BinaryTreeNode<char>*>;
template class Bag<BinaryTreeNode<float>*>;
template class Bag<BinaryTreeNode<bool>*>;
template class Bag<BinaryTreeNode<double>*>;
template class Bag<BinaryTreeNode<std::string>*>;