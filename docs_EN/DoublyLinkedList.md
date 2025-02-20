# `DoublyLinkedList` Documentation

## Overview

The `DoublyLinkedList.hpp` header file defines a template class `DoublyLinkedList` that implements a doubly linked list. This data structure consists of nodes where each node contains data and pointers to both the next and previous nodes. The class provides methods for insertion, deletion, traversal, and other common operations on doubly linked lists.

## Class: `DoublyLinkedList<T>`

### Description
The `DoublyLinkedList<T>` class is a template class that represents a doubly linked list. It provides methods to manipulate the list, including insertion, deletion, traversal, and other utility functions.

### Template Parameters
- `T`: The type of elements stored in the list.

### Constructors and Destructors

#### `DoublyLinkedList()`
- **Description**: Default constructor. Initializes an empty doubly linked list.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  ```

#### `DoublyLinkedList(const DoublyLinkedList<T>& other)`
- **Description**: Copy constructor. Initializes a new doubly linked list by copying elements from another list.
- **Parameters**:
  - `other`: The `DoublyLinkedList` object to copy from.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list1;
  // Insert elements into list1
  DoublyLinkedList<int> list2(list1);
  ```

#### `~DoublyLinkedList()`
- **Description**: Destructor. Cleans up the list by deleting all nodes.
- **Usage**: Automatically called when the object goes out of scope.

### Getter and Setter Methods

#### `DoubleNode<T>* GetFirst() const`
- **Description**: Returns a pointer to the first node in the list.
- **Return Value**: A pointer to the first `DoubleNode<T>`.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertFront(10);
  DoubleNode<int>* firstNode = list.GetFirst();
  ```

#### `DoubleNode<T>* GetLast() const`
- **Description**: Returns a pointer to the last node in the list.
- **Return Value**: A pointer to the last `DoubleNode<T>`.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(20);
  DoubleNode<int>* lastNode = list.GetLast();
  ```

#### `void SetFirst(DoubleNode<T>* node)`
- **Description**: Sets the first node of the list.
- **Parameters**:
  - `node`: A pointer to the `DoubleNode<T>` to set as the first node.
- **Usage**:
  ```cpp
  DoubleNode<int>* node = new DoubleNode<int>(10);
  DoublyLinkedList<int> list;
  list.SetFirst(node);
  ```

#### `void SetLast(DoubleNode<T>* node)`
- **Description**: Sets the last node of the list.
- **Parameters**:
  - `node`: A pointer to the `DoubleNode<T>` to set as the last node.
- **Usage**:
  ```cpp
  DoubleNode<int>* node = new DoubleNode<int>(20);
  DoublyLinkedList<int> list;
  list.SetLast(node);
  ```

### Iterator Methods

#### `DLIterator<T> begin() const`
- **Description**: Returns an iterator pointing to the first node in the list.
- **Return Value**: A `DLIterator<T>` object.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  DLIterator<int> it = list.begin();
  ```

#### `DLIterator<T> end() const`
- **Description**: Returns an iterator pointing to the end of the list (nullptr).
- **Return Value**: A `DLIterator<T>` object.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  DLIterator<int> it = list.end();
  ```

### Element Access

#### `Node<T>* Get(int i)`
- **Description**: Returns a pointer to the ith element in the list.
- **Parameters**:
  - `i`: The index of the element to retrieve.
- **Return Value**: A pointer to the `Node<T>` at the ith position.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  Node<int>* node = list.Get(1);  // Retrieves the second element (20)
  ```

### Insertion Methods

#### `void InsertFront(const T& e)`
- **Description**: Inserts an element at the front of the list.
- **Parameters**:
  - `e`: The element to insert.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertFront(10);
  ```

#### `void InsertBack(const T& e)`
- **Description**: Inserts an element at the end of the list.
- **Parameters**:
  - `e`: The element to insert.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(20);
  ```

#### `void Insert(int i, T e)`
- **Description**: Inserts an element at the ith position in the list.
- **Parameters**:
  - `i`: The index at which to insert the element.
  - `e`: The element to insert.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(30);
  list.Insert(1, 20);  // Inserts 20 at the second position
  ```

### Deletion Methods

#### `void DeleteFront()`
- **Description**: Deletes the element at the front of the list.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertFront(10);
  list.DeleteFront();  // Removes 10
  ```

#### `void DeleteBack()`
- **Description**: Deletes the element at the end of the list.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(20);
  list.DeleteBack();  // Removes 20
  ```

#### `void Delete(int i)`
- **Description**: Deletes the element at the ith position in the list.
- **Parameters**:
  - `i`: The index of the element to delete.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.InsertBack(30);
  list.Delete(1);  // Removes the second element (20)
  ```

### Other Functions

#### `int Length() const`
- **Description**: Returns the number of elements in the list.
- **Return Value**: The length of the list as an integer.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  int len = list.Length();  // len is 2
  ```

#### `void Concatenate(DoublyLinkedList<T>& b)`
- **Description**: Concatenates another doubly linked list to the current list.
- **Parameters**:
  - `b`: The `DoublyLinkedList` to concatenate.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2.InsertBack(20);
  list1.Concatenate(list2);  // list1 now contains 10 and 20
  ```

#### `void Reverse()`
- **Description**: Reverses the order of elements in the list.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.Reverse();  // List is now 20, 10
  ```

#### `bool IsEmpty() const`
- **Description**: Checks if the list is empty.
- **Return Value**: `true` if the list is empty, `false` otherwise.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  bool empty = list.IsEmpty();  // empty is true
  ```

### Overloaded Operators

#### `DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other)`
- **Description**: Assignment operator. Assigns the contents of another list to this list.
- **Parameters**:
  - `other`: The `DoublyLinkedList` to assign from.
- **Return Value**: A reference to the current list.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2 = list1;  // list2 now contains 10
  ```

#### `bool operator==(const DoublyLinkedList<T>& other) const`
- **Description**: Equality operator. Checks if two lists are equal.
- **Parameters**:
  - `other`: The `DoublyLinkedList` to compare with.
- **Return Value**: `true` if the lists are equal, `false` otherwise.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2.InsertBack(10);
  bool equal = (list1 == list2);  // equal is true
  ```

#### `bool operator!=(const DoublyLinkedList<T>& other) const`
- **Description**: Inequality operator. Checks if two lists are not equal.
- **Parameters**:
  - `other`: The `DoublyLinkedList` to compare with.
- **Return Value**: `true` if the lists are not equal, `false` otherwise.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2.InsertBack(20);
  bool notEqual = (list1 != list2);  // notEqual is true
  ```

#### `template <typename U> friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<U>& list)`
- **Description**: Overloaded `<<` operator for printing the list.
- **Parameters**:
  - `out`: The output stream.
  - `list`: The `DoublyLinkedList` to print.
- **Return Value**: The output stream.
- **Usage**:
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  std::cout << list;  // Prints the list
  ```

## Example Usage

```cpp
#include "DoublyLinkedList.hpp"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;
    list.InsertBack(10);
    list.InsertBack(20);
    list.InsertFront(5);

    std::cout << "List: " << list << std::endl;  // Output: 5 10 20
    std::cout << "Length: " << list.Length() << std::endl;  // Output: 3

    list.DeleteBack();
    std::cout << "After DeleteBack: " << list << std::endl;  // Output: 5 10

    list.Reverse();
    std::cout << "After Reverse: " << list << std::endl;  // Output: 10 5

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Empty List Operations**: Calling `DeleteFront()`, `DeleteBack()`, or `Delete(int i)` on an empty list may result in undefined behavior. Ensure the list is not empty before performing these operations.
2. **Index Out of Bounds**: When using `Get(int i)` or `Delete(int i)`, ensure the index is within the bounds of the list to avoid accessing invalid memory.
3. **Memory Management**: Ensure proper memory management when dealing with nodes to avoid memory leaks.

## Dependencies

- `DoubleNode.hpp`: Defines the node structure used in the list.
- `DLIterator.hpp`: Provides iterator functionality for the list.

Ensure these files are included and properly configured in your project to use `DoublyLinkedList.hpp`.
