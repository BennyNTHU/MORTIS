#include <vector>
#include <stdexcept>
#include <algorithm>
#include <queue>
#include "MaxHeap.hpp"
#include "../BinaryTreeNode/BinaryTreeNode.hpp"

// ============================================
// Internal Storage Helper Methods
// ============================================

template <class T>
BinaryTreeNode<T>* MaxHeap<T>::getParent(int index) 
{
    if (index == 0) 
        return nullptr;
    
    int parentIndex = (index - 1) / 2;
    return nodes[parentIndex];
}

template <class T>
BinaryTreeNode<T>* MaxHeap<T>::GetNodeAtIndex(int index) 
{
    if (index < 0 || index >= nodes.size())
        throw std::out_of_range("Index out of bounds");

    return nodes[index];
}

// Since we now use the vector to insert nodes in order, the next available parent is just the parent
// of the next insertion index.
template <class T>
BinaryTreeNode<T>* MaxHeap<T>::FindNextAvailableParent() 
{
    int n = nodes.size();
    int parentIndex = (n - 1) / 2;
    return nodes[parentIndex];
}

// ============================================
// Constructor and Destructor
// ============================================

template <class T>
MaxHeap<T>::MaxHeap(const T& rootData) : BinaryTree<T>(rootData) 
{
    // Initialize the nodes vector with the current root.
    nodes.push_back(this->getRoot());
}

template <class T>
MaxHeap<T>::~MaxHeap() 
{
    // The BinaryTree destructor will clean up all nodes.
}

// ============================================
// Push and Pop
// ============================================

template <class T>
void MaxHeap<T>::Push(const T& value) 
{
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);
    int n = nodes.size();

    if (this->IsEmpty()) 
    {
        this->set_root(newNode);    // If the heap is empty, new node becomes root.
    } 
    else 
    {
        int parentIndex = (n - 1) / 2;  // In a complete binary tree, the parent index for new node is (n-1)/2.
        BinaryTreeNode<T>* parentNode = nodes[parentIndex];

        if (parentNode->getLeftChild() == nullptr) 
        {
            parentNode->setLeftChild(newNode);
        } 
        else 
        {
            parentNode->setRightChild(newNode);
        }
        newNode->setParent(parentNode);
    }
    
    nodes.push_back(newNode);
    heapify_up(nodes.size() - 1);
}

template <class T>
void MaxHeap<T>::Pop() 
{
    if (this->IsEmpty()) 
    {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }
    
    // Save the current root node.
    BinaryTreeNode<T>* oldRoot = this->getRoot();
    int n = nodes.size();
    
    if (n == 1) // If there's only one node, clear the heap. 
    {
        this->set_root(nullptr);
        delete oldRoot;
        nodes.clear();
        return;
    }
    
    // Get the last node from the array and remove it.
    BinaryTreeNode<T>* lastNode = nodes.back();
    nodes.pop_back();
    
    // Replace the root in the vector with the last node.
    nodes[0] = lastNode;
    
    // Disconnect lastNode from its current parent.
    BinaryTreeNode<T>* parentOfLast = lastNode->getParent();
    if (parentOfLast) 
    {
        if (parentOfLast->getLeftChild() == lastNode)
            parentOfLast->setLeftChild(nullptr);
        else if (parentOfLast->getRightChild() == lastNode)
            parentOfLast->setRightChild(nullptr);
    }
    lastNode->setParent(nullptr);
    
    // Now, move lastNode to the root position:
    // It should adopt the children of oldRoot.
    // (Be careful not to set pointers to itself.)
    lastNode->setLeftChild(oldRoot->getLeftChild());
    if (lastNode->getLeftChild() && lastNode->getLeftChild() != lastNode)
        lastNode->getLeftChild()->setParent(lastNode);
    
    lastNode->setRightChild(oldRoot->getRightChild());
    if (lastNode->getRightChild() && lastNode->getRightChild() != lastNode)
        lastNode->getRightChild()->setParent(lastNode);
    
    // Update the tree's root pointer.
    this->set_root(lastNode);
    
    // (Optional) Rebuild the tree links from the vector if needed:
    rebuildTreeLinks();
    
    // Restore the heap property by heapifying down from the root.
    heapify_down(0);
    
    // Delete the old root.
    delete oldRoot;
}

// ============================================
// Helper methods to maintain heap property
// ============================================

// rebuildTreeLinks() updates each node's parent, left, and right pointers according to the
// nodes vector, which represents a complete binary tree.
template <class T>
void MaxHeap<T>::rebuildTreeLinks() 
{
    int n = nodes.size();
    if(n == 0) return;
    
    nodes[0]->setParent(nullptr);   // The first node is the root.
    this->set_root(nodes[0]);

    for (int i = 0; i < n; i++) 
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n) 
        {
            nodes[i]->setLeftChild(nodes[left]);
            nodes[left]->setParent(nodes[i]);
        } 
        else 
        {
            nodes[i]->setLeftChild(nullptr);
        }

        if (right < n) 
        {
            nodes[i]->setRightChild(nodes[right]);
            nodes[right]->setParent(nodes[i]);
        } 
        else 
        {
            nodes[i]->setRightChild(nullptr);
        }
    }
}

// Heapify up: using the array representation, swap nodes in the vector if needed
template <class T>
void MaxHeap<T>::heapify_up(int index) 
{
    while (index > 0) 
    {
        int parentIndex = (index - 1) / 2;

        if (nodes[index]->getData() > nodes[parentIndex]->getData()) 
        {
            std::swap(nodes[index], nodes[parentIndex]);
            rebuildTreeLinks();
            index = parentIndex;
        } 
        else 
        {
            break;
        }
    }
}

// Heapify down: similarly, adjust nodes in the vector
template <class T>
void MaxHeap<T>::heapify_down(int index) 
{
    int n = nodes.size();

    while (true) 
    {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int largest = index;

        if (leftIndex < n && nodes[leftIndex]->getData() > nodes[largest]->getData())
            largest = leftIndex;

        if (rightIndex < n && nodes[rightIndex]->getData() > nodes[largest]->getData())
            largest = rightIndex;

        if (largest != index) 
        {
            std::swap(nodes[index], nodes[largest]);
            rebuildTreeLinks();
            index = largest;
        } 
        else 
        {
            break;
        }
    }
}

// LevelOrderIterator: returns a vector of node pointers in level order (using the tree structure).
template <class T>
std::vector<BinaryTreeNode<T>*> MaxHeap<T>::LevelOrderIterator() 
{
    std::vector<BinaryTreeNode<T>*> result;

    if (this->getRoot() == nullptr)
        return result;

    std::queue<BinaryTreeNode<T>*> q;
    q.push(this->getRoot());

    while (!q.empty()) 
    {
        BinaryTreeNode<T>* curr = q.front();
        q.pop();
        result.push_back(curr);
        
        if (curr->getLeftChild() != nullptr)
            q.push(curr->getLeftChild());

        if (curr->getRightChild() != nullptr)
            q.push(curr->getRightChild());
    }
    
    return result;
}

// ============================================
// Explicit template instantiation 
// ============================================

template class MaxHeap<int>;
template class MaxHeap<char>;
template class MaxHeap<float>;
template class MaxHeap<bool>;
template class MaxHeap<double>;
template class MaxHeap<std::string>;
