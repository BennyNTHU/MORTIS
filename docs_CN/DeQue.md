# `DeQue.hpp` 文件

## 概述

`DeQue.hpp` 標頭檔定義了 `DeQue` 類別模板，該類別代表一個雙端佇列（deque）。它繼承自 `Bag<T>` 類別，允許從佇列的前端和後端添加或移除元素。`DeQue` 類別提供了多種操作，例如插入、移除以及存取佇列前端和後端的元素。它使用 `std::variant` 來處理各種類型的資料。

---

## 主要元件

### `DeQue` 類別

`DeQue` 類別實作了雙端佇列（deque）資料結構。它允許從佇列的兩端高效地添加和移除元素。

#### 成員變數：
- **`front`**: 佇列前端元素的索引。
- **`rear`**: 佇列後端元素的索引。
- **`size`**: 佇列中元素的數量。

#### 建構函式與解構函式：
- **`DeQue(int initial_capacity = 10)`**: 建構函式，初始化一個具有指定初始容量（預設為 10）的雙端佇列。它將佇列設置為空狀態（front = -1, rear = -1, size = 0）。

  範例：
  ```cpp
  DeQue<int> deque(10);  // 建立一個容量為 10 的整數雙端佇列
  ```

- **`~DeQue()`**: 解構函式，清理雙端佇列所使用的資源。

#### 雙端佇列操作：
- **`PushFront(const T& x)`**: 將元素 `x` 添加到佇列的前端。如果佇列已滿，可能會調整大小或覆蓋最舊的元素。

  範例：
  ```cpp
  deque.PushFront(5);  // 將 5 添加到佇列的前端
  ```

- **`PushBack(const T& x)`**: 將元素 `x` 添加到佇列的後端。如果佇列已滿，可能會調整大小或覆蓋最舊的元素。

  範例：
  ```cpp
  deque.PushBack(10);  // 將 10 添加到佇列的後端
  ```

- **`PopFront()`**: 移除佇列前端的元素。如果佇列為空，此操作應安全處理。

  範例：
  ```cpp
  deque.PopFront();  // 移除佇列前端的元素
  ```

- **`PopBack()`**: 移除佇列後端的元素。如果佇列為空，此操作應安全處理。

  範例：
  ```cpp
  deque.PopBack();  // 移除佇列後端的元素
  ```

#### 存取器：
- **`getFront()`**: 回傳佇列前端元素的索引。

  範例：
  ```cpp
  int frontIndex = deque.getFront();  // 取得前端元素的索引
  ```

- **`getRear()`**: 回傳佇列後端元素的索引。

  範例：
  ```cpp
  int rearIndex = deque.getRear();  // 取得後端元素的索引
  ```

- **`Front()`**: 回傳佇列前端的元素，但不移除它。

  範例：
  ```cpp
  int frontElement = deque.Front();  // 取得前端的元素（不移除）
  ```

- **`Back()`**: 回傳佇列後端的元素，但不移除它。

  範例：
  ```cpp
  int backElement = deque.Back();  // 取得後端的元素（不移除）
  ```

#### 屬性：
- **`IsEmpty()`**: 如果佇列為空，則回傳 `true`，否則回傳 `false`。

  範例：
  ```cpp
  bool empty = deque.IsEmpty();  // 檢查佇列是否為空
  ```

#### 運算子重載：
- **`operator<<`**: 重載串流插入 (`<<`) 運算子，以可讀格式印出佇列中的元素。

  範例：
  ```cpp
  std::cout << deque;  // 印出佇列中的元素
  ```

---

## 範例用法

以下是一個展示如何使用 `DeQue` 類別的範例：

```cpp
#include "DeQue.hpp"
#include <iostream>

int main() {
    // 建立一個容量為 5 的整數雙端佇列
    DeQue<int> deque(5);

    // 在佇列的前端和後端添加元素
    deque.PushFront(10);  // 佇列: 10
    deque.PushBack(20);   // 佇列: 10, 20
    deque.PushFront(5);   // 佇列: 5, 10, 20

    // 印出佇列
    std::cout << "插入元素後的佇列: " << deque << std::endl;

    // 取得前端和後端的元素
    std::cout << "前端: " << deque.Front() << std::endl;  // 前端: 5
    std::cout << "後端: " << deque.Back() << std::endl;    // 後端: 20

    // 移除前端的元素
    deque.PopFront();  // 佇列: 10, 20

    // 印出移除前端元素後的佇列
    std::cout << "移除前端元素後的佇列: " << deque << std::endl;

    // 移除後端的元素
    deque.PopBack();  // 佇列: 10

    // 印出移除後端元素後的佇列
    std::cout << "移除後端元素後的佇列: " << deque << std::endl;

    // 檢查佇列是否為空
    std::cout << "佇列是否為空？ " << (deque.IsEmpty() ? "是" : "否") << std::endl;

    return 0;
}
```

### 解釋：
- 此程式碼展示了如何使用 `DeQue` 類別來從佇列的前端和後端插入和移除元素。
- 它使用 `PushFront()` 和 `PushBack()` 方法來添加元素，並使用 `PopFront()` 和 `PopBack()` 來移除元素。
- `Front()` 和 `Back()` 方法用於存取佇列的前端和後端元素，但不移除它們。
- 程式使用 `IsEmpty()` 方法來檢查佇列是否為空。

---

## 潛在錯誤與邊界情況

1. **佇列已滿**: 如果佇列達到其容量並嘗試插入更多元素，請確保佇列能夠正確調整大小或處理溢出的情況。

2. **空佇列操作**: 在空佇列上執行 `PopFront()` 或 `PopBack()` 操作時，請確保這些操作能夠安全處理。這可能涉及回傳預設值、拋出例外，或者如果佇列為空則不執行任何操作。

   範例：
   ```cpp
   if (!deque.IsEmpty()) {
       deque.PopFront();
   }
   ```

3. **索引錯誤**: 確保在每次操作後正確更新 `front`、`rear` 和 `size` 變數，以確保佇列保持正確的狀態。

---

## 相依性

- **`Bag.hpp`**: `DeQue` 類別繼承自 `Bag<T>` 類別，因此請確保 `Bag<T>` 類別已正確定義並包含處理動態陣列操作的方法。
- **C++ 標準函式庫**: 該類別使用 `std::variant` 來儲存各種類型的元素，並使用 `std::ostream` 來印出佇列。
