# Queue Class Documentation

## Overview
The `Queue` class implements a First-In-First-Out (FIFO) data structure that inherits from the `Bag` class. It provides standard queue operations with a templated design for type flexibility.

## Dependencies
- Requires `Bag.hpp` as parent class
- Custom data structure headers:
  - `GeneralArray.hpp`
  - `Polynomial.hpp`
  - `SparseMatrix.hpp`
  - `String.hpp`

## Type Definitions

### MIXED_TYPE
```cpp
using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;
```
A variant type supporting basic data types.

### MORTISInvariant
```cpp
using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;
```
Extended variant type supporting both basic types and custom data structures.

## API Documentation with Examples

### Constructor
```cpp
Queue(int capacity = 10);
```
Creates a new queue with specified capacity.

**Parameters:**
- `capacity`: Initial queue size (optional, defaults to 10)

**Example:**
```cpp
// Create queues with different capacities and types
Queue<int> intQueue;              // Default capacity (10)
Queue<string> strQueue(20);       // Capacity of 20
Queue<MIXED_TYPE> mixedQueue(15); // Mixed type queue
```

### Push Operation
```cpp
void Push(const T& x);
```
Adds an element to the back of the queue.

**Parameters:**
- `x`: Element to add (const reference)

**Example:**
```cpp
Queue<int> queue(5);

// Basic integer push
try {
    queue.Push(10);        // [10]
    queue.Push(20);        // [10,20]
    queue.Push(30);        // [10,20,30]
    
    // Mixed type example
    Queue<MIXED_TYPE> mixedQueue;
    mixedQueue.Push(42);           // Integer
    mixedQueue.Push("Hello");      // String
    mixedQueue.Push(3.14);         // Double
    
    // Check for queue full condition
    Queue<int> smallQueue(1);
    smallQueue.Push(1);    // OK
    smallQueue.Push(2);    // Will throw exception - queue full
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### Pop Operation
```cpp
void Pop();
```
Removes the element from the front of the queue.

**Example:**
```cpp
Queue<int> queue(5);

try {
    // Add some elements
    queue.Push(10);
    queue.Push(20);
    queue.Push(30);    // [10,20,30]
    
    queue.Pop();       // [20,30]
    queue.Pop();       // [30]
    
    // Error handling for empty queue
    Queue<int> emptyQueue;
    emptyQueue.Pop();  // Will throw exception - queue empty
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### Front Access
```cpp
T Front() const;
```
Returns the front element of the queue.

**Returns:** Copy of the front element

**Example:**
```cpp
Queue<int> queue(5);

try {
    queue.Push(10);
    queue.Push(20);    // [10,20]
    
    int front = queue.Front();  // front = 10
    std::cout << "Front element: " << front << std::endl;
    
    // Error handling
    Queue<int> emptyQueue;
    int value = emptyQueue.Front();  // Will throw exception
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### Rear Access
```cpp
T Rear() const;
```
Returns the rear element of the queue.

**Returns:** Copy of the rear element

**Example:**
```cpp
Queue<int> queue(5);

try {
    queue.Push(10);
    queue.Push(20);    // [10,20]
    
    int rear = queue.Rear();  // rear = 20
    std::cout << "Rear element: " << rear << std::endl;
    
    // Error handling
    Queue<int> emptyQueue;
    int value = emptyQueue.Rear();  // Will throw exception
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### Empty Check
```cpp
bool IsEmpty() const;
```
Checks if the queue is empty.

**Returns:** `true` if empty, `false` otherwise

**Example:**
```cpp
Queue<int> queue(5);

// Check empty queue
bool isEmpty1 = queue.IsEmpty();  // true

// Check after adding elements
queue.Push(10);
bool isEmpty2 = queue.IsEmpty();  // false

// Check in conditional
if (queue.IsEmpty()) {
    std::cout << "Queue is empty" << std::endl;
} else {
    std::cout << "Queue has elements" << std::endl;
}
```

### Index Accessors
```cpp
int getFront() const;
int getRear() const;
```
Get the current front and rear indices.

**Example:**
```cpp
Queue<int> queue(5);

// Check initial indices
int frontIndex = queue.getFront();
int rearIndex = queue.getRear();

// Add elements and check again
queue.Push(10);
queue.Push(20);
std::cout << "Front index: " << queue.getFront() << std::endl;
std::cout << "Rear index: " << queue.getRear() << std::endl;
```

### Output Operator
```cpp
template <typename U>
friend std::ostream& operator<<(std::ostream& os, const Queue<U>& s);
```
Prints the queue contents.

**Example:**
```cpp
Queue<int> queue(5);
queue.Push(10);
queue.Push(20);
queue.Push(30);

// Print queue
std::cout << queue << std::endl;  // Output: [10 20 30]

// Using with string stream
std::ostringstream oss;
oss << queue;
std::string queueStr = oss.str();
```

## Complete Usage Example
```cpp
#include "Queue.hpp"
#include <iostream>

int main() {
    try {
        // Create a queue
        Queue<int> queue(5);
        
        // Add elements
        queue.Push(10);
        queue.Push(20);
        queue.Push(30);
        
        std::cout << "Queue: " << queue << std::endl;
        std::cout << "Front: " << queue.Front() << std::endl;
        std::cout << "Rear: " << queue.Rear() << std::endl;
        
        // Remove elements
        queue.Pop();
        std::cout << "After Pop: " << queue << std::endl;
        
        // Check if empty
        if (!queue.IsEmpty()) {
            std::cout << "Queue still has elements" << std::endl;
        }
        
        // Create a mixed type queue
        Queue<MIXED_TYPE> mixedQueue;
        mixedQueue.Push(42);
        mixedQueue.Push("Test");
        mixedQueue.Push(3.14);
        
        std::cout << "Mixed Queue: " << mixedQueue << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

## Error Handling
Common errors to handle:
1. Queue overflow (Push to full queue)
2. Queue underflow (Pop/Front/Rear on empty queue)
3. Memory allocation failures

## Best Practices
1. Always check IsEmpty() before Pop/Front/Rear operations
2. Use appropriate initial capacity to avoid overflow
3. Implement proper error handling
4. Consider using MIXED_TYPE or MORTISInvariant for flexible type support
5. Remember that Front() and Rear() return copies, not references

The Queue class provides standard FIFO operations with comprehensive error checking and flexible type support through templates and variants.
