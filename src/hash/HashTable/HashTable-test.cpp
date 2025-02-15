// g++ -std=c++17 HashTable.cpp HashTable-test.cpp\
../../chain/DoublyLinkedList/DoublyLinkedList.cpp\
../../chain/ChainIterator/ChainIterator.cpp ../../chain/DLIterator/DLIterator.cpp\
../../chain/Node/Node.cpp ../../chain/DoubleNode/DoubleNode.cpp -o test

#include "HashTable.hpp"
#include <iostream>

void testIntHashTable() 
{
    HashTable<int> intTable(10);
    std::cout << "Testing HashTable<int>...\n";

    intTable.insert(5);
    intTable.insert(15);
    intTable.insert(25);

    std::cout << "HashTable after insertions:\n";
    intTable.display();

    std::cout << "Searching 15: " << (intTable.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Removing 15...\n";
    intTable.remove(15);
    std::cout << "Searching 15: " << (intTable.search(15) ? "Found" : "Not Found") << std::endl;
    intTable.display();
    std::cout << std::endl;
}

void testCharHashTable() 
{
    HashTable<char> charTable(10);
    std::cout << "\nTesting HashTable<char>...\n";

    charTable.insert('a');
    charTable.insert('b');
    charTable.insert('z');

    std::cout << "HashTable after insertions:\n";
    charTable.display();

    std::cout << "Searching 'b': " << (charTable.search('b') ? "Found" : "Not Found") << std::endl;
    std::cout << "Removing 'b'...\n";
    charTable.remove('b');
    std::cout << "Searching 'b': " << (charTable.search('b') ? "Found" : "Not Found") << std::endl;
    charTable.display();
    std::cout << std::endl;
}

void teststringHashTable() 
{
    HashTable<std::string> strTable(10);
    std::cout << "\nTesting HashTable<std::string>...\n";

    strTable.insert("apple");
    strTable.insert("apple");
    strTable.insert("apple");
    strTable.insert("banana");
    strTable.insert("banana");
    strTable.insert("cherry");

    std::cout << "HashTable after insertions:\n";
    strTable.display();

    std::cout << "Searching 'banana': " << (strTable.search("banana") ? "Found" : "Not Found") << std::endl;
    std::cout << "Removing 'banana'...\n";
    strTable.remove("banana");
    std::cout << "Searching 'banana': " << (strTable.search("banana") ? "Found" : "Not Found") << std::endl;
    strTable.display();
    std::cout << std::endl;
}

int main() 
{
    testIntHashTable();
    testCharHashTable();
    teststringHashTable();

    return 0;
}
