// g++ -std=c++17 MinHeap.cpp MinHeap-test.cpp\
    ../BinaryTree/BinaryTree.cpp\
    ../BinaryTreeNode/BinaryTreeNode.cpp\
    ../MaxHeap/MaxHeap.cpp\
    ../../container/Bag/Bag.cpp\
    ../../container/DeQue/DeQue.cpp\
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
        
        // Build a sample heap:
        //           10
        //         /    \
        //       10      20
        //      /  \    /  \
        //    60   40  30  50
        //   /
        //  70
        
        // Tesst the builder and <<
        MinHeap<int> minHeap(10);  // Create a MinHeap with an root node 10
        
        cout << "Inserting elements into the MinHeap:" << endl;
        minHeap.Push(40);   // Push elements into the heap
        minHeap.Push(20);
        minHeap.Push(60);
        minHeap.Push(10);
        minHeap.Push(30);
        minHeap.Push(50);
        minHeap.Push(70);
    
        // Test LevelOrderIterator
        std::vector<BinaryTreeNode<int>*> levelOrderNodes = minHeap.LevelOrderIterator();   // Call LevelOrderIterator
        std::cout << "Level-order traversal of the heap:" << std::endl; // Print the values in level-order
        for (BinaryTreeNode<int>* node : levelOrderNodes) {
            std::cout << node->getData() << " ";
        }
        cout << endl;
        
        // Test the get_size and get_capacity functions
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "Top: " << minHeap.RootData() << endl;          // Should print 70
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 8
    
        // Pop the top element (max element) and check the top again
        cout << "\nPopping the top element (max element):" << endl;
    
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "New top: " << minHeap.RootData() << endl;      // Should print 60 (after popping 70)
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 7
    
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "New top: " << minHeap.RootData() << endl;      // Should print 50
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 6
    
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "New top: " << minHeap.RootData() << endl;      // Should print 40
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 5
    
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "New top: " << minHeap.RootData() << endl;      // Should print 30
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 4
    
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "New top: " << minHeap.RootData() << endl;      // Should print 20
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 3
    
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "New top: " << minHeap.RootData() << endl;      // Should print 10
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 2
    
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
        cout << "New top: " << minHeap.RootData() << endl;      // Should print 10
        cout << "Heap size: " << minHeap.CountNodes() << endl;  // Should print 1
        
        minHeap.Pop();
        cout << minHeap << endl;    // Print the MinHeap it self and level order traversal
    
        // Check if heap is empty
        cout << "\nIs the heap empty? " << (minHeap.IsEmpty() ? "Yes" : "No") << endl;  // Should print Yes
    
        // Try popping from an empty heap (this should throw an exception)
        try 
        {
            minHeap.Pop();  // Heap is empty now
        } 
        catch (const runtime_error& e) 
        {
            cout << "Caught exception: " << e.what() << endl;  // Should catch "Heap is empty" exception
        }
    
        // Check top on an empty heap (should throw an exception)
        try 
        {
            cout << "Top on empty heap: " << minHeap.RootData() << endl;
        } 
        catch (const runtime_error& e) 
        {
            cout << "Caught exception: " << e.what() << endl;  // Should catch "Heap is empty" exception
        }
    
        cout << "=== End of MinHeap Test ===\n\n";
    
        return 0;
    }    
    
    