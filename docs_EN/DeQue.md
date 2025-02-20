# `DeQue` Documentation

## Overview

The `DeQue.hpp` header file defines the `DeQue` class template, which represents a double-ended queue. It inherits from the `Bag<T>` class, allowing elements to be added or removed from both the front and back. The `DeQue` class provides various operations such as insertion, removal, and access to the front and back elements of the deque. It is designed to handle various types of data using `std::variant`.

---

## Key Components

### `DeQue` Class

The `DeQue` class implements the double-ended queue (deque) data structure. It allows for efficient addition and removal of elements from both ends of the queue.

#### Member Variables:
- **`front`**: The index of the front element in the deque.
- **`rear`**: The index of the last element in the deque.
- **`size`**: The number of elements in the deque.

#### Constructors & Destructor:
- **`DeQue(int initial_capacity = 10)`**: Constructor that initializes the deque with a specified initial capacity (default is 10). It sets up the deque with an empty state (front = -1, rear = -1, size = 0).

  Example:
  ```cpp
  DeQue<int> deque(10);  // Creates a deque for integers with capacity 10
  ```

- **`~DeQue()`**: Destructor that cleans up the resources used by the deque.

#### DeQue Operations:
- **`PushFront(const T& x)`**: Adds an element `x` to the front of the deque. If the deque is full, it may resize or overwrite the oldest elements.

  Example:
  ```cpp
  deque.PushFront(5);  // Add 5 to the front of the deque
  ```

- **`PushBack(const T& x)`**: Adds an element `x` to the back of the deque. If the deque is full, it may resize or overwrite the oldest elements.

  Example:
  ```cpp
  deque.PushBack(10);  // Add 10 to the back of the deque
  ```

- **`PopFront()`**: Removes the element at the front of the deque. If the deque is empty, this operation should be handled safely.

  Example:
  ```cpp
  deque.PopFront();  // Removes the front element of the deque
  ```

- **`PopBack()`**: Removes the element at the back of the deque. If the deque is empty, this operation should be handled safely.

  Example:
  ```cpp
  deque.PopBack();  // Removes the back element of the deque
  ```

#### Getters:
- **`getFront()`**: Returns the index of the front element in the deque.

  Example:
  ```cpp
  int frontIndex = deque.getFront();  // Get the index of the front element
  ```

- **`getRear()`**: Returns the index of the back element in the deque.

  Example:
  ```cpp
  int rearIndex = deque.getRear();  // Get the index of the back element
  ```

- **`Front()`**: Returns the front element in the deque without removing it.

  Example:
  ```cpp
  int frontElement = deque.Front();  // Get the front element (does not remove it)
  ```

- **`Back()`**: Returns the back element in the deque without removing it.

  Example:
  ```cpp
  int backElement = deque.Back();  // Get the back element (does not remove it)
  ```

#### Properties:
- **`IsEmpty()`**: Returns `true` if the deque is empty, otherwise `false`.

  Example:
  ```cpp
  bool empty = deque.IsEmpty();  // Check if the deque is empty
  ```

#### Operator Overloads:
- **`operator<<`**: Overloads the stream insertion (`<<`) operator to print the elements of the deque in a readable format.

  Example:
  ```cpp
  std::cout << deque;  // Prints the elements of the deque
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `DeQue` class:

```cpp
#include "DeQue.hpp"
#include <iostream>

int main() {
    // Create a DeQue for integers with a capacity of 5
    DeQue<int> deque(5);

    // Add elements to the front and back of the deque
    deque.PushFront(10);  // DeQue: 10
    deque.PushBack(20);   // DeQue: 10, 20
    deque.PushFront(5);   // DeQue: 5, 10, 20

    // Print the deque
    std::cout << "DeQue after insertions: " << deque << std::endl;

    // Get the front and back elements
    std::cout << "Front: " << deque.Front() << std::endl;  // Front: 5
    std::cout << "Back: " << deque.Back() << std::endl;    // Back: 20

    // Remove the front element
    deque.PopFront();  // DeQue: 10, 20

    // Print the deque after removing the front element
    std::cout << "DeQue after PopFront: " << deque << std::endl;

    // Remove the back element
    deque.PopBack();  // DeQue: 10

    // Print the deque after removing the back element
    std::cout << "DeQue after PopBack: " << deque << std::endl;

    // Check if the deque is empty
    std::cout << "Is the deque empty? " << (deque.IsEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

### Explanation:
- The code demonstrates how to use the `DeQue` class to insert and remove elements from both the front and back of the deque.
- It uses the `PushFront()` and `PushBack()` methods to add elements, and `PopFront()` and `PopBack()` to remove elements.
- The `Front()` and `Back()` methods are used to access the front and back elements of the deque, respectively, without removing them.
- The program checks if the deque is empty using the `IsEmpty()` method.

---

## Potential Errors & Edge Cases

1. **Full DeQue**: If the deque reaches its capacity and an attempt is made to insert more elements, ensure that the deque resizes properly or handles the overflow as expected.

2. **Empty DeQue Operations**: When performing operations like `PopFront()` or `PopBack()` on an empty deque, ensure that these operations are handled gracefully. This could involve returning a default value, throwing an exception, or simply not performing any operation if the deque is empty.

   Example:
   ```cpp
   if (!deque.IsEmpty()) {
       deque.PopFront();
   }
   ```

3. **Indexing Errors**: Make sure that the `front`, `rear`, and `size` variables are updated correctly after each operation to ensure the deque maintains the correct state.

---

## Dependencies

- **`Bag.hpp`**: The `DeQue` class inherits from the `Bag<T>` class, so ensure that the `Bag<T>` class is correctly defined and includes methods for handling dynamic array operations.
- **C++ Standard Library**: The class uses `std::variant` for storing elements of various types, as well as `std::ostream` for printing the deque.
