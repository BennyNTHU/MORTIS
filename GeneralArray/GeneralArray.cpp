#include "GeneralArray.h"                // Include the header for GeneralArray
#include <sstream>                       // For string stream processing
using namespace std;

//-----------------------------------------
// Helper function: convert multi-dimensional index to linear index (row-major order)
//-----------------------------------------
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

//-----------------------------------------
// Constructor: allocate memory and initialize array with initValue
//-----------------------------------------
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

//-----------------------------------------
// Destructor: free allocated memory
//-----------------------------------------
template <class T>
GeneralArray<T>::~GeneralArray() 
{
    delete[] data;
}

//-----------------------------------------
// Copy constructor: deep copy from other GeneralArray
//-----------------------------------------
template <class T>
GeneralArray<T>::GeneralArray(const GeneralArray<T>& other) 
{
    dimension = other.dimension;
    dims = other.dims;
    totalSize = other.totalSize;
    data = new T[totalSize];

    for (int i = 0; i < totalSize; i++)
        data[i] = other.data[i];
}

//-----------------------------------------
// Assignment operator: deep copy assignment
//-----------------------------------------
template <class T>
GeneralArray<T>& GeneralArray<T>::operator=(const GeneralArray<T>& other) 
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

//-----------------------------------------
// Equality operator: compare two arrays elementwise and dimensions
//-----------------------------------------
template <class T>
bool GeneralArray<T>::operator==(const GeneralArray<T>& other) const 
{
    if (dimension != other.dimension || dims != other.dims || totalSize != other.totalSize)
        return false;

    for (int i = 0; i < totalSize; i++) 
        if (!(data[i] == other.data[i]))
            return false;

    return true;
}

//-----------------------------------------
// Store() function: update element at the given multi-dimensional index with value x
//-----------------------------------------
template <class T>
void GeneralArray<T>::Store(const Index& idx, T x) 
{
    int linearIndex = computeLinearIndex(idx);
    data[linearIndex] = x;
}

//-----------------------------------------
// Retrieve() function: return the element at the given multi-dimensional index
//-----------------------------------------
template <class T>
T GeneralArray<T>::Retrieve(const Index& idx) const 
{
    int linearIndex = computeLinearIndex(idx);
    return data[linearIndex];
}

//-----------------------------------------
// sort() function: sort the array based on given parameters.
// For 1D, sort entire data array; for 2D, sort rows based on element at column (sortDim-1).
// 'reverse' true means ascending order; false means descending order.
//-----------------------------------------
template <class T>
void GeneralArray<T>::sort(bool reverse, int sortDim) 
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
        throw std::runtime_error("sort() not implemented for arrays with dimension > 2");
}

//-----------------------------------------
// Overloaded input operator >> to allow input from stream.
// For types that are std::variant, input operator is not supported.
//-----------------------------------------
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

//-----------------------------------------
// Overloaded output operator << to print array contents to stream.
//-----------------------------------------
template <class T>
ostream& operator<<(ostream& out, const GeneralArray<T>& arr) 
{
    if (arr.dimension == 1) 
    {
        out << "[";
        for (int i = 0; i < arr.totalSize; i++) 
        {
            out << arr.data[i];
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
                out << arr.data[row * arr.dims[1] + col];
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

// 顯式實例化 GeneralArray 模板，針對 ga-test.cpp 中使用到的型別：
template class GeneralArray<int>;
template class GeneralArray<double>;
template class GeneralArray<char>;
template class GeneralArray<std::variant<int, char, std::string>>;

template std::ostream& operator<<<int>(std::ostream&, const GeneralArray<int>&);
template std::ostream& operator<<<double>(std::ostream&, const GeneralArray<double>&);
template std::ostream& operator<<<char>(std::ostream&, const GeneralArray<char>&);
template std::ostream& operator<< <std::variant<int, char, std::string> >(std::ostream&, const GeneralArray<std::variant<int, char, std::string>>&);

template std::istream& operator>><int>(std::istream&, GeneralArray<int>&);
