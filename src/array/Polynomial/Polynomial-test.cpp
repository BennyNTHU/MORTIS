// Polynomial-test.cpp
// Compile with C++17:
//   g++ -std=c++17 Polynomial.cpp Polynomial-test.cpp -o test
#include <iostream>
#include <sstream>
#include "Polynomial.hpp"

using namespace std;

int main() 
{
    cout << "=== Polynomial Test Program ===" << endl << endl;

    // --- Test Default Constructor ---
    Polynomial p;
    cout << "Default polynomial p: " << p << endl;

    // --- Test Input Operator (operator>>)
    // Here we simulate input using a string stream.
    // Input string follows LaTeX format (e.g., "3x^{3}+2x^{2}+0.5x+1")
    string polyInput = "3x^{3}+2x^{2}+0.5x+1";
    istringstream iss(polyInput);
    iss >> p;
    cout << "\nAfter reading from input \"" << polyInput << "\":" << endl;
    cout << "Polynomial p: " << p << endl;

    // --- Test Accessor Methods ---
    cout << "\nCoefficient of x^2 in p: " << p.Coef(2) << endl;
    cout << "Leading exponent of p: " << p.LeadExp() << endl;
    cout << "p evaluated at x = 2: " << p.Eval(2.0f) << endl;

    // --- Test NewTerm(float, int) ---
    cout << "\nAdding new term 4x^4 to p using NewTerm(float, int):" << endl;
    p.NewTerm(4, 4);
    cout << "Updated polynomial p: " << p << endl;

    // --- Test NewTerm(LaTeX string) ---
    // Assume you have overloaded NewTerm() to accept a LaTeX formatted string.
    // For example, adding term "-5x^{1}".
    cout << "\nAdding new term \"-5x^{1}\" to p using NewTerm(string):" << endl;
    p.NewTerm("-5x^{1}");
    cout << "Updated polynomial p: " << p << endl;

    // --- Test Copy Constructor and Assignment Operator ---
    Polynomial q = p;  // Copy constructor
    cout << "\nCopied polynomial q (via copy constructor): " << q << endl;
    Polynomial r;
    r = p;           // Assignment operator
    cout << "Assigned polynomial r (via operator=): " << r << endl;

    // --- Test Equality and Inequality Operators ---
    if (p == q)
        cout << "\np equals q" << endl;
    else
        cout << "\np does not equal q" << endl;
    
    if (p != r)
        cout << "p is not equal to r (unexpected)" << endl;
    else
        cout << "p equals r" << endl;

    // --- Test Overloaded Arithmetic Operators ---
    // (Assuming you have overloaded +, -, and * for Polynomial.)
    Polynomial sum = p + q;
    cout << "\nSum (p + q): " << sum << endl;
    Polynomial diff = p - q;
    cout << "Difference (p - q): " << diff << endl;
    Polynomial prod = p * q;
    cout << "Product (p * q): " << prod << endl;

    // --- Test Constant Multiplication ---
    // (Assuming you have overloaded operator* for multiplying a polynomial by a constant.)
    Polynomial scaled = p * 2.5;
    cout << "\nScaled polynomial (p * 2.5): " << scaled << endl;

    // --- Test Differentiation ---
    Polynomial dp = p.Differentiate();
    cout << "\nDerivative of p: " << dp << endl;

    cout << "\n=== End of Polynomial Test Program ===" << endl;
    return 0;
}
