# Set Class API Documentation

The `Set` class is implemented as a specialization of a Binary Search Tree (BST) and supports typical set operations. It is defined in terms of the underlying BinarySearchTree and BinaryTree classes. All elements are maintained in sorted order, and in‐order traversal returns the elements in increasing order.

> **Note:** In our implementation the class uses the inherited methods from `BinarySearchTree` and `BinaryTree` (such as `InorderIterator()`, `Insert()`, `Get()`, and `Clear()`). For const functions that require traversal (which is implemented in non‑const methods), we use `const_cast` (with due care).

---

## Constructors

### `Set()`
Creates an empty set.

**Example:**
```cpp
Set<int> s;  // Creates an empty set of integers.
```

### `Set(std::initializer_list<T> elements)`
Creates a set containing the elements in the initializer list. (Duplicate elements are not stored multiple times.)

**Example:**
```cpp
Set<int> s = {10, 20, 30, 40, 50};
```

---

## Member Functions

### `void Insert(const T& value)`
Inserts a value into the set. The underlying BST is used to keep the data sorted.

**Usage Example:**
```cpp
Set<int> s;
s.Insert(15);
s.Insert(10);
s.Insert(20);
```

### `T* Get(const T& value) const`
Searches for the given value. If found, returns a pointer to a copy of the value; otherwise, returns `nullptr`.

**Usage Example:**
```cpp
Set<int> s = {15, 10, 20};
int* found = s.Get(10);
if (found) {
    std::cout << "Found: " << *found << std::endl;
    delete found;
} else {
    std::cout << "Not found." << std::endl;
}
```

### `Set<T> Union(const Set<T>& other) const`
Returns a new set that is the union of this set and another.  
*Example:* If A = {1, 2, 3} and B = {3, 4, 5}, then A ∪ B = {1, 2, 3, 4, 5}.

**Usage Example:**
```cpp
Set<int> A = {1, 2, 3};
Set<int> B = {3, 4, 5};
Set<int> unionSet = A.Union(B);
unionSet.Print();  // Expected output: { 1 2 3 4 5 }
```

### `Set<T> Intersection(const Set<T>& other) const`
Returns a new set that is the intersection of this set and another.  
*Example:* If A = {1, 2, 3} and B = {2, 3, 4}, then A ∩ B = {2, 3}.

**Usage Example:**
```cpp
Set<int> A = {1, 2, 3};
Set<int> B = {2, 3, 4};
Set<int> intersectSet = A.Intersection(B);
intersectSet.Print();  // Expected output: { 2 3 }
```

### `Set<T> Difference(const Set<T>& other) const`
Returns a new set that is the difference between this set and another (elements in this set that are not in the other).  
*Example:* If A = {1, 2, 3, 4} and B = {3, 4, 5}, then A – B = {1, 2}.

**Usage Example:**
```cpp
Set<int> A = {1, 2, 3, 4};
Set<int> B = {3, 4, 5};
Set<int> diffSet = A.Difference(B);
diffSet.Print();  // Expected output: { 1 2 }
```

### `bool IsSubsetOf(const Set<T>& other) const`
Returns `true` if every element of this set is contained in the other set, `false` otherwise.

**Usage Example:**
```cpp
Set<int> A = {1, 2};
Set<int> B = {1, 2, 3};
std::cout << (A.IsSubsetOf(B) ? "A is a subset of B" : "A is not a subset of B") << std::endl;
```

### `bool Contains(const T& value) const`
Returns `true` if the set contains the specified value.

**Usage Example:**
```cpp
Set<int> s = {10, 20, 30};
std::cout << (s.Contains(20) ? "Set contains 20" : "Set does not contain 20") << std::endl;
```

### `void Print() const`
Prints the elements of the set in sorted order (using in‑order traversal).

**Usage Example:**
```cpp
Set<int> s = {30, 10, 20};
s.Print();  // Expected output: { 10 20 30 }
```

### `std::vector<T> InorderIterator()`
Returns a vector containing the in‑order traversal of the set’s elements.

**Usage Example:**
```cpp
Set<int> s = {3, 1, 2};
std::vector<int> inorder = s.InorderIterator();
for (int val : inorder) {
    std::cout << val << " ";
}
std::cout << std::endl;  // Expected output: 1 2 3
```

---

## Example Program

Below is a complete example program that demonstrates the use of the Set APIs:

```cpp
#include <iostream>
#include "Set.hpp"  // Make sure to include the Set header file

using namespace std;

int main() {
    cout << "=== Set Test Program ===" << endl << endl;
    
    // Create two sets using initializer lists.
    Set<int> setA = {1, 2, 3, 4, 5};
    Set<int> setB = {4, 5, 6, 7, 8};
    
    cout << "Set A: ";
    setA.Print();
    cout << "Set B: ";
    setB.Print();
    
    // Test union
    Set<int> unionSet = setA.Union(setB);
    cout << "Union of A and B: ";
    unionSet.Print();
    
    // Test intersection
    Set<int> intersectSet = setA.Intersection(setB);
    cout << "Intersection of A and B: ";
    intersectSet.Print();
    
    // Test difference (A - B)
    Set<int> diffSet = setA.Difference(setB);
    cout << "Difference (A - B): ";
    diffSet.Print();
    
    // Test subset operation
    Set<int> subset = {2, 3};
    cout << "Subset: ";
    subset.Print();
    cout << "Is subset a subset of A? " << (subset.IsSubsetOf(setA) ? "Yes" : "No") << endl;
    
    // Test Contains
    cout << "Does A contain 3? " << (setA.Contains(3) ? "Yes" : "No") << endl;
    cout << "Does B contain 3? " << (setB.Contains(3) ? "Yes" : "No") << endl;
    
    // Test InorderIterator
    std::vector<int> inorder = setA.InorderIterator();
    cout << "In-order traversal of Set A: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Expected Output:**

```
=== Set Test Program ===

Set A: { 1 2 3 4 5 }
Set B: { 4 5 6 7 8 }
Union of A and B: { 1 2 3 4 5 6 7 8 }
Intersection of A and B: { 4 5 }
Difference (A - B): { 1 2 3 }
Subset: { 2 3 }
Is subset a subset of A? Yes
Does A contain 3? Yes
Does B contain 3? No
In-order traversal of Set A: 1 2 3 4 5
```

---

## Additional Notes

- **Complexity:** Since the underlying data structure is a binary search tree, the average complexity for insertion, search, and deletion is O(log n) (although worst-case can be O(n) if the tree becomes unbalanced).
- **Const-correctness:** In some member functions (e.g., those using `InorderIterator()`), you may notice the use of `const_cast` to call non‑const functions. This is a workaround because the base class function is not declared as const. If possible, consider refactoring the base class to provide a const version of the traversal methods.
- **Threaded Pointers:** The underlying BinaryTree class uses threading (pointers for in‑order predecessor/successor). Users of the Set API do not need to worry about these details.

---

## Conclusion

The `Set` class provides a convenient interface for performing set operations (union, intersection, difference, subset checking, etc.) while maintaining sorted order via a binary search tree. Use the API as shown in the example program to manage your data sets efficiently.
