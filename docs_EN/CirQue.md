# `CirQue.hpp` Documentation

## Overview

The `CirQue.hpp` file defines a `CirQue` class template that represents a circular queue, which is a type of data structure where the first element follows the last element. This class allows for insertion and removal of elements from both the front and back of the queue, while maintaining the circular nature of the structure. The queue supports various operations, such as checking its size, checking if it's empty, and accessing its front and back elements.

---

## Key Components

### `CirQue` Class

The `CirQue` class represents a circular queue that inherits from the `DeQue` class. It uses a `std::variant` to store elements of mixed types, such as integers, floating-point numbers, strings, and even more complex types like `GeneralArray`, `Polynomial`, `SparseMatrix`, and `String`.

#### Member Variables:
- **`front`**: The index of the first valid element in the queue.
- **`rear`**: The index of the last valid element in the queue.
- **`count`**: The current size of the queue (i.e., the number of elements in the queue).

#### Constructors & Destructor:
- **`CirQue(int capacity = 10)`**: Initializes the circular queue with a given capacity (default is 10). It sets up the queue with an empty state (front = -1, rear = -1, and count = 0).
  
  Example:
  ```cpp
  CirQue<int> queue(10);  // Creates a circular queue with capacity 10 for integers
  ```

- **`~CirQue()`**: Destructor that cleans up any dynamically allocated memory used by the queue.

#### Manipulation Functions:
- **`PushFront(const T& x)`**: Inserts an element `x` at the front of the queue. If the queue is full, it may overwrite the oldest elements.
  
  Example:
  ```cpp
  queue.PushFront(5);  // Insert 5 at the front of the queue
  ```

- **`PushBack(const T& x)`**: Inserts an element `x` at the back of the queue. If the queue is full, it may overwrite the oldest elements.
  
  Example:
  ```cpp
  queue.PushBack(10);  // Insert 10 at the back of the queue
  ```

- **`PopFront()`**: Removes the element at the front of the queue.

  Example:
  ```cpp
  queue.PopFront();  // Removes the front element from the queue
  ```

- **`PopBack()`**: Removes the element at the back of the queue.

  Example:
  ```cpp
  queue.PopBack();  // Removes the back element from the queue
  ```

#### Getter Functions:
- **`Front()`**: Returns the front element of the queue without removing it.
  
  Example:
  ```cpp
  int frontElement = queue.Front();  // Get the front element (does not remove it)
  ```

- **`Back()`**: Returns the back element of the queue without removing it.
  
  Example:
  ```cpp
  int backElement = queue.Back();  // Get the back element (does not remove it)
  ```

#### Properties:
- **`IsEmpty()`**: Returns `true` if the queue is empty, otherwise `false`.

  Example:
  ```cpp
  bool empty = queue.IsEmpty();  // Check if the queue is empty
  ```

- **`Size()`**: Returns the number of elements in the queue (i.e., the current size).

  Example:
  ```cpp
  int size = queue.Size();  // Get the current size of the queue
  ```

#### Operator Overloads:
- **`operator<<`**: Overloads the stream insertion (`<<`) operator to print the elements of the queue in a readable format.
  
  Example:
  ```cpp
  std::cout << queue;  // Prints the elements of the queue
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `CirQue` class:

```cpp
#include "CirQue.hpp"
#include <iostream>

int main() {
    // Create a circular queue for integers with a capacity of 5
    CirQue<int> queue(5);

    // Insert elements at the front and back of the queue
    queue.PushBack(10);    // Queue: 10
    queue.PushFront(20);   // Queue: 20, 10

    // Print the queue
    std::cout << "Queue after insertions: " << queue << std::endl;

    // Get the front and back elements
    std::cout << "Front: " << queue.Front() << std::endl;  // Front: 20
    std::cout << "Back: " << queue.Back() << std::endl;    // Back: 10

    // Remove the front element
    queue.PopFront();  // Queue: 10

    // Print the queue after removing the front element
    std::cout << "Queue after PopFront: " << queue << std::endl;

    // Remove the back element
    queue.PopBack();  // Queue: (empty)

    // Print the queue after removing the back element
    std::cout << "Queue after PopBack: " << queue << std::endl;

    // Check if the queue is empty
    std::cout << "Is the queue empty? " << (queue.IsEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

### Explanation:
- The code creates a circular queue of integers with a capacity of 5.
- Elements are inserted both at the front and back, and the queue is printed after each operation.
- The `Front()` and `Back()` methods are used to retrieve the front and back elements.
- Elements are then removed from both the front and back of the queue, and the queue's state is printed after each operation.
- The `IsEmpty()` method is used to check if the queue is empty after the operations.

---

## Potential Errors & Edge Cases

1. **Full Queue**: When the queue is full and an attempt is made to insert a new element, it may overwrite existing elements depending on how the circular queue is implemented. Be mindful of this behavior when performing insertions in a full queue.

2. **Empty Queue Operations**: Ensure that operations like `PopFront()` and `PopBack()` handle cases where the queue is empty. Calling these operations on an empty queue should not result in undefined behavior.

   Example:
   ```cpp
   if (!queue.IsEmpty()) {
       queue.PopFront();
   }
   ```

3. **Indexing Errors**: Ensure that the `front`, `rear`, and `count` variables are properly updated after each insertion and removal operation to maintain the correct state of the queue.

---

## Dependencies

- **`DeQue.hpp`**: The `CirQue` class inherits from the `DeQue` class, so ensure that the `DeQue` class is correctly defined and includes methods for handling a double-ended queue (or supports basic queue operations).
- **C++ Standard Library**: The class uses `std::variant` to store various types of elements and relies on standard C++ libraries such as `<iostream>` for input/output operations.
