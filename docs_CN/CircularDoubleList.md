# CircularDoubleList.hpp 文件

## 概述

`CircularDoubleList.hpp` 標頭檔定義了一個模板類別 `CircularDoubleList`，該類別實作了一個環狀雙向鏈結串列。此類別繼承自 `DoublyLinkedList`，並提供了額外的功能來維護串列的環狀特性。環狀雙向鏈結串列是一種資料結構，其中每個節點都有指向下一個節點和前一個節點的指標，並且最後一個節點會指回第一個節點，形成一個環狀結構。

## 類別: `CircularDoubleList<T>`

### 描述
`CircularDoubleList<T>` 類別是一個模板類別，代表一個環狀雙向鏈結串列。它提供了插入、刪除、串接和反轉串列元素的方法，同時保持串列的環狀特性。

### 模板參數
- `T`: 串列中儲存的元素型別。

### 建構函式與解構函式

#### `CircularDoubleList()`
- **描述**: 預設建構函式。初始化一個空的環狀雙向鏈結串列。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  ```

#### `CircularDoubleList(const CircularDoubleList<T>& other)`
- **描述**: 複製建構函式。透過複製另一個串列的元素來初始化一個新的環狀雙向鏈結串列。
- **參數**:
  - `other`: 要複製的 `CircularDoubleList` 物件。
- **用法**:
  ```cpp
  CircularDoubleList<int> list1;
  // 將元素插入 list1
  CircularDoubleList<int> list2(list1);
  ```

#### `~CircularDoubleList()`
- **描述**: 解構函式。透過刪除所有節點來清理串列。
- **用法**: 當物件超出作用域時自動呼叫。

### 操作

#### `void InsertBack(const T& e)`
- **描述**: 在串列的尾部（末端）插入一個元素。
- **參數**:
  - `e`: 要插入的元素。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  ```

#### `void InsertFront(const T& e)`
- **描述**: 在串列的頭部（前端）插入一個元素。
- **參數**:
  - `e`: 要插入的元素。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertFront(10);
  list.InsertFront(20);
  ```

#### `void DeleteBack()`
- **描述**: 刪除串列尾部（末端）的元素。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.DeleteBack();  // 移除 20
  ```

#### `void DeleteFront()`
- **描述**: 刪除串列頭部（前端）的元素。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertFront(10);
  list.InsertFront(20);
  list.DeleteFront();  // 移除 20
  ```

#### `void Concatenate(CircularDoubleList<T>& b)`
- **描述**: 將另一個環狀雙向鏈結串列串接到當前串列。
- **參數**:
  - `b`: 要串接的 `CircularDoubleList`。
- **用法**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2.InsertBack(20);
  list1.Concatenate(list2);  // list1 現在包含 10 和 20
  ```

#### `void Reverse()`
- **描述**: 反轉串列中元素的順序。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  list.Reverse();  // 串列現在是 20, 10
  ```

### 屬性

#### `int Length() const`
- **描述**: 回傳串列中元素的數量。
- **回傳值**: 串列的長度，以整數表示。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  int len = list.Length();  // len 為 2
  ```

### 重載運算子

#### `CircularDoubleList<T>& operator=(const CircularDoubleList<T>& other)`
- **描述**: 指派運算子。將另一個串列的內容指派給當前串列。
- **參數**:
  - `other`: 要指派的 `CircularDoubleList`。
- **回傳值**: 當前串列的參考。
- **用法**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2 = list1;  // list2 現在包含 10
  ```

#### `bool operator==(const CircularDoubleList<T>& other) const`
- **描述**: 相等運算子。檢查兩個串列是否相等。
- **參數**:
  - `other`: 要比較的 `CircularDoubleList`。
- **回傳值**: 如果串列相等則回傳 `true`，否則回傳 `false`。
- **用法**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2.InsertBack(10);
  bool equal = (list1 == list2);  // equal 為 true
  ```

#### `bool operator!=(const CircularDoubleList<T>& other) const`
- **描述**: 不等運算子。檢查兩個串列是否不相等。
- **參數**:
  - `other`: 要比較的 `CircularDoubleList`。
- **回傳值**: 如果串列不相等則回傳 `true`，否則回傳 `false`。
- **用法**:
  ```cpp
  CircularDoubleList<int> list1;
  list1.InsertBack(10);
  CircularDoubleList<int> list2;
  list2.InsertBack(20);
  bool notEqual = (list1 != list2);  // notEqual 為 true
  ```

#### `template <typename U> friend std::ostream& operator<<(std::ostream& out, const CircularDoubleList<U>& list)`
- **描述**: 重載 `<<` 運算子，用於印出串列。
- **參數**:
  - `out`: 輸出串流。
  - `list`: 要印出的 `CircularDoubleList`。
- **回傳值**: 輸出串流。
- **用法**:
  ```cpp
  CircularDoubleList<int> list;
  list.InsertBack(10);
  list.InsertBack(20);
  std::cout << list;  // 印出串列
  ```

## 範例用法

```cpp
#include "CircularDoubleList.hpp"
#include <iostream>

int main() {
    CircularDoubleList<int> list1;
    list1.InsertBack(10);
    list1.InsertBack(20);
    list1.InsertFront(5);

    CircularDoubleList<int> list2;
    list2.InsertBack(30);
    list2.InsertBack(40);

    list1.Concatenate(list2);
    list1.Reverse();

    std::cout << "List1: " << list1 << std::endl;
    std::cout << "List1 的長度: " << list1.Length() << std::endl;

    return 0;
}
```

## 潛在錯誤與邊界情況

1. **空串列操作**: 在空串列上呼叫 `DeleteBack()` 或 `DeleteFront()` 可能會導致未定義行為。在執行這些操作之前，請確保串列不為空。
2. **記憶體管理**: 處理大型串列時，請確保正確管理記憶體，以避免記憶體洩漏。
3. **環狀特性**: 手動操作串列時，請小心維護串列的環狀特性。

## 相依性

- `DoublyLinkedList.hpp`: 環狀雙向鏈結串列的基礎類別。
- `DoubleNode.hpp`: 定義串列中使用的節點結構。
- `DLIterator.hpp`: 提供串列的迭代器功能。
