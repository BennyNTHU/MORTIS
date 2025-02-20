#ifndef LINKEDPOLYNOMIAL
#define LINKEDPOLYNOMIAL

#include <iostream>
#include <math.h>

#include "../Node/Node.hpp"
#include "../DoubleNode/DoubleNode.hpp"
#include "../ChainIterator/ChainIterator.hpp"
#include "../DLIterator/DLIterator.hpp"

using namespace std;

// LinkedTerm represents a single term in the polynomial
class LinkedTerm 
{
    private:
        double coef;    // coefficient
        int exp;        // exponents

    public:
        LinkedTerm() : coef(0), exp(0) {}                  // Default constructor
        LinkedTerm(double c, int e) : coef(c), exp(e) {}   // Constructor with coefficient and exponent
    
        // Getter and setter functions
        double get_coef() const {return coef;}
        int get_exp() const {return exp;}
        double& get_coef_ref() {return coef;}
        void set_coef(double new_coef) { coef = new_coef; } // Allows modifying coefficient
    
        // Overloaded operators
        bool operator==(const LinkedTerm& other) const 
        {
            return coef == other.coef && exp == other.exp;
        }
};

// 多項式類別宣告
class LinkedPolynomial 
{
    private:
        DoubleNode<LinkedTerm>* first;  // Pointer to the first term
        DoubleNode<LinkedTerm>* last;   // Pointer to the last term
        int capacity;                   // capacity of termArray
        int terms;                      // numbers of nonzero terms
    
    public:
        // Constructor and destructors
        LinkedPolynomial();                              // p(x)=0
        LinkedPolynomial(const LinkedPolynomial& other); // deep copy constructors
        ~LinkedPolynomial();                             // destructors

        // Properties
        int LeadExp();                          // Returns the highest exponent in the polynomial
        double Coef(int e);                     // Returns the coefficient of the term with exponent e
        DLIterator<LinkedTerm> begin() const;   // Return iterator to the beginning
        DLIterator<LinkedTerm> end() const;     // Return iterator to the end

        // Operations
        LinkedPolynomial operator+(const LinkedPolynomial& other) const;    // polynomial addition
        LinkedPolynomial operator-(const LinkedPolynomial& other) const;
        LinkedPolynomial operator*(float constant) const; 
        LinkedPolynomial operator*(const LinkedPolynomial& other) const;    // polynomial multiplication
        LinkedPolynomial Differentiate() const;                             // Differentiates the polynomial
        double Evaluate(double x) const;                                    // Evaluates the polynomial at a given x

        // Other functions
        void Clear();                                   // Clear the polynomial
        void CopyFrom(const LinkedPolynomial& other);   // Copy polynomial from another
        void InsertLinkedTerm(double coef, int exp);    // Add a new term
        void InsertLinkedTerm(const std::string& term); // Add a new term in LaTeX style input
        void DeleteLinkedTerm(int exp);                 // Delete a term 

        // Operands overload
        LinkedPolynomial& operator=(const LinkedPolynomial &);                            // deep copy assignment
        bool operator==(const LinkedPolynomial& other) const;                             // equality check
        bool operator!=(const LinkedPolynomial& other) const;
        friend std::ostream& operator<<(std::ostream& out, const LinkedPolynomial& poly); // output in LaTeX style
        friend std::istream& operator>>(std::istream &in, LinkedPolynomial &poly);        // input in LaTeX style
};

#endif
