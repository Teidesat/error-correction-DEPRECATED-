#ifndef RSCENCODER_H
#define RSCENCODER_H

#include <vector>
#include <iostream>
#include <bitset>
#include "block.h"
#include "utils.h"

class RSCEncoder
{
public:
    explicit RSCEncoder(int k);

    Block encode(const Block& data);

private:
    const int RATE = 2;
    uint64_t bitRegs;
    int k;

    inline void shift(Bit input);
};

#endif // RSCENCODER_H
