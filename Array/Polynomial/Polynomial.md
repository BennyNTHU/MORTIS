# Polynomial Data Structure Documentation

此文件詳細介紹了 Polynomial 資料結構的使用方法，並提供完整的 API 說明、使用範例與編譯指引。Polynomial 類別用於表示多項式，每一項由一個係數（可為整數或浮點數）和一個整數次方組成。輸入與輸出皆使用 LaTeX 語法格式，且在輸出時會根據係數的數值特性決定是否以整數形式顯示（例如，若係數實際上為整數則不會輸出小數點）。

---

## 目錄

- [Polynomial Data Structure Documentation](#polynomial-data-structure-documentation)
  - [目錄](#目錄)
  - [概述](#概述)
  - [主要特性](#主要特性)
  - [API 說明](#api-說明)
    - [建構子與解構子](#建構子與解構子)
    - [成員函式](#成員函式)
    - [運算子重載](#運算子重載)
  - [使用範例](#使用範例)
  - [編譯與執行](#編譯與執行)
  - [注意事項](#注意事項)

---

## 概述

Polynomial 類別提供了一個靈活的多項式資料結構，允許使用者：
- 以 LaTeX 語法格式從字串輸入多項式（例如：`3x^{3}+2x^{2}+0.5x+1`）。
- 以 LaTeX 語法格式輸出多項式，並自動判斷係數顯示格式：
  - 若係數數值為整數（在允許誤差內），則以整數顯示；
  - 否則，則保留浮點數原始精度（不補零）。
- 執行多項式的加法、減法、乘法與評估操作。
- 支持深拷貝、賦值與相等比較。

---

## 主要特性

- **靈活的係數格式：** 係數既可以是整數，也可以是浮點數。輸出時，整數係數以整數形式呈現，浮點數則保留輸入時的精度。
- **LaTeX 語法輸入與輸出：** 輸入格式如 `3x^{3}+2x^{2}+0.5x+1`，輸出格式也相似，方便用戶閱讀與排版。
- **基本運算功能：** 支援加、減、乘以及評估多項式值。除法部分目前保留註解，不作處理。
- **動態儲存：** 內部使用動態陣列存放各項，當項目數超過當前容量時自動擴充。

---

## API 說明

### 建構子與解構子

- **`Polynomial()`**  
  建構零多項式 *p(x) = 0*。  
  _用法：_
  ```cpp
  Polynomial P; // P(x) = 0
  ```

- **`Polynomial(Term* t, int degree)`**  
  依據給定的 Term 陣列和項數建立多項式。傳入的陣列會在複製後被釋放。  
  _注意：_ 此建構子通常由內部使用，不常直接調用。

- **`Polynomial(const Polynomial &poly)`**  
  複製建構子，對多項式進行深拷貝。

- **`~Polynomial()`**  
  解構子，釋放內部動態分配的記憶體。

### 成員函式

- **`float Coef(int e)`**  
  回傳次方為 `e` 的項之係數；若該項不存在，回傳 0。  
  _用法：_
  ```cpp
  float c = P.Coef(2);  // 取得 x^2 項的係數
  ```

- **`int LeadExp()`**  
  回傳多項式中最高的次方（即多項式的次數）。  
  _用法：_
  ```cpp
  int degree = P.LeadExp();
  ```

- **`float Eval(float x)`**  
  評估多項式在指定 `x` 值處的結果。  
  _用法：_
  ```cpp
  float result = P.Eval(2.0f);
  ```

- **`void NewTerm(const float theCoeff, const int theExp)`**  
  新增一項，係數為 `theCoeff`，次方為 `theExp`。當內部陣列容量不足時自動擴充。  
  _用法：_
  ```cpp
  P.NewTerm(4, 4);  // 新增項 4x^4
  ```

- **`Polynomial Add(Polynomial poly)`**  
  回傳一個新多項式，其為本多項式與 `poly` 的和。  
  _用法：_
  ```cpp
  Polynomial Sum = P.Add(Q);
  ```

- **`Polynomial Sub(Polynomial poly)`**  
  回傳一個新多項式，其為本多項式減去 `poly` 的結果。  
  _用法：_
  ```cpp
  Polynomial Diff = P.Sub(Q);
  ```

- **`Polynomial Mult(Polynomial poly)`**  
  回傳一個新多項式，其為本多項式與 `poly` 的乘積。  
  _用法：_
  ```cpp
  Polynomial Prod = P.Mult(Q);
  ```

- **除法部分**  
  目前 `Quotient` 與 `Remainder` 函式均被註解，因為除法結果可能受到電腦計算結構的影響，如需使用請注意相關數值問題。

### 運算子重載

- **`istream& operator>>(istream& in, Polynomial& poly)`**  
  從輸入流讀取符合 LaTeX 語法格式的多項式字串。輸入時，字串中應無空格，例如：  
  `3x^{3}+2x^{2}+0.5x+1`  
  _用法：_
  ```cpp
  cin >> P;
  ```

- **`ostream& operator<<(ostream& out, const Polynomial& poly)`**  
  輸出多項式，格式為 LaTeX 語法，且係數會根據數值自動選擇整數或浮點數格式（保留原始精度）。  
  _用法：_
  ```cpp
  cout << P;
  ```

- **`Polynomial& operator=(const Polynomial &)`**  
  賦值運算子，執行深拷貝。
  
- **`bool operator==(const Polynomial &) const`**  
  檢查兩個多項式是否相等。

---

## 使用範例

以下是一個完整的範例，示範如何使用 Polynomial 類別進行各種操作：

```cpp
#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    // 建立多項式 P，預設為 0
    Polynomial P;
    cout << "Default polynomial P: " << P << endl;

    // 從輸入讀取多項式 P (請輸入類似 3x^{3}+2x^{2}+0.5x+1 的格式)
    cout << "\nEnter polynomial P in LaTeX format (e.g., 3x^{3}+2x^{2}+0.5x+1):" << endl;
    cin >> P;
    cout << "Polynomial P: " << P << endl;

    // 取得 P 中次方為 2 的項之係數
    cout << "\nCoefficient of x^2 in P: " << P.Coef(2) << endl;
    // 取得 P 的最高次方
    cout << "Highest exponent in P: " << P.LeadExp() << endl;
    // 計算 P 在 x = 2 處的值
    cout << "P evaluated at x = 2: " << P.Eval(2.0f) << endl;

    // 新增一項 4x^4 至 P
    cout << "\nAdding new term: 4x^4" << endl;
    P.NewTerm(4, 4);
    cout << "Updated polynomial P: " << P << endl;

    // 測試複製與賦值運算子
    Polynomial Q = P;  // 使用複製建構子
    cout << "\nCopied polynomial Q (via copy constructor): " << Q << endl;
    Polynomial R;
    R = P;           // 使用賦值運算子
    cout << "Assigned polynomial R (via operator=): " << R << endl;

    // 測試相等運算子
    if (P == Q)
        cout << "P equals Q" << endl;
    else
        cout << "P does not equal Q" << endl;

    // 輸入另一個多項式 Q (格式例如：2x^{2}+1)
    cout << "\nEnter another polynomial Q in LaTeX format (e.g., 2x^{2}+1):" << endl;
    cin >> Q;
    cout << "Polynomial Q: " << Q << endl;

    // 測試多項式加法與減法
    Polynomial Sum = P.Add(Q);
    cout << "P + Q: " << Sum << endl;
    Polynomial Diff = P.Sub(Q);
    cout << "P - Q: " << Diff << endl;

    // 測試多項式乘法
    Polynomial Prod = P.Mult(Q);
    cout << "P * Q: " << Prod << endl;

    // 除法部分目前已註解
    // if (Q.LeadExp() > 0 || Q.Coef(0) != 0) {
    //     Polynomial Quot = P.Quotient(Q);
    //     Polynomial Rem = P.Remainder(Q);
    //     cout << "P / Q: " << Quot << endl;
    //     cout << "P % Q: " << Rem << endl;
    // } else {
    //     cout << "Cannot perform division: Q is the zero polynomial." << endl;
    // }

    return 0;
}
```

---

## 編譯與執行

假設您將以下檔案置於同一目錄：
- `Polynomial.h`
- `Polynomial.cpp`
- `Polynomial-test.cpp`

請使用以下命令編譯並產生可執行檔（以 g++ 為例）：

```bash
g++ -std=c++11 Polynomial.cpp Polynomial-test.cpp -o polyTest
```

然後執行產生的執行檔：

- **Linux/macOS：**
  ```bash
  ./polyTest
  ```
- **Windows：**
  ```bash
  polyTest.exe
  ```

在執行時，根據提示輸入符合 LaTeX 語法的多項式字串，例如：
```
Enter polynomial P in LaTeX format (e.g., 3x^{3}+2x^{2}+0.5x+1):
3x^{3}+2x^{2}+0.5x+1
```

程式將顯示多項式的各項運算結果，並根據係數的數值特性適當格式化顯示。

---

## 注意事項

- **除法部分：** 由於除法（Quotient 與 Remainder）可能會受到計算機精度影響，該部分目前保留註解，未做處理。
- **係數格式：** 當輸入的係數為整數時，輸出會以整數顯示；若有小數則保持原有精度，不補零。這可確保輸出與輸入一致。
- **輸入格式：** 請確保輸入的多項式字串符合 LaTeX 語法，例如：`3x^{3}+2x^{2}+0.5x+1`。系統會自動移除空白字元並解析字串。

---

這就是 Polynomial 資料結構的詳細使用文檔。如有任何疑問或建議，請隨時聯絡我們！