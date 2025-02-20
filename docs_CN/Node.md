# `Node.hpp` 文件說明

## 概觀

`Node.hpp` 標頭文件定義了一個模板類別 `Node`，該類別代表單向鏈結串列中的一個節點。每個節點包含資料和指向下一個節點的指標。此類別提供創建、存取和修改節點的基本功能，這些功能是鏈結串列資料結構的基礎構建塊。

## 類別：`Node<T>`

### 說明
`Node<T>` 類別是一個模板類別，代表單向鏈結串列中的一個節點。它儲存型別為 `T` 的資料，並包含指向鏈結串列中下一個節點的指標。

### 模板參數
- `T`：儲存在節點中的資料型別。

### 建構子與解構子

#### `Node()`
- **說明**：預設建構子。初始化節點並設置默認值（資料為默認初始化，指標設為 `nullptr`）。
- **使用範例**：
  ```cpp
  Node<int> node;
  ```

#### `Node(const T& item, Node<T>* next)`
- **說明**：建構子。使用指定的資料和指向下一個節點的指標初始化節點。
- **參數**：
  - `item`：要儲存在節點中的資料。
  - `next`：指向下一個節點的指標。
- **使用範例**：
  ```cpp
  Node<int>* nextNode = new Node<int>(20, nullptr);
  Node<int> node(10, nextNode);
  ```

#### `~Node()`
- **說明**：解構子。清理節點。請注意，這不會自動刪除鏈結串列中的下一個節點。
- **使用範例**：當物件超出作用範圍時，會自動呼叫此解構子。

### 存取方法

#### `const T& getData() const`
- **說明**：返回儲存在節點中的資料。
- **回傳值**：返回資料的常數引用（型別 `T`）。
- **使用範例**：
  ```cpp
  Node<int> node(10, nullptr);
  int data = node.getData();  // data 為 10
  ```

#### `Node<T>* getLink() const`
- **說明**：返回指向鏈結串列中下一個節點的指標。
- **回傳值**：指向下一個 `Node<T>` 節點的指標。
- **使用範例**：
  ```cpp
  Node<int>* nextNode = new Node<int>(20, nullptr);
  Node<int> node(10, nextNode);
  Node<int>* link = node.getLink();  // link 指向 nextNode
  ```

### 設定方法

#### `void setData(const T& item)`
- **說明**：設定儲存在節點中的資料。
- **參數**：
  - `item`：要儲存的新資料。
- **使用範例**：
  ```cpp
  Node<int> node(10, nullptr);
  node.setData(20);  // 節點現在儲存資料 20
  ```

#### `void setLink(Node<T>* next)`
- **說明**：設定指向鏈結串列中下一個節點的指標。
- **參數**：
  - `next`：指向下一個節點的指標。
- **使用範例**：
  ```cpp
  Node<int>* nextNode = new Node<int>(20, nullptr);
  Node<int> node(10, nullptr);
  node.setLink(nextNode);  // 節點現在指向 nextNode
  ```

## 範例使用

```cpp
#include "Node.hpp"
#include <iostream>

int main() {
    // 創建節點
    Node<int>* node3 = new Node<int>(30, nullptr);
    Node<int>* node2 = new Node<int>(20, node3);
    Node<int>* node1 = new Node<int>(10, node2);

    // 遍歷鏈結串列
    Node<int>* current = node1;
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getLink();
    }
    std::cout << std::endl;

    // 修改節點
    node2->setData(25);
    std::cout << "修改後的 node2 資料: " << node2->getData() << std::endl;

    // 清理
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
```

## 可能的錯誤與邊界情形

1. **空指標解引用**：當使用 `getLink()` 或 `setLink(Node<T>*)` 時，請確保指標不為 `nullptr`，以避免在解引用時發生運行時錯誤。
2. **記憶體洩漏**：當動態配置節點（例如使用 `new`）時，請確保適當刪除節點，以避免記憶體洩漏。
3. **資料型別不匹配**：確保節點中使用的資料型別 `T` 與您打算儲存的資料型別匹配，因為不匹配的型別可能會導致編譯錯誤或未定義行為。

## 相依性

- **標準函式庫**：該標頭文件匯入了 `<iostream>` 和 `<string>`，這是 C++ 標準函式庫的一部分。請確保您的環境已正確配置以使用標準函式庫。

## 摘要

`Node.hpp` 文件提供了一個簡單且靈活的單向鏈結串列節點實作。它設計上便於整合到更大的資料結構中，例如鏈結串列、堆疊或佇列。透過提供的範例和指引，您可以有效地使用此類別來建立並操作鏈結串列。
