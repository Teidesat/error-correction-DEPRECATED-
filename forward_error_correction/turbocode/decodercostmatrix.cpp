#include "decodercostmatrix.h"

DecoderCostMatrix::DecoderCostMatrix(int memorySize, int inputSize, int encoderOutputs)
    : rows(pow2(memorySize))
    , cols(inputSize / encoderOutputs + 1U)
    , matrix(rows, Row(cols))
{}

uint32_t DecoderCostMatrix::getRows() const
{
    return rows;
}

uint32_t DecoderCostMatrix::getCols() const
{
    return cols;
}

int DecoderCostMatrix::getCost(uint32_t row, uint32_t col) const
{
    return matrix[row][col].cost;
}

uint32_t DecoderCostMatrix::getParent(uint32_t row, uint32_t col) const
{
    return matrix[row][col].parent;
}

Bit DecoderCostMatrix::getValue(uint32_t row, uint32_t col) const
{
    return matrix[row][col].value;
}

bool DecoderCostMatrix::isEnabled(uint32_t row, uint32_t col) const
{
    return matrix[row][col].enabled;
}

void DecoderCostMatrix::setNode(uint32_t row, uint32_t col, Bit value, uint32_t parent, int addedCost)
{
    matrix[row][col].enabled = true;
    matrix[row][col].value   = value;
    matrix[row][col].parent  = parent;
    matrix[row][col].cost    = (col == 0) ? addedCost : (matrix[parent][col - 1].cost + addedCost);
}

void DecoderCostMatrix::trySetNode(uint32_t row, uint32_t col, Bit value, uint32_t parent, int addedCost)
{
    assert(col > 0);

    int cost = matrix[parent][col - 1].cost + addedCost;
    if (!matrix[row][col].enabled || (cost < matrix[row][col].cost)) {
        matrix[row][col].enabled = true;
        matrix[row][col].value   = value;
        matrix[row][col].parent  = parent;
        matrix[row][col].cost    = (col == 0) ? addedCost : (matrix[parent][col - 1].cost + addedCost);
    }
}

Block DecoderCostMatrix::backtrack() const
{
    uint32_t max = cols - 1;
    Block result(max);
    const Node* currentNode = minCost(cols - 1);

    result[max - 1] = currentNode->value;
    for (uint32_t col = 1; col < max; ++col) {
        currentNode = &matrix[currentNode->parent][cols - 1 - col];
        result[max - 1 - col] = currentNode->value;
    }
    return result;
}

const DecoderCostMatrix::Node *DecoderCostMatrix::minCost(uint32_t col) const
{
    const Node* best = &matrix[0][col];
    for (uint32_t row = 1; row < rows; ++row) {
        if (matrix[row][col].cost < best->cost) {
            best = &matrix[row][col];
        }
    }
    return best;
}
