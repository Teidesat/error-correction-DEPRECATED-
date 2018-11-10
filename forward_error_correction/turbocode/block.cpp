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
            bit = (~bit & 0x1);
    }
}

void Block::addEraserNoise(double eraseRate)
{
    for (Bit& bit : *this) {
        if ((std::rand() / double(RAND_MAX)) < eraseRate)
            bit = 0;
    }
}

bool Block::operator==(const Block &other) const
{
    if (other.size() != size())
        return false;

    for (uint32_t i = 0; i < size(); ++i) {
        if (at(i) != other[i])
            return false;
    }
    return true;
}

int Block::diffs(const Block &other) const
{
    if (other.size() != size())
        return -1;

    int count = 0;
    for (uint32_t i = 0; i < size(); ++i) {
        if (at(i) != other[i])
            count++;
    }
    return count;
}
