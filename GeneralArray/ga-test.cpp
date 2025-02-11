#include <iostream>               // For standard I/O
#include <vector>                 // For std::vector
#include <sstream>                // For istringstream (simulate input)
#include <string>                 // For std::string
#include "GeneralArray.h"         // Include the GeneralArray header
using namespace std;

int main() 
{
    try 
    {
        cout << "=== Test 1: Int Array (1D) ===" << endl;
        // Create a 1D int array with 5 elements, initial value 0
        vector<int> dims1 = {5};
        GeneralArray<int> arrInt(1, dims1, 0);
        // Use Store() to set values
        arrInt.Store({0}, 10);
        arrInt.Store({1}, 20);
        arrInt.Store({2}, 30);
        arrInt.Store({3}, 40);
        arrInt.Store({4}, 50);
        cout << "Initial int array: " << arrInt << endl;
        cout << "Element at index [2]: " << arrInt.Retrieve({2}) << endl;
        cout << "Length of int array: " << arrInt.length() << endl;
        // Test reverse()
        arrInt.reverse();
        cout << "After reverse: " << arrInt << endl;
        // Test initialize()
        arrInt.initialize();
        cout << "After initialize (all elements set to 0): " << arrInt << endl;
        // Test initializer_list assignment
        arrInt = {1, 2, 3, 4, 5};
        cout << "After initializer_list assignment: " << arrInt << endl;
        // Test copy constructor and equality operator
        GeneralArray<int> arrIntCopy = arrInt;
        cout << "Copied int array: " << arrIntCopy << endl;
        cout << "Equality test: " << (arrInt == arrIntCopy ? "Equal" : "Not equal") << endl;
        
        
        cout << "\n=== Test 2: Double Array (1D) ===" << endl;
        GeneralArray<double> arrDouble(1, dims1, 0.0);
        arrDouble.Store({0}, 3.14);
        arrDouble.Store({1}, 2.71);
        arrDouble.Store({2}, 1.41);
        arrDouble.Store({3}, 0.577);
        arrDouble.Store({4}, 1.618);
        cout << "Initial double array: " << arrDouble << endl;
        // Test sorting: ascending order
        arrDouble.sort(true);
        cout << "Sorted ascending: " << arrDouble << endl;
        // Test sorting: descending order
        arrDouble.sort(false);
        cout << "Sorted descending: " << arrDouble << endl;
        // Test reverse()
        arrDouble.reverse();
        cout << "After reverse: " << arrDouble << endl;
        // Test initializer_list assignment
        arrDouble = {2.71, 3.14, 1.41, 1.73, 0.0};
        cout << "After initializer_list assignment: " << arrDouble << endl;
        
        
        cout << "\n=== Test 3: Char Array (1D) ===" << endl;
        vector<int> dimsChar = {5};
        GeneralArray<char> arrChar(1, dimsChar, ' ');
        arrChar.Store({0}, 'H');
        arrChar.Store({1}, 'E');
        arrChar.Store({2}, 'L');
        arrChar.Store({3}, 'L');
        arrChar.Store({4}, 'O');
        cout << "Initial char array: " << arrChar << endl;
        // Test initializer_list assignment
        arrChar = {'W', 'O', 'R', 'L', 'D'};
        cout << "After initializer_list assignment: " << arrChar << endl;
        
        
        cout << "\n=== Test 4: 2D Int Array ===" << endl;
        vector<int> dims2D = {3, 3}; // 3 rows x 3 columns
        GeneralArray<int> arr2D(2, dims2D, 0);
        // Simulate input via stringstream: format must be like [[9,8,7],[6,5,4],[3,2,1]]
        istringstream iss("[[9,8,7],[6,5,4],[3,2,1]]");
        iss >> arr2D;
        cout << "Input 2D array: " << arr2D << endl;
        // Test sort() on 2D array based on first column (sortDim = 1)
        arr2D.sort(true, 1);
        cout << "2D array sorted ascending by first column: " << arr2D << endl;
        arr2D.sort(false, 1);
        cout << "2D array sorted descending by first column: " << arr2D << endl;
        
        
        cout << "\n=== Test 5: Heterogeneous Array using std::variant ===" << endl;
        // Define a variant type supporting int, char, and string.
        using VarType = std::variant<int, char, std::string>;
        vector<int> dimsVar = {3};
        GeneralArray<VarType> arrVariant(1, dimsVar, VarType{});
        // Use Store() (operator>> is not supported for variant types)
        arrVariant.Store({0}, 100);                // int
        arrVariant.Store({1}, 'Z');                // char
        arrVariant.Store({2}, std::string("Test"));  // string
        cout << "Heterogeneous array: " << arrVariant << endl;
        
    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
