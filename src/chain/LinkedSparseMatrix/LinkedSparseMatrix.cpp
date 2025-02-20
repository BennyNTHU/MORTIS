#include <cmath>
#include "LinkedSparseMatrix.hpp"

// =====================================================
// Helper function
// =====================================================

// Helper function to extract value from std::variant<int, double>
double ExtractValue(const std::variant<int, double>& val) 
{
    if (std::holds_alternative<int>(val)) 
    {
        return static_cast<double>(std::get<int>(val));  // Convert int to double
    } 
    else if (std::holds_alternative<double>(val)) 
    {
        return std::get<double>(val);  // Return double directly
    }
    throw std::bad_variant_access();  // If the variant does not contain int or double
}

// =====================================================
// Constructors and Destructor
// =====================================================

// Default constructor for LinkedSparseMatrix
LinkedSparseMatrix::LinkedSparseMatrix() 
{
    this->rows = 0;         // Initialize rows to 0
    this->cols = 0;         // Initialize columns to 0
    this->head = nullptr;   // Set head to nullptr since no terms are inserted yet
}

// Constructor
LinkedSparseMatrix::LinkedSparseMatrix(int r, int c, int t) : rows(r), cols(c), terms(t), head(nullptr) {}

// Copy constructor
LinkedSparseMatrix::LinkedSparseMatrix(const LinkedSparseMatrix &b) : rows(b.rows), cols(b.cols), terms(b.terms), head(nullptr) 
{
    DoubleNode<LinkedMatrixTerm>* current = b.head;
    DoubleNode<LinkedMatrixTerm>* prevNode = nullptr;

    while (current) 
    {
        auto newNode = new DoubleNode<LinkedMatrixTerm>(current->getData());

        if (!head) 
        {
            head = newNode;
        } 
        else 
        {
            prevNode->setLink(newNode);
            newNode->setPrev(prevNode);
        }

        prevNode = newNode;
        current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
    }
}

// Destructor
LinkedSparseMatrix::~LinkedSparseMatrix() 
{
    DoubleNode<LinkedMatrixTerm>* current = head;

    while (current) 
    {
        DoubleNode<LinkedMatrixTerm>* next = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
        delete current;
        current = next;
    }
}

// =====================================================
// Getters
// =====================================================

// Get number of rows
int LinkedSparseMatrix::get_rows() const 
{
    return rows;
}

// Get number of cols
int LinkedSparseMatrix::get_cols() const 
{
    return cols;
}

// Get number of nonzero terms
int LinkedSparseMatrix::get_terms() const 
{
    return terms;
}

// =====================================================
// Other functions
// =====================================================

// StoreNum: Inserts a value into the matrix
void LinkedSparseMatrix::StoreNum(const std::variant<int, double>& num, const int r, const int c) 
{
    if ((std::holds_alternative<int>(num) && std::get<int>(num) == 0) || 
        (std::holds_alternative<double>(num) && std::get<double>(num) == 0.0)) 
    {
        return;  // Ignore zero values
    }

    // Create a new node with the given row, column, and value
    auto newNode = new DoubleNode<LinkedMatrixTerm>(LinkedMatrixTerm(r, c, num));

    if (!head) 
    {
        head = newNode;
        terms++;
        return;
    }

    DoubleNode<LinkedMatrixTerm>* current = head;
    DoubleNode<LinkedMatrixTerm>* prev = nullptr;

    // Find the correct insertion position
    while (current && (current->getData().getRow() < r || 
                      (current->getData().getRow() == r && current->getData().getCol() < c))) 
    {
        prev = current;
        current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
    }

    // If a term with the same row and column already exists, update its value
    if (current && current->getData().getRow() == r && current->getData().getCol() == c) 
    {
        LinkedMatrixTerm updatedTerm = current->getData(); // Copy data
        updatedTerm.setValue(num); // Modify value
        current->setData(updatedTerm); // Assign back to node
        delete newNode; // Delete the new node since it's not needed
    } 
    else 
    { 
        // Insert the new node at the correct position
        newNode->setLink(current);
        newNode->setPrev(prev);

        if (prev) 
            prev->setLink(newNode);
        else 
            head = newNode;  // Update head if necessary

        if (current) 
            current->setPrev(newNode);
        
        terms++;
    }
}

// Print the matrix in dense form
void LinkedSparseMatrix::printMatrix() const 
{
    DoubleNode<LinkedMatrixTerm>* current = head;
    std::vector<std::vector<std::variant<int, double>>> matrix(rows, std::vector<std::variant<int, double>>(cols, 0));

    while (current) 
    {
        matrix[current->getData().getRow()][current->getData().getCol()] = current->getData().getValue();
        current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
    }

    for (const auto& row : matrix) 
    {
        for (const auto& elem : row) 
        {
            if (std::holds_alternative<int>(elem))
                std::cout << std::get<int>(elem) << " ";
            else
                std::cout << std::get<double>(elem) << " ";
        }
        std::cout << std::endl;
    }
}

// Clears all elements in the sparse matrix by deleting all the nodes
void LinkedSparseMatrix::Clear() 
{
    DoubleNode<LinkedMatrixTerm>* currentNode = head;
    
    while (currentNode) 
    {
        DoubleNode<LinkedMatrixTerm>* nextNode = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentNode->getLink());
        delete currentNode;  // Delete the current node
        currentNode = nextNode; // Move to the next node
    }

    head = nullptr;  // Set head to null, indicating an empty matrix
    rows = 0;        // Reset rows and columns to 0
    cols = 0;
}

// =====================================================
// Matrix operation
// =====================================================

// Transpose matrix
LinkedSparseMatrix LinkedSparseMatrix::FastTranspose() const 
{
    LinkedSparseMatrix transposed(cols, rows, terms);  // Corrected constructor

    // Iterate through original matrix and insert elements in transposed positions
    for (DoubleNode<LinkedMatrixTerm>* current = head; current; 
         current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink())) 
    {
        transposed.StoreNum(current->getData().getValue(), 
                            current->getData().getCol(), 
                            current->getData().getRow());
    }
    
    return transposed;
}

double LinkedSparseMatrix::Norm() const 
{
    double sumOfSquares = 0.0;
    
    // Iterate through all terms in the sparse matrix and accumulate the sum of squares
    DoubleNode<LinkedMatrixTerm>* current = this->head;
    
    while (current) 
    {
        // Extract the value from std::variant
        double value = ExtractValue(current->getData().getValue()); // Get the value of the current term
        
        sumOfSquares += value * value; // Add the square of the value
        current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
    }

    // Return the square root of the sum of squares
    return std::sqrt(sumOfSquares);
}

// =====================================================
// Operator overloads for arithmetic:
// =====================================================

LinkedSparseMatrix LinkedSparseMatrix::operator+(const LinkedSparseMatrix& b) const 
{
    LinkedSparseMatrix result;
    
    // Traverse both matrices
    DoubleNode<LinkedMatrixTerm>* currentA = this->head;
    DoubleNode<LinkedMatrixTerm>* currentB = b.head;

    while (currentA || currentB) 
    {
        if (!currentA) 
        {
            result.StoreNum(currentB->getData().getValue(), currentB->getData().getRow(), currentB->getData().getCol());
            currentB = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentB->getLink());
        } 
        else if (!currentB) 
        {
            result.StoreNum(currentA->getData().getValue(), currentA->getData().getRow(), currentA->getData().getCol());
            currentA = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentA->getLink());
        } 
        else 
        {
            double valueA = ExtractValue(currentA->getData().getValue());
            double valueB = ExtractValue(currentB->getData().getValue());

            // If both positions are the same, add their values
            if (currentA->getData().getRow() == currentB->getData().getRow() && currentA->getData().getCol() == currentB->getData().getCol()) 
            {
                result.StoreNum(valueA + valueB, currentA->getData().getRow(), currentA->getData().getCol());
                currentA = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentA->getLink());
                currentB = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentB->getLink());
            } 
            // Otherwise, store the current value from the matrix with the lower row/col priority
            else if (currentA->getData().getRow() < currentB->getData().getRow() ||
                (currentA->getData().getRow() == currentB->getData().getRow() && currentA->getData().getCol() < currentB->getData().getCol())) 
            {
                result.StoreNum(valueA, currentA->getData().getRow(), currentA->getData().getCol());
                currentA = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentA->getLink());
            } 
            else 
            {
                result.StoreNum(valueB, currentB->getData().getRow(), currentB->getData().getCol());
                currentB = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentB->getLink());
            }
        }
    }

    return result;
}

LinkedSparseMatrix LinkedSparseMatrix::operator-(const LinkedSparseMatrix& b) const 
{
    LinkedSparseMatrix result;

    // Traverse both matrices
    DoubleNode<LinkedMatrixTerm>* currentA = this->head;
    DoubleNode<LinkedMatrixTerm>* currentB = b.head;

    while (currentA || currentB) 
    {
        if (!currentA) 
        {
            result.StoreNum(-ExtractValue(currentB->getData().getValue()), currentB->getData().getRow(), currentB->getData().getCol());
            currentB = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentB->getLink());
        } 
        else if (!currentB) 
        {
            result.StoreNum(ExtractValue(currentA->getData().getValue()), currentA->getData().getRow(), currentA->getData().getCol());
            currentA = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentA->getLink());
        } 
        else 
        {
            double valueA = ExtractValue(currentA->getData().getValue());
            double valueB = ExtractValue(currentB->getData().getValue());

            // If both positions are the same, subtract their values
            if (currentA->getData().getRow() == currentB->getData().getRow() && currentA->getData().getCol() == currentB->getData().getCol()) 
            {
                result.StoreNum(valueA - valueB, currentA->getData().getRow(), currentA->getData().getCol());
                currentA = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentA->getLink());
                currentB = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentB->getLink());
            } 
            // Otherwise, store the current value from the matrix with the lower row/col priority
            else if (currentA->getData().getRow() < currentB->getData().getRow() ||
                (currentA->getData().getRow() == currentB->getData().getRow() && currentA->getData().getCol() < currentB->getData().getCol())) 
            {
                result.StoreNum(valueA, currentA->getData().getRow(), currentA->getData().getCol());
                currentA = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentA->getLink());
            } 
            else 
            {
                result.StoreNum(-valueB, currentB->getData().getRow(), currentB->getData().getCol());
                currentB = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentB->getLink());
            }
        }
    }

    return result;
}

LinkedSparseMatrix LinkedSparseMatrix::operator*(const LinkedSparseMatrix& b) const 
{
    if (this->cols != b.rows) 
        throw std::invalid_argument("Matrix dimensions must match for multiplication");

    LinkedSparseMatrix result(this->rows, b.cols, 0);

    for (DoubleNode<LinkedMatrixTerm>* currentA = this->head; currentA; 
         currentA = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentA->getLink())) 
    {
        for (DoubleNode<LinkedMatrixTerm>* currentB = b.head; currentB; 
             currentB = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentB->getLink())) 
        {
            if (currentA->getData().getCol() == currentB->getData().getRow()) 
            {
                double value = std::get<double>(currentA->getData().getValue()) * 
                               std::get<double>(currentB->getData().getValue());
                result.StoreNum(value, currentA->getData().getRow(), currentB->getData().getCol());
            }
        }
    }

    return result;
}

LinkedSparseMatrix LinkedSparseMatrix::operator*(const std::vector<double>& vec) const 
{
    if (this->cols != vec.size()) 
        throw std::invalid_argument("Matrix columns must match vector size");

    LinkedSparseMatrix result(this->rows, 1, 0); // The result will be a vector (single column matrix)

    for (DoubleNode<LinkedMatrixTerm>* current = this->head; current; 
         current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink())) 
    {
        int row = current->getData().getRow();
        int col = current->getData().getCol();
        double value = std::get<double>(current->getData().getValue());
        
        result.StoreNum(value * vec[col], row, 0);  // Store result in the corresponding row
    }

    return result;
}

LinkedSparseMatrix LinkedSparseMatrix::operator*(std::variant<int, double> scalar) const 
{
    LinkedSparseMatrix result;
    double scalarValue = ExtractValue(scalar);

    DoubleNode<LinkedMatrixTerm>* current = this->head;

    while (current) 
    {
        double termValue = ExtractValue(current->getData().getValue());
        result.StoreNum(termValue * scalarValue, current->getData().getRow(), current->getData().getCol());
        current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
    }

    return result;
}

// =====================================================
// Other overloads
// =====================================================

LinkedSparseMatrix& LinkedSparseMatrix::operator=(const LinkedSparseMatrix& other) 
{
    if (this == &other) 
        return *this; // Handle self-assignment

    // Clear the current matrix
    this->Clear();

    // Copy dimensions
    this->rows = other.rows;
    this->cols = other.cols;

    // Copy elements (using a deep copy)
    DoubleNode<LinkedMatrixTerm>* currentOther = other.head;
    while (currentOther) 
    {
        this->StoreNum(currentOther->getData().getValue(), currentOther->getData().getRow(), currentOther->getData().getCol());
        currentOther = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentOther->getLink());
    }

    return *this;  // Return the current object
}

bool LinkedSparseMatrix::operator==(const LinkedSparseMatrix& other) const 
{
    // Check if dimensions are equal
    if (this->rows != other.rows || this->cols != other.cols) 
        return false;

    // Compare elements (same position in both matrices should have the same value)
    DoubleNode<LinkedMatrixTerm>* currentThis = this->head;
    DoubleNode<LinkedMatrixTerm>* currentOther = other.head;

    while (currentThis || currentOther) 
    {
        if (!currentThis || !currentOther)
            return false;  // One of the lists ended prematurely

        if (currentThis->getData().getRow() == currentOther->getData().getRow() && 
            currentThis->getData().getCol() == currentOther->getData().getCol()) 
        {
            if (currentThis->getData().getValue() != currentOther->getData().getValue()) 
                return false;  // Different values at the same position
            currentThis = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentThis->getLink());
            currentOther = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentOther->getLink());
        } 
        else if (currentThis->getData().getRow() < currentOther->getData().getRow() || 
                 (currentThis->getData().getRow() == currentOther->getData().getRow() && currentThis->getData().getCol() < currentOther->getData().getCol())) 
        {
            currentThis = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentThis->getLink());
        } 
        else 
        {
            currentOther = static_cast<DoubleNode<LinkedMatrixTerm>*>(currentOther->getLink());
        }
    }

    return true;  // All elements match
}

bool LinkedSparseMatrix::operator!=(const LinkedSparseMatrix& other) const 
{
    return !(*this == other);  // If the matrices are not equal, they are unequal
}

std::variant<int, double> LinkedSparseMatrix::operator[](int index) const 
{
    // Find the term at the specified index (we assume 'index' represents a row-major order of terms)
    DoubleNode<LinkedMatrixTerm>* current = this->head;
    int currentIndex = 0;

    while (current) 
    {
        if (currentIndex == index) 
        {
            return current->getData().getValue();  // Return the value of the term at the specified index
        }
        current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
        ++currentIndex;
    }

    throw std::out_of_range("Index out of range");  // If the index is out of range
}

// =====================================================
// Overloaded input and output operators
// =====================================================

std::istream& operator>>(std::istream& in, LinkedSparseMatrix& b) 
{
    int r, c;
    std::variant<int, double> v;

    while (in >> r >> c)    // Read row and column 
    { 
        if (in.peek() == '.')   // Detect double values 
        { 
            double temp;
            in >> temp;
            v = temp;
        } 
        else 
        {
            int temp;
            in >> temp;
            v = temp;
        }
        b.StoreNum(v, r, c);
    }

    return in;
}

// Overloaded output operator
std::ostream& operator<<(std::ostream& out, const LinkedSparseMatrix& b) 
{
    DoubleNode<LinkedMatrixTerm>* current = b.head;

    while (current) 
    {
        out << current->getData() << " ";
        current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink());
    }
    
    return out;
}
