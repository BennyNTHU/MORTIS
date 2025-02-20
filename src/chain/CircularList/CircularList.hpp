#ifndef CIRCULARLIST
#define CIRCULARLIST

#include "../LinkedList/LinkedList.hpp"  // Inherit from LinkedList

template <typename T>
class CircularList : public LinkedList<T> 
{
    private:
        // Utility function
        void CopyFrom(const CircularList<T>& other);    // to copy another circular list

    protected:
        // Setter
        void SetFirst(Node<T>* node);   // Set the first node

    public:
        // Constructors and destructors
        CircularList();
        CircularList(const CircularList<T>& other); // Copy constructor
        ~CircularList();    // Destructor to properly clean up circular linked list

        // Properties
        int Length() const;   // Return the length of the list
        bool IsEmpty() const;

        // Operations
        void InsertBack(const T& e) override;   // Override insert  functions to maintain circular structure
        void InsertFront(const T& e) override;
        void DeleteBack() override; // Override delete functions to maintain circular structure
        void DeleteFront() override;
        void Concatenate(CircularList<T>& b);   // Concatenation of two circular lists

        // Operator overloads
        CircularList<T>& operator=(const CircularList<T>& other);   // Assignment operator
        bool operator==(const CircularList<T>& other) const;
        bool operator!=(const CircularList<T>& other) const;
        template <typename U> friend std::ostream& operator<<(std::ostream& out, const CircularList<U>& list);    // Custom print function
};

// Declare the overloaded << operator function
template <typename T>
std::ostream& operator<<(std::ostream& out, const CircularList<T>& list);

#endif
