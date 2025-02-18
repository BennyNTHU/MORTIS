# **BinarySearchTree Documentation**

## **Overview**
The `BinarySearchTree<T>` class extends `BinaryTree<T>` and implements a binary search tree (BST) structure. It supports common BST operations such as **insertion**, **deletion**, **search**, and **splitting**. It maintains an ordered tree structure where the left subtree contains values smaller than the root, and the right subtree contains values greater than the root.

---

## **Class Definition**
```cpp
template <class T>
class BinarySearchTree : public BinaryTree<T> {
public:
    // Constructor & Destructor
    BinarySearchTree(const T& rootData);
    ~BinarySearchTree();

    // Core Operations
    T* Get(const T& key) const;             // Search for a key in the BST.
    T RankGet(int r) const;                 // Get the element at a specific rank.
    void Insert(const T& value);            // Insert a value into the BST.
    void Delete(const T& key);              // Delete a value from the BST.

    // Utility Methods
    static BinarySearchTree<T> JoinBST(const BinarySearchTree<T>& bst1, const BinarySearchTree<T>& bst2);
    static std::vector<BinarySearchTree<T>> SplitBST(const BinarySearchTree<T>& bst, const T& key);
};
```

---

## **Constructor & Destructor**
### **`BinarySearchTree(const T& rootData)`**
Creates a BST with an initial root node containing `rootData`.
```cpp
BinarySearchTree<int> bst(50);  // Creates a BST with root node value 50
```

### **`~BinarySearchTree()`**
Destructor to clean up the tree.
```cpp
BinarySearchTree<int>* bst = new BinarySearchTree<int>(50);
delete bst;  // Cleans up the tree
```

---

## **Insertion & Search**
### **`void Insert(const T& value)`**
Inserts a value into the BST, maintaining the BST property.
```cpp
BinarySearchTree<int> bst(50);
bst.Insert(30);
bst.Insert(70);
bst.Insert(20);
bst.Insert(40);
bst.Insert(60);
bst.Insert(80);
```
### **`T* Get(const T& key) const`**
Searches for `key` in the BST and returns a pointer to the value if found, otherwise returns `nullptr`.
```cpp
int* result = bst.Get(40);
if (result) {
    std::cout << "Found: " << *result << std::endl;
    delete result;  // Clean up the allocated memory
} else {
    std::cout << "Not Found" << std::endl;
}
```

---

## **Rank-Based Retrieval**
### **`T RankGet(int r) const`**
Retrieves the element at rank `r` (0-indexed) in an **in-order traversal**.
```cpp
std::cout << "Element at rank 2: " << bst.RankGet(2) << std::endl;
```

---

## **Deletion**
### **`void Delete(const T& key)`**
Deletes a node with `key` from the BST.
- If the node has **two children**, it replaces it with its in-order successor.
- If the node has **one child**, the child is linked to the parent.
- If the node is a **leaf**, it is simply removed.
```cpp
bst.Delete(70);  // Removes node 70
bst.Delete(50);  // Removes node 50 (root replacement)
```

---

## **Joining and Splitting**
### **`BinarySearchTree<T> JoinBST(const BinarySearchTree<T>& bst1, const BinarySearchTree<T>& bst2)`**
Merges two BSTs into one by inserting all elements from `bst2` into `bst1`.
```cpp
BinarySearchTree<int> bst1(25);
bst1.Insert(15);
bst1.Insert(35);

BinarySearchTree<int> bst2(75);
bst2.Insert(65);
bst2.Insert(85);

BinarySearchTree<int> joinedBST = BinarySearchTree<int>::JoinBST(bst1, bst2);
std::cout << "Joined BST: " << joinedBST << std::endl;
```

### **`std::vector<BinarySearchTree<T>> SplitBST(const BinarySearchTree<T>& bst, const T& key)`**
Splits the BST into **two separate BSTs**:
- The first contains values `< key`.
- The second contains values `>= key`.
```cpp
std::vector<BinarySearchTree<int>> splitTrees = BinarySearchTree<int>::SplitBST(bst, 50);
std::cout << "BST with elements < 50: " << splitTrees[0] << std::endl;
std::cout << "BST with elements >= 50: " << splitTrees[1] << std::endl;
```

---

## **Example Program**
```cpp
#include <iostream>
#include "BinarySearchTree.hpp"

int main() {
    std::cout << "=== BinarySearchTree Demo ===" << std::endl;

    // Create and populate the BST
    BinarySearchTree<int> bst(50);
    bst.Insert(30);
    bst.Insert(70);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(60);
    bst.Insert(80);

    // Print the BST
    std::cout << "Initial BST: " << bst << std::endl;

    // Search elements
    int* searchResult = bst.Get(40);
    if (searchResult) {
        std::cout << "Found: " << *searchResult << std::endl;
        delete searchResult;
    } else {
        std::cout << "Not found." << std::endl;
    }

    // Retrieve elements by rank
    std::cout << "Element at rank 2: " << bst.RankGet(2) << std::endl;

    // Split the BST
    auto splitTrees = BinarySearchTree<int>::SplitBST(bst, 50);
    std::cout << "BST < 50: " << splitTrees[0] << std::endl;
    std::cout << "BST >= 50: " << splitTrees[1] << std::endl;

    // Delete elements
    bst.Delete(70);
    std::cout << "After deleting 70: " << bst << std::endl;

    bst.Delete(50);
    std::cout << "After deleting 50: " << bst << std::endl;

    std::cout << "=== End of BinarySearchTree Demo ===" << std::endl;
    return 0;
}
```

---

## **Conclusion**
This documentation covers the implementation and usage of the `BinarySearchTree<T>` class. It includes:
- **Basic operations** like **insertion, deletion, and searching**.
- **Rank-based retrieval** using `RankGet()`.
- **Joining and splitting** BSTs.
- **Complete example program** demonstrating how to use the BST API.

This provides a comprehensive guide for developers to use the **BinarySearchTree** effectively in their applications.
