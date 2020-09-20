//
// Created by jsier on 20/09/2020.
//

#include <bitset>
#include "gtest/gtest.h"
#include "../src/encoder/RSC.h"
#include <random>

// Check that an RSC gives the results calculated manually
TEST(RSCTests, CorrectlyEncoding) {
    RSC rsc(031, 027);
    std::vector<uint8_t> input = {0b10010100, 0b11111010};
    auto out = rsc.encodeMem(input.data(), input.size());
    EXPECT_EQ(out[0], 0b11010010);
    EXPECT_EQ(out[1], 0b00110000);
    EXPECT_EQ(out[2], 0b10111110);
    EXPECT_EQ(out[3], 0b10001101);
}

// Check that Viterbi decoding works
TEST(RSCTests, CorrectlyDecodingViterbi) {
    const size_t BYTES = 1024;

    RSC rsc(031, 027);
    std::vector<uint8_t> input(BYTES);
    std::vector<uint8_t> encoded;
    std::vector<uint8_t> decoded;

    for (int i = 0; i < BYTES; ++i) {
        input[i] = i + 1;
    }

    encoded = rsc.encodeMem(input.data(), input.size());
    decoded = rsc.decodeMemViterbi(encoded.data(), encoded.size());
    EXPECT_EQ(decoded, input);
}


