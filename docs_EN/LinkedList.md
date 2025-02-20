# `LinkedList.hpp` Documentation

## Overview

The `LinkedList.hpp` header file defines a templated `LinkedList` class, which represents a singly or doubly linked list (depending on the implementation of `Node`). The class provides various methods for performing linked list operations such as insertion, deletion, and traversal. It also includes support for concatenating lists, reversing lists, and other utility methods.

---

## Key Components

### `LinkedList` Class

The `LinkedList` class is a generic class that implements the core functionality of a linked list, such as adding and removing nodes, traversing the list, and manipulating the data.

#### Member Variables:
- **`first`**: A pointer to the first node in the list, which is used to manage the linked list.

#### Constructors & Destructor:
- **`LinkedList()`**: Default constructor that initializes an empty linked list.
  
  Example:
  ```cpp
  LinkedList<int> list;  // Creates an empty linked list of integers
  ```

- **`~LinkedList()`**: Destructor that cleans up the resources used by the list.

#### Helper Functions:
- **`SetFirst(Node<T>* node)`**: Sets the `first` node of the list to the provided node pointer.
  
  Example:
  ```cpp
  list.SetFirst(&someNode);  // Sets the first node of the list
  ```

- **`GetFirst()`**: Returns a pointer to the first node in the list.

  Example:
  ```cpp
  Node<int>* firstNode = list.GetFirst();  // Get the first node
  ```

- **`Clear()`**: Clears the list by deleting all nodes.

#### Insertion Functions:
- **`InsertFront(const T& e)`**: Inserts an element `e` at the front of the list.
  
  Example:
  ```cpp
  list.InsertFront(10);  // Insert 10 at the front of the list
  ```

- **`InsertBack(const T& e)`**: Inserts an element `e` at the end of the list.
  
  Example:
  ```cpp
  list.InsertBack(20);  // Insert 20 at the end of the list
  ```

- **`Insert(int i, T e)`**: Inserts an element `e` at the specified position `i` in the list.

  Example:
  ```cpp
  list.Insert(1, 15);  // Insert 15 at position 1
  ```

#### Deletion Functions:
- **`DeleteFront()`**: Deletes the first node from the list.
  
  Example:
  ```cpp
  list.DeleteFront();  // Delete the first node
  ```

- **`DeleteBack()`**: Deletes the last node from the list.
  
  Example:
  ```cpp
  list.DeleteBack();  // Delete the last node
  ```

- **`Delete(int i)`**: Deletes the node at position `i` in the list.

  Example:
  ```cpp
  list.Delete(2);  // Delete the node at position 2
  ```

#### Traversal and Retrieval:
- **`begin()`**: Returns an iterator (`ChainIterator`) to the first element of the list.
  
  Example:
  ```cpp
  ChainIterator<int> it = list.begin();  // Get the iterator to the first element
  ```

- **`end()`**: Returns an iterator to the end of the list (past the last element).
  
  Example:
  ```cpp
  ChainIterator<int> endIt = list.end();  // Get the iterator to the end of the list
  ```

- **`Get(int i)`**: Returns a pointer to the `i`-th node in the list.
  
  Example:
  ```cpp
  Node<int>* node = list.Get(2);  // Get the node at position 2
  ```

- **`GetSublist(int i, int j)`**: Returns a sublist from index `i` to index `j` (both included).
  
  Example:
  ```cpp
  LinkedList<int> sublist = list.GetSublist(1, 3);  // Get a sublist from index 1 to 3
  ```

#### Other Functions:
- **`IsEmpty()`**: Returns `true` if the list is empty, otherwise `false`.
  
  Example:
  ```cpp
  bool empty = list.IsEmpty();  // Check if the list is empty
  ```

- **`Length()`**: Returns the length of the list (number of elements).
  
  Example:
  ```cpp
  int len = list.Length();  // Get the length of the list
  ```

- **`Concatenate(LinkedList<T>& b)`**: Concatenates the current list with another list `b`.
  
  Example:
  ```cpp
  list.Concatenate(otherList);  // Concatenate two lists
  ```

- **`Reverse()`**: Reverses the order of the elements in the list.
  
  Example:
  ```cpp
  list.Reverse();  // Reverse the list
  ```

#### Operator Overloads:
- **`operator=(const LinkedList<T>& other)`**: Assignment operator to copy another list into the current list.
  
  Example:
  ```cpp
  list = otherList;  // Copy the contents of otherList to list
  ```

- **`operator==(const LinkedList<T>& other) const`**: Checks if two lists are equal (i.e., have the same elements in the same order).
  
  Example:
  ```cpp
  if (list == otherList) {
      // Lists are equal
  }
  ```

- **`operator!=(const LinkedList<T>& other) const`**: Checks if two lists are not equal.

  Example:
  ```cpp
  if (list != otherList) {
      // Lists are not equal
  }
  ```

- **`operator<<(std::ostream& out, const LinkedList<T>& list)`**: Overloads the `<<` operator to print the contents of the list.
  
  Example:
  ```cpp
  std::cout << list;  // Print the linked list to the console
  ```

---

## Example Usage

```cpp
#include "LinkedList.hpp"

int main() {
    LinkedList<int> list;

    // Insert elements at the front and back
    list.InsertFront(10);   // List: 10
    list.InsertBack(20);    // List: 10, 20

    // Print the list
    std::cout << "List after insertions: " << list << std::endl;

    // Delete elements from the front and back
    list.DeleteBack();      // List: 10
    list.DeleteFront();     // List: (empty)

    // Check if the list is empty
    std::cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << std::endl;

    // Concatenate two lists
    LinkedList<int> list2;
    list2.InsertBack(20);
    list2.InsertBack(30);
    list.Concatenate(list2);  // List: 20, 30

    // Print concatenated list
    std::cout << "Concatenated List: " << list << std::endl;

    return 0;
}
```

### Explanation:
- A linked list is created, and elements are inserted both at the front and back.
- Elements are then deleted from both ends, demonstrating basic insertion and deletion operations.
- The `IsEmpty()` method checks if the list is empty after deletions.
- Two linked lists are concatenated, and the result is printed.

---

## Potential Errors & Edge Cases

1. **Index Out of Bounds**: When using `Get(int i)`, ensure that the index `i` is valid (i.e., within the bounds of the list). Invalid indices should be handled gracefully.

2. **Empty List Operations**: Calling `DeleteFront()` or `DeleteBack()` on an empty list could lead to undefined behavior. Always check if the list is empty before performing delete operations.

3. **Memory Management**: Ensure that memory management (especially in the destructor) is properly handled to prevent memory leaks.

---

## Dependencies

- **`Node.hpp`**: The `LinkedList` class relies on the `Node<T>` class for representing individual elements in the list. Ensure that `Node<T>` is defined and includes necessary fields like `next` pointers.
- **`ChainIterator.hpp`**: The `LinkedList` class uses the `ChainIterator` class for traversing the list. Ensure that `ChainIterator<T>` is correctly implemented.
