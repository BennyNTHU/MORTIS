#include "DeQue.hpp"
#include <iostream>
#include <stdexcept>

DeQue::~DeQue() {
    delete[] arr;  // 釋放記憶體
}

void DeQue::PushFront(const MORTISInvariant& x) {
    if (size == capacity) {
        ChangeSize1D(arr, capacity, capacity * 2);
        capacity *= 2;
    }
    for (int i = size; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    size++;
}

void DeQue::PopFront() {
    if (size == 0) {
        throw std::out_of_range("DeQue is empty!");
    }
    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;
}

MORTISInvariant DeQue::Front() const {
    if (size == 0) {
        throw std::out_of_range("DeQue is empty!");
    }
    return arr[0];
}

void DeQue::PushBack(const MORTISInvariant& x) {
    if (size == capacity) {
        ChangeSize1D(arr, capacity, capacity * 2);
        capacity *= 2;
    }
    arr[size++] = x;
}

void DeQue::PopBack() {
    if (size == 0) {
        throw std::out_of_range("DeQue is empty!");
    }
    size--;
}

MORTISInvariant DeQue::Back() const {
    if (size == 0) {
        throw std::out_of_range("DeQue is empty!");
    }
    return arr[size - 1];
}
