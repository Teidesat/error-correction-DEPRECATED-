#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <vector>

#define XOR ^
#define HIGH 1
#define LOW 0
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
        result ^= value & 0x1;
        value >>= 1;
    }
    return result;
}

inline uint32_t pow2(uint8_t  val) { return 0x1UL << val; }
inline uint32_t pow2(uint16_t val) { return 0x1UL << val; }
inline uint32_t pow2(uint32_t val) { return 0x1UL << val; }
inline uint32_t pow2(uint64_t val) { return 0x1UL << val; }
inline uint32_t pow2(int8_t   val) { return 0x1UL << val; }
inline uint32_t pow2(int16_t  val) { return 0x1UL << val; }
inline uint32_t pow2(int32_t  val) { return 0x1UL << val; }
inline uint32_t pow2(int64_t  val) { return 0x1UL << val; }

#endif // UTILS_H
