# ChainIterator Class Documentation

## Overview
The `ChainIterator` class provides an iterator for traversing through a `LinkedList`. It allows the user to iterate over elements, access their values, and modify the linked list structure efficiently.

---

## Features
- Supports **forward traversal** of the linked list.
- Overloaded **operators (`++`, `!=`, `*`, `->`)** for easy access.
- Provides methods for **getting and setting the current node**.

---

## Class Definition
```cpp
// Example Usage
ChainIterator<T> iterator = list.begin();
while (iterator != list.end()) {
    std::cout << *iterator << " ";
    ++iterator;
}
```

### Constructors
```cpp
ChainIterator(Node<T>* node);
```
- **Description**: Constructs an iterator pointing to the given node.
- **Parameters**:
  - `Node<T>* node` - Pointer to the starting node.

---

### Operator Overloads
```cpp
T& operator*() const;
```
- **Description**: Returns the data stored in the current node.

```cpp
T* operator->() const;
```
- **Description**: Returns a pointer to the data stored in the current node.

```cpp
ChainIterator& operator++();
```
- **Description**: Moves the iterator to the next node in the linked list.

```cpp
bool operator!=(const ChainIterator& other) const;
```
- **Description**: Compares two iterators for inequality.

---

### Accessor Methods
```cpp
Node<T>* getCurrent() const;
```
- **Description**: Returns a pointer to the current node.

```cpp
void setCurrent(Node<T>* node);
```
- **Description**: Updates the current node pointer.

---

## Example Usage

### Iterating Through a LinkedList
```cpp
#include "LinkedList.hpp"
#include "ChainIterator.hpp"
#include <iostream>

int main() {
    LinkedList<int> list;
    list.InsertBack(10);
    list.InsertBack(20);
    list.InsertBack(30);

    std::cout << "Linked List Elements: ";
    for (ChainIterator<int> it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

---

### Modifying Elements
```cpp
ChainIterator<int> it = list.begin();
if (it != list.end()) {
    *it = 100; // Modifies first element
}
```

---

### Checking End Condition
```cpp
if (iterator == list.end()) {
    std::cout << "Reached the end of the list!" << std::endl;
}
```

---

## Conclusion
The `ChainIterator` class simplifies the process of iterating over a linked list while maintaining encapsulation and modularity. It is a crucial component when working with the `LinkedList` class, making operations more intuitive and efficient.

