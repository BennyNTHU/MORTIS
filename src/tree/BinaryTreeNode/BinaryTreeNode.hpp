#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

template<class T> class BinaryTree;
template <class T> class Tree;

template <class T>
class TreeNode 
{
    friend class BinaryTree<T>;

    private:
        T data;
        TreeNode<T> *leftChild;
        TreeNode<T> *rightChild;

    public:
        TreeNode()
        {
            leftChild = nullptr;
            rightChild = nullptr;
        }
        TreeNode(const T& e, TreeNode<T>* ptr_left, TreeNode<T>* ptr_right)
        {
            data = e; 
            leftChild = ptr_left;
            rightChild = ptr_right; 
        }
        TreeNode(const T& e)
        {
            data = e;
            leftChild = nullptr;
            rightChild = nullptr;
        }
        T getdata()
        {
            return data;
        }
        TreeNode<T>* get_left_child()
        {
            return this->leftChild;
        }
        TreeNode<T>* get_right_child()
        {
            return this->rightChild;
        }
        TreeNode<T>* setNode(T in)
        {
            return this->data = in;
        }
        TreeNode<T>* set_left_child(TreeNode *in)
        {
            return this->left_child = in;
        }
        TreeNode<T>* set_right_child(TreeNode *in)
        {
            return this->right_child = in;
        }
};