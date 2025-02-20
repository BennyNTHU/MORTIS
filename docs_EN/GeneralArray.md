# `GeneralArray` Documentation

## Overview

`GeneralArray.hpp` defines a `GeneralArray` class that supports multi-dimensional arrays with mixed data types. The class leverages `std::variant` to handle a variety of types, including `int`, `char`, `float`, `bool`, `double`, and `std::string`. It provides a range of features for initializing, storing, retrieving, sorting, and manipulating elements in a multi-dimensional array.

---

## Key Components

### 1. `MIXED_TYPE`
A type alias for `std::variant`, which supports multiple data types:
```cpp
using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;
```
This allows the array to hold mixed types in a single instance.

### 2. `RangeList`
A type alias for `std::vector<int>`, representing the sizes of the array's dimensions:
```cpp
typedef std::vector<int> RangeList;
```

### 3. `Index`
A type alias for `std::vector<int>`, used to represent multi-dimensional indices:
```cpp
typedef std::vector<int> Index;
```

### 4. `is_variant`
A trait to detect whether a type is a specialization of `std::variant`:
```cpp
template<typename T>
struct is_variant : std::false_type {}; // Primary template

template<typename... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {}; // Specialization for std::variant
```

---

## `GeneralArray<T>` Class

The `GeneralArray` class is a templated class for creating multi-dimensional arrays. It supports various operations, such as initialization, element storage/retrieval, sorting, and more.

### Constructor & Destructor
- **Constructor**: Initializes a `GeneralArray` with the specified dimensions.
- **Destructor**: Frees any allocated memory.

### Member Functions

- **`Initialize()`**: Initializes all elements in the array to the default value of type `T`.
  
  Example:
  ```cpp
  arr.Initialize();
  ```

- **`Store(const Index& idx, T x)`**: Stores the value `x` at the given multi-dimensional index `idx`.

  Example:
  ```cpp
  Index idx = {0, 1, 2};
  arr.Store(idx, 10);
  ```

- **`Retrieve(const Index& idx) const`**: Retrieves the element at the given multi-dimensional index `idx`.
  
  Example:
  ```cpp
  int value = arr.Retrieve(idx);
  ```

- **`Length() const`**: Returns the total number of elements in the array.

  Example:
  ```cpp
  int len = arr.Length();
  ```

- **`Sort(bool reverse = false, int sortDim = 1)`**: Sorts the array along a specified dimension. Optionally, the sorting order can be reversed.

  Example:
  ```cpp
  arr.Sort(true, 1); // Sort in reverse order along the first dimension
  ```

- **`Reverse()`**: Reverses the order of elements in the array.

  Example:
  ```cpp
  arr.Reverse();
  ```

- **`Push_back(const T& value)`**: Adds an element to a 1D array (works only for 1D arrays).

  Example:
  ```cpp
  arr.Push_back(5);
  ```

### Operator Overloading

- **`operator=`**: Copies the content from another `GeneralArray` or initializer list.

  Example:
  ```cpp
  arr = otherArray;  // Copy constructor
  arr = {1, 2, 3};   // Using initializer list
  ```

- **`operator[]`**: Accesses elements by index (non-const and const versions).

  Example:
  ```cpp
  int& element = arr[0];  // Non-const access
  const int& element = arr[0];  // Const access
  ```

- **`operator==`**: Checks for equality between two `GeneralArray` instances.
- **`operator!=`**: Checks for inequality between two `GeneralArray` instances.

### Input/Output Stream Operators

- **`operator>>`**: Reads data from an input stream into the array.
- **`operator<<`**: Outputs the array contents to an output stream.

Example:
```cpp
std::cin >> arr;
std::cout << arr;
```

---

## Example Usage

```cpp
#include "GeneralArray.hpp"

int main() {
    // Create a GeneralArray for integer data type
    GeneralArray<int> arr(3); // 3-dimensional array
    
    // Initialize the array with default values
    arr.Initialize();
    
    // Define the index for storing/retrieving elements
    Index idx = {0, 1, 2}; // Access element at [0][1][2]
    
    // Store a value in the array
    arr.Store(idx, 10);
    
    // Retrieve and print the value
    int val = arr.Retrieve(idx);
    std::cout << "Value at index [0][1][2]: " << val << std::endl;
    
    // Sort array (optional dimension)
    arr.Sort(false, 1); // Sort along the first dimension
    
    // Reverse the array
    arr.Reverse();
    
    // Print the entire array using the stream operator
    std::cout << arr << std::endl;
    
    return 0;
}
```

---

## Potential Errors & Edge Cases

1. **Index Out of Bounds**: Ensure the indices are within the valid range for the array dimensions.
2. **Unsupported Data Types**: The array is limited to the types specified in `MIXED_TYPE`. Using other types will result in compilation errors.
3. **Sorting on Non-1D Arrays**: Sorting a non-1D array may require a valid dimension to avoid incorrect results.
4. **Memory Issues**: Ensure the array dimensions and element types are compatible with the available system memory.

---

## Dependencies

- **C++17 or higher**: Required for `std::variant`.
- **Standard C++ Libraries**: `<vector>`, `<iostream>`, `<algorithm>`, and others.
