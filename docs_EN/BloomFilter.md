# `BloomFilter.hpp` Documentation

## Overview

The `BloomFilter.hpp` header file defines a `BloomFilter` class template that implements a Bloom Filter data structure. It supports adding elements, checking if an element is present in the set, and displaying the internal bit array. The class uses multiple hash functions to map elements to positions in the bit array. The number of hash functions and the size of the bit array can be customized.

---

## Key Components

### `BloomFilter` Class

The `BloomFilter` class allows for the efficient insertion and search of elements in a set using a bit array and hash functions. It is designed to provide fast membership testing with a trade-off of allowing false positives.

#### Member Variables:
- **`size`**: The size of the Bloom filter bit array.
- **`hashFunctions`**: The number of hash functions used to insert and check elements.
- **`bitArray`**: A bit array that stores the Bloom filter's state.
- **`hashFunctionsList`**: A vector of hash functions used to calculate positions in the bit array.

#### Hash Functions:
- **`hash1`**: A hash function for the first hash.
- **`hash2`**: A hash function for the second hash.
- **`hash3`**: A hash function for the third hash.

#### Constructors & Destructor:
- **`BloomFilter(size_t size = DEFAULT_SIZE, size_t hashFunctions = DEFAULT_HASH_FUNCTIONS)`**: Constructor that initializes the Bloom filter with a specified size and the number of hash functions. By default, it uses a size of 1000 and 3 hash functions.

  Example:
  ```cpp
  BloomFilter<std::string> filter;  // Create a Bloom filter for strings with default size and hash functions
  ```

#### Public Methods:

- **`void insert(const T& key)`**: Inserts the element `key` into the Bloom filter. This method applies each of the hash functions to map the element to positions in the bit array and sets those positions to `true`.

  Example:
  ```cpp
  filter.insert("apple");  // Insert "apple" into the Bloom filter
  ```

- **`bool search(const T& key) const`**: Checks if the element `key` is present in the Bloom filter. It applies the hash functions and checks if all the corresponding positions in the bit array are `true`. If any of the positions is `false`, the element is definitely not in the set. If all positions are `true`, the element may be in the set (with a possibility of false positive).

  Example:
  ```cpp
  bool exists = filter.search("apple");  // Check if "apple" is in the Bloom filter
  ```

- **`void display() const`**: Displays the current state of the Bloom filter's bit array, showing which positions are set to `true`.

  Example:
  ```cpp
  filter.display();  // Display the current state of the Bloom filter's bit array
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `BloomFilter` class:

```cpp
#include "BloomFilter.hpp"
#include <iostream>

int main() {
    // Create a Bloom filter for strings with default size and 3 hash functions
    BloomFilter<std::string> filter;

    // Insert elements into the Bloom filter
    filter.insert("apple");
    filter.insert("banana");
    filter.insert("grape");

    // Check if elements are in the Bloom filter
    std::cout << "Is 'apple' in the filter? " << (filter.search("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'orange' in the filter? " << (filter.search("orange") ? "Yes" : "No") << std::endl;

    // Display the current state of the Bloom filter's bit array
    filter.display();

    return 0;
}
```

### Explanation:
- The code creates a `BloomFilter` instance for `std::string` types with the default size and number of hash functions.
- It inserts several fruit names into the Bloom filter and then checks if specific fruits are in the filter.
- The `display()` method shows the current state of the bit array, allowing the user to see the positions that have been set to `true`.

---

## Potential Errors & Edge Cases

1. **False Positives**: The Bloom filter may return `true` for an element that was never inserted. This is called a false positive. The likelihood of this occurring increases as more elements are added to the filter. You can reduce the chance of false positives by increasing the size of the bit array or the number of hash functions.

2. **False Negatives**: The Bloom filter is guaranteed to never produce false negatives. If the filter indicates that an element is not in the set, it is definitely not present.

3. **Hash Collisions**: If two distinct elements produce the same hash values (collisions), they may result in false positives. The number of hash functions used can influence the occurrence of hash collisions.

4. **Bit Array Overflow**: If too many elements are inserted into the Bloom filter, the bit array may overflow, increasing the chances of false positives. Consider resizing the bit array if you expect a large number of elements.

---

## Dependencies

- **C++ Standard Library**: The class uses standard library components like `std::vector`, `std::bitset`, and `std::function`.
- **Hash Functions**: The class uses three default hash functions for insertion and search operations. These are implemented as simple hashes, but they can be customized if needed.
