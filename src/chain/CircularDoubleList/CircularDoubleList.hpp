#ifndef CIRCULAR_DOUBLE_LIST
#define CIRCULAR_DOUBLE_LIST

#include "../DoublyLinkedList/DoublyLinkedList.hpp"
#include "../DoubleNode/DoubleNode.hpp"
#include "../DLIterator/DLIterator.hpp"

template <typename T>
class CircularDoubleList : public DoublyLinkedList<T> 
{
    private:
        // Utility function to copy elements from another list
        void CopyFrom(const CircularDoubleList<T>& other);

    public:
        // Constructor
        CircularDoubleList();

        // Copy constructor
        CircularDoubleList(const CircularDoubleList<T>& other);

        // Destructor
        ~CircularDoubleList();

        // Override Insert and Delete functions to maintain circular property
        void InsertBack(const T& e) override;
        void InsertFront(const T& e) override;
        void DeleteBack() override;
        void DeleteFront() override;

        // Concatenate another circular doubly linked list
        void Concatenate(CircularDoubleList<T>& b);

        // Get the length of the list
        int Length() const override;

        // Reverse the list
        void Reverse() override;

        // Assignment operator
        CircularDoubleList<T>& operator=(const CircularDoubleList<T>& other);

        // Overload << operator for printing
        template <typename U>
        friend std::ostream& operator<<(std::ostream& out, const CircularDoubleList<U>& list);
};

#endif // CIRCULARDOUBLELIST
