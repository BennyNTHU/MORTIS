#include "MinHeap.hpp"
#include "../BinaryTreeNode/BinaryTreeNode.hpp"
#include <algorithm>
#include <stdexcept>

// =================================
// Override heapify methods
// =================================

// Heapify up: for a min-heap, if a node is less than its parent, swap them.
template <class T>
void MinHeap<T>::heapify_up(int index) 
{
    while (index > 0) 
    {
        int parentIndex = (index - 1) / 2;
       
        if (this->nodes[index]->getData() < this->nodes[parentIndex]->getData()) 
        {
            std::swap(this->nodes[index], this->nodes[parentIndex]);     // If current node is less than its parent, swap.
            this->rebuildTreeLinks();   // Rebuild tree links to keep the BinaryTree structure consistent.
            index = parentIndex;
        } 
        else 
        {
            break;
        }
    }
}

// Heapify down: for a min-heap, if a node is greater than one of its children,
// swap it with the smallest child.
template <class T>
void MinHeap<T>::heapify_down(int index) 
{
    int n = this->nodes.size();

    while (true) 
    {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int smallest = index;

        if (leftIndex < n && this->nodes[leftIndex]->getData() < this->nodes[smallest]->getData())
            smallest = leftIndex;
        if (rightIndex < n && this->nodes[rightIndex]->getData() < this->nodes[smallest]->getData())
            smallest = rightIndex;
        if (smallest != index) 
        {
            std::swap(this->nodes[index], this->nodes[smallest]);
            this->rebuildTreeLinks();
            index = smallest;
        } 
        else 
        {
            break;
        }
    }
}

// =================================
// Constructor and destructor
// =================================

// Constructor: simply forward to the MaxHeap constructor.
template <class T>
MinHeap<T>::MinHeap(const T& rootData) : MaxHeap<T>(rootData) {}

// Destructor: cleanup is handled by the base class.
template <class T>
MinHeap<T>::~MinHeap() { }

// =================================
// Explicit template instantiation
// =================================

template class MinHeap<int>;
template class MinHeap<char>;
template class MinHeap<float>;
template class MinHeap<bool>;
template class MinHeap<double>;
template class MinHeap<std::string>;
