# **DeQue Documentation**

## **Introduction**
`DeQue` (Double-Ended Queue) is a container class that inherits from `Bag`, allowing insertion and deletion operations at both the front and the back.  
Unlike `Bag`, which only allows insertion and deletion at the back, `DeQue` supports operations at both ends.

---

## **Class Definition**
```cpp
class DeQue : public Bag {
public:
    // Constructor: Initializes DeQue with an initial capacity
    explicit DeQue(int initial_capacity = 10);

    // Inserts an element at the front
    void PushFront(const MORTISInvariant& x);

    // Inserts an element at the back (inherited from Bag)
    void PushBack(const MORTISInvariant& x);

    // Deletes an element from the front
    void PopFront();

    // Deletes an element from the back (inherited from Bag)
    void PopBack();

    // Returns the front element
    MORTISInvariant Front() const;

    // Returns the back element
    MORTISInvariant Back() const;

    // Checks if the DeQue is empty
    bool IsEmpty() const;

    // Prints all elements in the DeQue
    void PrintBag() const;
};
```

---

## **Function Details**
### **1. `DeQue(int initial_capacity)`**
**Description**:  
Initializes the `DeQue` with a specified capacity.

**Example**:
```cpp
DeQue dq(10); // Creates a DeQue with a capacity of 10
```

---

### **2. `void PushFront(const MORTISInvariant& x)`**
**Description**:  
Inserts an element at the **front** of the `DeQue`.

**Example**:
```cpp
dq.PushFront(100);
dq.PushFront('A');
```

---

### **3. `void PushBack(const MORTISInvariant& x)`**
**Description**:  
Inserts an element at the **back** of the `DeQue`. (Inherited from `Bag`'s `Push`)

**Example**:
```cpp
dq.PushBack(3.14);
dq.PushBack("Hello");
```

---

### **4. `void PopFront()`**
**Description**:  
Deletes an element from the **front** of the `DeQue`.

**Example**:
```cpp
dq.PopFront();
```

---

### **5. `void PopBack()`**
**Description**:  
Deletes an element from the **back** of the `DeQue`. (Inherited from `Bag`'s `Pop`)

**Example**:
```cpp
dq.PopBack();
```

---

### **6. `MORTISInvariant Front() const`**
**Description**:  
Returns the element at the **front** of the `DeQue`.

**Example**:
```cpp
std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Front());
```

---

### **7. `MORTISInvariant Back() const`**
**Description**:  
Returns the element at the **back** of the `DeQue`.

**Example**:
```cpp
std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Back());
```

---

### **8. `bool IsEmpty() const`**
**Description**:  
Checks if the `DeQue` is empty.

**Example**:
```cpp
if (dq.IsEmpty()) {
    std::cout << "DeQue is empty" << std::endl;
}
```

---

### **9. `void PrintBag() const`**
**Description**:  
Prints all elements in the `DeQue`, with each element on a new line. (Inherited from `Bag`)

**Example**:
```cpp
dq.PrintBag();
```

---

## **Complete Example**
```cpp
#include <iostream>
#include "DeQue.hpp"
#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

int main() {
    std::cout << "=== DeQue Test Program ===\n";
    
    // Initialize DeQue
    DeQue dq(10);
    
    // Insert basic types
    dq.PushFront(10);
    dq.PushBack('A');
    dq.PushBack(3.14f);
    dq.PushBack(true);
    dq.PushBack(2.718);
    
    std::cout << "After inserting basic types:\n";
    dq.PrintBag();
    
    // Insert std::string
    dq.PushBack(std::string("Hello, DeQue!"));

    // Insert GeneralArray<MIXED_TYPE>
    GeneralArray<MIXED_TYPE> ga(1, {3}, MIXED_TYPE{});
    ga.Store({0}, 100);
    ga.Store({1}, std::string("Test"));
    ga.Store({2}, 'Z');
    dq.PushBack(ga);

    // Insert Polynomial
    Polynomial poly;
    poly.NewTerm(2, 3); // 3x^2
    poly.NewTerm(0, 1); // +1
    dq.PushBack(poly);
    
    // Insert SparseMatrix
    SparseMatrix sm(3, 3, 2);
    sm.StoreNum(0, 0, 5);
    sm.StoreNum(1, 1, -2);
    dq.PushBack(sm);
    
    // Insert String
    char init1[] = "Custom String Object";
    String str(init1, 100);
    dq.PushBack(str);

    std::cout << "\nDeQue contents after inserting all types:\n";
    dq.PrintBag();

    // Test Front & Back
    std::cout << "\nFront element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Front());

    std::cout << "Back element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Back());

    // Test PopFront & PopBack
    dq.PopFront();
    dq.PopBack();
    
    std::cout << "\nDeQue after popping front and back:\n";
    dq.PrintBag();

    std::cout << "\nTest completed successfully!\n";

    return 0;
}
```

---

## **Conclusion**
1. `DeQue` allows insertion and deletion at both the front and the back, inheriting the functionality of `Bag`.
2. Internally, it uses `std::variant` to support multiple types, including:
   - `int`, `char`, `float`, `bool`, `double`, `std::string`
   - `GeneralArray<MIXED_TYPE>`, `Polynomial`, `SparseMatrix`, `String`
3. The test program covers all functions, ensuring proper functionality.

This design makes `DeQue` a powerful and flexible double-ended queue (Deque) data structure! 🚀

---