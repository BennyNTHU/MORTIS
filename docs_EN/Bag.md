# `Bag` Documentation

## Overview

The `Bag.hpp` file defines a templated `Bag` class, which can store elements of various types in a dynamic array. The class includes functionality for basic operations such as adding, removing, and checking elements, as well as advanced operations like union and multiplicity counting.

---

## Key Components

### `Bag` Class

The `Bag` class represents a collection of elements that can be dynamically modified. The elements in the bag are stored in an array, and various operations are supported for interacting with the collection.

#### Member Variables:
- **`arr`**: A pointer to the array of elements stored in the bag.
- **`top`**: The index of the last element in the array. If the bag is empty, `top` is `-1`.
- **`capacity`**: The current capacity of the array (i.e., the maximum number of elements the bag can hold before resizing).
- **`size`**: The number of elements currently in the bag. This is calculated as `top + 1`.

#### Constructors & Destructor:
- **`Bag()`**: Default constructor that initializes an empty bag with no elements and a default capacity.
  
  Example:
  ```cpp
  Bag<int> myBag;  // Creates an empty bag of integers
  ```

- **`Bag(int c)`**: Constructor that initializes a bag with a specified capacity `c`.
  
  Example:
  ```cpp
  Bag<int> myBag(10);  // Creates a bag with capacity for 10 elements
  ```

- **`Bag(const Bag<T>& other)`**: Copy constructor that initializes the bag with the elements of another `Bag`.
  
  Example:
  ```cpp
  Bag<int> copyBag = myBag;  // Creates a copy of the original bag
  ```

- **`~Bag()`**: Destructor that cleans up the resources used by the bag.

#### Getters:
- **`getCapacity()`**: Returns the capacity of the bag (i.e., the maximum number of elements it can hold before resizing).
  
  Example:
  ```cpp
  int cap = myBag.getCapacity();  // Get the capacity of the bag
  ```

- **`getTop()`**: Returns the index of the last element in the bag.
  
  Example:
  ```cpp
  int topIndex = myBag.getTop();  // Get the index of the last element
  ```

- **`getArr()`**: Returns a pointer to the array of elements stored in the bag.
  
  Example:
  ```cpp
  int* arr = myBag.getArr();  // Get the array of elements in the bag
  ```

- **`Element()`**: Returns the number of elements currently in the bag.

  Example:
  ```cpp
  int numElements = myBag.Element();  // Get the number of elements in the bag
  ```

#### Properties:
- **`IsEmpty()`**: Returns `true` if the bag is empty, otherwise `false`.
  
  Example:
  ```cpp
  bool empty = myBag.IsEmpty();  // Check if the bag is empty
  ```

- **`Multiplicity(const U& x)`**: Returns the number of times element `x` appears in the bag.

  Example:
  ```cpp
  int count = myBag.Multiplicity(5);  // Count how many times 5 appears in the bag
  ```

- **`isBelong(const U& x)`**: Returns `true` if element `x` exists in the bag, otherwise `false`.
  
  Example:
  ```cpp
  bool belongs = myBag.isBelong(5);  // Check if 5 exists in the bag
  ```

#### Manipulations:
- **`Push(const T& x)`**: Adds an element `x` to the bag.
  
  Example:
  ```cpp
  myBag.Push(10);  // Add 10 to the bag
  ```

- **`Pop()`**: Removes the last element from the bag.
  
  Example:
  ```cpp
  myBag.Pop();  // Remove the last element from the bag
  ```

- **`Unify()`**: Removes duplicate elements from the bag, leaving only unique items.

  Example:
  ```cpp
  myBag.Unify();  // Remove duplicate elements from the bag
  ```

- **`Union(const Bag<T>& b2)`**: Returns a new `Bag` that contains all the elements from both `this` bag and `b2`.

  Example:
  ```cpp
  Bag<int> bag2;
  bag2.Push(5);
  Bag<int> unionBag = myBag.Union(bag2);  // Combine elements of myBag and bag2
  ```

#### Operator Overloads:
- **`operator=`**: Assignment operator to copy the elements of another `Bag` into the current `Bag`.
  
  Example:
  ```cpp
  myBag = anotherBag;  // Copy elements of anotherBag to myBag
  ```

- **`operator==`**: Compares two bags for equality (the same elements in the same order).
  
  Example:
  ```cpp
  if (myBag == anotherBag) {
      // Bags are equal
  }
  ```

- **`operator!=`**: Compares two bags for inequality.
  
  Example:
  ```cpp
  if (myBag != anotherBag) {
      // Bags are not equal
  }
  ```

- **`operator<<`**: Overloaded to print the contents of the bag.
  
  Example:
  ```cpp
  std::cout << myBag;  // Prints the contents of the bag
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `Bag` class:

```cpp
#include "Bag.hpp"
#include <iostream>

int main() {
    // Create a bag for integers
    Bag<int> myBag(10);

    // Add elements to the bag
    myBag.Push(10);
    myBag.Push(20);
    myBag.Push(30);

    // Print the bag contents
    std::cout << "Bag contents: " << myBag << std::endl;

    // Check if the bag contains a specific element
    if (myBag.isBelong(20)) {
        std::cout << "20 is in the bag!" << std::endl;
    }

    // Get the number of elements in the bag
    std::cout << "Number of elements: " << myBag.Element() << std::endl;

    // Remove the last element
    myBag.Pop();

    // Print the bag contents after popping
    std::cout << "After popping an element: " << myBag << std::endl;

    // Create another bag and unify the two bags
    Bag<int> anotherBag;
    anotherBag.Push(10);
    anotherBag.Push(30);
    Bag<int> unifiedBag = myBag.Union(anotherBag);
    
    // Print the unified bag
    std::cout << "Unified bag: " << unifiedBag << std::endl;

    return 0;
}
```

### Explanation:
- The code creates a `Bag` of integers and performs various operations such as adding elements (`Push`), checking for membership (`isBelong`), and removing elements (`Pop`).
- It demonstrates how to check for the number of elements and use the `Union` function to combine two bags.

---

## Potential Errors & Edge Cases

1. **Bag Overflow**: If the number of elements exceeds the capacity of the bag, the array may need to be resized. Ensure that the bag handles resizing properly, especially in the `Push()` function.

2. **Empty Bag Operations**: Operations like `Pop()` or checking for membership should handle empty bags gracefully. Ensure that you check if the bag is empty before performing such operations.

   Example:
   ```cpp
   if (!myBag.IsEmpty()) {
       myBag.Pop();
   }
   ```

3. **Duplicate Handling in Unify**: The `Unify()` method removes duplicate elements. Ensure that the method does not accidentally remove unique elements or fail to handle edge cases where all elements are the same.

---

## Dependencies

- **C++ Standard Library**: The class uses `std::variant` to store heterogeneous elements, and other standard libraries such as `<iostream>`, `<string>`, and `<algorithm>`.
  
- **Other Includes**: The `Bag` class includes references to other array-related types (`GeneralArray`, `Polynomial`, `SparseMatrix`, `String`), which should be properly defined and included.
