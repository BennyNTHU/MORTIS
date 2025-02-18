# MinHeap Documentation

## Overview
The `MinHeap` class is a data structure that maintains a **binary heap** with the **minimum element at the root**. It extends `MaxHeap`, but swaps the comparison logic so that smaller elements are prioritized.

### Features:
- Insert elements while maintaining heap order
- Remove the smallest element (root)
- Supports rebalancing through heapify operations
- Implements a **binary tree structure** with heap properties

---

## Class Definition
```cpp
template <class T>
class MinHeap : public MaxHeap<T> {
public:
    // Constructor
    MinHeap(const T& rootData);
    
    // Destructor
    ~MinHeap();

    // Maintain the heap property
    void heapify_up(int index);
    void heapify_down(int index);
};
```

---

## Constructors and Destructors

### `MinHeap(const T& rootData)`
**Description:**  
Creates a min-heap with a **single root node** containing `rootData`.

**Usage:**
```cpp
MinHeap<int> heap(10);  // Creates a min-heap with root value 10
```

---

### `~MinHeap()`
**Description:**  
Destructor for the heap. It **cleans up all allocated nodes**.

**Usage:**  
This is automatically called when the object goes out of scope.

---

## Public Methods

### `void heapify_up(int index)`
**Description:**  
Moves a node **up** the heap to restore the min-heap property.

**Usage:**  
This is automatically called inside `Push()` when inserting a new value.

```cpp
MinHeap<int> heap(5);
heap.Push(3); // heapify_up is triggered internally
heap.Push(7);
```

---

### `void heapify_down(int index)`
**Description:**  
Moves a node **down** the heap to restore the min-heap property.

**Usage:**  
This is automatically called inside `Pop()` when removing the root.

```cpp
MinHeap<int> heap(5);
heap.Push(3);
heap.Push(7);
heap.Pop(); // heapify_down is triggered internally
```

---

## Example Program

```cpp
#include <iostream>
#include "MinHeap.hpp"

int main() {
    // Create a min-heap with root 15
    MinHeap<int> heap(15);
    
    // Insert elements
    heap.Push(10);
    heap.Push(20);
    heap.Push(5);
    heap.Push(30);
    heap.Push(2);
    
    // Display the minimum element
    std::cout << "Minimum: " << heap.Top() << std::endl; // Should print 2

    // Remove the smallest element
    heap.Pop();
    std::cout << "New Minimum after Pop: " << heap.Top() << std::endl; // Should print 5

    return 0;
}
```

---

## Summary
- `MinHeap` extends `MaxHeap`, reversing the comparison logic.
- **Push()** inserts a value and maintains heap order.
- **Pop()** removes the smallest value and reorders the heap.
- **heapify_up()** and **heapify_down()** are internal functions for balancing.
