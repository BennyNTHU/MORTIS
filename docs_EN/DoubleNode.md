# `DoubleNode` Documentation

## Overview

The `DoubleNode.hpp` header file defines a `DoubleNode` class template that extends from the `Node<T>` class. This class is used to represent a node in a doubly linked list, which has two pointers: one pointing to the next node and one pointing to the previous node. The `DoubleNode` class includes methods for setting and getting the previous node, as well as standard constructors and destructors.

---

## Key Components

### `DoubleNode` Class

The `DoubleNode` class is a specialized version of the `Node<T>` class, which adds a pointer to the previous node in the list. This allows traversal in both directions: forward and backward.

#### Member Variables:
- **`prev`**: A pointer to the previous node in the doubly linked list.

#### Constructors & Destructor:
- **`DoubleNode()`**: Default constructor that initializes a node with no data and both `next` and `prev` pointers set to `nullptr`.
  
  Example:
  ```cpp
  DoubleNode<int> node;  // Creates an empty DoubleNode
  ```

- **`DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr)`**: Constructor that initializes a node with the given item and optional `next` and `prev` pointers. If not provided, the default values for `next` and `prev` are `nullptr`.
  
  Example:
  ```cpp
  DoubleNode<int> node(10);  // Creates a node with data 10 and both next and prev as nullptr
  ```

- **`~DoubleNode()`**: Destructor that is used to clean up any resources used by the `DoubleNode` object. In this case, it ensures proper deletion of the node when it is no longer needed.

#### Getters and Setters:
- **`getPrev()`**: Returns the pointer to the previous node in the doubly linked list.
  
  Example:
  ```cpp
  DoubleNode<int>* prevNode = node.getPrev();  // Access the previous node pointer
  ```

- **`setPrev(DoubleNode<T>* prev)`**: Sets the previous node pointer to the provided `prev` node.

  Example:
  ```cpp
  node.setPrev(&anotherNode);  // Set the previous node pointer to anotherNode
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `DoubleNode` class in the context of a doubly linked list:

```cpp
#include "DoubleNode.hpp"
#include <iostream>

int main() {
    // Create two DoubleNode objects
    DoubleNode<int> node1(10);
    DoubleNode<int> node2(20);

    // Link the nodes
    node1.setPrev(nullptr);  // First node has no previous node
    node1.next = &node2;     // Link to the second node

    node2.setPrev(&node1);   // Second node's previous is the first node

    // Access data and previous node
    std::cout << "Node 1 data: " << node1.data << ", Previous: " << node1.getPrev() << std::endl;
    std::cout << "Node 2 data: " << node2.data << ", Previous: " << node2.getPrev()->data << std::endl;

    return 0;
}
```

### Explanation:
- The example demonstrates creating two `DoubleNode<int>` objects and linking them together to form a doubly linked list.
- The `setPrev()` method is used to set the previous node pointer for each node.
- The `getPrev()` method is used to retrieve and display the previous node.

---

## Potential Errors & Edge Cases

1. **Uninitialized Pointers**: Ensure that the `next` and `prev` pointers are properly initialized. If a `DoubleNode` is created without explicitly setting the `prev` pointer, it defaults to `nullptr`, but this should be checked before using the pointer.

   Example check:
   ```cpp
   if (node.getPrev() != nullptr) {
       std::cout << "Previous node data: " << node.getPrev()->data << std::endl;
   }
   ```

2. **Circular References**: In cases where a doubly linked list forms a loop (where the last node points to the first), special care must be taken to avoid infinite loops during traversal. Ensure that the list is properly managed to prevent circular references unless explicitly required by the use case.

---

## Dependencies

- **`Node.hpp`**: The `DoubleNode` class inherits from the `Node<T>` class, so ensure that the `Node<T>` class is properly defined and includes a `next` pointer for linking nodes.
- **C++ Standard Library**: The class relies on standard C++ features like pointers and constructors.
