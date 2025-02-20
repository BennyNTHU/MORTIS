#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <cmath>

#include "Polynomial.hpp"

using namespace std;

//===============================
// Constructors and Destructors
//===============================

// 多項式預設建構子：建立 p(x)=0
Polynomial::Polynomial() 
{
    // 初始化多項式只有一個項，代表常數 0
    terms = 1;           // 非零項數目設定為 1
    capacity = 1;        // 初始容量為 1
    termArray = (Term*)calloc(capacity, sizeof(Term)); // 分配記憶體並初始化為 0
    termArray[0].coef = 0.0f;  // 常數項係數為 0
    termArray[0].exp = 0;      // 指數為 0
}

// 透過指定的 Term 陣列與項數建立多項式
Polynomial::Polynomial(Term* t, int degree) 
{
    terms = degree;       // 非零項數目為 degree
    capacity = degree;    // 容量初始化為 degree
    termArray = (Term*)calloc(capacity, sizeof(Term)); // 分配記憶體
    // 將傳入的 t 陣列複製到 termArray
    for (int i = 0; i < degree; i++) 
    {
        termArray[i] = t[i];
    }
    free(t);  // 釋放傳入的暫存陣列
}

// 複製建構子：進行深拷貝
Polynomial::Polynomial(const Polynomial &poly) 
{
    capacity = poly.capacity; // 複製容量
    terms = poly.terms;       // 複製項數
    termArray = (Term*)calloc(capacity, sizeof(Term)); // 分配新記憶體
    for (int i = 0; i < terms; i++) 
    {
        termArray[i] = poly.termArray[i]; // 複製每一項
    }
}

// 解構子：釋放記憶體
Polynomial::~Polynomial() 
{
    free(termArray); // 釋放動態分配的記憶體
}

//===============================
// Member functions
//===============================

// Coef(e): 返回多項式中指數為 e 的項之係數；若不存在則返回 0
float Polynomial::Coef(int e) 
{
    for (int i = 0; i < terms; i++) 
    {
        if (termArray[i].exp == e)
            return termArray[i].coef;
    }
    return 0;
}

// LeadExp(): 返回多項式中最高指數（多項式的次數）
int Polynomial::LeadExp() 
{
    int lead = 0;
    for (int i = 0; i < terms; i++) 
    {
        if (termArray[i].exp > lead)
            lead = termArray[i].exp;
    }
    return lead;
}

// Eval(x): 評估多項式在 x 處的值，返回計算結果
float Polynomial::Eval(float x) 
{
    double value = 0;
    for (int i = 0; i < terms; i++) 
    {
        value += termArray[i].coef * pow(x, termArray[i].exp);
    }
    return static_cast<float>(value);
}

// Add a new term to the polynomial
void Polynomial::NewTerm(const float theCoeff, const int theExp) 
{
    // If the current number of terms equals the capacity,
    // we need to increase the capacity.
    if (terms == capacity) 
    {
        capacity *= 2; // Double the capacity.
        Term *temp = new Term[capacity];  // Allocate a new array.
        // Copy the existing terms into the new array.
        for (int i = 0; i < terms; i++) 
        {
            temp[i] = termArray[i];
        }
        delete[] termArray; // Free the old array.
        termArray = temp;   // Update the pointer.
    }
    // Insert the new term at the end.
    termArray[terms].coef = theCoeff;
    termArray[terms].exp = theExp;
    terms++; // Increase the count of terms.
}

// Overloaded NewTerm that accepts a LaTeX-formatted string.
// Example inputs: "3x^{3}", "-x^{2}", "7.25", "x"
void Polynomial::NewTerm(const std::string& latexTerm) 
{
    // Make a copy and remove all spaces.
    std::string term = latexTerm;
    term.erase(std::remove_if(term.begin(), term.end(), ::isspace), term.end());
    if (term.empty()) return; // Nothing to add.
    
    float coef = 1.0f;
    int exp = 0;
    
    // Look for the variable 'x'
    size_t xPos = term.find('x');
    if (xPos == std::string::npos) 
    {
        // No 'x' found, so it's a constant term.
        try 
        {
            coef = std::stof(term);
        } 
        catch (const std::exception&) 
        {
            throw std::invalid_argument("Invalid constant term in LaTeX string.");
        }
        exp = 0;
    } 
    else 
    {
        // There is an 'x'. The coefficient is the substring before 'x'
        std::string coefStr = term.substr(0, xPos);
        if (coefStr.empty()) 
        {
            coef = 1.0f;
        } 
        else if (coefStr == "-") 
        {
            coef = -1.0f;
        } 
        else 
        {
            try 
            {
                coef = std::stof(coefStr);
            } 
            catch (const std::exception&) 
            {
                throw std::invalid_argument("Invalid coefficient in LaTeX term.");
            }
        }
        // Default exponent is 1 if nothing follows 'x'
        exp = 1;
        // Check if there is a caret '^'
        size_t caretPos = term.find('^', xPos);
        if (caretPos != std::string::npos) 
        {
            // Check if exponent is enclosed in braces
            if (caretPos + 1 < term.size() && term[caretPos + 1] == '{') 
            {
                size_t endBrace = term.find('}', caretPos + 2);
                if (endBrace == std::string::npos)
                    throw std::invalid_argument("Missing closing brace in exponent.");
                std::string expStr = term.substr(caretPos + 2, endBrace - (caretPos + 2));
                try 
                {
                    exp = std::stoi(expStr);
                } 
                catch (const std::exception&) 
                {
                    throw std::invalid_argument("Invalid exponent in LaTeX term.");
                }
            } 
            else 
            {
                // Exponent is not enclosed; read directly until the end.
                std::string expStr = term.substr(caretPos + 1);
                try 
                {
                    exp = std::stoi(expStr);
                } 
                catch (const std::exception&) 
                {
                    throw std::invalid_argument("Invalid exponent in LaTeX term.");
                }
            }
        }
    }
    // Add the new term using the standard NewTerm(float, int) method.
    this->NewTerm(coef, exp);
}

// Implement Differentiate(): returns the derivative polynomial.
Polynomial Polynomial::Differentiate() const {
    Polynomial derivative;
    for (int i = 0; i < terms; i++) {
        int exp = termArray[i].exp;
        float coef = termArray[i].coef;
        if (exp > 0) {
            derivative.NewTerm(coef * exp, exp - 1);
        }
        // If exp == 0, derivative is 0 (skip it).
    }
    return derivative;
}

//===============================
// Operator overloads
//===============================

// Replace Add() with operator+
Polynomial Polynomial::operator+(const Polynomial& poly) const 
{
    Polynomial result;
    int aPos = 0, bPos = 0;

    while (aPos < terms && bPos < poly.terms) 
    {
        if (termArray[aPos].exp == poly.termArray[bPos].exp) 
        {
            float t = termArray[aPos].coef + poly.termArray[bPos].coef;
            if (fabs(t) > 1e-6)
                result.NewTerm(t, termArray[aPos].exp);
            aPos++;
            bPos++;
        }
        else if (termArray[aPos].exp > poly.termArray[bPos].exp) 
        {
            result.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
        else 
        {
            result.NewTerm(poly.termArray[bPos].coef, poly.termArray[bPos].exp);
            bPos++;
        }
    }

    for (; aPos < terms; aPos++)
        result.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    for (; bPos < poly.terms; bPos++)
        result.NewTerm(poly.termArray[bPos].coef, poly.termArray[bPos].exp);
    
    return result;
}

// Replace Sub() with operator-
Polynomial Polynomial::operator-(const Polynomial& poly) const 
{
    // Create a copy of poly and multiply each term by -1.
    Polynomial negPoly(poly);

    for (int i = 0; i < negPoly.terms; i++) 
    {
        negPoly.termArray[i].coef = -negPoly.termArray[i].coef;
    }

    return (*this) + negPoly;
}

// Replace Mult() with operator*
Polynomial Polynomial::operator*(const Polynomial& poly) const 
{
    Polynomial result;

    for (int i = 0; i < terms; i++) 
    {
        Polynomial temp;
        for (int j = 0; j < poly.terms; j++) 
        {
            temp.NewTerm(termArray[i].coef * poly.termArray[j].coef,
                         termArray[i].exp + poly.termArray[j].exp);
        }
        result = result + temp;
    }

    return result;
}

// Overload operator* for multiplying polynomial by a constant.
Polynomial Polynomial::operator*(float constant) const 
{
    Polynomial result(*this);  // copy current polynomial

    for (int i = 0; i < result.terms; i++) 
    {
        result.termArray[i].coef *= constant;
    }

    return result;
}

// operator== : 檢查兩個多項式是否相等
bool Polynomial::operator==(const Polynomial &poly) const 
{
    if (terms != poly.terms)
        return false;
    
    for (int i = 0; i < terms; i++) 
    {
        if (termArray[i].exp != poly.termArray[i].exp ||
            fabs(termArray[i].coef - poly.termArray[i].coef) > 1e-6)
            return false;
    }
    return true;
}

// Overload operator!= using operator==
bool Polynomial::operator!=(const Polynomial& poly) const {
    return !(*this == poly);
}

// operator= : 深拷貝賦值運算子
Polynomial& Polynomial::operator=(const Polynomial &poly) 
{
    if (this != &poly) 
    {
        free(termArray);  // 釋放原有記憶體
        capacity = poly.capacity;
        terms = poly.terms;
        termArray = (Term*)calloc(capacity, sizeof(Term)); // 重新分配記憶體
        for (int i = 0; i < terms; i++) 
        {
            termArray[i] = poly.termArray[i];  // 複製每一項
        }
    }
    return *this;
}

//===============================
// input/output operators
//===============================

// operator>> : 輸入運算子，從符合LaTeX語法的字串讀取多項式
// 輸入格式範例: "114x^{514}+4x^3+5x^2+7.25"
istream& operator>>(istream& in, Polynomial& poly) 
{
    // 從輸入流中讀取整行字串
    string line;
    getline(in, line);
    
    // 移除字串中所有空白
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    
    // 重新初始化多項式（釋放舊有項目）
    if (poly.termArray != nullptr) 
    {
        free(poly.termArray);
    }
    poly.capacity = 1;
    poly.terms = 0;
    poly.termArray = (Term*)calloc(poly.capacity, sizeof(Term));
    
    // 為了方便解析，若字串開頭不是 '+' 或 '-'，則補上 '+'
    if (!line.empty() && line[0] != '+' && line[0] != '-')
        line = "+" + line;
    
    size_t pos = 0;
    // 利用 '+' 作分隔符解析各個項目

    while (pos < line.size()) 
    {
        size_t nextPos = line.find('+', pos + 1);
        string termStr;

        if (nextPos == string::npos) 
        {
            termStr = line.substr(pos);
            pos = line.size();
        } else 
        {
            termStr = line.substr(pos, nextPos - pos);
            pos = nextPos;
        }
        if (termStr.empty())
            continue;

        // 每個項目必定以 '+' 或 '-' 開頭
        char sign = termStr[0];
        termStr = termStr.substr(1); // 移除符號
        float coef = 1.0f;  // 預設係數
        int exp = 0;        // 預設指數
        size_t xPos = termStr.find('x');

        if (xPos != string::npos) 
        {
            // 若在 'x' 前有係數數字則解析
            if (xPos > 0)
                coef = stof(termStr.substr(0, xPos));
            else
                coef = 1.0f;
            // 檢查 'x' 後是否有 '^' 表示指數
            size_t caretPos = termStr.find('^', xPos);
            if (caretPos != string::npos) 
            {
                string expStr;
                
                if (termStr[caretPos+1] == '{') // 如果 '^' 後以 '{' 開始，則取花括號中的內容
                {
                    size_t endBrace = termStr.find('}', caretPos+2);
                    expStr = termStr.substr(caretPos+2, endBrace - (caretPos+2));
                } else 
                {
                    expStr = termStr.substr(caretPos+1);
                }
                exp = stoi(expStr);
            } 
            else 
            {
                exp = 1;    // 無 '^' 表示指數為 1
            }
        } 
        else 
        {
            coef = stof(termStr);   // 無 'x' 表示為常數項
            exp = 0;
        }
        if (sign == '-') 
            coef = -coef;      // 根據符號調整係數
        
        poly.NewTerm(coef, exp);    // 新增解析後的項目到多項式中
    }
    return in;
}

//-------------------------------------------------
// operator<< : 輸出運算子，將多項式以LaTeX語法格式輸出
// 格式：
//   - 若項目的指數為 0，僅輸出係數；
//   - 若指數為 1，輸出 "係數x"；
//   - 若指數大於 1，輸出 "係數x^{指數}"；
// 各項間以 " + " 或 " - " 連接
//-------------------------------------------------
ostream& operator<<(ostream& out, const Polynomial& poly) 
{
    // 若多項式為零則直接輸出 "0"
    if (poly.terms == 0 || (poly.terms == 1 && fabs(poly.termArray[0].get_coef()) < 1e-6)) 
    {
        out << "0";
        return out;
    }
    
    // 將所有項目複製到 vector 並依指數由大到小排序
    vector<Term> termsVec(poly.termArray, poly.termArray + poly.terms);
    sort(termsVec.begin(), termsVec.end(), [](const Term &a, const Term &b) 
    {
        return a.get_exp() > b.get_exp();
    });
    
    bool firstTerm = true;
    for (const auto &term : termsVec) 
    {
        if (fabs(term.get_coef()) < 1e-6)
            continue;
        
        string signStr;
        if (firstTerm) 
        {
            signStr = (term.get_coef() < 0) ? "-" : "";
            firstTerm = false;
        } 
        else 
        {
            signStr = (term.get_coef() < 0) ? " - " : " + ";
        }
        
        float absCoef = fabs(term.get_coef());
        ostringstream oss;

        if (fabs(absCoef - round(absCoef)) < 1e-6) // 判斷若係數接近整數則輸出整數格式，否則輸出預設格式
        {
            oss << (int)round(absCoef);
        } 
        else 
        {
            oss << absCoef;
        }

        string coefStr = oss.str();
        string termStr;
        if (term.get_exp() == 0) 
        {
            termStr = coefStr;
        } 
        else if (term.get_exp() == 1) 
        {
            termStr = (fabs(absCoef - 1.0f) < 1e-6 ? "x" : coefStr + "x");  // 若係數為 1，則僅輸出 "x"
        } 
        else 
        {
            termStr = (fabs(absCoef - 1.0f) < 1e-6 ? 
                "x^{" + to_string(term.get_exp()) + "}" : 
                coefStr + "x^{" + to_string(term.get_exp()) + "}");
        }
        
        out << signStr << termStr;
    }
    return out;
}
