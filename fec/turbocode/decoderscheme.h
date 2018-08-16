#ifndef DECODERSCHEME_H
#define DECODERSCHEME_H

#include <cinttypes>
#include <vector>
#include <cassert>
#include "utils.h"
#include "block.h"

class DecoderScheme
{
public:
    DecoderScheme(int k, int encoderOutputs, int encoderInputs);

    const Block& getOutputs(uint32_t row, Bit link);
    uint32_t getDst(uint32_t row, Bit link);

private:
    struct Link {
        uint32_t dst;
        Block outputs; // |outputs| = Encoder outputs
    };

    struct Node {
        Link oneLink;
        Link zeroLink;
    };

    int k; // r = encoderInputs / encoderOutputs
    int encoderOutputs;
    int encoderInputs;
    std::vector<Node> scheme;
};

#endif // DECODERSCHEME_H
