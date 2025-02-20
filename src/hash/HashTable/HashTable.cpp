#include "HashTable.hpp"
#include <iostream>

// =======================================
// The hash function
// =======================================

// Hash function
template <typename T>
size_t HashTable<T>::hashFunction(const T& key) const 
{
    return std::hash<T>{}(key) % capacity;
}

// =======================================
// Constructors and destructors
// =======================================

// Constructor
template <typename T>
HashTable<T>::HashTable(size_t size) : capacity(size), table(size) {}

// Destructor
template <typename T>
HashTable<T>::~HashTable() {}

// =======================================
// Other functions
// =======================================

// Insert function
template <typename T>
void HashTable<T>::insert(const T& key) 
{
    size_t index = hashFunction(key);

    if (!search(key)) 
    {
        table[index].InsertBack(key);
    }
}

// Search function
template <typename T>
bool HashTable<T>::search(const T& key) const 
{
    size_t index = hashFunction(key);

    for (DLIterator<T> it = table[index].begin(); it != table[index].end(); ++it) 
    {
        if (*it == key) return true;
    }

    return false;
}

// Remove function
template <typename T>
bool HashTable<T>::remove(const T& key) 
{
    size_t index = hashFunction(key);
    int pos = 0;

    for (DLIterator<T> it = table[index].begin(); it != table[index].end(); ++it, ++pos) 
    {
        if (*it == key) 
        {
            table[index].Delete(pos);
            return true;
        }
    }

    return false;
}

// Display function
template <typename T>
void HashTable<T>::display() const 
{
    for (size_t i = 0; i < capacity; ++i) 
    {
        std::cout << "Bucket " << i << ": ";
        for (DLIterator<T> it = table[i].begin(); it != table[i].end(); ++it) 
        {
            std::cout << *it << " -> ";
        }
        std::cout << "nullptr" << std::endl;
    }
}

// Explicit instantiations for supported types
template class HashTable<int>;
template class HashTable<char>;
template class HashTable<std::string>;
