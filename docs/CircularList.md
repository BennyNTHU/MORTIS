# CircularList API Documentation

## Overview
The `CircularList<T>` class is a **circular linked list** implementation that inherits from `LinkedList<T>`. Unlike a regular linked list, in a circular list, the last node always points back to the first node, forming a closed loop. This structure is useful for buffering, scheduling, and cyclic traversal.

## Features
- Insert elements at the front and back.
- Delete elements from the front and back.
- Concatenate two circular lists.
- Compute the length of the list.
- Iterate over elements using `ChainIterator<T>`.
- Supports deep copying with a copy constructor and assignment operator.

## Header File
```cpp
#include "CircularList.hpp"
```

## Public Methods
### 1. Constructor & Destructor
```cpp
CircularList();  // Default constructor
CircularList(const CircularList<T>& other);  // Copy constructor
~CircularList(); // Destructor
```
**Example:**
```cpp
CircularList<int> list;
CircularList<int> copyList(list);  // Uses the copy constructor
```

### 2. Insert Elements
```cpp
void InsertBack(const T& e);   // Insert an element at the end
void InsertFront(const T& e);  // Insert an element at the beginning
```
**Example:**
```cpp
CircularList<int> list;
list.InsertBack(10);
list.InsertBack(20);
list.InsertFront(5);
// List: 5 -> 10 -> 20 -> (loops back to 5)
```

### 3. Delete Elements
```cpp
void DeleteBack();  // Remove the last element
void DeleteFront(); // Remove the first element
```
**Example:**
```cpp
list.DeleteFront();
list.DeleteBack();
```

### 4. Get List Length
```cpp
int Length(); // Returns the number of elements in the list
```
**Example:**
```cpp
int size = list.Length();  // size = 1
```

### 5. Concatenate Two Circular Lists
```cpp
void Concatenate(CircularList<T>& other); // Appends another list to this list
```
**Example:**
```cpp
CircularList<int> list1;
list1.InsertBack(1);
list1.InsertBack(2);

CircularList<int> list2;
list2.InsertBack(3);
list2.InsertBack(4);

list1.Concatenate(list2);
// List1: 1 -> 2 -> 3 -> 4 -> (loops back to 1)
```

### 6. Iterating Over Elements
You can use a `ChainIterator<T>` to traverse the elements.
```cpp
ChainIterator<T> begin(); // Returns an iterator to the first element
ChainIterator<T> end();   // Returns an iterator past the last element
```
**Example:**
```cpp
ChainIterator<int> it = list.begin();
do {
    std::cout << *it << " ";
    ++it;
} while (it != list.begin());
// Output: 1 2 3 4
```

## Full Example
```cpp
#include <iostream>
#include "CircularList.hpp"

int main() {
    CircularList<int> list;
    list.InsertBack(10);
    list.InsertBack(20);
    list.InsertFront(5);

    std::cout << "List Length: " << list.Length() << std::endl;

    ChainIterator<int> it = list.begin();
    do {
        std::cout << *it << " ";
        ++it;
    } while (it != list.begin());
    std::cout << std::endl;

    return 0;
}
```

## Output
```
List Length: 3
5 10 20
```

