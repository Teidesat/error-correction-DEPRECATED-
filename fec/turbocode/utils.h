#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <vector>

#define XOR ^
using Bit = uint8_t;
using Byte = uint8_t;

template<class T>
using Row = std::vector<T>;

template<class T>
using Matrix = std::vector<std::vector<T>>;

template<class T>
inline Bit parity(T value) {
    Bit result = 0;
    while (value) {
        result ^= value & 1;
        value >>= 1;
    }
    return result;
}

inline int hdistance(Bit* a, Bit* b, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i])
            count++;
    }
    return count;
}

#endif // UTILS_H
