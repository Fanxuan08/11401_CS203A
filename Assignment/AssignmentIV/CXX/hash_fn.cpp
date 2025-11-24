/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {

    if (m <= 0) return -1;// Simple integer hash (mod table size)
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    if (m <= 0) return -1; //Return -1 if table size m is invalid (<=0)

    // Simple string hashing: sum the ASCII values of each character
    for (size_t i = 0; i < str.length(); i++) {
        hash += static_cast<unsigned long>(str[i]);
    }

    return static_cast<int>(hash % m);  // basic division method
}
