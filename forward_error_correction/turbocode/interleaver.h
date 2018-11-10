#ifndef INTERLEAVER_H
#define INTERLEAVER_H

#include <vector>
#include "utils.h"
#include "block.h"

class interleaver
{
public:
    interleaver(uint32_t cols, uint32_t rows);

    void fill(const Block& input);
    Block read() const;

private:
    uint32_t cols;
    uint32_t rows;

    std::vector<std::vector<Bit>> matrix;
};

#endif // INTERLEAVER_H
