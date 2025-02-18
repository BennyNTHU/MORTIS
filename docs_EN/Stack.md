# Stack Class Documentation

## Introduction

The `Stack` class is an implementation of a **Last-In, First-Out (LIFO) stack** that extends the `Bag` class. It allows users to perform standard stack operations like **Push**, **Pop**, and **Top**, and supports **printing the stack contents** in a human-readable format.

The `Stack` class can store elements of various types, including:
- `int`
- `char`
- `float`
- `bool`
- `double`
- `std::string`
- `GeneralArray<MIXED_TYPE>`
- `Polynomial`
- `SparseMatrix`
- `String`

---

## **1. Including and Initializing a Stack**

Before using the stack, include the required header file:

```cpp
#include "Stack.hpp"
```

To create a stack, use the constructor:

```cpp
Stack stack(10); // Creates a stack with an initial capacity of 10 elements
```

---

## **2. Stack Operations**

### **2.1 Push Elements**
Pushes an element onto the stack.

```cpp
stack.Push(42);
stack.Push('A');
stack.Push(3.14);
stack.Push("Hello");
```

### **2.2 Pop Elements**
Removes the top element from the stack.

```cpp
stack.Pop();
```

If the stack is empty, calling `Pop()` will throw an exception.

### **2.3 Get the Top Element**
Retrieves the top element **without removing it**.

```cpp
MORTISInvariant topElement = stack.Top();
```

If the stack is empty, calling `Top()` will throw an exception.

### **2.4 Check if the Stack is Empty**
Returns `true` if the stack is empty, otherwise `false`.

```cpp
if (stack.IsEmpty()) {
    std::cout << "The stack is empty." << std::endl;
}
```

### **2.5 Print the Stack**
Displays all stack elements **from top to bottom**.

```cpp
stack.PrintStack();
```

Example Output:

```
Stack (Top to Bottom):
1. 42 <- top
2. A
3. 3.14
4. "Hello"
```

---

## **3. Example Usage**
A complete example demonstrating stack operations.

```cpp
#include <iostream>
#include "Stack.hpp"

int main() {
    Stack stack(5);

    stack.Push(42);
    stack.Push('A');
    stack.Push(3.14);
    stack.Push("Hello");

    stack.PrintStack();

    std::cout << "Top element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, stack.Top());

    stack.Pop();
    std::cout << "After popping an element:" << std::endl;
    stack.PrintStack();

    return 0;
}
```

Expected Output:

```
Stack (Top to Bottom):
1. 42 <- top
2. A
3. 3.14
4. "Hello"

Top element: 42

After popping an element:
Stack (Top to Bottom):
1. A <- top
2. 3.14
3. "Hello"
```

---

## **4. Exception Handling**
- **Calling `Pop()` on an empty stack** will throw an `std::out_of_range` exception.
- **Calling `Top()` on an empty stack** will also throw an `std::out_of_range` exception.

To handle these exceptions:

```cpp
try {
    stack.Pop();
} catch (const std::out_of_range& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

---

## **5. Summary of Stack Methods**
| Method          | Description |
|----------------|------------|
| `Stack(int initial_capacity)` | Constructor to initialize the stack with a given capacity. |
| `void Push(const MORTISInvariant& x)` | Push an element onto the stack. |
| `void Pop()` | Remove the top element from the stack. |
| `MORTISInvariant Top() const` | Retrieve the top element without removing it. |
| `bool IsEmpty() const` | Check if the stack is empty. |
| `void PrintStack() const` | Print all stack elements in a structured format. |
