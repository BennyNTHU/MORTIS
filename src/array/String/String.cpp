#include <iostream>
#include <algorithm>
#include <cstring>
#include "String.hpp"
using namespace std;

String::String(char *init, int m)   // constructor using input string init of length m
{
    length = m;
    str = (char *)calloc(length, sizeof(char));
    f = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++)
        str[i] = init[i];
    FailureFunction();  // evaluate the failure function and store in f
}

String::String(const String &s) // constructor using another string
{
    length = s.length;  // copy all attributes
    str = (char *)calloc(length, sizeof(char));
    for (int i = 0; i < length; i++)
        str[i] = s.str[i];
    // IMPORTANT: To avoid double-free errors, perform deep copy of f
    f = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++)
        f[i] = s.f[i];
}

String::~String()   // destructor
{
    free(str);
    free(f);
}

String String::Concat(String t) // concatenation with another string t
{
    int new_length = length + t.Length(); // new length
    char *A = (char *)calloc(new_length, sizeof(char));  // allocate new array dynamically
    for (int i = 0; i < length; i++)        // copy current string
        A[i] = str[i];
    for (int i = length; i < new_length; i++) // copy t
        A[i] = t.getString()[i - length];

    String concat_str(A, new_length);   // construct the concatenated string
    free(A);
    return concat_str;
}

String String::Substr(int i, int j) // generate a substring from index i with length j
{
    if (i + j - 1 > length - 1)
        throw "out of range!!";
    
    char *substring = (char *)calloc(j, sizeof(char));
    for (int k = 0; k < j; k++)
        substring[k] = str[i + k];

    String Sub(substring, j);
    free(substring);
    return Sub;
}

String String::Delete(int start, int len)   // delete len characters from index start
{
    if (start > length - 1 || len > length)
        throw "out of range!!";
    
    int del_length = length - len;          // new length
    char *del_str = (char *)calloc(del_length, sizeof(char));
    
    for (int i = 0; i < start; i++)             // characters before start
        del_str[i] = str[i];
    for (int i = start + len; i < length; i++)    // characters after deleted block
        del_str[i - len] = str[i];
    
    String D(del_str, del_length);
    free(del_str);
    return D;
}

String String::CharDelete(char c)   // delete a specific character in the string
{   
    // Make a copy of the current string for modification
    char *temp = (char *)calloc(length + 1, sizeof(char));
    strcpy(temp, str);
    int new_length = length;
    
    for (int i = 0; i < new_length; i++) {
        if (temp[i] == c) {
            // Shift left to remove character at position i
            for (int j = i; j < new_length; j++)
                temp[j] = temp[j + 1];
            new_length--;
            i--; // Check new character at this index
        }
    }
    
    String CD(temp, new_length);
    free(temp);
    return CD;
}

void String::FailureFunction()  // evaluate the failure function and store in f
{
    int lengthP = Length();
    f[0] = -1;
    for (int j = 1; j < lengthP; j++) 
    {
        int i = f[j - 1];
        while ((str[j] != str[i + 1]) && (i >= 0)) 
            i = f[i];
        if (str[j] == str[i + 1]) 
            f[j] = i + 1;
        else 
            f[j] = -1;
    }
}

char* String::getString() const   // get the string
{
    return str;
}

int* String::getf()    // get failure function
{
    return f;
}

int String::Length()   // get the number of characters of *this
{
    return length;
}

int String::FastFind(String pat) 
{
    // Using Knuth-Morris-Pratt (KMP) Algorithm
    int posP = 0, posS = 0;
    int lengthP = pat.Length(), lengthS = Length();
    while ((posP < lengthP) && (posS < lengthS))
    {
        if (pat.str[posP] == str[posS]) 
        {  
            posP++; 
            posS++;    
        }
        else
        {
            if (posP == 0) 
                posS++;
            else 
                posP = pat.f[posP - 1] + 1;
        }
    }
    if (posP < lengthP) 
        return -1;
    else 
        return posS - lengthP;
}

std::ostream& operator<<(std::ostream& out, const String& s) 
{
    out << s.getString();
    return out;
}

bool operator==(String t1, String t2)   // equality test
{
    return strcmp(t1.getString(), t2.getString()) == 0;
}

bool operator!(String t)    // empty test, return true if string is empty, otherwise false
{
    return (t.Length() == 0);
}

String & String::operator=(const String &t) // overload assignment (deep copy)
{
    if (this != &t) {
        free(str);
        free(f);
        length = t.length;
        str = (char *)calloc(length, sizeof(char));
        f = (int *)calloc(length, sizeof(int));
        for (int i = 0; i < length; i++) {
            str[i] = t.str[i];
            f[i] = t.f[i];
        }
    }
    return *this;
}

// ***NEW FUNCTION*** reverse(): Returns a new String with the characters in reverse order.
String String::reverse() {
    char *rev = (char *)calloc(length, sizeof(char));
    for (int i = 0; i < length; i++) {
        rev[i] = str[length - 1 - i];
    }
    String result(rev, length);
    free(rev);
    return result;
}
