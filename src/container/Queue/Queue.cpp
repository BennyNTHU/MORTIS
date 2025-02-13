#include "Queue.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor: Initializes the queue with a given capacity
Queue::Queue(int capacity) : Bag(capacity), front(0), rear(-1), size(0) {}

// Destructor
Queue::~Queue() {}

// Push: Adds an element to the back of the queue
void Queue::Push(const MORTISInvariant& x) 
{
    if (size == capacity) 
    {
        // Expand capacity and shift elements correctly
        ChangeSize1D(arr, capacity, capacity * 2);
        capacity *= 2;
    }

    // Move rear forward for new insertion
    rear++;
    arr[rear] = x;
    size++;

    // If first element is inserted, reset front
    if (size == 1) 
    {
        front = 0;
    }
}

// Pop: Removes an element from the front of the queue
void Queue::Pop() 
{
    if (IsEmpty()) 
    {
        throw runtime_error("Queue is empty, cannot dequeue.");
    }

    // Move front forward
    front++;
    size--;

    // Reset front and rear when queue becomes empty
    if (IsEmpty()) 
    {
        front = 0;
        rear = -1;
    }
}

// Front: Returns the first element in the queue
MORTISInvariant Queue::Front() const 
{
    if (IsEmpty()) 
    {
        throw runtime_error("Queue is empty, no front element.");
    }
    return arr[front];
}

// Rear: Returns the last element in the queue
MORTISInvariant Queue::Rear() const 
{
    if (IsEmpty()) 
    {
        throw runtime_error("Queue is empty, no rear element.");
    }
    return arr[rear];
}

// IsEmpty: Checks if the queue is empty
bool Queue::IsEmpty() const 
{
    return size == 0;
}

// PrintQueue: Prints the queue elements in the specified format
void Queue::PrintQueue() const 
{
    if (IsEmpty()) 
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue contents:" << endl;
    for (int i = 0; i < size; i++) 
    {
        int index = front + i; // Linear traversal
        cout << i + 1 << ". ";
        visit([](auto&& arg) { cout << arg; }, arr[index]);

        if (i == 0)
            cout << " <- front";
        else if (i == size - 1)
            cout << " <- rear";
        cout << endl;
    }
}

// Getters for front index
int Queue::getFront() const 
{ 
    return front; 
}

// Getters for rear index
int Queue::getRear() const 
{ 
    return rear; 
}
