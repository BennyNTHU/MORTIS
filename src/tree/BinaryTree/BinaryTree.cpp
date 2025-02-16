#include "BinaryTree.hpp"

// Default constructor
template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

// Constructor to initialize a BinaryTree with a root node
template <class T>
BinaryTree<T>::BinaryTree(const T& rootData) {
    root = new BinaryTreeNode<T>(rootData); // Create a new root node
}

// Copy constructor (copying two subtrees and merging them)
template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2) {
    root = new BinaryTreeNode<T>(item, bt1.root, bt2.root);
}

// Copy constructor (deep copy)
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& bt) {
    root = copy_node(bt.root);
}

// Destructor
template <class T>
BinaryTree<T>::~BinaryTree() {
    delete_subtree(root);
}

// Delete a subtree
template <class T>
void BinaryTree<T>::delete_subtree(BinaryTreeNode<T>* node) {
    if (node) {
        delete_subtree(node->getLeftChild());
        delete_subtree(node->getRightChild());
        delete node;
    }
}

// Getters
template <class T>
T BinaryTree<T>::RootData() {
    if (!root) throw runtime_error("Binary tree is empty!");
    return root->getData();
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::get_root() {
    return root;
}

template <class T>
BinaryTree<T> BinaryTree<T>::LeftSubtree() {
    BinaryTree<T> leftSubtree;
    leftSubtree.root = root ? root->getLeftChild() : nullptr;
    return leftSubtree;
}

template <class T>
BinaryTree<T> BinaryTree<T>::RightSubtree() {
    BinaryTree<T> rightSubtree;
    rightSubtree.root = root ? root->getRightChild() : nullptr;
    return rightSubtree;
}

// Setters
template <class T>
void BinaryTree<T>::set_root(BinaryTreeNode<T>* node) {
    root = node;
}

template <class T>
void BinaryTree<T>::InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) {
    if (!node) throw runtime_error("Cannot insert into a null node!");
    node->setRightChild(right);
}

template <class T>
void BinaryTree<T>::InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) {
    if (!node) throw runtime_error("Cannot insert into a null node!");
    node->setLeftChild(left);
}

// Function to count the number of nodes in the binary tree
template <class T>
int BinaryTree<T>::CountNodes() const {
    return countNodesHelper(root);
}

// Helper function to recursively count nodes
template <class T>
int BinaryTree<T>::countNodesHelper(BinaryTreeNode<T>* node) const {
    if (!node) return 0;
    return 1 + countNodesHelper(node->getLeftChild()) + countNodesHelper(node->getRightChild());
}

// Properties
template <class T>
bool BinaryTree<T>::IsEmpty() {
    return root == nullptr;
}

template <class T>
int BinaryTree<T>::Depth() {
    return Height();
}

template <class T>
int BinaryTree<T>::Height() {
    function<int(BinaryTreeNode<T>*)> computeHeight = [&](BinaryTreeNode<T>* node) {
        if (!node) return 0;
        return 1 + max(computeHeight(node->getLeftChild()), computeHeight(node->getRightChild()));
    };
    return computeHeight(root);
}

template <class T>
bool BinaryTree<T>::isBalanced() {
    function<int(BinaryTreeNode<T>*)> isBalance = [&](BinaryTreeNode<T>* node) {
        if (!node) return 0;
        int leftHeight = isBalanced(node->getLeftChild());
        int rightHeight = isBalanced(node->getRightChild());
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    };
    return isBalanced(root) != -1;
}

template <class T>
bool BinaryTree<T>::isComplete() {
    if (!root) return true;
    queue<BinaryTreeNode<T>*> q;
    q.push(root);
    bool foundNonFullNode = false;

    while (!q.empty()) {
        BinaryTreeNode<T>* node = q.front();
        q.pop();

        if (node->getLeftChild()) {
            if (foundNonFullNode) return false;
            q.push(node->getLeftChild());
        } else {
            foundNonFullNode = true;
        }

        if (node->getRightChild()) {
            if (foundNonFullNode) return false;
            q.push(node->getRightChild());
        } else {
            foundNonFullNode = true;
        }
    }
    return true;
}

template <class T>
bool BinaryTree<T>::isFull() {
    function<bool(BinaryTreeNode<T>*)> isFull = [&](BinaryTreeNode<T>* node) {
        if (!node) return true;
        if ((node->getLeftChild() == nullptr) != (node->getRightChild() == nullptr)) return false;
        return isFull(node->getLeftChild()) && isFull(node->getRightChild());
    };
    return isFull(root);
}

template <class T>
bool BinaryTree<T>::root_equal(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return root1->getData() == root2->getData();
}

// Operators
template <class T>
bool BinaryTree<T>::operator==(const BinaryTree& bt) {
    function<bool(BinaryTreeNode<T>*, BinaryTreeNode<T>*)> root_equal = [&](BinaryTreeNode<T>* node1, BinaryTreeNode<T>* node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;
        return (node1->getData() == node2->getData()) &&
               root_equal(node1->getLeftChild(), node2->getLeftChild()) &&
               root_equal(node1->getRightChild(), node2->getRightChild());
    };
    return root_equal(root, bt.root);
}

template <class T>
bool BinaryTree<T>::operator!=(const BinaryTree& bt) {
    return !(*this == bt);
}

template <class T>
ostream& operator<<(ostream& os, const BinaryTree<T>& bt) {
    function<void(BinaryTreeNode<T>*)> inorderPrint = [&](BinaryTreeNode<T>* node) {
        if (!node) return;
        inorderPrint(node->getLeftChild());
        os << node->getData() << " ";
        inorderPrint(node->getRightChild());
    };
    inorderPrint(bt.root);
    return os;
}

// Copy function for nodes
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::copy_node(BinaryTreeNode<T>* in) {
    if (!in) return nullptr;
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(in->getData());
    newNode->setLeftChild(copy_node(in->getLeftChild()));
    newNode->setRightChild(copy_node(in->getRightChild()));
    return newNode;
}

// Threaded inorder traversal (returning an array)
template <class T>
T* BinaryTree<T>::ThrededInorderIterator() {
    if (!root) return nullptr;
    
    vector<T> inorderValues;
    BinaryTreeNode<T>* current = root;

    while (current->getLeftChild()) {
        current = current->getLeftChild();
    }

    while (current) {
        inorderValues.push_back(current->getData());
        if (current->getRightThread()) {
            current = current->getRightThread();
        } else {
            current = current->getRightChild();
            while (current && current->getLeftChild()) {
                current = current->getLeftChild();
            }
        }
    }

    T* result = new T[inorderValues.size()];
    copy(inorderValues.begin(), inorderValues.end(), result);
    return result;
}

// Explicit template instantiation
template class BinaryTree<int>;
template class BinaryTree<char>;
template class BinaryTree<float>;
template class BinaryTree<bool>;
template class BinaryTree<double>;
template class BinaryTree<std::string>;
