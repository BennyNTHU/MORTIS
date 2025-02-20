# `GeneralArray` 技術文件

## 概述

`GeneralArray.hpp` 定義了一個 `GeneralArray` 類別，該類別支援多維陣列並能處理混合資料型別。此類別利用 `std::variant` 來處理多種型別，包括 `int`、`char`、`float`、`bool`、`double` 和 `std::string`。它提供了多種功能，用於初始化、儲存、檢索、排序和操作多維陣列中的元素。

---

## 主要元件

### 1. `MIXED_TYPE`
一個 `std::variant` 的型別別名，支援多種資料型別：
```cpp
using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;
```
這使得陣列可以在單一實例中儲存混合型別的資料。

### 2. `RangeList`
一個 `std::vector<int>` 的型別別名，表示陣列各維度的大小：
```cpp
typedef std::vector<int> RangeList;
```

### 3. `Index`
一個 `std::vector<int>` 的型別別名，用於表示多維索引：
```cpp
typedef std::vector<int> Index;
```

### 4. `is_variant`
一個用於檢測某型別是否為 `std::variant` 特化的特徵：
```cpp
template<typename T>
struct is_variant : std::false_type {}; // 主要模板

template<typename... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {}; // 針對 std::variant 的特化
```

---

## `GeneralArray<T>` 類別

`GeneralArray` 類別是一個模板類別，用於建立多維陣列。它支援多種操作，例如初始化、元素儲存/檢索、排序等。

### 建構函式與解構函式
- **建構函式**: 使用指定的維度初始化 `GeneralArray`。
- **解構函式**: 釋放所有分配的記憶體。

### 成員函式

- **`Initialize()`**: 將陣列中的所有元素初始化為型別 `T` 的預設值。
  
  範例：
  ```cpp
  arr.Initialize();
  ```

- **`Store(const Index& idx, T x)`**: 將值 `x` 儲存在給定的多維索引 `idx` 處。

  範例：
  ```cpp
  Index idx = {0, 1, 2};
  arr.Store(idx, 10);
  ```

- **`Retrieve(const Index& idx) const`**: 檢索給定多維索引 `idx` 處的元素。
  
  範例：
  ```cpp
  int value = arr.Retrieve(idx);
  ```

- **`Length() const`**: 回傳陣列中元素的總數。

  範例：
  ```cpp
  int len = arr.Length();
  ```

- **`Sort(bool reverse = false, int sortDim = 1)`**: 沿指定的維度對陣列進行排序。可選地，可以反轉排序順序。

  範例：
  ```cpp
  arr.Sort(true, 1); // 沿第一個維度進行反向排序
  ```

- **`Reverse()`**: 反轉陣列中元素的順序。

  範例：
  ```cpp
  arr.Reverse();
  ```

- **`Push_back(const T& value)`**: 將元素添加到一維陣列中（僅適用於一維陣列）。

  範例：
  ```cpp
  arr.Push_back(5);
  ```

### 運算子重載

- **`operator=`**: 從另一個 `GeneralArray` 或初始化列表複製內容。

  範例：
  ```cpp
  arr = otherArray;  // 複製建構函式
  arr = {1, 2, 3};   // 使用初始化列表
  ```

- **`operator[]`**: 通過索引存取元素（非 const 和 const 版本）。

  範例：
  ```cpp
  int& element = arr[0];  // 非 const 存取
  const int& element = arr[0];  // const 存取
  ```

- **`operator==`**: 檢查兩個 `GeneralArray` 實例是否相等。
- **`operator!=`**: 檢查兩個 `GeneralArray` 實例是否不相等。

### 輸入/輸出串流運算子

- **`operator>>`**: 從輸入串流中讀取資料到陣列。
- **`operator<<`**: 將陣列內容輸出到輸出串流。

範例：
```cpp
std::cin >> arr;
std::cout << arr;
```

---

## 範例用法

```cpp
#include "GeneralArray.hpp"

int main() {
    // 建立一個用於整數資料型別的 GeneralArray
    GeneralArray<int> arr(3); // 三維陣列
    
    // 使用預設值初始化陣列
    arr.Initialize();
    
    // 定義用於儲存/檢索元素的索引
    Index idx = {0, 1, 2}; // 存取位於 [0][1][2] 的元素
    
    // 在陣列中儲存一個值
    arr.Store(idx, 10);
    
    // 檢索並印出該值
    int val = arr.Retrieve(idx);
    std::cout << "位於索引 [0][1][2] 的值: " << val << std::endl;
    
    // 對陣列進行排序（可選維度）
    arr.Sort(false, 1); // 沿第一個維度進行排序
    
    // 反轉陣列
    arr.Reverse();
    
    // 使用串流運算子印出整個陣列
    std::cout << arr << std::endl;
    
    return 0;
}
```

---

## 潛在錯誤與邊界情況

1. **索引超出範圍**: 確保索引在陣列維度的有效範圍內。
2. **不支援的資料型別**: 陣列僅限於 `MIXED_TYPE` 中指定的型別。使用其他型別將導致編譯錯誤。
3. **對非一維陣列進行排序**: 對非一維陣列進行排序時，需要提供有效的維度以避免錯誤結果。
4. **記憶體問題**: 確保陣列維度和元素型別與系統可用記憶體相容。

---

## 相依性

- **C++17 或更高版本**: 需要 `std::variant`。
- **標準 C++ 函式庫**: `<vector>`、`<iostream>`、`<algorithm>` 等。
