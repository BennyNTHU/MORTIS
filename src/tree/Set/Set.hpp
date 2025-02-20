#ifndef SET_HPP
#define SET_HPP

#include <initializer_list>
#include <vector>
#include "../BinarySearchTree/BinarySearchTree.hpp"  // Our BST is defined to work with type T

// A Set is a specialized BinarySearchTree that stores unique elements.
template <class T>
class Set : public BinarySearchTree<T> 
{
    public:
        // Constructors
        Set();                                  // Default constructor. We use T() as the initial value.
        Set(std::initializer_list<T> elements); // Construct from an initializer list.

        // Set operation
        Set<T> Union(const Set<T>& other) const;        // Return a new Set that is the union of this set and other.
        Set<T> Intersection(const Set<T>& other) const; // Return a new Set that is the intersection of this set and other.
        Set<T> Difference(const Set<T>& other) const;   // Return a new Set that is the difference (this minus other).
        bool IsSubsetOf(const Set<T>& other) const;     // Return true if every element in this set is also in other.
        bool Contains(const T& value) const;            // Return true if value is in the set.

        // Print the set to std::cout.
        void Print() const;
};

// Use the BinarySearchTree<T> functions for insertion/search
// Since BinarySearchTree's InorderIterator() is non-const, in our const functions we use a const_cast

#endif
