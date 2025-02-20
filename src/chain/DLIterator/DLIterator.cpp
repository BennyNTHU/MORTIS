#include <iostream>
#include <stdexcept>

#include "DLIterator.hpp"
#include "../DoublyLinkedList/DoublyLinkedList.hpp"
#include "../LinkedPolynomial/LinkedPolynomial.hpp"

// =============================================
// Constructors
// =============================================

// Constructor
template <class T>
DLIterator<T>::DLIterator(DoubleNode<T>* startNode) : ChainIterator<T>(startNode) {}

// =============================================
// Move operators
// =============================================

// Pre-increment: Move to the next node
template <class T>
DLIterator<T>& DLIterator<T>::operator++() 
{
    if (this->current) 
        this->current = static_cast<DoubleNode<T>*>(this->current)->getLink();
    
    return *this;
}

// Post-increment: Move to the next node, return old state
template <class T>
ChainIterator<T> DLIterator<T>::operator++(int) 
{
    DLIterator<T> temp = *this;
    if (current) current = current->getLink();
    return temp;
}

// Pre-decrement: Move to the previous node
template <class T>
DLIterator<T>& DLIterator<T>::operator--() 
{
    if (this->current) 
        this->current = static_cast<DoubleNode<T>*>(this->current)->getPrev();
    
    return *this;
}

// Post-decrement: Move to the previous node, return old state
template <class T>
DLIterator<T> DLIterator<T>::operator--(int) 
{
    DLIterator<T> temp(*this);
    --(*this);
    return temp;
}

// =============================================
// Get current node
// =============================================

// Get current node
template <class T>
DoubleNode<T>* DLIterator<T>::getCurrent() const 
{
    return static_cast<DoubleNode<T>*>(this->current);
}

// =============================================
// Explicit instantiation
// =============================================

template class DLIterator<int>;
template class DLIterator<bool>;
template class DLIterator<char>;
template class DLIterator<float>;
template class DLIterator<double>;
template class DLIterator<std::string>;

template class DLIterator<DoublyLinkedList<int>>;
template class DLIterator<DoublyLinkedList<bool>>;
template class DLIterator<DoublyLinkedList<char>>;
template class DLIterator<DoublyLinkedList<float>>;
template class DLIterator<DoublyLinkedList<double>>;
template class DLIterator<DoublyLinkedList<std::string>>;

template class DLIterator<LinkedTerm>;
