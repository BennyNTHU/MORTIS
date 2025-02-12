// Compile with C++17:
//   g++ -std=c++17 GeneralArray.cpp GeneralArray-test.cpp -o test

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <variant>
#include "GeneralArray.hpp"
using namespace std;

int main() 
{
    try 
    {
        cout << "=== Test 1: Int Array (1D) ===" << endl;
        vector<int> dims1 = {5};
        GeneralArray<int> arrInt(1, dims1, 0);
        arrInt.Store({0}, 10);
        arrInt.Store({1}, 20);
        arrInt.Store({2}, 30);
        arrInt.Store({3}, 40);
        arrInt.Store({4}, 50);
        cout << "Initial int array: " << arrInt << endl;
        cout << "Element at index [2]: " << arrInt.Retrieve({2}) << endl;
        cout << "Length: " << arrInt.length() << endl;
        arrInt.reverse();
        cout << "After reverse: " << arrInt << endl;
        arrInt.initialize();
        cout << "After initialize: " << arrInt << endl;
        arrInt = {1, 2, 3, 4, 5};
        cout << "After initializer_list assignment: " << arrInt << endl;
        
        // 複製建構子與相等運算子測試
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
        arrDouble.sort(true);
        cout << "Sorted ascending: " << arrDouble << endl;
        arrDouble.sort(false);
        cout << "Sorted descending: " << arrDouble << endl;
        arrDouble.reverse();
        cout << "After reverse: " << arrDouble << endl;
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
        arrChar = {'W', 'O', 'R', 'L', 'D'};
        cout << "After initializer_list assignment: " << arrChar << endl;
        
        cout << "\n=== Test 4: 2D Int Array ===" << endl;
        vector<int> dims2D = {3, 3}; 
        GeneralArray<int> arr2D(2, dims2D, 0);
        istringstream iss("[[9,8,7],[6,5,4],[3,2,1]]");
        iss >> arr2D;
        cout << "Input 2D array: " << arr2D << endl;
        arr2D.sort(true, 1);
        cout << "2D array sorted ascending by first column: " << arr2D << endl;
        arr2D.sort(false, 1);
        cout << "2D array sorted descending by first column: " << arr2D << endl;
        
        cout << "\n=== Test 5: Heterogeneous Array (std::variant) ===" << endl;
        using VarType = MIXED_TYPE;
        vector<int> dimsVar = {6};
        GeneralArray<VarType> arrVariant(1, dimsVar, VarType{});
        arrVariant.Store({0}, 100);
        arrVariant.Store({1}, std::string("Test"));
        arrVariant.Store({2}, 'Z');
        
        cout << "Heterogeneous array: " << arrVariant << endl;
        
        // 額外測試：混合測試，使用 initializer_list 建立 variant 陣列
        GeneralArray<VarType> arrVariant2(1, dimsVar, VarType{});
        arrVariant2 = {VarType(42), VarType('X'), VarType(std::string("Hello"))};
        cout << "Variant array from initializer_list: " << arrVariant2 << endl;
        
    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
