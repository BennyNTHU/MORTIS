#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <iostream>

// Assuming your Term structure looks something like:
struct Term 
{
    float coef;
    int exp;

    float get_coef() const {return coef;}
    int get_exp() const {return exp;}
};

// Polynomial class declaration.
class Polynomial 
{
    private:
        int terms;      // number of nonzero terms
        int capacity;   // capacity of the term array
        Term* termArray;

        // Helper to add a new term into the current polynomial (assumes capacity check done).
        

    public:
        // Constructors and Destructor.
        Polynomial();
        Polynomial(Term* t, int degree);
        Polynomial(const Polynomial &poly);
        ~Polynomial();

        // Member functions
        float Coef(int e);
        int LeadExp();
        float Eval(float x);
        void NewTerm(const float theCoeff, const int theExp);
        void NewTerm(const std::string& latexTerm);
        Polynomial Differentiate() const;

        // Operator overloads.
        Polynomial operator+(const Polynomial& poly) const;
        Polynomial operator-(const Polynomial& poly) const;
        Polynomial operator*(const Polynomial& poly) const;
        Polynomial operator*(float constant) const;  // polynomial multiplied by a constant
        bool operator==(const Polynomial &poly) const;
        bool operator!=(const Polynomial &poly) const;
        Polynomial& operator=(const Polynomial &poly);

        // input/output operators
        friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly); // output polynomial in LaTeX form
        friend std::istream& operator>>(std::istream& in, Polynomial& poly);        // readin polynomial in LaTeX form 
};

#endif
