#ifndef CIRQUE
#define CIRQUE

#include "../DeQue/DeQue.hpp"  // 繼承自 DeQue
#include <iostream>

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;

class CirQue : public DeQue 
{
    private:
        int front;  // 指向佇列的第一個有效元素
        int rear;   // 指向佇列的最後一個有效元素
        int count;  // 當前佇列的大小

    public:
        // Constructor: 初始化循環佇列，預設容量為 10
        CirQue(int capacity = 10);

        // Insert element at front
        void PushFront(const MORTISInvariant& x);

        // Insert element at back
        void PushBack(const MORTISInvariant& x);

        // Remove element from front
        void PopFront();

        // Remove element from back
        void PopBack();

        // Get the front element
        MORTISInvariant Front() const;

        // Get the back element
        MORTISInvariant Back() const;

        // Check if queue is empty
        bool IsEmpty() const;

        // Get the size of the queue
        int Size() const;

        // Print all elements in the queue
        void PrintBag() const;
};

#endif // CIRQUE
