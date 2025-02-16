#ifndef MINHEAP
#define MINHEAP

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

template <class T> class MinHeap;
template <class T> class MaxPQ;

template <class T>
class MinPQ 
{
    public:
        virtual ~MinPQ() {}  // virtual destructor
        virtual bool IsEmpty() const = 0; //return true iff empty
        virtual const T& Top() const = 0; //return reference to the min
        virtual void Push(const T&) = 0;
        virtual void Pop() = 0;
};
