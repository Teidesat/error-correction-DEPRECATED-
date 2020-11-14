//
// Created by jsier on 20/09/2020.
//

#include <bitset>
#include <cstdlib>
#include <random>
#include <ctime>
#include "gtest/gtest.h"
#include "../../../src/encoder/RSC.h"
#include "../../../src/other/common.h"

// Check that an RSC gives the results calculated manually
TEST(RSCTests, CorrectlyEncoding) {
    const int state_size = 4;
    const int g1 = 0b11001; // 0o31
    const int g2 = 0b10111; // 0o27
    RSC rsc(g1, g2, state_size);
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
    const size_t REPEATS = 5;
    const int state_size = 4;
    const int g1 = 0b11001; // 0o31
    const int g2 = 0b10111; // 0o27

    for (int i = 0; i < REPEATS; ++i) {
        RSC rsc(g1, g2, state_size);
        std::vector<uint8_t> input = randomVector(BYTES);
        std::vector<uint8_t> encoded;
        std::vector<uint8_t> decoded;

        encoded = rsc.encodeMem(input.data(), input.size());
        decoded = rsc.decodeMemViterbi(encoded.data(), encoded.size());
        EXPECT_EQ(decoded, input);
    }
}


