#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;

template <class T>
class Queue
{ 
    private:
        T* queue;
        int front;
        int rear;
        int capacity;
        
    public:
        Queue(int c);
        ~Queue();
        bool IsEmpty() const;
        void Push(const T& item);    // add an item into the queue
        void Pop();    // delete an item 
        void print_queue();
        int get_size();
        int get_capacity();
        T* get_queue();
        T& Front() const;   // return top element
        T& Rear() const;    // return top element
        Queue<T> operator=(const Queue<T> &);
} ;

template <class T>
Queue<T> merge(Queue<T> Q1, Queue<T> Q2);

