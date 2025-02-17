#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include <vector>
#include "../BinaryTreeNode/BinaryTreeNode.hpp"

using namespace std;

template<class T>
class BinaryTree
{
    private:
	    BinaryTreeNode<T> *root;

        // Helper functions
        BinaryTreeNode<T>* copy_node(BinaryTreeNode<T>* in);
        BinaryTreeNode<T>* findHelper(BinaryTreeNode<T>* node, const T& value) const;
        void clear(BinaryTreeNode<T>* node); // delete a subtree
        void updateThreads(BinaryTreeNode<T>* node);         // Function to update threading after modification
        int countNodesHelper(BinaryTreeNode<T>* node) const; // Helper function to recursively count nodes

    public:
        // Constructor
        BinaryTree();                           // constructor for an empty binary tree
        BinaryTree(const T& rootData);          // Constructor with a root node containing rootData
        BinaryTree(const BinaryTree<T>& bt);    // copy constructor

        // Destructor
        ~BinaryTree(); // destructor
        void Clear(); // Clears the tree (deletes all nodes) and resets the root pointer.
           
        // Getters
        T RootData();  // return the data in the root node of *this
        BinaryTreeNode<T>* getRoot() const;
	    BinaryTree<T>* LeftSubtree(); // return the left subtree
        BinaryTree<T>* RightSubtree();// return the right subtree

        // Setters
        void set_root(BinaryTreeNode<T>* node);
        
        // Insertion
        void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right);    // insert a right child
        void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left);      // insert a left child
        void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right); // insert a right subtree 
        void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left);   // insert a left subtree 

        // Deletion
        void delete_subtree(BinaryTreeNode<T>* node); // delete a subtree (includes the node) ?

        // Properties
        bool isFull();          // return true iff the binary tree is full 
        bool IsEmpty() const;   // return true iff the binary tree is empty 
        bool isBalanced();      // return true iff the binary tree is balanced
        bool isComplete();      // return true iff the binary tree is complete
        int CountNodes() const; // Function to count the number of nodes
        int Height();           // return the height of the binary tree

        // Other functions
        BinaryTreeNode<T>* Find(const T& value) const; // Searches for a node containing the given value; returns a pointer if found, else nullptr.
        bool root_equal(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2); // return true iff the two binary trees have the same root 

        // operation overload
        BinaryTree<T>& operator=(const BinaryTree<T>& other);
        bool operator==(const BinaryTree<T>& bt);
        bool operator!=(const BinaryTree& bt); 
        template <typename U> friend ostream& operator<<(ostream& os, const BinaryTree<U>& bt); 

        // traversals: No need! we have BinaryTreeIterator for that. Only need threaded traversals
        vector<T> PreOrderIterator();   // return an array of the pre-order traversal of the binary tree
        vector<T> PostOrderIterator();  // return an array of the post-order traversal of the binary tree
        vector<T> InorderIterator();    // return an array of the in-order traversal of the binary tree
        vector<T> LevelOrderIterator(); // return an array of the level-order traversal of the binary tree
};

#endif