# `MaxHeap` 技術文件

## 概觀

`MaxHeap.hpp` 標頭文件定義了一個 `MaxHeap` 類別，這是一種特殊的二元樹，它維護堆積屬性（即每個父節點的值大於或等於其子節點的值）。此類別繼承自 `BinaryTree<T>` 類別，並提供插入和刪除元素的方法，同時透過 `heapify` 操作來維護堆積屬性。

`MaxHeap` 使用向量來儲存節點並保持層級順序，並且使用二元樹節點 (`BinaryTreeNode<T>`) 來管理結構。

---

## 主要元件

### `MaxHeap` 類別

`MaxHeap` 類別擴展了 `BinaryTree<T>` 類別，並提供了特定於最大堆積的額外方法和功能，如在添加或刪除元素時維護堆積屬性。

#### 成員變數：
- **`nodes`**：一個向量，按照層級順序儲存堆積的節點（即根節點位於索引 0，子節點儲存在後續的索引位置）。

#### 內部存儲輔助方法：
- **`getParent(int index)`**：返回堆積中指定索引位置的節點的父節點。
  
- **`GetNodeAtIndex(int index)`**：返回堆積中指定索引位置的節點。
  
- **`FindNextAvailableParent()`**：查找並返回下一個可用的父節點，以便插入新的子節點。

---

### 建構子與解構子

- **`MaxHeap(const T& rootData)`**：建構子，用來初始化一個具有指定根節點資料的最大堆積。它創建根節點並初始化 `nodes` 向量。

  範例：
  ```cpp
  MaxHeap<int> heap(10);  // 創建一個根節點資料為 10 的最大堆積
  ```

- **`~MaxHeap()`**：解構子，用來清理堆積並釋放節點佔用的記憶體。

  範例：
  ```cpp
  // 當物件超出作用範圍時，會自動清理堆積
  ```

---

### Push & Pop 方法

- **`void Push(const T& value)`**：將新值插入堆積，同時維護堆積屬性。該值被添加到下一個可用位置，並呼叫 `heapify_up` 方法來確保堆積屬性得到維護。

  範例：
  ```cpp
  heap.Push(15);  // 將值 15 插入最大堆積
  ```

- **`void Pop()`**：移除堆積中的最大元素（根節點）。堆積中的最後一個元素被移動到根節點位置，並呼叫 `heapify_down` 方法來恢復堆積屬性。

  範例：
  ```cpp
  heap.Pop();  // 移除最大元素（根節點）並調整堆積
  ```

---

### 維護堆積屬性的輔助方法

- **`void rebuildTreeLinks()`**：重建樹中節點的父子鏈結。此方法確保在修改後堆積結構仍然正確。

  範例：
  ```cpp
  heap.rebuildTreeLinks();  // 修改後重建樹的父子鏈結
  ```

- **`void heapify_up(int index)`**：這個方法透過將指定索引位置的節點向上移動，直到堆積屬性被滿足（即父節點大於子節點）。

  範例：
  ```cpp
  heap.heapify_up(3);  // 恢復索引為 3 的節點的堆積屬性
  ```

- **`void heapify_down(int index)`**：這個方法透過將指定索引位置的節點向下移動，直到堆積屬性被滿足（即父節點大於其子節點）。

  範例：
  ```cpp
  heap.heapify_down(0);  // 恢復根節點的堆積屬性
  ```

---

### 層級順序遍歷

- **`std::vector<BinaryTreeNode<T>*> LevelOrderIterator()`**：返回層級順序遍歷的節點向量，這是一個寬度優先的樹遍歷方法。此方法返回節點作為 `BinaryTreeNode<T>*` 指標。

  範例：
  ```cpp
  auto levelOrderNodes = heap.LevelOrderIterator();  // 獲取層級順序的節點
  ```

---

### 禁用的 `BinaryTree` 函式

`MaxHeap` 類別禁用了從 `BinaryTree` 類別繼承來的一些方法，這些方法在堆積中並不適用。這些方法已被刪除以防止誤用。

- **`void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) = delete;`**
- **`void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) = delete;`**
- **`void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right) = delete;`**
- **`void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left) = delete;`**

這些方法在堆積中未使用，因為堆積中的節點插入是通過不同的方式來維護堆積屬性的。

---

## 範例使用

以下是使用 `MaxHeap` 類別的範例：

```cpp
#include "MaxHeap.hpp"
#include <iostream>

int main() {
    // 創建一個初始值為 10 的最大堆積
    MaxHeap<int> heap(10);

    // 將元素插入堆積
    heap.Push(15);
    heap.Push(20);
    heap.Push(5);

    // 以層級順序顯示元素
    auto levelOrderNodes = heap.LevelOrderIterator();
    for (auto node : levelOrderNodes) {
        std::cout << node->getData() << " ";  // 輸出每個節點的資料
    }
    std::cout << std::endl;

    // 移除最大元素（根節點）
    heap.Pop();

    // 顯示移除根節點後的元素
    levelOrderNodes = heap.LevelOrderIterator();
    for (auto node : levelOrderNodes) {
        std::cout << node->getData() << " ";  // 輸出每個節點的資料
    }
    std::cout << std::endl;

    return 0;
}
```

### 說明：
- 程式展示了如何創建一個具有初始根節點值為 10 的 `MaxHeap`。
- 使用 `Push` 方法插入元素，並使用 `LevelOrderIterator` 方法以層級順序顯示堆積中的元素。
- 使用 `Pop` 方法移除最大元素（根節點），並再次顯示堆積的更新結構。

---

## 可能的錯誤與邊界情形

1. **堆積下溢**：對空堆積呼叫 `Pop()` 可能導致未定義行為。在嘗試移除元素之前，請確保堆積非空。考慮加入空檢查：
   
   範例：
   ```cpp
   if (!heap.IsEmpty()) {
       heap.Pop();
   }
   ```

2. **堆積屬性違反**：在修改堆積（插入或移除元素）後，確保適當呼叫 `heapify_up` 和 `heapify_down` 方法來恢復堆積屬性。

3. **堆積已滿**：雖然該類別並未明確處理大小調整，但它假設堆積可以根據需要擴展。如果堆積有固定大小或希望限制其成長，應實作防止在堆積已滿時添加元素的邏輯。

---

## 相依性

- **`BinaryTree.hpp`**：`MaxHeap` 類別繼承自 `BinaryTree<T>` 類別，請確保 `BinaryTree` 類別已正確定義並包含基本的樹操作（如添加和移除節點）。
- **`BinaryTreeNode.hpp`**：此檔案依賴 `BinaryTreeNode<T>` 來表示堆積中的個別節點。請確保 `BinaryTreeNode<T>` 類別正確定義，以管理節點資料和指標。
