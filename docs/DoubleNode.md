# DoubleNode 類別使用手冊

## 簡介
`DoubleNode<T>` 是雙向鏈結串列的節點類別，繼承自 `Node<T>`，並額外提供指向前一個節點的指標。

## 類別定義
```cpp
template <typename T>
class DoubleNode : public Node<T> {
public:
    DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr);
    void setPrev(DoubleNode<T>* prev);
    DoubleNode<T>* getPrev() const;
};
```

## **函式說明**
### `DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr)`
- **功能**：建立一個雙向鏈結節點，存放 `item`，並可指定 `next` 及 `prev`。
- **參數**：
  - `item`：節點存放的資料。
  - `next`：指向下一個節點的指標（預設為 `nullptr`）。
  - `prev`：指向前一個節點的指標（預設為 `nullptr`）。

### `void setPrev(DoubleNode<T>* prev)`
- **功能**：設定節點的前一個節點指標。
- **參數**：
  - `prev`：指向前一個節點的指標。

### `DoubleNode<T>* getPrev() const`
- **功能**：取得指向前一個節點的指標。
- **回傳**：
  - 指向前一個節點的指標，若無則回傳 `nullptr`。

## **範例**
```cpp
#include "DoubleNode.hpp"
#include <iostream>

int main() {
    DoubleNode<int> node1(10);
    DoubleNode<int> node2(20, nullptr, &node1);
    node1.setNext(&node2);  // 設定 node1 指向 node2

    std::cout << "Node1 data: " << node1.getData() << ", Next: " << node1.getLink()->getData() << std::endl;
    std::cout << "Node2 data: " << node2.getData() << ", Prev: " << node2.getPrev()->getData() << std::endl;

    return 0;
}
```
