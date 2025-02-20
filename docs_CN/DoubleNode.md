# `DoubleNode` 技術文件

## 概述

`DoubleNode.hpp` 標頭檔定義了一個 `DoubleNode` 類別模板，該類別繼承自 `Node<T>` 類別。此類別用於表示雙向鏈結串列中的節點，該節點具有兩個指標：一個指向下一個節點，另一個指向前一個節點。`DoubleNode` 類別包含了設置和獲取前一個節點的方法，以及標準的建構函式和解構函式。

---

## 主要元件

### `DoubleNode` 類別

`DoubleNode` 類別是 `Node<T>` 類別的特化版本，它增加了一個指向前一個節點的指標。這允許在雙向鏈結串列中進行雙向遍歷：向前和向後。

#### 成員變數：
- **`prev`**: 指向雙向鏈結串列中前一個節點的指標。

#### 建構函式與解構函式：
- **`DoubleNode()`**: 預設建構函式，初始化一個沒有資料的節點，並將 `next` 和 `prev` 指標設置為 `nullptr`。
  
  範例：
  ```cpp
  DoubleNode<int> node;  // 建立一個空的 DoubleNode
  ```

- **`DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr)`**: 建構函式，使用給定的資料和可選的 `next` 與 `prev` 指標初始化節點。如果未提供，`next` 和 `prev` 的預設值為 `nullptr`。
  
  範例：
  ```cpp
  DoubleNode<int> node(10);  // 建立一個資料為 10 且 next 和 prev 為 nullptr 的節點
  ```

- **`~DoubleNode()`**: 解構函式，用於清理 `DoubleNode` 物件所使用的資源。在此情況下，它確保在節點不再需要時正確刪除。

#### 存取器與設置器：
- **`getPrev()`**: 回傳指向雙向鏈結串列中前一個節點的指標。
  
  範例：
  ```cpp
  DoubleNode<int>* prevNode = node.getPrev();  // 存取前一個節點的指標
  ```

- **`setPrev(DoubleNode<T>* prev)`**: 將前一個節點的指標設置為提供的 `prev` 節點。

  範例：
  ```cpp
  node.setPrev(&anotherNode);  // 將前一個節點指標設置為 anotherNode
  ```

---

## 範例用法

以下是一個展示如何在雙向鏈結串列中使用 `DoubleNode` 類別的範例：

```cpp
#include "DoubleNode.hpp"
#include <iostream>

int main() {
    // 建立兩個 DoubleNode 物件
    DoubleNode<int> node1(10);
    DoubleNode<int> node2(20);

    // 鏈結節點
    node1.setPrev(nullptr);  // 第一個節點沒有前一個節點
    node1.next = &node2;     // 鏈結到第二個節點

    node2.setPrev(&node1);   // 第二個節點的前一個節點是第一個節點

    // 存取資料和前一個節點
    std::cout << "節點 1 資料: " << node1.data << ", 前一個節點: " << node1.getPrev() << std::endl;
    std::cout << "節點 2 資料: " << node2.data << ", 前一個節點: " << node2.getPrev()->data << std::endl;

    return 0;
}
```

### 解釋：
- 此範例展示了如何建立兩個 `DoubleNode<int>` 物件並將它們鏈結在一起，形成一個雙向鏈結串列。
- 使用 `setPrev()` 方法為每個節點設置前一個節點的指標。
- 使用 `getPrev()` 方法來取得並顯示前一個節點。

---

## 潛在錯誤與邊界情況

1. **未初始化的指標**: 確保 `next` 和 `prev` 指標已正確初始化。如果建立 `DoubleNode` 時未明確設置 `prev` 指標，它將預設為 `nullptr`，但在使用指標之前應檢查其是否為空。

   範例檢查：
   ```cpp
   if (node.getPrev() != nullptr) {
       std::cout << "前一個節點資料: " << node.getPrev()->data << std::endl;
   }
   ```

2. **循環參考**: 在雙向鏈結串列形成迴圈的情況下（最後一個節點指向第一個節點），必須特別小心以避免在遍歷時產生無限迴圈。確保串列被正確管理，以防止循環參考，除非使用情境明確需要。

---

## 相依性

- **`Node.hpp`**: `DoubleNode` 類別繼承自 `Node<T>` 類別，因此請確保 `Node<T>` 類別已正確定義並包含用於鏈結節點的 `next` 指標。
- **C++ 標準函式庫**: 該類別依賴於標準 C++ 功能，如指標和建構函式。
