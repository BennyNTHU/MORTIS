# LinkedList Class Documentation

## Overview
The **LinkedList** class is a template-based singly linked list implementation in C++. It provides essential operations such as insertion, deletion, traversal, concatenation, and reversal. It also supports iterators via the **ChainIterator** class for easy element traversal.

---

## Features
- Insert elements at the front, back, or a specific index
- Delete elements from the front, back, or a specific index
- Retrieve an element at a specific index
- Concatenate two linked lists
- Reverse the linked list
- Iterator support for traversing the list

---

## Header File
```cpp
#include "LinkedList.hpp"
```

---

## API Reference

### 1. **Constructor & Destructor**
```cpp
LinkedList();              // Default constructor
LinkedList(const LinkedList<T>& other); // Copy constructor
~LinkedList();             // Destructor
```
#### Example:
```cpp
LinkedList<int> list1;
LinkedList<int> list2(list1); // Copy constructor
```

### 2. **Insertion Operations**
```cpp
void InsertFront(const T& e);  // Insert an element at the front
void InsertBack(const T& e);   // Insert an element at the back
void Insert(int index, T e);   // Insert an element at a specific index
```
#### Example:
```cpp
LinkedList<int> list;
list.InsertFront(10);
list.InsertBack(20);
list.Insert(1, 15);
```

### 3. **Deletion Operations**
```cpp
void DeleteFront();  // Remove the first element
void DeleteBack();   // Remove the last element
void Delete(int index); // Remove element at a specific index
```
#### Example:
```cpp
list.DeleteFront();
list.DeleteBack();
list.Delete(1);
```

### 4. **Access Elements**
```cpp
T Get(int index);  // Get element at a specific index
```
#### Example:
```cpp
int val = list.Get(1);
std::cout << "Element at index 1: " << val << std::endl;
```

### 5. **Concatenation**
```cpp
void Concatenate(LinkedList<T>& other);  // Append another linked list
```
#### Example:
```cpp
LinkedList<int> list1;
list1.InsertBack(10);
list1.InsertBack(20);

LinkedList<int> list2;
list2.InsertBack(30);
list2.InsertBack(40);

list1.Concatenate(list2); // list1 now contains 10, 20, 30, 40
```

### 6. **Reversing the List**
```cpp
void Reverse();
```
#### Example:
```cpp
list.Reverse();
```

### 7. **Iterators**
```cpp
ChainIterator<T> begin() const;  // Return iterator to first node
ChainIterator<T> end() const;    // Return iterator to null node
```
#### Example:
```cpp
for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << " -> ";
}
```

### 8. **Operator Overloading**
```cpp
LinkedList<T>& operator=(const LinkedList<T>& other);  // Assignment operator
friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list);
```
#### Example:
```cpp
LinkedList<int> list1, list2;
list1.InsertBack(5);
list2 = list1; // Using overloaded assignment operator
std::cout << list2; // Prints the list
```

---

## Complete Example Program
```cpp
#include <iostream>
#include "LinkedList.hpp"

int main() {
    LinkedList<int> list;

    // Insert elements
    list.InsertFront(1);
    list.InsertBack(2);
    list.Insert(1, 3);

    // Print list
    std::cout << "List after insertions: " << list << std::endl;

    // Delete elements
    list.DeleteFront();
    list.DeleteBack();
    std::cout << "List after deletions: " << list << std::endl;

    // Reverse the list
    list.Reverse();
    std::cout << "Reversed List: " << list << std::endl;

    return 0;
}
```

---

## Conclusion
The **LinkedList** class provides a robust and easy-to-use interface for managing a singly linked list. By utilizing **ChainIterator**, traversing the list becomes efficient and readable. This class is ideal for cases where dynamic data structures are needed.
