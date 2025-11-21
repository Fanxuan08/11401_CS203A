// Hash function implementation in C++
//test

#include "hash_fn.hpp"

// 簡單整數 hash（對 table size 取餘數）
int hashInt(int key, int m) {
    if (m <= 0) return -1; // 防呆
    return key % m;
}

// 字串 hash（djb2 演算法）
int hashString(const std::string &key, int m) {
    if (m <= 0) return -1; // 防呆

    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % m;
}
