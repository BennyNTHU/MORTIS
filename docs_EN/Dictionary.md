# `Dictionary.hpp` Documentation

## Overview

The `Dictionary.hpp` file defines a templated `Dictionary` class, which implements a key-value store. It allows users to store, retrieve, and manipulate key-value pairs, and includes several useful methods for dictionary operations such as insertion, removal, and searching. The dictionary also supports various operations on the values associated with keys, such as applying transformations and merging values.

---

## Key Components

### `KeyValuePair` Structure

The `KeyValuePair` struct represents a single key-value pair in the dictionary. It contains:
- **`key`**: The key in the key-value pair.
- **`value`**: The value associated with the key.

```cpp
template <class K, class V>
struct KeyValuePair
{
    K key;   // The key
    V value; // The value associated with the key
};
```

### `Dictionary` Class

The `Dictionary` class stores a collection of `KeyValuePair` objects and provides methods for interacting with them. The keys and values can be of any types specified by the template parameters `K` and `V`.

#### Member Variables:
- **`capacity`**: The maximum number of key-value pairs the dictionary can hold before resizing.
- **`size`**: The number of key-value pairs currently stored in the dictionary.
- **`arr`**: An array that stores the key-value pairs.

#### Constructors & Destructor:
- **`Dictionary(int c)`**: Initializes the dictionary with the specified capacity `c`.

  Example:
  ```cpp
  Dictionary<int, std::string> dict(10);  // Create a dictionary with a capacity of 10
  ```

- **`Dictionary(const Dictionary<K, V>& dict)`**: Copy constructor that initializes the dictionary by copying the contents of another dictionary.

  Example:
  ```cpp
  Dictionary<int, std::string> dictCopy = dict;  // Create a copy of the dictionary
  ```

- **`~Dictionary()`**: Destructor that frees the resources used by the dictionary.

#### Properties:
- **`Capacity()`**: Returns the capacity of the dictionary.

  Example:
  ```cpp
  int cap = dict.Capacity();  // Get the capacity of the dictionary
  ```

- **`IsEmpty()`**: Returns `true` if the dictionary is empty, otherwise `false`.

  Example:
  ```cpp
  bool isEmpty = dict.IsEmpty();  // Check if the dictionary is empty
  ```

- **`Size()`**: Returns the number of elements currently stored in the dictionary.

  Example:
  ```cpp
  int size = dict.Size();  // Get the number of key-value pairs in the dictionary
  ```

- **`isBelong(const K& key)`**: Returns `true` if the specified key is present in the dictionary, otherwise `false`.

  Example:
  ```cpp
  bool exists = dict.isBelong(5);  // Check if key 5 is in the dictionary
  ```

#### Manipulation Functions:
- **`Insert(const KeyValuePair<K, V>& pair)`**: Inserts a key-value pair into the dictionary.

  Example:
  ```cpp
  KeyValuePair<int, std::string> pair = {1, "apple"};
  dict.Insert(pair);  // Insert the key-value pair into the dictionary
  ```

- **`Remove(const K& key)`**: Removes the key-value pair with the specified key from the dictionary.

  Example:
  ```cpp
  dict.Remove(5);  // Remove the key-value pair with key 5
  ```

- **`Map(const K& key)`**: Returns a vector of values associated with the given key. This function can handle multiple values for the same key.

  Example:
  ```cpp
  auto values = dict.Map(1);  // Get all values associated with key 1
  ```

- **`reduce(std::function<V(const V&, const V&)> reducer)`**: Applies a reduction function to combine values in the dictionary. The reducer function takes two values of type `V` and returns a new value.

  Example:
  ```cpp
  dict.reduce([](const std::string& v1, const std::string& v2) {
      return v1 + " " + v2;  // Combine string values by concatenation
  });
  ```

#### Operator Overloads:
- **`operator=`**: Assignment operator for copying the contents of another dictionary.

  Example:
  ```cpp
  dict = anotherDict;  // Copy the contents of anotherDict to dict
  ```

- **`operator[]`**: Accessor for the value associated with a given key. If the key is not found, it may throw an exception or return a default value, depending on the implementation.

  Example:
  ```cpp
  std::string value = dict[5];  // Access the value associated with key 5
  ```

- **`operator==`**: Checks if two dictionaries are equal (i.e., contain the same key-value pairs).

  Example:
  ```cpp
  if (dict == anotherDict) {
      // Dictionaries are equal
  }
  ```

- **`operator!=`**: Checks if two dictionaries are not equal.

  Example:
  ```cpp
  if (dict != anotherDict) {
      // Dictionaries are not equal
  }
  ```

- **`operator<<`**: Overloads the stream insertion (`<<`) operator to print the contents of the dictionary.

  Example:
  ```cpp
  std::cout << dict;  // Prints the dictionary contents
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `Dictionary` class:

```cpp
#include "Dictionary.hpp"
#include <iostream>

int main() {
    // Create a dictionary with integer keys and string values
    Dictionary<int, std::string> dict(10);

    // Insert key-value pairs into the dictionary
    dict.Insert({1, "apple"});
    dict.Insert({2, "banana"});
    dict.Insert({3, "cherry"});

    // Print the dictionary
    std::cout << "Dictionary contents: " << dict << std::endl;

    // Get the size of the dictionary
    std::cout << "Size of dictionary: " << dict.Size() << std::endl;

    // Check if a key exists in the dictionary
    std::cout << "Does key 2 exist? " << (dict.isBelong(2) ? "Yes" : "No") << std::endl;

    // Access a value using the key
    std::cout << "Value for key 2: " << dict[2] << std::endl;

    // Remove a key-value pair
    dict.Remove(2);
    std::cout << "After removing key 2: " << dict << std::endl;

    // Apply a reduce function (e.g., concatenate string values)
    dict.reduce([](const std::string& v1, const std::string& v2) {
        return v1 + " " + v2;
    });

    // Print the modified dictionary
    std::cout << "After reduce operation: " << dict << std::endl;

    return 0;
}
```

### Explanation:
- The code creates a `Dictionary` of integers as keys and strings as values.
- Key-value pairs are inserted using the `Insert()` method, and the dictionary is printed using the `operator<<`.
- The program checks the size of the dictionary and checks for the presence of a specific key.
- The `Remove()` function is used to remove a key-value pair, and a reduction operation is applied using the `reduce()` method to combine string values.

---

## Potential Errors & Edge Cases

1. **Key Not Found in `operator[]`**: If you attempt to access a key that does not exist, make sure to handle the case properly. Some implementations might throw an exception, while others may return a default value.

2. **Capacity Exceeded**: When inserting items into the dictionary, ensure that the dictionary resizes properly if the number of elements exceeds its initial capacity.

3. **Multiple Values for Same Key**: The `Map()` function may return multiple values for the same key. Ensure that the dictionary design handles this case if necessary.

4. **Memory Management**: Ensure proper memory handling, especially when copying dictionaries or handling dynamic memory for key-value pairs.

---

## Dependencies

- **C++ Standard Library**: This class uses `std::variant` for storing mixed types and `std::function` for the `reduce()` operation. Ensure you are using a C++17 or higher compiler for `std::variant` and `std::function`.
- **Other Includes**: This class includes `GeneralArray`, `Polynomial`, `SparseMatrix`, and `String` types, which should be properly defined and included.
