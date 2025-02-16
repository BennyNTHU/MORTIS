#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

template<class T>
class BinaryTree
{
    private:
	    TreeNode<T> *root;

    public:
        // constructor & destructor
        BinaryTree(); // constructor for an empty binary tree
        BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);    // copy constructor 1
        BinaryTree(const BinaryTree<T>& bt);    // copy constructor 2
        ~BinaryTree(); // destruvtor
        void delete_tree(TreeNode<T>* node); // delete a subtree
           
        // return properties
        T RootData();  // return the data in the root node of *this
        TreeNode<T>* get_root();
        void set_root(TreeNode<T>* node);
	    BinaryTree<T> LeftSubtree(); // return the left subtree
        BinaryTree<T> RightSubtree();// return the right subtree
        bool IsEmpty(); // return true iff the binary tree is empty

        // traversals
        void Inorder();
        void Inorder(TreeNode<T> *p);
        void Visit(TreeNode<T> *p);
        void Preorder();
        void Preorder(TreeNode<T> *t);
        void Postorder();
        void Postorder(TreeNode<T> *t);
        void LevelOrder();
        void NonrecInorder();
        void NoStackInorder();

        // operation overload
        bool operator==(const BinaryTree& bt);
        bool root_equal(TreeNode<T>* root1, TreeNode<T>* root2);
        TreeNode<T>* copy_node(TreeNode<T>* in);   // I don't know how to overload = so I use this method
};