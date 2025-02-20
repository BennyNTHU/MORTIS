# `Bag.hpp` 文件說明

## 概觀

`Bag.hpp` 文件定義了一個模板化的 `Bag` 類別，該類別可以儲存各種類型的元素於動態陣列中。此類別包含基本操作功能，如新增、移除及檢查元素，還有進階操作，如聯集及元素重複次數計算。

---

## 主要元件

### `Bag` 類別

`Bag` 類別表示一個可以動態修改的元素集合。多重集合中的元素存放於陣列中，並支援多種操作來與此集合互動。

#### 成員變數：
- **`arr`**：指向存放於多重集合中的元素陣列的指標。
- **`top`**：陣列中最後一個元素的索引。如果多重集合為空，`top` 為 `-1`。
- **`capacity`**：陣列目前的容量（即多重集合最多可以容納的元素數量，在重新配置之前）。
- **`size`**：目前多重集合中元素的數量，計算方式為 `top + 1`。

#### 建構子與解構子：
- **`Bag()`**：預設建構子，初始化為一個空多重集合，沒有任何元素且容量為預設值。

  範例：
  ```cpp
  Bag<int> myBag;  // 建立一個空的整數多重集合
  ```

- **`Bag(int c)`**：根據指定的容量 `c` 初始化一個多重集合。

  範例：
  ```cpp
  Bag<int> myBag(10);  // 建立一個容量為 10 的多重集合
  ```

- **`Bag(const Bag<T>& other)`**：複製建構子，用另一個 `Bag` 的元素來初始化此多重集合。

  範例：
  ```cpp
  Bag<int> copyBag = myBag;  // 建立原多重集合的複本
  ```

- **`~Bag()`**：解構子，清理多重集合所佔用的資源。

#### 取得方法：
- **`getCapacity()`**：返回多重集合的容量（即它在重新配置之前最多能容納的元素數量）。

  範例：
  ```cpp
  int cap = myBag.getCapacity();  // 取得多重集合的容量
  ```

- **`getTop()`**：返回多重集合中最後一個元素的索引。

  範例：
  ```cpp
  int topIndex = myBag.getTop();  // 取得多重集合中最後一個元素的索引
  ```

- **`getArr()`**：返回指向多重集合中元素陣列的指標。

  範例：
  ```cpp
  int* arr = myBag.getArr();  // 取得多重集合中的元素陣列
  ```

- **`Element()`**：返回多重集合中目前元素的數量。

  範例：
  ```cpp
  int numElements = myBag.Element();  // 取得多重集合中的元素數量
  ```

#### 屬性：
- **`IsEmpty()`**：如果多重集合為空，返回 `true`，否則返回 `false`。

  範例：
  ```cpp
  bool empty = myBag.IsEmpty();  // 檢查多重集合是否為空
  ```

- **`Multiplicity(const U& x)`**：返回元素 `x` 在多重集合中出現的次數。

  範例：
  ```cpp
  int count = myBag.Multiplicity(5);  // 計算 5 在多重集合中出現的次數
  ```

- **`isBelong(const U& x)`**：如果元素 `x` 存在於多重集合中，返回 `true`，否則返回 `false`。

  範例：
  ```cpp
  bool belongs = myBag.isBelong(5);  // 檢查 5 是否存在於多重集合中
  ```

#### 操作：
- **`Push(const T& x)`**：將元素 `x` 新增到多重集合中。

  範例：
  ```cpp
  myBag.Push(10);  // 將 10 新增到多重集合中
  ```

- **`Pop()`**：移除多重集合中的最後一個元素。

  範例：
  ```cpp
  myBag.Pop();  // 移除多重集合中的最後一個元素
  ```

- **`Unify()`**：移除多重集合中的重複元素，保留唯一的項目。

  範例：
  ```cpp
  myBag.Unify();  // 移除多重集合中的重複元素
  ```

- **`Union(const Bag<T>& b2)`**：返回一個新 `Bag`，包含 `this` 多重集合和 `b2` 中的所有元素。

  範例：
  ```cpp
  Bag<int> bag2;
  bag2.Push(5);
  Bag<int> unionBag = myBag.Union(bag2);  // 結合 myBag 和 bag2 的元素
  ```

#### 運算子重載：
- **`operator=`**：賦值運算子，將另一個 `Bag` 的元素複製到當前 `Bag`。

  範例：
  ```cpp
  myBag = anotherBag;  // 複製 anotherBag 的元素到 myBag
  ```

- **`operator==`**：比較兩個多重集合是否相等（元素和順序完全相同）。

  範例：
  ```cpp
  if (myBag == anotherBag) {
      // 多重集合相等
  }
  ```

- **`operator!=`**：比較兩個多重集合是否不相等。

  範例：
  ```cpp
  if (myBag != anotherBag) {
      // 多重集合不相等
  }
  ```

- **`operator<<`**：重載以印出多重集合中的內容。

  範例：
  ```cpp
  std::cout << myBag;  // 印出多重集合中的內容
  ```

---

## 使用範例

以下是示範如何使用 `Bag` 類別的範例：

```cpp
#include "Bag.hpp"
#include <iostream>

int main() {
    // 建立一個整數多重集合
    Bag<int> myBag(10);

    // 向多重集合中加入元素
    myBag.Push(10);
    myBag.Push(20);
    myBag.Push(30);

    // 印出多重集合中的內容
    std::cout << "Bag contents: " << myBag << std::endl;

    // 檢查多重集合中是否包含特定元素
    if (myBag.isBelong(20)) {
        std::cout << "20 is in the bag!" << std::endl;
    }

    // 取得多重集合中元素的數量
    std::cout << "Number of elements: " << myBag.Element() << std::endl;

    // 移除最後一個元素
    myBag.Pop();

    // 印出移除元素後的多重集合內容
    std::cout << "After popping an element: " << myBag << std::endl;

    // 建立另一個多重集合並將兩個多重集合進行整合
    Bag<int> anotherBag;
    anotherBag.Push(10);
    anotherBag.Push(30);
    Bag<int> unifiedBag = myBag.Union(anotherBag);
    
    // 印出整合後的多重集合
    std::cout << "Unified bag: " << unifiedBag << std::endl;

    return 0;
}
```

### 說明：
- 此程式碼建立了一個 `Bag` 來儲存整數並執行各種操作，如加入元素（`Push`）、檢查元素是否存在（`isBelong`）以及移除元素（`Pop`）。
- 範例中示範了如何檢查元素數量，並使用 `Union` 函數來整合兩個多重集合。

---

## 可能的錯誤與邊界情形

1. **多重集合溢位**：若元素數量超過多重集合的容量，陣列可能需要重新配置。請確保多重集合在 `Push()` 函數中能正確處理重新配置。

2. **空多重集合操作**：像是 `Pop()` 或檢查元素存在等操作應該優雅地處理空多重集合情形。確保在進行這些操作前檢查多重集合是否為空。

   範例：
   ```cpp
   if (!myBag.IsEmpty()) {
       myBag.Pop();
   }
   ```

3. **重複處理與 `Unify`**：`Unify()` 方法會移除重複元素。確保此方法不會誤移除唯一元素，並正確處理所有元素相同的情形。

---

## 相依性

- **C++ 標準函式庫**：此類別使用 `std::variant` 儲存異質元素，並使用 `<iostream>`、`<string>` 及 `<algorithm>` 等其他標準函式庫。
  
- **其他包含**：`Bag` 類別包含對其他陣列相關類型（`GeneralArray`、`Polynomial`、`SparseMatrix`、`String`）的引用，這些類型應該正確定義並匯入。
