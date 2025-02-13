#ifndef CIRCULARLIST
#define CIRCULARLIST

#include "../LinkedList/LinkedList.hpp"  // Inherit from LinkedList

template <typename T>
class CircularList : public LinkedList<T> 
{
    private:
        // Utility function to copy another circular list
        void CopyFrom(const CircularList<T>& other);

    protected:
        // Set the first node
        void SetFirst(Node<T>* node);

    public:
        // Constructor
        CircularList();

        // Copy constructor
        CircularList(const CircularList<T>& other);

        // Destructor to properly clean up circular linked list
        ~CircularList();

        // Return the length of the list
        int Length();

        // Override insert functions to maintain circular structure
        void InsertBack(const T& e) override;
        void InsertFront(const T& e) override;

        // Override deletion functions to maintain circular structure
        void DeleteBack() override;
        void DeleteFront() override;

        // Concatenation of two circular lists
        void Concatenate(CircularList<T>& b);

        // Assignment operator
        CircularList<T>& operator=(const CircularList<T>& other);

        // Custom print function
        template <typename U>
        friend std::ostream& operator<<(std::ostream& out, const CircularList<U>& list);
};

// Declare the overloaded << operator function
template <typename T>
std::ostream& operator<<(std::ostream& out, const CircularList<T>& list);

#endif // CIRCULARLIST_HPP
