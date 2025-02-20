#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <cstring>
#include "../Node/Node.hpp"
#include "../ChainIterator/ChainIterator.hpp"
using namespace std;

template <class T>
class LinkedList
{
    friend class ChainIterator<T>;

    private:
        Node<T>* first;

    protected:
        // Helper functions
        void SetFirst(Node<T>* node);
        Node<T>* GetFirst() const;
        void Clear();

    public:
        // Constructor and destructors 
        LinkedList();          // constructor
        virtual ~LinkedList(); // destructor

        // Insertion 
        virtual void InsertFront(const T& e);   // insert at the front of the list
        virtual void InsertBack(const T& e);    // insert at the end of the list
        void Insert(int i, T e);                // insert as the ith element

        // Deletion
        virtual void DeleteFront();             // delete at the front
        virtual void DeleteBack();              // delete at the end
        void Delete(int i);                     // delete the ith element

        // Return elements 
        ChainIterator<T> begin() const;
        ChainIterator<T> end() const;
        Node<T>* Get(int i);                    // returns the ith node in the list
        LinkedList<T> GetSublist(int i, int j); // return a sublist from index i to j (both included)

        // Other functions 
        virtual bool IsEmpty() const;                   // Check if the list is empty
        virtual int Length();                   // return the length of the list
        void Concatenate(LinkedList<T>& b);     // concatenate two list
        void Reverse();                         // reverse the list

        // Overloading
        LinkedList<T>& operator=(const LinkedList<T>& other);     // Deep copy of lists
        bool operator==(const LinkedList<T>& other) const;        // Comparison operators
        bool operator!=(const LinkedList<T>& other) const;
        template <typename U> friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list);

#endif