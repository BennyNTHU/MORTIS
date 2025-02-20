#ifndef CIRCULAR_DOUBLE_LIST
#define CIRCULAR_DOUBLE_LIST

#include "../DoublyLinkedList/DoublyLinkedList.hpp"
#include "../DoubleNode/DoubleNode.hpp"
#include "../DLIterator/DLIterator.hpp"

template <typename T>
class CircularDoubleList : public DoublyLinkedList<T> 
{
    private:
        // Utility function 
        void CopyFrom(const CircularDoubleList<T>& other);  // to copy elements from another list

    public:
        // Constructors and destructors
        CircularDoubleList();
        CircularDoubleList(const CircularDoubleList<T>& other);
        ~CircularDoubleList();

        // Operations
        void InsertBack(const T& e) override;       // Override Insert and Delete functions to maintain circular property
        void InsertFront(const T& e) override;
        void DeleteBack() override;
        void DeleteFront() override;
        void Concatenate(CircularDoubleList<T>& b); // Concatenate another circular doubly linked list
        void Reverse() override;                    // Reverse the list
        
        // Properties (IsEmpty() inherits from DoublyLinkedList)
        int Length() const override;    // Get the length of the list

        // OVerloading
        CircularDoubleList<T>& operator=(const CircularDoubleList<T>& other);   // Assignment operator
        bool operator==(const CircularDoubleList<T>& other) const;
        bool operator!=(const CircularDoubleList<T>& other) const;
        template <typename U> friend std::ostream& operator<<(std::ostream& out, const CircularDoubleList<U>& list);  // Overload << operator for printing
};

#endif
