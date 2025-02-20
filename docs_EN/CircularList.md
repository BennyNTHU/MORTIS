# `CircularList.hpp` Documentation

## Overview

The `CircularList.hpp` header file defines a templated `CircularList` class that extends from a basic `LinkedList`. This class provides methods for managing a circular linked list, where the last node links back to the first. It includes common linked list operations like insertion, deletion, and concatenation, while maintaining the circular structure.

---

## Key Components

### `CircularList` Class

The `CircularList` class extends from the `LinkedList` class, inheriting basic linked list functionality while adding features specific to circular linked lists, such as maintaining the circular structure when nodes are inserted or deleted.

#### Member Variables:
- Inherits from `LinkedList<T>`, which likely contains the basic structure and data members of a linked list such as a pointer to the first node.

#### Constructors & Destructor:
- **`CircularList()`**: Default constructor that initializes an empty circular list.
- **`CircularList(const CircularList<T>& other)`**: Copy constructor that initializes a new `CircularList` from an existing one.
- **`~CircularList()`**: Destructor to properly clean up the resources used by the circular linked list.

#### Member Functions:
- **`Length() const`**: Returns the number of elements in the circular list.

  Example:
  ```cpp
  int len = list.Length();  // Get the length of the circular list
  ```

- **`IsEmpty() const`**: Returns `true` if the circular list is empty, otherwise `false`.

  Example:
  ```cpp
  bool isEmpty = list.IsEmpty();  // Check if the list is empty
  ```

- **`InsertBack(const T& e)`**: Inserts an element at the back of the circular list, ensuring the list maintains its circular structure.

  Example:
  ```cpp
  list.InsertBack(10);  // Insert 10 at the end of the circular list
  ```

- **`InsertFront(const T& e)`**: Inserts an element at the front of the circular list, ensuring the list maintains its circular structure.

  Example:
  ```cpp
  list.InsertFront(5);  // Insert 5 at the front of the circular list
  ```

- **`DeleteBack()`**: Deletes the last element in the circular list while maintaining the circular structure.

  Example:
  ```cpp
  list.DeleteBack();  // Delete the last element from the circular list
  ```

- **`DeleteFront()`**: Deletes the first element in the circular list while maintaining the circular structure.

  Example:
  ```cpp
  list.DeleteFront();  // Delete the first element from the circular list
  ```

- **`Concatenate(CircularList<T>& b)`**: Concatenates two circular lists into a single list, maintaining the circular structure.

  Example:
  ```cpp
  list.Concatenate(otherList);  // Concatenate two circular lists
  ```

#### Operator Overloads:
- **`operator=(const CircularList<T>& other)`**: Assignment operator to copy data from another `CircularList` to the current one.

  Example:
  ```cpp
  list = otherList;  // Copy the contents of otherList to list
  ```

- **`operator==(const CircularList<T>& other) const`**: Checks if two circular lists are equal (i.e., have the same elements and circular structure).

  Example:
  ```cpp
  if (list == otherList) {
      // Do something
  }
  ```

- **`operator!=(const CircularList<T>& other) const`**: Checks if two circular lists are not equal.

  Example:
  ```cpp
  if (list != otherList) {
      // Do something
  }
  ```

- **`operator<<(std::ostream& out, const CircularList<T>& list)`**: Overloads the `<<` operator to print the circular list. This function is a friend function, allowing access to private members of `CircularList`.

  Example:
  ```cpp
  std::cout << list;  // Print the circular list using the overloaded << operator
  ```

---

## Example Usage

```cpp
#include "CircularList.hpp"

int main() {
    // Create a CircularList of integers
    CircularList<int> list;

    // Insert elements at the front and back
    list.InsertBack(10);   // List: 10
    list.InsertFront(5);   // List: 5, 10

    // Print the list
    std::cout << "List after insertions: " << list << std::endl;

    // Delete elements from the front and back
    list.DeleteBack();     // List: 5
    list.DeleteFront();    // List: (empty)

    // Check if the list is empty
    std::cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << std::endl;

    // Concatenate two circular lists
    CircularList<int> list2;
    list2.InsertBack(20);
    list2.InsertBack(30);
    list.Concatenate(list2);  // List: (previous elements) 20, 30

    // Print concatenated list
    std::cout << "Concatenated List: " << list << std::endl;

    return 0;
}
```

### Explanation:
- A circular list is created, and elements are inserted both at the front and back.
- Elements are then deleted from both ends, demonstrating the circular nature of the list.
- The `IsEmpty()` method is used to check if the list is empty after deletions.
- Two circular lists are concatenated and printed.

---

## Potential Errors & Edge Cases

1. **Empty List Operations**: Calling `DeleteFront()` or `DeleteBack()` on an empty list could lead to undefined behavior. Ensure that the list is not empty before performing delete operations.
   Example check before deletion:
   ```cpp
   if (!list.IsEmpty()) {
       list.DeleteBack();
   }
   ```

2. **Circular Structure Corruption**: It is crucial that all insertions and deletions maintain the circular structure. Make sure that the last node always points back to the first node after performing insertions or deletions.

3. **Concatenation**: The `Concatenate()` method assumes that both lists being concatenated are valid circular lists. Ensure that the lists are properly initialized and contain elements before concatenation.

---

## Dependencies

- **`LinkedList.hpp`**: The `CircularList` class extends the `LinkedList` class, so ensure that the `LinkedList` class is correctly defined and implemented.
- **C++ Standard Library**: The class relies on the standard C++ libraries such as `<iostream>` for input/output operations.
