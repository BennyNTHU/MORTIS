// g++ -std=c++17 DoublyLinkedList.cpp DoublyLinkedList-test.cpp ../DLIterator/DLIterator.cpp\
    ../DoubleNode/DoubleNode.cpp ../Node/Node.cpp ../ChainIterator/ChainIterator.cpp -o test

#include <iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

int main() 
{
    cout << "=== DoublyLinkedList Test Program ===\n";

    // Create DoublyLinkedList instances
    DoublyLinkedList<int> A;
    DoublyLinkedList<int> B;

    // Test InsertBack
    cout << "\nTesting InsertBack()\n";
    for (int i = 1; i <= 5; i++) 
    {
        A.InsertBack(i);
        B.InsertBack(i);
    }
    cout << "List A after inserting 1-5 at back: " << A << endl;
    std::cout << "Length of DoublyLinkedList: " << A.Length() << std::endl;

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
    DoublyLinkedList<int> C(A);
    cout << "List C (copy of A): " << C << endl;
    
    // Test Assignment Operator
    cout << "\nTesting Assignment Operator\n";
    DoublyLinkedList<int> D;
    D = C;
    cout << "List D (assigned from C): " << D << endl;
    
    cout << "\nTest completed successfully!\n";
    
    return 0;
}
