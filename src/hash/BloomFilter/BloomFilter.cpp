#include "BloomFilter.hpp"

// Constructor
template <typename T>
BloomFilter<T>::BloomFilter(size_t size, size_t hashFunctions): size(size), hashFunctions(hashFunctions), bitArray(size, false) 
{
    // Initialize hash functions
    hashFunctionsList.push_back([this](const T& key) 
    {
        return hash1(key); 
    });
    hashFunctionsList.push_back([this](const T& key) 
    {
        return hash2(key); 
    });
    hashFunctionsList.push_back([this](const T& key) 
    { 
        return hash3(key); 
    });
}

// Insert element into Bloom filter
template <typename T>
void BloomFilter<T>::insert(const T& key) 
{
    for (const auto& hashFunction : hashFunctionsList) 
    {
        size_t index = hashFunction(key) % size;
        bitArray[index] = true;
    }
}

// Search for an element in the Bloom filter
template <typename T>
bool BloomFilter<T>::search(const T& key) const 
{
    for (const auto& hashFunction : hashFunctionsList) 
    {
        size_t index = hashFunction(key) % size;
        if (!bitArray[index]) 
        {
            return false; // If any hash function returns a false bit, the key is not in the set
        }
    }

    return true; // Could be a false positive
}

// Display the bit array
template <typename T>
void BloomFilter<T>::display() const 
{
    for (bool bit : bitArray) 
    {
        std::cout << bit;
    }
    std::cout << std::endl;
}

// Hash function 1
template <typename T>
size_t BloomFilter<T>::hash1(const T& key) const 
{
    return std::hash<T>{}(key);
}

// Hash function 2
template <typename T>
size_t BloomFilter<T>::hash2(const T& key) const 
{
    return std::hash<T>{}(key) * 2654435761 % size;  // Knuth's Multiplicative Hash
}

// Hash function 3
template <typename T>
size_t BloomFilter<T>::hash3(const T& key) const 
{
    return (std::hash<T>{}(key) * 97 + 13) % size;  // Simple polynomial hash
}

// Explicit template instantiations
template class BloomFilter<int>;
template class BloomFilter<char>;
template class BloomFilter<std::string>;
