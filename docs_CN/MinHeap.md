# `MinHeap.hpp` 文件說明

## 概觀

`MinHeap.hpp` 標頭文件定義了一個 `MinHeap` 類別模板，這個類別擴展了 `MaxHeap` 類別。它提供了維護最小堆積資料結構的功能，其中每個父節點的值小於或等於其子節點。該類別覆寫了堆積化方法，確保在插入和移除元素時堆積屬性能夠得到維護。

---

## 主要元件

### `MinHeap` 類別

`MinHeap` 類別繼承自 `MaxHeap` 類別，並修改了堆積化操作以維護最小堆積屬性。該類別使用向量來儲存堆積元素，並支援基本的堆積操作，如插入、移除以及維護堆積結構。

#### 建構子與解構子

- **`MinHeap(const T& rootData)`**：建構子，使用指定的根節點資料初始化最小堆積。它創建根節點並使用提供的值初始化堆積。

  範例：
  ```cpp
  MinHeap<int> minHeap(10);  // 創建一個根值為 10 的最小堆積
  ```

- **`~MinHeap()`**：解構子，清理最小堆積並釋放節點所佔用的記憶體。

  範例：
  ```cpp
  // 當物件超出作用範圍時，自動清理最小堆積
  ```

---

### 堆積化方法

`MinHeap` 類別覆寫了來自 `MaxHeap` 類別的堆積化方法，確保堆積維持最小堆積屬性，其中父節點小於或等於其子節點。

- **`void heapify_up(int index)`**：這個方法通過將位於指定 `index` 的節點向上移動，直到父節點小於或等於子節點為止。當插入新元素到堆積時會呼叫此方法。

  範例：
  ```cpp
  minHeap.heapify_up(3);  // 恢復索引為 3 的節點的最小堆積屬性
  ```

- **`void heapify_down(int index)`**：這個方法通過將位於指定 `index` 的節點向下移動，直到滿足最小堆積屬性。當移除根節點或重新排列堆積時會呼叫此方法。

  範例：
  ```cpp
  minHeap.heapify_down(0);  // 恢復根節點的最小堆積屬性
  ```

---

### 相依性

- **`MaxHeap.hpp`**：`MinHeap` 類別繼承自 `MaxHeap` 類別。確保 `MaxHeap` 類別已正確實作並可用，這樣 `MinHeap` 類別才能正確工作。
- **`BinaryTree.hpp`**：該類別使用二元樹操作，因此需要 `BinaryTree` 類別來管理堆積的二元結構。

---

### 範例使用

以下是使用 `MinHeap` 類別的範例：

```cpp
#include "MinHeap.hpp"
#include <iostream>

int main() {
    // 創建一個根值為 10 的最小堆積
    MinHeap<int> minHeap(10);

    // 將元素插入最小堆積
    minHeap.Push(5);   // 插入 5 到堆積
    minHeap.Push(20);  // 插入 20 到堆積
    minHeap.Push(3);   // 插入 3 到堆積

    // 從堆積中移除最小元素（根節點）
    minHeap.Pop();  // 移除 3，這是最小的元素

    // 輸出移除後的新根元素
    std::cout << "New root after Pop: " << minHeap.GetRootData() << std::endl;

    return 0;
}
```

### 說明：
- 程式展示了如何創建一個根值為 10 的 `MinHeap`。
- 使用 `Push` 方法將數個元素插入最小堆積。
- 使用 `Pop` 方法移除最小元素（根節點），並顯示移除後的新根元素。

---

## 可能的錯誤與邊界情形

1. **堆積下溢**：對空堆積呼叫 `Pop()` 可能會導致未定義行為。在嘗試移除元素之前，請確保堆積非空。您可以在呼叫 `Pop()` 之前加入空檢查。

   範例：
   ```cpp
   if (!minHeap.IsEmpty()) {
       minHeap.Pop();
   }
   ```

2. **堆積屬性違反**：在插入或移除元素後，請確保適當呼叫 `heapify_up` 和 `heapify_down` 方法來恢復堆積屬性。

3. **無效索引**：當呼叫 `heapify_up` 或 `heapify_down` 時，請確保提供的 `index` 有效並在堆積的範圍內。
