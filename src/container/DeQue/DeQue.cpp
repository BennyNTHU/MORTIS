#include "DeQue.hpp"
#include <iostream>
#include <stdexcept>

// Constructor: 使用 Bag 的建構函式來初始化
DeQue::DeQue(int initial_capacity) : Bag(initial_capacity) {}

// 在前端插入元素
void DeQue::PushFront(const MORTISInvariant& x) {
    if (top + 1 == capacity) {
        ChangeSize1D(arr, capacity, capacity * 2);
        capacity *= 2;
    }

    // 將所有元素向後移動一位
    for (int i = top; i >= 0; --i) {
        arr[i + 1] = arr[i];
    }
    
    arr[0] = x; // 插入新元素到最前面
    top++;
}

// 在後端插入元素（與 Bag::Push 相同）
void DeQue::PushBack(const MORTISInvariant& x) {
    Push(x);  // 直接呼叫父類別的 `Push`
}

// 從前端刪除元素
void DeQue::PopFront() {
    if (IsEmpty()) {
        throw std::runtime_error("DeQue is empty, cannot pop front.");
    }

    // 所有元素向前移動一位
    for (int i = 0; i < top; ++i) {
        arr[i] = arr[i + 1];
    }

    top--; // 移除第一個元素
}

// 從後端刪除元素
void DeQue::PopBack() {
    Pop();  // 直接呼叫父類別的 `Pop`
}

// 獲取前端元素
MORTISInvariant DeQue::Front() const {
    if (IsEmpty()) {
        throw std::runtime_error("DeQue is empty.");
    }
    return arr[0];
}

// 獲取後端元素
MORTISInvariant DeQue::Back() const {
    if (IsEmpty()) {
        throw std::runtime_error("DeQue is empty.");
    }
    return arr[top];
}

// 檢查是否為空
bool DeQue::IsEmpty() const {
    return Bag::IsEmpty();
}

// 使用 Bag 的 PrintBag 來印出內容
void DeQue::PrintBag() const {
    Bag::PrintBag();
}
