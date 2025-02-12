#ifndef GENERALARRAY_H                   // Include guard start
#define GENERALARRAY_H                   // Include guard define

#include <iostream>                      // For standard I/O streams
#include <vector>                        // For std::vector container
#include <stdexcept>                     // For standard exceptions
#include <algorithm>                     // For std::sort, std::copy, std::reverse, etc.
#include <variant>                       // For std::variant support (C++17)
#include <type_traits>                   // For type traits (e.g. is_variant)
#include <memory>                        // For std::unique_ptr
#include <initializer_list>              // For std::initializer_list

using namespace std;                     // Use the standard namespace

// general array may store mixed C++ data type
using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

//-----------------------------------------
// Trait to detect if a type is a specialization of std::variant
//-----------------------------------------
template<typename T>
struct is_variant : std::false_type {};  // Primary template: false

template<typename... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {}; // Specialization for std::variant

//-----------------------------------------
// Type alias for a list of dimension sizes.
//-----------------------------------------
typedef vector<int> RangeList;            // RangeList represents the sizes of each dimension

//-----------------------------------------
// Type alias for a multi-dimensional index.
//-----------------------------------------
typedef vector<int> Index;                // Index represents an index in multi-dimensional array

//-----------------------------------------
// Template class for GeneralArray.
//-----------------------------------------
template <class T> 
class GeneralArray 
{
    private:
        int dimension;                        // Number of dimensions of the array
        RangeList dims;                       // Vector holding the size of each dimension
        T* data;                              // Pointer to the underlying flat array data
        int totalSize;                        // Total number of elements (product of dims)

        // Helper function: convert a multi-dimensional index to a linear index (row-major order)
        int computeLinearIndex(const Index& idx) const;

    public:
        // Constructor: user must specify dimensions and corresponding sizes; default initial value is T()
        GeneralArray(int j = 1, const RangeList& list = RangeList(), T initValue = T());

        // Destructor: releases allocated memory
        ~GeneralArray();

        // Copy constructor: deep copy from another GeneralArray
        GeneralArray(const GeneralArray<T>& other);

        // Assignment operator: deep copy assignment from another GeneralArray
        GeneralArray<T>& operator=(const GeneralArray<T>& other);

        // Overloaded assignment operator with initializer_list.
        // Allows syntax: GeneralArray A = {elem1, elem2, ...};
        GeneralArray<T>& operator=(std::initializer_list<T> il);

        // Equality operator: returns true if arrays have the same dimensions and all elements equal
        bool operator==(const GeneralArray<T>& other) const;

        // Store() function: update the element at the given multi-dimensional index with value x
        void Store(const Index& idx, T x);

        // Retrieve() function: return the element at the given multi-dimensional index
        T Retrieve(const Index& idx) const;

        // sort() function: sort the array based on parameters.
        // For 1D, sort entire data; for 2D, sort rows based on the element at column (sortDim-1).
        // 'reverse' true means ascending order; false means descending order (default false).
        void sort(bool reverse = false, int sortDim = 1);

        // reverse() function: reverse the order of elements (flat order)
        void reverse();

        // initialize() function: set all elements to default value T{} (e.g. 0 for numeric types)
        void initialize();

        // length() function: return the total number of elements in the array
        int length() const;

        // Friend overloaded >> operator to allow input from stream.
        // For types that are std::variant, input operator is not supported.
        template <class U>
        friend istream& operator>>(istream& in, GeneralArray<U>& arr);

        // Friend overloaded << operator to output the array content to stream.
        template <class U>
        friend ostream& operator<<(ostream& out, const GeneralArray<U>& arr);
};

#endif  // End of include guard GENERALARRAY_H