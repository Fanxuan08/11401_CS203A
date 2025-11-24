/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    if (m <= 0) return -1; // invalid table size
    return key % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    
    if (m <= 0) return -1; // invalid table size
    if (str == NULL) return -1; // null pointer check 

    // Simple string hashing: sum ASCII values
    for (int i = 0; str[i] != '\0'; i++) {
        hash += (unsigned long)str[i];
    }

    return (int)(hash % m); // basic division method
}
