// g++ -std=c++17 MinHeap.cpp MinHeap-test.cpp\
    ../MaxHeap/MaxHeap.cpp\
    ../BinaryTree/BinaryTree.cpp\
    ../BinaryTreeNode/BinaryTreeNode.cpp\
    ../../container/Bag/Bag.cpp ../../container/DeQue/DeQue.cpp\
    ../../container/Stack/Stack.cpp\
    ../../array/GeneralArray/GeneralArray.cpp\
    ../../array/Polynomial/Polynomial.cpp\
    ../../array/SparseMatrix/SparseMatrix.cpp\
    ../../array/String/String.cpp -o test -o test

#include <iostream>
#include "MinHeap.hpp"

using namespace std;

int main() 
{
    cout << "=== MinHeap Test ===\n\n";
    
    // Build a sample tree:
    //           40
    //         /    \
    //       20      60
    //      /  \    /  \
    //    10   30  50  70
    MinHeap<int> minHeap(10);  // Create a MinHeap with an initial capacity of 10

    minHeap.Push(40);
    minHeap.Push(20);
    minHeap.Push(60);
    minHeap.Push(10);
    minHeap.Push(30);
    minHeap.Push(50);
    minHeap.Push(70);
    
    cout << "MinHeap after pushing elements:\n";
    cout << "Top: " << minHeap.Top() << endl;  // Should print 10 (minimum value)
    
    // Pop the root (minimum) element
    minHeap.Pop();
    cout << "After popping the min, Top: " << minHeap.Top() << endl;  // Should print 20
    
    // Pop all elements and print the new top each time
    minHeap.Pop();
    cout << "After popping, Top: " << minHeap.Top() << endl;  // Should print 30
    minHeap.Pop();
    cout << "After popping, Top: " << minHeap.Top() << endl;  // Should print 40
    minHeap.Pop();
    cout << "After popping, Top: " << minHeap.Top() << endl;  // Should print 50
    minHeap.Pop();
    cout << "After popping, Top: " << minHeap.Top() << endl;  // Should print 60
    minHeap.Pop();
    cout << "After popping, Top: " << minHeap.Top() << endl;  // Should print 70
    minHeap.Pop();
    cout << "After popping, IsEmpty: " << (minHeap.IsEmpty() ? "Yes" : "No") << endl;  // Should print Yes
    
    cout << "=== End of MinHeap Test ===\n\n";

    return 0;
}

/*
Expected output:

MinHeap after pushing elements:
Top: 10
After popping the min, Top: 20
After popping, Top: 30
After popping, Top: 40
After popping, Top: 50
After popping, Top: 60
After popping, Top: 70
After popping, IsEmpty: Yes
*/