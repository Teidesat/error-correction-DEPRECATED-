#ifndef RSCDECODER_H
#define RSCDECODER_H

#include <vector>
#include <utility>
#include <iostream>
#include <bitset>
#include <cassert>
#include "utils.h"
#include "block.h"

class RSCDecoder
{
public:
    RSCDecoder(int k);
    Block decode(const Block& input);

private:
    static const int RATE = 2;

    struct SchemeLink {
        uint64_t dst;
        Bit outputs[RATE] = {0};
    };
    struct SchemeNode {
        SchemeLink oneLink;
        SchemeLink zeroLink;
    };
    struct CostNode {
        Bit decoded;
        uint64_t parent;
        int cost;
    };

    int k;
    std::vector<SchemeNode> scheme;

    void buildChunk(Bit *chunk, int size, uint64_t start, const Block& input) const;
    Block backtrack(Matrix<CostNode>& costs) const;
};

#endif // RSCDECODER_H
