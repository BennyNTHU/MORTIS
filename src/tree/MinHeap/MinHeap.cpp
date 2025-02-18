#include "MinHeap.hpp"
#include "../BinaryTreeNode/BinaryTreeNode.hpp"
#include <algorithm>
#include <stdexcept>

// Constructor: simply forward to the MaxHeap constructor.
template <class T>
MinHeap<T>::MinHeap(const T& rootData) : MaxHeap<T>(rootData) {
    // The base class constructor already initializes the heap.
}

// Destructor: cleanup is handled by the base class.
template <class T>
MinHeap<T>::~MinHeap() { }

// Heapify up: for a min-heap, if a node is less than its parent, swap them.
template <class T>
void MinHeap<T>::heapify_up(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        // If current node is less than its parent, swap.
        if (this->nodes[index]->getData() < this->nodes[parentIndex]->getData()) {
            std::swap(this->nodes[index], this->nodes[parentIndex]);
            // Rebuild tree links to keep the BinaryTree structure consistent.
            this->rebuildTreeLinks();
            index = parentIndex;
        } else {
            break;
        }
    }
}

// Heapify down: for a min-heap, if a node is greater than one of its children,
// swap it with the smallest child.
template <class T>
void MinHeap<T>::heapify_down(int index) {
    int n = this->nodes.size();
    while (true) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int smallest = index;
        if (leftIndex < n && this->nodes[leftIndex]->getData() < this->nodes[smallest]->getData())
            smallest = leftIndex;
        if (rightIndex < n && this->nodes[rightIndex]->getData() < this->nodes[smallest]->getData())
            smallest = rightIndex;
        if (smallest != index) {
            std::swap(this->nodes[index], this->nodes[smallest]);
            this->rebuildTreeLinks();
            index = smallest;
        } else {
            break;
        }
    }
}

// Explicit template instantiation (if needed)
template class MinHeap<int>;
template class MinHeap<char>;
template class MinHeap<float>;
template class MinHeap<bool>;
template class MinHeap<double>;
template class MinHeap<std::string>;
