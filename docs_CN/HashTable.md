# `HashTable.hpp` 文件說明

## 概觀

`HashTable.hpp` 標頭文件定義了一個模板類別 `HashTable`，用來實作雜湊表資料結構。雜湊表是一種鍵值對集合，其中鍵通過雜湊函式映射到陣列中的索引。此實作使用分離鏈結（透過 `DoublyLinkedList`）來處理碰撞，意味著多個雜湊到相同索引的鍵將存放在該索引的鏈結串列中。

`HashTable` 類別支援插入、搜尋和刪除鍵，並能處理多種資料型別。

## 類別：`HashTable<T>`

### 說明
`HashTable<T>` 類別是一個模板類別，表示一個雜湊表。它使用 `DoublyLinkedList<T>` 的向量來儲存鍵，並使用雜湊函式將鍵映射到向量中的索引。

### 模板參數
- `T`：儲存在雜湊表中的鍵的型別。

### 建構子與解構子

#### `explicit HashTable(size_t size)`
- **說明**：建構子，用來初始化具有指定容量的雜湊表。
- **參數**：
  - `size`：雜湊表的容量（桶數）。
- **使用範例**：
  ```cpp
  HashTable<int> hashTable(10);  // 創建一個容量為 10 的雜湊表
  ```

#### `~HashTable()`
- **說明**：解構子，用來清理雜湊表，刪除所有元素。
- **使用範例**：當物件超出作用範圍時，會自動呼叫此解構子。

### 方法

#### `void insert(const T& key)`
- **說明**：將鍵 `key` 插入到雜湊表中。
- **參數**：
  - `key`：要插入的鍵。
- **使用範例**：
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);  // 將鍵 42 插入雜湊表
  ```

#### `bool search(const T& key) const`
- **說明**：在雜湊表中搜尋鍵 `key`。
- **參數**：
  - `key`：要搜尋的鍵。
- **回傳值**：若找到鍵，則返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);
  bool found = hashTable.search(42);  // found 為 true
  ```

#### `bool remove(const T& key)`
- **說明**：從雜湊表中移除鍵 `key`。
- **參數**：
  - `key`：要移除的鍵。
- **回傳值**：若找到並移除鍵，則返回 `true`，否則返回 `false`。
- **使用範例**：
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);
  bool removed = hashTable.remove(42);  // removed 為 true
  ```

#### `void display() const`
- **說明**：顯示雜湊表的內容。
- **使用範例**：
  ```cpp
  HashTable<int> hashTable(10);
  hashTable.insert(42);
  hashTable.display();  // 輸出雜湊表的內容
  ```

### 私有方法

#### `size_t hashFunction(const T& key) const`
- **說明**：用來將鍵映射到雜湊表中的索引的雜湊函式。
- **參數**：
  - `key`：要雜湊的鍵。
- **回傳值**：返回鍵應該儲存的雜湊表索引。
- **使用範例**：此方法會在 `insert`、`search` 和 `remove` 方法中被內部使用。

## 使用範例

```cpp
#include "HashTable.hpp"
#include <iostream>

int main() {
    // 創建一個容量為 10 的雜湊表
    HashTable<int> hashTable(10);

    // 插入一些鍵
    hashTable.insert(42);
    hashTable.insert(15);
    hashTable.insert(7);
    hashTable.insert(23);

    // 搜尋一個鍵
    bool found = hashTable.search(15);
    std::cout << "Key 15 found: " << std::boolalpha << found << std::endl;

    // 移除一個鍵
    bool removed = hashTable.remove(7);
    std::cout << "Key 7 removed: " << std::boolalpha << removed << std::endl;

    // 顯示雜湊表
    hashTable.display();

    return 0;
}
```

## 可能的錯誤與邊界情形

1. **雜湊碰撞**：雜湊表使用分離鏈結來處理碰撞，但過多的碰撞會影響性能。確保雜湊函式能夠將鍵均勻分布在桶中。
2. **無效的鍵型別**：雜湊函式必須與鍵型別 `T` 兼容。如果 `T` 是自訂型別，請確保實作適合的雜湊函式。
3. **空雜湊表**：在空雜湊表中搜尋或移除鍵將返回 `false`。在執行這些操作前，請確保雜湊表不為空。
4. **記憶體管理**：在動態配置鍵時，請確保進行正確的清理，以避免記憶體洩漏。

## 相依性

- **DoublyLinkedList.hpp**：`HashTable` 類別使用 `DoublyLinkedList` 來處理碰撞。請確保此檔案已正確匯入並配置。
- **DLIterator.hpp**：`HashTable` 類別使用 `DLIterator` 來遍歷鏈結串列。請確保此檔案已正確匯入並配置。
- **DoubleNode.hpp**：`HashTable` 類別使用 `DoubleNode` 來作為鏈結串列的節點。請確保此檔案已正確匯入並配置。
- **標準函式庫**：此檔案包含了 C++ 標準函式庫中的 `<iostream>` 和 `<vector>`，確保您的環境已正確配置以使用這些庫。

## 摘要

`HashTable.hpp` 文件提供了一個靈活的雜湊表資料結構實作，支援鍵的插入、搜尋和移除。依照範例和指引使用此類別，您可以在專案中有效地建立和操作雜湊表。
