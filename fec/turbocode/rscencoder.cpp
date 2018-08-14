#include "rscencoder.h"

RSCEncoder::RSCEncoder(int k)
    : bitRegs(0)
    , k(k)
{}

Block RSCEncoder::encode(const Block &data)
{
    Block encoded;
    encoded.reserve(data.size() * 2);
    for (auto input : data) {
        encoded.push_back(input);
        Bit inputAdder = input XOR parity(bitRegs);
        encoded.push_back(inputAdder XOR (bitRegs & 0x1));
        shift(inputAdder);
    }
    return encoded;
}

void RSCEncoder::shift(Bit input)
{
    bitRegs = (bitRegs >> 1) | (uint64_t(input) << (k - 1));
}
