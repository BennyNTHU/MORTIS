// g++ -std=c++17 LinkedList.cpp LinkedList-test.cpp\
    ../Node/Node.cpp\
    ../ChainIterator/ChainIterator.cpp\
    ../DoubleNode/DoubleNode.cpp\
    ../DLIterator/DLIterator.cpp\
    ../DoublyLinkedList/DoublyLinkedList.cpp -o test

#include <iostream>
#include <algorithm>
#include "LinkedList.hpp"
using namespace std;

int main() 
{
    cout << "=== LinkedList Test Program ===\n";

    // Create LinkedList instances
    LinkedList<int> A;
    LinkedList<int> B;

    // Test InsertBack
    for (int i = 1; i <= 5; i++) 
    {
        A.InsertBack(i);
        B.InsertBack(i);
    }
    cout << "List A after inserting 1-5 at back: " << A << endl;

    // Test InsertFront
    cout << "\nTesting InsertFront()\n";
    A.InsertFront(0);
    cout << "List A after inserting 0 at front: " << A << endl;
    
    // Test Insert at specific position
    cout << "\nTesting Insert() at position 3\n";
    A.Insert(3, 6);
    cout << "List A after inserting 6 at position 3: " << A << endl;
    
    // Test DeleteFront
    cout << "\nTesting DeleteFront()\n";
    A.DeleteFront();
    cout << "List A after deleting front: " << A << endl;
    
    // Test DeleteBack
    cout << "\nTesting DeleteBack()\n";
    A.DeleteBack();
    cout << "List A after deleting back: " << A << endl;
    
    // Test Delete at specific position
    cout << "\nTesting Delete() at position 2\n";
    A.Delete(2);
    cout << "List A after deleting at position 2: " << A << endl;
    
    // Test Concatenate
    cout << "\nTesting Concatenate()\n";
    A.Concatenate(B);
    cout << "List A after concatenation with B (1-5): " << A << endl;
    
    // Test Reverse
    cout << "\nTesting Reverse()\n";
    A.Reverse();
    cout << "List A after reversal: " << A << endl;
    
    // Test Iterator functionality
    cout << "\nTesting Iterator\n";
    cout << "Iterating over List A: ";
    for (auto it = A.begin(); it != A.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout << endl;
    
    // Test Copy Constructor
    cout << "\nTesting Copy Constructor\n";
    LinkedList<int> C(A);
    cout << "List C (copy of A): " << C << endl;
    
    // Test Assignment Operator
    cout << "\nTesting Assignment Operator\n";
    LinkedList<int> D;
    D = C;
    cout << "List D (assigned from C): " << D << endl;
    
    // Test Get() function
    cout << "\nTesting Get()\n";
    cout << "Element at index 2 in List A: " << A.Get(2)->getData() << endl;
    
    // Test == operator
    cout << "\nTesting == operator\n";
    cout << "Is List C equal to List D? " << (C == D ? "Yes" : "No") << endl;
    
    // Test != operator
    cout << "\nTesting != operator\n";
    cout << "Is List A not equal to List B? " << (A != B ? "Yes" : "No") << endl;

    // Test IsEmpty function
    cout << "\nTesting IsEmpty()\n";
    cout << "Is List A empty? " << (A.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Is List B empty? " << (B.IsEmpty() ? "Yes" : "No") << endl;

    // Test sublist of A from index 1 to 3
    LinkedList<int> sublist = A.GetSublist(1, 3);

    // Print the sublist
    std::cout << "Sublist from index 1 to 3: ";
    for (int i = 0; i < 3; i++) 
    {
        std::cout << sublist.Get(i)->getData() << " ";
    }
    std::cout << std::endl;
    
    cout << "\nTest completed successfully!\n";
    return 0;
}
