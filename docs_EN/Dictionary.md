# **Dictionary API Documentation**

## **Overview**
The `Dictionary<K, V>` class is a **key-value storage** container similar to a **hash map** or **associative array**. It supports **basic operations** such as **insertion, deletion, lookup, mapping, and reduction** while maintaining a **fixed capacity**.

This class supports **various data types** for keys and values:
- `int`
- `char`
- `float`
- `bool`
- `double`
- `std::string`
- `GeneralArray<MIXED_TYPE>`
- `Polynomial`
- `SparseMatrix`
- `String`

## **Table of Contents**
- [Dictionary API Documentation](#dictionary-api-documentation)
  - [Overview](#overview)
  - [Class Declaration](#class-declaration)
  - [Constructors & Destructor](#constructors--destructor)
  - [Properties](#properties)
  - [Manipulation Functions](#manipulation-functions)
  - [Operator Overloads](#operator-overloads)
  - [Example Usage](#example-usage)
  - [Complete Example](#complete-example)

---

## **Class Declaration**
```cpp
template <typename K, typename V>
class Dictionary
{
private:
    int capacity;               // Maximum number of elements
    int size;                   // Current number of elements
    KeyValuePair<K, V>* arr;    // Array of key-value pairs

public:
    // Constructors & Destructor
    Dictionary(int c);
    Dictionary(const Dictionary<K, V>& dict);
    ~Dictionary();

    // Properties
    int Capacity() const;
    bool IsEmpty() const;
    int Size() const;
    bool isBelong(const K& key) const;

    // Manipulation
    void Insert(const KeyValuePair<K, V>& pair);
    void Remove(const K& key);
    vector<V> Map(const K& key) const;
    void reduce(std::function<V(const V&, const V&)> reducer);

    // Operators
    Dictionary<K, V>& operator=(const Dictionary<K, V>& dict);
    V& operator[](const K& key);
    bool operator==(const Dictionary<K, V>& dict) const;
    bool operator!=(const Dictionary<K, V>& dict) const;
    template <typename U, typename W>
    friend std::ostream& operator<<(std::ostream& os, const Dictionary<U, W>& dict);
};
```

---

## **Constructors & Destructor**

### **Dictionary(int c)**
Creates a new dictionary with a given **capacity**.
```cpp
Dictionary<int, std::string> dict(10); // Create a dictionary with capacity 10
```

### **Dictionary(const Dictionary<K, V>& dict)**
Creates a **deep copy** of an existing dictionary.

```cpp
Dictionary<std::string, int> dict1(5);
Dictionary<std::string, int> dict2 = dict1; // Copy constructor
```

### **~Dictionary()**
Destroys the dictionary and deallocates memory.

---

## **Properties**

### **int Capacity() const**
Returns the maximum number of elements the dictionary can hold.

```cpp
cout << "Capacity: " << dict.Capacity() << endl;
```

### **bool IsEmpty() const**
Checks if the dictionary is empty.

```cpp
if (dict.IsEmpty()) {
    cout << "Dictionary is empty!" << endl;
}
```

### **int Size() const**
Returns the current number of elements.

```cpp
cout << "Size: " << dict.Size() << endl;
```

### **bool isBelong(const K& key) const**
Checks if a key exists in the dictionary.

```cpp
if (dict.isBelong("apple")) {
    cout << "Apple is in the dictionary!" << endl;
}
```

---

## **Manipulation Functions**

### **void Insert(const KeyValuePair<K, V>& pair)**
Inserts a **key-value pair** into the dictionary.

```cpp
Dictionary<std::string, int> dict(5);
dict.Insert({"apple", 3});
dict.Insert({"banana", 2});
```

### **void Remove(const K& key)**
Removes **all values** associated with a key.

```cpp
dict.Remove("apple");
```

### **vector<V> Map(const K& key) const**
Returns **all values** associated with a key.

```cpp
vector<int> values = dict.Map("banana");
for (int v : values) {
    cout << v << " ";
}
```

### **void reduce(std::function<V(const V&, const V&)> reducer)**
Merges values with the **same key** using a **user-defined function**.

```cpp
Dictionary<std::string, int> dict(5);
dict.Insert({"apple", 3});
dict.Insert({"apple", 5});
dict.reduce([](int a, int b) { return a + b; }); // Combine duplicate keys by summing values
```

---

## **Operator Overloads**

### **Dictionary<K, V>& operator=(const Dictionary<K, V>& dict)**
Assigns one dictionary to another.

```cpp
Dictionary<std::string, int> dict1(5);
Dictionary<std::string, int> dict2 = dict1; // Assignment
```

### **V& operator[](const K& key)**
Retrieves a value associated with a key.

```cpp
cout << "Value: " << dict["apple"] << endl;
```

### **bool operator==(const Dictionary<K, V>& dict) const**
Checks if two dictionaries are equal.

```cpp
if (dict1 == dict2) {
    cout << "Dictionaries are equal!" << endl;
}
```

### **bool operator!=(const Dictionary<K, V>& dict) const**
Checks if two dictionaries are **not equal**.

```cpp
if (dict1 != dict2) {
    cout << "Dictionaries are different!" << endl;
}
```

### **friend ostream& operator<<(ostream& os, const Dictionary<K, V>& dict)**
Prints the dictionary.

```cpp
cout << dict << endl;
```

---

## **Example Usage**

### **Basic Operations**
```cpp
#include "Dictionary.hpp"

int main() {
    Dictionary<std::string, int> dict(10);

    // Insert elements
    dict.Insert({"apple", 3});
    dict.Insert({"banana", 2});
    dict.Insert({"apple", 5});

    // Check properties
    cout << "Size: " << dict.Size() << endl;
    cout << "Is empty? " << (dict.IsEmpty() ? "Yes" : "No") << endl;

    // Remove an element
    dict.Remove("banana");

    // Map operation
    vector<int> appleValues = dict.Map("apple");
    cout << "Values for 'apple': ";
    for (int v : appleValues) cout << v << " ";
    cout << endl;

    // Reduce operation
    dict.reduce([](int a, int b) { return a + b; });
    cout << "After reduction: " << dict << endl;

    return 0;
}
```

---

## **Complete Example**
```cpp
#include "Dictionary.hpp"
#include <iostream>

int main() {
    Dictionary<std::string, double> dict(10);

    // Insert key-value pairs
    dict.Insert({"Apple", 2.5});
    dict.Insert({"Banana", 1.2});
    dict.Insert({"Apple", 3.5});
    dict.Insert({"Orange", 1.8});
    
    // Print the dictionary
    cout << "Initial Dictionary: " << dict << endl;

    // Check for key existence
    cout << "Does 'Apple' exist? " << (dict.isBelong("Apple") ? "Yes" : "No") << endl;

    // Reduce values with a summing function
    dict.reduce([](double a, double b) { return a + b; });

    cout << "After Reduction: " << dict << endl;

    // Remove an entry
    dict.Remove("Banana");

    // Final state
    cout << "Final Dictionary: " << dict << endl;

    return 0;
}
```

---

## **Conclusion**
The **Dictionary<K, V>** class is a **lightweight key-value store** that provides **basic dictionary functionalities**. It supports **custom types**, **mapping**, **reductions**, and **operator overloads**, making it versatile for various applications.
