# `Node` Documentation

## Overview

The `Node.hpp` header file defines a template class `Node` that represents a node in a singly linked list. Each node contains data and a pointer to the next node in the list. This class provides basic functionality for creating, accessing, and modifying nodes, which are fundamental building blocks for linked list data structures.

## Class: `Node<T>`

### Description
The `Node<T>` class is a template class that represents a node in a singly linked list. It stores data of type `T` and a pointer to the next node in the list.

### Template Parameters
- `T`: The type of data stored in the node.

### Constructors and Destructor

#### `Node()`
- **Description**: Default constructor. Initializes a node with default values (data is default-initialized, and the link is set to `nullptr`).
- **Usage**:
  ```cpp
  Node<int> node;
  ```

#### `Node(const T& item, Node<T>* next)`
- **Description**: Constructor. Initializes a node with the given data and a pointer to the next node.
- **Parameters**:
  - `item`: The data to store in the node.
  - `next`: A pointer to the next node in the list.
- **Usage**:
  ```cpp
  Node<int>* nextNode = new Node<int>(20, nullptr);
  Node<int> node(10, nextNode);
  ```

#### `~Node()`
- **Description**: Destructor. Cleans up the node. Note that this does not automatically delete the next node in the list.
- **Usage**: Automatically called when the object goes out of scope.

### Getter Methods

#### `const T& getData() const`
- **Description**: Returns the data stored in the node.
- **Return Value**: A constant reference to the data of type `T`.
- **Usage**:
  ```cpp
  Node<int> node(10, nullptr);
  int data = node.getData();  // data is 10
  ```

#### `Node<T>* getLink() const`
- **Description**: Returns a pointer to the next node in the list.
- **Return Value**: A pointer to the next `Node<T>`.
- **Usage**:
  ```cpp
  Node<int>* nextNode = new Node<int>(20, nullptr);
  Node<int> node(10, nextNode);
  Node<int>* link = node.getLink();  // link points to nextNode
  ```

### Setter Methods

#### `void setData(const T& item)`
- **Description**: Sets the data stored in the node.
- **Parameters**:
  - `item`: The new data to store in the node.
- **Usage**:
  ```cpp
  Node<int> node(10, nullptr);
  node.setData(20);  // The node now stores 20
  ```

#### `void setLink(Node<T>* next)`
- **Description**: Sets the pointer to the next node in the list.
- **Parameters**:
  - `next`: A pointer to the next node.
- **Usage**:
  ```cpp
  Node<int>* nextNode = new Node<int>(20, nullptr);
  Node<int> node(10, nullptr);
  node.setLink(nextNode);  // The node now points to nextNode
  ```

## Example Usage

```cpp
#include "Node.hpp"
#include <iostream>

int main() {
    // Create nodes
    Node<int>* node3 = new Node<int>(30, nullptr);
    Node<int>* node2 = new Node<int>(20, node3);
    Node<int>* node1 = new Node<int>(10, node2);

    // Traverse the list
    Node<int>* current = node1;
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getLink();
    }
    std::cout << std::endl;

    // Modify a node
    node2->setData(25);
    std::cout << "Modified node2 data: " << node2->getData() << std::endl;

    // Clean up
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Null Pointer Dereferencing**: When using `getLink()` or `setLink(Node<T>*)`, ensure that the pointer is not `nullptr` before dereferencing it to avoid runtime errors.
2. **Memory Leaks**: When dynamically allocating nodes (e.g., using `new`), ensure that you properly delete them to avoid memory leaks.
3. **Data Type Mismatch**: Ensure that the data type `T` used in the node matches the type of data you intend to store, as mismatched types can lead to compilation errors or undefined behavior.

## Dependencies

- **Standard Library**: The header file includes `<iostream>` and `<string>`, which are part of the C++ Standard Library. Ensure that your environment is configured to use the standard library.

## Summary

The `Node.hpp` file provides a simple and flexible implementation of a node for a singly linked list. It is designed to be easily integrated into larger data structures like linked lists, stacks, or queues. By following the examples and guidelines provided, you can effectively use this class to build and manipulate linked lists in your projects.
