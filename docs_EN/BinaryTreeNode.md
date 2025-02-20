# `BinaryTreeNode` Documentation

## Overview

The `BinaryTreeNode.hpp` header file defines a `BinaryTreeNode` class template for representing a node in a binary tree. The class stores data of type `T` and provides various methods for managing tree structure, such as accessing and modifying children and parent pointers, as well as equality comparisons.

---

## Key Components

### `BinaryTreeNode` Class

The `BinaryTreeNode` class represents a node in a binary tree, storing data and pointers to the node's left and right children, parent, and threaded pointers. Threaded pointers are used in threaded binary trees to represent null child pointers.

#### Member Variables:
- **`data`**: The data stored in the node, of type `T`.
- **`leftChild`**: Pointer to the left child node.
- **`rightChild`**: Pointer to the right child node.
- **`parent`**: Pointer to the parent node.
- **`leftthread`**: Pointer used in threaded binary trees, typically pointing to the in-order predecessor.
- **`rightthread`**: Pointer used in threaded binary trees, typically pointing to the in-order successor.

---

### Constructors & Destructor

- **`BinaryTreeNode(const T& e)`**: Constructor that initializes a node with data `e`. The left and right child pointers, as well as parent and threaded pointers, are set to `nullptr`.

  Example:
  ```cpp
  BinaryTreeNode<int> node(10);  // Create a node with data 10
  ```

- **`BinaryTreeNode(const T& e, BinaryTreeNode<T>* ptr_left, BinaryTreeNode<T>* ptr_right)`**: Constructor that initializes a node with data `e` and sets the left and right children to the specified pointers `ptr_left` and `ptr_right`.

  Example:
  ```cpp
  BinaryTreeNode<int> node(10, leftNode, rightNode);  // Create a node with left and right children
  ```

---

### Getter Methods

- **`const T& getData() const`**: Returns the data stored in the node.

  Example:
  ```cpp
  int data = node.getData();  // Get the data from the node
  ```

- **`BinaryTreeNode<T>* getRightChild()`**: Returns a pointer to the right child node.

  Example:
  ```cpp
  BinaryTreeNode<int>* right = node.getRightChild();  // Get the right child of the node
  ```

- **`BinaryTreeNode<T>* getLeftChild()`**: Returns a pointer to the left child node.

  Example:
  ```cpp
  BinaryTreeNode<int>* left = node.getLeftChild();  // Get the left child of the node
  ```

- **`BinaryTreeNode<T>* getRightThread() const`**: Returns the threaded pointer for the right child (if used in a threaded binary tree).

  Example:
  ```cpp
  BinaryTreeNode<int>* rightThread = node.getRightThread();  // Get the right thread pointer
  ```

- **`BinaryTreeNode<T>* getLeftThread() const`**: Returns the threaded pointer for the left child (if used in a threaded binary tree).

  Example:
  ```cpp
  BinaryTreeNode<int>* leftThread = node.getLeftThread();  // Get the left thread pointer
  ```

- **`BinaryTreeNode<T>* getParent() const`**: Returns a pointer to the parent node.

  Example:
  ```cpp
  BinaryTreeNode<int>* parent = node.getParent();  // Get the parent of the node
  ```

---

### Setter Methods

- **`void setData(T in)`**: Sets the data of the node to `in`.

  Example:
  ```cpp
  node.setData(20);  // Set the data of the node to 20
  ```

- **`void setParent(BinaryTreeNode<T>* in)`**: Sets the parent of the node to `in`.

  Example:
  ```cpp
  node.setParent(parentNode);  // Set the parent of the node
  ```

- **`void setLeftChild(BinaryTreeNode<T>* in)`**: Sets the left child of the node to `in`.

  Example:
  ```cpp
  node.setLeftChild(leftNode);  // Set the left child of the node
  ```

- **`void setRightChild(BinaryTreeNode<T>* in)`**: Sets the right child of the node to `in`.

  Example:
  ```cpp
  node.setRightChild(rightNode);  // Set the right child of the node
  ```

---

### Threaded Pointer Methods

- **`void setLeftThread(BinaryTreeNode<T>* in)`**: Sets the left threaded pointer to `in`.

  Example:
  ```cpp
  node.setLeftThread(leftThreadNode);  // Set the left threaded pointer
  ```

- **`void setRightThread(BinaryTreeNode<T>* in)`**: Sets the right threaded pointer to `in`.

  Example:
  ```cpp
  node.setRightThread(rightThreadNode);  // Set the right threaded pointer
  ```

---

### Equality Methods

- **`bool operator==(const BinaryTreeNode<T>& r) const`**: Compares the current node to another node `r` for equality based on data.

  Example:
  ```cpp
  bool areEqual = node == anotherNode;  // Check if two nodes are equal
  ```

- **`bool operator!=(const BinaryTreeNode<T>& r) const`**: Compares the current node to another node `r` for inequality.

  Example:
  ```cpp
  bool areNotEqual = node != anotherNode;  // Check if two nodes are not equal
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `BinaryTreeNode` class:

```cpp
#include "BinaryTreeNode.hpp"
#include <iostream>

int main() {
    // Create a node with data 10
    BinaryTreeNode<int> node(10);

    // Set left and right children
    BinaryTreeNode<int> leftNode(5);
    BinaryTreeNode<int> rightNode(15);

    node.setLeftChild(&leftNode);  // Set left child
    node.setRightChild(&rightNode);  // Set right child

    // Get and print the data of the node
    std::cout << "Node data: " << node.getData() << std::endl;

    // Get the left and right children and print their data
    std::cout << "Left child data: " << node.getLeftChild()->getData() << std::endl;
    std::cout << "Right child data: " << node.getRightChild()->getData() << std::endl;

    // Set parent for left child and print the parent's data
    leftNode.setParent(&node);
    std::cout << "Parent of left child: " << leftNode.getParent()->getData() << std::endl;

    return 0;
}
```

### Explanation:
- The code creates a `BinaryTreeNode` with data `10` and sets its left and right children.
- It demonstrates how to access the data, set the parent, and manipulate the left and right children using setter and getter methods.

---

## Potential Errors & Edge Cases

1. **Null Pointers**: When accessing children, parents, or threaded pointers, ensure that the pointers are not `nullptr` before dereferencing. If necessary, check for `nullptr` and handle the case accordingly.

   Example:
   ```cpp
   if (node.getLeftChild() != nullptr) {
       std::cout << "Left child data: " << node.getLeftChild()->getData() << std::endl;
   }
   ```

2. **Threaded Pointer Misuse**: When using threaded binary trees, ensure that threaded pointers are set correctly, as incorrect handling can lead to undefined behavior.

3. **Equality Comparison**: The equality operators (`==`, `!=`) only compare the node's data. If your application requires a more thorough comparison (e.g., checking children or threaded pointers), modify the equality operator accordingly.

---

## Dependencies

- **C++ Standard Library**: This file uses basic C++ library features like `iostream` for printing and `std::nullptr_t` for handling null pointers.
- **`BinaryTree.hpp`**: This file assumes that the `BinaryTree` class is defined and includes functionality for managing the tree structure, such as traversals or root management.
