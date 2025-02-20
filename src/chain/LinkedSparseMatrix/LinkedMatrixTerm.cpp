#include "LinkedMatrixTerm.hpp"

// =============================================
// Consructors and desructors
// =============================================

LinkedMatrixTerm::LinkedMatrixTerm() : row(0), col(0), value(0) {}

LinkedMatrixTerm::LinkedMatrixTerm(int r, int c, std::variant<int, double> v): row(r), col(c), value(v) {}

// =============================================
// Getters
// =============================================

int LinkedMatrixTerm::getRow() const 
{ 
    return row; 
}

int LinkedMatrixTerm::getCol() const 
{ 
    return col; 
}

std::variant<int, double> LinkedMatrixTerm::getValue() const 
{ 
    return value; 
}

// =============================================
// Setters
// =============================================

void LinkedMatrixTerm::setRow(int r) 
{ 
    row = r; 
}

void LinkedMatrixTerm::setCol(int c) 
{ 
    col = c; 
}

void LinkedMatrixTerm::setValue(std::variant<int, double> v) 
{ 
    value = v; 
}

// =============================================
// outstreams and instreams overload
// =============================================

std::ostream& operator<<(std::ostream& out, const LinkedMatrixTerm& term) 
{
    out << "(" << term.getRow() << ", " << term.getCol() << ", ";

    if (std::holds_alternative<int>(term.value))
        out << std::get<int>(term.value);
    else
        out << std::get<double>(term.value);

    out << ")";

    return out;
}

std::istream& operator>>(std::istream& in, LinkedMatrixTerm& term) 
{
    int r, c;

    std::variant<int, double> v;
    in >> r >> c;

    if (in.peek() == '.') 
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

    term.setRow(r);
    term.setCol(c);
    term.setValue(v);
    
    return in;
}
