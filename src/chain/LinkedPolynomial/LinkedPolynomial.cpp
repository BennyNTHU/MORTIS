#include "LinkedPolynomial.hpp"
#include <sstream>
#include <cctype>
#include <iostream>
#include <cmath>
#include <stdexcept>

// Constructor: Initializes an empty polynomial
LinkedPolynomial::LinkedPolynomial() : first(nullptr), last(nullptr) {}

// Copy constructor: Deep copies another polynomial
LinkedPolynomial::LinkedPolynomial(const LinkedPolynomial& other) {
    first = last = nullptr;
    CopyFrom(other);
}

// Destructor: Clears the polynomial to free memory
LinkedPolynomial::~LinkedPolynomial() {
    Clear();
}

// Returns the highest exponent (lead exponent)
int LinkedPolynomial::LeadExp() {
    if (!first) throw std::runtime_error("Polynomial is empty.");
    return first->getData().get_exp();
}

// Returns coefficient for exponent e
double LinkedPolynomial::Coef(int e) {
    for (DLIterator<LinkedTerm> it = begin(); it != end(); ++it) {
        if (it.getCurrent()->getData().get_exp() == e) {
            return it.getCurrent()->getData().get_coef();
        }
    }
    return 0;
}

// Begin iterator for traversing the polynomial
DLIterator<LinkedTerm> LinkedPolynomial::begin() const {
    return DLIterator<LinkedTerm>(first);
}

// End iterator (nullptr signifies the end of the list)
DLIterator<LinkedTerm> LinkedPolynomial::end() const {
    return DLIterator<LinkedTerm>(nullptr);
}

// Adds two polynomials and returns a new polynomial
LinkedPolynomial LinkedPolynomial::operator+(const LinkedPolynomial& other) const {
    LinkedPolynomial result = *this;
    for (DLIterator<LinkedTerm> it = other.begin(); it != other.end(); ++it) {
        result.InsertLinkedTerm(it.getCurrent()->getData().get_coef(), it.getCurrent()->getData().get_exp());
    }
    return result;
}

// Multiplies two polynomials and returns a new polynomial
LinkedPolynomial LinkedPolynomial::operator*(const LinkedPolynomial& other) const {
    LinkedPolynomial result;
    for (DLIterator<LinkedTerm> itA = begin(); itA != end(); ++itA) {
        for (DLIterator<LinkedTerm> itB = other.begin(); itB != other.end(); ++itB) {
            result.InsertLinkedTerm(
                itA.getCurrent()->getData().get_coef() * itB.getCurrent()->getData().get_coef(),
                itA.getCurrent()->getData().get_exp() + itB.getCurrent()->getData().get_exp()
            );
        }
    }
    return result;
}

// Computes the derivative of the polynomial
LinkedPolynomial LinkedPolynomial::Differentiate() const {
    LinkedPolynomial result;
    for (DLIterator<LinkedTerm> it = begin(); it != end(); ++it) {
        if (it.getCurrent()->getData().get_exp() > 0) {
            result.InsertLinkedTerm(
                it.getCurrent()->getData().get_coef() * it.getCurrent()->getData().get_exp(),
                it.getCurrent()->getData().get_exp() - 1
            );
        }
    }
    return result;
}

// Evaluates the polynomial at a given x
double LinkedPolynomial::Evaluate(double x) const {
    double result = 0.0;
    for (DLIterator<LinkedTerm> it = begin(); it != end(); ++it) {
        result += it.getCurrent()->getData().get_coef() * pow(x, it.getCurrent()->getData().get_exp());
    }
    return result;
}

// Clears the polynomial by deleting all terms
void LinkedPolynomial::Clear() {
    while (first) {
        DoubleNode<LinkedTerm>* temp = first;
        first = static_cast<DoubleNode<LinkedTerm>*>(first->getLink());
        delete temp;
    }
    last = nullptr;
}

// Copies the polynomial from another
void LinkedPolynomial::CopyFrom(const LinkedPolynomial& other) {
    for (DLIterator<LinkedTerm> it = other.begin(); it != other.end(); ++it) {
        InsertLinkedTerm(it.getCurrent()->getData().get_coef(), it.getCurrent()->getData().get_exp());
    }
}

// Inserts a new term into the polynomial
void LinkedPolynomial::InsertLinkedTerm(double coef, int exp) {
    if (coef == 0) return;

    DoubleNode<LinkedTerm>* newNode = new DoubleNode<LinkedTerm>(LinkedTerm(coef, exp));

    if (!first) {
        first = last = newNode;
        newNode->setLink(nullptr);
        newNode->setPrev(nullptr);
        return;
    }

    DoubleNode<LinkedTerm>* current = first;
    while (current && current->getData().get_exp() > exp) {
        current = static_cast<DoubleNode<LinkedTerm>*>(current->getLink());
    }

    if (current && current->getData().get_exp() == exp) {
        LinkedTerm temp = current->getData(); 
        temp.set_coef(temp.get_coef() + coef);

        if (temp.get_coef() == 0) {
            DeleteLinkedTerm(exp);
        } else {
            *const_cast<LinkedTerm*>(&current->getData()) = temp;
        }

        delete newNode;
    } else {
        newNode->setLink(current);
        if (current) {
            newNode->setPrev(current->getPrev());
            if (current->getPrev()) {
                current->getPrev()->setLink(newNode);
            } else {
                first = newNode;
            }
            current->setPrev(newNode);
        } else {
            last->setLink(newNode);
            newNode->setPrev(last);
            last = newNode;
        }
    }
}

// Deletes a term with a given exponent
void LinkedPolynomial::DeleteLinkedTerm(int exp) {
    DoubleNode<LinkedTerm>* current = first;
    while (current && current->getData().get_exp() != exp) {
        current = static_cast<DoubleNode<LinkedTerm>*>(current->getLink());
    }

    if (!current) return;

    if (current == first) first = static_cast<DoubleNode<LinkedTerm>*>(current->getLink());
    if (current == last) last = current->getPrev();

    if (current->getPrev()) current->getPrev()->setLink(current->getLink());
    if (current->getLink()) static_cast<DoubleNode<LinkedTerm>*>(current->getLink())->setPrev(current->getPrev());

    delete current;
}

// Check if two polynomials are equal
bool LinkedPolynomial::operator==(const LinkedPolynomial &other) const {
    DLIterator<LinkedTerm> it1 = begin();
    DLIterator<LinkedTerm> it2 = other.begin();
    
    while (it1 != end() && it2 != other.end()) {
        if (it1.getCurrent()->getData().get_exp() != it2.getCurrent()->getData().get_exp() ||
            it1.getCurrent()->getData().get_coef() != it2.getCurrent()->getData().get_coef()) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return it1 == end() && it2 == other.end();
}

// Overloaded insertion operator to output the polynomial
std::ostream &operator<<(std::ostream &out, const LinkedPolynomial &poly) {
    for (DLIterator<LinkedTerm> it = poly.begin(); it != poly.end(); ++it) {
        out << it.getCurrent()->getData().get_coef() << "x^" << it.getCurrent()->getData().get_exp() << " ";
    }
    return out;
}

// Overloaded extraction operator to read polynomial from LaTeX format
std::istream &operator>>(std::istream &in, LinkedPolynomial &poly) {
    double coef;
    int exp;
    while (in >> coef >> exp) {
        poly.InsertLinkedTerm(coef, exp);
    }
    return in;
}

// Assignment operator
LinkedPolynomial& LinkedPolynomial::operator=(const LinkedPolynomial& other) {
    if (this != &other) {
        Clear();
        CopyFrom(other);
    }
    return *this;
}
