#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include "BinaryTree.hpp"
#include "../../container/DeQue/DeQue.hpp"

// --------------------
// Constructors 
// --------------------

// Default constructor.
template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

// Constructor to initialize a BinaryTree with a root node.
template <class T>
BinaryTree<T>::BinaryTree(const T& rootData) {
    root = new BinaryTreeNode<T>(rootData);
}

// Copy constructor (deep copy).
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& bt) {
    root = copy_node(bt.root);
}

// --------------------
// Destructors
// --------------------

// Destructor.
template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}

// Recursively clears nodes. Note that only genuine children are traversed 
// (i.e. if a pointer is marked as a thread, we do not follow it).
template <typename T>
void BinaryTree<T>::clear(BinaryTreeNode<T>* node) {
    if (!node)
        return;
    if (!node->leftthread)
        clear(node->leftChild);
    if (!node->rightthread)
        clear(node->rightChild);
    delete node;
}

// Clears the tree (deletes all nodes) and resets the root pointer.
template <class T>
void BinaryTree<T>::Clear() {
    clear(root);
    root = nullptr;
}

// --------------------
// Getters
// --------------------

// Returns the data stored at the root.
template <class T>
T BinaryTree<T>::RootData() {
    if (!root)
        throw std::runtime_error("Binary tree is empty!");
    return root->getData();
}

// Helper: returns the root pointer from the tree.
// (Assumes BinaryTree.hpp provides a getRoot() accessor; if not, store the root when calling set_root.)
template <class T>
BinaryTreeNode<T>* getRoot(BinaryTree<T>& tree, BinaryTreeNode<T>* root) {
    // For this test we already have the root pointer available.
    return root;
}

// Returns a new BinaryTree representing the left subtree.
// This version creates a new tree whose root is a deep copy of the current left child.
template <class T>
BinaryTree<T>* BinaryTree<T>::LeftSubtree() {
    if (root && root->getLeftChild()) {
        BinaryTree<T>* newTree = new BinaryTree<T>();
        newTree->root = copy_node(root->getLeftChild());
        return newTree;
    }
    return nullptr;
}

// Returns a new BinaryTree representing the right subtree.
template <class T>
BinaryTree<T>* BinaryTree<T>::RightSubtree() {
    if (root && root->getRightChild()) {
        BinaryTree<T>* newTree = new BinaryTree<T>();
        newTree->root = copy_node(root->getRightChild());
        return newTree;
    }
    return nullptr;
}

// --------------------
// Setters
// --------------------

// Sets the tree's root and updates threaded pointers.
template <typename T>
void BinaryTree<T>::set_root(BinaryTreeNode<T>* node) {
    root = node;
    updateThreads(root);
}

// Updates the threaded pointers by performing an in‑order traversal using BinaryTreeIterator.
// For any node lacking a genuine left child, its left pointer is set to its inorder predecessor
// and leftthread is set to that pointer; similarly, for the last node, rightthread is set to nullptr.
template <typename T>
void BinaryTree<T>::updateThreads(BinaryTreeNode<T>* node) {
    if (!node)
        return;
    BinaryTreeIterator<T> it(root, 'I');  // In‑order iterator.
    BinaryTreeNode<T>* prev = nullptr;
    while (it.hasNext()) {
        BinaryTreeNode<T>* curr = it.next();
        if (prev && prev->rightthread != nullptr)  // if prev was marked as a thread, update its pointer
            prev->rightChild = curr;
        if (curr->getLeftChild() == nullptr) {
            curr->leftChild = prev;
            curr->leftthread = prev;  // store the inorder predecessor
        }
        else {
            // Genuine left child, so no thread.
            curr->leftthread = nullptr;
        }
        prev = curr;
    }
    if (prev)
        prev->rightthread = nullptr;
}

// --------------------
// Insertion
// --------------------

// Inserts a right child for the given node and updates threading.
template <typename T>
void BinaryTree<T>::InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) {
    if (!node || !right)
        return;
    right->rightChild = node->rightChild;
    right->rightthread = node->rightthread;
    node->rightChild = right;
    // Mark that node now has a genuine right child.
    node->rightthread = nullptr;
    updateThreads(root);
}

// Inserts a left child for the given node and updates threading.
template <typename T>
void BinaryTree<T>::InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) {
    if (!node || !left)
        return;
    left->leftChild = node->leftChild;
    left->leftthread = node->leftthread;
    node->leftChild = left;
    // Mark that node now has a genuine left child.
    node->leftthread = nullptr;
    updateThreads(root);
}

// Insert a right subtree: attach the subtree (whose root is in 'right') as the right child of 'node'.
// Throws an error if 'node' already has a genuine right child.
template <class T>
void BinaryTree<T>::InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* rightSubtree) {
    if (!node || !rightSubtree)
        return;
    // If there is already a genuine right child, signal an error.
    if (node->getRightChild() != nullptr && node->rightthread == nullptr)
        throw std::runtime_error("Node already has a genuine right subtree.");
    node->rightChild = rightSubtree->root;
    if (node->rightChild != nullptr) {
        node->rightChild->parent = node;
        node->rightthread = nullptr; // mark as genuine child
    }
    // Detach the subtree from its original tree.
    rightSubtree->root = nullptr;
    updateThreads(root);
}

// Insert a left subtree: attach the subtree (whose root is in 'left') as the left child of 'node'.
// Throws an error if 'node' already has a genuine left child.
template <class T>
void BinaryTree<T>::InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* leftSubtree) {
    if (!node || !leftSubtree)
        return;
    if (node->getLeftChild() != nullptr && node->leftthread == nullptr)
        throw std::runtime_error("Node already has a genuine left subtree.");
    node->leftChild = leftSubtree->root;
    if (node->leftChild != nullptr) {
        node->leftChild->parent = node;
        node->leftthread = nullptr; // mark as genuine child
    }
    leftSubtree->root = nullptr;
    updateThreads(root);
}

// --------------------
// Deletion
// --------------------

// Delete a subtree (including the node) from the tree.
// This function removes 'node' from its parent (if any) and then deletes all nodes in that subtree.
template <class T>
void BinaryTree<T>::delete_subtree(BinaryTreeNode<T>* node) {
    if (!node)
        return;
    BinaryTreeNode<T>* p = node->getParent();
    if (p) {
        if (p->getLeftChild() == node) {
            p->leftChild = nullptr;
            p->leftthread = (p->getLeftChild() == nullptr) ? p->leftChild : nullptr;
        } else if (p->getRightChild() == node) {
            p->rightChild = nullptr;
            p->rightthread = (p->getRightChild() == nullptr) ? p->rightChild : nullptr;
        }
    } else {
        // If node is the root, update the tree's root.
        root = nullptr;
    }
    clear(node);  // Recursively delete nodes in the subtree.
    updateThreads(root);
}

// --------------------
// Properties
// --------------------

// Returns true if the binary tree is full (every node has either 0 or 2 genuine children).
template <class T>
bool BinaryTree<T>::isFull() {
    std::function<bool(BinaryTreeNode<T>*)> fullHelper = [&](BinaryTreeNode<T>* node) -> bool {
        if (!node)
            return true;
        bool leftExists  = (node->getLeftChild()  != nullptr && node->leftthread  == nullptr);
        bool rightExists = (node->getRightChild() != nullptr && node->rightthread == nullptr);
        // A node is full if either both children exist or neither exists.
        if (leftExists != rightExists)
            return false;
        return fullHelper(node->getLeftChild()) && fullHelper(node->getRightChild());
    };
    return fullHelper(root);
}

// Returns true if the binary tree is empty.
template <class T>
bool BinaryTree<T>::IsEmpty() {
    return root == nullptr;
}

// Returns true if the tree is empty.
template <class T>
bool BinaryTree<T>::IsEmpty() {
    return root == nullptr;
}

// Returns true if the tree is height-balanced.
template <class T>
bool BinaryTree<T>::isBalanced() {
    std::function<int(BinaryTreeNode<T>*)> checkBalance = [&](BinaryTreeNode<T>* node) -> int {
        if (!node)
            return 0;
        int leftHeight = checkBalance(node->getLeftChild());
        int rightHeight = checkBalance(node->getRightChild());
        if (leftHeight == -1 || rightHeight == -1 || std::abs(leftHeight - rightHeight) > 1)
            return -1;
        return 1 + std::max(leftHeight, rightHeight);
    };
    return checkBalance(root) != -1;
}

// Returns the total number of nodes in the tree.
template <class T>
int BinaryTree<T>::CountNodes() const {
    return countNodesHelper(root);
}

// Recursive helper for counting nodes.
template <class T>
int BinaryTree<T>::countNodesHelper(BinaryTreeNode<T>* node) const {
    return node ? 1 + countNodesHelper(node->getLeftChild()) + countNodesHelper(node->getRightChild()) : 0;
}

// Computes the height of the tree using memoization.
template <class T>
int BinaryTree<T>::Height() {
    if (!root)
        return 0;
    std::unordered_map<BinaryTreeNode<T>*, int> memo;
    std::function<int(BinaryTreeNode<T>*)> computeHeight = [&](BinaryTreeNode<T>* node) -> int {
        if (!node)
            return 0;
        if (memo.find(node) != memo.end())
            return memo[node];
        int leftHeight = computeHeight(node->getLeftChild());
        int rightHeight = computeHeight(node->getRightChild());
        memo[node] = 1 + std::max(leftHeight, rightHeight);
        return memo[node];
    };
    return computeHeight(root);
}

// --------------------
// Other functions
// --------------------

// Searches for a node containing the given value; returns a pointer if found, else nullptr.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Find(const T& value) const {
    return findHelper(root, value);
}

// Private helper for finding a node with the given value.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::findHelper(BinaryTreeNode<T>* node, const T& value) const {
    if (!node)
        return nullptr;
    if (node->getData() == value)
        return node;
    BinaryTreeNode<T>* found = findHelper(node->getLeftChild(), value);
    if (!found)
        found = findHelper(node->getRightChild(), value);
    return found;
}

// Compares two trees (starting at root1 and root2) for equality (structure and data).
template <class T>
bool BinaryTree<T>::root_equal(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) {
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    return (root1->getData() == root2->getData()) &&
           root_equal(root1->getLeftChild(), root2->getLeftChild()) &&
           root_equal(root1->getRightChild(), root2->getRightChild());
}

// --------------------
// operation overload
// --------------------

// Compares two trees for equality.
template <class T>
bool BinaryTree<T>::operator==(const BinaryTree<T>& bt) {
    std::function<bool(BinaryTreeNode<T>*, BinaryTreeNode<T>*)> root_equal =
        [&](BinaryTreeNode<T>* node1, BinaryTreeNode<T>* node2) -> bool {
            if (!node1 && !node2)
                return true;
            if (!node1 || !node2)
                return false;
            return (node1->getData() == node2->getData()) &&
                   root_equal(node1->getLeftChild(), node2->getLeftChild()) &&
                   root_equal(node1->getRightChild(), node2->getRightChild());
        };
    return root_equal(root, bt.root);
}

// Inequality operator: returns true if *this and bt are not equal.
template <class T>
bool BinaryTree<T>::operator!=(const BinaryTree<T>& bt) {
    return !(*this == bt);
}

// Friend operator<<: prints the tree using an inorder traversal.
template <typename U>
std::ostream& operator<<(std::ostream& os, const BinaryTree<U>& bt) {
    bt.InorderTraversal([&os](const U& val) {
        os << val << " ";
    });
    return os;
}

// --------------------
// traversals
// --------------------

// Returns a dynamically allocated array of T values representing the threaded inorder traversal.
// This routine starts from the leftmost genuine node and then follows thread pointers.
template <class T>
T* BinaryTree<T>::ThreadedInorderIterator() {
    if (!root)
        return nullptr;
    
    std::vector<T> inorderValues;
    BinaryTreeNode<T>* current = root;
    
    // Traverse to the leftmost genuine node.
    while (current->getLeftChild())
        current = current->getLeftChild();
    
    while (current) {
        inorderValues.push_back(current->getData());
        if (current->getRightThread())
            current = current->getRightThread();
        else {
            current = current->getRightChild();
            while (current && current->getLeftChild())
                current = current->getLeftChild();
        }
    }
    
    T* result = new T[inorderValues.size()];
    std::copy(inorderValues.begin(), inorderValues.end(), result);
    return result;
}

// Optimized threaded in‑order traversal.
// Returns a dynamically allocated array of T values in in‑order sequence.
template <class T>
T* BinaryTree<T>::ThreadedInorderIterator() {
    if (!root)
        return nullptr;
    
    std::vector<T> inorderValues;
    BinaryTreeNode<T>* current = root;
    
    // Go to the leftmost genuine node.
    while (current->getLeftChild())
        current = current->getLeftChild();
    
    while (current) {
        inorderValues.push_back(current->getData());
        if (current->getRightThread())
            current = current->getRightThread();
        else {
            current = current->getRightChild();
            while (current && current->getLeftChild())
                current = current->getLeftChild();
        }
    }
    
    T* result = new T[inorderValues.size()];
    std::copy(inorderValues.begin(), inorderValues.end(), result);
    return result;
}

// --------------------
// Explicit Template Instantiation & Friend Operators
// --------------------

template class BinaryTree<int>;
template class BinaryTree<char>;
template class BinaryTree<float>;
template class BinaryTree<bool>;
template class BinaryTree<double>;
template class BinaryTree<std::string>;

template std::ostream& operator<<(std::ostream& os, const BinaryTree<int>& bt);
template std::ostream& operator<<(std::ostream& os, const BinaryTree<bool>& bt);
template std::ostream& operator<<(std::ostream& os, const BinaryTree<char>& bt);
template std::ostream& operator<<(std::ostream& os, const BinaryTree<float>& bt);
template std::ostream& operator<<(std::ostream& os, const BinaryTree<double>& bt);
template std::ostream& operator<<(std::ostream& os, const BinaryTree<std::string>& bt);
