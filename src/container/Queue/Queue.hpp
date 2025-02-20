#ifndef QUEUE
#define QUEUE

#include "../Bag/Bag.hpp"  // Inherits from Bag

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using namespace std;

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

using MORTISInvariant = std::variant<int, char, float, bool, double, std::string,
    GeneralArray<MIXED_TYPE>, Polynomial, SparseMatrix, String>;

template <typename T>
class Queue : public Bag<T>
{
    private:
        int front; // Tracks the front of the queue
        int rear;  // Tracks the rear of the queue
        int size;

    public:
        // Constructor and Destructor
        Queue(int capacity = 10);
        ~Queue();   // Destructor

        // Manipulation
        void Push(const T& x);    // Adds an element to the back of the queue
        void Pop();               // Removes an element from the front of the queue

        // Getters
        int getFront() const;   // Getters for front index
        int getRear() const;    // Getters for rear index
        T Front() const;        // Returns the front element of the queue
        T Rear() const;         // Returns the rear element of the queue
        
        // Properties
        bool IsEmpty() const;   // Checks if the queue is empty

        // Overloading operator
        template <typename U> friend std::ostream& operator<<(std::ostream& os, const Queue<U>& s); // Prints the queue elements in a readable format
};

#endif
