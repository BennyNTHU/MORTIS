# Bag Data Structure Usage Guide

### 1. Introduction
`Bag` is a container class that allows storing various types of objects, including:
- `int`, `char`, `float`, `bool`, `double`, `std::string`
- `GeneralArray`
- `Polynomial`
- `SparseMatrix`
- `String`

This container supports duplicate elements and provides basic operations such as insertion, deletion, and searching.

---

### 2. Included Features
| Function | Description |
|----------|-------------|
| `Bag(int c)` | Constructor, creates a `Bag` with an initial capacity of `c` |
| `~Bag()` | Destructor, releases memory |
| `int Size() const` | Returns the capacity of the `Bag` |
| `bool IsEmpty() const` | Checks if the `Bag` is empty |
| `int Element() const` | Returns the current number of elements in the `Bag` |
| `void Push(const MORTISInvariant& x)` | Inserts element `x` into the `Bag` |
| `void Pop()` | Removes the last inserted element from the `Bag` |
| `template<class U> int Multiplicity(const U& x) const` | Returns the number of occurrences of `x` in the `Bag` |
| `template<class U> bool isBelong(const U& x) const` | Checks if `x` exists in the `Bag` |

---

### 3. Usage Example
```cpp
#include <iostream>
#include "Bag.hpp"
#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using namespace std;

int main() {
    cout << "=== Bag Test Program ===" << endl;
    
    // Create a Bag with an initial capacity of 5
    Bag b(5);

    // Create some elements of different types
    SparseMatrix A(4, 5, 3);
    double pi = 3.14159;

    // Test initial state
    cout << "Initial Bag:" << endl;
    cout << "  IsEmpty? " << (b.IsEmpty() ? "Yes" : "No") << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity: " << b.Size() << endl;

    // Insert elements of different types
    b.Push(10);
    b.Push(A);
    b.Push('c');
    b.Push(pi);
    b.Push("Hello");

    cout << "Bag after inserting elements:" << endl;
    cout << "  Number of elements: " << b.Element() << endl;

    // Test Multiplicity (count occurrences of an element)
    cout << "Multiplicity of 10: " << b.Multiplicity(10) << endl;
    cout << "Multiplicity of 'c': " << b.Multiplicity('c') << endl;

    // Test isBelong (check if an element exists)
    cout << "Does 'Hello' exist? " << (b.isBelong(std::string("Hello")) ? "Yes" : "No") << endl;
    cout << "Does 3.14159 exist? " << (b.isBelong(3.14159) ? "Yes" : "No") << endl;

    // Test Pop operation
    b.Pop();
    cout << "Bag after popping an element:" << endl;
    cout << "  Number of elements: " << b.Element() << endl;

    return 0;
}
```

---

### 4. Compilation Instructions
Ensure C++17 or higher is used, and compile with g++:
```sh
g++ -std=c++17 Bag.cpp Bag-test.cpp ../../MORTIS.hpp -o test
```
If additional classes (`GeneralArray`, `Polynomial`, `SparseMatrix`, `String`) are used, ensure they are correctly compiled and included in the compilation command.

---

### 5. Possible Errors and Solutions
| Error Message | Possible Cause | Solution |
|---------------|----------------|----------|
| `undefined reference to GeneralArray` | Missing `GeneralArray.cpp` in compilation | Add `../../array/GeneralArray/GeneralArray.cpp` to the g++ command |
| `MORTISInvariant does not name a type` | `MORTIS.hpp` is not correctly included | Ensure `#include "../../MORTIS.hpp"` is present in `Bag.hpp` |
| `Segmentation fault` | Using an uninitialized `Bag` | Ensure the `Bag` is constructed with the correct initial capacity |