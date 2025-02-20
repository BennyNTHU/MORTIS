#ifndef BLOOMFILTER
#define BLOOMFILTER

#include <iostream>
#include <vector>
#include <bitset>
#include <functional>
#include <string>

const size_t DEFAULT_SIZE = 1000;         // Default size of the Bloom filter bit array
const size_t DEFAULT_HASH_FUNCTIONS = 3;  // Number of hash functions

template <typename T>
class BloomFilter 
{
    private:
        size_t size;
        size_t hashFunctions;
        std::vector<bool> bitArray;
        std::vector<std::function<size_t(const T&)>> hashFunctionsList;

        // The hash functions
        size_t hash1(const T& key) const;
        size_t hash2(const T& key) const;
        size_t hash3(const T& key) const;

    public:
        // Constructors
        BloomFilter(size_t size = DEFAULT_SIZE, size_t hashFunctions = DEFAULT_HASH_FUNCTIONS);

        // Other functions
        void insert(const T& key);
        bool search(const T& key) const;
        void display() const;  // Show the Bloom filter bit array
};

#endif // BLOOMFILTER
