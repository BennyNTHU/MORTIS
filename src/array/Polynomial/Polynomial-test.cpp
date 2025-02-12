// Polynomial-test.cpp
// 測試多項式資料結構的完整功能
// 測試項目包括：
//  - 從標準輸入以 LaTeX 語法讀取多項式（例如：3x^{3}+2x^{2}+0.5x+1）
//  - 輸出多項式，以 LaTeX 語法呈現且係數若為整數則以整數表示，浮點數則保持原有格式
//  - 測試存取函式 Coef、LeadExp 與 Eval
//  - 測試新增項 NewTerm、複製建構子、賦值運算子與相等運算子
//  - 測試多項式加法、減法、乘法
//
// 請依下列說明進行編譯與執行
// Compile with C++17:
//   g++ -std=c++17 Polynomial.cpp Polynomial-test.cpp -o test

#include <iostream>
#include "Polynomial.hpp"
using namespace std;

int main()
{
    cout << "=== Polynomial Test Program ===" << endl;

    // 測試 1：使用預設建構子建立多項式 P(x)=0
    Polynomial P;
    cout << "\nDefault polynomial P: " << P << endl;

    // 測試 2：利用 operator>> 讀取符合 LaTeX 語法的多項式字串
    // 輸入範例格式： 3x^{3}+2x^{2}+0.5x+1
    cout << "\nEnter polynomial P in LaTeX format (e.g., 3x^{3}+2x^{2}+0.5x+1):" << endl;
    cin >> P;
    cout << "Polynomial P: " << P << endl;

    // 測試 3：存取函式 Coef、LeadExp 與 Eval
    cout << "\nCoefficient of x^2 in P: " << P.Coef(2) << endl;
    cout << "Leading exponent of P: " << P.LeadExp() << endl;
    cout << "P evaluated at x = 2: " << P.Eval(2.0f) << endl;

    // 測試 4：使用 NewTerm 新增項 (例如新增項 4x^4)
    cout << "\nAdding new term: 4x^4" << endl;
    P.NewTerm(4, 4);
    cout << "Updated polynomial P: " << P << endl;

    // 測試 5：複製建構子與賦值運算子
    Polynomial Q = P;  // 複製建構子
    cout << "\nCopied polynomial Q (via copy constructor): " << Q << endl;
    Polynomial R;
    R = P;           // 賦值運算子
    cout << "Assigned polynomial R (via operator=): " << R << endl;

    // 測試 6：相等運算子 (operator==)
    if (P == Q)
        cout << "P equals Q" << endl;
    else
        cout << "P does not equal Q" << endl;

    // 測試 7：多項式加法與減法
    cout << "\nEnter another polynomial Q in LaTeX format (e.g., 2x^{2}+1):" << endl;
    cin >> Q;
    cout << "Polynomial Q: " << Q << endl;
    Polynomial Sum = P.Add(Q);
    cout << "Sum (P + Q): " << Sum << endl;
    Polynomial Diff = P.Sub(Q);
    cout << "Difference (P - Q): " << Diff << endl;

    // 測試 8：多項式乘法
    Polynomial Prod = P.Mult(Q);
    cout << "\nProduct (P * Q): " << Prod << endl;

    return 0;
}
