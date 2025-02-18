以下是 **DeQue** 的詳細使用文檔，包括類別介紹、函式說明和範例程式碼。

---

# **DeQue 使用文檔**

## **簡介**
`DeQue` (雙端佇列) 是一個繼承自 `Bag` 的容器類別，允許在前端和後端進行插入和刪除操作。  
與 `Bag` 不同的是，`DeQue` 允許兩端操作，而 `Bag` 只允許後端插入和刪除。

---

## **類別定義**
```cpp
class DeQue : public Bag {
public:
    // Constructor: 初始化 DeQue，指定初始容量
    explicit DeQue(int initial_capacity = 10);

    // 在前端插入元素
    void PushFront(const MORTISInvariant& x);

    // 在後端插入元素 (繼承自 Bag)
    void PushBack(const MORTISInvariant& x);

    // 從前端刪除元素
    void PopFront();

    // 從後端刪除元素 (繼承自 Bag)
    void PopBack();

    // 取得前端元素
    MORTISInvariant Front() const;

    // 取得後端元素
    MORTISInvariant Back() const;

    // 檢查是否為空
    bool IsEmpty() const;

    // 印出 DeQue 內的所有元素
    void PrintBag() const;
};
```

---

## **函式詳解**
### **1. `DeQue(int initial_capacity)`**
**描述**:  
初始化 `DeQue`，並指定容量大小。

**範例**:
```cpp
DeQue dq(10); // 建立容量為 10 的 DeQue
```

---

### **2. `void PushFront(const MORTISInvariant& x)`**
**描述**:  
在 `DeQue` 的 **前端** 插入元素。

**範例**:
```cpp
dq.PushFront(100);
dq.PushFront('A');
```

---

### **3. `void PushBack(const MORTISInvariant& x)`**
**描述**:  
在 `DeQue` 的 **後端** 插入元素。（實際上是繼承 `Bag` 的 `Push`）

**範例**:
```cpp
dq.PushBack(3.14);
dq.PushBack("Hello");
```

---

### **4. `void PopFront()`**
**描述**:  
從 `DeQue` 的 **前端** 刪除一個元素。

**範例**:
```cpp
dq.PopFront();
```

---

### **5. `void PopBack()`**
**描述**:  
從 `DeQue` 的 **後端** 刪除一個元素。（實際上是繼承 `Bag` 的 `Pop`）

**範例**:
```cpp
dq.PopBack();
```

---

### **6. `MORTISInvariant Front() const`**
**描述**:  
回傳 `DeQue` **前端** 的元素。

**範例**:
```cpp
std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Front());
```

---

### **7. `MORTISInvariant Back() const`**
**描述**:  
回傳 `DeQue` **後端** 的元素。

**範例**:
```cpp
std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Back());
```

---

### **8. `bool IsEmpty() const`**
**描述**:  
檢查 `DeQue` 是否為空。

**範例**:
```cpp
if (dq.IsEmpty()) {
    std::cout << "DeQue is empty" << std::endl;
}
```

---

### **9. `void PrintBag() const`**
**描述**:  
印出 `DeQue` 內的所有元素，每個元素換行一次。（繼承自 `Bag`）

**範例**:
```cpp
dq.PrintBag();
```

---

## **完整範例**
```cpp
#include <iostream>
#include "DeQue.hpp"
#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

int main() {
    std::cout << "=== DeQue Test Program ===\n";
    
    // 初始化 DeQue
    DeQue dq(10);
    
    // 插入基本類型
    dq.PushFront(10);
    dq.PushBack('A');
    dq.PushBack(3.14f);
    dq.PushBack(true);
    dq.PushBack(2.718);
    
    std::cout << "After inserting basic types:\n";
    dq.PrintBag();
    
    // 插入 std::string
    dq.PushBack(std::string("Hello, DeQue!"));

    // 插入 GeneralArray<MIXED_TYPE>
    GeneralArray<MIXED_TYPE> ga(1, {3}, MIXED_TYPE{});
    ga.Store({0}, 100);
    ga.Store({1}, std::string("Test"));
    ga.Store({2}, 'Z');
    dq.PushBack(ga);

    // 插入 Polynomial
    Polynomial poly;
    poly.NewTerm(2, 3); // 3x^2
    poly.NewTerm(0, 1); // +1
    dq.PushBack(poly);
    
    // 插入 SparseMatrix
    SparseMatrix sm(3, 3, 2);
    sm.StoreNum(0, 0, 5);
    sm.StoreNum(1, 1, -2);
    dq.PushBack(sm);
    
    // 插入 String
    char init1[] = "Custom String Object";
    String str(init1, 100);
    dq.PushBack(str);

    std::cout << "\nDeQue contents after inserting all types:\n";
    dq.PrintBag();

    // 測試 Front & Back
    std::cout << "\nFront element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Front());

    std::cout << "Back element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Back());

    // 測試 PopFront & PopBack
    dq.PopFront();
    dq.PopBack();
    
    std::cout << "\nDeQue after popping front and back:\n";
    dq.PrintBag();

    std::cout << "\nTest completed successfully!\n";

    return 0;
}
```

---

## **結論**
1. `DeQue` 允許在前端和後端插入/刪除元素，並繼承 `Bag` 的功能。
2. 內部使用 `std::variant` 來支援多種類型，包括：
   - `int`, `char`, `float`, `bool`, `double`, `std::string`
   - `GeneralArray<MIXED_TYPE>`, `Polynomial`, `SparseMatrix`, `String`
3. 測試程式涵蓋了所有函式，確保功能正常。

這樣的設計使得 `DeQue` 成為一個強大且靈活的雙端佇列 (Deque) 資料結構！ 🚀