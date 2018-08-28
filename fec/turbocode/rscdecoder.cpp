#include "rscdecoder.h"

RSCDecoder::RSCDecoder(int k)
    : k(k)
    , scheme(k, encoderOutputs, encoderInputs)
{}

Block RSCDecoder::decode(const Block &input)
{
    const int encoderOutputs = 2;
    DecoderCostMatrix costs(k, input.size(), encoderOutputs);

    costs.setNode(0, 0); // Always start from the same node. Enable it.

    for (uint32_t col = 0; col < costs.getCols() - 1; ++col) {
        for (uint32_t row = 0; row < costs.getRows(); ++row) {
            if (costs.isEnabled(row, col)) {
                int zeroCost = Block::hdistance(input, scheme.getOutputs(row, LOW ), encoderOutputs, col * encoderOutputs);
                int oneCost  = Block::hdistance(input, scheme.getOutputs(row, HIGH), encoderOutputs, col * encoderOutputs);
                costs.trySetNode(scheme.getDst(row, HIGH), col + 1, HIGH, row, oneCost);
                costs.trySetNode(scheme.getDst(row, LOW ), col + 1, LOW , row, zeroCost);
            }
        }
    }

    for (uint32_t row = 0; row < costs.getRows(); ++row) {
        for (uint32_t col = 0; col < costs.getCols(); ++col) {
            if (costs.isEnabled(row, col)) {
                std::cout << costs.getParent(row, col) << " " << costs.getCost(row, col) << "  ";
            } else {
                std::cout << "-" << " -  ";
            }
        }
        std::cout << std::endl;
    }

    return costs.backtrack();
}
