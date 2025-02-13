#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;

template <class T> class ChainIterator;

/* iterator */
class ChainIterator
{
    private:  
        Node<T>* current;

    public:
        //Constructor
        ChainIterator(Node<T>* startNode = 0) 
        {
            current = startNode;
        }

        //Dereferencing operators
        T& operator *() const 
        {
            return current -> data;
        }
        T* operator ->() const 
        {
            return &current -> data;
        }

        //Increment
        ChainIterator& operator ++()    //preincrement
        {
            current = current ->link; 
            return *this;
        }
        ChainIterator operator ++(int) //postincrement
        {
            ChainIterator copy = *this;
            ++(*this); 
            return copy;
        }

        //Equality test
        bool operator!=(const ChainIterator r)
        {
            return current != r.current;
        }
        bool operator==(const ChainIterator r)
        {
            return current == r.current;
        }
    };