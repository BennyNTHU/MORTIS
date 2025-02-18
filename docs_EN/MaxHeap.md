# MaxHeap Documentation

## Overview

`MaxHeap` is a **binary heap** implemented as a **binary tree** where the maximum element is always at the root. It provides efficient insertion, deletion, and retrieval of the maximum element while maintaining the **complete binary tree** structure.

This implementation inherits from `BinaryTree<T>` and uses a **vector-based storage approach** to maintain heap properties.

## Features

- **Insertion (`Push`)**: Inserts a new element while maintaining the heap property.
- **Deletion (`Pop`)**: Removes the root (maximum element) and restructures the heap.
- **Retrieval (`Top`)**: Returns the maximum element without removing it.
- **Heapification (`heapify_up`, `heapify_down`)**: Maintains heap structure after insertions and deletions.
- **Level Order Traversal**: Retrieves elements in level order.

---

## 1. **Class Definition**
```cpp
template <class T>
class MaxHeap: public BinaryTree<T> {
private:
    std::vector<BinaryTreeNode<T>*> nodes;  // Stores tree nodes in heap order

public:
    // Constructors and Destructor
    MaxHeap(const T& rootData);   // Constructor with root data
    ~MaxHeap();                   // Destructor

    // Heap Operations
    void Push(const T& value);     // Insert a value
    void Pop();                    // Remove max element
    const T& Top() const;          // Get the max element
    bool IsEmpty() const;          // Check if empty

    // Internal Heap Management
    void heapify_up(int index);
    void heapify_down(int index);
    void rebuildTreeLinks();       // Rebuilds tree pointers from the array representation
};
```

---

## 2. **Constructor and Destructor**

### **Constructor**
```cpp
template <class T>
MaxHeap<T>::MaxHeap(const T& rootData) : BinaryTree<T>(rootData) {
    nodes.push_back(this->getRoot()); // Initialize with root node
}
```
📌 **Explanation**: Initializes the heap with a **single root node**.

### **Destructor**
```cpp
template <class T>
MaxHeap<T>::~MaxHeap() {
    // The BinaryTree destructor will clean up all nodes.
}
```
📌 **Explanation**: The destructor relies on the `BinaryTree<T>` destructor to clean up memory.

---

## 3. **Heap Operations**

### **Push (Insertion)**
```cpp
template <class T>
void MaxHeap<T>::Push(const T& value) {
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);
    int n = nodes.size();

    if (this->IsEmpty()) {
        this->set_root(newNode);
    } else {
        int parentIndex = (n - 1) / 2;
        BinaryTreeNode<T>* parentNode = nodes[parentIndex];
        if (parentNode->getLeftChild() == nullptr) {
            parentNode->setLeftChild(newNode);
        } else {
            parentNode->setRightChild(newNode);
        }
        newNode->setParent(parentNode);
    }

    nodes.push_back(newNode);
    heapify_up(nodes.size() - 1);
}
```
📌 **Explanation**:
1. Creates a **new node**.
2. Inserts it at the **next available position** (complete binary tree).
3. Updates **parent-child relationships**.
4. Calls **heapify_up** to maintain heap properties.

---

### **Pop (Remove Max Element)**
```cpp
template <class T>
void MaxHeap<T>::Pop() {
    if (this->IsEmpty()) {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }

    BinaryTreeNode<T>* oldRoot = this->getRoot();
    int n = nodes.size();

    if (n == 1) {
        this->set_root(nullptr);
        delete oldRoot;
        nodes.clear();
        return;
    }

    BinaryTreeNode<T>* lastNode = nodes.back();
    nodes.pop_back();
    nodes[0] = lastNode;

    BinaryTreeNode<T>* parentOfLast = lastNode->getParent();
    if (parentOfLast) {
        if (parentOfLast->getLeftChild() == lastNode)
            parentOfLast->setLeftChild(nullptr);
        else
            parentOfLast->setRightChild(nullptr);
    }
    lastNode->setParent(nullptr);

    lastNode->setLeftChild(oldRoot->getLeftChild());
    if (lastNode->getLeftChild() && lastNode->getLeftChild() != lastNode)
        lastNode->getLeftChild()->setParent(lastNode);

    lastNode->setRightChild(oldRoot->getRightChild());
    if (lastNode->getRightChild() && lastNode->getRightChild() != lastNode)
        lastNode->getRightChild()->setParent(lastNode);

    this->set_root(lastNode);
    rebuildTreeLinks();
    heapify_down(0);
    delete oldRoot;
}
```
📌 **Explanation**:
1. Stores the **current root** (max element).
2. Replaces it with the **last node**.
3. Updates **parent-child links**.
4. Calls **heapify_down** to maintain heap properties.

---

### **Top (Retrieve Max Element)**
```cpp
template <class T>
const T& MaxHeap<T>::Top() const {
    return this->getRoot()->getData();
}
```
📌 **Explanation**: Returns the **root node’s data**, which is always the maximum.

---

### **IsEmpty**
```cpp
template <class T>
bool MaxHeap<T>::IsEmpty() const {
    return nodes.empty();
}
```
📌 **Explanation**: Checks if the heap has no elements.

---

## 4. **Heap Property Maintenance**

### **Heapify Up**
```cpp
template <class T>
void MaxHeap<T>::heapify_up(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (nodes[index]->getData() > nodes[parentIndex]->getData()) {
            std::swap(nodes[index], nodes[parentIndex]);
            rebuildTreeLinks();
            index = parentIndex;
        } else {
            break;
        }
    }
}
```
📌 **Explanation**:
- Moves the inserted node **upward** if it is greater than its parent.

---

### **Heapify Down**
```cpp
template <class T>
void MaxHeap<T>::heapify_down(int index) {
    int n = nodes.size();
    while (true) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int largest = index;

        if (leftIndex < n && nodes[leftIndex]->getData() > nodes[largest]->getData())
            largest = leftIndex;
        if (rightIndex < n && nodes[rightIndex]->getData() > nodes[largest]->getData())
            largest = rightIndex;

        if (largest != index) {
            std::swap(nodes[index], nodes[largest]);
            rebuildTreeLinks();
            index = largest;
        } else {
            break;
        }
    }
}
```
📌 **Explanation**:
- Moves the root **downward** if it is smaller than a child.

---

## 5. **Example Usage**
```cpp
#include <iostream>
#include "MaxHeap.hpp"

int main() {
    MaxHeap<int> heap(10);  // Initialize with root 10

    heap.Push(20);
    heap.Push(15);
    heap.Push(30);
    heap.Push(25);

    std::cout << "Max element: " << heap.Top() << std::endl; // 30

    heap.Pop();
    std::cout << "After Pop, Max element: " << heap.Top() << std::endl; // 25

    return 0;
}
```

---

## Summary

| Function         | Description |
|-----------------|-------------|
| `Push(value)`   | Inserts an element and maintains heap properties. |
| `Pop()`         | Removes the max element and restructures the heap. |
| `Top()`         | Returns the max element without removing it. |
| `IsEmpty()`     | Checks if the heap is empty. |
