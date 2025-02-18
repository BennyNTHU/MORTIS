# BloomFilter Documentation

## Overview

The **`BloomFilter`** is a probabilistic data structure used to test whether an element is a member of a set. It may return **false positives** but never **false negatives**. The `BloomFilter` class supports **integers (`int`), characters (`char`), and C++ `std::string`**.

---

## Features

- **Insert elements** into the Bloom filter.
- **Search for elements** (may return false positives but never false negatives).
- **Display the bit array**.
- **Uses multiple hash functions** to minimize false positives.

---

## Class Definition

```cpp
template <typename T>
class BloomFilter {
public:
    BloomFilter(size_t size, size_t hashFunctions);  // Constructor
    void insert(const T& key);       // Insert an element
    bool search(const T& key) const; // Search for an element
    void display() const;            // Display the bit array

private:
    size_t size;               // Size of the Bloom filter
    size_t hashFunctions;      // Number of hash functions
    std::vector<bool> bitArray;// Bit array representing the Bloom filter
    std::vector<std::function<size_t(const T&)>> hashFunctionsList; // List of hash functions

    size_t hash1(const T& key) const; // First hash function
    size_t hash2(const T& key) const; // Second hash function
    size_t hash3(const T& key) const; // Third hash function
};
```

---

## Constructor

```cpp
BloomFilter(size_t size, size_t hashFunctions);
```

### Description:
- Initializes a Bloom filter of a given size.
- Uses multiple hash functions for better performance.

### Parameters:
- `size_t size`: Size of the bit array.
- `size_t hashFunctions`: Number of hash functions.

### Example:

```cpp
BloomFilter<int> intFilter(100, 3);
BloomFilter<char> charFilter(50, 3);
BloomFilter<std::string> stringFilter(200, 3);
```

---

## Insert an Element

```cpp
void insert(const T& key);
```

### Description:
- Inserts an element into the Bloom filter by hashing it multiple times.
- Sets the corresponding bits in the bit array.

### Example:

```cpp
intFilter.insert(42);
charFilter.insert('A');
stringFilter.insert("hello");
```

---

## Search for an Element

```cpp
bool search(const T& key) const;
```

### Description:
- Checks if an element exists in the Bloom filter.
- **False positives are possible** (i.e., it may return `true` for a value not actually inserted).
- **False negatives are not possible** (i.e., if it returns `false`, the element is definitely not present).

### Example:

```cpp
std::cout << intFilter.search(42) << std::endl; // Output: 1 (true)
std::cout << charFilter.search('B') << std::endl; // Output: 0 (false)
std::cout << stringFilter.search("hello") << std::endl; // Output: 1 (true)
```

---

## Display the Bit Array

```cpp
void display() const;
```

### Description:
- Displays the bit array, showing which bits have been set.

### Example:

```cpp
intFilter.display();  // Example output: 000100000010000000...
charFilter.display(); // Example output: 000001000100000...
stringFilter.display(); // Example output: 000100001010100...
```

---

## Hash Functions

### `size_t hash1(const T& key) const`
- Uses **C++'s built-in `std::hash<T>`** function.

### `size_t hash2(const T& key) const`
- Uses **Knuth's Multiplicative Hashing**.

### `size_t hash3(const T& key) const`
- Uses **a simple polynomial hash**.

---

## Full Example Program

```cpp
#include <iostream>
#include "BloomFilter.hpp"

int main() {
    // Create BloomFilter instances
    BloomFilter<int> intFilter(100, 3);
    BloomFilter<char> charFilter(50, 3);
    BloomFilter<std::string> stringFilter(200, 3);

    // Insert elements
    intFilter.insert(42);
    charFilter.insert('A');
    stringFilter.insert("hello");

    // Display the bit array
    std::cout << "Bit array for int filter: ";
    intFilter.display();

    std::cout << "Bit array for char filter: ";
    charFilter.display();

    std::cout << "Bit array for string filter: ";
    stringFilter.display();

    // Search for elements
    std::cout << "Searching for 42 in int filter: " << intFilter.search(42) << std::endl;
    std::cout << "Searching for 'B' in char filter: " << charFilter.search('B') << std::endl;
    std::cout << "Searching for \"hello\" in string filter: " << stringFilter.search("hello") << std::endl;
    std::cout << "Searching for \"world\" in string filter: " << stringFilter.search("world") << std::endl;

    return 0;
}
```

### Expected Output:

```
Bit array for int filter: 000100000010000000...
Bit array for char filter: 000001000100000...
Bit array for string filter: 000100001010100...
Searching for 42 in int filter: 1
Searching for 'B' in char filter: 0
Searching for "hello" in string filter: 1
Searching for "world" in string filter: 0
```

---

## Summary

| **Function**          | **Description** |
|----------------------|----------------------------------------|
| `BloomFilter(size_t, size_t)` | Creates a Bloom filter of given size with multiple hash functions. |
| `void insert(const T&)` | Inserts an element into the Bloom filter. |
| `bool search(const T&)` | Searches for an element (may return false positives). |
| `void display() const` | Displays the bit array. |

This **`BloomFilter`** is useful for:
- **Checking membership quickly**.
- **Reducing memory usage** compared to traditional sets.
- **Avoiding false negatives**, making it ideal for use cases where missing data is more problematic than extra data.
- 