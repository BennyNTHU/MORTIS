#include "CircularDoubleList.hpp"

// Utility function to copy elements from another CircularDoubleList
template <typename T>
void CircularDoubleList<T>::CopyFrom(const CircularDoubleList<T>& other) 
{
    if (!other.GetFirst()) return;  // If `other` is empty, do nothing

    // Create a copy of the first node
    this->SetFirst(new DoubleNode<T>(other.GetFirst()->getData(), nullptr, nullptr));
    this->SetLast(this->GetFirst());

    DoubleNode<T>* currentOther = static_cast<DoubleNode<T>*>(other.GetFirst()->getLink());
    while (currentOther != other.GetFirst()) 
    {
        DoubleNode<T>* newNode = new DoubleNode<T>(currentOther->getData(), nullptr, this->GetLast());
        this->GetLast()->setLink(newNode);
        this->SetLast(newNode);
        currentOther = static_cast<DoubleNode<T>*>(currentOther->getLink());
    }

    this->GetLast()->setLink(this->GetFirst());
    this->GetFirst()->setPrev(this->GetLast());
}

// Constructor: Initialize circular doubly linked list
template <typename T>
CircularDoubleList<T>::CircularDoubleList() : DoublyLinkedList<T>() 
{
    if (this->GetFirst()) 
    {
        this->GetLast()->setLink(this->GetFirst());
        this->GetFirst()->setPrev(this->GetLast());
    }
}

// Copy Constructor: Create a new circular doubly linked list from an existing one
template <typename T>
CircularDoubleList<T>::CircularDoubleList(const CircularDoubleList<T>& other) 
{
    this->SetFirst(nullptr);
    this->SetLast(nullptr);
    CopyFrom(other);
}

// Destructor: Properly delete all elements in the list
template <typename T>
CircularDoubleList<T>::~CircularDoubleList() 
{
    if (!this->GetFirst()) return;

    DoubleNode<T>* current = this->GetFirst();
    DoubleNode<T>* nextNode = nullptr;

    do 
    {
        nextNode = static_cast<DoubleNode<T>*>(current->getLink());
        delete current;
        current = nextNode;
    } while (current != this->GetFirst());

    this->SetFirst(nullptr);
    this->SetLast(nullptr);
}

// Insert at the back of the list
template <typename T>
void CircularDoubleList<T>::InsertBack(const T& e) 
{
    DoubleNode<T>* newNode = new DoubleNode<T>(e, nullptr, this->GetLast());

    if (!this->GetFirst())  // If the list is empty 
    {  
        this->SetFirst(newNode);
        this->SetLast(newNode);
    } 
    else 
    {
        this->GetLast()->setLink(newNode);
        newNode->setPrev(this->GetLast());
        this->SetLast(newNode);
    }

    // Maintain circular linkage
    this->GetLast()->setLink(this->GetFirst());
    this->GetFirst()->setPrev(this->GetLast());
}

// Insert at the front of the list
template <typename T>
void CircularDoubleList<T>::InsertFront(const T& e) 
{
    DoubleNode<T>* newNode = new DoubleNode<T>(e, this->GetFirst(), this->GetLast());

    if (!this->GetFirst())  // If the list is empty
    {
        this->SetFirst(newNode);
        this->SetLast(newNode);
    } 
    else 
    {
        this->GetFirst()->setPrev(newNode);
        this->GetLast()->setLink(newNode);
        this->SetFirst(newNode);
    }

    // Maintain circular linkage
    this->GetLast()->setLink(this->GetFirst());
    this->GetFirst()->setPrev(this->GetLast());
}

// Delete from the back of the list
template <typename T>
void CircularDoubleList<T>::DeleteBack() 
{
    if (!this->GetFirst()) return;  // Empty list

    DoubleNode<T>* temp = this->GetLast();

    if (this->GetFirst() == this->GetLast())    // Only one node 
    {  
        this->SetFirst(nullptr);
        this->SetLast(nullptr);
    } 
    else 
    {
        this->SetLast(this->GetLast()->getPrev());
        this->GetLast()->setLink(this->GetFirst());
        this->GetFirst()->setPrev(this->GetLast());
    }

    delete temp;
}

// Delete from the front of the list
template <typename T>
void CircularDoubleList<T>::DeleteFront() 
{
    if (!this->GetFirst()) return;  // Empty list

    DoubleNode<T>* temp = this->GetFirst();

    if (this->GetFirst() == this->GetLast())    // Only one node 
    {  
        this->SetFirst(nullptr);
        this->SetLast(nullptr);
    } 
    else 
    {
        this->SetFirst(static_cast<DoubleNode<T>*>(this->GetFirst()->getLink()));
        this->GetFirst()->setPrev(this->GetLast());
        this->GetLast()->setLink(this->GetFirst());
    }

    delete temp;
}

// Concatenate another circular doubly linked list
template <typename T>
void CircularDoubleList<T>::Concatenate(CircularDoubleList<T>& b) 
{
    if (!b.GetFirst())  // If `b` is empty, do nothing 
        return;  

    if (!this->GetFirst())  // If `this` list is empty, simply copy `b` 
    {  
        CopyFrom(b);
        return;
    }

    // Connect last of `this` to first of `b`
    this->GetLast()->setLink(b.GetFirst());
    b.GetFirst()->setPrev(this->GetLast());

    // Connect last of `b` to first of `this`
    this->GetFirst()->setPrev(b.GetLast());
    b.GetLast()->setLink(this->GetFirst());

    // Update `this` last pointer
    this->SetLast(b.GetLast());

    // Make `b` an empty list
    b.SetFirst(nullptr);
    b.SetLast(nullptr);
}

// Return the length of the circular doubly linked list using DLIterator
template <typename T>
int CircularDoubleList<T>::Length() const 
{
    if (!this->GetFirst())  // If the list is empty, return 0 
        return 0;  

    int count = 0;
    DLIterator<T> it = this->begin();

    do 
    {
        count++;
        ++it;
    } while (it != this->begin());

    return count;
}

template <typename T>
void CircularDoubleList<T>::Reverse() 
{
    if (!this->GetFirst() || this->GetFirst()->getLink() == this->GetFirst()) {
        return; // If the list is empty or has only one node, do nothing.
    }

    DoubleNode<T>* current = static_cast<DoubleNode<T>*>(this->GetFirst());
    DoubleNode<T>* temp = nullptr;

    do 
    {
        temp = static_cast<DoubleNode<T>*>(current->getPrev());  // Store previous node
        current->setPrev(static_cast<DoubleNode<T>*>(current->getLink()));  // Swap prev and next
        current->setLink(temp);
        current = static_cast<DoubleNode<T>*>(current->getPrev()); // Move to the next node in the reversed order
    } while (current != this->GetFirst()); // Stop when a full cycle is completed

    // Swap `first` and `last` pointers
    this->SetLast(this->GetFirst());
    this->SetFirst(static_cast<DoubleNode<T>*>(temp->getPrev()));  // Last processed node becomes new first
}

// Assignment Operator: Assign contents of one list to another
template <typename T>
CircularDoubleList<T>& CircularDoubleList<T>::operator=(const CircularDoubleList<T>& other) 
{
    if (this != &other) 
    {
        this->~CircularDoubleList();  // Explicitly call destructor logic
        CopyFrom(other);
    }
    return *this;
}

// Overload the << operator to print CircularDoubleList
template <typename T>
std::ostream& operator<<(std::ostream& out, const CircularDoubleList<T>& list) 
{
    if (!list.GetFirst()) 
    {
        out << "Empty Circular Doubly Linked List";
        return out;
    }

    DLIterator<T> it = list.begin();
    do 
    {
        out << *it << " <-> ";
        ++it;
    } while (it != list.begin());

    out << "(Back to first)";
    return out;
}

// Explicit instantiation
template std::ostream& operator<<(std::ostream&, const CircularDoubleList<int>&);
template std::ostream& operator<<(std::ostream&, const CircularDoubleList<bool>&);
template std::ostream& operator<<(std::ostream&, const CircularDoubleList<char>&);
template std::ostream& operator<<(std::ostream&, const CircularDoubleList<float>&);
template std::ostream& operator<<(std::ostream&, const CircularDoubleList<double>&);
template std::ostream& operator<<(std::ostream&, const CircularDoubleList<std::string>&);


// Explicit template instantiation
template class CircularDoubleList<int>;
template class CircularDoubleList<bool>;
template class CircularDoubleList<char>;
template class CircularDoubleList<float>;
template class CircularDoubleList<double>;
template class CircularDoubleList<std::string>;
