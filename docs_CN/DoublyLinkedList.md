# `DoublyLinkedList` 技術文件

## 概觀

`DoublyLinkedList.hpp` 標頭文件定義了一個模板類別 `DoublyLinkedList`，實作了一個雙向鏈結串列。這個資料結構由節點組成，每個節點包含資料和指向下一個節點及前一個節點的指標。此類別提供了插入、刪除、遍歷和其他常見操作的方法。

## 類別：`DoublyLinkedList<T>`

### 說明
`DoublyLinkedList<T>` 類別是一個模板類別，表示一個雙向鏈結串列。它提供了操作鏈表的方法，包括插入、刪除、遍歷和其他實用功能。

### 模板參數
- `T`：儲存在鏈表中節點的元素型別。

### 建構子與解構子

#### `DoublyLinkedList()`
- **說明**：預設建構子，初始化一個空的雙向鏈結串列。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  ```

#### `DoublyLinkedList(const DoublyLinkedList<T>& other)`
- **說明**：複製建構子，通過複製另一個鏈表的元素來初始化新鏈表。
- **參數**：
  - `other`：要複製的 `DoublyLinkedList` 物件。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list1;
  // 在 list1 中插入元素
  DoublyLinkedList<int> list2(list1);
  ```

#### `~DoublyLinkedList()`
- **說明**：解構子，清理鏈表並刪除所有節點。
- **使用範例**：當物件超出作用範圍時會自動呼叫。

### 取得與設定方法

#### `DoubleNode<T>* GetFirst() const`
- **說明**：返回鏈表中第一個節點的指標。
- **回傳值**：指向第一個 `DoubleNode<T>` 的指標。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertFront(10);
  DoubleNode<int>* firstNode = list.GetFirst();
  ```

#### `DoubleNode<T>* GetLast() const`
- **說明**：返回鏈表中最後一個節點的指標。
- **回傳值**：指向最後一個 `DoubleNode<T>` 的指標。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(20);
  DoubleNode<int>* lastNode = list.GetLast();
  ```

#### `void SetFirst(DoubleNode<T>* node)`
- **說明**：設定鏈表的第一個節點。
- **參數**：
  - `node`：要設為第一個節點的 `DoubleNode<T>` 的指標。
- **使用範例**：
  ```cpp
  DoubleNode<int>* node = new DoubleNode<int>(10);
  DoublyLinkedList<int> list;
  list.SetFirst(node);
  ```

#### `void SetLast(DoubleNode<T>* node)`
- **說明**：設定鏈表的最後一個節點。
- **參數**：
  - `node`：要設為最後一個節點的 `DoubleNode<T>` 的指標。
- **使用範例**：
  ```cpp
  DoubleNode<int>* node = new DoubleNode<int>(20);
  DoublyLinkedList<int> list;
  list.SetLast(node);
  ```

### 迭代器方法

#### `DLIterator<T> begin() const`
- **說明**：返回指向鏈表第一個節點的迭代器。
- **回傳值**：`DLIterator<T>` 物件。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  DLIterator<int> it = list.begin();
  ```

#### `DLIterator<T> end() const`
- **說明**：返回指向鏈表結尾（`nullptr`）的迭代器。
- **回傳值**：`DLIterator<T>` 物件。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  DLIterator<int> it = list.end();
  ```

### 存取元素

#### `Node<T>* Get(int i)`
- **說明**：返回鏈表中第 `i` 個元素的指標。
- **參數**：
  - `i`：要存取的元素索引。
- **回傳值**：指向第 `i` 個 `Node<T>` 的指標。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  Node<int>* node = list.Get(1);  // 取得第二個元素（20）
  ```

### 插入方法

#### `void InsertFront(const T& e)`
- **說明**：將元素 `e` 插入到鏈表的前端。
- **參數**：
  - `e`：要插入的元素。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertFront(10);
  ```

#### `void InsertBack(const T& e)`
- **說明**：將元素 `e` 插入到鏈表的後端。
- **參數**：
  - `e`：要插入的元素。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(20);
  ```

#### `void Insert(int i, T e)`
- **說明**：將元素 `e` 插入到鏈表的第 `i` 個位置。
- **參數**：
  - `i`：要插入元素的位置索引。
  - `e`：要插入的元素。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(30);
  list.Insert(1, 20);  // 在第二個位置插入 20
  ```

### 刪除方法

#### `void DeleteFront()`
- **說明**：刪除鏈表前端的元素。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertFront(10);
  list.DeleteFront();  // 刪除 10
  ```

#### `void DeleteBack()`
- **說明**：刪除鏈表後端的元素。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(20);
  list.DeleteBack();  // 刪除 20
  ```

#### `void Delete(int i)`
- **說明**：刪除鏈表中第 `i` 個位置的元素。
- **參數**：
  - `i`：要刪除的元素位置索引。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.InsertBack(30);
  list.Delete(1);  // 刪除第二個元素（20）
  ```

### 其他函式

#### `int Length() const`
- **說明**：返回鏈表中的元素數量。
- **回傳值**：鏈表的長度（即元素數量）。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  int len = list.Length();  // len 為 2
  ```

#### `void Concatenate(DoublyLinkedList<T>& b)`
- **說明**：將另一個雙向鏈結串列 `b` 併入當前鏈表。
- **參數**：
  - `b`：要併入的 `DoublyLinkedList`。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2.InsertBack(20);
  list1.Concatenate(list2);  // list1 現在包含 10 和 20
  ```

#### `void Reverse()`
- **說明**：反轉鏈表中的元素順序。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.Reverse();  // 鏈表現在是 20, 10
  ```

#### `bool IsEmpty() const`
- **說明**：檢查鏈表是否為空。
- **回傳值**：如果鏈表為空，返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  bool empty = list.IsEmpty();  // empty 為 true
  ```

### 運算子重載

#### `DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other)`
- **說明**：賦值運算子，將另一個鏈表的內容賦值給當前鏈表。
- **參數**：
  - `other```markdown
  - `other`：要賦值的 `DoublyLinkedList` 物件。
- **回傳值**：返回當前鏈表的參考。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2 = list1;  // list2 現在包含 10
  ```

#### `bool operator==(const DoublyLinkedList<T>& other) const`
- **說明**：相等運算子，檢查兩個鏈表是否相等。
- **參數**：
  - `other`：要比較的 `DoublyLinkedList` 物件。
- **回傳值**：如果兩個鏈表相等，返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2.InsertBack(10);
  bool equal = (list1 == list2);  // equal 為 true
  ```

#### `bool operator!=(const DoublyLinkedList<T>& other) const`
- **說明**：不相等運算子，檢查兩個鏈表是否不相等。
- **參數**：
  - `other`：要比較的 `DoublyLinkedList` 物件。
- **回傳值**：如果兩個鏈表不相等，返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list1;
  list1.InsertBack(10);
  DoublyLinkedList<int> list2;
  list2.InsertBack(20);
  bool notEqual = (list1 != list2);  // notEqual 為 true
  ```

#### `template <typename U> friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<U>& list)`
- **說明**：重載 `<<` 運算子，用於輸出鏈表。
- **參數**：
  - `out`：輸出流。
  - `list`：要輸出的 `DoublyLinkedList` 物件。
- **回傳值**：輸出流。
- **使用範例**：
  ```cpp
  DoublyLinkedList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  std::cout << list;  // 輸出鏈表
  ```

## 使用範例

```cpp
#include "DoublyLinkedList.hpp"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;
    list.InsertBack(10);
    list.InsertBack(20);
    list.InsertFront(5);

    std::cout << "List: " << list << std::endl;  // 輸出: 5 10 20
    std::cout << "Length: " << list.Length() << std::endl;  // 輸出: 3

    list.DeleteBack();
    std::cout << "After DeleteBack: " << list << std::endl;  // 輸出: 5 10

    list.Reverse();
    std::cout << "After Reverse: " << list << std::endl;  // 輸出: 10 5

    return 0;
}
```

## 可能的錯誤與邊界情形

1. **空列表操作**：對空列表執行 `DeleteFront()`、`DeleteBack()` 或 `Delete(int i)` 等操作可能導致未定義行為。請確保在執行這些操作之前，列表非空。
2. **索引越界**：使用 `Get(int i)` 或 `Delete(int i)` 時，請確保索引在列表的有效範圍內，否則將導致存取無效記憶體。
3. **記憶體管理**：在處理節點時，確保正確的記憶體管理以避免記憶體洩漏。

## 相依性

- `DoubleNode.hpp`：定義鏈結串列中使用的節點結構。
- `DLIterator.hpp`：提供鏈結串列的迭代器功能。
