#ifndef DOUBLENODE
#define DOUBLENODE

#include "../Node/Node.hpp"

template <typename T>
class DoubleNode : public Node<T> 
{
    private:
        DoubleNode<T>* prev; // Pointer to the previous node

    public:
        // Constructors
        DoubleNode();
        DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr);

        // Destructor
        ~DoubleNode();

        // Getters
        DoubleNode<T>* getPrev() const;

        // Setters
        void setPrev(DoubleNode<T>* prev);
};

#endif // DOUBLENODE
