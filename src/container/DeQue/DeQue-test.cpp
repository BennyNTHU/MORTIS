// g++ -std=c++17 DeQue.cpp DeQue-test.cpp ../../array/GeneralArray/GeneralArray.cpp\
     ../../array/Polynomial/Polynomial.cpp ../../array/SparseMatrix/SparseMatrix.cpp\
     ../../array/String/String.cpp ../Bag/Bag.cpp -o test

#include <iostream>
#include <sstream>
#include "DeQue.hpp"
#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

int main() 
{
    std::cout << "=== DeQue Test Program ===\n";
    
    // 初始化 DeQue
    DeQue<MORTISInvariant> dq(10);
    
    // 插入基本類型
    dq.PushFront(10);
    dq.PushBack('A');
    dq.PushBack(3.14f);
    dq.PushBack(true);
    dq.PushBack(2.718);
    
    std::cout << "After inserting basic types:\n";
    cout << dq << endl;
    
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
    cout << dq << endl;

    // 測試 Front & Back
    std::cout << "\nFront element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Front());

    std::cout << "Back element: ";
    std::visit([](auto&& arg) { std::cout << arg << std::endl; }, dq.Back());

    // 測試 PopFront & PopBack
    dq.PopFront();
    dq.PopBack();
    
    std::cout << "\nDeQue after popping front and back:\n";
    cout << dq << endl;

    std::cout << "\nTest completed successfully!\n";
}
