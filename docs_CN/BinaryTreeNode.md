# `BinaryTreeNode.hpp` 文件說明

## 概觀

`BinaryTreeNode.hpp` 標頭文件定義了一個 `BinaryTreeNode` 類別模板，用於表示二元樹中的節點。該類別儲存型別為 `T` 的資料，並提供了多種方法來管理樹的結構，例如存取和修改子節點及父節點指標，以及進行相等比較。

---

## 主要元件

### `BinaryTreeNode` 類別

`BinaryTreeNode` 類別表示二元樹中的一個節點，儲存資料及指向該節點的左、右子節點、父節點和線結指標。線結指標在線結二元樹中用來表示空的子節點指標。

#### 成員變數：
- **`data`**：儲存在節點中的資料，型別為 `T`。
- **`leftChild`**：指向左子節點的指標。
- **`rightChild`**：指向右子節點的指標。
- **`parent`**：指向父節點的指標。
- **`leftthread`**：在線結二元樹中使用的指標，通常指向中序遍歷的前驅。
- **`rightthread`**：在線結二元樹中使用的指標，通常指向中序遍歷的後繼。

---

### 建構子與解構子

- **`BinaryTreeNode(const T& e)`**：建構子，使用資料 `e` 初始化一個節點。左子節點、右子節點、父節點和線結指標初始化為 `nullptr`。

  範例：
  ```cpp
  BinaryTreeNode<int> node(10);  // 創建一個資料為 10 的節點
  ```

- **`BinaryTreeNode(const T& e, BinaryTreeNode<T>* ptr_left, BinaryTreeNode<T>* ptr_right)`**：建構子，使用資料 `e` 初始化一個節點，並將左、右子節點設為指定的指標 `ptr_left` 和 `ptr_right`。

  範例：
  ```cpp
  BinaryTreeNode<int> node(10, leftNode, rightNode);  // 創建一個具有左、右子節點的節點
  ```

---

### 取得方法

- **`const T& getData() const`**：返回節點中儲存的資料。

  範例：
  ```cpp
  int data = node.getData();  // 取得節點的資料
  ```

- **`BinaryTreeNode<T>* getRightChild()`**：返回指向右子節點的指標。

  範例：
  ```cpp
  BinaryTreeNode<int>* right = node.getRightChild();  // 取得節點的右子節點
  ```

- **`BinaryTreeNode<T>* getLeftChild()`**：返回指向左子節點的指標。

  範例：
  ```cpp
  BinaryTreeNode<int>* left = node.getLeftChild();  // 取得節點的左子節點
  ```

- **`BinaryTreeNode<T>* getRightThread() const`**：返回右子節點的線結指標（如果使用在線結二元樹中）。

  範例：
  ```cpp
  BinaryTreeNode<int>* rightThread = node.getRightThread();  // 取得右線結指標
  ```

- **`BinaryTreeNode<T>* getLeftThread() const`**：返回左子節點的線結指標（如果使用在線結二元樹中）。

  範例：
  ```cpp
  BinaryTreeNode<int>* leftThread = node.getLeftThread();  // 取得左線結指標
  ```

- **`BinaryTreeNode<T>* getParent() const`**：返回指向父節點的指標。

  範例：
  ```cpp
  BinaryTreeNode<int>* parent = node.getParent();  // 取得節點的父節點
  ```

---

### 設定方法

- **`void setData(T in)`**：設定節點的資料為 `in`。

  範例：
  ```cpp
  node.setData(20);  // 設定節點的資料為 20
  ```

- **`void setParent(BinaryTreeNode<T>* in)`**：設定節點的父節點為 `in`。

  範例：
  ```cpp
  node.setParent(parentNode);  // 設定節點的父節點
  ```

- **`void setLeftChild(BinaryTreeNode<T>* in)`**：設定節點的左子節點為 `in`。

  範例：
  ```cpp
  node.setLeftChild(leftNode);  // 設定節點的左子節點
  ```

- **`void setRightChild(BinaryTreeNode<T>* in)`**：設定節點的右子節點為 `in`。

  範例：
  ```cpp
  node.setRightChild(rightNode);  // 設定節點的右子節點
  ```

---

### 線結指標方法

- **`void setLeftThread(BinaryTreeNode<T>* in)`**：設定左線結指標為 `in`。

  範例：
  ```cpp
  node.setLeftThread(leftThreadNode);  // 設定左線結指標
  ```

- **`void setRightThread(BinaryTreeNode<T>* in)`**：設定右線結指標為 `in`。

  範例：
  ```cpp
  node.setRightThread(rightThreadNode);  // 設定右線結指標
  ```

---

### 相等比較方法

- **`bool operator==(const BinaryTreeNode<T>& r) const`**：比較當前節點和另一個節點 `r` 的資料是否相等。

  範例：
  ```cpp
  bool areEqual = node == anotherNode;  // 檢查兩個節點是否相等
  ```

- **`bool operator!=(const BinaryTreeNode<T>& r) const`**：比較當前節點和另一個節點 `r` 的資料是否不相等。

  範例：
  ```cpp
  bool areNotEqual = node != anotherNode;  // 檢查兩個節點是否不相等
  ```

---

## 使用範例

以下是如何使用 `BinaryTreeNode` 類別的範例：

```cpp
#include "BinaryTreeNode.hpp"
#include <iostream>

int main() {
    // 創建一個資料為 10 的節點
    BinaryTreeNode<int> node(10);

    // 設定左、右子節點
    BinaryTreeNode<int> leftNode(5);
    BinaryTreeNode<int> rightNode(15);

    node.setLeftChild(&leftNode);  // 設定左子節點
    node.setRightChild(&rightNode);  // 設定右子節點

    // 取得並輸出節點的資料
    std::cout << "Node data: " << node.getData() << std::endl;

    // 取得左、右子節點並輸出其資料
    std::cout << "Left child data: " << node.getLeftChild()->getData() << std::endl;
    std::cout << "Right child data: " << node.getRightChild()->getData() << std::endl;

    // 設定左子節點的父節點並輸出父節點的資料
    leftNode.setParent(&node);
    std::cout << "Parent of left child: " << leftNode.getParent()->getData() << std::endl;

    return 0;
}
```

### 說明：
- 此範例程式碼創建了一個 `BinaryTreeNode` 節點，資料為 `10`，並設置其左、右子節點。
- 它展示了如何透過設定器和取得器方法存取和修改節點資料，並處理父子節點關係。

---

## 可能的錯誤與邊界情形

1. **空指標**：在存取子節點、父節點或線結指標時，確保指標不是 `nullptr`，以免解引用空指標。若有需要，檢查是否為 `nullptr` 並適當處理。

   範例：
   ```cpp
   if (node.getLeftChild() != nullptr) {
       std::cout << "Left child data: " << node.getLeftChild()->getData() << std::endl;
   }
   ```

2. **線結指標誤用**：在使用線結二元樹時，確保線結指標正確設置，否則可能會導致未定義行為。

3. **相等比較**：相等運算子（`==`、`!=`）僅比較節點的資料。若應用程式需要更全面的比較（例如，檢查子節點或線結指標），可能需要相應修改相等運算子。

---

## 相依性

- **C++ 標準函式庫**：此檔案使用了基本的 C++ 函式庫特性，如 `iostream` 用於輸出，`std::nullptr_t` 用於處理空指標。
- **`BinaryTree.hpp`**：此檔案假設 `BinaryTree` 類別已定義並包含了管理樹結構的功能，如遍歷或根節點管理。
