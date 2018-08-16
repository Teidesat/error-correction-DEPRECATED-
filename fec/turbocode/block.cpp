#include "block.h"

Block::Block(const std::vector<Bit> &other)
    : std::vector<Bit>(other)
{}

Block::Block(uint32_t size)
    : std::vector<Bit>(size, 0)
{}

void Block::addNoise(double bitSwapRate)
{
    for (Bit& bit : *this) {
        if ((std::rand() / double(RAND_MAX)) < bitSwapRate)
            bit = ~bit;
    }
}
