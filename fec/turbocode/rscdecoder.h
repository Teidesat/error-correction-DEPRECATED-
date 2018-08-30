#ifndef RSCDECODER_H
#define RSCDECODER_H

#include <vector>
#include <utility>
#include <iostream>
#include <bitset>
#include <cassert>
#include "utils.h"
#include "block.h"
#include "decodercostmatrix.h"
#include "decoderscheme.h"

class RSCDecoder
{
public:
    RSCDecoder(uint8_t k);
    Block decode(const Block& input);

private:
    static const int encoderOutputs = 2;
    static const int encoderInputs = 1;
    uint8_t k;
    uint8_t memorySize;
    DecoderScheme scheme;

    //Block backtrack(Matrix<CostNode>& costs) const;
};

#endif // RSCDECODER_H
