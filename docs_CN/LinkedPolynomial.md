# `LinkedPolynomial.hpp` 文件說明

## 概觀

`LinkedPolynomial.hpp` 標頭文件定義了兩個類別：`LinkedTerm` 和 `LinkedPolynomial`。`LinkedTerm` 類別表示多項式中的單一項，而 `LinkedPolynomial` 類別則表示一個多項式，該多項式由 `LinkedTerm` 節點組成的雙向鏈結串列組成。此實作允許有效操作多項式，包括加法、減法、乘法、微分和評估。

## 類別：`LinkedTerm`

### 說明
`LinkedTerm` 類別表示多項式中的單一項，包含係數和指數。

### 建構子

#### `LinkedTerm()`
- **說明**：預設建構子。初始化一個係數為 0，指數為 0 的項。
- **使用範例**：
  ```cpp
  LinkedTerm term;
  ```

#### `LinkedTerm(double c, int e)`
- **說明**：建構子。初始化一個給定係數和指數的項。
- **參數**：
  - `c`: 該項的係數。
  - `e`: 該項的指數。
- **使用範例**：
  ```cpp
  LinkedTerm term(3.5, 2);  // 表示項 3.5x^2
  ```

### 取得與設定方法

#### `double get_coef() const`
- **說明**：返回該項的係數。
- **回傳值**：係數（`double` 型別）。
- **使用範例**：
  ```cpp
  LinkedTerm term(3.5, 2);
  double coef = term.get_coef();  // coef 為 3.5
  ```

#### `int get_exp() const`
- **說明**：返回該項的指數。
- **回傳值**：指數（`int` 型別）。
- **使用範例**：
  ```cpp
  LinkedTerm term(3.5, 2);
  int exp = term.get_exp();  // exp 為 2
  ```

#### `double& get_coef_ref()`
- **說明**：返回該項的係數的引用，允許修改。
- **回傳值**：係數的引用。
- **使用範例**：
  ```cpp
  LinkedTerm term(3.5, 2);
  term.get_coef_ref() = 4.0;  // 該項現在為 4.0x^2
  ```

#### `void set_coef(double new_coef)`
- **說明**：設定該項的係數。
- **參數**：
  - `new_coef`: 新的係數值。
- **使用範例**：
  ```cpp
  LinkedTerm term(3.5, 2);
  term.set_coef(4.0);  // 該項現在為 4.0x^2
  ```

### 運算子重載

#### `bool operator==(const LinkedTerm& other) const`
- **說明**：相等運算子。檢查兩個項是否相等。
- **參數**：
  - `other`: 要比較的 `LinkedTerm`。
- **回傳值**：若兩項相等，返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  LinkedTerm term1(3.5, 2);
  LinkedTerm term2(3.5, 2);
  bool equal = (term1 == term2);  // equal 為 true
  ```

## 類別：`LinkedPolynomial`

### 說明
`LinkedPolynomial` 類別表示一個多項式，該多項式由 `LinkedTerm` 節點組成的雙向鏈結串列構成。此類別提供多項式操作的方法，包括加法、減法、乘法、微分和評估。

### 建構子與解構子

#### `LinkedPolynomial()`
- **說明**：預設建構子。初始化一個空的多項式。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  ```

#### `LinkedPolynomial(const LinkedPolynomial& other)`
- **說明**：複製建構子。通過複製另一個多項式的元素來初始化新多項式。
- **參數**：
  - `other`: 要複製的 `LinkedPolynomial` 物件。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2(poly1);
  ```

#### `~LinkedPolynomial()`
- **說明**：解構子。刪除多項式的所有節點。
- **使用範例**：當物件超出作用範圍時自動呼叫。

### 屬性

#### `int LeadExp()`
- **說明**：返回多項式中的最高指數。
- **回傳值**：最高指數（`int` 型別）。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  poly.InsertLinkedTerm(2.0, 3);
  int leadExp = poly.LeadExp();  // leadExp 為 3
  ```

#### `double Coef(int e)`
- **說明**：返回給定指數的項的係數。
- **參數**：
  - `e`: 該項的指數。
- **回傳值**：該項的係數（`double` 型別）。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  double coef = poly.Coef(2);  // coef 為 3.5
  ```

#### `DLIterator<LinkedTerm> begin() const`
- **說明**：返回指向多項式第一項的迭代器。
- **回傳值**：`DLIterator<LinkedTerm>` 物件。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  DLIterator<LinkedTerm> it = poly.begin();
  ```

#### `DLIterator<LinkedTerm> end() const`
- **說明**：返回指向多項式結尾（`nullptr`）的迭代器。
- **回傳值**：`DLIterator<LinkedTerm>` 物件。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  DLIterator<LinkedTerm> it = poly.end();
  ```

### 操作

#### `LinkedPolynomial operator+(const LinkedPolynomial& other) const`
- **說明**：將兩個多項式相加。
- **參數**：
  - `other`: 要相加的 `LinkedPolynomial`。
- **回傳值**：返回表示兩多項式和的 `LinkedPolynomial`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  LinkedPolynomial sum = poly1 + poly2;
  ```

#### `LinkedPolynomial operator-(const LinkedPolynomial& other) const`
- **說明**：將另一個多項式從當前多項式中減去。
- **參數**：
  - `other`: 要減去的 `LinkedPolynomial`。
- **回傳值**：返回表示兩多項式差的 `LinkedPolynomial`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  LinkedPolynomial diff = poly1 - poly2;
  ```

#### `LinkedPolynomial operator*(float constant) const`
- **說明**：將多項式乘以一個常數。
- **參數**：
  - `constant`: 要乘的常數。
- **回傳值**：返回表示乘積的 `LinkedPolynomial`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial product = poly * 2.0;
  ```

#### `LinkedPolynomial operator*(const LinkedPolynomial& other) const`
- **說明**：將兩個多項式相乘。
- **參數**：
  - `other`: 要相乘的 `LinkedPolynomial`。
- **回傳值**：返回表示兩多項式乘積的 `LinkedPolynomial`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  LinkedPolynomial product = poly1 * poly2;
  ```

#### `LinkedPolynomial Differentiate() const`
- **說明**：對多項式進行微分。
- **回傳值**：返回表示導數的 `LinkedPolynomial`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial derivative = poly.Differentiate();
  ```

#### `double Evaluate(double x) const`
- **說明**：在給定的 `x` 值處評估多項式。
- **參數**：
  - `x`: 要評估的 `x` 值。
- **回傳值**：評估結果（`double` 型別）。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  double result = poly.Evaluate(2.0);  // 評估 3.5 * (2.0)^2
  ```

### 其他函式

#### `void Clear()`
- **說明**：清除多項式，刪除所有項。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  poly.Clear();  // 多項式現在為空
  ```

#### `void CopyFrom(const LinkedPolynomial& other)`
- **說明**：將另一個多項式的內容複製到當前多項式。
- **參數**：
  - `other`: 要複製的 `LinkedPolynomial`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.CopyFrom(poly1);
 

 ```

#### `void InsertLinkedTerm(double coef, int exp)`
- **說明**：將新項插入多項式。
- **參數**：
  - `coef`: 該項的係數。
  - `exp`: 該項的指數。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);  // 插入項 3.5x^2
  ```

#### `void InsertLinkedTerm(const std::string& term)`
- **說明**：使用 LaTeX 樣式的輸入字串插入新項。
- **參數**：
  - `term`: 代表該項的字串（例如："3.5x^2"）。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm("3.5x^2");  // 插入項 3.5x^2
  ```

#### `void DeleteLinkedTerm(int exp)`
- **說明**：刪除具有給定指數的項。
- **參數**：
  - `exp`: 要刪除的項的指數。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  poly.DeleteLinkedTerm(2);  // 刪除項 3.5x^2
  ```

### 運算子重載

#### `LinkedPolynomial& operator=(const LinkedPolynomial& other)`
- **說明**：賦值運算子。將另一個多項式的內容賦值給當前多項式。
- **參數**：
  - `other`: 要賦值的 `LinkedPolynomial`。
- **回傳值**：當前多項式的參考。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2 = poly1;  // poly2 現在包含項 3.5x^2
  ```

#### `bool operator==(const LinkedPolynomial& other) const`
- **說明**：相等運算子。檢查兩個多項式是否相等。
- **參數**：
  - `other`: 要比較的 `LinkedPolynomial`。
- **回傳值**：若多項式相等，返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(3.5, 2);
  bool equal = (poly1 == poly2);  // equal 為 true
  ```

#### `bool operator!=(const LinkedPolynomial& other) const`
- **說明**：不相等運算子。檢查兩個多項式是否不相等。
- **參數**：
  - `other`: 要比較的 `LinkedPolynomial`。
- **回傳值**：若多項式不相等，返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly1;
  poly1.InsertLinkedTerm(3.5, 2);
  LinkedPolynomial poly2;
  poly2.InsertLinkedTerm(2.0, 3);
  bool notEqual = (poly1 != poly2);  // notEqual 為 true
  ```

#### `friend std::ostream& operator<<(std::ostream& out, const LinkedPolynomial& poly)`
- **說明**：重載 `<<` 運算子，用於以 LaTeX 樣式輸出多項式。
- **參數**：
  - `out`: 輸出流。
  - `poly`: 要輸出的 `LinkedPolynomial`。
- **回傳值**：輸出流。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  poly.InsertLinkedTerm(3.5, 2);
  std::cout << poly;  // 以 LaTeX 樣式輸出多項式
  ```

#### `friend std::istream& operator>>(std::istream &in, LinkedPolynomial &poly)`
- **說明**：重載 `>>` 運算子，用於讀取 LaTeX 樣式的多項式。
- **參數**：
  - `in`: 輸入流。
  - `poly`: 要讀取的 `LinkedPolynomial`。
- **回傳值**：輸入流。
- **使用範例**：
  ```cpp
  LinkedPolynomial poly;
  std::cin >> poly;  // 讀取 LaTeX 樣式的多項式
  ```

## 範例使用

```cpp
#include "LinkedPolynomial.hpp"
#include <iostream>

int main() {
    LinkedPolynomial poly1;
    poly1.InsertLinkedTerm(3.5, 2);
    poly1.InsertLinkedTerm(2.0, 3);

    LinkedPolynomial poly2;
    poly2.InsertLinkedTerm(1.5, 2);
    poly2.InsertLinkedTerm(4.0, 1);

    LinkedPolynomial sum = poly1 + poly2;
    std::cout << "Sum: " << sum << std::endl;

    LinkedPolynomial product = poly1 * poly2;
    std::cout << "Product: " << product << std::endl;

    LinkedPolynomial derivative = poly1.Differentiate();
    std::cout << "Derivative of poly1: " << derivative << std::endl;

    double result = poly1.Evaluate(2.0);
    std::cout << "Evaluation of poly1 at x=2.0: " << result << std::endl;

    return 0;
}
```

## 可能的錯誤與邊界情形

1. **空多項式**：對空多項式執行 `LeadExp()` 或 `Coef(int e)` 等操作可能會導致未定義行為。請確保在執行這些操作之前，多項式非空。
2. **無效的指數**：在插入或刪除項時，確保指數有效（非負數），以避免意外行為。
3. **記憶體管理**：在處理大型多項式時，請確保適當的記憶體管理，以避免記憶體洩漏。

## 相依性

- `Node.hpp`: 定義基本節點結構。
- `DoubleNode.hpp`: 定義雙向鏈結節點結構。
- `ChainIterator.hpp`: 提供鏈結串列的迭代器功能。
- `DLIterator.hpp`: 提供雙向鏈結串列的迭代器功能。

確保這些文件已正確匯入並配置，以便使用 `LinkedPolynomial.hpp`。
