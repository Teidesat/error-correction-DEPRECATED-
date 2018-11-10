#ifndef DECODERCOSTMATRIX_H
#define DECODERCOSTMATRIX_H

#include <iostream>
#include <cassert>
#include "block.h"
#include "utils.h"

class DecoderCostMatrix
{
private:

    struct Node {
        bool enabled    = false;
        Bit value       = 0;
        uint32_t parent = 0;
        int cost        = 0;
    };

    using Row = std::vector<Node>;
    using Matrix = std::vector<Row>;

    uint32_t rows;
    uint32_t cols;
    Matrix matrix;

public:
    DecoderCostMatrix(int memorySize, int inputSize, int encoderOutputs);

    uint32_t getRows() const;
    uint32_t getCols() const;

    int      getCost(uint32_t row, uint32_t col) const;
    uint32_t getParent(uint32_t row, uint32_t col) const;
    Bit      getValue(uint32_t row, uint32_t col) const;

    bool isEnabled(uint32_t row, uint32_t col) const;
    void setNode(uint32_t row, uint32_t col, Bit value = 0, uint32_t parent = 0, int addedCost = 0);
    void trySetNode(uint32_t row, uint32_t col, Bit value = 0, uint32_t parent = 0, int addedCost = 0);
    Block backtrack() const;

private:
    const Node* minCost(uint32_t col) const;
};

#endif // DECODERCOSTMATRIX_H
