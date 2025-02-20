#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include <iostream>
#include <cstring>
#include "../DoubleNode/DoubleNode.hpp"
#include "../DLIterator/DLIterator.hpp"

using namespace std;

template <class T>
class DoublyLinkedList
{
    friend class ChainIterator<T>;

    private:
        DoubleNode<T>* first;
        DoubleNode<T>* last;  // Ensure this is declared

    public:
        // constructor and destructors
        DoublyLinkedList();          // constructor
        DoublyLinkedList(const DoublyLinkedList<T>& other);  // Copy Constructor
        virtual ~DoublyLinkedList(); // destructor

        // Getter and Setters
        DoubleNode<T>* GetFirst() const;
        DoubleNode<T>* GetLast() const;
        void SetFirst(DoubleNode<T>* node);
        void SetLast(DoubleNode<T>* node);

        // return elements 
        DLIterator<T> begin() const;
        DLIterator<T> end() const;
        Node<T>* Get(int i);                    // returns the ith element in the list

        // insertion 
        virtual void InsertFront(const T& e);   // insert at the front of the list
        virtual void InsertBack(const T& e);    // insert at the end of the list
        void Insert(int i, T e);                // insert as the ith element

        // deletion 
        virtual void DeleteFront();             // delete at the front
        virtual void DeleteBack();              // delete at the end
        void Delete(int i);                     // delete the ith element

        // Other functions
        virtual int Length() const;                           // return the length of the list
        virtual void Concatenate(DoublyLinkedList<T>& b);     // concatenate two list
        virtual void Reverse();                               // reverse the list
        bool IsEmpty() const;                                 // Check if the list is empty

        // overloading
        DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);     // Deep copy of lists
        bool operator==(const DoublyLinkedList<T>& other) const;
        bool operator!=(const DoublyLinkedList<T>& other) const;
        template <typename U> friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list);

#endif