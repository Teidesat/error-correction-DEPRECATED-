//
// Created by jsier on 18/09/2020.
//

#include <string>
#include <vector>
#include <random>
#include <cassert>
#include <bitset>
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

std::vector<uint8_t> randomVector(size_t bytes) {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 255);
    std::vector<uint8_t> v(bytes);

    for (int j = 0; j < bytes; ++j) {
        v[j] = uniform_dist(e1);
    }

    return v;
}

std::vector<uint8_t>addNoise(const std::vector<uint8_t>& v, float p) {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_real_distribution<float> uniform_real_dist(0.0f, 1.0f);
    std::uniform_int_distribution<int> uniform_byte_dist(0, 255);
    std::vector<uint8_t> n(v);

    for (auto& byte : n) {
        uint8_t noise = uniform_byte_dist(e1);
        if (uniform_real_dist(e1) < p) byte = (byte & 128U) | (noise & 128U);
        if (uniform_real_dist(e1) < p) byte = (byte &  64U) | (noise &  64U);
        if (uniform_real_dist(e1) < p) byte = (byte &  32U) | (noise &  32U);
        if (uniform_real_dist(e1) < p) byte = (byte &  16U) | (noise &  16U);
        if (uniform_real_dist(e1) < p) byte = (byte &   8U) | (noise &   8U);
        if (uniform_real_dist(e1) < p) byte = (byte &   4U) | (noise &   4U);
        if (uniform_real_dist(e1) < p) byte = (byte &   2U) | (noise &   2U);
        if (uniform_real_dist(e1) < p) byte = (byte &   1U) | (noise &   1U);
    }
    return n;
}

float ber(const std::vector<uint8_t>& noise, const std::vector<uint8_t>& original) {
    assert(noise.size() == original.size());
    int errors = 0;
    for (size_t i = 0; i < noise.size(); ++i) {
        #pragma unroll
        for (unsigned int j = 0; j < 8; ++j) {
            if ((noise[i] & (1U << j)) != (original[i] & (1U << j))) {
                errors++;
            }
        }
    }
    return (float)errors / (noise.size() * 8.0f);
}

void percentageBar(float current, float max) {
    float percentage = current / max;
    std::cout << format("({}%)", int(percentage * 100.0)) << std::endl;
}