// String.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include "String.hpp"
using namespace std;

// =====================================
// Constructors and destructors
// =====================================

// Default constructor: creates an empty string.
String::String() {
    // An empty string has length 0.
    length = 0;
    // Allocate a buffer for at least the null terminator.
    str = (char *)calloc(1, sizeof(char));
    // Allocate a minimal failure function array.
    f = (int *)calloc(1, sizeof(int));
    // Ensure the string is empty.
    str[0] = '\0';
}

// Constructor from a C-style string.
// This allows you to write: String s = "hello";
String::String(const char *init) {
    if (init == nullptr) {
        // If passed a null pointer, create an empty string.
        length = 0;
        str = (char *)calloc(1, sizeof(char));
        f = (int *)calloc(1, sizeof(int));
        str[0] = '\0';
    } else {
        // Determine the length (excluding the null terminator).
        length = strlen(init);
        // Allocate memory for the string (include room for the null terminator).
        str = (char *)calloc(length + 1, sizeof(char));
        // Allocate memory for the failure function (one per character).
        f = (int *)calloc(length, sizeof(int));
        // Copy the input string.
        strcpy(str, init);
        // Compute the failure function for KMP searches.
        FailureFunction();
    }
}

// Copy constructor: deep copy.
String::String(const String &s) {
    length = s.length;
    // Allocate a new buffer (include null terminator).
    str = (char *)calloc(length + 1, sizeof(char));
    strcpy(str, s.str);
    // Allocate and copy the failure function.
    f = (int *)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        f[i] = s.f[i];
    }
}

// Destructor: free allocated memory.
String::~String() {
    free(str);
    free(f);
}

// =====================================
// String manipulations
// =====================================

// Concatenation: returns a new String that is the concatenation of this string and t.
String String::Concat(String t) {
    // New length is sum of both lengths.
    int newLength = this->length + t.Length();
    // Allocate a temporary buffer to hold the concatenated characters (plus null terminator).
    char* buffer = (char*)calloc(newLength + 1, sizeof(char));
    // Copy current string.
    for (int i = 0; i < this->length; i++) {
        buffer[i] = this->str[i];
    }
    // Append string t.
    for (int i = 0; i < t.Length(); i++) {
        buffer[this->length + i] = t.getString()[i];
    }
    buffer[newLength] = '\0';
    
    // Construct new String from the buffer.
    String result(buffer);
    free(buffer);
    return result;
}

// Substr: returns a new String that is a substring starting at index i with length j.
String String::Substr(int i, int j) {
    // Check for valid range.
    if (i < 0 || i >= length || i + j > length)
        throw "Substr: Index out of range";
    
    // Allocate buffer for the substring (plus null terminator).
    char* buffer = (char*)calloc(j + 1, sizeof(char));
    for (int k = 0; k < j; k++) {
        buffer[k] = str[i + k];
    }
    buffer[j] = '\0';
    
    // Create a new String using the substring.
    String sub(buffer);
    free(buffer);
    return sub;
}

// Delete: removes len characters starting from index start and returns the new String.
String String::Delete(int start, int lenToDelete) {
    if (start < 0 || start >= length || start + lenToDelete > length)
        throw "Delete: Index out of range";
    
    int newLength = length - lenToDelete;
    // Allocate buffer for the new string.
    char* buffer = (char*)calloc(newLength + 1, sizeof(char));
    
    // Copy characters before the deletion.
    for (int i = 0; i < start; i++) {
        buffer[i] = str[i];
    }
    // Copy characters after the deletion.
    for (int i = start + lenToDelete; i < length; i++) {
        buffer[i - lenToDelete] = str[i];
    }
    buffer[newLength] = '\0';
    
    String result(buffer);
    free(buffer);
    return result;
}

// CharDelete: removes all occurrences of character c from the string and returns a new String.
String String::CharDelete(char c) {
    // Allocate a temporary buffer with maximum possible length (same as original).
    char* buffer = (char*)calloc(length + 1, sizeof(char));
    int newIndex = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != c) {
            buffer[newIndex++] = str[i];
        }
    }
    buffer[newIndex] = '\0';
    
    String result(buffer);
    free(buffer);
    return result;
}

// Reverse: returns a new String that is the reverse of the current string.
String String::Reverse() {
    // Allocate a buffer for the reversed string.
    char* buffer = (char*)calloc(length + 1, sizeof(char));
    for (int i = 0; i < length; i++) {
        buffer[i] = str[length - 1 - i];
    }
    buffer[length] = '\0';
    
    String result(buffer);
    free(buffer);
    return result;
}

// =====================================
// Getters
// =====================================

//------------------------------------------------------------------------------
// FailureFunction(): evaluate the failure function (KMP algorithm) and store it in f.
// The failure function f[i] is defined as the length of the longest proper prefix 
// of the substring str[0..i] which is also a suffix of this substring.
//------------------------------------------------------------------------------
void String::FailureFunction() 
{
    int lenP = Length();       // current string length
    if (f != nullptr) {        // free any existing failure function array
        free(f);
    }
    // Allocate memory for f array of the same length.
    f = (int*)calloc(lenP, sizeof(int));
    if (lenP == 0)
        return;
    
    // The first position is defined as -1 (or sometimes 0; here we choose -1).
    f[0] = -1;
    // For each subsequent character, compute the failure function.
    for (int j = 1; j < lenP; j++) 
    {
        int i = f[j - 1];  // start with the failure value of the previous position
        // While we have a valid index and the character at current j does not match 
        // the character following the current candidate prefix,
        // backtrack using the failure function.
        while (i >= 0 && str[j] != str[i + 1]) 
        {
            i = f[i];
        }
        // If a match is found, update the failure function.
        if (str[j] == str[i + 1]) 
            f[j] = i + 1;
        else 
            f[j] = -1;
    }
}

//------------------------------------------------------------------------------
// getString(): returns a pointer to the internal character array.
//------------------------------------------------------------------------------
char* String::getString() const 
{
    return str;
}

//------------------------------------------------------------------------------
// getFailure(): returns the pointer to the failure function array.
//------------------------------------------------------------------------------
int* String::getFailure() 
{
    return f;
}

//------------------------------------------------------------------------------
// Length(): returns the length of the string (number of characters).
//------------------------------------------------------------------------------
int String::Length() 
{
    return length;
}

//------------------------------------------------------------------------------
// FastFind(String pat): Uses the Knuth-Morris-Pratt algorithm to find an occurrence
// of the pattern pat in the current string. Returns the starting index if found,
// or -1 if the pattern is not found.
//------------------------------------------------------------------------------
int String::FastFind(String pat) 
{
    int posPat = 0, posStr = 0;
    int lenPat = pat.Length();
    int lenStr = Length();
    
    // Make sure the pattern's failure function is computed.
    pat.FailureFunction();
    
    while (posStr < lenStr && posPat < lenPat) 
    {
        if (pat.str[posPat] == str[posStr]) 
        {
            posPat++;
            posStr++;
        } 
        else 
        {
            if (posPat == 0)
                posStr++;
            else 
                posPat = pat.f[posPat - 1] + 1;
        }
    }
    if (posPat == lenPat)
        return posStr - lenPat;  // Match found, return starting index.
    else
        return -1;  // No match found.
}

// =====================================
// Operand overloads
// =====================================

// Overloaded operator! : returns true if the string is empty.
bool operator!(String t) {
    return (t.Length() == 0);
}

// Subscript operator: returns the ith character.
char String::operator[](int index) const {
    if (index < 0 || index >= length)
        throw "Index out of range";
    return str[index];
}

String & String::operator=(const String &other) {
    if (this != &other) {
        // Free any previously allocated memory.
        if (str) {
            free(str);
            str = nullptr;
        }
        if (f) {
            free(f);
            f = nullptr;
        }

        // Copy the length.
        length = other.length;

        // Allocate new memory for the string.
        // Note: If you want to ensure a null terminator, you might allocate (length+1) characters.
        str = (char *)calloc(length, sizeof(char));
        if (str == nullptr && length > 0) {
            throw std::bad_alloc();
        }
        // Copy the characters.
        for (int i = 0; i < length; i++) {
            str[i] = other.str[i];
        }

        // Allocate new memory for the failure function array.
        f = (int *)calloc(length, sizeof(int));
        if (f == nullptr && length > 0) {
            throw std::bad_alloc();
        }
        // Copy the failure function values.
        for (int i = 0; i < length; i++) {
            f[i] = other.f[i];
        }
    }
    return *this;
}

// Equality operator: compares two strings.
bool operator==(String t1, String t2) {
    if (t1.Length() != t2.Length())
        return false;
    return (strncmp(t1.getString(), t2.getString(), t1.Length()) == 0);
}

// Inequality operator.
bool operator!=(String t1, String t2) {
    return !(t1 == t2);
}

// =====================================
// input/output operand
// =====================================

// Overloaded stream operators.
std::ostream & operator<<(std::ostream &out, const String &s) {
    out << s.getString();
    return out;
}

std::istream & operator>>(std::istream &in, String &s) {
    std::string temp;
    in >> temp;
    // Free old data.
    if (s.str) free(s.str);
    s.length = temp.size();
    s.str = (char*)calloc(s.length, sizeof(char));
    for (int i = 0; i < s.length; i++) {
        s.str[i] = temp[i];
    }
    s.FailureFunction();
    return in;
}
