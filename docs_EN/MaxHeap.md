# `MaxHeap.hpp` Documentation

## Overview

The `MaxHeap.hpp` file defines a `MaxHeap` class, which is a specialized type of binary tree that maintains the heap property (i.e., the value of each parent node is greater than or equal to the values of its children). This class is derived from the `BinaryTree<T>` class and provides methods for inserting and removing elements, as well as maintaining the heap property through `heapify` operations.

The `MaxHeap` is implemented using a vector to store nodes in level-order, and it uses binary tree nodes (`BinaryTreeNode<T>`) to manage the structure.

---

## Key Components

### `MaxHeap` Class

The `MaxHeap` class extends the `BinaryTree<T>` class and provides additional methods and functionality specific to max-heaps, such as maintaining the heap property when adding or removing elements.

#### Member Variables:
- **`nodes`**: A vector that stores the nodes of the heap in level-order (i.e., the root is at index 0, and children are stored in subsequent indices).
  
#### Internal Storage Helper Methods:
- **`getParent(int index)`**: Returns the parent node of the node at the specified index in the heap.
  
- **`GetNodeAtIndex(int index)`**: Returns the node at the specified index in the heap.
  
- **`FindNextAvailableParent()`**: Finds and returns the next available parent node where a new child can be inserted.

---

### Constructors & Destructor

- **`MaxHeap(const T& rootData)`**: Constructor that initializes a max-heap with the specified root data. It creates the root node and initializes the `nodes` vector.

  Example:
  ```cpp
  MaxHeap<int> heap(10);  // Creates a max-heap with root data 10
  ```

- **`~MaxHeap()`**: Destructor that cleans up the heap and deallocates memory used by the nodes.

  Example:
  ```cpp
  // Automatically cleans up the heap when it goes out of scope
  ```

---

### Push & Pop Methods

- **`void Push(const T& value)`**: Inserts a new value into the heap while maintaining the heap property. The value is added at the next available position, and the `heapify_up` method is called to ensure the max-heap property is maintained.

  Example:
  ```cpp
  heap.Push(15);  // Push the value 15 into the max-heap
  ```

- **`void Pop()`**: Removes the maximum element (the root) from the heap. The last element in the heap is moved to the root position, and the `heapify_down` method is called to restore the heap property.

  Example:
  ```cpp
  heap.Pop();  // Remove the maximum element (root) from the heap
  ```

---

### Helper Methods to Maintain Heap Property

- **`void rebuildTreeLinks()`**: Rebuilds the parent-child links in the tree from the array representation. This ensures that the heap structure is correctly maintained after modifications.

  Example:
  ```cpp
  heap.rebuildTreeLinks();  // Rebuild the tree links after modifications
  ```

- **`void heapify_up(int index)`**: A method that restores the heap property by moving the node at the specified `index` upwards until the heap property is satisfied (i.e., the parent is greater than the child).

  Example:
  ```cpp
  heap.heapify_up(3);  // Restore the heap property for the node at index 3
  ```

- **`void heapify_down(int index)`**: A method that restores the heap property by moving the node at the specified `index` downwards until the heap property is satisfied (i.e., the parent is greater than its children).

  Example:
  ```cpp
  heap.heapify_down(0);  // Restore the heap property for the root node
  ```

---

### Level-Order Traversal

- **`std::vector<BinaryTreeNode<T>*> LevelOrderIterator()`**: Returns a vector of nodes in level-order, which is a breadth-first traversal of the tree. This method provides the nodes as `BinaryTreeNode<T>*` pointers.

  Example:
  ```cpp
  auto levelOrderNodes = heap.LevelOrderIterator();  // Get the nodes in level-order
  ```

---

### Disabled `BinaryTree` Functions

The `MaxHeap` class disables certain functions from the `BinaryTree` class that are not applicable to heaps. These methods are deleted to prevent misuse.

- **`void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) = delete;`**
- **`void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) = delete;`**
- **`void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right) = delete;`**
- **`void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left) = delete;`**

These methods are not used in heaps because the insertion of nodes in a heap is handled differently to maintain the heap property.

---

## Example Usage

Here’s an example demonstrating how to use the `MaxHeap` class:

```cpp
#include "MaxHeap.hpp"
#include <iostream>

int main() {
    // Create a max-heap with an initial value of 10
    MaxHeap<int> heap(10);

    // Push elements into the heap
    heap.Push(15);
    heap.Push(20);
    heap.Push(5);

    // Display the elements in level-order
    auto levelOrderNodes = heap.LevelOrderIterator();
    for (auto node : levelOrderNodes) {
        std::cout << node->getData() << " ";  // Print each node's data
    }
    std::cout << std::endl;

    // Pop the maximum element (the root)
    heap.Pop();

    // Display the elements after popping the root
    levelOrderNodes = heap.LevelOrderIterator();
    for (auto node : levelOrderNodes) {
        std::cout << node->getData() << " ";  // Print each node's data after pop
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation:
- The code demonstrates creating a `MaxHeap` with an initial root value of 10.
- Elements are inserted into the heap using the `Push` method, and the heap is printed in level-order using the `LevelOrderIterator` method.
- The maximum element (the root) is removed using the `Pop` method, and the heap is printed again to show the updated structure.

---

## Potential Errors & Edge Cases

1. **Heap Underflow**: Calling `Pop()` on an empty heap could result in undefined behavior. Ensure that the heap is not empty before attempting to remove an element. Consider adding a check for emptiness:

   Example:
   ```cpp
   if (!heap.IsEmpty()) {
       heap.Pop();
   }
   ```

2. **Heap Property Violations**: After modifying the heap (inserting or removing elements), ensure that the `heapify_up` and `heapify_down` methods are properly called to restore the heap property.

3. **Full Heap**: While the class doesn't explicitly handle resizing, it assumes that the heap can grow as needed. If the heap has a fixed size or you wish to limit its growth, implement logic to prevent adding elements once the heap is full.

---

## Dependencies

- **`BinaryTree.hpp`**: The `MaxHeap` class inherits from the `BinaryTree<T>` class, so ensure that the `BinaryTree` class is properly defined and includes basic tree operations like adding and removing nodes.
- **`BinaryTreeNode.hpp`**: This file relies on `BinaryTreeNode<T>` to represent individual nodes in the heap. Ensure that the `BinaryTreeNode<T>` class is correctly defined for managing node data and pointers.
