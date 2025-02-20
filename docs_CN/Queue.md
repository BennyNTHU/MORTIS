# `Queue` 技術文件

## 概觀
`Queue` 類別實作了先進先出（FIFO）資料結構，並繼承自 `Bag` 類別。它提供標準的佇列操作，並使用模板設計來支持型別的靈活性。

## 相依性
- 需要 `Bag.hpp` 作為父類別
- 自訂資料結構標頭檔：
  - `GeneralArray.hpp`
  - `Polynomial.hpp`
  - `SparseMatrix.hpp`
  - `String.hpp`

## 型別定義

### MIXED_TYPE
```cpp
using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;
```
一種支援基本資料型別的變異型別。

### MORTISInvariant
```cpp
using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;
```
擴展的變異型別，支援基本型別和自訂資料結構。

## API 文件說明與範例

### 建構子
```cpp
Queue(int capacity = 10);
```
建立一個具有指定容量的佇列。

**參數:**
- `capacity`: 初始佇列大小（選擇性，預設為 10）

**範例:**
```cpp
// 創建具有不同容量和型別的佇列
Queue<int> intQueue;              // 預設容量（10）
Queue<string> strQueue(20);       // 容量為 20
Queue<MIXED_TYPE> mixedQueue(15); // 混合型別佇列
```

### Push 操作
```cpp
void Push(const T& x);
```
將元素添加到佇列的末端。

**參數:**
- `x`: 要添加的元素（常數參考）

**範例:**
```cpp
Queue<int> queue(5);

// 基本整數推入
try {
    queue.Push(10);        // [10]
    queue.Push(20);        // [10,20]
    queue.Push(30);        // [10,20,30]
    
    // 混合型別範例
    Queue<MIXED_TYPE> mixedQueue;
    mixedQueue.Push(42);           // 整數
    mixedQueue.Push("Hello");      // 字串
    mixedQueue.Push(3.14);         // 雙精度浮點數
    
    // 檢查佇列滿的情況
    Queue<int> smallQueue(1);
    smallQueue.Push(1);    // OK
    smallQueue.Push(2);    // 會拋出異常 - 佇列已滿
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### Pop 操作
```cpp
void Pop();
```
移除佇列中的第一個元素。

**範例:**
```cpp
Queue<int> queue(5);

try {
    // 添加一些元素
    queue.Push(10);
    queue.Push(20);
    queue.Push(30);    // [10,20,30]
    
    queue.Pop();       // [20,30]
    queue.Pop();       // [30]
    
    // 處理空佇列的錯誤
    Queue<int> emptyQueue;
    emptyQueue.Pop();  // 會拋出異常 - 佇列空
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### Front 存取
```cpp
T Front() const;
```
返回佇列中的第一個元素。

**回傳值:** 佇列前端元素的副本

**範例:**
```cpp
Queue<int> queue(5);

try {
    queue.Push(10);
    queue.Push(20);    // [10,20]
    
    int front = queue.Front();  // front = 10
    std::cout << "Front element: " << front << std::endl;
    
    // 處理錯誤
    Queue<int> emptyQueue;
    int value = emptyQueue.Front();  // 會拋出異常
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### Rear 存取
```cpp
T Rear() const;
```
返回佇列中的最後一個元素。

**回傳值:** 佇列末端元素的副本

**範例:**
```cpp
Queue<int> queue(5);

try {
    queue.Push(10);
    queue.Push(20);    // [10,20]
    
    int rear = queue.Rear();  // rear = 20
    std::cout << "Rear element: " << rear << std::endl;
    
    // 處理錯誤
    Queue<int> emptyQueue;
    int value = emptyQueue.Rear();  // 會拋出異常
} catch (const std::runtime_error& e) {
    std::cout << "Queue error: " << e.what() << std::endl;
}
```

### 空佇列檢查
```cpp
bool IsEmpty() const;
```
檢查佇列是否為空。

**回傳值:** 如果空則返回 `true`，否則返回 `false`

**範例:**
```cpp
Queue<int> queue(5);

// 檢查空佇列
bool isEmpty1 = queue.IsEmpty();  // true

// 檢查添加元素後
queue.Push(10);
bool isEmpty2 = queue.IsEmpty();  // false

// 條件式檢查
if (queue.IsEmpty()) {
    std::cout << "Queue is empty" << std::endl;
} else {
    std::cout << "Queue has elements" << std::endl;
}
```

### 索引存取
```cpp
int getFront() const;
int getRear() const;
```
獲取當前的前端和後端索引。

**範例:**
```cpp
Queue<int> queue(5);

// 檢查初始索引
int frontIndex = queue.getFront();
int rearIndex = queue.getRear();

// 添加元素並再次檢查
queue.Push(10);
queue.Push(20);
std::cout << "Front index: " << queue.getFront() << std::endl;
std::cout << "Rear index: " << queue.getRear() << std::endl;
```

### 輸出運算子
```cpp
template <typename U>
friend std::ostream& operator<<(std::ostream& os, const Queue<U>& s);
```
打印佇列內容。

**範例:**
```cpp
Queue<int> queue(5);
queue.Push(10);
queue.Push(20);
queue.Push(30);

// 打印佇列
std::cout << queue << std::endl;  // 輸出: [10 20 30]

// 使用字串串流
std::ostringstream oss;
oss << queue;
std::string queueStr = oss.str();
```

## 完整使用範例
```cpp
#include "Queue.hpp"
#include <iostream>

int main() {
    try {
        // 創建佇列
        Queue<int> queue(5);
        
        // 添加元素
        queue.Push(10);
        queue.Push(20);
        queue.Push(30);
        
        std::cout << "Queue: " << queue << std::endl;
        std::cout << "Front: " << queue.Front() << std::endl;
        std::cout << "Rear: " << queue.Rear() << std::endl;
        
        // 移除元素
        queue.Pop();
        std::cout << "After Pop: " << queue << std::endl;
        
        // 檢查是否為空
        if (!queue.IsEmpty()) {
            std::cout << "Queue still has elements" << std::endl;
        }
        
        // 創建混合型別佇列
        Queue<MIXED_TYPE> mixedQueue;
        mixedQueue.Push(42);
        mixedQueue.Push("Test");
        mixedQueue.Push(3.14);
        
        std::cout << "Mixed Queue: " << mixedQueue << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

## 錯誤處理
常見錯誤：
1. 佇列溢位（Push 到已滿的佇列）
2. 佇列下溢（在空佇列上進行 Pop/Front/Rear）
3. 記憶體配置失敗

## 最佳實踐
1. 在進行 Pop/Front/Rear 操作之前，始終檢查 IsEmpty()
2. 使用適當的初始容量以避免溢位
3. 實作適當的錯誤處理
4. 考慮使用 MIXED_TYPE 或 MORTISInvariant 以支援靈活型別
5. 請記得 Front() 和 Rear() 返回的是副本，而非引用
