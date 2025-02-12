#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <Queue.h>
using namespace std;

template <class T>
Queue<T>::Queue(int c)
{ 
    capacity = c;
    if (capacity < 1) 
        throw "Queue capacity must be > 0";
    queue= new T[capacity];
    front = 0; // indicate empty stack
    rear = 0;
}

template <class T>
Queue<T>::~Queue()
{ 
    delete(queue);
}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
    return front == rear;
}

template <class T>
void Queue<T>::Push(const T& x) // add x to stack
{
    if ((rear+1)%capacity == front) 
    {   
        T* newQu = new T[2*capacity];
        int start = (front+1) % capacity;

        if(start<2)
           copy(queue+start, queue+start+capacity-1, newQu);
        else
        {
           copy(queue+start, queue+capacity, newQu);
           copy(queue, queue+rear+1,newQu+capacity-start);
        }

        front = 2*capacity - 1;
        rear = capacity -2;
        delete[] queue;
        queue = newQu;
    }
    rear = (rear+1)%capacity;  
    queue[rear] = x;
}

template <class T>
void Queue<T>::Pop( ) 
{
    if (IsEmpty()) 
        throw "Queue is empty, cannot delete";	
    front = (front + 1) % capacity;
    queue[front].~T(); // destructor for T
}

template <class T>
void Queue<T>::print_queue()
{
    cout << "The queue has: ";
    for (int i=front+1; i<=rear; i++)
        cout << queue[i] << " , ";
    cout << endl;
}

template <class T>
int Queue<T>::get_size()
{
    return rear-front;
}

template <class T>
int Queue<T>::get_capacity()
{
    return capacity;
}

template <class T>
inline T* Queue<T>::get_queue()
{
    return queue;
}

template <class T>
inline T& Queue<T>::Front() const
{
    if (IsEmpty()) 
        throw "Queue is empty. No front element.";
    return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const
{
    if (IsEmpty()) 
        throw "Queue is empty. No rear element.";
    return queue[rear];
}

template <class T>
Queue<T> Queue<T>::operator=(const Queue<T> &Q) // overload assignment
{
    front = Q.front;    // copy every attributes
    rear = Q.rear;
    capacity = Q.capacity;
    queue = Q.queue;

    return *this;
}

template <class T>
Queue<T> merge(Queue<T> Q1, Queue<T> Q2) 
{
    Queue<T> M(Q1.get_capacity()+Q2.get_capacity());

    while(!Q1.IsEmpty() || !Q2.IsEmpty())
    {
        if(!Q1.IsEmpty()) // Q1 is not empty
        {
            M.Push(Q1.Front());
            Q1.Pop();
        }
        if(!Q2.IsEmpty()) // Q2 is not empty
        {
            M.Push(Q2.Front());
            Q2.Pop();
        }
    }
    return M;
}

#endif