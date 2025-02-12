// g++ -std=c++17 DeQue.cpp DeQue-test.cpp ../../array/GeneralArray/GeneralArray.cpp \
    ../../array/Polynomial/Polynomial.cpp ../../array/SparseMatrix/SparseMatrix.cpp \
    ../../array/String/String.cpp ../Bag/Bag.cpp -o test

#include <iostream>
#include "DeQue.hpp"

int main() {
    try {
        std::cout << "=== DeQue Test Program ===" << std::endl;

        DeQue dq(5);  // 確保 capacity 至少為 1

        dq.PushBack(10);
        dq.PushBack(20);
        dq.PushBack(30);

        std::cout << "Front: " << std::get<int>(dq.Front()) << std::endl;
        std::cout << "Back: " << std::get<int>(dq.Back()) << std::endl;

        dq.PushFront(5);
        dq.PushFront(1);

        std::cout << "After PushFront(5), PushFront(1): " << std::endl;
        std::cout << "Front: " << std::get<int>(dq.Front()) << std::endl;
        std::cout << "Back: " << std::get<int>(dq.Back()) << std::endl;

        dq.PopFront();
        std::cout << "After PopFront(): " << std::endl;
        std::cout << "Front: " << std::get<int>(dq.Front()) << std::endl;

        dq.PopBack();
        std::cout << "After PopBack(): " << std::endl;
        std::cout << "Back: " << std::get<int>(dq.Back()) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
