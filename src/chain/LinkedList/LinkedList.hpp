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

    public:
        /* constructor and destructors */
        LinkedList();  // constructor
        ~LinkedList(); // destructor
        void Clear();

        /* insertion */
        void InsertFront(const T& e);   // insert at the front of the list
        void InsertBack(const T& e);    // insert at the end of the list
        void Insert(int i, T e);        // insert as the ith element

        /* deletion */
        void DeleteFront();  // delete at the front
        void DeleteBack();   // delete at the end
        void Delete(int i);  // delete the ith element

        /* return elements */
        ChainIterator<T> begin() const;
        ChainIterator<T> end() const;
        Node<T>* Get(int i); // returns the ith element in the list

        /* Other functions */
        void Concatenate(LinkedList<T>& b);   // concatenate two list
        void Reverse();                 // reverse the list

        /* overloading */
        template <typename U>
        friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
        LinkedList<T>& operator=(const LinkedList<T>& other);     // Deep copy of lists
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list);

#endif