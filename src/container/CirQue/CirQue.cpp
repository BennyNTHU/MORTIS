#include "CirQue.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructor: 初始化變數
CirQue::CirQue(int capacity) : DeQue(capacity) {
    front = -1;
    rear = -1;
    count = 0;
}

// 在前端插入元素
void CirQue::PushFront(const MORTISInvariant& x) {
    if (count == capacity) {
        throw overflow_error("CirQue is full.");
    }

    if (IsEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + capacity) % capacity;  // 環形索引處理
    }

    arr[front] = x;
    count++;
}

// 在後端插入元素
void CirQue::PushBack(const MORTISInvariant& x) {
    if (count == capacity) {
        throw overflow_error("CirQue is full.");
    }

    if (IsEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;  // 環形索引處理
    }

    arr[rear] = x;
    count++;
}

// 從前端移除元素
void CirQue::PopFront() {
    if (IsEmpty()) {
        throw underflow_error("CirQue is empty.");
    }

    if (front == rear) {  // 只有一個元素時
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;  // 環形索引處理
    }

    count--;
}

// 從後端移除元素
void CirQue::PopBack() {
    if (IsEmpty()) {
        throw underflow_error("CirQue is empty.");
    }

    if (front == rear) {  // 只有一個元素時
        front = rear = -1;
    } else {
        rear = (rear - 1 + capacity) % capacity;  // 環形索引處理
    }

    count--;
}

// 獲取前端元素
MORTISInvariant CirQue::Front() const {
    if (IsEmpty()) {
        throw underflow_error("CirQue is empty.");
    }
    return arr[front];
}

// 獲取後端元素
MORTISInvariant CirQue::Back() const {
    if (IsEmpty()) {
        throw underflow_error("CirQue is empty.");
    }
    return arr[rear];
}

// 判斷是否為空
bool CirQue::IsEmpty() const {
    return (count == 0);
}

// 返回當前佇列大小
int CirQue::Size() const {
    return count;
}

// 印出所有元素
void CirQue::PrintBag() const {
    if (IsEmpty()) {
        cout << "CirQue is empty." << endl;
        return;
    }

    int index = front;
    for (int i = 0; i < count; ++i) {
        std::visit([](auto&& arg) {
            cout << arg << endl;
        }, arr[index]);
        index = (index + 1) % capacity;  // 環形索引處理
    }
}
