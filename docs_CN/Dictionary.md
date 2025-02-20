# `Dictionary` 技術文件

## 概述

`Dictionary.hpp` 檔案定義了一個模板化的 `Dictionary` 類別，用於實作鍵值對儲存功能。它允許使用者儲存、擷取和操作鍵值對，並包含了多個字典操作的實用方法，如插入、移除和搜尋。此字典也支援對與鍵相關聯的值進行各種操作，例如套用轉換和合併值。

---

## 主要元件

### `KeyValuePair` 結構

`KeyValuePair` 結構代表字典中的單一鍵值對。它包含：
- **`key`**：鍵值對中的鍵。
- **`value`**：與鍵相關聯的值。

```cpp
template <class K, class V>
struct KeyValuePair
{
    K key;   // 鍵
    V value; // 與鍵相關聯的值
};
```

### `Dictionary` 類別

`Dictionary` 類別儲存 `KeyValuePair` 物件的集合，並提供與這些物件互動的方法。鍵和值可以是由模板參數 `K` 和 `V` 指定的任何型別。

#### 成員變數：
- **`capacity`**：字典在需要調整大小前可以儲存的鍵值對最大數量。
- **`size`**：目前儲存在字典中的鍵值對數量。
- **`arr`**：儲存鍵值對的陣列。

#### 建構子和解構子：
- **`Dictionary(int c)`**：以指定容量 `c` 初始化字典。

  範例：
  ```cpp
  Dictionary<int, std::string> dict(10);  // 建立容量為 10 的字典
  ```

- **`Dictionary(const Dictionary<K, V>& dict)`**：複製建構子，透過複製另一個字典的內容來初始化字典。

  範例：
  ```cpp
  Dictionary<int, std::string> dictCopy = dict;  // 建立字典的複本
  ```

- **`~Dictionary()`**：解構子，用於釋放字典使用的資源。

#### 屬性：
- **`Capacity()`**：回傳字典的容量。

  範例：
  ```cpp
  int cap = dict.Capacity();  // 取得字典的容量
  ```

- **`IsEmpty()`**：如果字典為空則回傳 `true`，否則回傳 `false`。

  範例：
  ```cpp
  bool isEmpty = dict.IsEmpty();  // 檢查字典是否為空
  ```

- **`Size()`**：回傳目前儲存在字典中的元素數量。

  範例：
  ```cpp
  int size = dict.Size();  // 取得字典中鍵值對的數量
  ```

- **`isBelong(const K& key)`**：如果指定的鍵存在於字典中則回傳 `true`，否則回傳 `false`。

  範例：
  ```cpp
  bool exists = dict.isBelong(5);  // 檢查鍵 5 是否在字典中
  ```

#### 操作函式：
- **`Insert(const KeyValuePair<K, V>& pair)`**：將鍵值對插入字典中。

  範例：
  ```cpp
  KeyValuePair<int, std::string> pair = {1, "apple"};
  dict.Insert(pair);  // 將鍵值對插入字典中
  ```

- **`Remove(const K& key)`**：從字典中移除具有指定鍵的鍵值對。

  範例：
  ```cpp
  dict.Remove(5);  // 移除鍵為 5 的鍵值對
  ```

- **`Map(const K& key)`**：回傳與給定鍵相關聯的值的向量。此函式可以處理同一個鍵的多個值。

  範例：
  ```cpp
  auto values = dict.Map(1);  // 取得與鍵 1 相關聯的所有值
  ```

- **`reduce(std::function<V(const V&, const V&)> reducer)`**：套用歸納函式來合併字典中的值。歸納函式接受兩個 `V` 型別的值並回傳一個新值。

  範例：
  ```cpp
  dict.reduce([](const std::string& v1, const std::string& v2) {
      return v1 + " " + v2;  // 透過串接合併字串值
  });
  ```

#### 運算子重載：
- **`operator=`**：指定運算子，用於複製另一個字典的內容。

  範例：
  ```cpp
  dict = anotherDict;  // 將 anotherDict 的內容複製到 dict
  ```

- **`operator[]`**：存取指定鍵相關聯的值的運算子。如果找不到鍵，可能會拋出例外或回傳預設值，取決於實作方式。

  範例：
  ```cpp
  std::string value = dict[5];  // 存取鍵 5 相關聯的值
  ```

- **`operator==`**：檢查兩個字典是否相等（即包含相同的鍵值對）。

  範例：
  ```cpp
  if (dict == anotherDict) {
      // 字典相等
  }
  ```

- **`operator!=`**：檢查兩個字典是否不相等。

  範例：
  ```cpp
  if (dict != anotherDict) {
      // 字典不相等
  }
  ```

- **`operator<<`**：重載串流插入（`<<`）運算子以輸出字典的內容。

  範例：
  ```cpp
  std::cout << dict;  // 輸出字典內容
  ```

---

## 使用範例

以下是展示如何使用 `Dictionary` 類別的範例：

```cpp
#include "Dictionary.hpp"
#include <iostream>

int main() {
    // 建立一個具有整數鍵和字串值的字典
    Dictionary<int, std::string> dict(10);

    // 將鍵值對插入字典
    dict.Insert({1, "apple"});
    dict.Insert({2, "banana"});
    dict.Insert({3, "cherry"});

    // 輸出字典
    std::cout << "字典內容：" << dict << std::endl;

    // 取得字典的大小
    std::cout << "字典大小：" << dict.Size() << std::endl;

    // 檢查鍵是否存在於字典中
    std::cout << "鍵 2 是否存在？" << (dict.isBelong(2) ? "是" : "否") << std::endl;

    // 使用鍵存取值
    std::cout << "鍵 2 的值：" << dict[2] << std::endl;

    // 移除鍵值對
    dict.Remove(2);
    std::cout << "移除鍵 2 後：" << dict << std::endl;

    // 套用歸納函式（例如，串接字串值）
    dict.reduce([](const std::string& v1, const std::string& v2) {
        return v1 + " " + v2;
    });

    // 輸出修改後的字典
    std::cout << "歸納操作後：" << dict << std::endl;

    return 0;
}
```

### 說明：
- 程式碼建立了一個以整數為鍵、字串為值的 `Dictionary`。
- 使用 `Insert()` 方法插入鍵值對，並使用 `operator<<` 輸出字典。
- 程式檢查字典的大小並確認特定鍵是否存在。
- 使用 `Remove()` 函式移除鍵值對，並使用 `reduce()` 方法套用歸納操作來合併字串值。

---

## 潛在錯誤與邊界情況

1. **在 `operator[]` 中找不到鍵**：如果嘗試存取不存在的鍵，請確保適當處理此情況。某些實作可能會拋出例外，而其他可能會回傳預設值。

2. **超出容量**：當插入項目到字典時，確保在元素數量超過初始容量時字典能適當調整大小。

3. **同一個鍵的多個值**：`Map()` 函式可能會為同一個鍵回傳多個值。如有必要，確保字典設計能處理此情況。

4. **記憶體管理**：確保適當的記憶體處理，特別是在複製字典或處理鍵值對的動態記憶體時。

---

## 相依性

- **C++ 標準函式庫**：此類別使用 `std::variant` 來儲存混合型別，並使用 `std::function` 進行 `reduce()` 操作。請確保使用 C++17 或更高版本的編譯器以支援 `std::variant` 和 `std::function`。
- **其他引用**：此類別包含 `GeneralArray`、`Polynomial`、`SparseMatrix` 和 `String` 型別，這些都應該被適當定義和引用。
