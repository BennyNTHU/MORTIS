#ifndef STRING
#define STRING
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

class String
{
    private:
        int length; // length of the string
        char* str;  // the string
        int* f;     // failure function

    public:
        // Constructors and destructors
        String();                     // default constructor
        String(const char* init);     // constructor from cstring
        String(const String &s);      // constructor using another string
        ~String();                    // destructor

        // String manipulations
        String Concat(String t);      // concatenation with another string t
        String Substr(int i, int j);  // generate a substring from index i of length j
        String Delete(int start, int len);  // delete len characters from index start
        String CharDelete (char c);         // delete a specific character in the string
        String Reverse();             // ***NEW*** reverse the string
        
        // Getters
        void FailureFunction();     // evaluate the failure function and store in f
        char* getString() const;    // get the string
        int* getFailure();          // get failure function
        int Length();               // get the number of characters of *this
        int FastFind(String pat);   // Return an index where pat matches the substring
        
        // Operand overloads
        friend bool operator!(String t);                // empty test
        char operator[](int index) const;               // Subscript operator: returns the the ith char
        String & operator=(const String &);             // overload assignment
        friend bool operator==(String t1, String t2);   // equality test
        friend bool operator!=(String t1, String t2);   // equality test

        // input/output operand
        friend std::ostream& operator<<(std::ostream& out, const String& mat);  // print the string
        friend std::istream& operator>>(std::istream& in, String& mat);         // usual input of the string
};

#endif
