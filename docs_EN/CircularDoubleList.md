# CircularDoubleList.hpp Documentation

## Overview

The `CircularDoubleList.hpp` header file defines a template class `CircularDoubleList` that implements a circular doubly linked list. This class inherits from `DoublyLinkedList` and provides additional functionality to maintain the circular property of the list. The circular doubly linked list is a data structure where each node has pointers to both the next and previous nodes, and the last node points back to the first node, forming a circle.

## Class: `CircularDoubleList<T>`

### Description
The `CircularDoubleList<T>` class is a template class that represents a circular doubly linked list. It provides methods to insert, delete, concatenate, and reverse elements in the list while maintaining the circular property.

### Template Parameters
- `T`: The type of elements stored in the list.

### Constructors and Destructors

#### `CircularDoubleList()`
- **Description**: Default constructor. Initializes an empty circular doubly linked list.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  ```

#### `CircularDoubleList(const CircularDoubleList<T>& other)`
- **Description**: Copy constructor. Initializes a new circular doubly linked list by copying elements from another list.
- **Parameters**:
  - `other`: The `CircularDoubleList` object to copy from.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list1;
  // Insert elements into list1
  CircularDoubleList<int> list2(list1);
  ```

#### `~CircularDoubleList()`
- **Description**: Destructor. Cleans up the list by deleting all nodes.
- **Usage**: Automatically called when the object goes out of scope.

### Operations

#### `void InsertBack(const T& e)`
- **Description**: Inserts an element at the back (end) of the list.
- **Parameters**:
  - `e`: The element to insert.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  ```

#### `void InsertFront(const T& e)`
- **Description**: Inserts an element at the front (beginning) of the list.
- **Parameters**:
  - `e`: The element to insert.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertFront(10);
  list.InsertFront(20);
  ```

#### `void DeleteBack()`
- **Description**: Deletes the element at the back (end) of the list.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.DeleteBack();  // Removes 20
  ```

#### `void DeleteFront()`
- **Description**: Deletes the element at the front (beginning) of the list.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertFront(10);
  list.InsertFront(20);
  list.DeleteFront();  // Removes 20
  ```

#### `void Concatenate(CircularDoubleList<T>& b)`
- **Description**: Concatenates another circular doubly linked list to the current list.
- **Parameters**:
  - `b`: The `CircularDoubleList` to concatenate.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2.InsertBack(20);
  list1.Concatenate(list2);  // list1 now contains 10 and 20
  ```

#### `void Reverse()`
- **Description**: Reverses the order of elements in the list.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.Reverse();  // List is now 20, 10
  ```

### Properties

#### `int Length() const`
- **Description**: Returns the number of elements in the list.
- **Return Value**: The length of the list as an integer.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  int len = list.Length();  // len is 2
  ```

### Overloaded Operators

#### `CircularDoubleList<T>& operator=(const CircularDoubleList<T>& other)`
- **Description**: Assignment operator. Assigns the contents of another list to this list.
- **Parameters**:
  - `other`: The `CircularDoubleList` to assign from.
- **Return Value**: A reference to the current list.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2 = list1;  // list2 now contains 10
  ```

#### `bool operator==(const CircularDoubleList<T>& other) const`
- **Description**: Equality operator. Checks if two lists are equal.
- **Parameters**:
  - `other`: The `CircularDoubleList` to compare with.
- **Return Value**: `true` if the lists are equal, `false` otherwise.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2.InsertBack(10);
  bool equal = (list1 == list2);  // equal is true
  ```

#### `bool operator!=(const CircularDoubleList<T>& other) const`
- **Description**: Inequality operator. Checks if two lists are not equal.
- **Parameters**:
  - `other`: The `CircularDoubleList` to compare with.
- **Return Value**: `true` if the lists are not equal, `false` otherwise.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2.InsertBack(20);
  bool notEqual = (list1 != list2);  // notEqual is true
  ```

#### `template <typename U> friend std::ostream& operator<<(std::ostream& out, const CircularDoubleList<U>& list)`
- **Description**: Overloaded `<<` operator for printing the list.
- **Parameters**:
  - `out`: The output stream.
  - `list`: The `CircularDoubleList` to print.
- **Return Value**: The output stream.
- **Usage**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  std::cout << list;  // Prints the list
  ```

## Example Usage

```cpp
#include "CircularDoubleList.hpp"
#include <iostream>

int main() {
    CircularDoubleList<int> list1;
    list1.InsertBack(10);
    list1.InsertBack(20);
    list1.InsertFront(5);

    CircularDoubleList<int> list2;
    list2.InsertBack(30);
    list2.InsertBack(40);

    list1.Concatenate(list2);
    list1.Reverse();

    std::cout << "List1: " << list1 << std::endl;
    std::cout << "Length of List1: " << list1.Length() << std::endl;

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Empty List Operations**: Calling `DeleteBack()` or `DeleteFront()` on an empty list may result in undefined behavior. Ensure the list is not empty before performing these operations.
2. **Memory Management**: Ensure proper memory management when dealing with large lists to avoid memory leaks.
3. **Circular Property**: Be cautious when manually manipulating the list to maintain the circular property.

## Dependencies

- `DoublyLinkedList.hpp`: Base class for the circular doubly linked list.
- `DoubleNode.hpp`: Defines the node structure used in the list.
- `DLIterator.hpp`: Provides iterator functionality for the list.

Ensure these files are included and properly configured in your project to use `CircularDoubleList.hpp`.
