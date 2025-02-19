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
        // Constructors and Destructor
        GeneralArray();
        GeneralArray(int j, const RangeList& list, T initValue);   // default initial dimensions and sizes is T()    
        GeneralArray(const GeneralArray<T>& other); // Copy constructor: deep copy from another GeneralArray
        ~GeneralArray();    // Destructor: releases allocated memory

        // Properties
        int length() const; // return the total number of elements in the array

        // Getters
        T Retrieve(const Index& idx) const;  // Retrieve the element at the given multi-dimensional index

        // Manipulations
        void initialize();  // set all elements to default value T{} (e.g. 0 for numeric types)
        void Store(const Index& idx, T x);  // pdate the element at the given multi-dimensional index with value x
        void sort(bool reverse = false, int sortDim = 1);   // sort the array based on parameters.
        void reverse(); // 'reverse' true means ascending order; false means descending order (default false).
        void push_back(const T& value); // For 1D arrays only.
        
        // Operator overloading
        GeneralArray<T>& operator=(const GeneralArray<T>& other);   // deep copy assignment from another GeneralArray
        GeneralArray<T>& operator=(std::initializer_list<T> il);    // Allows syntax: GeneralArray A = {elem1, elem2, ...};
        T& operator[](int index);                                   // Overloaded subscript operator for non-const access.
        const T& operator[](int index) const;                       // Overloaded subscript operator for const access.
        bool operator==(const GeneralArray<T>& other) const;        // true if same dimensions and all elements equal
        bool operator!=(const GeneralArray<T>& other) const;        // false if same dimensions and all elements equal
        template <class U> friend istream& operator>>(istream& in, GeneralArray<U>& arr);           // input from stream. not supported for std::variant
        template <class U> friend ostream& operator<<(ostream& out, const GeneralArray<U>& arr);    // output the array content to stream.
};

#endif  // End of include guard GENERALARRAY_H