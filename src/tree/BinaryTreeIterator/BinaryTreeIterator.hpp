#ifndef BINARY_TREE_ITERATOR
#define BINARY_TREE_ITERATOR

#include "../BinaryTreeNode/BinaryTreeNode.hpp"
#include "../../container/DeQue/DeQue.hpp"
#include "../../container/Stack/Stack.hpp"

using namespace std;

template <class T>
class BinaryTreeIterator
{
    private:
        BinaryTreeNode<T>* current;
        char mode;              // 'I' for inorder, 'P' for preorder, 'O' for postorder, 'L' for levelorder
        Stack<BinaryTreeNode<T>*> s;  // Stack for iterative traversal
        DeQue<BinaryTreeNode<T>*> q;  // Queue for level-order traversal

        void pushLeft(BinaryTreeNode<T>* node);
        void pushRight(BinaryTreeNode<T>* node);
        void pushRightReverse(BinaryTreeNode<T>* node);  // Used for reverse traversal

    public:
        BinaryTreeIterator(BinaryTreeNode<T>* root, char traversalMode);
        ~BinaryTreeIterator();

        // Getters
        BinaryTreeNode<T>* getCurrent() const;     // Return next node pointer

        //Dereferencing operators
        const T& operator*() const;
        const T* operator->() const;

        // Reset the iterator
        void reset(BinaryTreeNode<T>* root, char traversalMode);
        bool hasNext();

        // Increment and decrement operators
        BinaryTreeIterator<T>& operator++();    // preincrement
        BinaryTreeIterator<T> operator++(int);
        BinaryTreeIterator<T>& operator--();    // Pre-decrement
        BinaryTreeIterator<T> operator--(int);  // Post-decrement
        BinaryTreeNode<T>* next();              // Additional next() function – returns the current node then advances the iterator.
        
        //Equality test
        bool operator!=(const BinaryTreeIterator<T>& r) const;
        bool operator==(const BinaryTreeIterator<T>& r) const;
};

#endif
