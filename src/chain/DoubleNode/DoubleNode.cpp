#include "DoubleNode.hpp"
#include "../DoublyLinkedList/DoublyLinkedList.hpp"

// =============================================
// Constructors and destructors
// =============================================

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

// =============================================
// Getters and setters
// =============================================

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

// =============================================
// Explicit instantiation
// =============================================

template class DoubleNode<int>;
template class DoubleNode<bool>;
template class DoubleNode<char>;
template class DoubleNode<float>;
template class DoubleNode<double>;
template class DoubleNode<std::string>;

template class DoubleNode<DoublyLinkedList<int>>;
template class DoubleNode<DoublyLinkedList<bool>>;
template class DoubleNode<DoublyLinkedList<char>>;
template class DoubleNode<DoublyLinkedList<float>>;
template class DoubleNode<DoublyLinkedList<double>>;
template class DoubleNode<DoublyLinkedList<std::string>>;
