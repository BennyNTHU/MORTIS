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
        String(char *init, int m);    // constructor using input string init of length m
        String(const String &s);      // constructor using another string
        ~String();                    // destructor
    
        String Concat(String t);      // concatenation with another string t
        String Substr(int i, int j);  // generate a substring from index i of length j
        String Delete(int start, int len);  // delete len characters from index start
        String CharDelete (char c);         // delete a specific character in the string
        String reverse();             // ***NEW*** reverse the string
        
        void FailureFunction();     // evaluate the failure function and store in f
        char* getString();          // get the string
        int* getf();                // get failure function
        int Length();               // get the number of characters of *this
        int FastFind(String pat);   // Return an index where pat matches the substring

        friend bool operator==(String t1, String t2);   // equality test
        friend bool operator!(String t);                // empty test
        String & operator=(const String &);             // overload assignment
};

bool operator==(String t1, String t2);    // equality test
bool operator!(String t);                 // empty test, returns true if string is empty

#endif
