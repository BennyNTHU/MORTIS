#ifndef DLITERATOR
#define DLITERATOR

#include "../DoubleNode/DoubleNode.hpp"
#include "../ChainIterator/ChainIterator.hpp"

template <typename T>
class DLIterator : public ChainIterator<T> 
{
    public:
        // Constructor
        DLIterator(DoubleNode<T>* startNode = nullptr);

        // Move operators
        DLIterator<T>& operator++();      // Pre-increment
        virtual ChainIterator<T> operator++(int) override; // Post-increment
        DLIterator<T>& operator--();      // Pre-decrement
        DLIterator<T> operator--(int);    // Post-decrement

        // Get current node
        DoubleNode<T>* getCurrent() const;

    private:
        using ChainIterator<T>::current; // Access the inherited member
};

#endif // DLITERATOR
