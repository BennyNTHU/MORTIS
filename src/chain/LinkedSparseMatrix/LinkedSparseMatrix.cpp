#include "LinkedSparseMatrix.hpp"

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

// Get number of nonzero terms
int LinkedSparseMatrix::get_terms() const 
{
    return terms;
}

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

// Matrix addition
LinkedSparseMatrix LinkedSparseMatrix::Add(const LinkedSparseMatrix& b) const 
{
    if (rows != b.rows || cols != b.cols) 
    {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    LinkedSparseMatrix sum(rows, cols, 0); // Fixed constructor usage

    DoubleNode<LinkedMatrixTerm>* ptrA = head;
    DoubleNode<LinkedMatrixTerm>* ptrB = b.head;

    while (ptrA || ptrB) 
    {
        if (!ptrB || (ptrA && (ptrA->getData().getRow() < ptrB->getData().getRow() ||
                              (ptrA->getData().getRow() == ptrB->getData().getRow() &&
                               ptrA->getData().getCol() < ptrB->getData().getCol())))) 
        {
            sum.StoreNum(ptrA->getData().getValue(), ptrA->getData().getRow(), ptrA->getData().getCol());
            ptrA = static_cast<DoubleNode<LinkedMatrixTerm>*>(ptrA->getLink());
        } 
        else if (!ptrA || (ptrB && (ptrB->getData().getRow() < ptrA->getData().getRow() ||
                                   (ptrB->getData().getRow() == ptrA->getData().getRow() &&
                                    ptrB->getData().getCol() < ptrA->getData().getCol())))) 
        {
            sum.StoreNum(ptrB->getData().getValue(), ptrB->getData().getRow(), ptrB->getData().getCol());
            ptrB = static_cast<DoubleNode<LinkedMatrixTerm>*>(ptrB->getLink());
        } 
        else 
        {
            // Perform addition and store result
            std::variant<int, double> newVal;
            if (std::holds_alternative<int>(ptrA->getData().getValue()) &&
                std::holds_alternative<int>(ptrB->getData().getValue())) 
            {
                newVal = std::get<int>(ptrA->getData().getValue()) + std::get<int>(ptrB->getData().getValue());
            } 
            else 
            {
                double valA = std::holds_alternative<int>(ptrA->getData().getValue()) ? 
                             static_cast<double>(std::get<int>(ptrA->getData().getValue())) :
                             std::get<double>(ptrA->getData().getValue());

                double valB = std::holds_alternative<int>(ptrB->getData().getValue()) ? 
                             static_cast<double>(std::get<int>(ptrB->getData().getValue())) :
                             std::get<double>(ptrB->getData().getValue());

                newVal = valA + valB;
            }

            sum.StoreNum(newVal, ptrA->getData().getRow(), ptrA->getData().getCol());
            ptrA = static_cast<DoubleNode<LinkedMatrixTerm>*>(ptrA->getLink());
            ptrB = static_cast<DoubleNode<LinkedMatrixTerm>*>(ptrB->getLink());
        }
    }
    return sum;
}


LinkedSparseMatrix LinkedSparseMatrix::Multiply(const LinkedSparseMatrix& b) const 
{
    if (this->cols != b.rows) 
    {
        throw std::invalid_argument("Matrix dimensions do not allow multiplication.");
    }

    LinkedSparseMatrix result(this->rows, b.cols, 0); // Corrected usage of rows and cols

    // Iterate through each nonzero element in the first matrix
    for (DoubleNode<LinkedMatrixTerm>* aNode = this->head; aNode; aNode = static_cast<DoubleNode<LinkedMatrixTerm>*>(aNode->getLink())) 
    {
        int aRow = aNode->getData().getRow();
        int aCol = aNode->getData().getCol();
        std::variant<int, double> aValue = aNode->getData().getValue();

        // Iterate through the second matrix to find matching column elements
        for (DoubleNode<LinkedMatrixTerm>* bNode = b.head; bNode; bNode = static_cast<DoubleNode<LinkedMatrixTerm>*>(bNode->getLink())) 
        {
            if (bNode->getData().getRow() == aCol)  // Match column from A with row in B 
            { 
                int bCol = bNode->getData().getCol();
                std::variant<int, double> bValue = bNode->getData().getValue();

                // Compute the product and accumulate into result matrix
                std::variant<int, double> product;
                if (std::holds_alternative<int>(aValue) && std::holds_alternative<int>(bValue)) 
                {
                    product = std::get<int>(aValue) * std::get<int>(bValue);
                } 
                else 
                {
                    product = std::get<double>(aValue) * std::get<double>(bValue);
                }
                result.StoreNum(product, aRow, bCol);
            }
        }
    }

    return result;
}

LinkedSparseMatrix LinkedSparseMatrix::ScalarProduct(std::variant<int, double> n) const 
{
    LinkedSparseMatrix result(rows, cols, 0);

    // Iterate over nonzero elements and multiply each by scalar
    for (DoubleNode<LinkedMatrixTerm>* current = head; current; current = static_cast<DoubleNode<LinkedMatrixTerm>*>(current->getLink())) 
    {
        int row = current->getData().getRow();
        int col = current->getData().getCol();
        std::variant<int, double> value = current->getData().getValue();

        std::variant<int, double> product;
        
        // Use std::visit to handle different cases safely
        product = std::visit([](auto&& val, auto&& scalar) -> std::variant<int, double> 
        {
            return val * scalar;
        }, value, n);   // WTF

        result.StoreNum(product, row, col);
    }

    return result;
}

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
