#include <iostream>
#include "LinkedList.hpp"

using namespace std;

// ================================================
// Helper functions
// ================================================

// set first node
template <class T>
void LinkedList<T>::SetFirst(Node<T>* node)
{
    first = node;
}

// get first node
template <class T>
Node<T>* LinkedList<T>::GetFirst() const
{
    return first;
}

// Clear all nodes from the list
template <class T>
void LinkedList<T>::Clear() 
{
    Node<T>* deleteNode = first;

    while (deleteNode != nullptr) 
    {
        Node<T>* nextNode = deleteNode->getLink();
        delete deleteNode;
        deleteNode = nextNode;
    }
    first = nullptr;
}

// ================================================
// Constructor and destructors 
// ================================================

// Constructor: Initializes an empty linked list
template <class T>
LinkedList<T>::LinkedList() : first(nullptr) {}

// Destructor: Deletes all nodes in the linked list
template <class T>
LinkedList<T>::~LinkedList() 
{
    Clear(); // Ensures proper memory cleanup
}

// ================================================
// Insertion
// ================================================

// Insert an element at the front of the list
template <class T>
void LinkedList<T>::InsertFront(const T& e) 
{
    first = new Node<T>(e, first);
}

// Insert an element at the back of the list
template <class T>
void LinkedList<T>::InsertBack(const T& e) 
{
    if (!first) 
    {
        first = new Node<T>(e, nullptr);
        return;
    }
    ChainIterator<T> it = begin();
    while (it.getCurrent() && it.getCurrent()->getLink() != nullptr) 
    { 
        ++it; 
    }  // Stop at last node
    if (it.getCurrent()) 
    {
        it.getCurrent()->setLink(new Node<T>(e, nullptr)); // Add new node
    }
}

// Insert an element at a specific index
template <class T>
void LinkedList<T>::Insert(int i, T e) 
{
    if (i == 0) 
    {
        InsertFront(e);
        return;
    }

    Node<T>* current = first;
    for (int j = 0; j < i - 1 && current; j++) 
    {
        current = current->getLink();
    }

    if (!current) 
        throw runtime_error("Index out of bounds");

    current->setLink(new Node<T>(e, current->getLink()));  // FIXED
}

// ================================================
// Deletion
// ================================================

// Delete the front element
template <class T>
void LinkedList<T>::DeleteFront() 
{
    if (!first) 
        throw runtime_error("Cannot delete from an empty list");

    Node<T>* deleteNode = first;
    first = first->getLink();
    delete deleteNode;
}

// Delete the back element
template <class T>
void LinkedList<T>::DeleteBack() 
{
    if (!first) throw runtime_error("Cannot delete from an empty list");
    if (!first->getLink()) 
    {
        delete first;
        first = nullptr;
        return;
    }
    
    ChainIterator<T> prev = begin();
    ChainIterator<T> it = begin();
    ++it;  // Move second iterator ahead
    
    while (it.getCurrent()->getLink())  // Traverse to the last element
    { 
        ++prev;
        ++it;
    }
    
    delete it.getCurrent();
    prev.getCurrent()->setLink(nullptr); // FIXED
}

// Delete an element at a specific index
template <class T>
void LinkedList<T>::Delete(int i) 
{
    if (!first) 
        throw runtime_error("Cannot delete from an empty list");

    if (i == 0) 
    {
        DeleteFront();
        return;
    }

    Node<T>* current = first;

    for (int j = 0; j < i - 1 && current->getLink(); j++) 
    {
        current = current->getLink();
    }

    if (!current->getLink()) throw runtime_error("Index out of bounds");
    Node<T>* deleteNode = current->getLink();
    current->setLink(deleteNode->getLink());  // FIXED
    delete deleteNode;
}

// ================================================
// Return elements 
// ================================================

// Iterator support
template <typename T>
ChainIterator<T> LinkedList<T>::begin() const 
{
    return ChainIterator<T>(first);
}

template <typename T>
ChainIterator<T> LinkedList<T>::end() const 
{
    return ChainIterator<T>(nullptr);
}

// Get the node at a specific index
template <class T>
Node<T>* LinkedList<T>::Get(int i) 
{
    Node<T>* current = first;

    for (int j = 0; j < i && current; j++) 
    {
        current = current->getLink();
    }
    if (!current) 
        throw runtime_error("Index out of bounds");
    return current;
}

template <class T>
LinkedList<T> LinkedList<T>::GetSublist(int i, int j) 
{
    if (i < 0 || j < 0 || i > j || j >= this->Length()) 
    {
        throw std::out_of_range("Invalid indices for sublist");
    }

    LinkedList<T> sublist;

    // Use Get() to insert the elements from i to j
    for (int index = i; index <= j; ++index) 
    {
        Node<T>* currentNode = this->Get(index);  // Get the node at index
        sublist.InsertBack(currentNode->getData()); // Insert the data from the node
    }

    return sublist;
}

// ================================================
// Other functions
// ================================================

// IsEmpty function to check if the list is empty
template <class T>
bool LinkedList<T>::IsEmpty() const 
{
    return first == nullptr;
}

// Function to return the length of the linked list using ChainIterator
template <class T>
int LinkedList<T>::Length() 
{
    int count = 0;
    for (ChainIterator<T> it = this->begin(); it != this->end(); ++it) 
    {
        count++;
    }
    return count;
}

// Concatenate another linked list to this one
template <class T>
void LinkedList<T>::Concatenate(LinkedList<T>& b) 
{
    if (!b.first) return; // Nothing to concatenate

    ChainIterator<T> itB = b.begin();
    while (itB != b.end()) 
    {
        InsertBack(*itB); // Copy each node
        ++itB;
    }
}

// Reverse the linked list
template <class T>
void LinkedList<T>::Reverse() 
{
    Node<T>* prev = nullptr;
    Node<T>* curr = first;
    while (curr) 
    {
        Node<T>* next = curr->getLink();
        curr->setLink(prev);  // FIXED
        prev = curr;
        curr = next;
    }
    first = prev;
}

// ================================================
// Overloading
// ================================================

// Copy assignment operator (deep copy)
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) 
{
    if (this != &other) // Prevent self-assignment
    {  
        Clear();        // Clear existing list
        
        Node<T>* current = other.first;
        while (current) 
        {
            InsertBack(current->getData()); // Copy each node
            current = current->getLink();
        }
    }
    return *this;
}

// Overload == operator to compare two LinkedLists
template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const 
{
    Node<T>* currentA = first;
    Node<T>* currentB = other.first;

    while (currentA != nullptr && currentB != nullptr) 
    {
        if (currentA->getData() != currentB->getData()) 
        {
            return false;  // Data doesn't match
        }

        currentA = currentA->getLink();
        currentB = currentB->getLink();
    }

    return currentA == nullptr && currentB == nullptr;  // Both should be at the end
}

// Overload != operator to compare two LinkedLists
template <class T>
bool LinkedList<T>::operator!=(const LinkedList<T>& other) const 
{
    return !(*this == other);  // Not equal if == is false
}

// Overloaded output operator for LinkedList
template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) 
{
    for (auto it = list.begin(); it != list.end(); ++it) 
    {
        out << *it << " -> ";
    }
    out << "NULL";
    return out;
}

// ================================================
// Explicit instantiation
// ================================================

template std::ostream& operator<<(std::ostream&, const LinkedList<int>&);
template std::ostream& operator<<(std::ostream&, const LinkedList<bool>&);
template std::ostream& operator<<(std::ostream&, const LinkedList<char>&);
template std::ostream& operator<<(std::ostream&, const LinkedList<float>&);
template std::ostream& operator<<(std::ostream&, const LinkedList<double>&);
template std::ostream& operator<<(std::ostream&, const LinkedList<std::string>&);

template class LinkedList<int>;
template class LinkedList<bool>;
template class LinkedList<char>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<std::string>;
