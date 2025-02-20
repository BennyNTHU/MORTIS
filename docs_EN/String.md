# `String` Documentation

## Overview

`String.hpp` defines a `String` class designed to manage and manipulate strings in C++. The class provides a range of string manipulation methods such as concatenation, substring extraction, character deletion, and string reversal. Additionally, the class supports various operator overloads and includes a failure function used for pattern matching.

---

## Key Components

### `String` Class

The `String` class models a dynamic string and supports various operations like string concatenation, substring extraction, character deletion, and string reversal. The class utilizes a failure function (`f`) for pattern matching and provides basic string operations like equality checks and indexing.

#### Member Variables:
- **`length`**: The length of the string.
- **`str`**: A pointer to the string stored as a dynamic character array.
- **`f`**: A pointer to an integer array used for the failure function (used for string pattern matching).

#### Constructors & Destructor:
- **`String()`**: Default constructor that initializes an empty string.
- **`String(const char* init)`**: Constructor that initializes the string with a C-style string.
- **`String(const String &s)`**: Copy constructor that initializes the string from another `String` object.
- **`~String()`**: Destructor that frees the dynamically allocated memory used for the string and failure function.

#### String Manipulation Methods:
- **`Concat(String t)`**: Concatenates the current string with another string `t` and returns the result.
  
  Example:
  ```cpp
  String result = str1.Concat(str2);  // Concatenate str1 and str2
  ```

- **`Substr(int i, int j)`**: Returns a substring starting from index `i` with length `j`.
  
  Example:
  ```cpp
  String sub = str.Substr(2, 5);  // Get substring starting at index 2 with length 5
  ```

- **`Delete(int start, int len)`**: Deletes `len` characters starting from index `start` in the string.
  
  Example:
  ```cpp
  String result = str.Delete(2, 3);  // Delete 3 characters starting from index 2
  ```

- **`CharDelete(char c)`**: Deletes all occurrences of character `c` in the string.
  
  Example:
  ```cpp
  String result = str.CharDelete('a');  // Remove all 'a' characters
  ```

- **`Reverse()`**: Reverses the current string and returns the result.
  
  Example:
  ```cpp
  String reversed = str.Reverse();  // Reverse the string
  ```

#### Getters:
- **`FailureFunction()`**: Calculates and stores the failure function for the string.
  
- **`getString()`**: Returns a pointer to the underlying C-style string.
  
- **`getFailure()`**: Returns a pointer to the failure function array.

- **`Length()`**: Returns the length of the string.
  
  Example:
  ```cpp
  int len = str.Length();  // Get the length of the string
  ```

- **`FastFind(String pat)`**: Finds the index of the first occurrence of the pattern `pat` in the string using the failure function. Returns `-1` if the pattern is not found.
  
  Example:
  ```cpp
  int index = str.FastFind("pattern");  // Find the index of "pattern"
  ```

#### Operator Overloads:
- **`operator!()`**: Returns `true` if the string is empty, `false` otherwise.
  
  Example:
  ```cpp
  bool isEmpty = !str;  // Check if the string is empty
  ```

- **`operator[](int index)`**: Returns the character at the specified index of the string.
  
  Example:
  ```cpp
  char ch = str[2];  // Get the character at index 2
  ```

- **`operator=(const String&)`**: Assignment operator to copy another `String` object into the current object.
  
  Example:
  ```cpp
  str1 = str2;  // Assign the value of str2 to str1
  ```

- **`operator==(String t1, String t2)`**: Compares two strings for equality and returns `true` if they are equal.
  
  Example:
  ```cpp
  bool isEqual = (str1 == str2);  // Check if str1 and str2 are equal
  ```

- **`operator!=(String t1, String t2)`**: Compares two strings for inequality and returns `true` if they are not equal.
  
  Example:
  ```cpp
  bool isNotEqual = (str1 != str2);  // Check if str1 and str2 are not equal
  ```

#### Input/Output Operators:
- **`operator<<(std::ostream& out, const String& mat)`**: Outputs the string to an output stream.
  
  Example:
  ```cpp
  std::cout << str;  // Print the string to the console
  ```

- **`operator>>(std::istream& in, String& mat)`**: Reads a string from an input stream.
  
  Example:
  ```cpp
  std::cin >> str;  // Read a string from user input
  ```

---

## Example Usage

```cpp
#include "String.hpp"

int main() {
    // Create a String from a C-style string
    String str1("Hello");

    // Create a String using the copy constructor
    String str2(str1);

    // Concatenate two strings
    String str3 = str1.Concat(str2);  // Result: "HelloHello"

    // Substring example
    String sub = str3.Substr(0, 5);  // Result: "Hello"

    // Delete characters from the string
    String newStr = str3.Delete(5, 5);  // Result: "Hello"

    // Reverse the string
    String reversed = str1.Reverse();  // Result: "olleH"

    // Use the FastFind function to find a pattern
    int index = str3.FastFind("Hello");  // Result: 0 (index of the first "Hello")

    // Output the string
    std::cout << "String: " << str1 << std::endl;

    return 0;
}
```

---

## Potential Errors & Edge Cases

1. **Out-of-Bounds Access**: Be cautious when using the subscript operator `operator[]` and `Substr()` to ensure that the index is within the valid range of the string length.
2. **Empty String**: The `operator!()` method can be used to check if a string is empty. Be sure to handle empty strings appropriately in your code.
3. **Memory Management**: The class uses dynamic memory allocation for the string and failure function, so ensure that the string is properly managed to avoid memory leaks.
4. **Pattern Not Found**: The `FastFind()` function will return `-1` if the pattern is not found. Ensure to handle this case properly in your code.

---

## Dependencies

- **C++ Standard Library**: The class uses the standard C++ libraries `<iostream>`, `<cstring>`, and `<math.h>`.
