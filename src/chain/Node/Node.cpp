#include <iostream>

#include "Node.hpp"
#include "../DoublyLinkedList/DoublyLinkedList.hpp"
#include "../LinkedPolynomial/LinkedPolynomial.hpp"

// =============================================
// Constructors and destructors
// =============================================

// Implementation of Constructors
template <class T>
Node<T>::Node() : data(T()), link(nullptr) {}  // Default initialization

template <class T>
Node<T>::Node(const T& item, Node<T>* next) : data(item), link(next) {}

// Destructor
template <class T>
Node<T>::~Node() 
{
    // The destructor does not delete 'link' to prevent recursive deletion.
    link = nullptr;  // Prevent accidental access after deletion
}

// =============================================
// Getters
// =============================================

template <class T>
const T& Node<T>::getData() const 
{
    return data;
}

template <class T>
Node<T>* Node<T>::getLink() const 
{
    return link;
}

// =============================================
// Setters
// =============================================

// Setter Implementations
template <class T>
void Node<T>::setData(const T& item) 
{
    data = item;
}

template <class T>
void Node<T>::setLink(Node<T>* next) 
{
    link = next;
}

// =============================================
// Explicit instantiation
// =============================================

template class Node<int>;
template class Node<bool>;
template class Node<char>;
template class Node<float>;
template class Node<double>;
template class Node<std::string>;

template class Node<DoublyLinkedList<int>>;
template class Node<DoublyLinkedList<bool>>;
template class Node<DoublyLinkedList<char>>;
template class Node<DoublyLinkedList<float>>;
template class Node<DoublyLinkedList<double>>;
template class Node<DoublyLinkedList<std::string>>;

template class Node<LinkedTerm>;
