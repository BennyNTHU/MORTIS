# `Set` Documentation

## Overview

The `Set.hpp` file defines a `Set` class template that represents a set of unique elements, implemented using a binary search tree (BST). The class provides several set operations like union, intersection, difference, and subset checking, along with a method to check for membership. It supports initialization using an initializer list and provides methods for printing the set.

The `Set` class is a specialized form of the `BinarySearchTree` that ensures all elements are unique, leveraging the BST's efficient search and insertion methods.

---

## Key Components

### `Set` Class

The `Set` class is a derived class from the `BinarySearchTree` class and provides additional functionality specific to sets.

#### Member Variables:
- **Inherited from `BinarySearchTree<T>`**: The `Set` class inherits all member variables from the `BinarySearchTree`, which includes the root node and tree structure. The underlying structure is a binary search tree where each node contains an element of type `T`.

---

### Constructors

- **`Set()`**: Default constructor that creates an empty set. The set uses a default value of type `T()` as the initial value.

  Example:
  ```cpp
  Set<int> mySet;  // Creates an empty set of integers
  ```

- **`Set(std::initializer_list<T> elements)`**: Constructor that initializes the set with a list of elements provided in the initializer list.

  Example:
  ```cpp
  Set<int> mySet = {1, 2, 3};  // Creates a set with elements 1, 2, and 3
  ```

---

### Set Operations

- **`Set<T> Union(const Set<T>& other) const`**: Returns a new set that is the union of this set and another set `other`. The union includes all elements that are in either set.

  Example:
  ```cpp
  Set<int> set1 = {1, 2, 3};
  Set<int> set2 = {3, 4, 5};
  Set<int> result = set1.Union(set2);  // Result: {1, 2, 3, 4, 5}
  ```

- **`Set<T> Intersection(const Set<T>& other) const`**: Returns a new set that is the intersection of this set and another set `other`. The intersection contains only elements that are present in both sets.

  Example:
  ```cpp
  Set<int> set1 = {1, 2, 3};
  Set<int> set2 = {2, 3, 4};
  Set<int> result = set1.Intersection(set2);  // Result: {2, 3}
  ```

- **`Set<T> Difference(const Set<T>& other) const`**: Returns a new set that is the difference of this set and another set `other`. The difference contains elements that are in this set but not in `other`.

  Example:
  ```cpp
  Set<int> set1 = {1, 2, 3};
  Set<int> set2 = {2, 3, 4};
  Set<int> result = set1.Difference(set2);  // Result: {1}
  ```

- **`bool IsSubsetOf(const Set<T>& other) const`**: Returns `true` if every element in this set is also in the set `other`. Otherwise, it returns `false`.

  Example:
  ```cpp
  Set<int> set1 = {1, 2};
  Set<int> set2 = {1, 2, 3};
  bool result = set1.IsSubsetOf(set2);  // Result: true
  ```

- **`bool Contains(const T& value) const`**: Returns `true` if the set contains the element `value`, otherwise returns `false`.

  Example:
  ```cpp
  Set<int> set = {1, 2, 3};
  bool result = set.Contains(2);  // Result: true
  ```

---

### Printing Method

- **`void Print() const`**: Prints the elements of the set to `std::cout`. The elements are printed in ascending order due to the in-order traversal of the BST.

  Example:
  ```cpp
  Set<int> set = {3, 1, 2};
  set.Print();  // Output: 1 2 3
  ```

---

## Example Usage

Here’s an example demonstrating how to use the `Set` class:

```cpp
#include "Set.hpp"
#include <iostream>

int main() {
    // Create sets using initializer lists
    Set<int> set1 = {1, 2, 3};
    Set<int> set2 = {2, 3, 4};

    // Union of two sets
    Set<int> unionSet = set1.Union(set2);
    std::cout << "Union: ";
    unionSet.Print();  // Output: 1 2 3 4

    // Intersection of two sets
    Set<int> intersectionSet = set1.Intersection(set2);
    std::cout << "Intersection: ";
    intersectionSet.Print();  // Output: 2 3

    // Difference of two sets
    Set<int> differenceSet = set1.Difference(set2);
    std::cout << "Difference: ";
    differenceSet.Print();  // Output: 1

    // Check if set1 is a subset of set2
    bool isSubset = set1.IsSubsetOf(set2);
    std::cout << "Is set1 a subset of set2? " << (isSubset ? "Yes" : "No") << std::endl;

    // Check if a set contains a specific element
    bool contains = set1.Contains(2);
    std::cout << "Does set1 contain 2? " << (contains ? "Yes" : "No") << std::endl;

    return 0;
}
```

### Explanation:
- The code creates two sets, `set1` and `set2`, using initializer lists.
- It demonstrates how to compute the union, intersection, and difference of sets.
- The `Print()` method is used to display the elements of each resulting set.
- The program checks if `set1` is a subset of `set2` and if `set1` contains the value `2`.

---

## Potential Errors & Edge Cases

1. **Empty Sets**: Operations like union, intersection, and difference on empty sets should be handled properly. For example, the union of an empty set with any set is the non-empty set, and the intersection of any set with an empty set is an empty set.

2. **Handling Duplicates**: The `Set` class ensures that elements are unique. If duplicate elements are inserted, only one instance will remain in the set, as the `BinarySearchTree` ensures uniqueness during insertion.

3. **Invalid Set Operations**: Make sure that methods like `IsSubsetOf()` and `Contains()` are used with valid sets. For example, calling `IsSubsetOf()` with a set that is not fully initialized may lead to undefined behavior.

---

## Dependencies

- **`BinarySearchTree.hpp`**: The `Set` class inherits from the `BinarySearchTree<T>` class. Make sure the `BinarySearchTree` class is correctly implemented, including the required methods for insertion, traversal, and deletion of nodes.
