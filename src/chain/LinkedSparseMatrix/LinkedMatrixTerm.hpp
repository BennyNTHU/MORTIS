#ifndef LINKEDMATRIXTERM
#define LINKEDMATRIXTERM

#include <iostream>
#include <vector>
#include <variant>
#include "../DoubleNode/DoubleNode.hpp"

class LinkedMatrixTerm 
{
    private:
        int row, col;
        std::variant<int, double> value;
    
    public:
        // Consructors and desructors
        LinkedMatrixTerm();
        LinkedMatrixTerm(int r, int c, std::variant<int, double> v);

        // Getters
        int getRow() const;
        int getCol() const;
        std::variant<int, double> getValue() const;
        
        // Setters
        void setRow(int r);
        void setCol(int c);
        void setValue(std::variant<int, double> v);
        
        // outstreams and instreams overload
        friend std::ostream& operator<<(std::ostream& out, const LinkedMatrixTerm& term);
        friend std::istream& operator>>(std::istream& in, LinkedMatrixTerm& term);
};


#endif // LINKEDMATRIXTERM
