// g++ -std=c++17 CircularList.cpp CircularList-test.cpp ../ChainIterator/ChainIterator.cpp ../Node/Node.cpp ../LinkedList/LinkedList.cpp -o test

#include <iostream>
#include "CircularList.hpp"
using namespace std;

int main() 
{
    cout << "=== CircularList Test Program ===\n";

    // Create CircularList instances
    CircularList<int> A;
    CircularList<int> B;

    //Test InsertBack
    cout << "\nTesting InsertBack()\n";
    for (int i = 1; i <= 5; i++) 
    {
        A.InsertBack(i);
        B.InsertBack(i);
    }
    cout << "Circular List A after inserting 1-5 at back: " << A << endl;
    cout << "The length of Circular List A: " << A.Length() << endl;
    
    // Test InsertFront
    cout << "\nTesting InsertFront()\n";
    A.InsertFront(0);
    cout << "Circular List A after inserting 0 at front: " << A << endl;
    
    // Test Insert at specific position
    cout << "\nTesting Insert() at position 3\n";
    A.Insert(3, 6);
    cout << "Circular List A after inserting 6 at position 3: " << A << endl;
    
    // Test DeleteFront
    cout << "\nTesting DeleteFront()\n";
    A.DeleteFront();
    cout << "Circular List A after deleting front: " << A << endl;
    
    // Test DeleteBack
    cout << "\nTesting DeleteBack()\n";
    A.DeleteBack();
    cout << "Circular List A after deleting back: " << A << endl;
    
    // Test Delete at specific position
    cout << "\nTesting Delete() at position 2\n";
    A.Delete(2);
    cout << "Circular List A after deleting at position 2: " << A << endl;
    
    // Test Concatenate
    cout << "\nTesting Concatenate()\n";
    A.Concatenate(B);
    cout << "Circular List A after concatenation with B (1-5): " << A << endl;
    
    // Test Reverse
    cout << "\nTesting Reverse()\n";
    A.Reverse();
    cout << "Circular List A after reversal: " << A << endl;
    
    // Test Iterator functionality
    int j=1;
    cout << "\nTesting Iterator\n";
    cout << "Iterating over Circular List A: ";
    for (auto it = A.begin(); j <= 3; ++it, j++) 
    {
        cout << *it << " ";
    }
    cout << endl;
    
    // Test Copy Constructor
    cout << "\nTesting Copy Constructor\n";
    CircularList<int> C(A);
    cout << "Circular List C (copy of A): " << C << endl;
    
    // Test Assignment Operator
    cout << "\nTesting Assignment Operator\n";
    CircularList<int> D;
    D = C;
    cout << "Circular List D (assigned from C): " << D << endl;
    
    cout << "\nTest completed successfully!\n";
    return 0;
}
