#include "GeneralArray.hpp"                // Include the header for GeneralArray
#include <sstream>                         // For string stream processing
using namespace std;

// =======================================================
// Helper function
// =======================================================

// Helper function: convert multi-dimensional index to linear index (row-major order)
template <class T>
int GeneralArray<T>::computeLinearIndex(const Index& idx) const 
{
    if (idx.size() != dims.size())
        throw std::out_of_range("Index size does not match array dimensions");
    int linear = 0;
    int multiplier = 1;
    for (int i = dims.size() - 1; i >= 0; i--) 
    {
        if (idx[i] < 0 || idx[i] >= dims[i])
            throw std::out_of_range("Index out of bounds");
        linear += idx[i] * multiplier;
        multiplier *= dims[i];
    }
    return linear;
}

// =======================================================
// Constructors and Destructor
// =======================================================

template <class T>
GeneralArray<T>::GeneralArray(): dimension(0), totalSize(0), data(nullptr) {}

template <class T>
GeneralArray<T>::GeneralArray(int j, const RangeList& list, T initValue)
{
    if (list.size() != static_cast<size_t>(j))
        throw std::invalid_argument("Dimension count does not match size list");
    dimension = j;
    dims = list;
    totalSize = 1;
    for (int i = 0; i < j; i++) 
    {
        if (list[i] <= 0)
            throw std::invalid_argument("Dimension sizes must be positive");
        totalSize *= list[i];
    }
    data = new T[totalSize];
    for (int i = 0; i < totalSize; i++)
        data[i] = initValue;
}

template <class T>
GeneralArray<T>::GeneralArray(const GeneralArray<T>& other) // Copy constructor: deep copy from other GeneralArray
{
    dimension = other.dimension;
    dims = other.dims;
    totalSize = other.totalSize;
    data = new T[totalSize];

    for (int i = 0; i < totalSize; i++)
        data[i] = other.data[i];
}

template <class T>
GeneralArray<T>::~GeneralArray()    // Destructor: free allocated memory 
{
    delete[] data;
}

// =======================================================
// Properties
// =======================================================

// Length() function: return total number of elements in the array
template <class T>
int GeneralArray<T>::Length() const 
{
    return totalSize;
}

// =======================================================
// Getters
// =======================================================

template <class T>
T GeneralArray<T>::Retrieve(const Index& idx) const // Retrieve() function: return the element at the given multi-dimensional index 
{
    int linearIndex = computeLinearIndex(idx);
    return data[linearIndex];
}


// =======================================================
// Manipulations
// =======================================================

// Initialize() function: set all elements to default value T{}
template <class T>
void GeneralArray<T>::Initialize() 
{
    for (int i = 0; i < totalSize; i++)
        data[i] = T{};
}

template <class T>
void GeneralArray<T>::Store(const Index& idx, T x)  // Store() function: update element at the given multi-dimensional index with value x 
{
    int linearIndex = computeLinearIndex(idx);
    data[linearIndex] = x;
}

// Sort() function: sort the array based on given parameters.
// For 1D, sort entire data array; for 2D, sort rows based on element at column (sortDim-1).
// 'reverse' true means ascending order; false means descending order.
template <class T>
void GeneralArray<T>::Sort(bool reverse, int sortDim) 
{
    if (dimension == 1) 
    {
        if (reverse)
            std::sort(data, data + totalSize);
        else
            std::sort(data, data + totalSize, std::greater<T>());
    } 
    else if (dimension == 2) 
    {
        if (sortDim < 1 || sortDim > dims[1])
            throw std::out_of_range("sortDim out of range for 2D array");
        vector<int> rowIndices(dims[0]);
        for (int i = 0; i < dims[0]; i++)
            rowIndices[i] = i;
        auto comp = [this, sortDim, reverse](int a, int b) 
        {
            T valA = data[a * dims[1] + (sortDim - 1)];
            T valB = data[b * dims[1] + (sortDim - 1)];
            return reverse ? (valA < valB) : (valA > valB);
        };
        std::sort(rowIndices.begin(), rowIndices.end(), comp);
        T* temp = new T[totalSize];
        for (int newRow = 0; newRow < dims[0]; newRow++) 
        {
            int oldRow = rowIndices[newRow];
            for (int col = 0; col < dims[1]; col++) 
                temp[newRow * dims[1] + col] = data[oldRow * dims[1] + col];
        }
        std::copy(temp, temp + totalSize, data);
        delete[] temp;
    } 
    else 
        throw std::runtime_error("Sort() not implemented for arrays with dimension > 2");
}

// Reverse() function: reverse the order of all elements (flat order)
template <class T>
void GeneralArray<T>::Reverse() 
{
    std::reverse(data, data + totalSize);
}

template <class T>
void GeneralArray<T>::Push_back(const T& value) 
{
    // Allocate a new array of size totalSize + 1.
    T* newData = new T[totalSize + 1];

    // Copy existing elements.
    for (int i = 0; i < totalSize; i++) 
    {
        newData[i] = data[i];
    }

    // Append the new value.
    newData[totalSize] = value;

    // Free the old memory.
    delete[] data;
    data = newData;
    totalSize++;

    // Also update dims[0] if dims is not empty.
    if (!dims.empty())
        dims[0] = totalSize;
}

// =======================================================
// Operator overloading
// =======================================================

template <class T>
GeneralArray<T>& GeneralArray<T>::operator=(const GeneralArray<T>& other)   // Assignment operator: deep copy assignment 
{
    if (this != &other) 
    {
        delete[] data;
        dimension = other.dimension;
        dims = other.dims;
        totalSize = other.totalSize;
        data = new T[totalSize];

        for (int i = 0; i < totalSize; i++)
            data[i] = other.data[i];
    }
    return *this;
}

// Overloaded assignment operator with initializer_list.
template <class T>
GeneralArray<T>& GeneralArray<T>::operator=(std::initializer_list<T> il) 
{
    if (il.size() != static_cast<size_t>(totalSize))
        throw std::invalid_argument("Initializer list size does not match array size");
    int i = 0;
    for (const T& elem : il)
        data[i++] = elem;
    return *this;
}

template <class T>
T& GeneralArray<T>::operator[](int index) 
{
    if (index < 0 || index >= totalSize)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <class T>
const T& GeneralArray<T>::operator[](int index) const 
{
    if (index < 0 || index >= totalSize)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <class T>
bool GeneralArray<T>::operator==(const GeneralArray<T>& other) const    // Equality operator: compare two arrays elementwise and dimensions
{
    if (dimension != other.dimension || dims != other.dims || totalSize != other.totalSize)
        return false;

    for (int i = 0; i < totalSize; i++) 
        if (!(data[i] == other.data[i]))
            return false;

    return true;
}

template <class T>
bool GeneralArray<T>::operator!=(const GeneralArray<T>& other) const 
{
    return !(*this==other);
}

// =======================================================
// Input/Output operands
// =======================================================

// Overloaded input operator >> to allow input from stream.
// For types that are std::variant, input operator is not supported.
template <class T>
istream& operator>>(istream& in, GeneralArray<T>& arr) 
{
    if constexpr (is_variant<T>::value) 
    {
        throw std::runtime_error("Input operator >> not implemented for variant types. Please use Store() to populate the array.");
    } 
    else 
    {
        char ch;
        if (arr.dimension == 1) 
        {
            in >> ch;
            if (ch != '[')
                throw std::runtime_error("Expected '[' at beginning of array input");
            for (int i = 0; i < arr.totalSize; i++) 
            {
                T value;
                in >> value;
                arr.data[i] = value;
                in >> ch;
                if (i < arr.totalSize - 1) 
                {
                    if (ch != ',')
                        throw std::runtime_error("Expected ',' between elements");
                } 
                else 
                {
                    if (ch != ']')
                        throw std::runtime_error("Expected ']' at end of array input");
                }
            }
        } 
        else if (arr.dimension == 2) 
        {
            in >> ch;
            if (ch != '[')
                throw std::runtime_error("Expected '[' at beginning of 2D array input");
            for (int row = 0; row < arr.dims[0]; row++) 
            {
                in >> ch;
                if (ch != '[')
                    throw std::runtime_error("Expected '[' at beginning of row input");
                for (int col = 0; col < arr.dims[1]; col++) 
                {
                    T value;
                    in >> value;
                    arr.data[row * arr.dims[1] + col] = value;
                    in >> ch;
                    if (col < arr.dims[1] - 1) 
                    {
                        if (ch != ',')
                            throw std::runtime_error("Expected ',' between elements in row");
                    } 
                    else 
                    {
                        if (ch != ']')
                            throw std::runtime_error("Expected ']' at end of row input");
                    }
                }
                if (row < arr.dims[0] - 1) 
                {
                    in >> ch;
                    if (ch != ',')
                        throw std::runtime_error("Expected ',' between rows");
                }
            }
            in >> ch;
            if (ch != ']')
                throw std::runtime_error("Expected ']' at end of 2D array input");
        } 
        else 
        {
            throw std::runtime_error("operator>> not implemented for arrays with dimension > 2");
        }
        return in;
    }
}

// helper functions
template<typename U>
void printVal(std::ostream &out, const U &value) 
{
    out << value;
}

template<typename... Ts>
void printVal(std::ostream &out, const std::variant<Ts...> &value) 
{
    std::visit([&](auto &&arg) { out << arg; }, value);
}

template <class T>
ostream& operator<<(ostream& out, const GeneralArray<T>& arr)   // Overloaded output operator << to print array contents to stream.
{
    if (arr.dimension == 1) 
    {
        out << "[";
        for (int i = 0; i < arr.totalSize; i++) 
        {
            printVal(out, arr.data[i]);
            if (i < arr.totalSize - 1)
                out << ", ";
        }
        out << "]";
    } 
    else if (arr.dimension == 2) 
    {
        out << "[";
        for (int row = 0; row < arr.dims[0]; row++) 
        {
            out << "[";
            for (int col = 0; col < arr.dims[1]; col++) 
            {
                printVal(out, arr.data[row * arr.dims[1] + col]);
                if (col < arr.dims[1] - 1)
                    out << ", ";
            }
            out << "]";
            if (row < arr.dims[0] - 1)
                out << ", ";
        }
        out << "]";
    } 
    else 
    {
        out << "Output operator not implemented for arrays with dimension > 2";
    }
    return out;
}

// =======================================================
// Explicit instantiations
// =======================================================

template class GeneralArray<int>;
template class GeneralArray<double>;
template class GeneralArray<char>;
template class GeneralArray<float>;
template class GeneralArray<bool>;
template class GeneralArray<MIXED_TYPE>;
template class GeneralArray<std::vector<MIXED_TYPE>>;

template std::ostream& operator<<<int>(std::ostream&, const GeneralArray<int>&);
template std::ostream& operator<<<double>(std::ostream&, const GeneralArray<double>&);
template std::ostream& operator<<<char>(std::ostream&, const GeneralArray<char>&);
template std::ostream& operator<<<float>(std::ostream&, const GeneralArray<float>&);
template std::ostream& operator<<<bool>(std::ostream&, const GeneralArray<bool>&);
template std::ostream& operator<< <MIXED_TYPE>(std::ostream&, const GeneralArray<MIXED_TYPE>&);

template std::istream& operator>><int>(std::istream&, GeneralArray<int>&);
template std::istream& operator>><double>(std::istream&, GeneralArray<double>&);
template std::istream& operator>><char>(std::istream&, GeneralArray<char>&);
template std::istream& operator>><float>(std::istream&, GeneralArray<float>&);
template std::istream& operator>><bool>(std::istream&, GeneralArray<bool>&);
template std::istream& operator>> <MIXED_TYPE>(std::istream&, GeneralArray<MIXED_TYPE>&);
