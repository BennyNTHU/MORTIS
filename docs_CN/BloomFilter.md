# `BloomFilter` 技術文件

## 概觀

`BloomFilter.hpp` 標頭文件定義了一個 `BloomFilter` 類別模板，實作了 Bloom Filter 資料結構。它支援新增元素、檢查元素是否存在於集合中，以及顯示內部的位元陣列。此類別使用多個雜湊函式來將元素映射到位元陣列中的位置。雜湊函式的數量和位元陣列的大小可以自訂。

---

## 主要元件

### `BloomFilter` 類別

`BloomFilter` 類別允許使用位元陣列和雜湊函式來高效地插入和搜尋集合中的元素。它設計用來提供快速的成員檢測，但有可能會產生誤報（false positives）。

#### 成員變數：
- **`size`**：Bloom filter 位元陣列的大小。
- **`hashFunctions`**：用於插入和檢查元素的雜湊函式數量。
- **`bitArray`**：儲存 Bloom filter 狀態的位元陣列。
- **`hashFunctionsList`**：一組雜湊函式，用於計算位元陣列中的位置。

#### 雜湊函式：
- **`hash1`**：第一個雜湊函式。
- **`hash2`**：第二個雜湊函式。
- **`hash3`**：第三個雜湊函式。

#### 建構子與解構子：
- **`BloomFilter(size_t size = DEFAULT_SIZE, size_t hashFunctions = DEFAULT_HASH_FUNCTIONS)`**：建構子，初始化 Bloom filter，並指定位元陣列的大小和雜湊函式的數量。預設使用大小為 1000 和 3 個雜湊函式。

  範例：
  ```cpp
  BloomFilter<std::string> filter;  // 創建一個預設大小和雜湊函式的 Bloom filter，用於字串
  ```

#### 公共方法：

- **`void insert(const T& key)`**：將元素 `key` 插入到 Bloom filter 中。此方法會應用每個雜湊函式，將元素映射到位元陣列中的位置並將這些位置設為 `true`。

  範例：
  ```cpp
  filter.insert("apple");  // 將 "apple" 插入到 Bloom filter 中
  ```

- **`bool search(const T& key) const`**：檢查元素 `key` 是否存在於 Bloom filter 中。它會應用雜湊函式並檢查所有對應位置是否為 `true`。若任何位置為 `false`，則該元素確實不在集合中；若所有位置均為 `true`，則該元素可能在集合中（但有可能是誤報）。

  範例：
  ```cpp
  bool exists = filter.search("apple");  // 檢查 "apple" 是否在 Bloom filter 中
  ```

- **`void display() const`**：顯示 Bloom filter 位元陣列的當前狀態，顯示哪些位置被設為 `true`。

  範例：
  ```cpp
  filter.display();  // 顯示 Bloom filter 位元陣列的當前狀態
  ```

---

## 使用範例

以下是示範如何使用 `BloomFilter` 類別的範例：

```cpp
#include "BloomFilter.hpp"
#include <iostream>

int main() {
    // 創建一個預設大小和 3 個雜湊函式的 Bloom filter，用於字串
    BloomFilter<std::string> filter;

    // 將元素插入到 Bloom filter 中
    filter.insert("apple");
    filter.insert("banana");
    filter.insert("grape");

    // 檢查元素是否在 Bloom filter 中
    std::cout << "Is 'apple' in the filter? " << (filter.search("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'orange' in the filter? " << (filter.search("orange") ? "Yes" : "No") << std::endl;

    // 顯示 Bloom filter 位元陣列的當前狀態
    filter.display();

    return 0;
}
```

### 說明：
- 程式碼創建了一個 `BloomFilter` 實例，用於 `std::string` 類型，並使用預設的大小和雜湊函式數量。
- 它將幾個水果名稱插入到 Bloom filter 中，然後檢查特定水果是否存在於過濾器中。
- `display()` 方法顯示位元陣列的當前狀態，讓使用者看到哪些位置被設為 `true`。

---

## 可能的錯誤與邊界情形

1. **誤報（False Positives）**：Bloom filter 可能會對未插入的元素返回 `true`，這稱為誤報。隨著加入更多元素，誤報的機率會增加。您可以通過增加位元陣列的大小或雜湊函式的數量來減少誤報的機率。

2. **誤缺（False Negatives）**：Bloom filter 保證永遠不會產生誤缺。如果過濾器顯示元素不在集合中，則該元素確實不在。

3. **雜湊碰撞（Hash Collisions）**：如果兩個不同的元素產生相同的雜湊值（碰撞），可能會導致誤報。使用的雜湊函式數量會影響碰撞的發生。

4. **位元陣列溢位**：如果插入過多的元素，位元陣列可能會溢位，增加誤報的機率。若預期會插入大量元素，請考慮重新調整位元陣列的大小。

---

## 相依性

- **C++ 標準函式庫**：此類別使用了標準函式庫中的組件，如 `std::vector`、`std::bitset` 和 `std::function`。
- **雜湊函式**：此類別使用了三個預設的雜湊函式來執行插入和搜尋操作。這些雜湊函式是簡單的實作，但如有需要，您可以自訂雜湊函式。
