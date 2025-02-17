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

// Push and Pop
template <class T>
void MaxHeap<T>::Push(const T& value) {
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);

    if (this->IsEmpty()) {
        this->set_root(newNode);
    } else {
        BinaryTreeNode<T>* parentNode = FindNextAvailableParent();  
        if (parentNode->getLeftChild() == nullptr) {
            parentNode->setLeftChild(newNode);
        } else {
            parentNode->setRightChild(newNode);
        }
    }

    nodes.push_back(newNode);
    heapify_up(nodes.size() - 1);
}

template <class T>
void MaxHeap<T>::Pop() {
    if (this->IsEmpty()) return;

    // Swap the root with the last node
    BinaryTreeNode<T>* rootNode = this->getRoot();
    BinaryTreeNode<T>* lastNode = nodes.back();
    
    // Set root to last node
    this->set_root(lastNode);
    cout << "root: " << this->RootData()<<endl;

    // Remove the last node from the vector
    nodes.pop_back();

    // Ensure the heap property is maintained by calling heapify_down
    heapify_down(0);  // Start from the root (index 0)
}


// ============================================
// Helper methods to maintain heap property
// ============================================

template <class T>
void MaxHeap<T>::heapify_up(int index) {
    BinaryTreeNode<T>* node = nodes[index];
    while (node != nullptr) {
        BinaryTreeNode<T>* parentNode = getParent(index);

        if (parentNode && node->getData() > parentNode->getData()) {
            T temp = node->getData();
            node->setData(parentNode->getData());
            parentNode->setData(temp);

            index = (index - 1) / 2;
            node = parentNode;
        } else {
            break;
        }
    }
}

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
            // Swap the data between the node and its larger child
            T temp = node->getData();
            node->setData(largerChild->getData());
            largerChild->setData(temp);

            // Rewire the parent-child links after the swap
            BinaryTreeNode<T>* parentNode = node->getParent();

            if (parentNode) {
                // Set the parent pointer to the new child
                if (parentNode->getLeftChild() == node) {
                    parentNode->setLeftChild(largerChild);
                } else {
                    parentNode->setRightChild(largerChild);
                }
            }

            // Update the node's left and right children (to ensure they point to correct nodes after the swap)
            if (largerChild == leftChild) {
                node->setLeftChild(leftChild->getLeftChild());
                node->setRightChild(leftChild->getRightChild());
                if (leftChild->getLeftChild() != nullptr) {
                    leftChild->getLeftChild()->setParent(node);
                }
                if (leftChild->getRightChild() != nullptr) {
                    leftChild->getRightChild()->setParent(node);
                }
            } else {
                node->setLeftChild(rightChild->getLeftChild());
                node->setRightChild(rightChild->getRightChild());
                if (rightChild->getLeftChild() != nullptr) {
                    rightChild->getLeftChild()->setParent(node);
                }
                if (rightChild->getRightChild() != nullptr) {
                    rightChild->getRightChild()->setParent(node);
                }
            }

            // Set the parent's child pointers (if any) to null, because they have been replaced by the new larger child
            largerChild->setParent(node);

            // Reassign the current node to the larger child to continue heapifying down
            node = largerChild;
        } else {
            break;  // Heap property restored, no need to continue
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
