# HashTable.hpp Documentation

## Overview

The `HashTable.hpp` header file defines a template class `HashTable` that implements a hash table data structure. A hash table is a collection of key-value pairs where keys are mapped to indices in an array using a hash function. This implementation uses separate chaining (via `DoublyLinkedList`) to handle collisions, meaning that multiple keys that hash to the same index are stored in a linked list at that index.

The `HashTable` class supports insertion, search, and removal of keys, and it can handle multiple data types.

## Class: `HashTable<T>`

### Description
The `HashTable<T>` class is a template class that represents a hash table. It uses a vector of `DoublyLinkedList<T>` to store the keys, and a hash function to map keys to indices in the vector.

### Template Parameters
- `T`: The type of keys stored in the hash table.

### Constructors and Destructor

#### `explicit HashTable(size_t size)`
- **Description**: Constructor. Initializes a hash table with a specified capacity.
- **Parameters**:
  - `size`: The capacity of the hash table (number of buckets).
- **Usage**:
  ```cpp
  HashTable<int> hashTable(10);  // Creates a hash table with 10 buckets
  ```

#### `~HashTable()`
- **Description**: Destructor. Cleans up the hash table by deleting all elements.
- **Usage**: Automatically called when the object goes out of scope.

### Methods

#### `void insert(const T& key)`
- **Description**: Inserts a key into the hash table.
- **Parameters**:
  - `key`: The key to insert.
- **Usage**:
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);  // Inserts the key 42 into the hash table
  ```

#### `bool search(const T& key) const`
- **Description**: Searches for a key in the hash table.
- **Parameters**:
  - `key`: The key to search for.
- **Return Value**: `true` if the key is found, `false` otherwise.
- **Usage**:
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);
  bool found = hashTable.search(42);  // found is true
  ```

#### `bool remove(const T& key)`
- **Description**: Removes a key from the hash table.
- **Parameters**:
  - `key`: The key to remove.
- **Return Value**: `true` if the key was found and removed, `false` otherwise.
- **Usage**:
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);
  bool removed = hashTable.remove(42);  // removed is true
  ```

#### `void display() const`
- **Description**: Displays the contents of the hash table.
- **Usage**:
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);
  hashTable.display();  // Prints the contents of the hash table
  ```

### Private Methods

#### `size_t hashFunction(const T& key) const`
- **Description**: The hash function used to map keys to indices in the hash table.
- **Parameters**:
  - `key`: The key to hash.
- **Return Value**: The index in the hash table where the key should be stored.
- **Usage**: This method is used internally by the `insert`, `search`, and `remove` methods.

## Example Usage

```cpp
#include "HashTable.hpp"
#include <iostream>

int main() {
    // Create a hash table with 10 buckets
    HashTable<int> hashTable(10);

    // Insert some keys
    hashTable.insert(42);
    hashTable.insert(15);
    hashTable.insert(7);
    hashTable.insert(23);

    // Search for a key
    bool found = hashTable.search(15);
    std::cout << "Key 15 found: " << std::boolalpha << found << std::endl;

    // Remove a key
    bool removed = hashTable.remove(7);
    std::cout << "Key 7 removed: " << std::boolalpha << removed << std::endl;

    // Display the hash table
    hashTable.display();

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Hash Collisions**: The hash table uses separate chaining to handle collisions, but excessive collisions can degrade performance. Ensure that the hash function distributes keys evenly across the buckets.
2. **Invalid Key Types**: The hash function must be compatible with the key type `T`. If `T` is a custom type, ensure that a suitable hash function is implemented.
3. **Empty Hash Table**: Searching or removing keys from an empty hash table will return `false`. Ensure that the hash table is not empty before performing these operations.
4. **Memory Management**: When dynamically allocating keys, ensure proper cleanup to avoid memory leaks.

## Dependencies

- **DoublyLinkedList.hpp**: The `HashTable` class uses `DoublyLinkedList` to handle collisions. Ensure that this file is included and properly configured in your project.
- **DLIterator.hpp**: The `HashTable` class uses `DLIterator` for iterating over the linked lists. Ensure that this file is included and properly configured.
- **DoubleNode.hpp**: The `HashTable` class uses `DoubleNode` for the nodes in the linked lists. Ensure that this file is included and properly configured.
- **Standard Library**: The header file includes `<iostream>` and `<vector>`, which are part of the C++ Standard Library. Ensure that your environment is configured to use the standard library.

## Summary

The `HashTable.hpp` file provides a flexible implementation of a hash table data structure, supporting insertion, search, and removal of keys. By following the examples and guidelines provided, you can effectively use this class to build and manipulate hash tables in your projects.
