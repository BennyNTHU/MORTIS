// g++ -std=c++17 MaxHeap.cpp MaxHeap-test.cpp\
    ../BinaryTree/BinaryTree.cpp\
    ../BinaryTreeNode/BinaryTreeNode.cpp\
    ../../container/Bag/Bag.cpp ../../container/DeQue/DeQue.cpp\
    ../../container/Stack/Stack.cpp\
    ../../array/GeneralArray/GeneralArray.cpp\
    ../../array/Polynomial/Polynomial.cpp\
    ../../array/SparseMatrix/SparseMatrix.cpp\
    ../../array/String/String.cpp -o test -o test

#include <iostream>
#include "MaxHeap.hpp"

using namespace std;

int main() 
{
    cout << "=== MaxHeap Test ===\n\n";
    
    // Build a sample heap:
    //           70
    //         /    \
    //       60      50
    //      /  \    /  \
    //    40   10  20  30
    //   /
    //  10
    
    // Tesst the builder and <<
    MaxHeap<int> maxHeap(10);  // Create a MaxHeap with an root node 10
    
    cout << "Inserting elements into the MaxHeap:" << endl;
    maxHeap.Push(40);   // Push elements into the heap
    maxHeap.Push(20);
    maxHeap.Push(60);
    maxHeap.Push(10);
    maxHeap.Push(30);
    maxHeap.Push(50);
    maxHeap.Push(70);

    cout << maxHeap << endl;    // Print the MaxHeap it self and level order traversal

    // Test LevelOrderIterator
    std::vector<BinaryTreeNode<int>*> levelOrderNodes = maxHeap.LevelOrderIterator();   // Call LevelOrderIterator
    std::cout << "Level-order traversal of the heap:" << std::endl; // Print the values in level-order
    for (BinaryTreeNode<int>* node : levelOrderNodes) {
        std::cout << node->getData() << " ";
    }
    std::cout << std::endl;

    cout << "Heap after insertions:\n";
    cout << maxHeap << endl;
    cout << "Top: " << maxHeap.RootData() << endl;  // Should print 70

    // Test the get_size and get_capacity functions
    cout << "Heap size: " << maxHeap.CountNodes() << endl;  // Should print 8

    // Pop the top element (max element) and check the top again
    cout << "\nPopping the top element (max element):" << endl;
    maxHeap.Pop();
    cout << "New top: " << maxHeap.RootData() << endl;  // Should print 60 (after popping 70)

    // Pop elements and check the top each time
    cout << "\nPopping all elements:" << endl;
    maxHeap.Pop();
    cout << "New top: " << maxHeap.RootData() << endl;  // Should print 50
    cout << "Heap size: " << maxHeap.CountNodes() << endl;

    maxHeap.Pop();
    cout << "New top: " << maxHeap.RootData() << endl;  // Should print 40
    cout << "Heap size: " << maxHeap.CountNodes() << endl;

    maxHeap.Pop();
    cout << "New top: " << maxHeap.RootData() << endl;  // Should print 30
    cout << "Heap size: " << maxHeap.CountNodes() << endl;

    maxHeap.Pop();
    cout << "New top: " << maxHeap.RootData() << endl;  // Should print 20
    cout << "Heap size: " << maxHeap.CountNodes() << endl;

    maxHeap.Pop();
    cout << "New top: " << maxHeap.RootData() << endl;  // Should print 10
    cout << "Heap size: " << maxHeap.CountNodes() << endl;

    maxHeap.Pop();
    cout << "New top: " << maxHeap.RootData() << endl;  // Should print 10
    cout << "Heap size: " << maxHeap.CountNodes() << endl;   // Should print 1
    
    // maxHeap.Pop();
    // cout << "New top: " << maxHeap.RootData() << endl;  // Should print 10
    // cout << "Heap size: " << maxHeap.CountNodes() << endl;

    // Check if heap is empty
    cout << "\nIs the heap empty? " << (maxHeap.IsEmpty() ? "Yes" : "No") << endl;  // Should print Yes

    // Try popping from an empty heap (this should throw an exception)
    try 
    {
        maxHeap.Pop();  // Heap is empty now
    } 
    catch (const runtime_error& e) 
    {
        cout << "Caught exception: " << e.what() << endl;  // Should catch "Heap is empty" exception
    }

    // Check top on an empty heap (should throw an exception)
    try 
    {
        cout << "Top on empty heap: " << maxHeap.RootData() << endl;
    } 
    catch (const runtime_error& e) 
    {
        cout << "Caught exception: " << e.what() << endl;  // Should catch "Heap is empty" exception
    }

    // Insert more elements to test resizing (if capacity is exceeded)
    maxHeap.Push(80);
    maxHeap.Push(90);
    cout << "\nInserting more elements to test resizing:" << endl;
    cout << "Top: " << maxHeap.RootData() << endl;  // Should print 90 after insertions
    cout << "Heap size: " << maxHeap.CountNodes() << endl;  // Should print 3

    cout << "=== End of MaxHeap Test ===\n\n";

    return 0;
}    

/*
Expected output:

=== MaxHeap Test ===

Inserting elements into the MaxHeap:
Heap after insertions:
Top: 70
Heap size: 7
Heap capacity: 10

Popping the top element (max element):
New top: 60

Popping all elements:
New top: 50
New top: 40
New top: 30
New top: 20
New top: 10

Is the heap empty? Yes
Caught exception: Heap is empty
Caught exception: Heap is empty

Inserting more elements to test resizing:
Top: 90
Heap size: 3
Heap capacity: 20

=== End of MaxHeap Test ===

*/ 
