# DLIterator 類別使用手冊

## 簡介
`DLIterator<T>` 是雙向鏈結串列的迭代器，允許前後遍歷 `DoublyLinkedList<T>`。

## 類別定義
```cpp
template <typename T>
class DLIterator : public ChainIterator<T> {
public:
    DLIterator(DoubleNode<T>* start = nullptr);
    DLIterator<T>& operator++(); // 前進
    DLIterator<T>& operator--(); // 後退
    bool operator!=(const DLIterator<T>& other) const;
};
```

## **函式說明**
### `DLIterator(DoubleNode<T>* start = nullptr)`
- **功能**：建立一個指向 `start` 節點的迭代器。
- **參數**：
  - `start`：起始節點指標（預設為 `nullptr`）。

### `DLIterator<T>& operator++()`
- **功能**：將迭代器前進到下一個節點。
- **回傳**：
  - `*this`，表示迭代器移動後的狀態。

### `DLIterator<T>& operator--()`
- **功能**：將迭代器移動到前一個節點。
- **回傳**：
  - `*this`，表示迭代器移動後的狀態。

### `bool operator!=(const DLIterator<T>& other) const`
- **功能**：比較兩個迭代器是否指向不同的節點。
- **參數**：
  - `other`：另一個 `DLIterator<T>` 迭代器。
- **回傳**：
  - 若指向不同節點則回傳 `true`，否則回傳 `false`。

## **範例**
```cpp
#include "DoublyLinkedList.hpp"
#include "DLIterator.hpp"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;
    list.InsertBack(1);
    list.InsertBack(2);
    list.InsertBack(3);

    std::cout << "從前往後遍歷: ";
    for (DLIterator<int> it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```