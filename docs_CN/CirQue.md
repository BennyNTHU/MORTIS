# `CirQue.hpp` 文件說明

## 概觀

`CirQue.hpp` 標頭文件定義了一個 `CirQue` 類別模板，表示一個循環佇列，這是一種資料結構，其中第一個元素緊接著最後一個元素。此類別允許從佇列的前端和後端插入和移除元素，同時保持結構的循環性。此佇列支援各種操作，如檢查大小、檢查是否為空，並存取其前端和後端元素。

---

## 主要元件

### `CirQue` 類別

`CirQue` 類別表示一個循環佇列，繼承自 `DeQue` 類別。它使用 `std::variant` 來儲存混合型別的元素，例如整數、浮點數、字串，甚至更複雜的型別如 `GeneralArray`、`Polynomial`、`SparseMatrix` 和 `String`。

#### 成員變數：
- **`front`**：佇列中第一個有效元素的索引。
- **`rear`**：佇列中最後一個有效元素的索引。
- **`count`**：佇列的當前大小（即佇列中的元素數量）。

#### 建構子與解構子：
- **`CirQue(int capacity = 10)`**：以給定容量初始化循環佇列（預設為 10）。它將佇列設為空狀態（front = -1, rear = -1, count = 0）。
  
  範例：
  ```cpp
  CirQue<int> queue(10);  // 創建一個容量為 10 的循環佇列，儲存整數
  ```

- **`~CirQue()`**：解構子，清理佇列使用的所有動態配置記憶體。

#### 操作函式：
- **`PushFront(const T& x)`**：將元素 `x` 插入佇列的前端。如果佇列已滿，可能會覆蓋最舊的元素。
  
  範例：
  ```cpp
  queue.PushFront(5);  // 將 5 插入到佇列的前端
  ```

- **`PushBack(const T& x)`**：將元素 `x` 插入佇列的後端。如果佇列已滿，可能會覆蓋最舊的元素。
  
  範例：
  ```cpp
  queue.PushBack(10);  // 將 10 插入到佇列的後端
  ```

- **`PopFront()`**：移除佇列前端的元素。

  範例：
  ```cpp
  queue.PopFront();  // 移除佇列的前端元素
  ```

- **`PopBack()`**：移除佇列後端的元素。

  範例：
  ```cpp
  queue.PopBack();  // 移除佇列的後端元素
  ```

#### 取得函式：
- **`Front()`**：返回佇列前端的元素，但不移除它。
  
  範例：
  ```cpp
  int frontElement = queue.Front();  // 取得佇列的前端元素（不會移除）
  ```

- **`Back()`**：返回佇列後端的元素，但不移除它。
  
  範例：
  ```cpp
  int backElement = queue.Back();  // 取得佇列的後端元素（不會移除）
  ```

#### 屬性：
- **`IsEmpty()`**：如果佇列為空，返回 `true`，否則返回 `false`。

  範例：
  ```cpp
  bool empty = queue.IsEmpty();  // 檢查佇列是否為空
  ```

- **`Size()`**：返回佇列中的元素數量（即當前大小）。

  範例：
  ```cpp
  int size = queue.Size();  // 取得佇列的當前大小
  ```

#### 運算子重載：
- **`operator<<`**：重載流插入運算子 (`<<`)，以可讀的格式印出佇列中的元素。
  
  範例：
  ```cpp
  std::cout << queue;  // 印出佇列中的元素
  ```

---

## 使用範例

以下是示範如何使用 `CirQue` 類別的範例：

```cpp
#include "CirQue.hpp"
#include <iostream>

int main() {
    // 創建一個容量為 5 的整數循環佇列
    CirQue<int> queue(5);

    // 在佇列的前端和後端插入元素
    queue.PushBack(10);    // 佇列: 10
    queue.PushFront(20);   // 佇列: 20, 10

    // 印出佇列
    std::cout << "Queue after insertions: " << queue << std::endl;

    // 取得前端和後端元素
    std::cout << "Front: " << queue.Front() << std::endl;  // Front: 20
    std::cout << "Back: " << queue.Back() << std::endl;    // Back: 10

    // 移除前端元素
    queue.PopFront();  // 佇列: 10

    // 印出移除前端元素後的佇列
    std::cout << "Queue after PopFront: " << queue << std::endl;

    // 移除後端元素
    queue.PopBack();  // 佇列: (空)

    // 印出移除後端元素後的佇列
    std::cout << "Queue after PopBack: " << queue << std::endl;

    // 檢查佇列是否為空
    std::cout << "Is the queue empty? " << (queue.IsEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

### 說明：
- 程式碼創建了一個容量為 5 的整數循環佇列。
- 在佇列的前端和後端插入元素，並在每次操作後印出佇列的狀態。
- 使用 `Front()` 和 `Back()` 方法來取得前端和後端元素。
- 然後從佇列的前端和後端移除元素，並在每次操作後印出佇列的狀態。
- 使用 `IsEmpty()` 方法檢查佇列是否為空。

---

## 可能的錯誤與邊界情形

1. **佇列已滿**：當佇列已滿，並且嘗試插入新元素時，根據循環佇列的實作方式，可能會覆蓋已存在的元素。在執行插入操作時，應注意此行為。

2. **空佇列操作**：確保像 `PopFront()` 和 `PopBack()` 等操作能處理佇列為空的情況。對空佇列執行這些操作不應導致未定義的行為。

   範例：
   ```cpp
   if (!queue.IsEmpty()) {
       queue.PopFront();
   }
   ```

3. **索引錯誤**：確保在每次插入和移除操作後，`front`、`rear` 和 `count` 變數會正確更新，以維持佇列的正確狀態。

---

## 相依性

- **`DeQue.hpp`**：`CirQue` 類別繼承自 `DeQue` 類別，請確保 `DeQue` 類別已正確定義，並包含處理雙端佇列的方法（或支援基本佇列操作）。
- **C++ 標準函式庫**：此類別使用 `std::variant` 儲存各種型別的元素，並依賴標準 C++ 函式庫，如 `<iostream>` 來進行輸入/輸出操作。
