#include "interleaver.h"

interleaver::interleaver(uint32_t cols, uint32_t rows)
    : cols(cols)
    , rows(rows)
    , matrix(rows, std::vector<Bit>(cols, 0))
{}

void interleaver::fill(const Block &input)
{
    uint32_t pos = 0;
    for (uint32_t row = 0; row < rows; ++row) {
        for (uint32_t col = 0; col < cols; ++col) {
            matrix[row][col] = input[pos++];
        }
    }
}

Block interleaver::read() const
{
    Block result(rows * cols);
    uint32_t pos = 0;

    for (uint32_t col = 0; col < cols; ++col) {
        for (uint32_t row = 0; row < rows; ++row) {
            result[pos++] = matrix[row][col];
        }
    }
    return result;
}
