# `Set.hpp` 文件說明

## 概觀

`Set.hpp` 檔案定義了一個 `Set` 類別模板，表示一個唯一元素的集合，並使用二元搜尋樹（BST）來實作。此類別提供了多種集合運算，如聯集、交集、差集和子集檢查，並提供一個方法來檢查是否包含某個元素。它支援使用初始化列表來進行初始化，並提供了列印集合的方法。

`Set` 類別是 `BinarySearchTree` 的特殊化，確保所有元素都是唯一的，並利用 BST 的高效搜尋和插入方法。

---

## 主要元件

### `Set` 類別

`Set` 類別是從 `BinarySearchTree` 類別衍生出來的，並提供了與集合相關的額外功能。

#### 成員變數：
- **繼承自 `BinarySearchTree<T>`**：`Set` 類別繼承自 `BinarySearchTree` 類別的所有成員變數，包括根節點和樹結構。底層結構是二元搜尋樹，每個節點包含型別 `T` 的元素。

---

### 建構子

- **`Set()`**：預設建構子，創建一個空的集合。集合使用型別 `T()` 的預設值作為初始值。

  範例：
  ```cpp
  Set<int> mySet;  // 創建一個空的整數集合
  ```

- **`Set(std::initializer_list<T> elements)`**：使用初始化列表來初始化集合，提供的元素將加入集合中。

  範例：
  ```cpp
  Set<int> mySet = {1, 2, 3};  // 創建一個包含元素 1、2 和 3 的集合
  ```

---

### 集合運算

- **`Set<T> Union(const Set<T>& other) const`**：返回一個新的集合，該集合是當前集合和另一個集合 `other` 的聯集。聯集包含兩個集合中的所有元素。

  範例：
  ```cpp
  Set<int> set1 = {1, 2, 3};
  Set<int> set2 = {3, 4, 5};
  Set<int> result = set1.Union(set2);  // 結果: {1, 2, 3, 4, 5}
  ```

- **`Set<T> Intersection(const Set<T>& other) const`**：返回一個新的集合，該集合是當前集合和另一個集合 `other` 的交集。交集只包含兩個集合中都存在的元素。

  範例：
  ```cpp
  Set<int> set1 = {1, 2, 3};
  Set<int> set2 = {2, 3, 4};
  Set<int> result = set1.Intersection(set2);  // 結果: {2, 3}
  ```

- **`Set<T> Difference(const Set<T>& other) const`**：返回一個新的集合，該集合是當前集合和另一個集合 `other` 的差集。差集只包含在當前集合中但不在 `other` 集合中的元素。

  範例：
  ```cpp
  Set<int> set1 = {1, 2, 3};
  Set<int> set2 = {2, 3, 4};
  Set<int> result = set1.Difference(set2);  // 結果: {1}
  ```

- **`bool IsSubsetOf(const Set<T>& other) const`**：如果當前集合的每個元素都包含在集合 `other` 中，則返回 `true`，否則返回 `false`。

  範例：
  ```cpp
  Set<int> set1 = {1, 2};
  Set<int> set2 = {1, 2, 3};
  bool result = set1.IsSubsetOf(set2);  // 結果: true
  ```

- **`bool Contains(const T& value) const`**：如果集合中包含元素 `value`，則返回 `true`，否則返回 `false`。

  範例：
  ```cpp
  Set<int> set = {1, 2, 3};
  bool result = set.Contains(2);  // 結果: true
  ```

---

### 列印方法

- **`void Print() const`**：將集合中的元素列印到 `std::cout`，元素會按照升序顯示，因為是透過二元搜尋樹的中序遍歷進行列印。

  範例：
  ```cpp
  Set<int> set = {3, 1, 2};
  set.Print();  // 輸出: 1 2 3
  ```

---

## 範例使用

以下是使用 `Set` 類別的範例：

```cpp
#include "Set.hpp"
#include <iostream>

int main() {
    // 使用初始化列表創建集合
    Set<int> set1 = {1, 2, 3};
    Set<int> set2 = {2, 3, 4};

    // 集合的聯集
    Set<int> unionSet = set1.Union(set2);
    std::cout << "Union: ";
    unionSet.Print();  // 輸出: 1 2 3 4

    // 集合的交集
    Set<int> intersectionSet = set1.Intersection(set2);
    std::cout << "Intersection: ";
    intersectionSet.Print();  // 輸出: 2 3

    // 集合的差集
    Set<int> differenceSet = set1.Difference(set2);
    std::cout << "Difference: ";
    differenceSet.Print();  // 輸出: 1

    // 檢查 set1 是否是 set2 的子集
    bool isSubset = set1.IsSubsetOf(set2);
    std::cout << "Is set1 a subset of set2? " << (isSubset ? "Yes" : "No") << std::endl;

    // 檢查集合是否包含特定元素
    bool contains = set1.Contains(2);
    std::cout << "Does set1 contain 2? " << (contains ? "Yes" : "No") << std::endl;

    return 0;
}
```

### 說明：
- 程式創建了兩個集合 `set1` 和 `set2`，並使用初始化列表初始化。
- 它展示了如何計算集合的聯集、交集和差集。
- 使用 `Print()` 方法顯示每個結果集合的元素。
- 程式檢查 `set1` 是否是 `set2` 的子集，並檢查 `set1` 是否包含值 `2`。

---

## 可能的錯誤與邊界情形

1. **空集合**：對空集合進行聯集、交集和差集運算應該妥善處理。例如，空集合與任何集合的聯集是非空集合，任何集合與空集合的交集是空集合。
   
2. **處理重複元素**：`Set` 類別確保元素唯一。如果插入重複元素，則只有一個實例會保留，因為 `BinarySearchTree` 在插入過程中會確保唯一性。

3. **無效的集合操作**：確保方法 `IsSubsetOf()` 和 `Contains()` 使用時，集合已正確初始化。例如，對未完全初始化的集合呼叫 `IsSubsetOf()` 可能導致未定義行為。

---

## 相依性

- **`BinarySearchTree.hpp`**：`Set` 類別繼承自 `BinarySearchTree<T>` 類別。確保 `BinarySearchTree` 類別正確實作，並包含插入、遍歷和刪除節點所需的方法。
