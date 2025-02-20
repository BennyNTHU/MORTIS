# `Stack` Documentation

## Overview

The `Stack.hpp` header file defines a templated `Stack` class that implements a stack data structure, providing functionality to push, pop, and view the top element of the stack. The stack supports various data types using `std::variant`, and it inherits from the `Bag<T>` class for basic operations on the underlying storage.

---

## Key Components

### `Stack` Class

The `Stack` class implements the basic operations of a stack, such as adding elements to the top (`Push`), removing elements from the top (`Pop`), and accessing the top element (`Top`).

#### Member Variables:
- **`capacity`**: The maximum number of elements that the stack can hold before needing to resize.
- **`size`**: The current number of elements in the stack.
- **`arr`**: A dynamic array (inherited from `Bag<T>`) that stores the elements of the stack.

#### Constructors & Destructor:
- **`Stack(int initial_capacity = 10)`**: Initializes the stack with a specified initial capacity (default is 10). It sets up the stack with an empty state, and the elements are stored in a dynamically allocated array.
  
  Example:
  ```cpp
  Stack<int> stack(10);  // Create a stack of integers with capacity 10
  ```

#### Manipulation Functions:
- **`Push(const T& x)`**: Adds an element `x` to the top of the stack. If the stack is full, it may resize the internal array to accommodate more elements.

  Example:
  ```cpp
  stack.Push(5);  // Add 5 to the top of the stack
  ```

- **`Pop()`**: Removes the top element from the stack. If the stack is empty, this operation should be handled safely to avoid errors.

  Example:
  ```cpp
  stack.Pop();  // Remove the top element from the stack
  ```

#### Getters:
- **`Top()`**: Returns the top element of the stack without removing it. If the stack is empty, this function should throw an exception or return a default value.

  Example:
  ```cpp
  int topElement = stack.Top();  // Get the top element (does not remove it)
  ```

#### Operator Overloads:
- **`operator<<`**: Overloads the stream insertion (`<<`) operator to print the contents of the stack.

  Example:
  ```cpp
  std::cout << stack;  // Prints the elements of the stack
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `Stack` class:

```cpp
#include "Stack.hpp"
#include <iostream>

int main() {
    // Create a stack for integers with a capacity of 5
    Stack<int> stack(5);

    // Push elements onto the stack
    stack.Push(10);  // Stack: 10
    stack.Push(20);  // Stack: 20, 10
    stack.Push(30);  // Stack: 30, 20, 10

    // Print the stack
    std::cout << "Stack after pushes: " << stack << std::endl;

    // Access the top element
    std::cout << "Top element: " << stack.Top() << std::endl;  // Top: 30

    // Pop the top element
    stack.Pop();  // Stack: 20, 10

    // Print the stack after popping
    std::cout << "Stack after pop: " << stack << std::endl;

    // Check the top element after pop
    std::cout << "Top element after pop: " << stack.Top() << std::endl;  // Top: 20

    return 0;
}
```

### Explanation:
- The code creates a stack of integers and demonstrates how to push elements onto the stack using `Push()`.
- It then prints the stack, accesses the top element using `Top()`, and removes the top element using `Pop()`.
- The state of the stack is printed after each operation to demonstrate the changes.

---

## Potential Errors & Edge Cases

1. **Empty Stack Operations**: When performing `Pop()` or `Top()` on an empty stack, ensure that these operations are handled safely. It is important to check if the stack is empty before calling these methods to avoid undefined behavior or accessing invalid memory.

   Example:
   ```cpp
   if (!stack.IsEmpty()) {
       stack.Pop();
   }
   ```

2. **Full Stack**: If the stack is full and an element is pushed, ensure that the stack can dynamically resize or manage the overflow. This behavior depends on how the underlying array is managed (e.g., doubling the size when full).

3. **Indexing Errors**: When accessing the top element using `Top()`, ensure that the index is within valid bounds (i.e., the stack is not empty).

4. **Memory Management**: Ensure proper memory handling, especially when copying stacks or handling dynamic memory for the underlying array.

---

## Dependencies

- **`Bag.hpp`**: The `Stack` class inherits from the `Bag<T>` class, so ensure that the `Bag<T>` class is correctly defined and includes methods for dynamic array manipulation.
- **C++ Standard Library**: The class uses `std::variant` for storing heterogeneous types, and the stream insertion operator (`operator<<`) for printing the stack's contents.
