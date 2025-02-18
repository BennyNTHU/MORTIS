# DLIterator Class Documentation

## Introduction
`DLIterator<T>` is an iterator for doubly linked lists, allowing traversal of `DoublyLinkedList<T>` in both forward and backward directions.

## Class Definition
```cpp
template <typename T>
class DLIterator : public ChainIterator<T> {
public:
    DLIterator(DoubleNode<T>* start = nullptr);
    DLIterator<T>& operator++(); // Move forward
    DLIterator<T>& operator--(); // Move backward
    bool operator!=(const DLIterator<T>& other) const;
};
```

## **Function Descriptions**
### `DLIterator(DoubleNode<T>* start = nullptr)`
- **Function**: Constructs an iterator pointing to the `start` node.
- **Parameters**:
  - `start`: Pointer to the starting node (default is `nullptr`).

### `DLIterator<T>& operator++()`
- **Function**: Advances the iterator to the next node.
- **Returns**:
  - `*this`, representing the state of the iterator after moving forward.

### `DLIterator<T>& operator--()`
- **Function**: Moves the iterator to the previous node.
- **Returns**:
  - `*this`, representing the state of the iterator after moving backward.

### `bool operator!=(const DLIterator<T>& other) const`
- **Function**: Compares whether two iterators point to different nodes.
- **Parameters**:
  - `other`: Another `DLIterator<T>` iterator.
- **Returns**:
  - Returns `true` if the iterators point to different nodes, otherwise returns `false`.

## **Example**
```cpp
#include "DoublyLinkedList.hpp"
#include "DLIterator.hpp"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;
    list.InsertBack(1);
    list.InsertBack(2);
    list.InsertBack(3);

    std::cout << "Forward traversal: ";
    for (DLIterator<int> it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```