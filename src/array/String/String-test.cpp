// String-test.cpp
// Compile with: 
//    g++ -std=c++17 String.cpp String-test.cpp -o test
#include <iostream>
#include <cassert>
#include "String.hpp"

using namespace std;

int main() 
{
    cout << "=== String Test Program ===" << endl << endl;

    // Test 1: Default Constructor (should create an empty string)
    String s_default;
    cout << "Default constructed string: \"" << s_default << "\"" << endl;
    assert(s_default.Length() == 0);
    if (!s_default)
        cout << "Default string is empty." << endl;
    else
        cout << "Error: Default string is not empty." << endl;
    cout << "--------------------------" << endl;

    // Test 2: Construct from C-string literal using conversion constructor
    // (Assuming you have added a constructor to allow: String s = "hello";)
    String s1 = "Hello, World!";
    cout << "String s1 (constructed from literal): \"" << s1 << "\"" << endl;
    cout << "Length of s1: " << s1.Length() << endl;
    cout << "Failure function of s1: ";
    int* f = s1.getFailure();
    for (int i = 0; i < s1.Length(); i++)
        cout << f[i] << " ";
    cout << endl;
    cout << "--------------------------" << endl;

    // Test 3: Copy constructor and assignment operator
    String s2 = s1;  // copy constructor
    cout << "String s2 (copy of s1): \"" << s2 << "\"" << endl;
    String s3;
    s3 = s1;         // assignment operator
    cout << "String s3 (assigned from s1): \"" << s3 << "\"" << endl;
    assert(s1 == s2 && s1 == s3);
    cout << "s1 equals s2 and s3." << endl;
    cout << "--------------------------" << endl;

    // Test 4: Concatenation (Concat)
    String s4 = " Goodbye!";
    String s_concat = s1.Concat(s4);
    cout << "Concatenation: s1 + s4 = \"" << s_concat << "\"" << endl;
    // Alternatively, if you overloaded + operator, you can test that as well.
    cout << "--------------------------" << endl;

    // Test 5: Substring (Substr)
    // Extract "World" from "Hello, World!"
    int start = 7;
    int len = 5;
    String s_sub = s1.Substr(start, len);
    cout << "Substring of s1 starting at " << start << " with length " << len << ": \"" << s_sub << "\"" << endl;
    cout << "--------------------------" << endl;

    // Test 6: Delete (delete a block of characters)
    // Delete ", World" from s1.
    String s_deleted = s1.Delete(5, 7);
    cout << "After deleting 7 characters starting from index 5 in s1: \"" << s_deleted << "\"" << endl;
    cout << "--------------------------" << endl;

    // Test 7: Character Deletion (CharDelete)
    // Remove all occurrences of 'l' (lowercase L) from s1.
    String s_charDel = s1.CharDelete('l');
    cout << "After deleting character 'l' from s1: \"" << s_charDel << "\"" << endl;
    cout << "--------------------------" << endl;

    // Test 8: Reverse
    String s_rev = s1.Reverse();
    cout << "Reversed s1: \"" << s_rev << "\"" << endl;
    cout << "--------------------------" << endl;

    // Test 9: FastFind (KMP search)
    // Search for substring "World" in s1.
    String pattern = "World";
    int pos = s1.FastFind(pattern);
    if (pos >= 0)
        cout << "Pattern \"" << pattern << "\" found in s1 at index: " << pos << endl;
    else
        cout << "Pattern \"" << pattern << "\" not found in s1." << endl;
    cout << "--------------------------" << endl;

    // Test 10: Subscript operator and operator! (empty test)
    cout << "s1[0] = '" << s1[0] << "'" << endl;
    cout << "s_default is " << ( !s_default ? "empty" : "not empty" ) << endl;
    cout << "--------------------------" << endl;

    // Test 11: Comparison operators (== and !=)
    String s_equal = "Hello, World!";
    assert(s1 == s_equal);
    cout << "s1 equals \"" << s_equal << "\"" << endl;
    String s_diff = "Different String";
    assert(s1 != s_diff);
    cout << "s1 is not equal to \"" << s_diff << "\"" << endl;
    cout << "--------------------------" << endl;

    cout << "\n=== End of String Test Program ===" << endl;
    return 0;
}
