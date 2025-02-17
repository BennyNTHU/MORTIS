#include <vector>
#include <stdexcept>
#include <algorithm>
#include <queue>  // Required for LevelOrderIterator

#include "MaxHeap.hpp"
#include "../BinaryTreeNode/BinaryTreeNode.hpp"

// ============================================
// Constructor and Destructor
// ============================================

// Constructor and Destructor
template <class T>
MaxHeap<T>::MaxHeap(const T& rootData) : BinaryTree<T>(rootData) {
    nodes.push_back(this->getRoot());
}

template <class T>
MaxHeap<T>::~MaxHeap() {
    // Destructor: Cleanup will be handled by BinaryTree destructor
}

// ============================================
// Push and Pop
// ============================================

template <class T>
void MaxHeap<T>::Push(const T& value) {
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);

    if (this->IsEmpty()) {
        // If the heap is empty, the new node becomes the root
        this->set_root(newNode);
    } else {
        // Otherwise, insert the new node as a child of the next available parent
        BinaryTreeNode<T>* parentNode = FindNextAvailableParent();
        if (parentNode->getLeftChild() == nullptr) {
            parentNode->setLeftChild(newNode);
        } else {
            parentNode->setRightChild(newNode);
        }
        newNode->setParent(parentNode); // Set parent for the new node
    }

    nodes.push_back(newNode);
    heapify_up(nodes.size() - 1);  // Bubble up to restore the heap property
}

// Pop function
template <class T>
void MaxHeap<T>::Pop() {
    if (this->IsEmpty()) {
        std::cout << "Heap is empty!" << std::endl;
        return;  // Nothing to pop if the heap is empty
    }

    // Get the current root node
    BinaryTreeNode<T>* rootNode = this->getRoot();

    // If there is only one element, set the heap to empty
    if (this->CountNodes() == 1) {
        this->set_root(nullptr);  // The heap is empty after the pop
        delete rootNode;  // Clean up the last node
        return;
    }

    // Get the last node (the last element in the heap vector)
    BinaryTreeNode<T>* lastNode = nodes.back();

    // Set the root to the last node
    this->set_root(lastNode);

    // Remove the last node from the heap vector
    nodes.pop_back();

    // Restore the heap property by calling heapify_down starting from the root (index 0)
    heapify_down(0);

    // Delete the old root node, as it is no longer part of the heap
    delete rootNode;
}


// ============================================
// Helper methods to maintain heap property
// ============================================

// Helper function for heapifying up
template <class T>
void MaxHeap<T>::heapify_up(int index) {
    BinaryTreeNode<T>* node = nodes[index];
    while (node != nullptr) {
        BinaryTreeNode<T>* parentNode = node->getParent();
        
        // Check if the parent's value is smaller than the current node's value
        if (parentNode && node->getData() > parentNode->getData()) {
            // Swap data between parent and child node
            T temp = node->getData();
            node->setData(parentNode->getData());
            parentNode->setData(temp);

            // Move up the tree to continue the heapify process
            node = parentNode;
        } else {
            break;  // Heap property is restored
        }
    }
}

// Helper function for heapifying down
template <class T>
void MaxHeap<T>::heapify_down(int index) {
    BinaryTreeNode<T>* node = nodes[index];
    while (node != nullptr) {
        BinaryTreeNode<T>* leftChild = node->getLeftChild();
        BinaryTreeNode<T>* rightChild = node->getRightChild();
        BinaryTreeNode<T>* largerChild = nullptr;

        // Determine the larger child
        if (leftChild && rightChild) {
            largerChild = (leftChild->getData() > rightChild->getData()) ? leftChild : rightChild;
        } else if (leftChild) {
            largerChild = leftChild;
        } else if (rightChild) {
            largerChild = rightChild;
        }

        // If the larger child is greater than the current node, swap the values
        if (largerChild && node->getData() < largerChild->getData()) {
            T temp = node->getData();
            node->setData(largerChild->getData());
            largerChild->setData(temp);

            // Move down the tree to continue the heapify process
            node = largerChild;
        } else {
            break;  // Heap property is restored
        }
    }
}

// ============================================
// Internal Storage Helper Methods
// ============================================

// Get Node at index
template <class T>
BinaryTreeNode<T>* MaxHeap<T>::GetNodeAtIndex(int index) {
    if (index < 0 || index >= nodes.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return nodes[index];
}

// Get Parent
template <class T>
BinaryTreeNode<T>* MaxHeap<T>::getParent(int index) {
    if (index == 0) return nullptr;
    int parentIndex = (index - 1) / 2;
    return nodes[parentIndex];
}

// Find next available parent
template <class T>
BinaryTreeNode<T>* MaxHeap<T>::FindNextAvailableParent() {
    std::vector<BinaryTreeNode<T>*> levelOrderNodes = LevelOrderIterator();

    for (BinaryTreeNode<T>* node : levelOrderNodes) {
        if (node->getLeftChild() == nullptr || node->getRightChild() == nullptr) {
            return node;  
        }
    }

    return nullptr;
}

template <class T>
std::vector<BinaryTreeNode<T>*> MaxHeap<T>::LevelOrderIterator() {
    std::vector<BinaryTreeNode<T>*> result;
    
    // Check if the tree is empty
    if (this->getRoot() == nullptr) {
        return result;  // Return an empty result if the tree is empty
    }

    std::queue<BinaryTreeNode<T>*> q;
    q.push(this->getRoot());  // Start with the root node

    while (!q.empty()) {
        BinaryTreeNode<T>* currentNode = q.front();  // Get the front node
        q.pop();  // Remove it from the queue
        result.push_back(currentNode);  // Add it to the result vector

        // Push the children to the queue in level order
        if (currentNode->getLeftChild() != nullptr) {
            q.push(currentNode->getLeftChild());
        }
        if (currentNode->getRightChild() != nullptr) {
            q.push(currentNode->getRightChild());
        }
    }
    
    return result;  // Return the nodes in level order
}


template class MaxHeap<int>;
template class MaxHeap<char>;
template class MaxHeap<float>;
template class MaxHeap<bool>;
template class MaxHeap<double>;
template class MaxHeap<std::string>;
