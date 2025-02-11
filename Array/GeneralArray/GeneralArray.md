下面是一份詳細的 Markdown 文檔，介紹了 GeneralArray 類中各個函式的用途、參數與使用範例：

---

# GeneralArray 類使用文檔

GeneralArray 類是一個支持多維陣列操作的模板類。它允許您創建一個任意維度的陣列，並提供下列操作：
- **儲存與讀取元素**  
- **初始化、反轉與排序**  
- **透過 initializer_list 進行賦值**  
- **輸入/輸出操作**

本文檔將詳細介紹各個成員函式的用途與使用方法，並附上相應的範例。

---

## 目錄

1. [構造函式與基礎操作](#構造函式與基礎操作)
2. [元素存取](#元素存取)
3. [陣列操作](#陣列操作)
    - [排序](#排序)
    - [反轉](#反轉)
    - [初始化](#初始化)
4. [賦值與複製](#賦值與複製)
5. [輸入與輸出](#輸入與輸出)
6. [使用範例](#使用範例)

---

## 構造函式與基礎操作

### 構造函式

```cpp
// GeneralArray(int j, const RangeList& list, T initValue = T());
```

- **用途**：用於創建一個多維陣列。
- **參數**：
  - `j`：維度的個數。例如，一維陣列傳入 1，二維陣列傳入 2。
  - `list`：一個 `vector<int>`，每個元素表示該維度的大小。例如，對於一個 1D 陣列，可傳入 `{5}` 表示 5 個元素；對於 2D 陣列，可傳入 `{3, 3}` 表示 3 行 3 列。
  - `initValue`：所有元素的初始值，預設為 T()。

### 析構函式

- **用途**：釋放動態分配的記憶體。

---

## 元素存取

### Store() 函式

```cpp
// void Store(const Index& idx, T x);
```

- **用途**：將指定索引處的元素更新為新值。
- **參數**：
  - `idx`：一個 `vector<int>`，代表多維索引。例如，一維陣列可以傳入 `{2}`；二維陣列傳入 `{1, 0}` 表示第 2 行第 1 列。
  - `x`：要儲存的新值。

### Retrieve() 函式

```cpp
// T Retrieve(const Index& idx) const;
```

- **用途**：讀取指定索引處的元素。
- **參數**：
  - `idx`：與 Store() 相同，多維索引。

---

## 陣列操作

### 排序

```cpp
// void sort(bool reverse = false, int sortDim = 1);
```

- **用途**：
  - 當陣列為一維時：對整個陣列進行排序。參數 `reverse` 為 `true` 時使用升序排序，為 `false` 時使用降序排序。
  - 當陣列為二維時：根據指定列（`sortDim` 表示第幾列，從 1 開始）對行進行排序。
- **參數**：
  - `reverse`：排序順序。預設為 `false`（降序排序），設為 `true` 表示升序排序。
  - `sortDim`：僅針對 2D 陣列有效，用於指定根據哪一列排序。

### 反轉

```cpp
// void reverse();
```

- **用途**：將陣列中的所有元素以扁平（linear）順序反轉。

### 初始化

```cpp
// void initialize();
```

- **用途**：將陣列中的所有元素重設為預設值 `T{}`（例如對數字類型重設為 0）。

### 長度

```cpp
// int length() const;
```

- **用途**：返回陣列中元素的總數。

---

## 賦值與複製

### 複製建構子

- **用途**：根據另一個 GeneralArray 進行深拷貝。

### 深拷貝賦值

```cpp
// GeneralArray<T>& operator=(const GeneralArray<T>& other);
```

- **用途**：將另一個 GeneralArray 的所有數據複製到當前對象。

### initializer_list 賦值

```cpp
// GeneralArray<T>& operator=(std::initializer_list<T> il);
```

- **用途**：允許透過花括號列表來賦值。例如：
  ```cpp
  arr = {1, 2, 3, 4, 5};
  ```
- **注意**：初始化列表的大小必須與陣列中元素數量一致，否則會拋出異常。

### Equality Operator

```cpp
// bool operator==(const GeneralArray<T>& other) const;
```

- **用途**：比較兩個 GeneralArray 是否在維度及元素上均相等。

---

## 輸入與輸出

### 輸出運算子 (operator<<)

- **用途**：將陣列的內容以易讀的格式輸出到輸出流（例如 `std::cout`）。
- **格式**：
  - 一維陣列：以 `[elem1, elem2, ...]` 格式輸出。
  - 二維陣列：以 `[[row1], [row2], ...]` 格式輸出。

### 輸入運算子 (operator>>)

- **用途**：從輸入流中讀取數據，並填充到陣列中。  
- **注意**：對於使用 `std::variant` 的型別，不支持輸入運算子，必須使用 `Store()` 來填充數據。

---

## 使用範例

以下提供幾個範例展示如何使用 GeneralArray 類：

### 範例 1：一維整數陣列

```cpp
#include <iostream>
#include <vector>
#include "GeneralArray.h"
using namespace std;

int main() {
    // 建立一個 1D 陣列，包含 5 個元素，初始值皆為 0
    vector<int> dims = {5};
    GeneralArray<int> arrInt(1, dims, 0);

    // 使用 Store() 設置各索引的值
    arrInt.Store({0}, 10);
    arrInt.Store({1}, 20);
    arrInt.Store({2}, 30);
    arrInt.Store({3}, 40);
    arrInt.Store({4}, 50);

    // 輸出陣列內容
    cout << "Initial int array: " << arrInt << endl;
    cout << "Element at index [2]: " << arrInt.Retrieve({2}) << endl;
    cout << "Length of int array: " << arrInt.length() << endl;

    // 反轉陣列
    arrInt.reverse();
    cout << "After reverse: " << arrInt << endl;

    // 初始化陣列（所有元素重設為 0）
    arrInt.initialize();
    cout << "After initialize: " << arrInt << endl;

    // 使用 initializer_list 賦值
    arrInt = {1, 2, 3, 4, 5};
    cout << "After initializer_list assignment: " << arrInt << endl;

    return 0;
}
```

### 範例 2：一維浮點數陣列與排序

```cpp
#include <iostream>
#include <vector>
#include "GeneralArray.h"
using namespace std;

int main() {
    vector<int> dims = {5};
    GeneralArray<double> arrDouble(1, dims, 0.0);

    // 設定數值
    arrDouble.Store({0}, 3.14);
    arrDouble.Store({1}, 2.71);
    arrDouble.Store({2}, 1.41);
    arrDouble.Store({3}, 0.577);
    arrDouble.Store({4}, 1.618);

    cout << "Initial double array: " << arrDouble << endl;

    // 升序排序
    arrDouble.sort(true);
    cout << "Sorted ascending: " << arrDouble << endl;

    // 降序排序
    arrDouble.sort(false);
    cout << "Sorted descending: " << arrDouble << endl;

    return 0;
}
```

### 範例 3：二維整數陣列與輸入操作

```cpp
#include <iostream>
#include <sstream>
#include <vector>
#include "GeneralArray.h"
using namespace std;

int main() {
    vector<int> dims2D = {3, 3};  // 3 行 3 列
    GeneralArray<int> arr2D(2, dims2D, 0);

    // 模擬輸入：必須符合格式 [[9,8,7],[6,5,4],[3,2,1]]
    istringstream iss("[[9,8,7],[6,5,4],[3,2,1]]");
    iss >> arr2D;

    cout << "Input 2D array: " << arr2D << endl;

    // 根據第一列排序（升序與降序示例）
    arr2D.sort(true, 1);
    cout << "2D array sorted ascending by first column: " << arr2D << endl;

    arr2D.sort(false, 1);
    cout << "2D array sorted descending by first column: " << arr2D << endl;

    return 0;
}
```

### 範例 4：異質陣列（使用 std::variant）

```cpp
#include <iostream>
#include <vector>
#include <variant>
#include <string>
#include "GeneralArray.h"
using namespace std;

int main() {
    // 定義支持 int、char 與 string 的 variant 型別
    using VarType = std::variant<int, char, std::string>;

    vector<int> dimsVar = {3};
    GeneralArray<VarType> arrVariant(1, dimsVar, VarType{});

    // 透過 Store() 存入不同類型的數值
    arrVariant.Store({0}, 100);                // int
    arrVariant.Store({1}, 'Z');                // char
    arrVariant.Store({2}, std::string("Test"));  // string

    cout << "Heterogeneous array: " << arrVariant << endl;

    return 0;
}
```

---

## 小結

GeneralArray 類提供了靈活的多維陣列操作功能，並且支援基本的元素存取、排序、反轉以及以 initializer_list 進行快速賦值。透過上面的範例，可以直觀地理解如何在不同情境下使用該類進行陣列操作。對於特殊型別（例如 `std::variant`），請注意部分操作（如輸入運算子）不支持，必須使用 Store() 等函式進行資料設置。

以上便是 GeneralArray 類的詳細使用說明與範例。希望這份文檔能幫助你快速上手並充分利用該類的功能。

---