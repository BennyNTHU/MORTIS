// SparseMatrix.cpp
// Implementation of the SparseMatrix class.
// Elements are stored using std::variant<int, double> to allow both integers and doubles.
// Arithmetic helper functions ensure that if both operands are integers, the result remains an integer.

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <variant>
#include "SparseMatrix.hpp"
using namespace std;

// ============================
// Helper function
// ============================

// Helper function: add two variant values.
std::variant<int, double> addValues(const std::variant<int, double>& a, const std::variant<int, double>& b) 
{
    if(a.index() == 0 && b.index() == 0)
        return std::get<int>(a) + std::get<int>(b);
    else 
    {
        double af = std::visit([](auto v){ return static_cast<double>(v); }, a);
        double bf = std::visit([](auto v){ return static_cast<double>(v); }, b);
        return af + bf;
    }
}

// Helper function: multiply two variant values.
std::variant<int, double> multiplyValues(const std::variant<int, double>& a, const std::variant<int, double>& b) 
{
    if(a.index() == 0 && b.index() == 0)
        return std::get<int>(a) * std::get<int>(b);
    else 
    {
        double af = std::visit([](auto v){ return static_cast<double>(v); }, a);
        double bf = std::visit([](auto v){ return static_cast<double>(v); }, b);
        return af * bf;
    }
}

// ============================
// Constructors and destructor
// ============================

// Defalut COnstructor
SparseMatrix::SparseMatrix(): rows(0), cols(0), terms(0), capacity(10)  // default capacity set to 10
{
    smArray = new MatrixTerm[capacity];
}

// Constructor: allocate memory for the given number of nonzero terms.
SparseMatrix::SparseMatrix(int r, int c, int t) 
{
    rows = r;
    cols = c;
    terms = 0;
    capacity = (t > 0 ? t : 10); // ensure a minimum capacity
    smArray = (MatrixTerm *)calloc(capacity, sizeof(MatrixTerm));
}

// Copy constructor: deep copy of another SparseMatrix.
SparseMatrix::SparseMatrix(const SparseMatrix &b) 
{
    rows = b.rows;
    cols = b.cols;
    terms = b.terms;
    capacity = b.capacity;
    smArray = new MatrixTerm[capacity];

    for (int i = 0; i < terms; i++) 
    {
        smArray[i].row = b.smArray[i].row;
        smArray[i].col = b.smArray[i].col;
        smArray[i].value = b.smArray[i].value;
    }
}

// Destructor: free allocated memory.
SparseMatrix::~SparseMatrix() 
{
    delete [] smArray;
}

// ============================
// Accessors
// ============================

int SparseMatrix::get_rows() const 
{
    return rows;
}

int SparseMatrix::get_cols() const 
{
    return cols;
}

int SparseMatrix::get_capacity() const 
{
    return capacity;
}

// get_terms: Returns the number of nonzero terms.
int SparseMatrix::get_terms() const 
{
    return terms;
}

MatrixTerm* SparseMatrix::get_smArray() const 
{
    return smArray;
}

// ============================
// // Other functions
// ============================

// StoreNum: If num is nonzero, add a new term with given row and col.
void SparseMatrix::StoreNum(const std::variant<int, double>& num, const int r, const int c) 
{
    double numVal = std::visit([](auto v) { return static_cast<double>(v); }, num);

    if (fabs(numVal) > 1e-6) 
    {
        if (terms == capacity)
            ChangeSize1D(2 * capacity);
        
        smArray[terms].row = r;
        smArray[terms].col = c;
        smArray[terms].value = num;
        terms++;
    }
}

// ChangeSize1D: Change the size of the internal array to newSize.
void SparseMatrix::ChangeSize1D(const int newSize) 
{
    if (newSize < terms)
        throw "New size must be >= number of terms";
    
    MatrixTerm *temp = new MatrixTerm[newSize];
    copy(smArray, smArray + terms, temp);
    delete [] smArray;
    smArray = temp;
    capacity = newSize;
}

// printMatrix: Prints the matrix in dense form.
// It prints all rows and columns, showing nonzero values where they exist.
void SparseMatrix::printMatrix() const 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            bool found = false;
            std::variant<int, double> cellValue = 0;
            for (int k = 0; k < terms; k++) 
            {
                if (smArray[k].row == i && smArray[k].col == j) 
                {
                    cellValue = smArray[k].value;
                    found = true;
                    break;
                }
            }
            std::visit([&](auto&& val) 
            {
                cout << val;
            }, cellValue);
            if (j < cols - 1)
                cout << " ";
        }
        cout << endl;
    }
}

// ============================
// Matrix operation
// ============================

// FastTranspose: Returns the transpose of this matrix.
SparseMatrix SparseMatrix::FastTranspose() 
{
    SparseMatrix b(cols, rows, terms);
    if (terms > 0) 
    {
        int *rowSize = new int[cols];
        int *rowStart = new int[cols];
        fill(rowSize, rowSize + cols, 0);

        for (int i = 0; i < terms; i++)
            rowSize[smArray[i].col]++;
        
        rowStart[0] = 0;

        for (int i = 1; i < cols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        
        for (int i = 0; i < terms; i++) 
        {
            int j = rowStart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        }

        delete [] rowSize;
        delete [] rowStart;
    }
    return b;
}

// Norm: compute and return the Frobenius norm of the matrix.
double SparseMatrix::Norm() const 
{
    double sum = 0.0;

    for (int i = 0; i < terms; i++) 
    {
        double val = std::visit([](auto v){ return static_cast<double>(v); }, smArray[i].value);
        sum += val * val;
    }

    return std::sqrt(sum);
}

// ============================
// Operator overloads for arithmetic:
// ============================

// Addition operator.
SparseMatrix SparseMatrix::operator+(const SparseMatrix& b) const 
{
    assert(rows == b.rows && cols == b.cols);
    // Create a result matrix with an upper-bound on number of terms.

    SparseMatrix result(rows, cols, terms + b.terms);
    int index = 0;

    // For each position, add terms from both matrices
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            std::variant<int, double> sum = 0;
            
            for (int k = 0; k < terms; k++) // Sum terms from this matrix.
            {
                if (smArray[k].row == i && smArray[k].col == j)
                    sum = addValues(sum, smArray[k].value);
            }
            
            for (int k = 0; k < b.terms; k++)   // Sum terms from matrix b.
            {
                if (b.smArray[k].row == i && b.smArray[k].col == j)
                    sum = addValues(sum, b.smArray[k].value);
            }

            double sVal = std::visit([](auto v){ return static_cast<double>(v); }, sum);

            if (fabs(sVal) > 1e-6) 
            {
                result.smArray[index].row = i;
                result.smArray[index].col = j;
                result.smArray[index].value = sum;
                index++;
            }
        }
    }
    result.terms = index;

    return result;
}

// Subtraction operator.
SparseMatrix SparseMatrix::operator-(const SparseMatrix& b) const 
{
    assert(rows == b.rows && cols == b.cols);
    SparseMatrix negB = b * std::variant<int, double>(-1);   

    return (*this) + negB;  // Multiply b by -1 and then add.
}

// Multiplication operator (matrix multiplication).
SparseMatrix SparseMatrix::operator*(const SparseMatrix& b) const 
{
    assert(cols == b.rows);
    SparseMatrix result(rows, b.cols);

    // A simple algorithm: for every (i,j), compute the dot product of row i of A and column j of B.
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < b.cols; j++) 
        {
            std::variant<int, double> sum = 0;

            for (int k = 0; k < cols; k++) 
            {
                std::variant<int, double> aVal = 0;
                std::variant<int, double> bVal = 0;
                
                for (int p = 0; p < terms; p++) // Find A(i,k)
                {
                    if (smArray[p].row == i && smArray[p].col == k) 
                    {
                        aVal = smArray[p].value;
                        break;
                    }
                }
                for (int p = 0; p < b.terms; p++)   // Find B(k,j)
                {
                    if (b.smArray[p].row == k && b.smArray[p].col == j) 
                    {
                        bVal = b.smArray[p].value;
                        break;
                    }
                }
                sum = addValues(sum, multiplyValues(aVal, bVal));
            }

            double sVal = std::visit([](auto v){ return static_cast<double>(v); }, sum);
            if (fabs(sVal) > 1e-6) 
            {
                result.StoreNum(sum, i, j);
            }
        }
    }
    return result;
}

// Matrix-vector multiplication. Here vec is a dense vector of doubles.
SparseMatrix SparseMatrix::operator*(const std::vector<double>& vec) const 
{
    assert(cols == vec.size());
    SparseMatrix result(rows, 1);

    // For each nonzero term in A, add its contribution to the corresponding row of the result.
    for (int i = 0; i < terms; i++) 
    {
        int r = smArray[i].row;
        int c = smArray[i].col;
        double val = std::visit([](auto v){ return static_cast<double>(v); }, smArray[i].value);
        double prod = val * vec[c];
        result.StoreNum(prod, r, 0);
    }

    return result;
}

// Scalar multiplication.
SparseMatrix SparseMatrix::operator*(std::variant<int, double> scalar) const 
{
    SparseMatrix result(rows, cols, terms);

    for (int i = 0; i < terms; i++) 
    {
        result.smArray[i].row = smArray[i].row;
        result.smArray[i].col = smArray[i].col;
        result.smArray[i].value = multiplyValues(smArray[i].value, scalar);
    }

    return result;
}

// ============================
// Other overloads
// ============================

// Assignment operator.
SparseMatrix& SparseMatrix::operator=(const SparseMatrix& other) 
{
    if (this == &other)
        return *this;

    delete[] smArray;
    rows = other.rows;
    cols = other.cols;
    terms = other.terms;
    capacity = other.capacity;
    smArray = new MatrixTerm[capacity];

    for (int i = 0; i < terms; i++)
        smArray[i] = other.smArray[i];

    return *this;
}

// Equality and inequality operators.
bool SparseMatrix::operator==(const SparseMatrix& other) const 
{
    if (rows != other.rows || cols != other.cols || terms != other.terms)
        return false;
    
    for (int i = 0; i < terms; i++) 
        if (smArray[i] != other.smArray[i])
            return false;
    
    return true;
}

bool SparseMatrix::operator!=(const SparseMatrix& other) const 
{
    return !(*this == other);
}

// Subscript operator.
std::variant<int, double> SparseMatrix::operator[](int index) const 
{
    assert(index >= 0 && index < terms);
    return smArray[index].value;
}


// ============================
// Friend I/O operators.
// ============================

// Overloaded output operator: Prints each term in the format (row, col, value).
// The value is printed preserving its type: if it is an integer, it is printed as int; otherwise, as double.
ostream& operator<<(ostream& out, const SparseMatrix& b) 
{
    out << "(row, col, value)" << endl;
    
    for (int i = 0; i < b.terms; i++) 
    {
        out << '(' << b.smArray[i].get_row() << ',' << b.smArray[i].get_col() << ',';
        std::visit([&out](auto&& val) { out << val; }, b.smArray[i].get_value());
        out << ')' << endl;
    }

    return out;
}

// Overloaded input operator: Reads each term from input in the format "row col value".
// The value is read as a string to decide whether to store it as int or double.
std::istream& operator>>(std::istream& in, SparseMatrix& mat) 
{
    int r, c;
    std::string token; // read the numeric value as a string

    // Read until the stream fails (e.g. end-of-file)
    while (in >> r >> c >> token) 
    {
        // If the token contains a decimal point, treat it as double.
        std::variant<int, double> v;
        if (token.find('.') != std::string::npos) 
        {
            double fVal = std::stof(token);
            v = fVal;
        } 
        else 
        {
            int iVal = std::stoi(token);
            v = iVal;
        }
        mat.StoreNum(v, r, c);
    }
    return in;
}

