// Main program calling hash functions

#include <iostream>
#include <vector>
#include "hash_fn.hpp"

int main() {
    int tableSize = 10; // 你可以改成 17, 20, 100 等測試不同分布

    // 測試整數 hash
    std::vector<int> intKeys = {1, 12, 23, 34, 45};
    std::cout << "Integer hash results:\n";
    for (int key : intKeys) {
        std::cout << "key " << key << " -> index " << hashInt(key, tableSize) << "\n";
    }

    // 測試字串 hash
    std::vector<std::string> strKeys = {"apple", "banana", "cherry"};
    std::cout << "\nString hash results:\n";
    for (const auto &key : strKeys) {
        std::cout << "key " << key << " -> index " << hashString(key, tableSize) << "\n";
    }

    return 0;
}