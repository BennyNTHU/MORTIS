# `DLIterator.hpp` 文件說明

## 概觀

`DLIterator.hpp` 標頭文件定義了一個模板類別 `DLIterator`，用於遍歷雙向鏈結串列。此類別繼承自 `ChainIterator`，並提供了向前和向後遍歷鏈表的功能，以及存取當前節點的方法。

## 類別：`DLIterator<T>`

### 說明
`DLIterator<T>` 類別是一個模板類別，表示一個雙向鏈結串列的迭代器。它提供了在鏈表中向前和向後遍歷的功能，並可以存取當前節點。

### 模板參數
- `T`：儲存在節點中的元素型別。

### 建構子

#### `DLIterator(DoubleNode<T>* startNode = nullptr)`
- **說明**：建構子，初始化迭代器，指向起始節點。
- **參數**：
  - `startNode`：指向 `DoubleNode<T>` 的指標，指定迭代器的起始位置。預設為 `nullptr`。
- **使用範例**：
  ```cpp
  DoubleNode<int>* node = new DoubleNode<int>(10);
  DLIterator<int> it(node);
  ```

### 移動運算子

#### `DLIterator<T>& operator++()`
- **說明**：前遞增運算子，將迭代器移動到鏈表中的下一個節點。
- **回傳值**：更新後的迭代器參考。
- **使用範例**：
  ```cpp
  DLIterator<int> it(node);
  ++it;  // 移動到下一個節點
  ```

#### `ChainIterator<T> operator++(int)`
- **說明**：後遞增運算子，將迭代器移動到鏈表中的下一個節點，並返回遞增之前的迭代器狀態。
- **回傳值**：表示遞增前的 `ChainIterator<T>` 物件。
- **使用範例**：
  ```cpp
  DLIterator<int> it(node);
  it++;  // 移動到下一個節點，並返回遞增前的狀態
  ```

#### `DLIterator<T>& operator--()`
- **說明**：前遞減運算子，將迭代器移動到鏈表中的前一個節點。
- **回傳值**：更新後的迭代器參考。
- **使用範例**：
  ```cpp
  DLIterator<int> it(node);
  --it;  // 移動到前一個節點
  ```

#### `DLIterator<T> operator--(int)`
- **說明**：後遞減運算子，將迭代器移動到鏈表中的前一個節點，並返回遞減前的迭代器狀態。
- **回傳值**：表示遞減前的 `DLIterator<T>` 物件。
- **使用範例**：
  ```cpp
  DLIterator<int> it(node);
  it--;  // 移動到前一個節點，並返回遞減前的狀態
  ```

### 取得當前節點

#### `DoubleNode<T>* getCurrent() const`
- **說明**：返回指向當前節點的指標。
- **回傳值**：指向當前 `DoubleNode<T>` 節點的指標。
- **使用範例**：
  ```cpp
  DLIterator<int> it(node);
  DoubleNode<int>* currentNode = it.getCurrent();
  ```

## 使用範例

```cpp
#include "DLIterator.hpp"
#include "DoubleNode.hpp"
#include <iostream>

int main() {
    DoubleNode<int>* node1 = new DoubleNode<int>(10);
    DoubleNode<int>* node2 = new DoubleNode<int>(20);
    DoubleNode<int>* node3 = new DoubleNode<int>(30);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;

    DLIterator<int> it(node1);

    std::cout << "Current node: " << it.getCurrent()->data << std::endl;  // 輸出: 10
    ++it;
    std::cout << "Next node: " << it.getCurrent()->data << std::endl;     // 輸出: 20
    --it;
    std::cout << "Previous node: " << it.getCurrent()->data << std::endl; // 輸出: 10

    delete node1;
    delete node2;
    delete node3;

    return 0;
}
```

### 說明：
- 程式碼創建了一個包含三個節點的雙向鏈結串列，每個節點都包含一個整數資料。
- 使用 `DLIterator<int>` 來遍歷鏈結串列並顯示每個節點的資料。`operator++` 用來移動到下一個節點，`operator--` 用來移動到前一個節點。

---

## 可能的錯誤與邊界情形

1. **空指標**：如果迭代器初始化為 `nullptr`，則呼叫 `operator++` 或 `operator--` 會導致未定義行為。確保迭代器初始化時指向有效節點。
2. **鏈表結尾**：如果迭代器已達鏈表的結尾（即 `current->next` 為 `nullptr`），呼叫 `operator++` 會導致未定義行為。類似地，如果迭代器位於鏈表的開頭（即 `current->prev` 為 `nullptr`），呼叫 `operator--` 也會導致未定義行為。移動迭代器之前請確保檢查邊界。
3. **記憶體管理**：在處理節點時確保正確的記憶體管理，以避免記憶體洩漏。

## 相依性

- **`DoubleNode.hpp`**：定義鏈結串列中使用的節點結構。
- **`ChainIterator.hpp`**：此迭代器功能的基類。
