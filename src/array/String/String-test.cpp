// String-test.cpp
// Test program for the String data structure.
// This program tests construction, concatenation, substring extraction,
// deletion, character deletion, failure function and KMP-based pattern matching,
// reverse, equality, empty check, and assignment operator.
// Compile with C++17 (e.g., using g++):
//   g++ -std=c++17 String.cpp String-test.cpp -o test

#include <iostream>
#include "String.hpp"
using namespace std;

int main() {
    cout << "=== String Test Program ===" << endl;
    
    // Test 1: Constructor, getString(), overload <<, and Length()
    char init1[] = "Hello, World!";
    String s1(init1, sizeof(init1) - 1);
    cout << "overload << operator to print s1: " << s1 << endl;
    cout << "s1: " << s1.getString() << endl;
    cout << "Length of s1: " << s1.Length() << endl;
    
    // Test 2: reverse()
    String sRev = s1.reverse();
    cout << "Reversed s1: " << sRev.getString() << endl;
    
    // Test 3: Concat
    char init2[] = " Goodbye!";
    String s2(init2, sizeof(init2) - 1);
    String s3 = s1.Concat(s2);
    cout << "s1 concatenated with s2: " << s3.getString() << endl;
    
    // Test 4: Substr
    try {
        String sub = s1.Substr(7, 5); // Expect "World"
        cout << "Substring of s1 (index 7, length 5): " << sub.getString() << endl;
    } catch (const char* err) {
        cout << "Substr error: " << err << endl;
    }
    
    // Test 5: Delete
    try {
        String del = s1.Delete(5, 3);
        cout << "s1 after deleting 3 characters from index 5: " << del.getString() << endl;
    } catch (const char* err) {
        cout << "Delete error: " << err << endl;
    }
    
    // Test 6: CharDelete
    String cd = s1.CharDelete('o');
    cout << "s1 after deleting 'o': " << cd.getString() << endl;
    
    // Test 7: FailureFunction and FastFind (KMP)
    char patInit[] = "World";
    String pattern(patInit, sizeof(patInit) - 1);
    int pos = s1.FastFind(pattern);
    cout << "Position of 'World' in s1: " << pos << endl;
    
    // Test 8: Operator==
    char init3[] = "Hello, World!";
    String s4(init3, sizeof(init3) - 1);
    if (s1 == s4)
        cout << "s1 equals s4." << endl;
    else
        cout << "s1 does not equal s4." << endl;
    
    // Test 9: Operator! (empty test)
    char initEmpty[] = "";
    String emptyStr(initEmpty, 0);
    if (!emptyStr)
        cout << "emptyStr is empty." << endl;
    else
        cout << "emptyStr is not empty." << endl;
    
    // Test 10: Assignment operator (deep copy)
    String s5 = s1;
    cout << "s5 (assigned from s1): " << s5.getString() << endl;
    
    return 0;
}
