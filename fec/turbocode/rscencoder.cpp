#include "rscencoder.h"

RSCEncoder::RSCEncoder(uint8_t k, uint32_t g1, uint32_t g2)
    : memory(0)
    , memorySize(k - 1)
    , g1(g1)
    , g2(g2)
    , k(k)
{
    assert(k >= 2 && k <= 31); // Minimum k for the encoder is 2
}

Block RSCEncoder::encode(const Block &data)
{
    memory = 0;
    Block encoded;
    encoded.reserve(data.size() * 2); // Size x2 if rate 1/2
    uint32_t memoryInput;

    for (Bit input : data) {
        memoryInput = input XOR parity(g1 & memory); // Bit k of memory = 0 because of shift
        memory     |= memoryInput << memorySize;
        /* Xk */ encoded.push_back(input);
        /* Yk */ encoded.push_back(parity(g2 & memory));
        memory >>= 1;
    }
    return encoded;
}
