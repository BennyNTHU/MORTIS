/* HashTable.hpp */
#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <vector>
#include "../../chain/DoublyLinkedList/DoublyLinkedList.hpp"
#include "../../chain/DLIterator/DLIterator.hpp"
#include "../../chain/DoubleNode/DoubleNode.hpp"

// HashTable class template for handling multiple data types separately
template <typename T>
class HashTable 
{
    private:
        size_t capacity;
        std::vector<DoublyLinkedList<T>> table;

        // The hash function
        size_t hashFunction(const T& key) const;

    public:
        // Constructors and destructors
        explicit HashTable(size_t size);
        ~HashTable();

        // Other functions
        void insert(const T& key);
        bool search(const T& key) const;
        bool remove(const T& key);
        void display() const;
};

#endif // HASHTABLE
