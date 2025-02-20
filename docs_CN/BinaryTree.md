# `BinaryTree.hpp` 文件說明

## 概觀

`BinaryTree.hpp` 標頭文件定義了一個模板類別 `BinaryTree`，實作了二元樹資料結構。二元樹是一種階層資料結構，每個節點最多有兩個子節點，分別為左子節點和右子節點。本實作提供了用於樹的操作、遍歷及查詢樹的特性（如高度、平衡性和完全性）的方法。

## 類別：`BinaryTree<T>`

### 說明
`BinaryTree<T>` 類別是一個模板類別，表示一個二元樹。它提供了插入、刪除和遍歷節點的方法，並支援查詢樹的特性。

### 模板參數
- `T`：樹中節點儲存的資料型別。

### 建構子與解構子

#### `BinaryTree()`
- **說明**：預設建構子，初始化為一個空的二元樹。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree;
  ```

#### `BinaryTree(const T& rootData)`
- **說明**：建構子，初始化一個根節點資料為指定值的二元樹。
- **參數**：
  - `rootData`：根節點要儲存的資料。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);  // 創建一個根值為 10 的二元樹
  ```

#### `BinaryTree(const BinaryTree<T>& bt)`
- **說明**：複製建構子，通過複製另一個二元樹來初始化新樹。
- **參數**：
  - `bt`：要複製的 `BinaryTree` 物件。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(tree1);  // tree2 是 tree1 的複本
  ```

#### `~BinaryTree()`
- **說明**：解構子，清理二元樹並刪除所有節點。
- **使用方式**：當物件超出作用範圍時，自動呼叫。

### 方法

#### `void Clear()`
- **說明**：清空樹（刪除所有節點），並重設根指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.Clear();  // 樹現在為空
  ```

### 取得方法

#### `T RootData()`
- **說明**：返回樹根節點的資料。
- **回傳值**：樹根節點儲存的資料，型別為 `T`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  int rootData = tree.RootData();  // rootData 為 10
  ```

#### `BinaryTreeNode<T>* getRoot() const`
- **說明**：返回指向樹根節點的指標。
- **回傳值**：指向樹根 `BinaryTreeNode<T>` 的指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  BinaryTreeNode<int>* root = tree.getRoot();  // root 指向根節點
  ```

#### `BinaryTree<T>* LeftSubtree()`
- **說明**：返回樹的左子樹。
- **回傳值**：指向左子樹的指標，型別為 `BinaryTree<T>`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  BinaryTree<int>* leftSubtree = tree.LeftSubtree();  // leftSubtree 指向左子樹
  ```

#### `BinaryTree<T>* RightSubtree()`
- **說明**：返回樹的右子樹。
- **回傳值**：指向右子樹的指標，型別為 `BinaryTree<T>`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertRight(tree.getRoot(), new BinaryTreeNode<int>(15));
  BinaryTree<int>* rightSubtree = tree.RightSubtree();  // rightSubtree 指向右子樹
  ```

### 設定方法

#### `void set_root(BinaryTreeNode<T>* node)`
- **說明**：設定樹的根節點並更新相應的鏈結。
- **參數**：
  - `node`：指向要設為根的 `BinaryTreeNode<T>` 的指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree;
  tree.set_root(new BinaryTreeNode<int>(10));  // 設定根節點為 10
  ```

### 插入方法

#### `void InsertRight(BinaryTreeNode<T>* node, BinaryTreeNode<T>* right)`
- **說明**：為指定節點插入右子節點。
- **參數**：
  - `node`：指向要插入右子節點的節點的指標。
  - `right`：指向要插入為右子節點的 `BinaryTreeNode<T>` 的指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertRight(tree.getRoot(), new BinaryTreeNode<int>(15));  // 插入 15 作為根的右子節點
  ```

#### `void InsertLeft(BinaryTreeNode<T>* node, BinaryTreeNode<T>* left)`
- **說明**：為指定節點插入左子節點。
- **參數**：
  - `node`：指向要插入左子節點的節點的指標。
  - `left`：指向要插入為左子節點的 `BinaryTreeNode<T>` 的指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));  // 插入 5 作為根的左子節點
  ```

#### `void InsertRightSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* right)`
- **說明**：為指定節點插入右子樹。
- **參數**：
  - `node`：指向要插入右子樹的節點的指標。
  - `right`：指向要插入為右子樹的 `BinaryTree<T>` 的指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  BinaryTree<int> rightSubtree(15);
  tree.InsertRightSubtree(tree.getRoot(), &rightSubtree);  // 插入右子樹
  ```

#### `void InsertLeftSubtree(BinaryTreeNode<T>* node, BinaryTree<T>* left)`
- **說明**：為指定節點插入左子樹。
- **參數**：
  - `node`：指向要插入左子樹的節點的指標。
  - `left`：指向要插入為左子樹的 `BinaryTree<T>` 的指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  BinaryTree<int> leftSubtree(5);
  tree.InsertLeftSubtree(tree.getRoot(), &leftSubtree);  // 插入左子樹
  ```

### 刪除方法

#### `void delete_subtree(BinaryTreeNode<T>* node)`
- **說明**：刪除子樹（包括指定的節點）。
- **參數**：
  - `node`：指向要刪除的子樹根節點的指標。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  tree.delete_subtree(tree.getRoot()->left);  // 刪除左子樹
  ```

### 特性

#### `bool isFull()`
- **說明**：檢查二元樹是否為滿樹（每個節點都只有 0 或 2 個子節點）。
- **回傳值**：如果樹是滿樹，則返回 `true`，否則返回 `false`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  bool full = tree.isFull();  // full 為 false（根節點只有一個子節點）
  ```

#### `bool IsEmpty() const`
- **說明**：檢查二元樹是否為空。
- **回傳值**：如果樹為空，則返回 `true`，否則返回 `false`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree;
  bool empty = tree.IsEmpty();  // empty 為 true
  ```

#### `bool isBalanced()`
- **說明**：檢查二元樹是否為平衡樹（每個節點的左右子樹高度差不超過 1）。
- **回傳值**：如果樹是平衡的，則返回 `true`，否則返回 `false`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  bool balanced = tree.isBalanced();  // balanced 為 true
  ```

#### `bool isComplete()`
- **說明**：檢查二元樹是否為完全樹（所有層級完全填滿，最後一層從左到右填滿）。
- **回傳值**：如果樹是完全的，則返回 `true`，否則返回 `false`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  bool complete = tree.isComplete();  // complete 為 true
  ```

#### `int CountNodes() const`
- **說明**：計算二元樹中的節點數量。
- **回傳值**：節點數量。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  int nodeCount = tree.CountNodes();  // nodeCount 為 2
  ```

#### `int Height()`
- **說明**：返回二元樹的高度（從根到葉節點的最長路徑上的邊數）。
- **回傳值**：樹的高度。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  int height = tree.Height();  // height 為 1
  ```

### 其他函式

#### `BinaryTreeNode<T>* Find(const T& value) const`
- **說明**：搜尋是否有節點包含給定的資料值。
- **參數**：
  - `value`：要搜尋的資料值。
- **回傳值**：如果找到，返回指向 `BinaryTreeNode<T>` 的指標，否則返回 `nullptr`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  BinaryTreeNode<int>* node = tree.Find(5);  // node 指向包含 5 的節點
  ```

#### `bool root_equal(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2)`
- **說明**：檢查兩個二元樹的根節點是否相等。
- **參數**：
  - `root1`：第一顆樹的根節點。
  - `root2`：第二顆樹的根節點。
- **回傳值**：如果根節點相等，返回 `true`，否則返回 `false`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(10);
  bool equal = tree1.root_equal(tree1.getRoot(), tree2.getRoot());  // equal 為 true
  ```

### 運算子重載

#### `BinaryTree<T>& operator=(const BinaryTree<T>& other)`
- **說明**：賦值運算子，執行二元樹的深層複製。
- **參數**：
  - `other`：要複製的 `BinaryTree`。
- **回傳值**：返回當前二元樹的參考。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2;
  tree2 = tree1;  // tree2 現在是 tree1 的複本
  ```

#### `bool operator==(const BinaryTree<T>& bt)`
- **說明**：等號運算子，檢查兩個二元樹是否相等。
- **參數**：
  - `bt`：要比較的 `BinaryTree`。
- **回傳值**：如果兩顆樹相等，返回 `true`，否則返回 `false`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(10);
  bool equal = (tree1 == tree2);  // equal 為 true
  ```

#### `bool operator!=(const BinaryTree& bt)`
- **說明**：不等號運算子，檢查兩個二元樹是否不相等。
- **參數**：
  - `bt`：要比較的 `BinaryTree`。
- **回傳值**：如果兩顆樹不相等，返回 `true`，否則返回 `false`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree1(10);
  BinaryTree<int> tree2(15);
  bool notEqual = (tree1 != tree2);  // notEqual 為 true
  ```

#### `template <typename U> friend ostream& operator<<(ostream& os, const BinaryTree<U>& bt)`
- **說明**：重載 `<<` 運算子，用於輸出二元樹。
- **參數**：
  - `os`：輸出流。
  - `bt`：要輸出的 `BinaryTree`。
- **回傳值**：輸出流。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  std::cout << tree;  // 輸出二元樹
  ```

### 遍歷方法

#### `vector<T> PreOrderIterator()`
- **說明**：返回二元樹的前序遍歷結果。
- **回傳值**：包含前序遍歷結果的 `vector<T>`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> preOrder = tree.PreOrderIterator();  // preOrder 包含 {10, 5}
  ```

#### `vector<T> PostOrderIterator()`
- **說明**：返回二元樹的後序遍歷結果。
- **回傳值**：包含後序遍歷結果的 `vector<T>`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> postOrder = tree.PostOrderIterator();  // postOrder 包含 {5, 10}
  ```

#### `vector<T> InorderIterator()`
- **說明**：返回二元樹的中序遍歷結果。
- **回傳值**：包含中序遍歷結果的 `vector<T>`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> inOrder = tree.InorderIterator();  // inOrder 包含 {5, 10}
  ```

#### `vector<T> LevelOrderIterator()`
- **說明**：返回二元樹的層級遍歷結果。
- **回傳值**：包含層級遍歷結果的 `vector<T>`。
- **使用方式**：
  ```cpp
  BinaryTree<int> tree(10);
  tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
  vector<int> levelOrder = tree.LevelOrderIterator();  // levelOrder 包含 {10, 5}
  ```

## 使用範例

```cpp
#include "BinaryTree.hpp"
#include <iostream>

int main() {
    // 創建一顆根節點為 10 的二元樹
    BinaryTree<int> tree(10);

    // 插入左子節點和右子節點
    tree.InsertLeft(tree.getRoot(), new BinaryTreeNode<int>(5));
    tree.InsertRight(tree.getRoot(), new BinaryTreeNode<int>(15));

    // 輸出樹
    std::cout << "Tree: " << tree << std::endl;

    // 檢查樹的特性
    std::cout << "Is full: " << std::boolalpha << tree.isFull() << std::endl;
    std::cout << "Is balanced: " << std::boolalpha << tree.isBalanced() << std::endl;
    std::cout << "Height: " << tree.Height() << std::endl;

    // 遍歷樹
    vector<int> preOrder = tree.PreOrderIterator();
    std::cout

 << "Pre-order traversal: ";
    for (int val : preOrder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## 可能的錯誤與邊界情形

1. **空指標**：插入或刪除節點時，確保節點指標有效（非 `nullptr`）。無效的指標可能導致運行時錯誤。
2. **記憶體管理**：當動態配置節點時，請確保正確清理以避免記憶體泄漏。
3. **空樹操作**：在空樹上執行像 `RootData()` 或 `Height()` 等操作，可能導致未定義的行為。請確保在執行這些操作之前，樹不是空的。

## 相依性

- **BinaryTreeNode.hpp**：`BinaryTree` 類別使用 `BinaryTreeNode` 來表示樹中的節點。請確保此檔案已正確包含並配置於您的專案中。
- **標準函式庫**：該標頭文件包含 `<iostream>` 和 `<vector>`，這些是 C++ 標準函式庫的一部分。請確保您的開發環境能正確使用標準函式庫。

## 摘要

`BinaryTree.hpp` 文件提供了靈活的二元樹資料結構實作，支援插入、刪除、遍歷和屬性查詢。通過遵循提供的範例和指南，您可以在專案中有效使用此類別來建立和操作二元樹。
