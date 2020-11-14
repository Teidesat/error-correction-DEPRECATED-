//
// Created by jsier on 18/09/2020.
//

#ifndef TSAT_TC_COMMON_H
#define TSAT_TC_COMMON_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#define COUNT1S(byte) ((uint8_t)__builtin_popcount(byte))
#define PARITY(byte) ((uint8_t)(COUNT1S(byte) % 2))

using State = uint32_t;
std::string binToStr(uint32_t bin, uint8_t size = 32);
uint32_t hammingDist(uint32_t a, uint32_t b);
void percentageBar(float current, float max);

std::vector<uint8_t> randomVector(size_t bytes);
std::vector<uint8_t> addNoise(const std::vector<uint8_t>& v, float p);
float ber(const std::vector<uint8_t>& noise, const std::vector<uint8_t>& original);

template <class... Ts>
std::string format(const char* str, Ts const&... rest) {
    std::string s(str);
    return std::move(__format(s, 0, rest...));
}

template <class T, class... Ts>
std::string& __format(std::string& str, uint32_t begin, T const& first, Ts const&... rest) {
    int index = -1;
    int var_size = -1;

    if (str.size() < 2) {
        return str;
    }
    for (uint32_t i = begin; i < str.size() - 1; ++i) {
        if ((i == 0 || str[i - 1] != '\\') &&
            str[i + 0] == '{' &&
            str[i + 1] == '}') {
            index = i;
            var_size = 2;
            break;
        }
    }
    if (index != -1) {
        std::stringstream ss;
        ss << first;
        str.erase(index, var_size);
        str.insert(index, ss.str());
        var_size = ss.str().size();
    }
    if constexpr (sizeof...(rest) > 0) {
        return __format(str, index + var_size, rest...);
    }
    return str;
}

#endif //TSAT_TC_COMMON_H
