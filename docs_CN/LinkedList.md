# `LinkedList` 技術文件

## 概述

`LinkedList.hpp` 標頭檔定義了一個模板化的 `LinkedList` 類別，該類別代表一個單向或雙向鏈結串列（取決於 `Node` 的實作）。該類別提供了多種方法來執行鏈結串列操作，例如插入、刪除和遍歷。它還支援串接串列、反轉串列以及其他實用方法。

---

## 主要元件

### `LinkedList` 類別

`LinkedList` 類別是一個泛型類別，實作了鏈結串列的核心功能，例如添加和移除節點、遍歷串列以及操作資料。

#### 成員變數：
- **`first`**: 指向串列中第一個節點的指標，用於管理鏈結串列。

#### 建構函式與解構函式：
- **`LinkedList()`**: 預設建構函式，初始化一個空的鏈結串列。
  
  範例：
  ```cpp
  LinkedList<int> list;  // 建立一個空的整數鏈結串列
  ```

- **`~LinkedList()`**: 解構函式，清理串列所使用的資源。

#### 輔助函式：
- **`SetFirst(Node<T>* node)`**: 將串列的 `first` 節點設置為提供的節點指標。
  
  範例：
  ```cpp
  list.SetFirst(&someNode);  // 設置串列的第一個節點
  ```

- **`GetFirst()`**: 回傳指向串列中第一個節點的指標。

  範例：
  ```cpp
  Node<int>* firstNode = list.GetFirst();  // 取得第一個節點
  ```

- **`Clear()`**: 清除串列，刪除所有節點。

#### 插入函式：
- **`InsertFront(const T& e)`**: 在串列的前端插入元素 `e`。
  
  範例：
  ```cpp
  list.InsertFront(10);  // 在串列前端插入 10
  ```

- **`InsertBack(const T& e)`**: 在串列的末端插入元素 `e`。
  
  範例：
  ```cpp
  list.InsertBack(20);  // 在串列末端插入 20
  ```

- **`Insert(int i, T e)`**: 在串列的指定位置 `i` 插入元素 `e`。

  範例：
  ```cpp
  list.Insert(1, 15);  // 在位置 1 插入 15
  ```

#### 刪除函式：
- **`DeleteFront()`**: 刪除串列中的第一個節點。
  
  範例：
  ```cpp
  list.DeleteFront();  // 刪除第一個節點
  ```

- **`DeleteBack()`**: 刪除串列中的最後一個節點。
  
  範例：
  ```cpp
  list.DeleteBack();  // 刪除最後一個節點
  ```

- **`Delete(int i)`**: 刪除串列中位置 `i` 的節點。

  範例：
  ```cpp
  list.Delete(2);  // 刪除位置 2 的節點
  ```

#### 遍歷與檢索：
- **`begin()`**: 回傳指向串列第一個元素的迭代器 (`ChainIterator`)。
  
  範例：
  ```cpp
  ChainIterator<int> it = list.begin();  // 取得指向第一個元素的迭代器
  ```

- **`end()`**: 回傳指向串列末尾（最後一個元素之後）的迭代器。
  
  範例：
  ```cpp
  ChainIterator<int> endIt = list.end();  // 取得指向串列末尾的迭代器
  ```

- **`Get(int i)`**: 回傳指向串列中第 `i` 個節點的指標。
  
  範例：
  ```cpp
  Node<int>* node = list.Get(2);  // 取得位置 2 的節點
  ```

- **`GetSublist(int i, int j)`**: 回傳從索引 `i` 到索引 `j`（包含兩者）的子串列。
  
  範例：
  ```cpp
  LinkedList<int> sublist = list.GetSublist(1, 3);  // 取得從索引 1 到 3 的子串列
  ```

#### 其他函式：
- **`IsEmpty()`**: 如果串列為空，則回傳 `true`，否則回傳 `false`。
  
  範例：
  ```cpp
  bool empty = list.IsEmpty();  // 檢查串列是否為空
  ```

- **`Length()`**: 回傳串列的長度（元素數量）。
  
  範例：
  ```cpp
  int len = list.Length();  // 取得串列的長度
  ```

- **`Concatenate(LinkedList<T>& b)`**: 將當前串列與另一個串列 `b` 串接。
  
  範例：
  ```cpp
  list.Concatenate(otherList);  // 串接兩個串列
  ```

- **`Reverse()`**: 反轉串列中元素的順序。
  
  範例：
  ```cpp
  list.Reverse();  // 反轉串列
  ```

#### 運算子重載：
- **`operator=(const LinkedList<T>& other)`**: 指派運算子，將另一個串列的內容複製到當前串列。
  
  範例：
  ```cpp
  list = otherList;  // 將 otherList 的內容複製到 list
  ```

- **`operator==(const LinkedList<T>& other) const`**: 檢查兩個串列是否相等（即具有相同順序的相同元素）。
  
  範例：
  ```cpp
  if (list == otherList) {
      // 串列相等
  }
  ```

- **`operator!=(const LinkedList<T>& other) const`**: 檢查兩個串列是否不相等。

  範例：
  ```cpp
  if (list != otherList) {
      // 串列不相等
  }
  ```

- **`operator<<(std::ostream& out, const LinkedList<T>& list)`**: 重載 `<<` 運算子，用於印出串列的內容。
  
  範例：
  ```cpp
  std::cout << list;  // 將鏈結串列印出到終端機
  ```

---

## 範例用法

```cpp
#include "LinkedList.hpp"

int main() {
    LinkedList<int> list;

    // 在前端和末端插入元素
    list.InsertFront(10);   // 串列: 10
    list.InsertBack(20);    // 串列: 10, 20

    // 印出串列
    std::cout << "插入元素後的串列: " << list << std::endl;

    // 從前端和末端刪除元素
    list.DeleteBack();      // 串列: 10
    list.DeleteFront();     // 串列: (空)

    // 檢查串列是否為空
    std::cout << "串列是否為空？ " << (list.IsEmpty() ? "是" : "否") << std::endl;

    // 串接兩個串列
    LinkedList<int> list2;
    list2.InsertBack(20);
    list2.InsertBack(30);
    list.Concatenate(list2);  // 串列: 20, 30

    // 印出串接後的串列
    std::cout << "串接後的串列: " << list << std::endl;

    return 0;
}
```

### 解釋：
- 建立一個鏈結串列，並在前端和末端插入元素。
- 然後從前端和末端刪除元素，展示基本的插入和刪除操作。
- 使用 `IsEmpty()` 方法檢查刪除後串列是否為空。
- 將兩個鏈結串列串接，並印出結果。

---

## 潛在錯誤與邊界情況

1. **索引超出範圍**: 使用 `Get(int i)` 時，確保索引 `i` 是有效的（即在串列的範圍內）。應妥善處理無效索引。

2. **空串列操作**: 在空串列上呼叫 `DeleteFront()` 或 `DeleteBack()` 可能導致未定義行為。執行刪除操作前應檢查串列是否為空。

3. **記憶體管理**: 確保記憶體管理（特別是在解構函式中）正確處理，以避免記憶體洩漏。

---

## 相依性

- **`Node.hpp`**: `LinkedList` 類別依賴於 `Node<T>` 類別來表示串列中的個別元素。請確保 `Node<T>` 已定義並包含必要的欄位，例如 `next` 指標。
- **`ChainIterator.hpp`**: `LinkedList` 類別使用 `ChainIterator` 類別來遍歷串列。請確保 `ChainIterator<T>` 已正確實作。
