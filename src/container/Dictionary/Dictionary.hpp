#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <functional>
#include <vector>

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/Polynomial/Polynomial.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../array/String/String.hpp"

using namespace std;

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

template <class K, class V>
struct KeyValuePair
{
    K key;
    V value;
};

template <typename K, typename V>
class Dictionary
{
    private:
        int capacity;                // Capacity of the dictionary
        int size;                    // Number of elements
        KeyValuePair<K, V>* arr;     // Array to store key-value pairs
        
    public:
        // Constructors
        Dictionary(int c);                               // Constructor with capacity
        Dictionary(const Dictionary<K, V>& dict);       // Copy constructor
        ~Dictionary();                                   // Destructor

        // Properties
        int Capacity() const;      // Return capacity
        bool IsEmpty() const;      // Return true if dictionary is empty
        int Size() const;          // Return number of elements
        bool isBelong(const K& key) const; // Check if a key is present in the dictionary

        // Manipulations
        void Insert(const KeyValuePair<K, V>& pair);   // Insert a key-value pair
        void Remove(const K& key);                     // Remove elements with the specified key
        vector<V> Map(const K& key) const;             // Return values associated with a key
        void reduce(std::function<V(const V&, const V&)> reducer); // Reduce function for merging values

        // Overloaded operators
        Dictionary<K, V>& operator=(const Dictionary<K, V>& dict); // Assignment operator
        V& operator[](const K& key);                               // Access value by key
        bool operator==(const Dictionary<K, V>& dict) const;       // Equality operator
        bool operator!=(const Dictionary<K, V>& dict) const;       // Inequality operator
        template <typename U, typename W> friend ostream& operator<<(ostream& os, const Dictionary<U, W>& dict); // Output operator
};

#endif
