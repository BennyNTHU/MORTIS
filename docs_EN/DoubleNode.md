# DoubleNode Class Documentation

## Introduction
`DoubleNode<T>` is a node class for doubly linked lists, inheriting from `Node<T>`, and provides an additional pointer to the previous node.

## Class Definition
```cpp
template <typename T>
class DoubleNode : public Node<T> {
public:
    DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr);
    void setPrev(DoubleNode<T>* prev);
    DoubleNode<T>* getPrev() const;
};
```

## **Function Descriptions**
### `DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr)`
- **Function**: Constructs a doubly linked list node that stores `item`, and optionally specifies `next` and `prev`.
- **Parameters**:
  - `item`: The data stored in the node.
  - `next`: Pointer to the next node (default is `nullptr`).
  - `prev`: Pointer to the previous node (default is `nullptr`).

### `void setPrev(DoubleNode<T>* prev)`
- **Function**: Sets the pointer to the previous node.
- **Parameters**:
  - `prev`: Pointer to the previous node.

### `DoubleNode<T>* getPrev() const`
- **Function**: Retrieves the pointer to the previous node.
- **Returns**:
  - Pointer to the previous node, or `nullptr` if none exists.

## **Example**
```cpp
#include "DoubleNode.hpp"
#include <iostream>

int main() {
    DoubleNode<int> node1(10);
    DoubleNode<int> node2(20, nullptr, &node1);
    node1.setNext(&node2);  // Set node1 to point to node2

    std::cout << "Node1 data: " << node1.getData() << ", Next: " << node1.getLink()->getData() << std::endl;
    std::cout << "Node2 data: " << node2.getData() << ", Prev: " << node2.getPrev()->getData() << std::endl;

    return 0;
}
```