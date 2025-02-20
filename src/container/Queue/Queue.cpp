#include "Queue.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

// ==========================================
// Constructor and Destructor
// ==========================================

// Constructor: Initializes the queue with a given capacity
template <class T>
Queue<T>::Queue(int capacity): Bag<T>(capacity), front(0), rear(-1), size(0) {}

// Destructor
template <class T>
Queue<T>::~Queue() {}

// ==========================================
// Manipulation
// ==========================================

// Push: Adds an element to the back of the queue
template <class T>
void Queue<T>::Push(const T& x) 
{
    if (size == this->getCapacity())  // Use getCapacity()
    {
        T* tempArr = this->getArr();  // Create a local reference
        ChangeSize1D(tempArr, this->getCapacity(), this->getCapacity() * 2);
    }

    rear = (rear + 1) % this->getCapacity();
    this->getArr()[rear] = x;  // Use getArr() to access array
    size++;
}

// Pop: Removes an element from the front of the queue
template <class T>
void Queue<T>::Pop() 
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

// ==========================================
// Getters
// ==========================================

// Getters for front index
template <class T>
int Queue<T>::getFront() const 
{ 
    return front; 
}

// Getters for rear index
template <class T>
int Queue<T>::getRear() const 
{ 
    return rear; 
}

// Front: Returns the first element in the queue
template <class T>
T Queue<T>::Front() const 
{
    return this->getArr()[front];  // Use getArr() properly
}

// Rear: Returns the last element in the queue
template <class T>
T Queue<T>::Rear() const 
{
    return this->getArr()[rear];  // Use getArr() properly
}

// ==========================================
// Properties
// ==========================================

// IsEmpty: Checks if the queue is empty
template <class T>
bool Queue<T>::IsEmpty() const 
{
    return size == 0;
}

// ==========================================
// Overloading operator
// ==========================================

// Prints the queue elements in the specified format
template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q) 
{
    if (q.IsEmpty()) 
    {
        cout << "Queue is empty." << endl;
        return os;
    }

    cout << "Queue contents:" << endl;
    T* temp = q.getArr();

    for (int i = 0; i < q.size; i++)
    {
        int index = q.getFront() + i; // Linear traversal
        cout << i + 1 << ". ";

        // Handle std::variant properly
        if constexpr (std::is_same_v<T, MORTISInvariant>) 
            std::visit([&os](const auto& val) { os << val; }, temp[i]);
        else 
            os << temp[i];

        if (i == 0)
            cout << " <- front";
        else if (i == q.size - 1)
            cout << " <- rear";
        
        cout << endl;
    }

    return os;
}

// ==========================================
// Explicit instantiations
// ==========================================

template class Queue<int>;
template class Queue<bool>;
template class Queue<char>;
template class Queue<float>;
template class Queue<double>;
template class Queue<std::string>;
template class Queue<MORTISInvariant>;
template class Queue<GeneralArray<MIXED_TYPE>>;
template class Queue<Polynomial>;
template class Queue<SparseMatrix>;
template class Queue<String>;
template class Queue<MIXED_TYPE>;

// Explicit instantiation for operator<<
template std::ostream& operator<<(std::ostream& os, const Queue<int>&);
template std::ostream& operator<<(std::ostream& os, const Queue<bool>&);
template std::ostream& operator<<(std::ostream& os, const Queue<char>&);
template std::ostream& operator<<(std::ostream& os, const Queue<float>&);
template std::ostream& operator<<(std::ostream& os, const Queue<double>&);
template std::ostream& operator<<(std::ostream& os, const Queue<std::string>&);
template std::ostream& operator<<(std::ostream& os, const Queue<MORTISInvariant>&);
