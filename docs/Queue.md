# Queue Class Documentation

The `Queue` class is a linear queue implementation that extends the `Bag` class. It supports inserting elements at the back and removing elements from the front while maintaining a **FIFO (First In, First Out)** order. 

## Features:
- Inherits from `Bag`
- Supports dynamic resizing
- Handles various data types using `MORTISInvariant` (a variant type)
- Provides essential queue operations (`Push`, `Pop`, `Front`, `Rear`, `IsEmpty`)
- Prints elements in a structured format

## Class Declaration
```cpp
class Queue : public Bag {
private:
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Number of elements in the queue

public:
    // Constructor & Destructor
    Queue(int capacity = 10);
    ~Queue();

    // Queue operations
    void Push(const MORTISInvariant& x); // Enqueue an element
    void Pop();                          // Dequeue an element
    MORTISInvariant Front() const;       // Get front element
    MORTISInvariant Rear() const;        // Get rear element
    bool IsEmpty() const;                // Check if queue is empty

    // Utility functions
    void PrintQueue() const; // Print queue elements
};
```

---

## Queue Operations

### **Constructor: `Queue(int capacity = 10);`**
Creates a queue with an optional initial capacity.

#### **Example:**
```cpp
Queue q(5);  // Create a queue with capacity 5
```

---

### **`void Push(const MORTISInvariant& x);`**
Adds an element to the back of the queue.

#### **Example:**
```cpp
q.Push(25);                      // Enqueue an integer
q.Push(3.14159);                 // Enqueue a float
q.Push("Hello");                 // Enqueue a string
```

---

### **`void Pop();`**
Removes an element from the front of the queue.

#### **Example:**
```cpp
q.Pop();  // Removes the first element from the queue
```

---

### **`MORTISInvariant Front() const;`**
Returns the first element in the queue.

#### **Example:**
```cpp
cout << std::get<int>(q.Front()) << endl; // Outputs: 25
```

---

### **`MORTISInvariant Rear() const;`**
Returns the last element in the queue.

#### **Example:**
```cpp
cout << std::get<std::string>(q.Rear()) << endl; // Outputs: "Hello"
```

---

### **`bool IsEmpty() const;`**
Checks if the queue is empty.

#### **Example:**
```cpp
if (q.IsEmpty()) {
    cout << "Queue is empty." << endl;
}
```

---

### **`void PrintQueue() const;`**
Prints the queue elements in a structured format.

#### **Example Output:**
```
Queue contents:
1. 25 <- front
2. 3.14159
3. A
4. 56
5. 2x^3
6. "Hello" <- rear
```

#### **Example Usage:**
```cpp
q.PrintQueue();
```

---

## **Example Program (Queue-test.cpp)**
```cpp
#include <iostream>
#include "Queue.hpp"

using namespace std;

int main() {
    Queue q(5);

    cout << "IsEmpty? " << (q.IsEmpty() ? "Yes" : "No") << endl;

    // Push elements
    q.Push(25);
    q.Push(3.14159);
    q.Push('A');
    q.Push("Hello");

    cout << "Front: " << std::get<int>(q.Front()) << endl;
    cout << "Rear: " << std::get<std::string>(q.Rear()) << endl;

    q.PrintQueue();  // Display the queue

    // Pop elements
    q.Pop();
    q.PrintQueue();

    return 0;
}
```

---

## Summary
| Function | Description |
|----------|------------|
| `Queue(int capacity = 10);` | Creates a queue with optional capacity |
| `void Push(const MORTISInvariant& x);` | Adds an element to the rear |
| `void Pop();` | Removes an element from the front |
| `MORTISInvariant Front() const;` | Returns the front element |
| `MORTISInvariant Rear() const;` | Returns the rear element |
| `bool IsEmpty() const;` | Checks if the queue is empty |
| `void PrintQueue() const;` | Prints queue elements |
