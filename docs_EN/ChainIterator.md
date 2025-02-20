# `ChainIterator` Documentation

## Overview

The `ChainIterator.hpp` file defines a templated `ChainIterator` class for iterating through a linked list structure where each element is stored in a `Node<T>`. This iterator supports the common operations such as dereferencing, incrementing, and equality comparison, making it useful for traversing through a chain (linked list) of nodes.

---

## Key Components

### `ChainIterator` Class

The `ChainIterator` class template is designed to allow iteration over a linked list (or chain) of nodes. It provides methods to move through the list and access the data within each node.

#### Member Variables:
- **`current`**: A pointer to the current node in the chain, which the iterator is pointing to.

#### Constructors:
- **`ChainIterator(Node<T>* startNode = nullptr)`**: Constructor that initializes the iterator to point to the provided starting node. If no node is provided, the iterator is initialized to `nullptr`.

#### Getters:
- **`getCurrent()`**: Returns a pointer to the current node.

  Example:
  ```cpp
  Node<int>* currentNode = iterator.getCurrent();
  ```

#### Dereferencing Operators:
- **`operator*()`**: Dereferences the iterator and returns a constant reference to the data stored in the current node.
  
  Example:
  ```cpp
  const int& value = *iterator;  // Access the data of the current node
  ```

- **`operator->()`**: Returns a pointer to the current node, allowing access to the node’s members directly.
  
  Example:
  ```cpp
  const Node<int>* nodePtr = iterator.operator->();  // Access the node's properties
  ```

#### Increment Operators:
- **`operator++()`**: Pre-increment operator, which moves the iterator to the next node in the chain.

  Example:
  ```cpp
  ++iterator;  // Move to the next node
  ```

- **`operator++(int)`**: Post-increment operator, which moves the iterator to the next node but returns the current iterator before incrementing.
  
  Example:
  ```cpp
  iterator++;  // Move to the next node, but return the current node
  ```

#### Equality and Inequality Operators:
- **`operator!=(const ChainIterator<T>& r)`**: Checks if the current iterator is not equal to the provided iterator, meaning it is not pointing to the same node.
  
  Example:
  ```cpp
  if (iterator != anotherIterator) {
      // Do something
  }
  ```

- **`operator==(const ChainIterator<T>& r)`**: Checks if the current iterator is equal to the provided iterator, meaning it points to the same node.
  
  Example:
  ```cpp
  if (iterator == anotherIterator) {
      // Do something
  }
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `ChainIterator` class with a linked list of `Node<T>` elements.

```cpp
#include "ChainIterator.hpp"
#include "Node.hpp"

int main() {
    // Creating a simple linked list of integers
    Node<int> node1(10);  // Node with data 10
    Node<int> node2(20);  // Node with data 20
    Node<int> node3(30);  // Node with data 30

    node1.next = &node2;
    node2.next = &node3;
    node3.next = nullptr;

    // Creating a ChainIterator to traverse the list
    ChainIterator<int> iterator(&node1);

    // Iterating through the list
    while (iterator != ChainIterator<int>()) {
        std::cout << *iterator << std::endl;  // Dereference to get the data
        ++iterator;  // Move to the next node
    }

    return 0;
}
```

### Explanation:
- A linked list of `Node<int>` is created with three nodes, each containing an integer.
- A `ChainIterator<int>` is initialized to point to the first node of the list.
- The `while` loop uses the `operator!=` to iterate through the list, printing the data of each node. The `operator++` is used to move to the next node.

---

## Potential Errors & Edge Cases

1. **Null Pointer Dereferencing**: If the iterator points to a null node (`nullptr`), dereferencing it will lead to undefined behavior. Ensure that the iterator is not null before dereferencing.
   
   Example check before dereferencing:
   ```cpp
   if (iterator.getCurrent() != nullptr) {
       std::cout << *iterator << std::endl;
   }
   ```

2. **Infinite Loops**: If the chain (linked list) has a cycle (a node points back to a previous node), the iterator may run into an infinite loop. Make sure that the linked list structure is acyclic or include logic to prevent infinite iteration.

3. **Uninitialized Iterator**: If the iterator is not properly initialized with a valid node, accessing or using it may lead to unexpected results. Ensure the iterator is initialized with a valid node or `nullptr`.

---

## Dependencies

- **`Node.hpp`**: The `ChainIterator` class relies on the `Node<T>` class to define the structure of the linked list. Ensure that the `Node<T>` class is defined and includes a `next` pointer to link nodes together.
  
- **C++ Standard Library**: The class uses `<iostream>` and `<cstring>` for standard I/O and string manipulations.
