#include <iostream>
#include "Node.hpp"

// Implementation of Constructors
template <typename T>
Node<T>::Node() : data(T()), link(nullptr) {}  // Default initialization

template <typename T>
Node<T>::Node(const T& item, Node<T>* next) : data(item), link(next) {}

// Destructor
template <typename T>
Node<T>::~Node() 
{
    // The destructor does not delete 'link' to prevent recursive deletion.
    link = nullptr;  // Prevent accidental access after deletion
}

template <typename T>
const T& Node<T>::getData() const 
{
    return data;
}

template <typename T>
Node<T>* Node<T>::getLink() const 
{
    return link;
}

// Setter Implementations
template <typename T>
void Node<T>::setData(const T& item) 
{
    data = item;
}

template <typename T>
void Node<T>::setLink(Node<T>* next) 
{
    link = next;
}

template class Node<int>;
template class Node<bool>;
template class Node<char>;
template class Node<float>;
template class Node<double>;
template class Node<std::string>;
