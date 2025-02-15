// g++ -std=c++17 BloomFilter.cpp BloomFilter-test.cpp -o test

#include <iostream>
#include "BloomFilter.hpp"

void testBloomFilterInt() 
{
    std::cout << "\n==== Testing BloomFilter<int> ====\n";

    BloomFilter<int> intFilter(100);

    // Insert values
    intFilter.insert(10);
    intFilter.insert(25);
    intFilter.insert(42);
    intFilter.insert(99);

    // Display the bit array
    std::cout << "Bit array after inserting 10, 25, 42, 99:\n";
    intFilter.display();

    // Search for present values
    std::cout << "Searching 10: " << (intFilter.search(10) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 42: " << (intFilter.search(42) ? "Found" : "Not Found") << std::endl;

    // Search for absent values
    std::cout << "Searching 50: " << (intFilter.search(50) ? "False Positive" : "Not Found") << std::endl;
    std::cout << "Searching 77: " << (intFilter.search(77) ? "False Positive" : "Not Found") << std::endl;
}

void testBloomFilterChar() 
{
    std::cout << "\n==== Testing BloomFilter<char> ====\n";

    BloomFilter<char> charFilter(100);

    // Insert values
    charFilter.insert('A');
    charFilter.insert('M');
    charFilter.insert('Z');

    // Display the bit array
    std::cout << "Bit array after inserting 'A', 'M', 'Z':\n";
    charFilter.display();

    // Search for present values
    std::cout << "Searching 'A': " << (charFilter.search('A') ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 'M': " << (charFilter.search('M') ? "Found" : "Not Found") << std::endl;

    // Search for absent values
    std::cout << "Searching 'B': " << (charFilter.search('B') ? "False Positive" : "Not Found") << std::endl;
    std::cout << "Searching 'X': " << (charFilter.search('X') ? "False Positive" : "Not Found") << std::endl;
}

void testBloomFilterString() 
{
    std::cout << "\n==== Testing BloomFilter<std::string> ====\n";

    BloomFilter<std::string> stringFilter(100);

    // Insert values
    stringFilter.insert("hello");
    stringFilter.insert("world");
    stringFilter.insert("bloom");

    // Display the bit array
    std::cout << "Bit array after inserting 'hello', 'world', 'bloom':\n";
    stringFilter.display();

    // Search for present values
    std::cout << "Searching 'hello': " << (stringFilter.search("hello") ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 'bloom': " << (stringFilter.search("bloom") ? "Found" : "Not Found") << std::endl;

    // Search for absent values
    std::cout << "Searching 'filter': " << (stringFilter.search("filter") ? "False Positive" : "Not Found") << std::endl;
    std::cout << "Searching 'data': " << (stringFilter.search("data") ? "False Positive" : "Not Found") << std::endl;
}

int main() 
{
    testBloomFilterInt();
    testBloomFilterChar();
    testBloomFilterString();
    
    return 0;
}
