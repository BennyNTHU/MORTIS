# `Polynomial` 技術文件

## 概觀

`Polynomial.hpp` 定義了一個 `Polynomial` 類別，用來表示具有整數指數和浮點數係數的多項式。此類別支援常見的多項式運算，如加法、減法、乘法和微分。它還提供函式來評估多項式、檢索係數以及處理項目。

---

## 主要元件

### `Term` 結構

`Term` 代表多項式中的單一項，包含以下成員：
- **`coef`**：項的係數（`float` 型別）。
- **`exp`**：項的指數（`int` 型別）。

`Term` 結構包括以下方法：
- **`get_coef()`**：返回項的係數。
- **`get_exp()`**：返回項的指數。

```cpp
struct Term
{
    float coef;
    int exp;

    float get_coef() const { return coef; }
    int get_exp() const { return exp; }
};
```

### `Polynomial` 類別

`Polynomial` 類別代表多項式，作為 `Term` 物件的集合。它支援多項式運算，並提供多個建構子、成員函式和運算子重載來執行多項式運算。

#### 成員變數
- **`terms`**：多項式中非零項的數量。
- **`capacity`**：項陣列的容量。
- **`termArray`**：表示多項式項目的動態陣列。

#### 建構子與解構子
- **`Polynomial()`**：預設建構子，初始化一個空的多項式。
- **`Polynomial(Term* t, int degree)`**：建構子，根據給定的項陣列和多項式的階數初始化多項式。
- **`Polynomial(const Polynomial& poly)`**：複製建構子，建立一個多項式的深層副本。
- **`~Polynomial()`**：解構子，釋放為項分配的記憶體。

#### 成員函式

- **`Coef(int e)`**：返回具有指數 `e` 的項的係數。如果該指數的項不存在，則返回 `0.0f`。
  
  範例：
  ```cpp
  float coef = poly.Coef(2);  // 獲取 x^2 項的係數
  ```

- **`LeadExp()`**：返回領先項（最高指數）的指數。
  
  範例：
  ```cpp
  int leadExp = poly.LeadExp();  // 獲取領先指數
  ```

- **`Eval(float x)`**：在給定的 `x` 值處評估多項式，使用多項式的項來計算值。
  
  範例：
  ```cpp
  float result = poly.Eval(2.0f);  // 在 x = 2.0 時評估多項式
  ```

- **`NewTerm(const float theCoeff, const int theExp)`**：向多項式中添加具有給定係數 `theCoeff` 和指數 `theExp` 的新項。
  
  範例：
  ```cpp
  poly.NewTerm(3.0f, 2);  // 向多項式中添加 3x^2
  ```

- **`NewTerm(const std::string& latexTerm)`**：從 LaTeX 樣式的字串表示添加新項。

  範例：
  ```cpp
  poly.NewTerm("3x^2");  // 使用 LaTeX 表示法添加 3x^2
  ```

- **`Differentiate()`**：返回當前多項式的導數，作為一個新多項式。

  範例：
  ```cpp
  Polynomial derivative = poly.Differentiate();  // 微分多項式
  ```

#### 運算子重載

- **`operator+(const Polynomial& poly)`**：將兩個多項式相加並返回結果。
  
  範例：
  ```cpp
  Polynomial sum = poly1 + poly2;  // 加法兩個多項式
  ```

- **`operator-(const Polynomial& poly)`**：將一個多項式從另一個多項式中減去並返回結果。
  
  範例：
  ```cpp
  Polynomial difference = poly1 - poly2;  // 減法兩個多項式
  ```

- **`operator*(const Polynomial& poly)`**：將兩個多項式相乘並返回結果。
  
  範例：
  ```cpp
  Polynomial product = poly1 * poly2;  // 乘法兩個多項式
  ```

- **`operator*(float constant)`**：將多項式乘以常數並返回結果。
  
  範例：
  ```cpp
  Polynomial scaled = poly * 3.0f;  // 將多項式乘以 3
  ```

- **`operator==(const Polynomial &poly)`**：檢查兩個多項式是否相等（即項和指數相同）。
  
  範例：
  ```cpp
  bool isEqual = (poly1 == poly2);  // 檢查兩個多項式是否相等
  ```

- **`operator!=(const Polynomial &poly)`**：檢查兩個多項式是否不相等。
  
  範例：
  ```cpp
  bool isNotEqual = (poly1 != poly2);  // 檢查兩個多項式是否不相等
  ```

- **`operator=(const Polynomial &poly)`**：賦值運算子，用來複製另一個多項式的內容。
  
  範例：
  ```cpp
  poly1 = poly2;  // 複製 poly2 的內容到 poly1
  ```

#### 輸入/輸出運算子

- **`operator<<(std::ostream& out, const Polynomial& poly)`**：以 LaTeX 形式輸出多項式。
  
  範例：
  ```cpp
  std::cout << poly;  // 以 LaTeX 格式輸出多項式
  ```

- **`operator>>(std::istream& in, Polynomial& poly)`**：從輸入流中讀取 LaTeX 形式的多項式。
  
  範例：
  ```cpp
  std::cin >> poly;  // 讀取 LaTeX 格式的多項式
  ```

---

## 範例使用

```cpp
#include "Polynomial.hpp"

int main() {
    // 使用項來創建多項式
    Term terms[] = {{3.0f, 2}, {2.0f, 1}, {1.0f, 0}};
    Polynomial poly(terms, 2);  // 多項式 3x^2 + 2x + 1

    // 添加新項
    poly.NewTerm(4.0f, 3);  // 添加 4x^3

    // 在 x = 2 處評估多項式
    float result = poly.Eval(2.0f);
    std::cout << "在 x=2 處評估的結果: " << result << std::endl;

    // 微分多項式
    Polynomial derivative = poly.Differentiate();
    std::cout << "導數: " << derivative << std::endl;

    // 輸出多項式
    std::cout << "多項式: " << poly << std::endl;

    // 加法兩個多項式
    Polynomial poly2(terms, 2);
    Polynomial sum = poly + poly2;
    std::cout << "兩個多項式的和: " << sum << std::endl;

    return 0;
}
```

---

## 可能的錯誤與邊界情形

1. **空多項式**：確保多項式運算能處理沒有項目的情況。
2. **無效 LaTeX 格式**：使用 LaTeX 字串時，確保字串格式正確並且有效，以便解析。
3. **指數衝突**：在加減多項式時，確保具有相同指數的項目被正確合併。

---

## 相依性

- **C++ 標準函式庫**：此類別使用了標準 C++ 函式庫，如 `<iostream>`。
