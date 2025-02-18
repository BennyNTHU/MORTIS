#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include "BinaryTree.hpp"
#include "../../container/DeQue/DeQue.hpp"
#include "../../container/Stack/Stack.hpp"

// --------------------
// Helper functions
// --------------------

// Performs a deep copy of the tree nodes.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::copy_node(BinaryTreeNode<T>* in) 
{
    if (!in)
        return nullptr;
    
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(in->getData());
    newNode->setLeftChild(copy_node(in->getLeftChild()));
    newNode->setRightChild(copy_node(in->getRightChild()));
    return newNode;
}

// Private helper for finding a node with the given value.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::findHelper(BinaryTreeNode<T>* node, const T& value) const 
{
    if (!node)
        return nullptr;

    if (node->getData() == value)
        return node;

    BinaryTreeNode<T>* found = findHelper(node->getLeftChild(), value);

    if (!found)
        found = findHelper(node->getRightChild(), value);
    
    return found;
}


// Recursively clears nodes. Only genuine children (i.e. not threads) are traversed.
template <typename T>
void BinaryTree<T>::clear(BinaryTreeNode<T>* node) 
{
    if (!node)
        return;
    if (node->leftthread == nullptr)
        clear(node->leftChild);
    if (node->rightthread == nullptr)
        clear(node->rightChild);
    
    delete node;
}


// Update the threads of the binary tree every time the tree is modified
// i.e. insert/delete a node/subtree, change root
template <typename T>
void BinaryTree<T>::updateThreads(BinaryTreeNode<T>* node) 
{
    if (!node)
        return;

    // Using the In-Order traversal function
    vector<T> inorder = InorderIterator();  // Get the in-order traversal of the tree
    BinaryTreeNode<T>* prev = nullptr;

    // Traverse through the in-order traversal vector
    for (const auto& data : inorder)    // Use const reference to avoid issues with types like bool 
    {  
        BinaryTreeNode<T>* curr = Find(data);  // Find the node by its data

        // If current node has no genuine left child, thread it to its inorder predecessor.
        if (curr->getLeftChild() == nullptr) 
        {
            if (prev)   // Ensure prev is not nullptr before accessing it 
            {  
                curr->leftthread = prev;
            }
        } 
        else 
        {
            curr->leftthread = nullptr;
        }

        // For the previous node, if it lacks a genuine right child, thread it to the current node.
        if (prev && prev->getRightChild() == nullptr) 
        {
            prev->rightthread = curr;
        }

        prev = curr;
    }

    // Set the last node's right thread to nullptr
    if (prev) 
    {
        prev->rightthread = nullptr;
    }
}

// Recursive helper for counting nodes.
template <class T>
int BinaryTree<T>::countNodesHelper(BinaryTreeNode<T>* node) const 
{
    return node ? 1 + countNodesHelper(node->getLeftChild()) + countNodesHelper(node->getRightChild()) : 0;
}

// Computes the height of the tree using memoization.
template <class T>
int BinaryTree<T>::Height() 
{
    if (!root)
        return 0;

    std::unordered_map<BinaryTreeNode<T>*, int> memo;
    std::function<int(BinaryTreeNode<T>*)> computeHeight = [&](BinaryTreeNode<T>* node) -> int 
    {
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
// Constructors 
// --------------------

// Default constructor.
template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

// Constructor to initialize a BinaryTree with a root node.
template <class T>
BinaryTree<T>::BinaryTree(const T& rootData) 
{
    root = new BinaryTreeNode<T>(rootData);
}

// Copy constructor (deep copy).
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& bt) 
{
    root = copy_node(bt.root);
}

// --------------------
// Destructors
// --------------------

// Destructor.
template <typename T>
BinaryTree<T>::~BinaryTree() 
{
    clear(root);
}

// Clears the tree (deletes all nodes) and resets the root pointer.
template <class T>
void BinaryTree<T>::Clear() 
{
    clear(root);
    root = nullptr;
}

// --------------------
// Getters
// --------------------

// Returns the data stored at the root.
template <class T>
T BinaryTree<T>::RootData() 
{
    if (!root)
        throw std::runtime_error("Binary tree is empty!");

    return root->getData();
}

// Return the root node (const version) for operator<<.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() const 
{
    return root;
}

// Returns a new BinaryTree representing the left subtree.
template <class T>
BinaryTree<T>* BinaryTree<T>::LeftSubtree() 
{
    if (root && root->getLeftChild()) 
    {
        BinaryTree<T>* newTree = new BinaryTree<T>();
        newTree->root = copy_node(root->getLeftChild());
        return newTree;
    }

    return nullptr;
}

// Returns a new BinaryTree representing the right subtree.
template <class T>
BinaryTree<T>* BinaryTree<T>::RightSubtree() 
{
    if (root && root->getRightChild()) 
    {
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
void BinaryTree<T>::set_root(BinaryTreeNode<T>* node) 
{
    root = node;
    updateThreads(root);
}

// --------------------
// Insertion
// --------------------

// Inserts a left child for the given node and updates threading.
template <typename T>
void BinaryTree<T>::InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) 
{
    if (!node || !left)
        return;
    
    // Save the current left child (if any)
    BinaryTreeNode<T>* oldLeft = node->getLeftChild();
    
    // Insert the new left node.
    node->leftChild = left;
    left->parent = node;

    // If there was an existing left child, attach it as the left child of the new node.
    if (oldLeft) 
    {
        left->leftChild = oldLeft;
        oldLeft->parent = left;
        left->leftthread = node->leftthread; // copy thread info from the old setting
    } 
    else 
    {
        left->leftChild = nullptr;
        left->leftthread = nullptr;
    }
    
    // Now the node has a genuine left child.
    node->leftthread = nullptr;
    
    updateThreads(root);
}

// Inserts a right child for the given node and updates threading.
template <typename T>
void BinaryTree<T>::InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) 
{
    if (!node || !right)
        return;
    
    // Check if the given node already has a genuine right child.
    if (node->getRightChild() != nullptr && node->rightthread == nullptr)
        throw std::runtime_error("InsertRight error: The target node already has a genuine right child.");
    
    // Check if the new right node is already part of a tree.
    if (right->getParent() != nullptr)
        throw std::runtime_error("InsertRight error: The right node already has a parent.");

    // Insert the new right node using the setter.
    node->setRightChild(right);
    
    // Mark that node now has a genuine right child.
    node->rightthread = nullptr;
    
    updateThreads(root);
}

// Inserts a right subtree: attach the subtree (whose root is in 'rightSubtree')
// as the right child of 'node'. Throws an error if 'node' already has a genuine right child
// or if the subtree's root already has a parent.
template <class T>
void BinaryTree<T>::InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* rightSubtree) 
{
    if (!node || !rightSubtree)
        return;
    
    // Check if the target node already has a genuine right child.
    if (node->getRightChild() != nullptr && node->rightthread == nullptr)
        throw std::runtime_error("InsertRightSubtree error: The target node already has a genuine right child.");
    
    // Check if the right subtree's root is already attached.
    if (rightSubtree->root && rightSubtree->root->getParent() != nullptr)
        throw std::runtime_error("InsertRightSubtree error: The right subtree's root already has a parent.");

    // Attach the subtree's root as the right child.
    node->setRightChild(rightSubtree->root);
    
    // Mark that node now has a genuine right child.
    node->rightthread = nullptr;
    
    // Detach the subtree from its original tree.
    rightSubtree->root = nullptr;
    
    updateThreads(root);
}

// Insert a left subtree: attach the subtree (whose root is in 'leftSubtree') as the left child of 'node'.
// Throws an error if 'node' already has a genuine left child.
template <class T>
void BinaryTree<T>::InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* leftSubtree) 
{
    if (!node || !leftSubtree)
        return;

    if (node->getLeftChild() != nullptr && node->leftthread == nullptr)
        throw std::runtime_error("Node already has a genuine left subtree.");

    node->leftChild = leftSubtree->root;

    if (node->leftChild != nullptr) 
    {
        node->leftChild->parent = node;
        node->leftthread = nullptr;
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
void BinaryTree<T>::delete_subtree(BinaryTreeNode<T>* node) 
{
    if (!node)
        return;

    BinaryTreeNode<T>* p = node->getParent();

    if (p) 
    {
        if (p->getLeftChild() == node) 
        {
            p->leftChild = nullptr;
            p->leftthread = (p->getLeftChild() == nullptr) ? nullptr : p->leftthread;
        } 
        else if (p->getRightChild() == node) 
        {
            p->rightChild = nullptr;
            p->rightthread = (p->getRightChild() == nullptr) ? nullptr : p->rightthread;
        }
    } 
    else 
    {
        root = nullptr; 
    }

    clear(node);
    updateThreads(root);    // If node is the root, update the tree's root.
}

// --------------------
// Properties
// --------------------

// Returns true if the binary tree is full (every node has either 0 or 2 genuine children).
template <class T>
bool BinaryTree<T>::isFull() 
{
    std::function<bool(BinaryTreeNode<T>*)> fullHelper = [&](BinaryTreeNode<T>* node) -> bool 
    {
        if (!node)
            return true;

        bool leftExists  = (node->getLeftChild()  != nullptr && node->leftthread == nullptr);
        bool rightExists = (node->getRightChild() != nullptr && node->rightthread == nullptr);

        if (leftExists != rightExists)
            return false;

        return fullHelper(node->getLeftChild()) && fullHelper(node->getRightChild());
    };

    return fullHelper(root);
}

// Returns true if the binary tree is empty.
template <class T>
bool BinaryTree<T>::IsEmpty() const 
{
    return root == nullptr;
}

// Returns true if the tree is height-balanced.
template <class T>
bool BinaryTree<T>::isBalanced() 
{
    std::function<int(BinaryTreeNode<T>*)> checkBalance = [&](BinaryTreeNode<T>* node) -> int 
    {
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

template <typename T>
bool BinaryTree<T>::isComplete() 
{
    if (!root) return true;  // An empty tree is complete

    DeQue<BinaryTreeNode<T>*> q;
    q.Push(root);
    bool must_be_leaf = false;  // If true, all following nodes must be leaf nodes

    while (!q.IsEmpty()) 
    {
        BinaryTreeNode<T>* node = q.Front();
        q.Pop();

        // If we encounter a null child after a non-null node, the tree is not complete
        if (must_be_leaf && (node->getLeftChild() || node->getRightChild())) 
        {
            return false;
        }

        // Left child check
        if (node->getLeftChild()) 
        {
            q.Push(node->getLeftChild());
        } 
        else 
        {
            must_be_leaf = true;  // Any further nodes must be leaves
        }

        // Right child check
        if (node->getRightChild()) 
        {
            if (must_be_leaf) return false; // If we expected a leaf, the tree isn't complete
            q.Push(node->getRightChild());
        } 
        else 
        {
            must_be_leaf = true;
        }
    }

    return true;
}

// Returns the total number of nodes in the tree.
template <class T>
int BinaryTree<T>::CountNodes() const 
{
    return countNodesHelper(root);
}

// --------------------
// Other functions
// --------------------

// Searches for a node containing the given value; returns a pointer if found, else nullptr.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Find(const T& value) const 
{
    return findHelper(root, value);
}

// Compares two trees (starting at root1 and root2) for equality (structure and data).
template <class T>
bool BinaryTree<T>::root_equal(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) 
{
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

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) 
{
    if (this != &other) 
    {
        Clear();
        if (!other.root)
            root = nullptr;
        else 
        {
            std::function<BinaryTreeNode<T>*(BinaryTreeNode<T>*)> deepCopy =
            [&](BinaryTreeNode<T>* node) -> BinaryTreeNode<T>* 
            {
                if (!node)
                    return nullptr;

                BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(node->getData());
                newNode->setLeftChild(deepCopy(node->getLeftChild()));
                newNode->setRightChild(deepCopy(node->getRightChild()));
                return newNode;
            };
            root = deepCopy(other.root);
        }
        updateThreads(root);
    }
    return *this;
}

// Compares two trees for equality.
template <class T>
bool BinaryTree<T>::operator==(const BinaryTree<T>& bt) 
{
    std::function<bool(BinaryTreeNode<T>*, BinaryTreeNode<T>*)> eq =
        [&](BinaryTreeNode<T>* node1, BinaryTreeNode<T>* node2) -> bool 
        {
            if (!node1 && !node2)
                return true;
            if (!node1 || !node2)
                return false;
            return (node1->getData() == node2->getData()) &&
                   eq(node1->getLeftChild(), node2->getLeftChild()) &&
                   eq(node1->getRightChild(), node2->getRightChild());
        };
    
    return eq(root, bt.root);
}

// Inequality operator.
template <class T>
bool BinaryTree<T>::operator!=(const BinaryTree<T>& bt) 
{
    return !(*this == bt);
}

// Friend operator<< Overload
template <typename U>
std::ostream& operator<<(std::ostream& os, const BinaryTree<U>& bt) 
{
    if (bt.IsEmpty()) 
    {
        os << "(empty tree)" << std::endl;
        return os;
    }
    
    // Collect nodes at each level
    std::vector<std::vector<U>> levels;
    std::vector<BinaryTreeNode<U>*> current_level;
    std::vector<BinaryTreeNode<U>*> next_level;
    
    current_level.push_back(bt.getRoot());
    
    while (!current_level.empty()) 
    {
        std::vector<U> level_values;
        next_level.clear();

        for (auto node : current_level) 
        {
            if (node) 
            {
                level_values.push_back(node->getData());
                next_level.push_back(node->getLeftChild());
                next_level.push_back(node->getRightChild());
            } 
            else 
            {
                level_values.push_back(U());
                next_level.push_back(nullptr);
                next_level.push_back(nullptr);
            }
        }

        levels.push_back(level_values);
        current_level = next_level;
        bool all_null = true;

        for (auto node : next_level) 
        {
            if (node) 
            {
                all_null = false;
                break;
            }
        }
        if (all_null) 
            break;
    }
    
    int total_width = 80;
    for (size_t i = 0; i < levels.size(); ++i) 
    {
        int level_width = total_width / (1 << i);
        for (size_t j = 0; j < levels[i].size(); ++j) 
        {
            if (j > 0) 
                os << std::setw(level_width) << " ";

            if (levels[i][j] != U()) 
                os << std::setw(level_width) << levels[i][j];
            else 
                os << std::setw(level_width) << " ";
        }
        os << std::endl;
    }
    return os;
}

// --------------------
// traversals
// --------------------

template <typename T>
vector<T> BinaryTree<T>::PreOrderIterator() 
{
    vector<T> result;

    if (!root) 
        return result;
    
    Stack<BinaryTreeNode<T>*> s;
    s.Push(root);
    
    while (!s.IsEmpty()) 
    {
        BinaryTreeNode<T>* node = s.Top();
        s.Pop();
        result.push_back(node->getData());  // Visit the node
        
        // Push right child first, so left child is processed first
        if (node->getRightChild()) 
            s.Push(node->getRightChild());

        if (node->getLeftChild()) 
            s.Push(node->getLeftChild());
    }
    
    return result;
}

template <typename T>
vector<T> BinaryTree<T>::PostOrderIterator() 
{
    vector<T> result;
    if (!root) 
        return result;
    
    Stack<BinaryTreeNode<T>*> s1, s2;
    s1.Push(root);
    
    while (!s1.IsEmpty()) 
    {
        BinaryTreeNode<T>* node = s1.Top();
        s1.Pop();
        s2.Push(node);  // Push to the second Stack to visit later
        
        // Push left and right children to the first Stack
        if (node->getLeftChild()) 
            s1.Push(node->getLeftChild());
        
        if (node->getRightChild()) 
            s1.Push(node->getRightChild());
    }
    
    // Now Pop from s2 and store in the result for post-order traversal
    while (!s2.IsEmpty()) 
    {
        result.push_back(s2.Top()->getData());
        s2.Pop();
    }
    
    return result;
}

template <typename T>
vector<T> BinaryTree<T>::InorderIterator() 
{
    vector<T> result;

    if (!root) 
        return result;
    
    Stack<BinaryTreeNode<T>*> s;
    BinaryTreeNode<T>* curr = root;
    
    // Traverse the tree
    while (curr || !s.IsEmpty()) 
    {
        // Reach the leftmost node
        while (curr) 
        {
            s.Push(curr);
            curr = curr->getLeftChild();
        }
        
        curr = s.Top();
        s.Pop();
        result.push_back(curr->getData());  // Visit the node
        curr = curr->getRightChild();  // Move to the right subtree
    }
    
    return result;
}

template <typename T>
vector<T> BinaryTree<T>::LevelOrderIterator() 
{
    vector<T> result;

    if (!root) 
        return result;
    
    DeQue<BinaryTreeNode<T>*> q;

    q.PushBack(root);  // Add root to the back of the deque
    
    while (!q.IsEmpty()) 
    {
        BinaryTreeNode<T>* node = q.Front();  // Access the front element
        q.PopFront();  // Remove the front element
        result.push_back(node->getData());  // Visit the node
        
        // Enqueue left and right children at the back of the deque
        if (node->getLeftChild()) 
            q.PushBack(node->getLeftChild());
        
        if (node->getRightChild()) 
            q.PushBack(node->getRightChild());
    }
    
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