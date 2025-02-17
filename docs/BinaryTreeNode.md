## Documentation for `BinaryTreeNode` APIs

### Overview
`BinaryTreeNode` is the core building block for creating a threaded binary tree. It represents each node in the tree and includes both standard binary tree child pointers (`leftChild`, `rightChild`) as well as thread pointers (`leftthread`, `rightthread`) used in threaded binary trees. It supports typical binary tree operations along with some additional features specific to threaded binary trees.

This document provides detailed explanations and examples for using the `BinaryTreeNode` class.

### Header File (`BinaryTreeNode.hpp`)

```cpp
template <class T>
class BinaryTreeNode {
public:
    T data;                     // Data stored in the node
    BinaryTreeNode<T>* leftChild;   // Left child pointer
    BinaryTreeNode<T>* rightChild;  // Right child pointer
    BinaryTreeNode<T>* leftthread;  // Left thread pointer for threaded binary tree
    BinaryTreeNode<T>* rightthread; // Right thread pointer for threaded binary tree
    BinaryTreeNode<T>* parent;      // Parent pointer

    // Constructors
    BinaryTreeNode(const T& e); // Default constructor
    BinaryTreeNode(const T& e, BinaryTreeNode<T>* ptr_left, BinaryTreeNode<T>* ptr_right); // Constructor with data and optional children

    // Getters
    const T& getData() const;
    BinaryTreeNode<T>* getLeftChild();
    BinaryTreeNode<T>* getRightChild();
    BinaryTreeNode<T>* getLeftThread() const;
    BinaryTreeNode<T>* getRightThread() const;
    BinaryTreeNode<T>* getParent() const;

    // Setters
    void setData(T in);
    void setParent(BinaryTreeNode<T>* in);
    void setLeftChild(BinaryTreeNode<T>* in);
    void setRightChild(BinaryTreeNode<T>* in);
    void setLeftThread(BinaryTreeNode<T>* in);
    void setRightThread(BinaryTreeNode<T>* in);

    // Equality comparison
    bool operator==(const BinaryTreeNode<T>& r) const;
    bool operator!=(const BinaryTreeNode<T>& r) const;
};
```

### `BinaryTreeNode` Functions

#### 1. Constructors
- **Default Constructor**: Initializes a node with the given data, and both child pointers (`leftChild`, `rightChild`) set to `nullptr`.
    ```cpp
    BinaryTreeNode<T>::BinaryTreeNode(const T& e)
        : BinaryTreeNode(e, nullptr, nullptr) {}
    ```

- **Constructor with Data and Optional Child Pointers**: Initializes a node with the given data, left and right child pointers. If the children are provided, the parent pointers are also updated.
    ```cpp
    BinaryTreeNode<T>::BinaryTreeNode(const T& e, BinaryTreeNode<T>* ptr_left, BinaryTreeNode<T>* ptr_right)
        : data(e), leftChild(ptr_left), rightChild(ptr_right), parent(nullptr), leftthread(nullptr), rightthread(nullptr) {
        if (ptr_left) {
            ptr_left->parent = this;
        }
        if (ptr_right) {
            ptr_right->parent = this;
        }
    }
    ```

#### 2. Getters
These methods allow access to the data and child nodes of the current `BinaryTreeNode`.

- **getData**: Returns the data stored in the node.
    ```cpp
    const T& BinaryTreeNode<T>::getData() const { return data; }
    ```

- **getLeftChild**: Returns the left child pointer of the node.
    ```cpp
    BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild() { return leftChild; }
    ```

- **getRightChild**: Returns the right child pointer of the node.
    ```cpp
    BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild() { return rightChild; }
    ```

- **getLeftThread**: Returns the left thread pointer of the node (for threaded binary trees).
    ```cpp
    BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftThread() const { return leftthread; }
    ```

- **getRightThread**: Returns the right thread pointer of the node (for threaded binary trees).
    ```cpp
    BinaryTreeNode<T>* BinaryTreeNode<T>::getRightThread() const { return rightthread; }
    ```

- **getParent**: Returns the parent pointer of the node.
    ```cpp
    BinaryTreeNode<T>* BinaryTreeNode<T>::getParent() const { return parent; }
    ```

#### 3. Setters
These methods allow modification of the node's data, children, and thread pointers.

- **setData**: Sets the data stored in the node.
    ```cpp
    void BinaryTreeNode<T>::setData(T in) { data = in; }
    ```

- **setParent**: Sets the parent pointer of the node.
    ```cpp
    void BinaryTreeNode<T>::setParent(BinaryTreeNode<T>* in) { parent = in; }
    ```

- **setLeftChild**: Sets the left child pointer of the node, and updates the parent's pointer accordingly.
    ```cpp
    void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* in) {
        if (leftChild == in) return;
        if (leftChild && leftChild->parent == this) leftChild->parent = nullptr;
        leftChild = in;
        if (in) in->parent = this;
    }
    ```

- **setRightChild**: Sets the right child pointer of the node, and updates the parent's pointer accordingly.
    ```cpp
    void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* in) {
        if (rightChild == in) return;
        if (rightChild && rightChild->parent == this) rightChild->parent = nullptr;
        rightChild = in;
        if (in) in->parent = this;
    }
    ```

- **setLeftThread**: Sets the left thread pointer.
    ```cpp
    void BinaryTreeNode<T>::setLeftThread(BinaryTreeNode<T>* in) { leftthread = in; }
    ```

- **setRightThread**: Sets the right thread pointer.
    ```cpp
    void BinaryTreeNode<T>::setRightThread(BinaryTreeNode<T>* in) { rightthread = in; }
    ```

#### 4. Equality Comparison
These methods allow comparing two nodes to see if they are the same based on their data and child pointers.

- **operator==**: Compares the data, left child, and right child of two nodes.
    ```cpp
    bool BinaryTreeNode<T>::operator==(const BinaryTreeNode<T>& r) const {
        return (this->data == r.data) &&
               (this->leftChild == r.leftChild) &&
               (this->rightChild == r.rightChild);
    }
    ```

- **operator!=**: Returns the negation of `operator==`.
    ```cpp
    bool BinaryTreeNode<T>::operator!=(const BinaryTreeNode<T>& r) const {
        return !(this->operator==(r));
    }
    ```

### Example Usage

#### Example 1: Creating a Binary Tree Node and Accessing Data

```cpp
int main() {
    // Create a BinaryTreeNode with data 10
    BinaryTreeNode<int> node(10);

    // Accessing the node's data
    std::cout << "Node Data: " << node.getData() << std::endl; // Output: Node Data: 10

    // Setting and accessing left and right children
    BinaryTreeNode<int> leftChild(5);
    BinaryTreeNode<int> rightChild(15);

    node.setLeftChild(&leftChild);
    node.setRightChild(&rightChild);

    std::cout << "Left Child Data: " << node.getLeftChild()->getData() << std::endl;  // Output: Left Child Data: 5
    std::cout << "Right Child Data: " << node.getRightChild()->getData() << std::endl; // Output: Right Child Data: 15
}
```

#### Example 2: Using Equality Operators

```cpp
int main() {
    BinaryTreeNode<int> node1(10);
    BinaryTreeNode<int> node2(10);
    BinaryTreeNode<int> node3(20);

    // Check if two nodes have the same data and children
    if (node1 == node2) {
        std::cout << "node1 is equal to node2" << std::endl; // Output: node1 is equal to node2
    }

    if (node1 != node3) {
        std::cout << "node1 is not equal to node3" << std::endl; // Output: node1 is not equal to node3
    }
}
```

### Conclusion

The `BinaryTreeNode` class is designed to represent nodes in a binary tree with additional thread pointers for threaded binary trees. It provides fundamental operations for managing node data, setting child nodes, and checking equality between nodes. This class can be easily extended for use in more complex tree structures.