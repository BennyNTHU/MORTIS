#include <iostream>
#include "../BinaryTree/BinaryTree.hpp"
#include "../BinaryTreeIterator/BinaryTreeIterator.hpp"
#include "../BinaryTreeNode/BinaryTreeNode.hpp"

using namespace std;



void testBinaryTreeConstruction() {
    cout << "=== Binary Tree Construction Test ===\n";
    
    // Construct a simple tree:
    //         5
    //       /   \
    //     10     15
    BinaryTree<int> tree;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(15);
    
    tree.set_root(root);
    tree.InsertLeft(root, leftChild);
    tree.InsertRight(root, rightChild);
    
    cout << "Root Data: " << tree.RootData() << "\n";
    BinaryTree<int>* leftSubtree = tree.LeftSubtree();
    BinaryTree<int>* rightSubtree = tree.RightSubtree();
    cout << "Left Subtree Root Data: " << (leftSubtree ? leftSubtree->RootData() : -1) << "\n";
    cout << "Right Subtree Root Data: " << (rightSubtree ? rightSubtree->RootData() : -1) << "\n";
    
    cout << "Tree Height: " << tree.Height() << "\n";
    cout << "Is Balanced: " << (tree.isBalanced() ? "Yes" : "No") << "\n";
    cout << "Is Complete: " << (tree.isComplete() ? "Yes" : "No") << "\n";
    cout << "Is Full: " << (tree.isFull() ? "Yes" : "No") << "\n";
    cout << "Is Empty: " << (tree.IsEmpty() ? "Yes" : "No") << "\n";
    cout << "Total Nodes: " << tree.CountNodes() << "\n";
    
    cout << "=== End of Construction Test ===\n\n";
}

void testTraversalMethods() {
    cout << "=== Iterator Traversals (with Increments & Decrements) ===\n\n";
    
    // Build a sample tree:
    //           40
    //         /    \
    //       20      60
    //      /  \    /  \
    //    10   30  50  70
    BinaryTree<int> tree;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(40);
    tree.set_root(root);
    BinaryTreeNode<int>* n20 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* n60 = new BinaryTreeNode<int>(60);
    tree.InsertLeft(root, n20);
    tree.InsertRight(root, n60);
    tree.InsertLeft(n20, new BinaryTreeNode<int>(10));
    tree.InsertRight(n20, new BinaryTreeNode<int>(30));
    tree.InsertLeft(n60, new BinaryTreeNode<int>(50));
    tree.InsertRight(n60, new BinaryTreeNode<int>(70));
    
    // ---------------------------
    // Inorder Traversal using Iterator
    // ---------------------------
    cout << "Inorder Iterator Forward: ";
    BinaryTreeIterator<int> itIn(root, 'I');
    BinaryTreeIterator<int> lastIn = itIn; // copy initial state
    while(itIn.hasNext()){
        lastIn = itIn;  // keep a copy of the last valid state
        cout << *itIn << " ";
        ++itIn;
    }
    cout << "\nInorder Iterator Reverse: ";
    // Start with last valid state from forward traversal.
    cout << *lastIn << " ";
    while (true) {
        try {
            --lastIn;
            if (lastIn.getCurrent() == nullptr)
                break;
            cout << *lastIn << " ";
        }
        catch (const exception& e) {
            break;
        }
    }
    cout << "\n\n";
    
    // ---------------------------
    // Postorder Traversal using Iterator
    // ---------------------------
    cout << "Postorder Iterator Forward: ";
    BinaryTreeIterator<int> itPost(root, 'O');
    BinaryTreeIterator<int> lastPost = itPost;
    while(itPost.hasNext()){
        lastPost = itPost;
        cout << *itPost << " ";
        ++itPost;
    }
    cout << "\nPostorder Iterator Reverse: ";
    cout << *lastPost << " ";
    while(true) {
        try {
            --lastPost;
            if(lastPost.getCurrent() == nullptr)
                break;
            cout << *lastPost << " ";
        }
        catch(const exception& e) {
            break;
        }
    }
    cout << "\n\n";
    
    // ---------------------------
    // Level Order Traversal using Iterator
    // ---------------------------
    cout << "Level Order Iterator Forward: ";
    BinaryTreeIterator<int> itLevel(root, 'L');
    BinaryTreeIterator<int> lastLevel = itLevel;
    while(itLevel.hasNext()){
        lastLevel = itLevel;
        cout << *itLevel << " ";
        ++itLevel;
    }
    cout << "\nLevel Order Iterator Reverse: ";
    cout << *lastLevel << " ";
    while(true) {
        try {
            --lastLevel;
            if(lastLevel.getCurrent() == nullptr)
                break;
            cout << *lastLevel << " ";
        }
        catch(const exception& e) {
            break;
        }
    }
    cout << "\n\n";
    
    cout << "=== End of Iterator Traversals Test ===\n";
}

void testIterator() {
    cout << "=== Binary Tree Iterator Test ===\n";
    
    BinaryTree<int> tree;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(20);
    tree.set_root(root);
    tree.InsertLeft(root, new BinaryTreeNode<int>(10));
    tree.InsertRight(root, new BinaryTreeNode<int>(30));
    
    cout << "Inorder Iterator: ";
    for (BinaryTreeIterator<int> it(root, 'I'); it.hasNext(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Preorder Iterator: ";
    for (BinaryTreeIterator<int> it(root, 'P'); it.hasNext(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Postorder Iterator: ";
    for (BinaryTreeIterator<int> it(root, 'O'); it.hasNext(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Level Order Iterator: ";
    for (BinaryTreeIterator<int> it(root, 'L'); it.hasNext(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "=== End of Iterator Test ===\n\n";
}

void testCopyAndComparison() {
    cout << "=== Copy and Comparison Test ===\n";
    
    BinaryTree<int> tree1;
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(50);
    tree1.set_root(root1);
    tree1.InsertLeft(root1, new BinaryTreeNode<int>(25));
    tree1.InsertRight(root1, new BinaryTreeNode<int>(75));
    
    // Use copy constructor
    BinaryTree<int> tree2 = tree1;
    cout << "Trees are equal: " << (tree1 == tree2 ? "Yes" : "No") << "\n";
    
    cout << "=== End of Copy and Comparison Test ===\n\n";
}

void testFindAndClear() {
    cout << "=== Find and Clear Test ===\n";
    
    BinaryTree<int> tree;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(100);
    tree.set_root(root);
    tree.InsertLeft(root, new BinaryTreeNode<int>(50));
    tree.InsertRight(root, new BinaryTreeNode<int>(150));
    
    BinaryTreeNode<int>* found = tree.Find(50);
    cout << "Find(50): " << (found ? found->getData() : -1) << "\n";
    
    tree.Clear();
    cout << "After Clear, IsEmpty: " << (tree.IsEmpty() ? "Yes" : "No") << "\n";
    
    cout << "=== End of Find and Clear Test ===\n\n";
}

void testDeleteSubtree() {
    cout << "=== Delete Subtree Test ===\n";
    
    BinaryTree<int> tree;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(200);
    tree.set_root(root);
    BinaryTreeNode<int>* left = new BinaryTreeNode<int>(100);
    BinaryTreeNode<int>* right = new BinaryTreeNode<int>(300);
    tree.InsertLeft(root, left);
    tree.InsertRight(root, right);
    cout << "Before deletion, CountNodes: " << tree.CountNodes() << "\n";
    
    // Assuming delete_subtree is a public member function that deletes the subtree rooted at the given node.
    tree.delete_subtree(left);
    cout << "After deletion of left subtree, CountNodes: " << tree.CountNodes() << "\n";
    
    cout << "=== End of Delete Subtree Test ===\n\n";
}

void testNodeCount() {
    cout << "=== Node Count Test ===\n";
    
    BinaryTree<int> tree;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    tree.set_root(root);
    tree.InsertLeft(root, new BinaryTreeNode<int>(5));
    tree.InsertRight(root, new BinaryTreeNode<int>(20));
    
    cout << "Number of nodes in the tree: " << tree.CountNodes() << "\n";
    
    cout << "=== End of Node Count Test ===\n\n";
}

int main() {
    testBinaryTreeConstruction();
    testTraversalMethods();
    testIterator();
    testCopyAndComparison();
    testFindAndClear();
    testDeleteSubtree();
    testNodeCount();
    
    return 0;
}
