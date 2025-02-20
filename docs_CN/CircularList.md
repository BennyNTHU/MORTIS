# `CircularList.hpp` 技術文件

## 概述

`CircularList.hpp` 標頭檔定義了一個模板化的 `CircularList` 類別，此類別繼承自基礎的鏈結串列。這個類別提供了管理循環鏈結串列的方法，其中最後一個節點會鏈結回第一個節點。它包含了常見的鏈結串列操作，如插入、刪除和串接，同時維持其循環結構。

---

## 主要元件

### `CircularList` 類別

`CircularList` 類別繼承自 `LinkedList` 類別，繼承了基礎鏈結串列的功能，同時增加了循環鏈結串列特有的功能，例如在插入或刪除節點時維持循環結構。

#### 成員變數：
- 繼承自 `LinkedList<T>`，其中可能包含基礎鏈結串列的結構和資料成員，如指向第一個節點的指標。

#### 建構子和解構子：
- **`CircularList()`**：預設建構子，初始化一個空的循環串列。
- **`CircularList(const CircularList<T>& other)`**：複製建構子，從現有的循環串列初始化一個新的循環串列。
- **`~CircularList()`**：解構子，用於適當清理循環鏈結串列使用的資源。

#### 成員函式：
- **`Length() const`**：回傳循環串列中的元素數量。

  範例：
  ```cpp
  int len = list.Length();  // 取得循環串列的長度
  ```

- **`IsEmpty() const`**：如果循環串列為空則回傳 `true`，否則回傳 `false`。

  範例：
  ```cpp
  bool isEmpty = list.IsEmpty();  // 檢查串列是否為空
  ```

- **`InsertBack(const T& e)`**：在循環串列尾端插入元素，確保串列維持其循環結構。

  範例：
  ```cpp
  list.InsertBack(10);  // 在循環串列尾端插入 10
  ```

- **`InsertFront(const T& e)`**：在循環串列前端插入元素，確保串列維持其循環結構。

  範例：
  ```cpp
  list.InsertFront(5);  // 在循環串列前端插入 5
  ```

- **`DeleteBack()`**：刪除循環串列中的最後一個元素，同時維持循環結構。

  範例：
  ```cpp
  list.DeleteBack();  // 從循環串列刪除最後一個元素
  ```

- **`DeleteFront()`**：刪除循環串列中的第一個元素，同時維持循環結構。

  範例：
  ```cpp
  list.DeleteFront();  // 從循環串列刪除第一個元素
  ```

- **`Concatenate(CircularList<T>& b)`**：將兩個循環串列串接成單一串列，維持循環結構。

  範例：
  ```cpp
  list.Concatenate(otherList);  // 串接兩個循環串列
  ```

#### 運算子重載：
- **`operator=(const CircularList<T>& other)`**：指定運算子，用於將另一個 `CircularList` 的資料複製到目前的串列。

  範例：
  ```cpp
  list = otherList;  // 將 otherList 的內容複製到 list
  ```

- **`operator==(const CircularList<T>& other) const`**：檢查兩個循環串列是否相等（即具有相同的元素和循環結構）。

  範例：
  ```cpp
  if (list == otherList) {
      // 執行某些操作
  }
  ```

- **`operator!=(const CircularList<T>& other) const`**：檢查兩個循環串列是否不相等。

  範例：
  ```cpp
  if (list != otherList) {
      // 執行某些操作
  }
  ```

- **`operator<<(std::ostream& out, const CircularList<T>& list)`**：重載 `<<` 運算子以輸出循環串列。這個函式是一個友誼函式，允許存取 `CircularList` 的私有成員。

  範例：
  ```cpp
  std::cout << list;  // 使用重載的 << 運算子輸出循環串列
  ```

---

## 使用範例

```cpp
#include "CircularList.hpp"

int main() {
    // 建立一個整數型別的循環串列
    CircularList<int> list;

    // 在前端和尾端插入元素
    list.InsertBack(10);   // 串列：10
    list.InsertFront(5);   // 串列：5, 10

    // 輸出串列
    std::cout << "插入後的串列：" << list << std::endl;

    // 從前端和尾端刪除元素
    list.DeleteBack();     // 串列：5
    list.DeleteFront();    // 串列：(空)

    // 檢查串列是否為空
    std::cout << "串列是否為空？" << (list.IsEmpty() ? "是" : "否") << std::endl;

    // 串接兩個循環串列
    CircularList<int> list2;
    list2.InsertBack(20);
    list2.InsertBack(30);
    list.Concatenate(list2);  // 串列：(原有元素) 20, 30

    // 輸出串接後的串列
    std::cout << "串接後的串列：" << list << std::endl;

    return 0;
}
```

### 說明：
- 建立一個循環串列，並在前端和尾端插入元素。
- 從兩端刪除元素，展示串列的循環特性。
- 使用 `IsEmpty()` 方法檢查刪除後的串列是否為空。
- 串接兩個循環串列並輸出結果。

---

## 潛在錯誤與邊界情況

1. **空串列操作**：在空串列上呼叫 `DeleteFront()` 或 `DeleteBack()` 可能導致未定義行為。在執行刪除操作前，請確保串列不為空。
   刪除前的檢查範例：
   ```cpp
   if (!list.IsEmpty()) {
       list.DeleteBack();
   }
   ```

2. **循環結構損壞**：確保所有的插入和刪除操作都維持循環結構是很重要的。在執行插入或刪除操作後，最後一個節點必須始終指向第一個節點。

3. **串接操作**：`Concatenate()` 方法假設要串接的兩個串列都是有效的循環串列。在串接之前，請確保串列已正確初始化且包含元素。

---

## 相依性

- **`LinkedList.hpp`**：`CircularList` 類別繼承自 `LinkedList` 類別，因此請確保 `LinkedList` 類別已正確定義和實作。
- **C++ 標準函式庫**：此類別相依性標準 C++ 函式庫，如用於輸入/輸出操作的 `<iostream>`。
