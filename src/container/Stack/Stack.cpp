#include "Stack.hpp"
#include <stdexcept>
#include <iostream>
#include "../../tree/BinaryTreeNode/BinaryTreeNode.hpp"

// =======================================
// Constructors
// =======================================

template <class T>
Stack<T>::Stack() : Bag<T>() {}  // Default constructor calling Bag's default constructor

// Constructor: Initializes the stack with a given capacity using Bag's constructor
template <class T>
Stack<T>::Stack(int initial_capacity) : Bag<T>(initial_capacity) {}

// =======================================
// Manipulation
// =======================================

// Push an element onto the stack (calls Bag's Push)
template <class T>
void Stack<T>::Push(const T& x) 
{
    this->Bag<T>::Push(x);
}

// Pop the top element from the stack
template <class T>
void Stack<T>::Pop() 
{
    if (this->IsEmpty()) 
    {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    }
    this->Bag<T>::Pop();
}

// =======================================
// Getters
// =======================================

// Get the top element of the stack without removing it
template <class T>
T Stack<T>::Top() const 
{
    if (this->IsEmpty()) 
    {
        throw std::out_of_range("Stack is empty. Cannot retrieve top element.");
    }
    return this->getArr()[this->Element() - 1]; // Last inserted element
}

// =======================================
// overloading operator
// =======================================

// Overload << operator to print the stack
template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) 
{
    if (s.IsEmpty()) 
    {
        os << "Stack is empty.";
        return os;
    }

    // Get the stack array
    T* temp = s.getArr();

    for (int i = s.Element() - 1; i >= 0; --i)  // Print from top to bottom
    {  
        os << (s.Element() - i) << ". ";  // Line numbering
        
        // Handle std::variant properly
        if constexpr (std::is_same_v<T, MORTISInvariant>) 
        {
            std::visit([&os](const auto& val) { os << val; }, temp[i]);
        } 
        else 
        {
            os << temp[i];
        }

        // Mark the top element
        if (i == s.Element() - 1) 
        {
            os << " <- top";
        }

        os << std::endl;
    }

    return os;
}

// =======================================
// Explicit instantiations
// =======================================

template class Stack<int>;
template class Stack<bool>;
template class Stack<char>;
template class Stack<float>;
template class Stack<double>;
template class Stack<std::string>;
template class Stack<MORTISInvariant>;
template class Stack<GeneralArray<MIXED_TYPE>>;
template class Stack<Polynomial>;
template class Stack<SparseMatrix>;
template class Stack<String>;
template class Stack<MIXED_TYPE>;

// Explicit instantiation for operator<<
template std::ostream& operator<<(std::ostream& os, const Stack<int>&);
template std::ostream& operator<<(std::ostream& os, const Stack<bool>&);
template std::ostream& operator<<(std::ostream& os, const Stack<char>&);
template std::ostream& operator<<(std::ostream& os, const Stack<float>&);
template std::ostream& operator<<(std::ostream& os, const Stack<double>&);
template std::ostream& operator<<(std::ostream& os, const Stack<std::string>&);
template std::ostream& operator<<(std::ostream& os, const Stack<MORTISInvariant>&);

// for trees
template class Stack<BinaryTreeNode<int>*>;
template class Stack<BinaryTreeNode<char>*>;
template class Stack<BinaryTreeNode<float>*>;
template class Stack<BinaryTreeNode<bool>*>;
template class Stack<BinaryTreeNode<double>*>;
template class Stack<BinaryTreeNode<std::string>*>;