#include "CirQue.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

// ==========================================
// Constructor
// ==========================================

// Constructor: Properly initialize CirQue by calling the base class constructor
template <class T>
CirQue<T>::CirQue(int cap) : DeQue<T>(cap)  // Call the DeQue constructor
{
    this->front = -1;
    this->rear = -1;
    this->count = 0;
}   

// Destructor: The base class handles memory deallocation, no need to delete `arr`
template <class T>
CirQue<T>::~CirQue() {}

// ==========================================
// Manipulation
// ==========================================

// Insert at front
template <class T>
void CirQue<T>::PushFront(const T& x) 
{
    if (this->count == this->capacity) 
    {
        throw std::overflow_error("CirQue is full.");
    }

    if (this->IsEmpty()) 
    {
        this->front = this->rear = 0;
    } 
    else 
    {
        this->front = (this->front - 1 + this->capacity) % this->capacity;
    }

    this->arr[this->front] = x;
    this->count++;
}

// Insert at rear (corrected)
template <class T>
void CirQue<T>::PushBack(const T& x) 
{
    if (this->count == this->capacity) 
    {
        throw std::overflow_error("CirQue is full.");
    }

    if (this->IsEmpty()) 
    {
        // If the queue is empty, properly initialize both pointers
        this->front = this->rear = 0;
    } 
    else 
    {
        // Correctly move rear using modulo operation
        this->rear = (this->rear + 1) % this->capacity;
    }

    this->arr[this->rear] = x;  // Insert at the new rear position
    this->count++;
}

// Remove from front
template <class T>
void CirQue<T>::PopFront() 
{
    if (this->IsEmpty()) 
    {
        throw std::underflow_error("CirQue is empty.");
    }

    if (this->count == 1)  // Only one element
    {  
        this->front = this->rear = -1;
    } 
    else 
    {
        this->front = (this->front + 1) % this->capacity;
    }

    this->count--;
}

// Remove from rear
template <class T>
void CirQue<T>::PopBack() 
{
    if (this->IsEmpty()) 
    {
        throw std::underflow_error("CirQue is empty.");
    }

    if (this->count == 1)  // Only one element
    {  
        this->front = this->rear = -1;
    } 
    else 
    {
        this->rear = (this->rear - 1 + this->capacity) % this->capacity;
    }

    this->count--;
}

// ==========================================
// Getters
// ==========================================

// Get front element
template <class T>
T CirQue<T>::Front() const 
{
    if (this->IsEmpty()) 
    {
        throw underflow_error("CirQue is empty.");
    }

    return this->arr[this->front];
}

// Get rear element
template <class T>
T CirQue<T>::Back() const 
{
    if (this->IsEmpty()) 
    {
        throw underflow_error("CirQue is empty.");
    }

    return this->arr[this->rear];
}

// ==========================================
// Properties
// ==========================================

// Check if queue is empty
template <class T>
bool CirQue<T>::IsEmpty() const 
{
    return (this->count == 0);
}

// Return current queue size
template <class T>
int CirQue<T>::Size() const 
{
    return this->count;
}

// ==========================================
// Overloading operator
// ==========================================

// Prints the queue elements in the specified format
template <class T>
std::ostream& operator<<(std::ostream& os, const CirQue<T>& q) 
{
    if (q.IsEmpty()) 
    {
        os << "CirQue is empty." << std::endl;
        return os;
    }

    os << "CirQue contents:" << std::endl;
    T* temp = q.getArr();
    
    for (int i = 0; i < q.Size(); i++)
    {
        int index = (q.getFront() + i) % q.getCapacity(); // Handle circular indexing
        os << i + 1 << ". ";

        // Handle std::variant properly
        if constexpr (std::is_same_v<T, MORTISInvariant>) 
            std::visit([&os](const auto& val) { os << val; }, temp[index]);
        else 
            os << temp[index];

        if (index == q.getFront())
            os << " <- front";
        else if (index == q.getRear())
            os << " <- rear";
        
        os << std::endl;
    }

    return os;
}

// ==========================================
// Explicit instantiations
// ==========================================

template class CirQue<int>;
template class CirQue<bool>;
template class CirQue<char>;
template class CirQue<float>;
template class CirQue<double>;
template class CirQue<std::string>;
template class CirQue<MORTISInvariant>;
template class CirQue<GeneralArray<MIXED_TYPE>>;
template class CirQue<Polynomial>;
template class CirQue<SparseMatrix>;
template class CirQue<String>;
template class CirQue<MIXED_TYPE>;

// Explicit instantiation for operator<<
template std::ostream& operator<<(std::ostream& os, const CirQue<int>&);
template std::ostream& operator<<(std::ostream& os, const CirQue<bool>&);
template std::ostream& operator<<(std::ostream& os, const CirQue<char>&);
template std::ostream& operator<<(std::ostream& os, const CirQue<float>&);
template std::ostream& operator<<(std::ostream& os, const CirQue<double>&);
template std::ostream& operator<<(std::ostream& os, const CirQue<std::string>&);
template std::ostream& operator<<(std::ostream& os, const CirQue<MORTISInvariant>&);
