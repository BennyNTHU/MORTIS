### **CirQue Documentation**
#### **Circular Queue (CirQue) - A Circular Double-Ended Queue Implementation**
---
#### **Introduction**
CirQue is an implementation of a circular queue that extends the functionality of a double-ended queue (DeQue), which in turn inherits from the Bag class. This structure allows efficient insertion and deletion from both ends while ensuring optimal memory usage.

CirQue supports multiple data types, including:
- Primitive types: `int, char, float, bool, double, std::string`
- Complex data structures: `GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String`

This document provides a guide on how to use the CirQue class.

---

## **1. Class Interface**
```cpp
class CirQue : public DeQue {
public:
    // Constructor
    CirQue(int capacity);

    // Insert elements at the front and back
    void PushFront(const MORTISInvariant& x);
    void PushBack(const MORTISInvariant& x);

    // Remove elements from the front and back
    void PopFront();
    void PopBack();

    // Retrieve elements from the front and back
    MORTISInvariant Front() const;
    MORTISInvariant Back() const;

    // Utility functions
    bool IsEmpty() const;
    int Size() const;

    // Print all elements
    void PrintBag() const;
};
```

---

## **2. Usage Guide**
### **2.1 Initializing a CirQue**
To create a CirQue instance, specify the maximum capacity:
```cpp
CirQue queue(10);
```
This creates a circular queue with space for up to 10 elements.

---

### **2.2 Inserting Elements**
Use `PushFront` and `PushBack` to insert elements:
```cpp
queue.PushBack(42);
queue.PushBack('A');
queue.PushBack(3.14);
queue.PushFront("Hello");
```
This inserts elements at the front and back.

---

### **2.3 Removing Elements**
To remove elements, use `PopFront` and `PopBack`:
```cpp
queue.PopFront();
queue.PopBack();
```
These functions remove elements from the respective ends.

---

### **2.4 Retrieving Front & Back Elements**
To check the elements at the front and back without removing them:
```cpp
std::cout << "Front: ";
std::visit([](auto&& arg) { std::cout << arg << std::endl; }, queue.Front());

std::cout << "Back: ";
std::visit([](auto&& arg) { std::cout << arg << std::endl; }, queue.Back());
```

---

### **2.5 Checking Size & Empty Status**
Use the following functions to check if the queue is empty and get its size:
```cpp
if (queue.IsEmpty()) {
    std::cout << "Queue is empty!" << std::endl;
} else {
    std::cout << "Queue size: " << queue.Size() << std::endl;
}
```

---

### **2.6 Printing All Elements**
To print all elements in the queue:
```cpp
queue.PrintBag();
```
This will print each element on a new line.

---

## **3. Complete Example**
Below is a comprehensive test case that demonstrates all functionalities of CirQue.
```cpp
#include "CirQue.hpp"
#include <iostream>

using namespace std;

int main() {
    CirQue queue(15);

    cout << "=== CirQue Test ===" << endl;

    // Insert primitive types
    queue.PushBack(42);
    queue.PushBack('A');
    queue.PushBack(3.14);
    queue.PushBack(true);
    queue.PushBack("Hello");

    cout << "Queue after inserting basic types:" << endl;
    queue.PrintBag();

    // Remove elements
    queue.PopFront();
    queue.PopBack();
    cout << "Queue after removing front and back elements:" << endl;
    queue.PrintBag();

    // Insert std::string
    queue.PushBack(std::string("Hello, CirQue!"));

    // Insert GeneralArray<MIXED_TYPE>
    GeneralArray<MIXED_TYPE> ga(1, {3}, MIXED_TYPE{});
    ga.Store({0}, 100);
    ga.Store({1}, std::string("Test"));
    ga.Store({2}, 'Z');
    queue.PushBack(ga);

    // Insert Polynomial
    Polynomial poly;
    poly.NewTerm(2, 3); // 3x^2
    poly.NewTerm(0, 1); // +1
    queue.PushBack(poly);
    
    // Insert SparseMatrix
    SparseMatrix sm(3, 3, 2);
    sm.StoreNum(0, 0, 5);
    sm.StoreNum(1, 1, -2);
    queue.PushBack(sm);
    
    // Insert String
    char init1[] = "Yeah Tiger";
    String str(init1, 100);
    queue.PushBack(str);

    cout << "\nDeQue contents after inserting all types:\n";
    queue.PrintBag();

    // Test Front & Back
    cout << "\nFront element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, queue.Front());

    cout << "Back element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, queue.Back());

    // Test PopFront & PopBack
    queue.PopFront();
    queue.PopBack();
    
    cout << "\nDeQue after popping front and back:\n";
    queue.PrintBag();

    cout << "\nTest completed successfully!\n";

    return 0;
}
```

---

## **4. Compilation**
Compile the test program using:
```sh
g++ -std=c++17 CirQue.cpp CirQue-test.cpp ../../array/GeneralArray/GeneralArray.cpp \
    ../../array/Polynomial/Polynomial.cpp ../../array/SparseMatrix/SparseMatrix.cpp \
    ../../array/String/String.cpp ../DeQue/DeQue.cpp ../Bag/Bag.cpp -o test
```

---

## **5. Expected Output**
```
=== CirQue Test ===
Queue after inserting basic types:
42
A
3.14
1
Hello

Queue after removing front and back elements:
A
3.14
1

DeQue contents after inserting all types:
A
3.14
1
Hello, CirQue!
GeneralArray data...
Polynomial data...
SparseMatrix data...
String data...

Front element: A
Back element: String data...

DeQue after popping front and back:
3.14
1
Hello, CirQue!
GeneralArray data...
Polynomial data...
SparseMatrix data...

Test completed successfully!
```

---

## **6. Summary**
- **CirQue** is a circular double-ended queue that allows insertion and removal from both ends.
- Supports multiple data types, including primitive types and complex data structures.
- Implements a **ring buffer** to efficiently use memory.
- Inherits from **DeQue**, which in turn inherits from **Bag**.
- Includes robust error handling for underflow and overflow situations.

This documentation provides everything needed to use CirQue efficiently. 🚀