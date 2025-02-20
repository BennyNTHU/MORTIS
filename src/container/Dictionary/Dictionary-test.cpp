// g++ -std=c++17 Dictionary.cpp Dictionary-test.cpp\
    ../../array/GeneralArray/GeneralArray.cpp\
    ../../array/Polynomial/Polynomial.cpp\
    ../../array/SparseMatrix/SparseMatrix.cpp\
    ../../array/String/String.cpp -o test

#include "Dictionary.hpp"
#include <iostream>
#include <cassert>

using namespace std;

// Test the constructor, insertion, and basic functionality
void testDictionaryBasics() 
{
    cout << "\n Testing Dictionary Basics\n";

    Dictionary<string, int> dict(10);

    assert(dict.Capacity() == 10);
    assert(dict.Size() == 0);
    assert(dict.IsEmpty());

    // Insert some key-value pairs
    dict.Insert({"apple", 3});
    dict.Insert({"banana", 2});
    dict.Insert({"apple", 5});
    dict.Insert({"orange", 7});
    dict.Insert({"banana", 4});

    assert(dict.Size() == 5);
    assert(!dict.IsEmpty());

    cout << "V Basic Dictionary Tests Passed!\n";
}

// Test `isBelong`
void testIsBelong() 
{
    cout << "\n* Testing isBelong()\n";

    Dictionary<string, int> dict(10);
    dict.Insert({"apple", 3});
    dict.Insert({"banana", 2});

    assert(dict.isBelong("apple"));
    assert(dict.isBelong("banana"));
    assert(!dict.isBelong("grape"));

    cout << "V isBelong() Tests Passed!\n";
}

// Test `Remove`
void testRemove() 
{
    cout << "\n* Testing Remove()\n";

    Dictionary<string, int> dict(10);
    dict.Insert({"apple", 3});
    dict.Insert({"banana", 2});
    dict.Insert({"apple", 5});

    dict.Remove("apple");
    assert(!dict.isBelong("apple"));
    assert(dict.isBelong("banana"));
    assert(dict.Size() == 1);

    cout << "V Remove() Tests Passed!\n";
}

// Test `Map`
void testMap() 
{
    cout << "\n* Testing Map()\n";

    Dictionary<string, int> dict(10);
    dict.Insert({"apple", 3});
    dict.Insert({"apple", 5});
    dict.Insert({"banana", 2});
    
    vector<int> appleValues = dict.Map("apple");
    assert(appleValues.size() == 2);
    assert(appleValues[0] == 3);
    assert(appleValues[1] == 5);

    vector<int> bananaValues = dict.Map("banana");
    assert(bananaValues.size() == 1);
    assert(bananaValues[0] == 2);

    vector<int> grapeValues = dict.Map("grape");
    assert(grapeValues.empty());

    cout << "V Map() Tests Passed!\n";
}

// Test `reduce`
void testReduce() 
{
    cout << "\n* Testing reduce()\n";

    Dictionary<string, int> dict(10);
    dict.Insert({"apple", 3});
    dict.Insert({"apple", 5});
    dict.Insert({"banana", 2});
    dict.Insert({"banana", 4});

    // Sum reducer function
    auto sumReducer = [](const int& a, const int& b) { return a + b; };
    dict.reduce(sumReducer);

    vector<int> appleValues = dict.Map("apple");
    vector<int> bananaValues = dict.Map("banana");

    assert(appleValues.size() == 1 && appleValues[0] == 8); // 3 + 5
    assert(bananaValues.size() == 1 && bananaValues[0] == 6); // 2 + 4

    cout << "V reduce() Tests Passed!\n";
}

// Test overloaded operators
void testOperators() 
{
    cout << "\n* Testing Operators\n";

    Dictionary<string, int> dict1(10);
    dict1.Insert({"apple", 3});
    dict1.Insert({"banana", 2});

    // Assignment operator
    Dictionary<string, int> dict2 = dict1;
    assert(dict2.Size() == dict1.Size());

    // Equality check
    assert(dict1 == dict2);
    
    dict2.Insert({"grape", 5});
    assert(dict1 != dict2);

    // Operator []
    dict2["banana"] = 7;
    assert(dict2["banana"] == 7);

    cout << "V Operators Tests Passed!\n";
}

// Test output operator
void testOutputOperator() 
{
    cout << "\n* Testing Output Operator (<<)\n";

    Dictionary<string, int> dict(10);
    dict.Insert({"apple", 3});
    dict.Insert({"banana", 2});
    dict.Insert({"apple", 5});

    cout << dict << endl;

    cout << "V Output Operator (<<) Tests Passed!\n";
}

// Main test runner
int main() 
{
    testDictionaryBasics();
    testIsBelong();
    testRemove();
    testMap();
    testReduce();
    testOperators();
    testOutputOperator();

    cout << "\n* ALL TESTS PASSED SUCCESSFULLY!\n";
    return 0;
}
