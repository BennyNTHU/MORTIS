// g++ -std=c++17 Set.cpp Set-test.cpp\
    ../BinarySearchTree/BinarySearchTree.cpp\
    ../BinaryTree/BinaryTree.cpp\
    ../BinaryTreeNode/BinaryTreeNode.cpp\
    ../../container/Bag/Bag.cpp\
    ../../container/DeQue/DeQue.cpp\
    ../../container/Stack/Stack.cpp\
    ../../array/GeneralArray/GeneralArray.cpp\
    ../../array/Polynomial/Polynomial.cpp\
    ../../array/SparseMatrix/SparseMatrix.cpp\
    ../../array/String/String.cpp -o test -o test

#include "Set.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void TestSetOperations() 
{
    Set<int> A = {1, 2, 3, 4, 5};
    Set<int> B = {4, 5, 6, 7, 8};

    cout << "Set A: ";
    A.Print();
    cout << "Set B: ";
    B.Print();

    Set<int> unionAB = A.Union(B);
    cout << "Union of A and B: ";
    unionAB.Print();

    Set<int> intersectionAB = A.Intersection(B);
    cout << "Intersection of A and B: ";
    intersectionAB.Print();

    Set<int> differenceAB = A.Difference(B);
    cout << "Difference (A - B): ";
    differenceAB.Print();

    Set<int> differenceBA = B.Difference(A);
    cout << "Difference (B - A): ";
    differenceBA.Print();

    Set<int> subsetA = {2, 3};
    cout << "Subset A: ";
    subsetA.Print();
    cout << "Is subsetA a subset of A? " << (subsetA.IsSubsetOf(A) ? "Yes" : "No") << endl;
    cout << "Is A a subset of B? " << (A.IsSubsetOf(B) ? "Yes" : "No") << endl;

    cout << "Does A contain 3? " << (A.Contains(3) ? "Yes" : "No") << endl;
    cout << "Does B contain 3? " << (B.Contains(3) ? "Yes" : "No") << endl;
}

void TestSetWithStrings() 
{
    Set<string> set1 = {"apple", "banana", "cherry"};
    Set<string> set2 = {"banana", "cherry", "date", "elderberry"};

    cout << "\nSet 1: ";
    set1.Print();
    cout << "Set 2: ";
    set2.Print();

    Set<string> unionSet = set1.Union(set2);
    cout << "Union of Set1 and Set2: ";
    unionSet.Print();

    Set<string> intersectionSet = set1.Intersection(set2);
    cout << "Intersection of Set1 and Set2: ";
    intersectionSet.Print();

    Set<string> differenceSet = set1.Difference(set2);
    cout << "Difference (Set1 - Set2): ";
    differenceSet.Print();
}

int main() 
{
    cout << "===== Testing Set Operations =====" << endl;
    TestSetOperations();

    cout << "\n===== Testing Set with Strings =====" << endl;
    TestSetWithStrings();

    return 0;
}
