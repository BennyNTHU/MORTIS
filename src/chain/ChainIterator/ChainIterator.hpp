#ifndef CHAINITERATOR
#define CHAINITERATOR

#include <iostream>
#include <cstring>
#include "../Node/Node.hpp"
using namespace std;

/* iterator */
template <typename T> 
class ChainIterator
{
    protected:
        Node<T>* current;

    public:
        // Constructor
        explicit ChainIterator(Node<T>* startNode = nullptr);

        // Getters
        Node<T>* getCurrent() const;          // Return next node pointer

        // Dereferencing operators
        const T& operator*() const;
        const T* operator->() const;

        // Increment
        virtual ChainIterator<T>& operator++();    //preincrement
        virtual ChainIterator<T> operator++(int);  //postincrement

        // Equality test
        bool operator!=(const ChainIterator<T>& r) const;
        bool operator==(const ChainIterator<T>& r) const;
};

#endif

