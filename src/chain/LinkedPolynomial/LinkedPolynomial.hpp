#ifndef LINKEDPOLYNOMIAL
#define LINKEDPOLYNOMIAL

#include <iostream>
#include <math.h>
#include "../Node/Node.hpp"
#include "../Node/Node.cpp"
#include "../DoubleNode/DoubleNode.hpp"
#include "../DoubleNode/DoubleNode.cpp"
#include "../ChainIterator/ChainIterator.hpp"
#include "../ChainIterator/ChainIterator.cpp"
#include "../DLIterator/DLIterator.hpp"
#include "../DLIterator/DLIterator.cpp"

using namespace std;

// LinkedTerm represents a single term in the polynomial
class LinkedTerm 
{
    private:
        double coef;    // 係數
        int exp;        // 指數

    public:
        LinkedTerm() : coef(0), exp(0) {}                  // Default constructor
        LinkedTerm(double c, int e) : coef(c), exp(e) {}   // Constructor with coefficient and exponent
    
        // Getter and setter functions
        double get_coef() const {return coef;}
        int get_exp() const {return exp;}
        double& get_coef_ref() {return coef;}
        void set_coef(double new_coef) { coef = new_coef; } // Allows modifying coefficient
    
        // Overloaded operators
        bool operator==(const LinkedTerm& other) const 
        {
            return coef == other.coef && exp == other.exp;
        }
};

// 多項式類別宣告
class LinkedPolynomial 
{
    private:
        DoubleNode<LinkedTerm>* first;  // Pointer to the first term
        DoubleNode<LinkedTerm>* last;   // Pointer to the last term
        int capacity;                   // termArray 的容量
        int terms;                      // 實際的項數（非零項）
    
    public:
        // 建構子與解構子
        LinkedPolynomial();                              // 建構 p(x)=0
        LinkedPolynomial(const LinkedPolynomial& other); // 複製建構子（深拷貝）
        ~LinkedPolynomial();                             // 解構子，釋放記憶體

        // 屬性存取函式
        int LeadExp();                          // Returns the highest exponent in the polynomial
        double Coef(int e);                     // Returns the coefficient of the term with exponent e
        DLIterator<LinkedTerm> begin() const;   // Return iterator to the beginning
        DLIterator<LinkedTerm> end() const;     // Return iterator to the end

        // 多項式運算
        LinkedPolynomial operator+(const LinkedPolynomial& other) const;    // 多項式加法
        LinkedPolynomial operator*(const LinkedPolynomial& other) const;    // 多項式減法
        LinkedPolynomial Differentiate() const;                             // Differentiates the polynomial
        double Evaluate(double x) const;                                    // Evaluates the polynomial at a given x

        // 其他函式
        void Clear();                                   // Clear the polynomial
        void CopyFrom(const LinkedPolynomial& other);   // Copy polynomial from another
        void InsertLinkedTerm(double coef, int exp);    // 新增一項至多項式
        void DeleteLinkedTerm(int exp);                 // 刪除一項

        // 運算子重載
        bool operator==(const LinkedPolynomial& other) const;                             // 相等運算子，檢查兩多項式是否相等 X
        friend std::ostream& operator<<(std::ostream& out, const LinkedPolynomial& poly); // 輸出運算子，以 LaTeX 語法輸出多項式
        friend std::istream& operator>>(std::istream &in, LinkedPolynomial &poly);        // 輸入運算子，從 LaTeX 格式字串建立多項式 X
        LinkedPolynomial& operator=(const LinkedPolynomial &);                            // 賦值運算子 (深拷貝)
};

#endif
