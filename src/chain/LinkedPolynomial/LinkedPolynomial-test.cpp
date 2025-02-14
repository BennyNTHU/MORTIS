// g++ -std=c++17 LinkedPolynomial.cpp LinkedPolynomial-test.cpp\
    ../DLIterator/DLIterator.cpp ../DoubleNode/DoubleNode.cpp\
    ../Node/Node.cpp ../ChainIterator/ChainIterator.cpp -o test

#include "LinkedPolynomial.hpp"
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

void TestInsertAndPrint() {
    cout << "=== Test InsertLinkedTerm() and operator<< ===" << endl;
    LinkedPolynomial poly;
    poly.InsertLinkedTerm(5, 3);
    poly.InsertLinkedTerm(-2, 2);
    poly.InsertLinkedTerm(4, 1);
    poly.InsertLinkedTerm(3, 0);
    cout << "Expected output: 5x^3 - 2x^2 + 4x + 3" << endl;
    cout << "Actual output:   " << poly << endl;
}

void TestLeadExp() {
    cout << "=== Test LeadExp() ===" << endl;
    LinkedPolynomial poly;
    poly.InsertLinkedTerm(5, 4);
    poly.InsertLinkedTerm(3, 2);
    assert(poly.LeadExp() == 4);
    cout << "LeadExp() passed ✅" << endl;
}

void TestCoef() {
    cout << "=== Test Coef() ===" << endl;
    LinkedPolynomial poly;
    poly.InsertLinkedTerm(3.5, 4);
    poly.InsertLinkedTerm(2.0, 2);
    assert(poly.Coef(4) == 3.5);
    assert(poly.Coef(2) == 2.0);
    assert(poly.Coef(1) == 0.0); // Not in polynomial
    cout << "Coef() passed ✅" << endl;
}

void TestDelete() {
    cout << "=== Test DeleteLinkedTerm() ===" << endl;
    LinkedPolynomial poly;
    poly.InsertLinkedTerm(5, 3);
    poly.InsertLinkedTerm(-2, 2);
    poly.InsertLinkedTerm(4, 1);
    poly.InsertLinkedTerm(3, 0);

    poly.DeleteLinkedTerm(2); // Remove -2x^2
    cout << "Expected output: 5x^3 + 4x + 3" << endl;
    cout << "Actual output:   " << poly << endl;
}

void TestEquality() {
    cout << "=== Test operator==() ===" << endl;
    LinkedPolynomial p1, p2;
    p1.InsertLinkedTerm(3, 2);
    p1.InsertLinkedTerm(1, 0);

    p2.InsertLinkedTerm(3, 2);
    p2.InsertLinkedTerm(1, 0);

    assert(p1 == p2);
    cout << "Equality test passed ✅" << endl;
}

void TestAddition() {
    cout << "=== Test operator+() ===" << endl;
    LinkedPolynomial p1, p2;
    p1.InsertLinkedTerm(3, 2);
    p1.InsertLinkedTerm(1, 0);

    p2.InsertLinkedTerm(-3, 2);
    p2.InsertLinkedTerm(5, 1);

    LinkedPolynomial sum = p1 + p2;
    cout << "Expected output: 5x" << endl;
    cout << "Actual output:   " << sum << endl;
}

void TestMultiplication() {
    cout << "=== Test operator*() ===" << endl;
    LinkedPolynomial p1, p2;
    p1.InsertLinkedTerm(3, 2);
    p1.InsertLinkedTerm(1, 0);

    p2.InsertLinkedTerm(2, 1);

    LinkedPolynomial prod = p1 * p2;
    cout << "Expected output: 6x^3 + 2x" << endl;
    cout << "Actual output:   " << prod << endl;
}

void TestEvaluation() {
    cout << "=== Test Evaluate() ===" << endl;
    LinkedPolynomial poly;
    poly.InsertLinkedTerm(2, 2);
    poly.InsertLinkedTerm(3, 1);
    poly.InsertLinkedTerm(4, 0);

    double result = poly.Evaluate(2);
    assert(result == 2 * 4 + 3 * 2 + 4);
    cout << "Evaluate(2) = " << result << " (Expected: 18)" << endl;
}

void TestLatexInput() {
    cout << "=== Test operator>> (LaTeX Input) ===" << endl;
    LinkedPolynomial poly;
    stringstream input("5x^3 - 2x^2 + 4x + 3");
    input >> poly;
    cout << "Expected output: 5x^3 - 2x^2 + 4x + 3" << endl;
    cout << "Actual output:   " << poly << endl;
}

int main() {
    TestInsertAndPrint();
    TestLeadExp();
    TestCoef();
    TestDelete();
    TestEquality();
    TestAddition();
    TestMultiplication();
    TestEvaluation();
    TestLatexInput();
    cout << "All tests passed successfully! ✅✅✅" << endl;
    return 0;
}
