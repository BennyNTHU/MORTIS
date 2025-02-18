#include "BinarySearchTree.hpp"
#include <stdexcept>
#include <functional>

// ------------------------------
// Constructor and Destructor
// ------------------------------

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootData): BinaryTree<T>(rootData) {}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {}  // Cleanup is handled by the BinaryTree destructor.

// ------------------------------
// Get: Search for a value in the BST
// ------------------------------

template <class T>
T* BinarySearchTree<T>::Get(const T& key) const 
{
    BinaryTreeNode<T>* current = this->getRoot();

    while (current != nullptr) 
    {
        T curVal = current->getData();

        if (key == curVal) 
        {
            return new T(curVal);
        }
        else if (key < curVal)
            current = current->getLeftChild();
        else
            current = current->getRightChild();
    }
    return nullptr;
}

// ------------------------------
// RankGet: Return the element at rank r (0-indexed)
// ------------------------------

template <class T>
T BinarySearchTree<T>::RankGet(int r) const 
{
    // InorderIterator() is non-const; use const_cast to call it.
    std::vector<T> inorder = const_cast<BinarySearchTree<T>*>(this)->InorderIterator();

    if (r < 0 || r >= inorder.size())
        throw std::out_of_range("Rank out of range");

    return inorder[r];
}

// ------------------------------
// Insert: Insert a value into the BST
// ------------------------------

template <class T>
void BinarySearchTree<T>::Insert(const T& value) 
{
    if (this->IsEmpty()) 
    {
        this->set_root(new BinaryTreeNode<T>(value));
        return;
    }
    
    BinaryTreeNode<T>* current = this->getRoot();
    BinaryTreeNode<T>* parent = nullptr;
    
    while (current != nullptr) 
    {
        parent = current;
        T curVal = current->getData();

        if (value == curVal) 
        {
            current->setData(value);   // Duplicate: update the node.
            return;
        } 
        else if (value < curVal)
            current = current->getLeftChild();
        else
            current = current->getRightChild();
    }
    
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);

    if (value < parent->getData())
        parent->setLeftChild(newNode);
    else
        parent->setRightChild(newNode);
   
    newNode->setParent(parent);
   
}

// ------------------------------
// Delete: Delete a value from the BST
// ------------------------------

template <class T>
void BinarySearchTree<T>::Delete(const T& key) 
{
    BinaryTreeNode<T>* current = this->getRoot();
    BinaryTreeNode<T>* parent = nullptr;
    
    while (current != nullptr && current->getData() != key) 
    {
        parent = current;

        if (key < current->getData())
            current = current->getLeftChild();
        else
            current = current->getRightChild();
    }

    if (current == nullptr)
        throw std::runtime_error("Key not found in BST.");
    
    // If node has two children, find its in-order successor.
    if (current->getLeftChild() != nullptr && current->getRightChild() != nullptr) 
    {
        BinaryTreeNode<T>* successor = current->getRightChild();
        BinaryTreeNode<T>* successorParent = current;

        while (successor->getLeftChild() != nullptr) 
        {
            successorParent = successor;
            successor = successor->getLeftChild();
        }

        // Copy successor's value.
        current->setData(successor->getData());
        current = successor;
        parent = successorParent;
    }
    
    // Now, current has at most one child.
    BinaryTreeNode<T>* child = (current->getLeftChild() != nullptr) ? current->getLeftChild() : current->getRightChild();

    if (parent == nullptr) 
    {
        // Deleting the root.
        this->set_root(child);
        if (child)
            child->setParent(nullptr);
    } 
    else 
    {
        if (parent->getLeftChild() == current)
            parent->setLeftChild(child);
        else
            parent->setRightChild(child);

        if (child)
            child->setParent(parent);
    }
    
    delete current;
}

// ------------------------------
// JoinBST: Naively join two BSTs by inserting all elements from bst2 into bst1.
// ------------------------------

template <class T>
BinarySearchTree<T> BinarySearchTree<T>::JoinBST(const BinarySearchTree<T>& bst1, const BinarySearchTree<T>& bst2) 
{
    BinarySearchTree<T> result = bst1;  // Copy bst1.
    std::vector<T> inorder2 = const_cast<BinarySearchTree<T>&>(bst2).InorderIterator();

    for (const T& value : inorder2) 
    {
        result.Insert(value);
    }

    return result;
}

// ------------------------------
// SplitBST: Naively split a BST into two by key.
// Split a BST into two BSTs by a key.
// Returns a vector of two BSTs:
//   - the first BST contains all elements less than key.
//   - the second BST contains all elements greater than or equal to key.
// ------------------------------

template <class T>
std::vector<BinarySearchTree<T>> BinarySearchTree<T>::SplitBST(const BinarySearchTree<T>& bst, const T& key) 
{
    // Create two BSTs. We initialize them with a dummy value then clear them.
    BinarySearchTree<T> leftTree(key);  // dummy initialization
    leftTree.Clear();
    BinarySearchTree<T> rightTree(key); // dummy initialization
    rightTree.Clear();
    
    std::vector<T> inorder = const_cast<BinarySearchTree<T>&>(bst).InorderIterator();
    for (const T& value : inorder) 
    {
        if (value < key)
            leftTree.Insert(value);
        else
            rightTree.Insert(value);
    }
    return { leftTree, rightTree };
}

// Explicit instantiation
template class BinarySearchTree<int>;
template class BinarySearchTree<char>;
template class BinarySearchTree<float>;
template class BinarySearchTree<double>;
template class BinarySearchTree<std::string>;
