#include "DoubleNode.hpp"

// Default Constructor
template <typename T>
DoubleNode<T>::DoubleNode() : Node<T>(), prev(nullptr) {}

// Parameterized Constructor
template <typename T>
DoubleNode<T>::DoubleNode(const T& item, DoubleNode<T>* next, DoubleNode<T>* prev): Node<T>(item, next), prev(prev) {}

// Destructor
template <typename T>
DoubleNode<T>::~DoubleNode() 
{
    prev = nullptr; // Ensure no dangling pointer
}

// Getter for previous node
template <typename T>
DoubleNode<T>* DoubleNode<T>::getPrev() const 
{
    return prev;
}

// Setter for previous node
template <typename T>
void DoubleNode<T>::setPrev(DoubleNode<T>* prev) 
{
    this->prev = prev;
}

// Explicit instantiation for common types
template class DoubleNode<int>;
template class DoubleNode<bool>;
template class DoubleNode<char>;
template class DoubleNode<float>;
template class DoubleNode<double>;
template class DoubleNode<std::string>;
