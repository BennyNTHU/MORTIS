#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include "../BinaryTreeNode/BinaryTreeNode.hpp"
#include "../BinaryTreeIterator/BinaryTreeIterator.hpp"

using namespace std;

template<class T>
class BinaryTree
{
    private:
	    BinaryTreeNode<T> *root;

    public:
        // Constructor
        BinaryTree();                                                   // constructor for an empty binary tree
        BinaryTree(const T& rootData);                                  // Constructor with a root node containing rootData
        BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);    // copy constructor 1
        BinaryTree(const BinaryTree<T>& bt);                            // copy constructor 2

        // Destructor
        ~BinaryTree(); // destruvtor
        void delete_subtree(BinaryTreeNode<T>* node); // delete a subtree
           
        // Getters
        T RootData();  // return the data in the root node of *this
        BinaryTreeNode<T>* get_root();
	    BinaryTree<T> LeftSubtree(); // return the left subtree
        BinaryTree<T> RightSubtree();// return the right subtree

        // Setters
        void set_root(BinaryTreeNode<T>* node);
        void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right); // insert a right child since this is a binary threaded tree
        void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left);  // insert a left child since this is a binary threaded tree

        // Properties
        int CountNodes() const; // Function to count the number of nodes
        int countNodesHelper(BinaryTreeNode<T>* node) const; // Helper function to recursively count nodes
        bool IsEmpty(); // return true iff the binary tree is empty
        int Depth();    // return the depth of the binary tree
        int Height();   // return the height of the binary tree
        bool isBalanced();  // return true iff the binary tree is balanced
        bool isComplete();  // return true iff the binary tree is complete
        bool isFull();      // return true iff the binary tree is full
        bool root_equal(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2); // return true iff the two binary trees have the same root

        // operation overload
        bool operator==(const BinaryTree& bt);
        bool operator!=(const BinaryTree& bt);
        friend ostream& operator<<(ostream& os, const BinaryTree<T>& bt);
        BinaryTreeNode<T>* copy_node(BinaryTreeNode<T>* in);   // I don't know how to overload = so I use this method

        // traversals: No need! we have BinaryTreeIterator for that. Only need threaded traversals
        T* ThrededInorderIterator(); // return an array of the inorder traversal of the binary tree
};

#endif