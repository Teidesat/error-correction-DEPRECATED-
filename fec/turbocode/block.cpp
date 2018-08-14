#include "block.h"

Block::Block(const std::vector<Bit> &other)
    : std::vector<Bit>(other)
{}

Block::Block(uint64_t size)
    : std::vector<Bit>(size, 0)
{}
