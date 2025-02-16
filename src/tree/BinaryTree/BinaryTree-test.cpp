// g++ -std=c++17 BinaryTree.cpp BinaryTree-test.cpp ../BinaryTreeIterator/BinaryTreeIterator.cpp ../BinaryTreeNode/BinaryTreeNode.cpp -o test

#include <iostream>
#include "../BinaryTreeNode/BinaryTreeNode.hpp"
#include "../BinaryTreeIterator/BinaryTreeIterator.hpp"

using namespace std;

// Function to test binary tree construction and basic properties
void testBinaryTreeConstruction() {
    cout << "=== Binary Tree Construction Test ===\n";

    // Creating a simple binary tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(15);

    root->setLeftChild(leftChild);
    root->setRightChild(rightChild);

    BinaryTree<int> tree;
    tree.set_root(root);

    cout << "Root Data: " << tree.RootData() << endl;
    cout << "Left Subtree Root Data: " << tree.LeftSubtree().RootData() << endl;
    cout << "Right Subtree Root Data: " << tree.RightSubtree().RootData() << endl;
    
    cout << "Tree Depth: " << tree.Depth() << endl;
    cout << "Tree Height: " << tree.Height() << endl;
    cout << "Is Balanced: " << (tree.isBalanced() ? "Yes" : "No") << endl;
    cout << "Is Complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << "Is Full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << "Is Empty: " << (tree.IsEmpty() ? "Yes" : "No") << endl;

    cout << "=== End of Binary Tree Construction Test ===\n\n";
}

// Function to test binary tree iterator
void testBinaryTreeIterator() {
    cout << "=== Binary Tree Iterator Test ===\n";

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* leftLeftChild = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* leftRightChild = new BinaryTreeNode<int>(7);
    BinaryTreeNode<int>* rightLeftChild = new BinaryTreeNode<int>(15);
    BinaryTreeNode<int>* rightRightChild = new BinaryTreeNode<int>(25);

    // Constructing the tree
    root->setLeftChild(leftChild);
    root->setRightChild(rightChild);
    leftChild->setLeftChild(leftLeftChild);
    leftChild->setRightChild(leftRightChild);
    rightChild->setLeftChild(rightLeftChild);
    rightChild->setRightChild(rightRightChild);

    BinaryTree<int> tree;
    tree.set_root(root);

    // Test inorder traversal
    cout << "Inorder Traversal: ";
    BinaryTreeIterator<int> inorderIt(root, 'I');
    while (inorderIt.hasNext()) {
        cout << *inorderIt << " ";
        ++inorderIt;
    }
    cout << endl;

    // Test preorder traversal
    cout << "Preorder Traversal: ";
    BinaryTreeIterator<int> preorderIt(root, 'P');
    while (preorderIt.hasNext()) {
        cout << *preorderIt << " ";
        ++preorderIt;
    }
    cout << endl;

    // Test postorder traversal
    cout << "Postorder Traversal: ";
    BinaryTreeIterator<int> postorderIt(root, 'O');
    while (postorderIt.hasNext()) {
        cout << *postorderIt << " ";
        ++postorderIt;
    }
    cout << endl;

    // Test level-order traversal
    cout << "Level-order Traversal: ";
    BinaryTreeIterator<int> levelorderIt(root, 'L');
    while (levelorderIt.hasNext()) {
        cout << *levelorderIt << " ";
        ++levelorderIt;
    }
    cout << endl;

    cout << "=== End of Binary Tree Iterator Test ===\n\n";
}

// Function to test threaded inorder traversal
void testThreadedInorderTraversal() {
    cout << "=== Threaded Inorder Traversal Test ===\n";

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>();
    BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>();
    BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>();

    root->setLeftChild(leftChild);
    root->setRightChild(rightChild);

    BinaryTree<int> tree;
    tree.set_root(root);

    // Get threaded inorder traversal
    int* inorderArray = tree.ThrededInorderIterator();
    cout << "Threaded Inorder Traversal: ";
    for (int i = 0; i < 3; ++i) { // Since we have only 3 elements in the tree
        cout << inorderArray[i] << " ";
    }
    cout << endl;

    delete[] inorderArray; // Clean up

    cout << "=== End of Threaded Inorder Traversal Test ===\n\n";
}

// Function to test binary tree copy and equality operators
void testBinaryTreeCopyAndComparison() {
    cout << "=== Binary Tree Copy and Comparison Test ===\n";

    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* leftChild1 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* rightChild1 = new BinaryTreeNode<int>(20);

    root1->setLeftChild(leftChild1);
    root1->setRightChild(rightChild1);

    BinaryTree<int> tree1;
    tree1.set_root(root1);

    // Copying the tree
    BinaryTree<int> tree2 = tree1;

    cout << "Tree1: " << tree1 << endl;
    cout << "Tree2: " << tree2 << endl;
    cout << "Are Trees Equal? " << (tree1 == tree2 ? "Yes" : "No") << endl;

    cout << "=== End of Binary Tree Copy and Comparison Test ===\n\n";
}

// Function to test tree deletion
void testTreeDeletion() {
    cout << "=== Binary Tree Deletion Test ===\n";

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(50);
    BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(30);
    BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(70);

    root->setLeftChild(leftChild);
    root->setRightChild(rightChild);

    BinaryTree<int> tree;
    tree.set_root(root);

    cout << "Before Deletion: " << tree << endl;
    tree.delete_subtree(root->getLeftChild()); // Deleting left subtree
    cout << "After Deletion of Left Subtree: " << tree << endl;

    cout << "=== End of Binary Tree Deletion Test ===\n\n";
}

void testNodeCount() {
    cout << "=== Binary Tree Node Count Test ===\n";

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* leftLeftChild = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* leftRightChild = new BinaryTreeNode<int>(7);

    root->setLeftChild(leftChild);
    root->setRightChild(rightChild);
    leftChild->setLeftChild(leftLeftChild);
    leftChild->setRightChild(leftRightChild);

    BinaryTree<int> tree;
    tree.set_root(root);

    cout << "Number of nodes in the tree: " << tree.CountNodes() << endl;

    cout << "=== End of Binary Tree Node Count Test ===\n\n";
}

int main() {
    testBinaryTreeConstruction();
    testBinaryTreeIterator();
    testThreadedInorderTraversal();
    testBinaryTreeCopyAndComparison();
    testTreeDeletion();
    testNodeCount(); // Call the new test function
    return 0;
}
