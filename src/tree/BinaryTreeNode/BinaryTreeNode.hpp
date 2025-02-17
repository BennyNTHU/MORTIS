#ifndef BINARY_TREE_NODE
#define BINARY_TREE_NODE

#include <iostream>

using namespace std;

template <class T>
class BinaryTree; // Forward declaration

template <class T>
class BinaryTreeNode 
{
    friend class BinaryTree<T>; // Allow BinaryTree to access private members

    protected:
        T data;
        BinaryTreeNode<T>* leftChild;
        BinaryTreeNode<T>* rightChild;
        BinaryTreeNode<T>* parent;
        BinaryTreeNode<T>* leftthread;
        BinaryTreeNode<T>* rightthread;

        // Private methods to set threaded pointers (Used internally)
        void setLeftThread(BinaryTreeNode<T>* in);
        void setRightThread(BinaryTreeNode<T>* in);

    public:
        // Constructors and Destructor
        BinaryTreeNode(const T& e);
        BinaryTreeNode(const T& e, BinaryTreeNode<T>* ptr_left, BinaryTreeNode<T>* ptr_right);

        // Getters
        const T& getData() const;
        BinaryTreeNode<T>* getRightChild();
        BinaryTreeNode<T>* getLeftChild();
        BinaryTreeNode<T>* getRightThread() const;
        BinaryTreeNode<T>* getLeftThread() const;
        BinaryTreeNode<T>* getParent() const;

        // Setters (Ensure Parent-Child Consistency)
        void setData(T in);
        void setParent(BinaryTreeNode<T>* in);
        void setLeftChild(BinaryTreeNode<T>* in);
        void setRightChild(BinaryTreeNode<T>* in);

        // Equality test
        bool operator==(const BinaryTreeNode<T>& r) const;
        bool operator!=(const BinaryTreeNode<T>& r) const;
};

#endif
