#include <iostream>
#include <cstring>

#include "ChainIterator.hpp"
#include "../DoublyLinkedList/DoublyLinkedList.hpp"

using namespace std;

template <typename T>
ChainIterator<T>::ChainIterator(Node<T>* startNode) : current(startNode) {}

// Getters
template <typename T>
Node<T>* ChainIterator<T>::getCurrent() const 
{
    return current;
}

//Dereferencing operators
template <typename T>
const T& ChainIterator<T>::operator*() const 
{
    if (!current) 
        throw std::runtime_error("Dereferencing a null iterator");

    return current->getData(); // Ensure getData() returns const T&
}

template <typename T>
const T* ChainIterator<T>::operator->() const 
{
    if (!current) 
        throw std::runtime_error("Accessing member of a null iterator");

    return &(current->getData()); // Ensure getData() returns const T&
}

template <typename T>
ChainIterator<T>& ChainIterator<T>::operator++()    // Pre-increment
{ 
    if (current) 
        current = current->getLink();
    return *this;
}

template <typename T>
ChainIterator<T> ChainIterator<T>::operator++(int)  // Post-increment
{ 
    ChainIterator<T> temp(std::move(*this));        // Move for efficiency
    ++(*this);
    return temp;
}

// Equality test
template <typename T>
bool ChainIterator<T>::operator!=(const ChainIterator<T>& r) const 
{
    return current != r.current;
}

template <typename T>
bool ChainIterator<T>::operator==(const ChainIterator<T>& r) const 
{
    return current == r.current;
}

template class ChainIterator<int>;
template class ChainIterator<bool>;
template class ChainIterator<char>;
template class ChainIterator<float>;
template class ChainIterator<double>;
template class ChainIterator<std::string>;

template class ChainIterator<DoublyLinkedList<int>>;
template class ChainIterator<DoublyLinkedList<bool>>;
template class ChainIterator<DoublyLinkedList<char>>;
template class ChainIterator<DoublyLinkedList<float>>;
template class ChainIterator<DoublyLinkedList<double>>;
template class ChainIterator<DoublyLinkedList<std::string>>;