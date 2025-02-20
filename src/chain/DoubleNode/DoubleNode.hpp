#ifndef DOUBLENODE
#define DOUBLENODE

#include "../Node/Node.hpp"

template <typename T>
class DoubleNode : public Node<T> 
{
    private:
        DoubleNode<T>* prev; // Pointer to the previous node

    public:
        // Constructors and destructors
        DoubleNode();
        DoubleNode(const T& item, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr);
        ~DoubleNode();  // Destructor

        // Getters and setters
        DoubleNode<T>* getPrev() const;     // Getters
        void setPrev(DoubleNode<T>* prev);  // Setters
};

#endif // DOUBLENODE
