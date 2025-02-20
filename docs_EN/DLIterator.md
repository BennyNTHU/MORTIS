# DLIterator.hpp Documentation

## Overview

The `DLIterator.hpp` header file defines a template class `DLIterator` that implements an iterator for traversing doubly linked lists. This class inherits from `ChainIterator` and provides functionality to move forward and backward through the list, as well as access the current node.

## Class: `DLIterator<T>`

### Description
The `DLIterator<T>` class is a template class that represents an iterator for doubly linked lists. It provides methods to traverse the list in both directions (forward and backward) and to access the current node.

### Template Parameters
- `T`: The type of elements stored in the nodes of the list.

### Constructors

#### `DLIterator(DoubleNode<T>* startNode = nullptr)`
- **Description**: Constructor. Initializes the iterator with a starting node.
- **Parameters**:
  - `startNode`: A pointer to the `DoubleNode<T>` where the iterator should start. Defaults to `nullptr`.
- **Usage**:
  ```cpp
  DoubleNode<int>* node = new DoubleNode<int>(10);
  DLIterator<int> it(node);
  ```

### Move Operators

#### `DLIterator<T>& operator++()`
- **Description**: Pre-increment operator. Moves the iterator to the next node in the list.
- **Return Value**: A reference to the updated iterator.
- **Usage**:
  ```cpp
  DLIterator<int> it(node);
  ++it;  // Move to the next node
  ```

#### `ChainIterator<T> operator++(int)`
- **Description**: Post-increment operator. Moves the iterator to the next node in the list and returns the previous iterator state.
- **Return Value**: A `ChainIterator<T>` object representing the iterator before the increment.
- **Usage**:
  ```cpp
  DLIterator<int> it(node);
  it++;  // Move to the next node, but return the previous state
  ```

#### `DLIterator<T>& operator--()`
- **Description**: Pre-decrement operator. Moves the iterator to the previous node in the list.
- **Return Value**: A reference to the updated iterator.
- **Usage**:
  ```cpp
  DLIterator<int> it(node);
  --it;  // Move to the previous node
  ```

#### `DLIterator<T> operator--(int)`
- **Description**: Post-decrement operator. Moves the iterator to the previous node in the list and returns the previous iterator state.
- **Return Value**: A `DLIterator<T>` object representing the iterator before the decrement.
- **Usage**:
  ```cpp
  DLIterator<int> it(node);
  it--;  // Move to the previous node, but return the previous state
  ```

### Get Current Node

#### `DoubleNode<T>* getCurrent() const`
- **Description**: Returns a pointer to the current node.
- **Return Value**: A pointer to the `DoubleNode<T>` that the iterator is currently pointing to.
- **Usage**:
  ```cpp
  DLIterator<int> it(node);
  DoubleNode<int>* currentNode = it.getCurrent();
  ```

## Example Usage

```cpp
#include "DLIterator.hpp"
#include "DoubleNode.hpp"
#include <iostream>

int main() {
    DoubleNode<int>* node1 = new DoubleNode<int>(10);
    DoubleNode<int>* node2 = new DoubleNode<int>(20);
    DoubleNode<int>* node3 = new DoubleNode<int>(30);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;

    DLIterator<int> it(node1);

    std::cout << "Current node: " << it.getCurrent()->data << std::endl;  // Output: 10
    ++it;
    std::cout << "Next node: " << it.getCurrent()->data << std::endl;     // Output: 20
    --it;
    std::cout << "Previous node: " << it.getCurrent()->data << std::endl; // Output: 10

    delete node1;
    delete node2;
    delete node3;

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Null Pointer**: If the iterator is initialized with a `nullptr`, calling `operator++` or `operator--` will result in undefined behavior. Ensure the iterator is initialized with a valid node.
2. **End of List**: If the iterator reaches the end of the list (i.e., `current->next` is `nullptr`), calling `operator++` will result in undefined behavior. Similarly, if the iterator is at the beginning of the list (i.e., `current->prev` is `nullptr`), calling `operator--` will result in undefined behavior. Always check the boundaries before moving the iterator.
3. **Memory Management**: Ensure proper memory management when dealing with nodes to avoid memory leaks.

## Dependencies

- `DoubleNode.hpp`: Defines the node structure used in the list.
- `ChainIterator.hpp`: Base class for the iterator functionality.

Ensure these files are included and properly configured in your project to use `DLIterator.hpp`.
