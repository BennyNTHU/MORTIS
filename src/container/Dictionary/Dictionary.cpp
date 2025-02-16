#include "Dictionary.hpp"
#include <stdexcept>
#include <algorithm>

// Constructor: Initialize with a given capacity
template <typename K, typename V>
Dictionary<K, V>::Dictionary(int c) : capacity(c), size(0) 
{
    arr = new KeyValuePair<K, V>[capacity];
}

// Copy Constructor
template <typename K, typename V>
Dictionary<K, V>::Dictionary(const Dictionary<K, V>& dict) : capacity(dict.capacity), size(dict.size) 
{
    arr = new KeyValuePair<K, V>[capacity];
    for (int i = 0; i < size; i++) 
    {
        arr[i] = dict.arr[i];
    }
}

// Destructor
template <typename K, typename V>
Dictionary<K, V>::~Dictionary() 
{
    delete[] arr;
}

// Get capacity
template <typename K, typename V>
int Dictionary<K, V>::Capacity() const 
{
    return capacity;
}

// Check if dictionary is empty
template <typename K, typename V>
bool Dictionary<K, V>::IsEmpty() const 
{
    return size == 0;
}

// Get the number of elements
template <typename K, typename V>
int Dictionary<K, V>::Size() const 
{
    return size;
}

// Check if a key exists in the dictionary
template <typename K, typename V>
bool Dictionary<K, V>::isBelong(const K& key) const 
{
    for (int i = 0; i < size; i++) 
        if (arr[i].key == key) 
            return true;

    return false;
}

// Insert a key-value pair
template <typename K, typename V>
void Dictionary<K, V>::Insert(const KeyValuePair<K, V>& pair) 
{
    if (size == capacity) 
    {
        throw std::overflow_error("Dictionary is full!");
    }
    arr[size++] = pair;
}

// Remove all values associated with a key
template <typename K, typename V>
void Dictionary<K, V>::Remove(const K& key) 
{
    int i = 0;

    while (i < size) 
    {
        if (arr[i].key == key) 
        {
            for (int j = i; j < size - 1; j++) 
            {
                arr[j] = arr[j + 1];    // Shift left
            }
            size--;
        } 
        else 
        {
            i++;
        }
    }
}

// Return all values associated with a key
template <typename K, typename V>
vector<V> Dictionary<K, V>::Map(const K& key) const 
{
    vector<V> values;

    for (int i = 0; i < size; i++) 
        if (arr[i].key == key) 
            values.push_back(arr[i].value);

    return values;
}

// Reduce function: Merge values with the same key
template <typename K, typename V>
void Dictionary<K, V>::reduce(std::function<V(const V&, const V&)> reducer) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i].key == arr[j].key) 
            {
                arr[i].value = reducer(arr[i].value, arr[j].value); 
                
                // Shift elements left
                for (int k = j; k < size - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--; // Adjust index to recheck
            }
        }
    }
}

// Assignment operator
template <typename K, typename V>
Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary<K, V>& dict) 
{
    if (this != &dict) 
    {
        delete[] arr;
        capacity = dict.capacity;
        size = dict.size;
        arr = new KeyValuePair<K, V>[capacity];

        for (int i = 0; i < size; i++) 
        {
            arr[i] = dict.arr[i];
        }
    }
    return *this;
}

// Access values by key
template <typename K, typename V>
V& Dictionary<K, V>::operator[](const K& key) 
{
    for (int i = 0; i < size; i++) 
        if (arr[i].key == key) 
            return arr[i].value;

    throw std::out_of_range("Key not found");
}

// Equality operator
template <typename K, typename V>
bool Dictionary<K, V>::operator==(const Dictionary<K, V>& dict) const 
{
    if (size != dict.size) 
        return false;

    for (int i = 0; i < size; i++) 
        if (arr[i].key != dict.arr[i].key || arr[i].value != dict.arr[i].value) 
            return false;

    return true;
}

// Inequality operator
template <typename K, typename V>
bool Dictionary<K, V>::operator!=(const Dictionary<K, V>& dict) const 
{
    return !(*this == dict);
}

// Overloaded output stream operator for Dictionary
template <typename U, typename W>
ostream& operator<<(ostream& os, const Dictionary<U, W>& dict) 
{
    for (int i = 0; i < dict.size; i++) {
        os << "[" << dict.arr[i].key << ": " << dict.arr[i].value << "] ";
    }
    return os;
}

// The following codes are explicitly instantiated for the supported types

template class Dictionary<int, int>;
template class Dictionary<int, char>;
template class Dictionary<int, float>;
template class Dictionary<int, bool>;
template class Dictionary<int, double>;
template class Dictionary<int, std::string>;

template class Dictionary<char, int>;
template class Dictionary<char, char>;
template class Dictionary<char, float>;
template class Dictionary<char, bool>;
template class Dictionary<char, double>;
template class Dictionary<char, std::string>;

template class Dictionary<float, int>;
template class Dictionary<float, char>;
template class Dictionary<float, float>;
template class Dictionary<float, bool>;
template class Dictionary<float, double>;
template class Dictionary<float, std::string>;

template class Dictionary<bool, int>;
template class Dictionary<bool, char>;
template class Dictionary<bool, float>;
template class Dictionary<bool, bool>;
template class Dictionary<bool, double>;
template class Dictionary<bool, std::string>;

template class Dictionary<double, int>;
template class Dictionary<double, char>;
template class Dictionary<double, float>;
template class Dictionary<double, bool>;
template class Dictionary<double, double>;
template class Dictionary<double, std::string>;

template class Dictionary<std::string, int>;
template class Dictionary<std::string, char>;
template class Dictionary<std::string, float>;
template class Dictionary<std::string, bool>;
template class Dictionary<std::string, double>;
template class Dictionary<std::string, std::string>;

template std::ostream& operator<<(std::ostream&, const Dictionary<int, int>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<int, char>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<int, float>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<int, bool>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<int, double>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<int, std::string>&);

template std::ostream& operator<<(std::ostream&, const Dictionary<char, int>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<char, char>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<char, float>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<char, bool>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<char, double>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<char, std::string>&);

template std::ostream& operator<<(std::ostream&, const Dictionary<float, int>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<float, char>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<float, float>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<float, bool>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<float, double>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<float, std::string>&);

template std::ostream& operator<<(std::ostream&, const Dictionary<bool, int>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<bool, char>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<bool, float>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<bool, bool>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<bool, double>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<bool, std::string>&);

template std::ostream& operator<<(std::ostream&, const Dictionary<double, int>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<double, char>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<double, float>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<double, bool>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<double, double>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<double, std::string>&);

template std::ostream& operator<<(std::ostream&, const Dictionary<std::string, int>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<std::string, char>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<std::string, float>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<std::string, bool>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<std::string, double>&);
template std::ostream& operator<<(std::ostream&, const Dictionary<std::string, std::string>&);
