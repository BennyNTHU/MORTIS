#ifndef CHAINITERATOR
#define CHAINITERATOR

#include <iostream>
#include <cstring>
#include "../Node/Node.hpp"
using namespace std;

/* iterator */
template <class T> 
class ChainIterator
{
    private:  
        Node<T>* current;

    public:
        //Constructor
        explicit ChainIterator(Node<T>* startNode = nullptr);

        // Getters
        Node<T>* getCurrent() const;          // Return next node pointer

        //Dereferencing operators
        const T& operator*() const;
        const T* operator->() const;

        //Increment
        ChainIterator<T>& operator++();    //preincrement
        ChainIterator<T> operator++(int);  //postincrement

        //Equality test
        bool operator!=(const ChainIterator<T>& r) const;
        bool operator==(const ChainIterator<T>& r) const;
};

#endif

