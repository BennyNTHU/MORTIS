#include <iostream>
#include <vector>
#include <utility>

#include "Set.hpp"

// =================================
// Constructors
// =================================

template <class T>
Set<T>::Set() : BinarySearchTree<T>(T()) 
{ 
    this->Clear();
}

template <class T>
Set<T>::Set(std::initializer_list<T> elements): BinarySearchTree<T>(elements.size() > 0 ? *elements.begin() : T()) 
{
    // Clear out the default root (if any) and insert all elements.
    this->Clear();

    for (const T& elem : elements) 
    {
        this->Insert(elem);
    }
}

// =================================
// Set operation
// =================================

template <class T>
Set<T> Set<T>::Union(const Set<T>& other) const 
{
    Set<T> result;  
    // Use const_cast to call non-const InorderIterator() on our BST.
    std::vector<T> thisElements = const_cast<Set<T>*>(this)->InorderIterator();
    std::vector<T> otherElements = const_cast<Set<T>*>(&other)->InorderIterator();

    for (const T& elem : thisElements) 
    {
        result.Insert(elem);
    }
    for (const T& elem : otherElements) 
    {
        result.Insert(elem);
    }

    return result;
}

template <class T>
Set<T> Set<T>::Intersection(const Set<T>& other) const 
{
    Set<T> result;
    std::vector<T> thisElements = const_cast<Set<T>*>(this)->InorderIterator();

    for (const T& elem : thisElements)
        if (other.Contains(elem))
            result.Insert(elem);

    return result;
}

template <class T>
Set<T> Set<T>::Difference(const Set<T>& other) const 
{
    Set<T> result;
    std::vector<T> thisElements = const_cast<Set<T>*>(this)->InorderIterator();

    for (const T& elem : thisElements)
        if (!other.Contains(elem))
            result.Insert(elem);
    
    return result;
}

template <class T>
bool Set<T>::IsSubsetOf(const Set<T>& other) const 
{
    std::vector<T> thisElements = const_cast<Set<T>*>(this)->InorderIterator();

    for (const T& elem : thisElements)
        if (!other.Contains(elem))
            return false;

    return true;
}

template <class T>
bool Set<T>::Contains(const T& value) const 
{
    return (this->Get(value) != nullptr);
}

// =================================
// Print the set to std::cout
// =================================

template <class T>
void Set<T>::Print() const 
{
    std::vector<T> elements = const_cast<Set<T>*>(this)->InorderIterator();
    
    std::cout << "{ ";
    for (const T& elem : elements) 
    {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}

// =================================
// Explicit template instantiation
// =================================

template class Set<int>;
template class Set<bool>;
template class Set<char>;
template class Set<float>;
template class Set<double>;
template class Set<std::string>;
