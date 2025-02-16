#ifndef CIRQUE
#define CIRQUE

#include "../Bag/Bag.hpp"
#include "../DeQue/DeQue.hpp"  // 繼承自 DeQue
#include <iostream>

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

using T = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;

template <typename T>
class CirQue : public DeQue<T>
{
    private:
        int front;  // 指向佇列的第一個有效元素
        int rear;   // 指向佇列的最後一個有效元素
        int count;  // 當前佇列的大小

    public:
        // Constructor
        CirQue(int capacity = 10);  // Constructor: 初始化循環佇列，預設容量為 10
        ~CirQue();  // Destructor: 釋放記憶體

        // Manipulation
        void PushFront(const T& x); // Insert element at front
        void PushBack(const T& x);  // Insert element at back
        void PopFront();    // Remove element from front
        void PopBack(); // Remove element from back

        // Getters
        T Front() const;    // Get the front element
        T Back() const; // Get the back element

        // Properties
        bool IsEmpty() const;   // Check if queue is empty
        int Size() const;   // Get the size of the queue

        // overloading operator
        template <typename U> friend std::ostream& operator<<(std::ostream& os, const CirQue<U>& s); // Prints the queue elements in a readable format
};

#endif
