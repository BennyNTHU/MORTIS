#include "DeQue.hpp"
#include <iostream>
#include <stdexcept>

// Constructor: Initializes the queue with a given capacity
template <class T>
DeQue<T>::DeQue(int capacity): Bag<T>(capacity), front(0), rear(-1), size(0) {}

// Destructor
template <class T>
DeQue<T>::~DeQue() {}

// Push element to the front
template <class T>
void DeQue<T>::PushFront(const T& x)
{
    if (this->top + 1 == this->capacity)  // Check if resizing is needed
    {
        ChangeSize1D(this->arr, this->capacity, this->capacity * 2);
        this->capacity *= 2;
    }

    // Shift elements to the right
    for (int i = this->top; i >= 0; --i)
    {
        this->arr[i + 1] = this->arr[i];
    }

    this->arr[0] = x; // Insert new element at the front
    this->top++;
}

// Push element to the back (same as Bag's `Push`)
template <class T>
void DeQue<T>::PushBack(const T& x)
{
    this->Push(x);  // Explicitly call the inherited `Push()` method
}

// Pop element from the front
template <class T>
void DeQue<T>::PopFront()
{
    if (this->IsEmpty())
    {
        throw std::out_of_range("DeQue is empty.");
    }

    // Shift elements to the left
    for (int i = 0; i < this->top; ++i)
    {
        this->arr[i] = this->arr[i + 1];
    }

    this->top--; // Remove the first element
}

// Pop element from the back (same as Bag's `Pop`)
template <class T>
void DeQue<T>::PopBack()
{
    this->Pop();  // Explicitly call the inherited `Pop()` method
}

// Getters for front index
template <class T>
int DeQue<T>::getFront() const 
{ 
    return front; 
}

// Getters for rear index
template <class T>
int DeQue<T>::getRear() const 
{ 
    return rear; 
}

// Return front element
template <class T>
T DeQue<T>::Front() const
{
    if (this->IsEmpty())
    {
        throw std::out_of_range("DeQue is empty.");
    }

    return this->arr[0];
}

// Return back element
template <class T>
T DeQue<T>::Back() const
{
    if (this->IsEmpty())
    {
        throw std::out_of_range("DeQue is empty.");
    }

    return this->arr[this->top];
}

// Check if deque is empty
template <class T>
bool DeQue<T>::IsEmpty() const
{
    return this->Bag<T>::IsEmpty();  // Explicitly call `Bag<T>::IsEmpty()`
}

// Prints the queue elements in the specified format
template <class T>
std::ostream& operator<<(std::ostream& os, const DeQue<T>& dq) 
{
    if (dq.IsEmpty()) 
    {
        os << "DeQue is empty." << std::endl;
        return os;
    }

    os << "DeQue contents:" << std::endl;
    T* temp = dq.getArr();

    for (int i = 0; i <= dq.top; i++)  // Deque is indexed from 0 to top
    {
        os << i + 1 << ". ";

        // Handle std::variant properly
        if constexpr (std::is_same_v<T, MORTISInvariant>) 
        {
            std::visit([&os](const auto& val) { os << val; }, temp[i]);
        }
        else 
        {
            os << temp[i];
        }

        // Indicate front and rear positions
        if (i == 0)
            os << " <- front";
        else if (i == dq.top)
            os << " <- rear";

        os << std::endl;
    }

    return os;
}

// Explicit instantiations
template class DeQue<int>;
template class DeQue<bool>;
template class DeQue<char>;
template class DeQue<float>;
template class DeQue<double>;
template class DeQue<std::string>;
template class DeQue<MORTISInvariant>;
template class DeQue<GeneralArray<MIXED_TYPE>>;
template class DeQue<Polynomial>;
template class DeQue<SparseMatrix>;
template class DeQue<String>;
template class DeQue<MIXED_TYPE>;

// Explicit instantiation for operator<<
template std::ostream& operator<<(std::ostream& os, const DeQue<int>&);
template std::ostream& operator<<(std::ostream& os, const DeQue<bool>&);
template std::ostream& operator<<(std::ostream& os, const DeQue<char>&);
template std::ostream& operator<<(std::ostream& os, const DeQue<float>&);
template std::ostream& operator<<(std::ostream& os, const DeQue<double>&);
template std::ostream& operator<<(std::ostream& os, const DeQue<std::string>&);
template std::ostream& operator<<(std::ostream& os, const DeQue<MORTISInvariant>&);
