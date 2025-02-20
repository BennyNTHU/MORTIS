# `BinarySearchTree` 技術文件

## 概觀

`BinarySearchTree.hpp` 文件定義了一個模板化的 `BinarySearchTree` 類別，該類別是 `BinaryTree` 類別的專用子類別。此類別專為二元搜尋樹（BST）操作設計，支援搜尋、插入、刪除及進階操作，如合併和拆分兩個 BST。它確保樹保持根據 BST 特性排序（即左子樹 < 父節點 < 右子樹）。

---

## 主要元件

### `BinarySearchTree` 類別

`BinarySearchTree` 類別繼承自 `BinaryTree<T>` 類別，並新增了特定於二元搜尋樹的方法，如 `Insert`、`Delete`、`RankGet` 等。

#### 成員變數：
- **`rootData`**：二元搜尋樹的根節點值。
- **`BinaryTree` 成員**：從 `BinaryTree` 類別繼承，這些成員處理樹的結構，包括根節點及其子節點。

---

### 建構子與解構子

- **`BinarySearchTree(const T& rootData)`**：建構子，根據指定的初始值 `rootData` 創建一個二元搜尋樹。

  範例：
  ```cpp
  BinarySearchTree<int> bst(10);  // 創建根值為 10 的 BST
  ```

- **`~BinarySearchTree()`**：解構子，清理二元搜尋樹並釋放節點佔用的記憶體。

  範例：
  ```cpp
  // 當 BST 超出作用範圍時會自動清理
  ```

---

### 搜尋方法

- **`T* Get(const T& key) const`**：在 BST 中搜尋給定的 `key`。若找到，則返回該值的副本指標；若未找到，則返回 `nullptr`。

  範例：
  ```cpp
  int* result = bst.Get(5);  // 搜尋 5 是否在 BST 中
  if (result) {
      std::cout << "找到: " << *result << std::endl;
  } else {
      std::cout << "未找到。" << std::endl;
  }
  ```

- **`T RankGet(int r) const`**：返回 BST 中以中序遍歷為基準，指定排名 `r`（0 索引）處的元素。此方法可用來獲取第 `r` 小的元素。

  範例：
  ```cpp
  int rankValue = bst.RankGet(2);  // 獲取 BST 中的第 2 小元素
  std::cout << "排名 2 的元素: " << rankValue << std::endl;
  ```

---

### 操作方法

- **`void Insert(const T& value)`**：將給定的 `value` 插入 BST 中。如果該值已存在，則更新該節點的值。

  範例：
  ```cpp
  bst.Insert(15);  // 將 15 插入 BST
  bst.Insert(7);   // 將 7 插入 BST
  ```

- **`void Delete(const T& key)`**：刪除 BST 中具有指定 `key` 的節點。

  範例：
  ```cpp
  bst.Delete(10);  // 刪除值為 10 的節點
  ```

- **`BinarySearchTree<T> JoinBST(const BinarySearchTree<T>& bst1, const BinarySearchTree<T>& bst2)`**：將兩個二元搜尋樹合併為一個 BST，結果樹將包含 `bst1` 和 `bst2` 的所有節點。

  範例：
  ```cpp
  BinarySearchTree<int> bst1(10);
  BinarySearchTree<int> bst2(20);
  BinarySearchTree<int> joinedTree = bst1.JoinBST(bst1, bst2);  // 合併 bst1 和 bst2
  ```

- **`std::vector<BinarySearchTree<T>> SplitBST(const BinarySearchTree<T>& bst, const T& key)`**：根據給定的 `key` 將 BST 拆分成兩個子樹，左子樹包含小於 `key` 的值，右子樹包含大於 `key` 的值。

  範例：
  ```cpp
  std::vector<BinarySearchTree<int>> splitTrees = bst.SplitBST(bst, 10);  // 根據鍵值 10 拆分 bst
  ```

---

### 禁用的 `BinaryTree` 方法

- **`void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right) = delete`**
- **`void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left) = delete`**
- **`void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right) = delete`**
- **`void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left) = delete`**

這些方法被禁用，因為它們對二元搜尋樹不適用。在二元搜尋樹中，節點的插入是通過保持二元搜尋樹屬性來進行的，而不是隨意插入左或右子樹。

---

## 使用範例

以下是示範如何使用 `BinarySearchTree` 類別的範例：

```cpp
#include "BinarySearchTree.hpp"
#include <iostream>

int main() {
    // 創建根值為 10 的 BST
    BinarySearchTree<int> bst(10);

    // 向 BST 插入元素
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(7);

    // 搜尋一個元素
    int* searchResult = bst.Get(7);  // 搜尋 7
    if (searchResult) {
        std::cout << "找到: " << *searchResult << std::endl;
    } else {
        std::cout << "未找到。" << std::endl;
    }

    // 獲取中序遍歷排名為 2 的元素
    int rankValue = bst.RankGet(2);  // 應返回 7（第 2 小元素）
    std::cout << "排名 2 的元素: " << rankValue << std::endl;

    // 刪除一個節點
    bst.Delete(5);  // 刪除值為 5 的節點

    // 刪除後顯示結果
    searchResult = bst.Get(5);
    std::cout << "刪除後: " << (searchResult ? "找到" : "未找到") << std::endl;

    return 0;
}
```

### 說明：
- 此程式碼創建了一個 `BinarySearchTree` 來儲存整數，並插入多個元素，演示了搜尋和排名檢索功能。
- 也展示了如何刪除樹中的節點，並通過檢查已刪除的節點來驗證刪除操作。

---

## 可能的錯誤與邊界情形

1. **搜尋不存在的元素**：若 `Get()` 方法未找到元素，它會返回 `nullptr`。請務必檢查返回值以避免解引用空指標。

   範例：
   ```cpp
   int* result = bst.Get(100);  // 搜尋不存在的元素
   if (result == nullptr) {
       std::cout << "元素未找到！" << std::endl;
   }
   ```

2. **無效排名的 `RankGet`**：`RankGet()` 函數假設提供的排名是有效的。如果提供無效的排名（例如超出樹的範圍），可能會導致未定義行為。應確保排名在有效範圍內。

   範例：
   ```cpp
   if (rank >= 0 && rank < bst.Size()) {
       bst.RankGet(rank);
   }
   ```

3. **空樹的邊界情形**：若在空樹上呼叫 `Get()`、`RankGet()` 或 `Delete()` 等方法，請確保這些方法能正確處理並避免錯誤。

4. **重複元素**：`Insert()` 方法處理重複元素，會更新已存在的節點。如果應用程式需要更嚴格的重複處理（例如不允許重複），可能需要相應修改 `Insert()` 方法。

---

## 相依性

- **`BinaryTree.hpp`**：`BinarySearchTree` 類別繼承自 `BinaryTree<T>` 類別，請確保正確實作 `BinaryTree` 類別。
- **`BinaryTreeNode.hpp`**：每個二元搜尋樹中的節點由 `BinaryTreeNode` 物件表示，請確保 `BinaryTreeNode<T>` 類別正確定義，並可用來管理樹節點。
