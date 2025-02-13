# Node Class Documentation

## Overview
The `Node` class is a fundamental building block for linked data structures, such as linked lists. It represents a single element in a linked list, storing data and a pointer to the next node.

## Features
- Stores a single element of type `T`
- Maintains a pointer to the next node in the sequence
- Provides getter and setter methods for encapsulation
- Supports template-based generic data storage

## Usage
### Include the Header
```cpp
#include "Node.hpp"
```

### Creating a Node
```cpp
Node<int> node1(10);
Node<int> node2(20, &node1);
```

### Accessing and Modifying Data
```cpp
std::cout << node1.getData(); // Output: 10
node1.setData(15);
std::cout << node1.getData(); // Output: 15
```

### Accessing and Modifying Links
```cpp
node1.setLink(&node2);
std::cout << node1.getLink()->getData(); // Output: 20
```

## API Reference
### Constructors
```cpp
Node(const T& data, Node<T>* next = nullptr);
```
- **data**: Value to store in the node
- **next**: Pointer to the next node (default: `nullptr`)

### Getters
```cpp
T getData() const;
Node<T>* getLink() const;
```
- `getData()`: Returns the stored data
- `getLink()`: Returns the pointer to the next node

### Setters
```cpp
void setData(const T& data);
void setLink(Node<T>* next);
```
- `setData(data)`: Updates the node's data
- `setLink(next)`: Updates the next node pointer

## Example Usage in Linked List
```cpp
Node<int>* head = new Node<int>(10);
head->setLink(new Node<int>(20));
head->getLink()->setLink(new Node<int>(30));

// Print linked list elements
Node<int>* current = head;
while (current) {
    std::cout << current->getData() << " -> ";
    current = current->getLink();
}
std::cout << "nullptr";
```
**Output:**
```
10 -> 20 -> 30 -> nullptr
```

