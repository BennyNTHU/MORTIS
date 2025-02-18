# DoublyLinkedList Class Documentation

## Introduction
`DoublyLinkedList<T>` is a doubly linked list that provides functionalities such as insertion, deletion, and traversal.

## Class Definition
```cpp
template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void InsertFront(const T& e);
    void InsertBack(const T& e);
    void Insert(int pos, T e);
    void DeleteFront();
    void DeleteBack();
    void Delete(int pos);
    int Length() const;
    void Reverse();
    void Concatenate(DoublyLinkedList<T>& other);
    DLIterator<T> begin() const;
    DLIterator<T> end() const;
};
```

## **Function Descriptions**
### `DoublyLinkedList()`
- **Function**: Creates an empty doubly linked list.

### `~DoublyLinkedList()`
- **Function**: Destroys the linked list and releases all nodes.

### `void InsertFront(const T& e)`
- **Function**: Inserts element `e` at the front of the linked list.

### `void InsertBack(const T& e)`
- **Function**: Inserts element `e` at the back of the linked list.

### `void Insert(int pos, T e)`
- **Function**: Inserts `e` at position `pos`.
- **Exceptions**:
  - Throws `std::out_of_range` if `pos` is out of bounds.

### `void DeleteFront()`
- **Function**: Deletes the front element.
- **Exceptions**:
  - Throws `std::runtime_error` if the list is empty.

### `void DeleteBack()`
- **Function**: Deletes the back element.
- **Exceptions**:
  - Throws `std::runtime_error` if the list is empty.

### `void Delete(int pos)`
- **Function**: Deletes the element at position `pos`.
- **Exceptions**:
  - Throws `std::out_of_range` if `pos` is out of bounds.

### `int Length() const`
- **Function**: Returns the length of the linked list.

### `void Reverse()`
- **Function**: Reverses the linked list.

### `void Concatenate(DoublyLinkedList<T>& other)`
- **Function**: Concatenates `other` to the end of the current linked list.

### `DLIterator<T> begin() const`
- **Function**: Returns an iterator pointing to the beginning of the linked list.

### `DLIterator<T> end() const`
- **Function**: Returns an iterator pointing to the end of the linked list.

## **Example**
```cpp
#include "DoublyLinkedList.hpp"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;
    list.InsertBack(1);
    list.InsertBack(2);
    list.InsertBack(3);
    list.InsertFront(0);

    std::cout << "Linked list length: " << list.Length() << std::endl;
    list.DeleteFront();
    list.DeleteBack();

    std::cout << "Length after deleting front and back elements: " << list.Length() << std::endl;

    return 0;
}
```