# `MinHeap.hpp` Documentation

## Overview

The `MinHeap.hpp` file defines a `MinHeap` class template that extends the `MaxHeap` class. It provides functionality for maintaining a min-heap data structure, where each parent node is smaller than or equal to its children. The class overrides the heapify methods to ensure that the min-heap property is maintained during insertion and removal of elements.

---

## Key Components

### `MinHeap` Class

The `MinHeap` class inherits from the `MaxHeap` class and modifies the heapify operations to maintain the min-heap property. The class uses a vector to store the heap elements and supports basic heap operations like insertion, removal, and maintaining the heap structure.

#### Constructors & Destructor

- **`MinHeap(const T& rootData)`**: Constructor that initializes the min-heap with the specified root data. It creates the root node and initializes the heap with the provided value.

  Example:
  ```cpp
  MinHeap<int> minHeap(10);  // Creates a min-heap with root value 10
  ```

- **`~MinHeap()`**: Destructor that cleans up the min-heap and deallocates memory used by the nodes.

  Example:
  ```cpp
  // Automatically cleans up the min-heap when it goes out of scope
  ```

---

### Heapify Methods

The `MinHeap` class overrides the heapify methods from the `MaxHeap` class to ensure that the heap maintains the min-heap property, where the parent is smaller than its children.

- **`void heapify_up(int index)`**: This method ensures the min-heap property by moving the node at the specified `index` upwards until the parent is smaller or equal to the child node. This method is called when inserting a new element into the heap.

  Example:
  ```cpp
  minHeap.heapify_up(3);  // Restore the min-heap property for the node at index 3
  ```

- **`void heapify_down(int index)`**: This method ensures the min-heap property by moving the node at the specified `index` downwards until the min-heap property is satisfied. This method is called when removing the root or rearranging the heap after an operation.

  Example:
  ```cpp
  minHeap.heapify_down(0);  // Restore the min-heap property for the root node
  ```

---

### Dependencies

- **`MaxHeap.hpp`**: The `MinHeap` class inherits from the `MaxHeap` class. Ensure that the `MaxHeap` class is properly implemented and available for the `MinHeap` class to work correctly.
- **`BinaryTree.hpp`**: The class uses binary tree operations, so the `BinaryTree` class is required for managing the binary structure of the heap.

---

### Example Usage

Here’s an example demonstrating how to use the `MinHeap` class:

```cpp
#include "MinHeap.hpp"
#include <iostream>

int main() {
    // Create a MinHeap with an initial root value of 10
    MinHeap<int> minHeap(10);

    // Push elements into the MinHeap
    minHeap.Push(5);   // Insert 5 into the heap
    minHeap.Push(20);  // Insert 20 into the heap
    minHeap.Push(3);   // Insert 3 into the heap

    // Pop the minimum element (root) from the heap
    minHeap.Pop();  // Removes 3, which is the minimum

    // Print the root element after the pop
    std::cout << "New root after Pop: " << minHeap.GetRootData() << std::endl;

    return 0;
}
```

### Explanation:
- The code demonstrates creating a `MinHeap` with an initial root value of 10.
- It inserts several elements into the min-heap using the `Push` method.
- The root element (the minimum) is removed using the `Pop` method, and the new root is printed to show the heap's state after the pop.

---

## Potential Errors & Edge Cases

1. **Heap Underflow**: Calling `Pop()` on an empty heap could result in undefined behavior. Ensure that the heap is not empty before attempting to remove an element. You can add a check for emptiness before calling `Pop()`.

   Example:
   ```cpp
   if (!minHeap.IsEmpty()) {
       minHeap.Pop();
   }
   ```

2. **Heap Property Violations**: After inserting or removing elements, ensure that the heapify operations (`heapify_up` and `heapify_down`) are properly called to restore the heap property.

3. **Invalid Indices**: When calling `heapify_up` or `heapify_down`, ensure that the `index` provided is valid and within the bounds of the heap.
