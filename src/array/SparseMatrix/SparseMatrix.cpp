// SparseMatrix.cpp
// Implementation of the SparseMatrix class.
// Elements are stored using std::variant<int, float> to allow both integers and floats.
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

// Helper function: add two variant values. If both are ints, return int; otherwise, return float.
std::variant<int, float> addValues(const std::variant<int, float>& a, const std::variant<int, float>& b) 
{
    if(a.index() == 0 && b.index() == 0)
        return std::get<int>(a) + std::get<int>(b);
    else 
    {
        float af = std::visit([](auto v) { return static_cast<float>(v); }, a);
        float bf = std::visit([](auto v) { return static_cast<float>(v); }, b);
        return af + bf;
    }
}

// Helper function: multiply two variant values.
std::variant<int, float> multiplyValues(const std::variant<int, float>& a, const std::variant<int, float>& b) 
{
    if(a.index() == 0 && b.index() == 0)
        return std::get<int>(a) * std::get<int>(b);
    else 
    {
        float af = std::visit([](auto v) { return static_cast<float>(v); }, a);
        float bf = std::visit([](auto v) { return static_cast<float>(v); }, b);
        return af * bf;
    }
}

// Constructor: allocate memory for the given number of nonzero terms.
SparseMatrix::SparseMatrix(int r, int c, int t) 
{
    rows = r;
    cols = c;
    terms = t;
    capacity = terms;
    smArray = (MatrixTerm *)calloc(capacity, sizeof(MatrixTerm));
}

// Copy constructor: deep copy of another SparseMatrix.
SparseMatrix::SparseMatrix(const SparseMatrix &b) 
{
    rows = b.rows;
    cols = b.cols;
    terms = b.terms;
    capacity = b.capacity;
    smArray = (MatrixTerm *)calloc(capacity, sizeof(MatrixTerm));
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
    free(smArray);
}

// StoreNum: If num is nonzero, add a new term with given row and col.
void SparseMatrix::StoreNum(const std::variant<int, float>& num, const int r, const int c) 
{
    float numVal = std::visit([](auto v) { return static_cast<float>(v); }, num);
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
            std::variant<int, float> cellValue = 0;
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

// get_terms: Returns the number of nonzero terms.
int SparseMatrix::get_terms() const 
{
    return terms;
}

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

// Add: Returns the sum of this matrix and matrix b.
SparseMatrix SparseMatrix::Add(SparseMatrix b) 
{
    if (rows != b.rows || cols != b.cols)
        throw "Matrices are not the same size!";
    
    int same_place = 0;

    for (int i = 0; i < terms; i++)
        for (int j = 0; j < b.get_terms(); j++)
            if (smArray[i].row == b.smArray[j].row && smArray[i].col == b.smArray[j].col)
                same_place++;

    int add_terms = terms + b.get_terms() - same_place;
    SparseMatrix c(rows, cols, add_terms);
    int c_index = 0;

    // Combine terms with same position.
    for (int i = 0; i < terms; i++)
        for (int j = 0; j < b.get_terms(); j++)
            if (smArray[i].row == b.smArray[j].row && smArray[i].col == b.smArray[j].col) 
            {
                auto newVal = addValues(smArray[i].value, b.smArray[j].get_value());
                c.smArray[c_index].write_term(smArray[i].row, smArray[i].col, newVal);
                c_index++;
            }

    // Add remaining terms from this matrix.
    for (int i = 0; i < terms; i++) 
    {
        int count = 0;
        for (int j = 0; j < b.get_terms(); j++) 
        {
            if (!(smArray[i].row == b.smArray[j].row && smArray[i].col == b.smArray[j].col))
                count++;
        }
        if (count == b.get_terms())
            c.smArray[c_index++].write_term(smArray[i].row, smArray[i].col, smArray[i].value);
    }

    // Add remaining terms from matrix b.
    for (int i = 0; i < b.get_terms(); i++) 
    {
        int count = 0;
        for (int j = 0; j < terms; j++) 
        {
            if (!(b.smArray[i].row == smArray[j].row && b.smArray[i].col == smArray[j].col))
                count++;
        }
        if (count == terms)
            c.smArray[c_index++].write_term(b.smArray[i].get_row(), b.smArray[i].get_col(), b.smArray[i].get_value());
    }
    return c;
}

// Multiply: Returns the product of this matrix and matrix b.
SparseMatrix SparseMatrix::Multiply(SparseMatrix b) 
{
    if (cols != b.rows)
        throw "Incompatible matrices for multiplication";
    
    SparseMatrix bXpose = b.FastTranspose();
    SparseMatrix d(rows, b.cols, 0); // Result matrix, initially with 0 terms.
    int currRowIndex = 0, currRowBegin = 0;
    int currRowA = smArray[0].row;
    
    // Add dummy term for boundary conditions.
    if (terms == capacity)
        ChangeSize1D(terms + 1);
    smArray[terms].row = rows;
    
    if (bXpose.terms == bXpose.capacity)
        bXpose.ChangeSize1D(bXpose.terms + 1);
    
    bXpose.smArray[b.get_terms()].row = b.cols;
    bXpose.smArray[b.get_terms()].col = -1;
    
    std::variant<int, float> num = 0; // Initialize num as integer 0.
    
    while (currRowIndex < terms) 
    {
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        while (currColIndex <= b.get_terms()) 
        {
            if (smArray[currRowIndex].row != currRowA) 
            {
                d.StoreNum(num, currRowA, currColB);
                num = 0;
                currRowIndex = currRowBegin;
                while (currColIndex <= b.get_terms() && bXpose.smArray[currColIndex].row == currColB)
                    currColIndex++;
                
                if (currColIndex <= b.get_terms())
                    currColB = bXpose.smArray[currColIndex].row;
            } 
            else if (bXpose.smArray[currColIndex].row != currColB) 
            {
                d.StoreNum(num, currRowA, currColB);
                num = 0;
                currRowIndex = currRowBegin;
                currColB = bXpose.smArray[currColIndex].row;
            } 
            else 
            {
                if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col)
                    currRowIndex++;
                else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col) 
                {
                    auto prod = multiplyValues(smArray[currRowIndex].value, bXpose.smArray[currColIndex].value);
                    num = addValues(num, prod);
                    currRowIndex++;
                    currColIndex++;
                } 
                else
                    currColIndex++;
            }
        }

        while (currRowIndex < terms && smArray[currRowIndex].row == currRowA)
            currRowIndex++;
        
        currRowBegin = currRowIndex;

        if (currRowIndex < terms)
            currRowA = smArray[currRowIndex].row;
    }
    return d;
}

// Multiply with exponent: placeholder function, not implemented.
SparseMatrix SparseMatrix::Multiply(SparseMatrix b, int n) 
{
    return *this;
}

// Public method to set a term at a given index.
void SparseMatrix::setTerm(int index, int r, int c, const std::variant<int, float>& v) 
{
    if (index < 0 || index >= capacity)
        throw "Index out of bounds";
    
    smArray[index].write_term(r, c, v);
}

// Overloaded input operator: Reads each term from input in the format "row col value".
// The value is read as a string to decide whether to store it as int or float.
istream& operator>>(istream& in, const SparseMatrix& b) 
{
    // Cast away const so we can modify the matrix.
    SparseMatrix& mat = const_cast<SparseMatrix&>(b);
    int r, c;
    string valStr;

    cout << "Enter (row col value) for each term:" << endl;

    for (int i = 0; i < mat.terms; i++) 
    {
        in >> r >> c >> valStr;

        if (valStr.find('.') != string::npos) 
        {
            float fVal = stof(valStr);
            mat.smArray[i].write_term(r, c, fVal);
        } 
        else 
        {
            int iVal = stoi(valStr);
            mat.smArray[i].write_term(r, c, iVal);
        }
    }
    return in;
}

// ScalarProduct: Returns a new sparse matrix that is the current matrix multiplied by scalar n.
SparseMatrix SparseMatrix::ScalarProduct(std::variant<int, float> n) 
{
    // Create a new matrix with the same dimensions and number of terms.
    SparseMatrix result(rows, cols, terms);

    for (int i = 0; i < terms; i++) 
    {
        result.smArray[i].row = smArray[i].row;
        result.smArray[i].col = smArray[i].col;
        // Multiply the existing value by n using the helper function.
        result.smArray[i].value = multiplyValues(smArray[i].value, n);
    }

    return result;
}

// Overloaded output operator: Prints each term in the format (row, col, value).
// The value is printed preserving its type: if it is an integer, it is printed as int; otherwise, as float.
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

// Overload the equality operator to compare two SparseMatrix objects.
bool operator==(const SparseMatrix& a, const SparseMatrix& b)
{
    if (a.get_rows() != b.get_rows() || a.get_cols() != b.get_cols() || a.get_terms() != b.get_terms())
        return false;
    else 
    {
        for (int i = 0; i < a.get_terms(); i++) 
        {
            MatrixTerm* A = a.get_smArray();
            MatrixTerm* B = b.get_smArray();
            if (A[i].get_row() != B[i].get_row() || A[i].get_col() != B[i].get_col() || A[i].get_value() != B[i].get_value())
                return false;
        }
    }
    return true;
}