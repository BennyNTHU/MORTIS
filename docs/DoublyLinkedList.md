# DoublyLinkedList 類別使用手冊

## 簡介
`DoublyLinkedList<T>` 是一個雙向鏈結串列，提供插入、刪除、遍歷等功能。

## 類別定義
```cpp
template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void InsertFront(const T& e);
    void InsertBack(const T& e);
    void Insert(int pos, T e);
    void DeleteFront();
    void DeleteBack();
    void Delete(int pos);
    int Length() const;
    void Reverse();
    void Concatenate(DoublyLinkedList<T>& other);
    DLIterator<T> begin() const;
    DLIterator<T> end() const;
};
```

## **函式說明**
### `DoublyLinkedList()`
- **功能**：建立一個空的雙向鏈結串列。

### `~DoublyLinkedList()`
- **功能**：銷毀鏈結串列，釋放所有節點。

### `void InsertFront(const T& e)`
- **功能**：在鏈結串列前端插入元素 `e`。

### `void InsertBack(const T& e)`
- **功能**：在鏈結串列尾端插入元素 `e`。

### `void Insert(int pos, T e)`
- **功能**：在 `pos` 位置插入 `e`。
- **例外**：
  - 若 `pos` 超出範圍，拋出 `std::out_of_range`。

### `void DeleteFront()`
- **功能**：刪除前端元素。
- **例外**：
  - 若列表為空，拋出 `std::runtime_error`。

### `void DeleteBack()`
- **功能**：刪除尾端元素。
- **例外**：
  - 若列表為空，拋出 `std::runtime_error`。

### `void Delete(int pos)`
- **功能**：刪除 `pos` 位置的元素。
- **例外**：
  - 若 `pos` 超出範圍，拋出 `std::out_of_range`。

### `int Length() const`
- **功能**：回傳鏈結串列的長度。

### `void Reverse()`
- **功能**：將鏈結串列反轉。

### `void Concatenate(DoublyLinkedList<T>& other)`
- **功能**：將 `other` 串接到當前鏈結串列後面。

### `DLIterator<T> begin() const`
- **功能**：回傳指向鏈結串列開頭的迭代器。

### `DLIterator<T> end() const`
- **功能**：回傳指向鏈結串列結尾的迭代器。

## **範例**
```cpp
#include "DoublyLinkedList.hpp"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;
    list.InsertBack(1);
    list.InsertBack(2);
    list.InsertBack(3);
    list.InsertFront(0);

    std::cout << "鏈結串列長度: " << list.Length() << std::endl;
    list.DeleteFront();
    list.DeleteBack();

    std::cout << "刪除前後元素後長度: " << list.Length() << std::endl;

    return 0;
}
```