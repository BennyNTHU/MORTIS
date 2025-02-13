#ifndef QUEUE
#define QUEUE

#include "../Bag/Bag.hpp"  // Inherits from Bag

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

class Queue : public Bag 
{
    private:
        int front; // Tracks the front of the queue
        int rear;  // Tracks the rear of the queue
        int size;

    public:
        // Constructor
        Queue(int capacity = 10);

        // Destructor
        ~Queue();

        // Adds an element to the back of the queue
        void Push(const MORTISInvariant& x);

        // Removes an element from the front of the queue
        void Pop();

        // Returns the front element of the queue
        MORTISInvariant Front() const;

        // Returns the rear element of the queue
        MORTISInvariant Rear() const;

        // Checks if the queue is empty
        bool IsEmpty() const;

        // Prints the queue elements in a readable format
        void PrintQueue() const;

        // Getters for front index
        int getFront() const;

        // Getters for rear index
        int getRear() const;
};

#endif
