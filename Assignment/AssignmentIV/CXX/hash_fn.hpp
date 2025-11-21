// Header file for C++ hash functions

#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>

// 整數 key 的 hash 函式
int hashInt(int key, int m);

// 字串 key 的 hash 函式
int hashString(const std::string &key, int m);

#endif
