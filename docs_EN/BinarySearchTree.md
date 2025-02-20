The `BinarySearchTree.hpp` file defines a `BinarySearchTree` (BST) class template, which is a specialized subclass of a `BinaryTree`. The class is designed to store values of type `T` in a binary search tree (BST) structure. It provides methods for searching, inserting, deleting, and manipulating the tree, including joining and splitting BSTs. The class also disables some functions from the `BinaryTree` class that are not applicable to a binary search tree.

Here is the markdown documentation for the `BinarySearchTree.hpp` header file:

---

# `BinarySearchTree.hpp` Documentation

## Overview

The `BinarySearchTree.hpp` file defines a templated `BinarySearchTree` class that extends a `BinaryTree` class. This class is specifically designed for binary search tree operations and supports searching, insertion, deletion, and advanced operations like joining and splitting two BSTs. It ensures that the tree remains sorted according to the BST property (i.e., left child < parent < right child).

---

## Key Components

### `BinarySearchTree` Class

The `BinarySearchTree` class inherits from the `BinaryTree<T>` class and adds methods specific to binary search trees, such as `Insert`, `Delete`, `RankGet`, and more.

#### Member Variables:
- **`rootData`**: The root value of the binary search tree.
- **`BinaryTree` members**: Inherited from the `BinaryTree` class, these handle the tree's structure, including the root node and its children.

---

### Constructors & Destructor

- **`BinarySearchTree(const T& rootData)`**: Constructor that creates a binary search tree with the specified initial value `rootData` as the root.

  Example:
  ```cpp
  BinarySearchTree<int> bst(10);  // Creates a BST with root value 10
  ```

- **`~BinarySearchTree()`**: Destructor that cleans up the binary search tree and deallocates memory for the nodes.

  Example:
  ```cpp
  // Automatically cleans up the BST when it goes out of scope
  ```

---

### Search Methods

- **`T* Get(const T& key) const`**: Searches the BST for the given `key`. If found, it returns a pointer to a new copy of the value. If not found, it returns `nullptr`.

  Example:
  ```cpp
  int* result = bst.Get(5);  // Search for 5 in the BST
  if (result) {
      std::cout << "Found: " << *result << std::endl;
  } else {
      std::cout << "Not found." << std::endl;
  }
  ```

- **`T RankGet(int r) const`**: Returns the element at the specified rank `r` (0-indexed) in the in-order traversal of the BST. This can be used to retrieve the `r`-th smallest element.

  Example:
  ```cpp
  int rankValue = bst.RankGet(2);  // Get the 2nd smallest element in the BST
  std::cout << "Rank 2 element: " << rankValue << std::endl;
  ```

---

### Manipulation Methods

- **`void Insert(const T& value)`**: Inserts the given `value` into the BST. If the value already exists, it updates that node’s value.

  Example:
  ```cpp
  bst.Insert(15);  // Insert 15 into the BST
  bst.Insert(7);   // Insert 7 into the BST
  ```

- **`void Delete(const T& key)`**: Deletes the node with the specified `key` from the BST.

  Example:
  ```cpp
  bst.Delete(10);  // Delete the node with value 10 from the BST
  ```

- **`BinarySearchTree<T> JoinBST(const BinarySearchTree<T>& bst1, const BinarySearchTree<T>& bst2)`**: Joins two binary search trees into a single BST. The resulting tree will contain the nodes of both `bst1` and `bst2`.

  Example:
  ```cpp
  BinarySearchTree<int> bst1(10);
  BinarySearchTree<int> bst2(20);
  BinarySearchTree<int> joinedTree = bst1.JoinBST(bst1, bst2);  // Join bst1 and bst2
  ```

- **`std::vector<BinarySearchTree<T>> SplitBST(const BinarySearchTree<T>& bst, const T& key)`**: Splits a BST into two subtrees based on the given `key`. The left subtree will contain values less than `key`, and the right subtree will contain values greater than `key`.

  Example:
  ```cpp
  std::vector<BinarySearchTree<int>> splitTrees = bst.SplitBST(bst, 10);  // Split bst into two subtrees by key 10
  ```

---

### Disabled BinaryTree Methods

- **`void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) = delete`**
- **`void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) = delete`**
- **`void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right) = delete`**
- **`void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left) = delete`**

These methods are disabled because they are not applicable to a binary search tree. In a binary search tree, the insertion of nodes is handled by maintaining the binary search tree property, rather than arbitrarily inserting to the left or right.

---

## Example Usage

Here’s an example demonstrating how to use the `BinarySearchTree` class:

```cpp
#include "BinarySearchTree.hpp"
#include <iostream>

int main() {
    // Create a BST with an initial value of 10
    BinarySearchTree<int> bst(10);

    // Insert elements into the BST
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(7);

    // Search for an element
    int* searchResult = bst.Get(7);  // Search for 7
    if (searchResult) {
        std::cout << "Found: " << *searchResult << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    // Get the element at rank 2 in the in-order traversal
    int rankValue = bst.RankGet(2);  // Should return 7 (the 2nd smallest element)
    std::cout << "Rank 2 element: " << rankValue << std::endl;

    // Delete a node
    bst.Delete(5);  // Deletes the node with value 5

    // Display the result after deletion
    searchResult = bst.Get(5);
    std::cout << "After deletion: " << (searchResult ? "Found" : "Not found") << std::endl;

    return 0;
}
```

### Explanation:
- The code creates a `BinarySearchTree` of integers, inserts several elements, and demonstrates the search and rank retrieval functions.
- It also shows how to delete a node from the tree and verifies the deletion by checking for the deleted node.

---

## Potential Errors & Edge Cases

1. **Searching for Non-Existent Elements**: The `Get()` method returns `nullptr` if the element is not found. Always check the return value to avoid dereferencing a null pointer.

   Example:
   ```cpp
   int* result = bst.Get(100);  // Searching for a non-existent element
   if (result == nullptr) {
       std::cout << "Element not found!" << std::endl;
   }
   ```

2. **Rank Get with Invalid Rank**: The `RankGet()` function assumes the rank is valid. If an invalid rank is passed (e.g., a rank outside the bounds of the tree), it could lead to undefined behavior. You should ensure the rank is within the valid range.

   Example:
   ```cpp
   if (rank >= 0 && rank < bst.Size()) {
       bst.RankGet(rank);
   }
   ```

3. **Edge Cases with Empty Trees**: If you call methods like `Get()`, `RankGet()`, or `Delete()` on an empty tree, ensure that the methods handle this gracefully without causing errors.

4. **Duplicate Elements**: The `Insert()` method handles duplicates by updating the existing node. If your application requires stricter handling of duplicates (e.g., disallowing them), you may need to modify the `Insert()` method accordingly.

---

## Dependencies

- **`BinaryTree.hpp`**: The `BinarySearchTree` class inherits from the `BinaryTree<T>` class, so ensure that the `BinaryTree` class is properly implemented.
- **`BinaryTreeNode.hpp`**: Each node in the binary search tree is represented by a `BinaryTreeNode` object. Ensure that the `BinaryTreeNode<T>` class is defined correctly for managing tree nodes.
