#include "rscdecoder.h"

RSCDecoder::RSCDecoder(int k)
    : k(k)
    , scheme(0x1ULL << k) // 2^k rows
{
    assert(k >= 2);

    for (uint64_t i = 0; i < (0x1ULL << k); ++i) {
        Bit inAdder[2] = {0};

        inAdder[1] = parity(i) XOR 1;
        inAdder[0] = parity(i) XOR 0;
        scheme[i].oneLink .dst = (i >> 1) | (static_cast<uint64_t>(inAdder[1]) << (k - 1));
        scheme[i].zeroLink.dst = (i >> 1) | (static_cast<uint64_t>(inAdder[0]) << (k - 1));
        scheme[i].oneLink .outputs[0] = 1;
        scheme[i].zeroLink.outputs[0] = 0;
        scheme[i].oneLink .outputs[1] = inAdder[1] XOR static_cast<Bit>(i & 0x1);
        scheme[i].zeroLink.outputs[1] = inAdder[0] XOR static_cast<Bit>(i & 0x1);
    }
}

Block RSCDecoder::decode(const Block &input)
{
    const uint64_t rows = 0x1ULL << k;
    const uint64_t cols = input.size() / RATE;
    Matrix<CostNode> costs(cols, Row<CostNode>(rows, CostNode({ 0, 0, -1 }))); // Build matrix of nodes with rows: 2^k & cols: |Input|/k
    // Sparse matrix may be better ? => Prob no

    Bit chunk[RATE] = {0};

    // COL ZERO
    costs[0][0].cost = 0;

    // COL ONE
    buildChunk(chunk, RATE, 0, input);
    costs[1][scheme[0].oneLink .dst].decoded = 1;
    costs[1][scheme[0].zeroLink.dst].decoded = 0;
    costs[1][scheme[0].oneLink .dst].parent = 0;
    costs[1][scheme[0].zeroLink.dst].parent = 0;
    costs[1][scheme[0].oneLink .dst].cost = hdistance(chunk, scheme[0].oneLink.outputs, RATE);
    costs[1][scheme[0].zeroLink.dst].cost = hdistance(chunk, scheme[0].zeroLink.outputs, RATE);

    // OTHER COLS
    for (uint64_t col = 1; col < (cols - 1); ++col) { // Last col makes no operations
        buildChunk(chunk, RATE, col * RATE, input);
        for (uint64_t row = 0; row < rows; ++row) {
            CostNode& node = costs[col][row];
            if (node.cost != -1) {
                CostNode& oneNode  = costs[col + 1][scheme[row].oneLink.dst];
                CostNode& zeroNode = costs[col + 1][scheme[row].zeroLink.dst];
                int oneCost  = node.cost + hdistance(chunk, scheme[row].oneLink.outputs, RATE);
                int zeroCost = node.cost + hdistance(chunk, scheme[row].zeroLink.outputs, RATE);
                if (oneNode.cost < 0 || oneNode.cost > oneCost) {
                    oneNode.decoded = 1;
                    oneNode.parent = row;
                    oneNode.cost = oneCost;
                }
                if (zeroNode.cost < 0 || zeroNode.cost > zeroCost) {
                    zeroNode.decoded = 0;
                    zeroNode.parent = row;
                    zeroNode.cost = zeroCost;
                }
            }
        }
    }

    for (uint64_t row = 0; row < rows; ++row) {
        for (uint64_t col = 0; col < cols; ++col) {
            if (costs[col][row].cost >= 0) {
                std::cout << costs[col][row].parent << " " << costs[col][row].cost << "  ";
            } else {
                std::cout << costs[col][row].parent << " -  ";
            }
        }
        std::cout << std::endl;
    }

    return backtrack(costs);
}

void RSCDecoder::buildChunk(Bit* chunk, int size, uint64_t start, const Block &input) const
{
    assert((start + size) <= input.size());

    for (int i = 0; i < size; ++i) {
        chunk[i] = input[start + i] ? 1 : 0;
    }
}

Block RSCDecoder::backtrack(Matrix<RSCDecoder::CostNode> &costs) const
{
    Block result(costs.size());
    CostNode* currentNode = &costs.back().front();

    // LAST COL
    for (uint64_t row = 1; row < costs.back().size(); ++row) {
        if (currentNode->cost > costs.back()[row].cost) {
            currentNode = &costs.back()[row];
        }
    }

    for (uint64_t col = 0; col < costs.size(); ++col) {
        currentNode = &costs[costs.size() - col - 1][currentNode->parent];
        std::cout << std::bitset<1>(currentNode->decoded) << std::endl; // -1 porque el primero es un decode de un nodo sin hijo, ergo, el decode no tiene significado
        result[costs.size() - 1 - col] = currentNode->decoded;
    }

    // FIRST COL


    return result;
}
