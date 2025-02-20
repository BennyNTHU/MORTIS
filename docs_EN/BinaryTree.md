# BinaryTree.hpp Documentation

## Overview

The `BinaryTree.hpp` header file defines a template class `BinaryTree` that implements a binary tree data structure. A binary tree is a hierarchical data structure where each node has at most two children, referred to as the left child and the right child. This implementation provides methods for tree manipulation, traversal, and querying properties such as height, balance, and completeness.

## Class: `BinaryTree<T>`

### Description
The `BinaryTree<T>` class is a template class that represents a binary tree. It provides methods for inserting, deleting, and traversing nodes, as well as querying properties of the tree.

### Template Parameters
- `T`: The type of data stored in the nodes of the tree.

### Constructors and Destructor

#### `BinaryTree()`
- **Description**: Default constructor. Initializes an empty binary tree.
- **Usage**:
  ```cpp
  BinaryTree<int> tree;
  ```

#### `BinaryTree(const T& rootData)`
- **Description**: Constructor. Initializes a binary tree with a root node containing the specified data.
- **Parameters**:
  - `rootData`: The data to store in the root node.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);  // Creates a binary tree with root node containing 10
  ```

#### `BinaryTree(const BinaryTree<T>& bt)`
- **Description**: Copy constructor. Initializes a new binary tree by copying another binary tree.
- **Parameters**:
  - `bt`: The `BinaryTree` object to copy from.
- **Usage**:
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(tree1);  // tree2 is a copy of tree1
  ```

#### `~BinaryTree()`
- **Description**: Destructor. Cleans up the binary tree by deleting all nodes.
- **Usage**: Automatically called when the object goes out of scope.

### Methods

#### `void Clear()`
- **Description**: Clears the tree (deletes all nodes) and resets the root pointer.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.Clear();  // The tree is now empty
  ```

### Getters

#### `T RootData()`
- **Description**: Returns the data in the root node of the tree.
- **Return Value**: The data of type `T` stored in the root node.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  int rootData = tree.RootData();  // rootData is 10
  ```

#### `BinaryTreeNode<T>* getRoot() const`
- **Description**: Returns a pointer to the root node of the tree.
- **Return Value**: A pointer to the root `BinaryTreeNode<T>`.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  BinaryTreeNode<int>* root = tree.getRoot();  // root points to the root node
  ```

#### `BinaryTree<T>* LeftSubtree()`
- **Description**: Returns the left subtree of the tree.
- **Return Value**: A pointer to the left subtree as a `BinaryTree<T>` object.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  BinaryTree<int>* leftSubtree = tree.LeftSubtree();  // leftSubtree points to the left subtree
  ```

#### `BinaryTree<T>* RightSubtree()`
- **Description**: Returns the right subtree of the tree.
- **Return Value**: A pointer to the right subtree as a `BinaryTree<T>` object.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertRight(tree.getRoot(), new BinaryTreeNode<int>(15));
  BinaryTree<int>* rightSubtree = tree.RightSubtree();  // rightSubtree points to the right subtree
  ```

### Setters

#### `void set_root(BinaryTreeNode<T>* node)`
- **Description**: Sets the root node of the tree and updates the threading.
- **Parameters**:
  - `node`: A pointer to the `BinaryTreeNode<T>` to set as the root.
- **Usage**:
  ```cpp
  BinaryTree<int> tree;
  tree.set_root(new BinaryTreeNode<int>(10));  // Sets the root node to contain 10
  ```

### Insertion Methods

#### `void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right)`
- **Description**: Inserts a right child for the given node.
- **Parameters**:
  - `node`: A pointer to the node to which the right child will be added.
  - `right`: A pointer to the `BinaryTreeNode<T>` to insert as the right child.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertRight(tree.getRoot(), new BinaryTreeNode<int>(15));  // Inserts 15 as the right child of the root
  ```

#### `void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left)`
- **Description**: Inserts a left child for the given node.
- **Parameters**:
  - `node`: A pointer to the node to which the left child will be added.
  - `left`: A pointer to the `BinaryTreeNode<T>` to insert as the left child.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));  // Inserts 5 as the left child of the root
  ```

#### `void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right)`
- **Description**: Inserts a right subtree for the given node.
- **Parameters**:
  - `node`: A pointer to the node to which the right subtree will be added.
  - `right`: A pointer to the `BinaryTree<T>` to insert as the right subtree.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  BinaryTree<int> rightSubtree(15);
  tree.InsertRightSubtree(tree.getRoot(), &rightSubtree);  // Inserts the right subtree
  ```

#### `void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left)`
- **Description**: Inserts a left subtree for the given node.
- **Parameters**:
  - `node`: A pointer to the node to which the left subtree will be added.
  - `left`: A pointer to the `BinaryTree<T>` to insert as the left subtree.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  BinaryTree<int> leftSubtree(5);
  tree.InsertLeftSubtree(tree.getRoot(), &leftSubtree);  // Inserts the left subtree
  ```

### Deletion Methods

#### `void delete_subtree(BinaryTreeNode<T>* node)`
- **Description**: Deletes a subtree (including the given node).
- **Parameters**:
  - `node`: A pointer to the root of the subtree to delete.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  tree.delete_subtree(tree.getRoot()->left);  // Deletes the left subtree
  ```

### Properties

#### `bool isFull()`
- **Description**: Checks if the binary tree is full (every node has either 0 or 2 children).
- **Return Value**: `true` if the tree is full, `false` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  bool full = tree.isFull();  // full is false (root has only one child)
  ```

#### `bool IsEmpty() const`
- **Description**: Checks if the binary tree is empty.
- **Return Value**: `true` if the tree is empty, `false` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree;
  bool empty = tree.IsEmpty();  // empty is true
  ```

#### `bool isBalanced()`
- **Description**: Checks if the binary tree is balanced (the heights of the two subtrees of every node differ by at most 1).
- **Return Value**: `true` if the tree is balanced, `false` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  bool balanced = tree.isBalanced();  // balanced is true
  ```

#### `bool isComplete()`
- **Description**: Checks if the binary tree is complete (all levels are fully filled except possibly the last level, which is filled from left to right).
- **Return Value**: `true` if the tree is complete, `false` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  bool complete = tree.isComplete();  // complete is true
  ```

#### `int CountNodes() const`
- **Description**: Counts the number of nodes in the binary tree.
- **Return Value**: The number of nodes as an integer.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  int nodeCount = tree.CountNodes();  // nodeCount is 2
  ```

#### `int Height()`
- **Description**: Returns the height of the binary tree (the number of edges on the longest path from the root to a leaf).
- **Return Value**: The height of the tree as an integer.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  int height = tree.Height();  // height is 1
  ```

### Other Functions

#### `BinaryTreeNode<T>* Find(const T& value) const`
- **Description**: Searches for a node containing the given value.
- **Parameters**:
  - `value`: The value to search for.
- **Return Value**: A pointer to the `BinaryTreeNode<T>` if found, `nullptr` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  BinaryTreeNode<int>* node = tree.Find(5);  // node points to the node containing 5
  ```

#### `bool root_equal(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2)`
- **Description**: Checks if two binary trees have the same root.
- **Parameters**:
  - `root1`: A pointer to the root of the first tree.
  - `root2`: A pointer to the root of the second tree.
- **Return Value**: `true` if the roots are equal, `false` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(10);
  bool equal = tree1.root_equal(tree1.getRoot(), tree2.getRoot());  // equal is true
  ```

### Operator Overloads

#### `BinaryTree<T>& operator=(const BinaryTree<T>& other)`
- **Description**: Assignment operator. Performs a deep copy of another binary tree.
- **Parameters**:
  - `other`: The `BinaryTree` to copy from.
- **Return Value**: A reference to the current binary tree.
- **Usage**:
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2;
  tree2 = tree1;  // tree2 is now a copy of tree1
  ```

#### `bool operator==(const BinaryTree<T>& bt)`
- **Description**: Equality operator. Checks if two binary trees are equal.
- **Parameters**:
  - `bt`: The `BinaryTree` to compare with.
- **Return Value**: `true` if the trees are equal, `false` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(10);
  bool equal = (tree1 == tree2);  // equal is true
  ```

#### `bool operator!=(const BinaryTree& bt)`
- **Description**: Inequality operator. Checks if two binary trees are not equal.
- **Parameters**:
  - `bt`: The `BinaryTree` to compare with.
- **Return Value**: `true` if the trees are not equal, `false` otherwise.
- **Usage**:
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(15);
  bool notEqual = (tree1 != tree2);  // notEqual is true
  ```

#### `template <typename U> friend ostream& operator<<(ostream& os, const BinaryTree<U>& bt)`
- **Description**: Overloaded `<<` operator for printing the binary tree.
- **Parameters**:
  - `os`: The output stream.
  - `bt`: The `BinaryTree` to print.
- **Return Value**: The output stream.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  std::cout << tree;  // Prints the binary tree
  ```

### Traversal Methods

#### `vector<T> PreOrderIterator()`
- **Description**: Returns an array of the pre-order traversal of the binary tree.
- **Return Value**: A `vector<T>` containing the elements in pre-order.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> preOrder = tree.PreOrderIterator();  // preOrder contains {10, 5}
  ```

#### `vector<T> PostOrderIterator()`
- **Description**: Returns an array of the post-order traversal of the binary tree.
- **Return Value**: A `vector<T>` containing the elements in post-order.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> postOrder = tree.PostOrderIterator();  // postOrder contains {5, 10}
  ```

#### `vector<T> InorderIterator()`
- **Description**: Returns an array of the in-order traversal of the binary tree.
- **Return Value**: A `vector<T>` containing the elements in in-order.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> inOrder = tree.InorderIterator();  // inOrder contains {5, 10}
  ```

#### `vector<T> LevelOrderIterator()`
- **Description**: Returns an array of the level-order traversal of the binary tree.
- **Return Value**: A `vector<T>` containing the elements in level-order.
- **Usage**:
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> levelOrder = tree.LevelOrderIterator();  // levelOrder contains {10, 5}
  ```

## Example Usage

```cpp
#include "BinaryTree.hpp"
#include <iostream>

int main() {
    // Create a binary tree with root node containing 10
    BinaryTree<int> tree(10);

    // Insert left and right children
    tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
    tree.InsertRight(tree.getRoot(), new BinaryTreeNode<int>(15));

    // Print the tree
    std::cout << "Tree: " << tree << std::endl;

    // Check properties
    std::cout << "Is full: " << std::boolalpha << tree.isFull() << std::endl;
    std::cout << "Is balanced: " << std::boolalpha << tree.isBalanced() << std::endl;
    std::cout << "Height: " << tree.Height() << std::endl;

    // Traverse the tree
    vector<int> preOrder = tree.PreOrderIterator();
    std::cout << "Pre-order traversal: ";
    for (int val : preOrder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Null Pointers**: When inserting or deleting nodes, ensure that the node pointers are valid (not `nullptr`). Invalid pointers may lead to runtime errors.
2. **Memory Management**: When dynamically allocating nodes, ensure proper cleanup to avoid memory leaks.
3. **Empty Tree**: Performing operations like `RootData()` or `Height()` on an empty tree may result in undefined behavior. Ensure the tree is not empty before performing these operations.

## Dependencies

- **BinaryTreeNode.hpp**: The `BinaryTree` class uses `BinaryTreeNode` to represent nodes in the tree. Ensure that this file is included and properly configured in your project.
- **Standard Library**: The header file includes `<iostream>` and `<vector>`, which are part of the C++ Standard Library. Ensure that your environment is configured to use the standard library.

## Summary

The `BinaryTree.hpp` file provides a flexible implementation of a binary tree data structure, supporting insertion, deletion, traversal, and property queries. By following the examples and guidelines provided, you can effectively use this class to build and manipulate binary trees in your projects.
