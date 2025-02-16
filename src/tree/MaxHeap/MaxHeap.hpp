#ifndef MAXHEAP
#define MAXHEAP

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

template <class T>
class MaxHeap: public MaxPQ<T> 
{
    private:
        T* heap;      // element array
        int heapSize; // number of elements in heap
        int capacity; // size of the element array
    
    public:
        // constructor and destructor
        MaxHeap(int theCapacity = 10);  // constructor
        ~MaxHeap();  // virtual destructor

        // properties
        bool IsEmpty() const; //return true iff empty
        const T& Top() const; //return reference to the max
        T* get_heap();
        int get_size();
        int get_capacity();

        // push and pop
        void Push(const T&);
        void Pop();
};

template <class T>
void ChangeSize1D (T*&, const int, const int);  // change the array size to newSize