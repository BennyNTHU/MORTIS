#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <Stack.h>
using namespace std;

template <class T>
Stack<T>::Stack(int c):Bag<T>(c)
{
    if (c < 1)
        throw "Stack capacity must be > 0";
    this->arr = new T[c];
    this->top = -1; // indicate empty stack
    this->capacity = c;
}

template <class T>
Stack<T>::~Stack()
{ 
    delete(this->arr);
}

template <class T>
inline T& Stack<T>:: Top() const
{
    if (*this.IsEmpty()) 
        throw "Stack is empty";
    return *this.arr[*this.top];
}

template <class T>
inline T* Stack<T>::get_stack()
{
    return this->arr;
}


template <class T>
void Stack<T>::print_stack()
{
    T* q = this->get_stack();
    cout << "The stack has: ";
    for (int i=0; i<=this->top; i++)
        cout << q[i] << " , ";
    cout << endl;
}
