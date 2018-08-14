#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <utils.h>

class Block : public std::vector<Bit>
{
public:
    Block(const std::vector<Bit>& other);
    Block(uint64_t size = 0);
};

#endif // BLOCK_H
