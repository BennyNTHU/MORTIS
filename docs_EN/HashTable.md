# HashTable Documentation

## Overview

The **HashTable** class is a templated hash table implementation that supports separate chaining to handle collisions. It uses a **Doubly Linked List** to store elements that hash to the same index.

This hash table supports storing the following types **separately**:
- `int`
- `char`
- `std::string` (C++ built-in string type)

---

## Table of Contents
- [HashTable Documentation](#hashtable-documentation)
  - [Overview](#overview)
  - [Table of Contents](#table-of-contents)
  - [Class Definition](#class-definition)
  - [Constructor](#constructor)
    - [`HashTable(size_t size)`](#hashtablesize_t-size)
  - [Destructor](#destructor)
    - [`~HashTable()`](#hashtable)
  - [Public Methods](#public-methods)
    - [`void insert(const T& key)`](#void-insertconst-t-key)
    - [`bool search(const T& key) const`](#bool-searchconst-t-key-const)
    - [`bool remove(const T& key)`](#bool-removeconst-t-key)
    - [`void display() const`](#void-display-const)
  - [Example Usage](#example-usage)
  - [Conclusion](#conclusion)

---

## Class Definition

```cpp
template <typename T>
class HashTable {
public:
    explicit HashTable(size_t size);
    ~HashTable();

    void insert(const T& key);
    bool search(const T& key) const;
    bool remove(const T& key);
    void display() const;

private:
    size_t hashFunction(const T& key) const;
    size_t capacity;
    std::vector<DoublyLinkedList<T>> table;
};
```

---

## Constructor

### `HashTable(size_t size)`
**Description:**  
Creates a hash table with the given number of buckets.

**Parameters:**
- `size_t size` – The number of buckets in the hash table.

**Example:**
```cpp
HashTable<int> intTable(10);  // Creates an integer hash table with 10 buckets.
```

---

## Destructor

### `~HashTable()`
**Description:**  
Destroys the hash table and frees up memory.

**Example:**
```cpp
{
    HashTable<char> charTable(10);
} // Automatically destroyed when it goes out of scope.
```

---

## Public Methods

### `void insert(const T& key)`
**Description:**  
Inserts a new key into the hash table. If the key already exists, it is **not** inserted again.

**Parameters:**
- `const T& key` – The key to be inserted.

**Example:**
```cpp
HashTable<int> table(5);
table.insert(42);
table.insert(21);
table.insert(42); // Duplicate, will not be inserted again.
```

---

### `bool search(const T& key) const`
**Description:**  
Searches for a key in the hash table.

**Parameters:**
- `const T& key` – The key to be searched.

**Returns:**
- `true` – If the key exists in the table.
- `false` – If the key does not exist.

**Example:**
```cpp
HashTable<std::string> strTable(5);
strTable.insert("apple");

if (strTable.search("apple")) {
    std::cout << "Found apple!" << std::endl;
} else {
    std::cout << "Apple not found." << std::endl;
}
```

---

### `bool remove(const T& key)`
**Description:**  
Removes a key from the hash table if it exists.

**Parameters:**
- `const T& key` – The key to be removed.

**Returns:**
- `true` – If the key was found and removed.
- `false` – If the key was not found.

**Example:**
```cpp
HashTable<char> charTable(5);
charTable.insert('A');
charTable.insert('B');

charTable.remove('A');  // Removes 'A'
charTable.remove('X');  // Returns false, since 'X' doesn't exist
```

---

### `void display() const`
**Description:**  
Displays the contents of the hash table.

**Example:**
```cpp
HashTable<int> table(5);
table.insert(12);
table.insert(7);
table.insert(42);

table.display();  
```

**Possible Output:**
```
Bucket 0: nullptr
Bucket 1: 7 -> nullptr
Bucket 2: 12 -> nullptr
Bucket 3: nullptr
Bucket 4: 42 -> nullptr
```

---

## Example Usage

Here is a full example that demonstrates the usage of the **HashTable** class with different data types:

```cpp
#include <iostream>
#include "HashTable.hpp"

int main() {
    // Integer Hash Table
    HashTable<int> intTable(10);
    intTable.insert(10);
    intTable.insert(20);
    intTable.insert(30);
    std::cout << "Integer Hash Table:" << std::endl;
    intTable.display();

    // Char Hash Table
    HashTable<char> charTable(5);
    charTable.insert('A');
    charTable.insert('B');
    charTable.insert('C');
    std::cout << "\nChar Hash Table:" << std::endl;
    charTable.display();

    // String Hash Table
    HashTable<std::string> strTable(7);
    strTable.insert("hello");
    strTable.insert("world");
    strTable.insert("hash");
    std::cout << "\nString Hash Table:" << std::endl;
    strTable.display();

    // Searching
    std::cout << "\nSearching for 'hello' in String Hash Table: " 
              << (strTable.search("hello") ? "Found" : "Not Found") << std::endl;

    // Removing
    strTable.remove("hello");
    std::cout << "\nAfter removing 'hello':" << std::endl;
    strTable.display();

    return 0;
}
```

**Expected Output:**
```
Integer Hash Table:
Bucket 0: nullptr
Bucket 1: 10 -> nullptr
Bucket 2: 20 -> nullptr
Bucket 3: 30 -> nullptr
...

Char Hash Table:
Bucket 0: nullptr
Bucket 1: A -> nullptr
Bucket 2: B -> nullptr
Bucket 3: C -> nullptr
...

String Hash Table:
Bucket 0: nullptr
Bucket 1: hash -> nullptr
Bucket 2: world -> nullptr
Bucket 3: hello -> nullptr
...

Searching for 'hello' in String Hash Table: Found

After removing 'hello':
Bucket 0: nullptr
Bucket 1: hash -> nullptr
Bucket 2: world -> nullptr
Bucket 3: nullptr
...
```

---

## Conclusion

This documentation provides a detailed guide on how to use the `HashTable` class, including its:
- **Constructor**
- **Insert** function
- **Search** function
- **Remove** function
- **Display** function
- **Example usage** of different data types

By following the examples, users can efficiently store and manage their data using the **HashTable** class.
