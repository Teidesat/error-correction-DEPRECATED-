#ifndef RSCENCODER_H
#define RSCENCODER_H

#include <vector>
#include <iostream>
#include <bitset>
#include <cassert>
#include "block.h"
#include "utils.h"

class RSCEncoder
{
public:
    RSCEncoder(uint8_t k, uint32_t g1, uint32_t g2);

    Block encode(const Block& data);

private:
    uint32_t memory;
    uint32_t g1;
    uint32_t g2;
    uint8_t k;
};

#endif // RSCENCODER_H
