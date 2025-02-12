#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <iostream>
#include <math.h>
using namespace std;

// forward declaration of Polynomial
class Polynomial;

// 定義多項式的項（Term）
class Term 
{
    friend class Polynomial;    // 允許 Polynomial 存取 Term 的私有成員

    private:
        float coef;  // 係數
        int exp;     // 指數

    public:
    Term() : coef(0), exp(0) {}                 // 預設建構子：初始化為 0x^0
    Term(int e, float c) : coef(c), exp(e) {}   // 建構子：根據指定指數 e 與係數 c 建立項
    float get_coef() const { return coef; }     // 取得係數（改為 const 成員函式）
    int get_exp() const { return exp; }         // 取得指數（改為 const 成員函式）
    void write_term(int e, int c) { exp = e; coef = c; }    // 寫入新項：覆蓋原有項 (此函式可依需求修改)
};

// 多項式類別宣告
class Polynomial 
{
    private:
        Term *termArray;   // 儲存各項的陣列
        int capacity;      // termArray 的容量
        int terms;         // 實際的項數（非零項）
    
    public:
        // 建構子與解構子
        Polynomial();                             // 建構 p(x)=0
        Polynomial(Term* t, int degree);          // 透過指定 Term 陣列建立多項式
        Polynomial(const Polynomial &poly);       // 複製建構子（深拷貝）
        ~Polynomial();                            // 解構子，釋放記憶體

        // 屬性存取函式
        float Coef(int e);                        // 回傳指數為 e 的項之係數，若不存在則回傳 0
        int LeadExp();                            // 回傳多項式的最高指數（次數）
        float Eval(float x);                      // 計算並回傳 p(x) 的值
        void NewTerm(const float theCoeff, const int theExp);   // 新增一項至多項式

        // 多項式運算
        Polynomial Add(Polynomial poly);          // 多項式加法
        Polynomial Sub(Polynomial poly);          // 多項式減法
        Polynomial Mult(Polynomial poly);         // 多項式乘法

        // 運算子重載
        friend istream& operator>>(istream& in, Polynomial& poly); // 輸入運算子，從 LaTeX 格式字串建立多項式
        friend ostream& operator<<(ostream& out, const Polynomial& poly); // 輸出運算子，以 LaTeX 語法輸出多項式

        Polynomial& operator=(const Polynomial &);  // 賦值運算子 (深拷貝)
        bool operator==(const Polynomial &) const;    // 相等運算子，檢查兩多項式是否相等
};

// 全域的輸入與輸出運算子宣告
istream& operator>>(istream& in, Polynomial& poly);
ostream& operator<<(ostream& out, const Polynomial& poly);

#endif
