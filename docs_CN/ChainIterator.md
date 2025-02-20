# `ChainIterator.hpp` 文件說明

## 概觀

`ChainIterator.hpp` 標頭文件定義了一個模板類別 `ChainIterator`，用於遍歷鏈結串列結構，其中每個元素都儲存在 `Node<T>` 中。此迭代器支援常見操作，如解引用、遞增和相等比較，方便用於遍歷節點的鏈結（鏈結串列）。

---

## 主要元件

### `ChainIterator` 類別

`ChainIterator` 類別模板設計用於遍歷鏈結串列（或鏈結）的節點。它提供了方法來在列表中移動並存取每個節點中的資料。

#### 成員變數：
- **`current`**：指向鏈結中當前節點的指標，即此迭代器目前指向的節點。

#### 建構子：
- **`ChainIterator(Node<T>* startNode = nullptr)`**：建構子，初始化迭代器，指向提供的起始節點。如果未提供節點，則將迭代器初始化為 `nullptr`。

#### 取得方法：
- **`getCurrent()`**：返回指向當前節點的指標。

  範例：
  ```cpp
  Node<int>* currentNode = iterator.getCurrent();
  ```

#### 解引用運算子：
- **`operator*()`**：解引用此迭代器，並返回當前節點資料的常數參考。
  
  範例：
  ```cpp
  const int& value = *iterator;  // 存取當前節點的資料
  ```

- **`operator->()`**：返回指向當前節點的指標，允許直接存取節點的成員。
  
  範例：
  ```cpp
  const Node<int>* nodePtr = iterator.operator->();  // 存取節點的屬性
  ```

#### 遞增運算子：
- **`operator++()`**：前遞增運算子，將迭代器移動到鏈結中的下一個節點。

  範例：
  ```cpp
  ++iterator;  // 移動到下一個節點
  ```

- **`operator++(int)`**：後遞增運算子，將迭代器移動到下一個節點，但在遞增之前返回當前迭代器。
  
  範例：
  ```cpp
  iterator++;  // 移動到下一個節點，但返回當前節點
  ```

#### 相等與不相等運算子：
- **`operator!=(const ChainIterator<T>& r)`**：檢查當前迭代器是否與提供的迭代器不相等，意味著它們不指向同一個節點。
  
  範例：
  ```cpp
  if (iterator != anotherIterator) {
      // 做一些處理
  }
  ```

- **`operator==(const ChainIterator<T>& r)`**：檢查當前迭代器是否與提供的迭代器相等，意味著它們指向同一個節點。
  
  範例：
  ```cpp
  if (iterator == anotherIterator) {
      // 做一些處理
  }
  ```

---

## 使用範例

以下是示範如何使用 `ChainIterator` 類別來遍歷 `Node<T>` 類型的鏈結串列。

```cpp
#include "ChainIterator.hpp"
#include "Node.hpp"

int main() {
    // 創建一個簡單的整數鏈結串列
    Node<int> node1(10);  // 資料為 10 的節點
    Node<int> node2(20);  // 資料為 20 的節點
    Node<int> node3(30);  // 資料為 30 的節點

    node1.next = &node2;
    node2.next = &node3;
    node3.next = nullptr;

    // 創建一個 ChainIterator 用來遍歷鏈結串列
    ChainIterator<int> iterator(&node1);

    // 遍歷鏈結串列
    while (iterator != ChainIterator<int>()) {
        std::cout << *iterator << std::endl;  // 解引用以取得資料
        ++iterator;  // 移動到下一個節點
    }

    return 0;
}
```

### 說明：
- 創建了一個包含三個節點的 `Node<int>` 鏈結串列，每個節點都包含一個整數資料。
- 創建了一個 `ChainIterator<int>` 來指向鏈結串列的第一個節點。
- 使用 `operator!=` 來遍歷鏈結串列，並列印每個節點的資料，`operator++` 用來移動到下一個節點。

---

## 可能的錯誤與邊界情形

1. **空指標解引用**：如果迭代器指向空節點（`nullptr`），解引用它將導致未定義行為。確保在解引用之前，迭代器不是空的。
   
   解引用前的檢查範例：
   ```cpp
   if (iterator.getCurrent() != nullptr) {
       std::cout << *iterator << std::endl;
   }
   ```

2. **無窮迴圈**：如果鏈結串列中存在迴圈（某個節點指向之前的節點），迭代器可能會進入無窮迴圈。請確保鏈結串列結構是無循環的，或在迭代時加入防止無窮迴圈的邏輯。

3. **未初始化的迭代器**：如果迭代器未正確初始化為有效的節點，存取或使用它可能會導致意外的結果。確保迭代器已正確初始化，並指向有效的節點或 `nullptr`。

---

## 相依性

- **`Node.hpp`**：`ChainIterator` 類別依賴 `Node<T>` 類別來定義鏈結串列的結構。確保 `Node<T>` 類別已正確定義，並包含一個 `next` 指標來將節點鏈結起來。
  
- **C++ 標準函式庫**：此類別使用 `<iostream>` 和 `<cstring>` 來進行標準輸入/輸出和字串處理。
