// g++ -std=c++17 CirQue.cpp CirQue-test.cpp ../../array/GeneralArray/GeneralArray.cpp\
     ../../array/Polynomial/Polynomial.cpp ../../array/SparseMatrix/SparseMatrix.cpp\
     ../../array/String/String.cpp ../DeQue/DeQue.cpp ../Bag/Bag.cpp -o test

#include "CirQue.hpp"
#include <iostream>

using namespace std;

int main() 
{
    CirQue<MORTISInvariant> queue(8);

    cout << "=== CirQue Test ===" << endl;

    // 測試基本資料型態
    queue.PushBack(42);
    queue.PushBack('A');
    queue.PushBack(3.14);
    queue.PushBack(true);
    queue.PushBack("Hello");

    cout << queue.Size() << endl;

    cout << "Queue after inserting basic types:" << endl;
    cout << queue << endl;
    cout << "rear index: " << queue.getRear() << endl;

    // 測試移除
    queue.PopFront();
    queue.PopBack();
    cout << "Queue after removing front and back elements:" << endl;
    cout << queue << endl;

    // 插入 std::string
    queue.PushBack(std::string("Hello, CirQue!"));

    // 插入 GeneralArray<MIXED_TYPE>
    GeneralArray<MIXED_TYPE> ga(1, {3}, MIXED_TYPE{});
    ga.Store({0}, 100);
    ga.Store({1}, std::string("Test"));
    ga.Store({2}, 'Z');
    queue.PushBack(ga);

    // 插入 Polynomial
    Polynomial poly;
    poly.NewTerm(2, 3); // 3x^2
    poly.NewTerm(0, 1); // +1
    queue.PushBack(poly);
    
    // 插入 SparseMatrix
    SparseMatrix sm(3, 3, 2);
    sm.StoreNum(0, 0, 5);
    sm.StoreNum(1, 1, -2);
    queue.PushBack(sm);
    
    // 插入 String
    char init1[] = "Yeah Tiger";
    String str(init1, 100);
    queue.PushBack(str);

    std::cout << "\nDeQue contents after inserting all types:\n";
    cout << queue << endl;

    // 測試 Front & Back
    std::cout << "\nFront element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, queue.Front());

    std::cout << "Back element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, queue.Back());

    // 測試 PopFront & PopBack
    queue.PopFront();
    queue.PopBack();
    
    std::cout << "\nDeQue after popping front and back:\n";
    cout << queue << endl;

    std::cout << "\nTest completed successfully!\n";

    return 0;
}
