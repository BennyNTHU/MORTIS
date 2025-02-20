#include "BinaryTreeNode.hpp"

// =================================
// Private methods to set threaded pointers (Used internally)
// =================================

// Threaded tree operations (internal)
template <class T>
void BinaryTreeNode<T>::setLeftThread(BinaryTreeNode<T>* in) 
{
    leftthread = in;
}

template <class T>
void BinaryTreeNode<T>::setRightThread(BinaryTreeNode<T>* in) 
{
    rightthread = in;
}

// =================================
// Constructors and Destructor
// =================================

// Default Constructor
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& e): BinaryTreeNode(e, nullptr, nullptr) {}

// Constructor with data and optional child pointers
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& e, BinaryTreeNode<T>* ptr_left, BinaryTreeNode<T>* ptr_right)
    : data(e), leftChild(ptr_left), rightChild(ptr_right), parent(nullptr), leftthread(nullptr), rightthread(nullptr)
{
    if (ptr_left) 
    {
        ptr_left->parent = this;
    }
    if (ptr_right) 
    {
        ptr_right->parent = this;
    }
}

// =================================
// Getters
// =================================

template <class T>
const T& BinaryTreeNode<T>::getData() const 
{
    return data;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild() 
{
    return rightChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild() 
{
    return leftChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightThread() const 
{
    return rightthread;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftThread() const 
{
    return leftthread;
}


template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getParent() const 
{
    return parent;
}

// =================================
// Setters (Ensure Parent-Child Consistency)
// =================================

template <class T>
void BinaryTreeNode<T>::setData(T in) 
{
    data = in;
}

template <class T>
void BinaryTreeNode<T>::setParent(BinaryTreeNode<T>* in) 
{
    parent = in;
}

template <class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* in) 
{
    if (leftChild == in)    // Avoid redundant assignment 
        return;  
    
    
    if (leftChild && leftChild->parent == this) // Detach previous left child if necessary
        leftChild->parent = nullptr;

    leftChild = in;

    if (in)
        in->parent = this;
}

template <class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* in) 
{
    if (rightChild == in)   // Avoid redundant assignment
        return;  
    
    if (rightChild && rightChild->parent == this)   // Detach previous right child if necessary
        rightChild->parent = nullptr;

    rightChild = in;

    if (in)
        in->parent = this;
}

// =================================
// Equality test
// =================================

template <class T>
bool BinaryTreeNode<T>::operator==(const BinaryTreeNode<T>& r) const 
{
    // Compare data and both left and right child pointers
    return (this->data == r.data) &&
           (this->leftChild == r.leftChild) &&
           (this->rightChild == r.rightChild);
}

template <class T>
bool BinaryTreeNode<T>::operator!=(const BinaryTreeNode<T>& r) const 
{
    return !(this->operator==(r));  // If they are not equal, return true
}

// =================================
// Explicit instantiation
// =================================

template class BinaryTreeNode<int>;
template class BinaryTreeNode<bool>;
template class BinaryTreeNode<char>;
template class BinaryTreeNode<float>;
template class BinaryTreeNode<double>;
template class BinaryTreeNode<std::string>;
