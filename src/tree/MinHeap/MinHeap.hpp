#ifndef MINHEAP
#define MINHEAP

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

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

template <class T>
class MinHeap: public MinPQ<T> 
{
    private:
        T* heap;      // element array
        int heapSize; // number of elements in heap
        int capacity; // size of the element array
    
    public:
        // constructor and destructor
        MinHeap(int theCapacity = 10);  // constructor
        ~MinHeap();  // virtual destructor

        // properties
        bool IsEmpty() const; //return true iff empty
        const T& Top() const; //return reference to the min
        T* get_heap();
        int get_size();
        int get_capacity();

        // push and pop
        void Push(const T&);
        void Pop();
};

template <class T>
void ChangeSize1D (T*&, const int, const int);  // change the array size to newSize