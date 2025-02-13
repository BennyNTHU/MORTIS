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
        void SetFirst(Node<T>* node);
        Node<T>* GetFirst() const;

    public:
        /* constructor and destructors */
        LinkedList();          // constructor
        virtual ~LinkedList(); // destructor
        void Clear();

        /* insertion */
        virtual void InsertFront(const T& e);   // insert at the front of the list
        virtual void InsertBack(const T& e);    // insert at the end of the list
        void Insert(int i, T e);                // insert as the ith element

        /* deletion */
        virtual void DeleteFront();             // delete at the front
        virtual void DeleteBack();              // delete at the end
        void Delete(int i);                     // delete the ith element

        /* return elements */
        ChainIterator<T> begin() const;
        ChainIterator<T> end() const;
        Node<T>* Get(int i);                    // returns the ith element in the list

        /* Other functions */
        virtual int Length();                           // return the length of the list
        void Concatenate(LinkedList<T>& b);     // concatenate two list
        void Reverse();                         // reverse the list

        /* overloading */
        template <typename U>
        friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
        LinkedList<T>& operator=(const LinkedList<T>& other);     // Deep copy of lists
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list);

#endif