#ifndef MAXHEAP
#define MAXHEAP

#include <vector>
#include <iostream>
#include <queue>  // Required for LevelOrderIterator

#include "../BinaryTree/BinaryTree.hpp"
#include "../BinaryTreeNode/BinaryTreeNode.hpp"

using namespace std;

template <class T>
class MaxHeap: public BinaryTree<T> 
{
    private:
        std::vector<BinaryTreeNode<T>*> nodes; // Vector to store nodes in level-order

        // Internal Storage Helper Methods
        BinaryTreeNode<T>* getParent(int index);
        BinaryTreeNode<T>* GetNodeAtIndex(int index); // Get node at specific index
        BinaryTreeNode<T>* FindNextAvailableParent();

    public:
        // constructor and destructor
        MaxHeap(const T& rootData);
        ~MaxHeap();

        // push and pop
        void Push(const T& value);
        void Pop();

        // Helper methods to maintain heap property
        void heapify_up(int index);     // Modify the tree structure
        void heapify_down(int index);   // Modify the tree structure
        std::vector<BinaryTreeNode<T>*> LevelOrderIterator(); // Iterate in level order
};
        
#endif
