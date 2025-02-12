#ifndef STACK
#define STACK

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include "../Bag/Bag.h"
using namespace std;


template <class T>
class Stack: public Bag<T>
{
    public:
        Stack (int c);
        ~Stack();
        T& Top() const;
        void print_stack();
        T* get_stack();
};

#endif