# GeneralArray

The `GeneralArray` class is a template class that supports multi-dimensional array operations. It allows you to create arrays of arbitrary dimensions and provides the following functionalities:
- **Storing and retrieving elements**  
- **Initialization, reversal, and sorting**  
- **Assignment via `initializer_list`**  
- **Input/output operations**

This documentation will detail the purpose and usage of each member function, along with corresponding examples.

---

## Table of Contents

1. [Constructors and Basic Operations](#constructors-and-basic-operations)
2. [Element Access](#element-access)
3. [Array Operations](#array-operations)
    - [Sorting](#sorting)
    - [Reversal](#reversal)
    - [Initialization](#initialization)
4. [Assignment and Copying](#assignment-and-copying)
5. [Input and Output](#input-and-output)
6. [Usage Examples](#usage-examples)

---

## Constructors and Basic Operations

### Constructor

```cpp
// GeneralArray(int j, const RangeList& list, T initValue = T());
```

- **Purpose**: Used to create a multi-dimensional array.
- **Parameters**:
  - `j`: The number of dimensions. For example, pass `1` for a 1D array, `2` for a 2D array.
  - `list`: A `vector<int>` where each element represents the size of the corresponding dimension. For example, for a 1D array, pass `{5}` for 5 elements; for a 2D array, pass `{3, 3}` for a 3x3 matrix.
  - `initValue`: The initial value for all elements, defaulting to `T()`.

### Destructor

- **Purpose**: Releases dynamically allocated memory.

---

## Element Access

### Store() Function

```cpp
// void Store(const Index& idx, T x);
```

- **Purpose**: Updates the element at the specified index with a new value.
- **Parameters**:
  - `idx`: A `vector<int>` representing the multi-dimensional index. For example, pass `{2}` for a 1D array; pass `{1, 0}` for the second row and first column in a 2D array.
  - `x`: The new value to store.

### Retrieve() Function

```cpp
// T Retrieve(const Index& idx) const;
```

- **Purpose**: Retrieves the element at the specified index.
- **Parameters**:
  - `idx`: Same as in `Store()`, a multi-dimensional index.

---

## Array Operations

### Sorting

```cpp
// void sort(bool reverse = false, int sortDim = 1);
```

- **Purpose**:
  - For 1D arrays: Sorts the entire array. If `reverse` is `true`, sorts in ascending order; if `false`, sorts in descending order.
  - For 2D arrays: Sorts the rows based on the specified column (`sortDim` indicates the column number, starting from 1).
- **Parameters**:
  - `reverse`: The sorting order. Default is `false` (descending), set to `true` for ascending.
  - `sortDim`: Only valid for 2D arrays, specifies which column to sort by.

### Reversal

```cpp
// void reverse();
```

- **Purpose**: Reverses all elements of the array in a linear (flattened) order.

### Initialization

```cpp
// void initialize();
```

- **Purpose**: Resets all elements of the array to the default value `T{}` (e.g., `0` for numeric types).

### Length

```cpp
// int length() const;
```

- **Purpose**: Returns the total number of elements in the array.

---

## Assignment and Copying

### Copy Constructor

- **Purpose**: Performs a deep copy of another `GeneralArray`.

### Deep Copy Assignment

```cpp
// GeneralArray<T>& operator=(const GeneralArray<T>& other);
```

- **Purpose**: Copies all data from another `GeneralArray` to the current object.

### `initializer_list` Assignment

```cpp
// GeneralArray<T>& operator=(std::initializer_list<T> il);
```

- **Purpose**: Allows assignment via a brace-enclosed list. For example:
  ```cpp
  arr = {1, 2, 3, 4, 5};
  ```
- **Note**: The size of the initializer list must match the number of elements in the array, otherwise an exception is thrown.

### Equality Operator

```cpp
// bool operator==(const GeneralArray<T>& other) const;
```

- **Purpose**: Compares two `GeneralArray` objects for equality in both dimensions and elements.

---

## Input and Output

### Output Operator (`operator<<`)

- **Purpose**: Outputs the contents of the array in a readable format to an output stream (e.g., `std::cout`).
- **Format**:
  - For 1D arrays: Outputs as `[elem1, elem2, ...]`.
  - For 2D arrays: Outputs as `[[row1], [row2], ...]`.

### Input Operator (`operator>>`)

- **Purpose**: Reads data from an input stream and fills the array.  
- **Note**: For types using `std::variant`, the input operator is not supported; you must use `Store()` to populate the array.

---

## Usage Examples

Below are some examples demonstrating how to use the `GeneralArray` class:

### Example 1: 1D Integer Array

```cpp
#include <iostream>
#include <vector>
#include "GeneralArray.h"
using namespace std;

int main() {
    // Create a 1D array with 5 elements, all initialized to 0
    vector<int> dims = {5};
    GeneralArray<int> arrInt(1, dims, 0);

    // Use Store() to set values at specific indices
    arrInt.Store({0}, 10);
    arrInt.Store({1}, 20);
    arrInt.Store({2}, 30);
    arrInt.Store({3}, 40);
    arrInt.Store({4}, 50);

    // Output the array contents
    cout << "Initial int array: " << arrInt << endl;
    cout << "Element at index [2]: " << arrInt.Retrieve({2}) << endl;
    cout << "Length of int array: " << arrInt.length() << endl;

    // Reverse the array
    arrInt.reverse();
    cout << "After reverse: " << arrInt << endl;

    // Initialize the array (reset all elements to 0)
    arrInt.initialize();
    cout << "After initialize: " << arrInt << endl;

    // Assign using initializer_list
    arrInt = {1, 2, 3, 4, 5};
    cout << "After initializer_list assignment: " << arrInt << endl;

    return 0;
}
```

### Example 2: 1D Floating-Point Array with Sorting

```cpp
#include <iostream>
#include <vector>
#include "GeneralArray.h"
using namespace std;

int main() {
    vector<int> dims = {5};
    GeneralArray<double> arrDouble(1, dims, 0.0);

    // Set values
    arrDouble.Store({0}, 3.14);
    arrDouble.Store({1}, 2.71);
    arrDouble.Store({2}, 1.41);
    arrDouble.Store({3}, 0.577);
    arrDouble.Store({4}, 1.618);

    cout << "Initial double array: " << arrDouble << endl;

    // Sort in ascending order
    arrDouble.sort(true);
    cout << "Sorted ascending: " << arrDouble << endl;

    // Sort in descending order
    arrDouble.sort(false);
    cout << "Sorted descending: " << arrDouble << endl;

    return 0;
}
```

### Example 3: 2D Integer Array with Input Operation

```cpp
#include <iostream>
#include <sstream>
#include <vector>
#include "GeneralArray.h"
using namespace std;

int main() {
    vector<int> dims2D = {3, 3};  // 3 rows, 3 columns
    GeneralArray<int> arr2D(2, dims2D, 0);

    // Simulate input: must match the format [[9,8,7],[6,5,4],[3,2,1]]
    istringstream iss("[[9,8,7],[6,5,4],[3,2,1]]");
    iss >> arr2D;

    cout << "Input 2D array: " << arr2D << endl;

    // Sort by the first column (ascending and descending examples)
    arr2D.sort(true, 1);
    cout << "2D array sorted ascending by first column: " << arr2D << endl;

    arr2D.sort(false, 1);
    cout << "2D array sorted descending by first column: " << arr2D << endl;

    return 0;
}
```

### Example 4: Heterogeneous Array (using `std::variant`)

```cpp
#include <iostream>
#include <vector>
#include <variant>
#include <string>
#include "GeneralArray.h"
using namespace std;

int main() {
    // Define a variant type supporting int, char, and string
    using VarType = std::variant<int, char, std::string>;

    vector<int> dimsVar = {3};
    GeneralArray<VarType> arrVariant(1, dimsVar, VarType{});

    // Store different types of values using Store()
    arrVariant.Store({0}, 100);                // int
    arrVariant.Store({1}, 'Z');                // char
    arrVariant.Store({2}, std::string("Test"));  // string

    cout << "Heterogeneous array: " << arrVariant << endl;

    return 0;
}
```

---

## Summary

The `GeneralArray` class provides flexible multi-dimensional array operations, supporting basic element access, sorting, reversal, and quick assignment via `initializer_list`. Through the examples above, you can intuitively understand how to use this class for array operations in different scenarios. For special types (e.g., `std::variant`), note that some operations (like the input operator) are not supported, and you must use functions like `Store()` to set data.

This concludes the detailed usage guide and examples for the `GeneralArray` class. We hope this documentation helps you quickly get started and make the most of its features.

---