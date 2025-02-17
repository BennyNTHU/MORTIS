# BinaryTree API Documentation

## Overview

The `BinaryTree` class is a generic class that implements a threaded binary tree. This data structure supports a variety of operations such as insertion, deletion, traversal, and checking properties like completeness, balance, and fullness. It uses threads to make traversal more efficient.

The following sections document the available methods for interacting with the `BinaryTree` and provide example usage.

---

## `BinaryTree` Class Methods

### Constructors

1. **Default Constructor:**
   ```cpp
   BinaryTree<T>::BinaryTree();
   ```
   - Creates an empty binary tree.

2. **Parameterized Constructor:**
   ```cpp
   BinaryTree<T>::BinaryTree(const T& rootData);
   ```
   - Initializes the binary tree with a root node containing `rootData`.

3. **Copy Constructor:**
   ```cpp
   BinaryTree<T>::BinaryTree(const BinaryTree<T>& bt);
   ```
   - Creates a deep copy of the binary tree.

### Destructor

1. **Destructor:**
   ```cpp
   BinaryTree<T>::~BinaryTree();
   ```
   - Deletes all nodes in the tree and frees memory.

### Getters

1. **Root Data:**
   ```cpp
   T BinaryTree<T>::RootData();
   ```
   - Returns the data stored at the root of the tree. Throws an exception if the tree is empty.

2. **Get Root Node:**
   ```cpp
   BinaryTreeNode<T>* BinaryTree<T>::getRoot() const;
   ```
   - Returns the root node of the tree.

3. **Left Subtree:**
   ```cpp
   BinaryTree<T>* BinaryTree<T>::LeftSubtree();
   ```
   - Returns a new `BinaryTree` object representing the left subtree of the tree.

4. **Right Subtree:**
   ```cpp
   BinaryTree<T>* BinaryTree<T>::RightSubtree();
   ```
   - Returns a new `BinaryTree` object representing the right subtree of the tree.

### Setters

1. **Set Root:**
   ```cpp
   void BinaryTree<T>::set_root(BinaryTreeNode<T>* node);
   ```
   - Sets the root of the tree and updates the tree's threads accordingly.

2. **Insert Left Child:**
   ```cpp
   void BinaryTree<T>::InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left);
   ```
   - Inserts a left child for the given node and updates threading.

3. **Insert Right Child:**
   ```cpp
   void BinaryTree<T>::InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right);
   ```
   - Inserts a right child for the given node and updates threading.

### Traversals

1. **In-Order Traversal:**
   ```cpp
   vector<T> BinaryTree<T>::InorderIterator();
   ```
   - Returns a vector of nodes in in-order sequence (left, root, right).

2. **Pre-Order Traversal:**
   ```cpp
   vector<T> BinaryTree<T>::PreOrderIterator();
   ```
   - Returns a vector of nodes in pre-order sequence (root, left, right).

3. **Post-Order Traversal:**
   ```cpp
   vector<T> BinaryTree<T>::PostOrderIterator();
   ```
   - Returns a vector of nodes in post-order sequence (left, right, root).

4. **Level-Order Traversal:**
   ```cpp
   vector<T> BinaryTree<T>::LevelOrderIterator();
   ```
   - Returns a vector of nodes in level-order sequence.

### Node Count and Size

1. **Count Nodes:**
   ```cpp
   int BinaryTree<T>::CountNodes() const;
   ```
   - Returns the total number of nodes in the tree.

### Properties

1. **Is Empty:**
   ```cpp
   bool BinaryTree<T>::IsEmpty() const;
   ```
   - Returns true if the tree is empty, false otherwise.

2. **Is Full:**
   ```cpp
   bool BinaryTree<T>::isFull();
   ```
   - Returns true if every node has either 0 or 2 children (a full binary tree).

3. **Is Balanced:**
   ```cpp
   bool BinaryTree<T>::isBalanced();
   ```
   - Returns true if the tree is balanced (the heights of the left and right subtrees of any node differ by no more than 1).

4. **Is Complete:**
   ```cpp
   bool BinaryTree<T>::isComplete();
   ```
   - Returns true if the tree is complete (all levels are fully filled except possibly the last, which is filled from left to right).

### Insertion

1. **Insert Left Subtree:**
   ```cpp
   void BinaryTree<T>::InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* leftSubtree);
   ```
   - Inserts the left subtree of `leftSubtree` as the left child of `node`.

2. **Insert Right Subtree:**
   ```cpp
   void BinaryTree<T>::InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* rightSubtree);
   ```
   - Inserts the right subtree of `rightSubtree` as the right child of `node`.

### Deletion

1. **Delete Subtree:**
   ```cpp
   void BinaryTree<T>::delete_subtree(BinaryTreeNode<T>* node);
   ```
   - Deletes the subtree rooted at `node`.

### Equality

1. **Equality Comparison:**
   ```cpp
   bool BinaryTree<T>::operator==(const BinaryTree<T>& bt);
   ```
   - Returns true if the two trees are equal (same structure and data).

2. **Inequality Comparison:**
   ```cpp
   bool BinaryTree<T>::operator!=(const BinaryTree<T>& bt);
   ```
   - Returns true if the two trees are not equal.

---

## Example Usage

### Creating a Binary Tree

```cpp
BinaryTree<int> tree(10);  // Create a binary tree with root data 10.
```

### Inserting Nodes

```cpp
BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(5);
BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(15);

tree.InsertLeft(tree.getRoot(), node1);
tree.InsertRight(tree.getRoot(), node2);
```

### Traversing the Tree

```cpp
// In-order traversal
vector<int> inorder = tree.InorderIterator();
for (int val : inorder) {
    std::cout << val << " ";
}
// Output: 5 10 15

// Pre-order traversal
vector<int> preorder = tree.PreOrderIterator();
for (int val : preorder) {
    std::cout << val << " ";
}
// Output: 10 5 15
```

### Checking Tree Properties

```cpp
if (tree.isBalanced()) {
    std::cout << "The tree is balanced.\n";
}

if (tree.isFull()) {
    std::cout << "The tree is full.\n";
}

if (tree.isComplete()) {
    std::cout << "The tree is complete.\n";
}
```

### Removing Nodes

```cpp
BinaryTree<int>* leftSubtree = tree.LeftSubtree();
tree.delete_subtree(leftSubtree->getRoot());
```

---

## Conclusion

The `BinaryTree` class provides a robust and versatile set of operations for managing threaded binary trees, allowing for efficient insertions, deletions, traversals, and various property checks. This documentation serves as a detailed guide to using these functions effectively with examples.