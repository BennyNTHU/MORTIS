#include "BinaryTreeNode.hpp"

// Default Constructor
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& e) : BinaryTreeNode(e, nullptr, nullptr) {}

// Constructor with data and optional child pointers
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& e, BinaryTreeNode<T>* ptr_left, BinaryTreeNode<T>* ptr_right)
    : data(e), leftChild(ptr_left), rightChild(ptr_right), parent(nullptr), leftthread(nullptr), rightthread(nullptr) 
{
    if (ptr_left) ptr_left->parent = this;
    if (ptr_right) ptr_right->parent = this;
}

// Getters
template <class T>
T BinaryTreeNode<T>::getData() const 
{
    return data;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild() const 
{
    return leftChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild() const 
{
    return rightChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftThread() const 
{
    return leftthread;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightThread() const 
{
    return rightthread;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getParent() const 
{
    return parent;
}

// Setters (Ensure Consistent Parent-Child Relationships)
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
    if (leftChild == in) return; // Avoid redundant assignments

    // Detach previous left child
    if (leftChild && leftChild->parent == this) 
    {
        leftChild->parent = nullptr;
    }

    leftChild = in;
    
    // Ensure correct parent reference
    if (in) 
    {
        in->parent = this;
    }
}

template <class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* in) 
{
    if (rightChild == in) return; // Avoid redundant assignments

    // Detach previous right child
    if (rightChild && rightChild->parent == this) 
    {
        rightChild->parent = nullptr;
    }

    rightChild = in;

    // Ensure correct parent reference
    if (in) 
    {
        in->parent = this;
    }
}

// Threaded tree internal operations (Not for public use)
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

// Explicit template instantiation
template class BinaryTreeNode<int>;
template class BinaryTreeNode<char>;
template class BinaryTreeNode<float>;
template class BinaryTreeNode<bool>;
template class BinaryTreeNode<double>;
template class BinaryTreeNode<std::string>;
