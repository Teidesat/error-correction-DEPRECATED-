//
// Created by jsier on 18/09/2020.
//

#include <string>
#include "common.h"

std::string binToStr(uint32_t bin, uint8_t size) {
    std::string txt;
    for (unsigned int i = size - 1; i < size; --i) {
        txt += (1U << i) & bin ? "1" : "0";
    }
    return txt;
}

uint32_t hammingDist(uint32_t a, uint32_t b) {
    return COUNT1S(a ^ b);
}