## Bag 資料結構使用指南

### 1. 簡介
`Bag` 是一個容器類別，它允許儲存各種不同型別的物件，包括：
- `int`, `char`, `float`, `bool`, `double`, `std::string`
- `GeneralArray`
- `Polynomial`
- `SparseMatrix`
- `String`

此容器支援重複的元素，並提供基本的插入、刪除、搜尋等操作。

---

### 2. 包含的功能
| 函數 | 描述 |
|------|------|
| `Bag(int c)` | 建構函式，建立初始容量為 `c` 的 `Bag` |
| `~Bag()` | 解構函式，釋放記憶體 |
| `int Size() const` | 返回 `Bag` 的容量 |
| `bool IsEmpty() const` | 檢查 `Bag` 是否為空 |
| `int Element() const` | 返回 `Bag` 目前的元素數量 |
| `void Push(const MORTISInvariant& x)` | 將元素 `x` 插入 `Bag` |
| `void Pop()` | 刪除 `Bag` 最後插入的元素 |
| `template<class U> int Multiplicity(const U& x) const` | 返回 `x` 在 `Bag` 出現的次數 |
| `template<class U> bool isBelong(const U& x) const` | 檢查 `x` 是否在 `Bag` 內 |

---

### 3. 使用範例
```cpp
#include <iostream>
#include "Bag.hpp"
#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using namespace std;

int main() {
    cout << "=== Bag Test Program ===" << endl;
    
    // 創建一個 Bag，初始容量為 5
    Bag b(5);

    // 創建一些不同類型的元素
    SparseMatrix A(4, 5, 3);
    double pi = 3.14159;

    // 測試初始狀態
    cout << "Initial Bag:" << endl;
    cout << "  IsEmpty? " << (b.IsEmpty() ? "Yes" : "No") << endl;
    cout << "  Number of elements: " << b.Element() << endl;
    cout << "  Capacity: " << b.Size() << endl;

    // 插入不同型別的元素
    b.Push(10);
    b.Push(A);
    b.Push('c');
    b.Push(pi);
    b.Push("Hello");

    cout << "Bag after inserting elements:" << endl;
    cout << "  Number of elements: " << b.Element() << endl;

    // 測試 Multiplicity（計算元素出現次數）
    cout << "Multiplicity of 10: " << b.Multiplicity(10) << endl;
    cout << "Multiplicity of 'c': " << b.Multiplicity('c') << endl;

    // 測試 isBelong（元素是否存在）
    cout << "Does 'Hello' exist? " << (b.isBelong(std::string("Hello")) ? "Yes" : "No") << endl;
    cout << "Does 3.14159 exist? " << (b.isBelong(3.14159) ? "Yes" : "No") << endl;

    // 測試 Pop 操作
    b.Pop();
    cout << "Bag after popping an element:" << endl;
    cout << "  Number of elements: " << b.Element() << endl;

    return 0;
}
```

---

### 4. 編譯方式
確保 C++17 以上的標準，並使用 g++ 編譯：
```sh
g++ -std=c++17 Bag.cpp Bag-test.cpp ../../MORTIS.hpp -o test
```
若有額外的類別 (`GeneralArray`, `Polynomial`, `SparseMatrix`, `String`)，請確保它們已正確編譯並包含在編譯指令中。

---

### 5. 可能的錯誤與解法
| 錯誤訊息 | 可能原因 | 解決方案 |
|----------|----------|----------|
| `undefined reference to GeneralArray` | 缺少 `GeneralArray.cpp` 於編譯 | 在 g++ 命令中加入 `../../array/GeneralArray/GeneralArray.cpp` |
| `MORTISInvariant does not name a type` | `MORTIS.hpp` 沒有被正確包含 | 確保 `#include "../../MORTIS.hpp"` 在 `Bag.hpp` 內 |
| `Segmentation fault` | 使用未初始化的 `Bag` | 確保 `Bag` 建構時指定正確的初始容量 |
