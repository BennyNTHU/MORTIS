#include <iostream>
#include <vector>
#include "BinarySearchTree.hpp"

using namespace std;

int main() 
{
    cout << "=== BinarySearchTree Test ===" << endl << endl;
    
    // Test 1: Insertion, Get, and RankGet.
    cout << "Test 1: Insert and Search" << endl;
    // Create a BST with initial value 50.
    BinarySearchTree<int> bst(50);
    bst.Insert(30);
    bst.Insert(70);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(60);
    bst.Insert(80);
    cout << bst << endl;    // Print the BST
    
    int searchValues[] = {50, 20, 80, 90};
    for (int key : searchValues) 
    {
        int* res = bst.Get(key);
        if (res) 
        {
            cout << "Get(" << key << ") returns: " << *res << endl;
            delete res;
        } 
        else 
        {
            cout << "Get(" << key << ") returns nullptr (not found)" << endl;
        }
    }
    
    cout << "\nIn-order sequence (via RankGet):" << endl;
    int totalNodes = bst.CountNodes();
    for (int i = 0; i < totalNodes; i++) {
        cout << bst.RankGet(i) << " ";
    }
    cout << endl << endl;
    
    // Test 2: JoinBST.
    cout << "Test 2: JoinBST" << endl;
    BinarySearchTree<int> bst1(25);
    bst1.Insert(15);
    bst1.Insert(35);
    cout << "bst1:\n" << bst1 << endl;
    
    BinarySearchTree<int> bst2(75);
    bst2.Insert(65);
    bst2.Insert(85);
    cout << "bst2:\n" << bst2 << endl;
    
    BinarySearchTree<int> joinedBST = bst1.JoinBST(bst1, bst2);
    cout << "After joining:\n" << joinedBST << endl;
    
    // Test 3: SplitBST.
    cout << "Test 3: SplitBST" << endl;
    vector<BinarySearchTree<int>> splitTrees = bst.SplitBST(bst, 50);
    cout << "BST with elements < 50 (in-order):" << splitTrees[0] << endl;
    cout << "BST with elements >= 50 (in-order):" << splitTrees[1] << endl;
    
    // Test 4: Delete.
    cout << "\nTest 4: Delete" << endl;
    bst.Delete(70);
    cout << "After deleting 70:\n" << bst << endl;
    
    bst.Delete(50);
    cout << "After deleting 50:\n" << bst << endl;
    
    cout << "\n=== End of BinarySearchTree Test ===" << endl;
    return 0;
}
