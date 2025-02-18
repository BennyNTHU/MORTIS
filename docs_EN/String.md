# String Data Structure Documentation

This document provides a detailed guide on how to use the custom **String** class. The class supports a variety of operations such as concatenation, substring extraction, deletion, character deletion, pattern matching using the Knuth-Morris-Pratt (KMP) algorithm, and string reversal. Additionally, it overloads some operators for equality, emptiness checking, and assignment. Note that the copy constructor and assignment operator have been modified to perform deep copies in order to prevent memory errors.

---

## Table of Contents

- [String Data Structure Documentation](#string-data-structure-documentation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Supported Operations](#supported-operations)
  - [API Documentation](#api-documentation)
    - [Constructors and Destructor](#constructors-and-destructor)
    - [Member Functions](#member-functions)
    - [Operator Overloads](#operator-overloads)
  - [Usage Examples](#usage-examples)
  - [Compilation Instructions](#compilation-instructions)
  - [Summary](#summary)

---

## Overview

The **String** class is a custom implementation for string manipulation that internally stores a C-style string and computes a failure function used for pattern matching (KMP algorithm). In addition to common operations like concatenation and substring extraction, the class now supports a `reverse()` function that returns a new string with its characters in reverse order.

---

## Supported Operations

- **Construction:**  
  Create a new String from a C-style array or by copying another String. The failure function is computed upon construction.

- **Concatenation (`Concat`):**  
  Join two String objects to form a new String.

- **Substring Extraction (`Substr`):**  
  Extract a substring starting at a specified index with a given length.

- **Deletion (`Delete`):**  
  Delete a block of characters from the string.

- **Character Deletion (`CharDelete`):**  
  Remove all occurrences of a specified character from the string.

- **Pattern Matching (`FastFind`):**  
  Use the KMP algorithm to search for a pattern within the string.

- **String Reversal (`reverse`):**  
  Return a new String with the characters in reverse order.

- **Accessors:**  
  - `getString()`: Returns the underlying C-string.  
  - `Length()`: Returns the length of the string.  
  - `getf()`: Returns the computed failure function array.

- **Operator Overloads:**  
  - `operator==`: Tests for equality between two String objects.  
  - `operator!`: Checks if a String is empty.  
  - `operator=`: Assignment operator that performs a deep copy.

---

## API Documentation

### Constructors and Destructor

- **`String(char *init, int m)`**  
  Constructs a new String object from the C-style string `init` with length `m`. The failure function is computed immediately.

  **Usage Example:**
  ```cpp
  char init[] = "Hello, World!";
  String s1(init, sizeof(init) - 1);
  ```

- **`String(const String &s)`**  
  Copy constructor. Creates a new String object as a deep copy of the existing String `s`.

- **`~String()`**  
  Destructor. Frees the allocated memory for both the string and the failure function.

### Member Functions

- **`String Concat(String t)`**  
  Concatenates the current string with string `t` and returns the resulting String.

  **Usage Example:**
  ```cpp
  String s3 = s1.Concat(s2);
  ```

- **`String Substr(int i, int j)`**  
  Returns a substring starting at index `i` with length `j`. Throws an exception if the requested range is out of bounds.

  **Usage Example:**
  ```cpp
  String sub = s1.Substr(7, 5);  // Should return "World" if s1 is "Hello, World!"
  ```

- **`String Delete(int start, int len)`**  
  Deletes `len` characters from the string starting at index `start` and returns the new String.

- **`String CharDelete(char c)`**  
  Deletes all occurrences of the character `c` from the string and returns the new String.

- **`String reverse()`**  
  Returns a new String with the characters in reverse order.

  **Usage Example:**
  ```cpp
  String sRev = s1.reverse();
  // If s1 is "Hello, World!", sRev will be "!dlroW ,olleH"
  ```

- **`void FailureFunction()`**  
  Computes the failure function for the string (used by the KMP algorithm) and stores it in the internal array `f`.

- **`char* getString()`**  
  Returns the underlying C-style string.

- **`int* getf()`**  
  Returns the pointer to the failure function array.

- **`int Length()`**  
  Returns the number of characters in the string.

- **`int FastFind(String pat)`**  
  Uses the KMP algorithm to find the substring `pat` within the string. Returns the starting index if found, or -1 if not found.

### Operator Overloads

- **`bool operator==(String t1, String t2)`**  
  Returns `true` if the two Strings are identical, `false` otherwise.

- **`bool operator!(String t)`**  
  Returns `true` if the String is empty; otherwise, returns `false`.

- **`String & operator=(const String &t)`**  
  Assignment operator that performs a deep copy of the string and its failure function.

---

## Usage Examples

Below is an example program that demonstrates how to use the String class:

```cpp
#include <iostream>
#include "String.h"
using namespace std;

int main() {
    // Create a String from a C-style string.
    char init1[] = "Hello, World!";
    String s1(init1, sizeof(init1) - 1);
    cout << "s1: " << s1.getString() << endl;
    cout << "Length of s1: " << s1.Length() << endl;
    
    // Reverse the string.
    String sRev = s1.reverse();
    cout << "Reversed s1: " << sRev.getString() << endl;
    
    // Concatenate s1 with another string.
    char init2[] = " Goodbye!";
    String s2(init2, sizeof(init2) - 1);
    String s3 = s1.Concat(s2);
    cout << "s1 concatenated with s2: " << s3.getString() << endl;
    
    // Extract a substring from s1.
    try {
        String sub = s1.Substr(7, 5);
        cout << "Substring of s1 (index 7, length 5): " << sub.getString() << endl;
    } catch (const char* err) {
        cout << "Substr error: " << err << endl;
    }
    
    // Delete a block of characters from s1.
    try {
        String del = s1.Delete(5, 3);
        cout << "s1 after deleting 3 characters from index 5: " << del.getString() << endl;
    } catch (const char* err) {
        cout << "Delete error: " << err << endl;
    }
    
    // Delete all occurrences of a character.
    String cd = s1.CharDelete('o');
    cout << "s1 after deleting 'o': " << cd.getString() << endl;
    
    // Pattern matching using KMP.
    char patInit[] = "World";
    String pattern(patInit, sizeof(patInit) - 1);
    int pos = s1.FastFind(pattern);
    cout << "Position of 'World' in s1: " << pos << endl;
    
    // Test equality operator.
    char init3[] = "Hello, World!";
    String s4(init3, sizeof(init3) - 1);
    if (s1 == s4)
        cout << "s1 equals s4." << endl;
    else
        cout << "s1 does not equal s4." << endl;
    
    // Test empty operator.
    String emptyStr("");
    if (!emptyStr)
        cout << "emptyStr is empty." << endl;
    else
        cout << "emptyStr is not empty." << endl;
    
    // Test assignment operator (deep copy).
    String s5;
    s5 = s1;
    cout << "s5 (assigned from s1): " << s5.getString() << endl;
    
    return 0;
}
```

---

## Compilation Instructions

To compile and run the test program, ensure you have the following files in the same directory:
- `String.h`
- `String.cpp`
- `String-test.cpp`

Use a C++ compiler (such as g++) with support for C++ standards. For example, using g++:

```bash
g++ -std=c++11 String.cpp String-test.cpp -o stringTest
```

Then run the executable:

- On Linux/macOS:
  ```bash
  ./stringTest
  ```
- On Windows:
  ```bash
  stringTest.exe
  ```

---

## Summary

The **String** class provides a variety of operations for string manipulation, including concatenation, substring extraction, deletion, character deletion, pattern matching (via KMP), and reversal. The class also correctly handles deep copies to avoid memory errors. Use the provided sample code to integrate and test the functionality in your projects.

If you have any questions or need further modifications, please feel free to ask!