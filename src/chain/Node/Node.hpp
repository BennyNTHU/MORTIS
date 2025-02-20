#ifndef NODE
#define NODE

#include <iostream>
#include <string>

// Node class for singly linked list
template <typename T>
class Node 
{
    private:
        T data;               // Holds the data of the node
        Node<T>* link;        // Pointer to the next node

    public:
        // Constructors
        Node();                              // Default constructor
        Node(const T& item, Node<T>* next);  // Constructor with data and link
        ~Node();                             // Destructor

        // Getters
        const T& getData() const;            // Return data
        Node<T>* getLink() const;            // Return next node pointer

        // Setters
        void setData(const T& item);         // Set data
        void setLink(Node<T>* next);         // Set next node
};

#endif
