# CircularDoubleList Documentation

## Overview
The `CircularDoubleList` class is a circular doubly linked list implementation that extends the functionality of the `DoublyLinkedList` class. It supports operations such as insertion, deletion, concatenation, reversal, and traversal in a circular doubly linked list structure.

## Features
- Supports bidirectional traversal
- Ensures circular linkage after each operation
- Allows insertion and deletion at the front and back
- Implements operator overloads for easy usage
- Maintains memory integrity through copy and assignment operations

## API Reference

### Constructors & Destructor
```cpp
CircularDoubleList();
```
Creates an empty circular doubly linked list.

```cpp
CircularDoubleList(const CircularDoubleList<T>& other);
```
Creates a deep copy of another `CircularDoubleList` object.

```cpp
~CircularDoubleList();
```
Destroys the circular doubly linked list and frees memory.

### Assignment Operator
```cpp
CircularDoubleList<T>& operator=(const CircularDoubleList<T>& other);
```
Assigns the contents of another `CircularDoubleList` object.

### Insertion Methods
```cpp
void InsertFront(const T& e);
```
Inserts an element `e` at the front of the list while maintaining circular linkage.

```cpp
void InsertBack(const T& e);
```
Inserts an element `e` at the back of the list while maintaining circular linkage.

### Deletion Methods
```cpp
void DeleteFront();
```
Deletes the front element while maintaining circular linkage.

```cpp
void DeleteBack();
```
Deletes the last element while maintaining circular linkage.

### List Operations
```cpp
void Concatenate(CircularDoubleList<T>& b);
```
Concatenates another circular doubly linked list `b` to the current list.

```cpp
void Reverse() override;
```
Reverses the order of elements in the circular doubly linked list.

```cpp
int Length() override;
```
Returns the number of elements in the list.

### Overloaded Operators
```cpp
friend std::ostream& operator<<(std::ostream& os, const CircularDoubleList<T>& list);
```
Overloads `<<` for easy output of the list contents.

## Example Usage

### Creating and Using a CircularDoubleList
```cpp
#include "CircularDoubleList.hpp"
#include <iostream>

int main() {
    CircularDoubleList<int> list;

    // Insert elements
    list.InsertBack(10);
    list.InsertBack(20);
    list.InsertBack(30);
    list.InsertFront(5);

    // Display list
    std::cout << "List: " << list << std::endl;

    // Delete elements
    list.DeleteFront();
    list.DeleteBack();

    // Display list after deletion
    std::cout << "After Deletion: " << list << std::endl;

    // Reverse the list
    list.Reverse();
    std::cout << "After Reversal: " << list << std::endl;

    // Get length
    std::cout << "Length: " << list.Length() << std::endl;

    // Concatenation
    CircularDoubleList<int> anotherList;
    anotherList.InsertBack(100);
    anotherList.InsertBack(200);
    list.Concatenate(anotherList);
    std::cout << "After Concatenation: " << list << std::endl;

    return 0;
}
```

## Notes
- The class ensures circular linkage after every modification.
- Users should be cautious when performing operations on an empty list.
- The copy constructor and assignment operator correctly handle memory allocation to prevent shallow copies.
