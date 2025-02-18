#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <vector>
#include "../BinaryTree/BinaryTree.hpp"
#include "../BinaryTreeNode/BinaryTreeNode.hpp"

using namespace std;

// A simple BinarySearchTree that stores values of type T.
// T must support operator< and operator==.
template <class T>
class BinarySearchTree : public BinaryTree<T> 
{
   public:
      // Consructors and destrctors
      BinarySearchTree(const T& rootData);   // Constructor: create BST with an initial value.
      ~BinarySearchTree();                   // Destructor.

      // Search
      T* Get(const T& key) const;   // Search the BST for a value. If found, returns a pointer to a new copy of the value; otherwise returns nullptr.
      T RankGet(int r) const;       // Return the element at the given rank (0-indexed) in the in-order traversal.

      // Manipulation
      void Insert(const T& value);  // Insert a value into the BST. If the value already exists, update that node's value.
      void Delete(const T& key);    // Delete a value from the BST.
      BinarySearchTree<T> JoinBST(const BinarySearchTree<T>& bst1, const BinarySearchTree<T>& bst2);  // Join two BSTs
      std::vector<BinarySearchTree<T>> SplitBST(const BinarySearchTree<T>& bst, const T& key);  // Split a BST into two BSTs by a key

      // Disable inherited BinaryTree functions that are not applicable.
      void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) = delete;
      void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) = delete;
      void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right) = delete;
      void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left) = delete;
};

#endif
