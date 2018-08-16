#include "decoderscheme.h"

DecoderScheme::DecoderScheme(int k, int encoderOutputs, int encoderInputs)
    : k(k)
    , encoderOutputs(encoderOutputs)
    , encoderInputs(encoderInputs)
    , scheme()
{
    assert(k >= 2 && k <= 31); // Minimum k for the encoder is 2
    scheme.reserve(pow2(k));

    for (uint32_t i = 0; i < pow2(k); ++i) {
        Node node;
        Bit inAdder[2] = {0};

        inAdder[HIGH] = parity(i) XOR HIGH;
        inAdder[LOW ] = parity(i) XOR LOW;
        node.oneLink .dst = (i >> 1) | (static_cast<uint32_t>(inAdder[HIGH]) << (k - 1));
        node.zeroLink.dst = (i >> 1) | (static_cast<uint32_t>(inAdder[LOW ]) << (k - 1));
        node.oneLink .outputs = std::vector<Bit>({1, static_cast<Bit>(inAdder[1] XOR (i & 0x1))});
        node.zeroLink.outputs = std::vector<Bit>({0, static_cast<Bit>(inAdder[0] XOR (i & 0x1))});
        scheme.push_back(node);
    }

    for (uint32_t i = 0; i < pow2(k); ++i) {
        std::cout << std::bitset<2>(i) << " 1/" << std::bitset<1>(scheme[i].oneLink.outputs[0]) << std::bitset<1>(scheme[i].oneLink.outputs[1]) << " => " << scheme[i].oneLink.dst << std::endl;
        std::cout << std::bitset<2>(i) << " 0/" << std::bitset<1>(scheme[i].zeroLink.outputs[0]) << std::bitset<1>(scheme[i].zeroLink.outputs[1]) << " => " << scheme[i].zeroLink.dst << std::endl;
        std::cout << std::endl;
    }
}

const Block& DecoderScheme::getOutputs(uint32_t row, Bit link)
{
    return (link == HIGH)
           ? scheme[row].oneLink .outputs
           : scheme[row].zeroLink.outputs;
}

uint32_t DecoderScheme::getDst(uint32_t row, Bit link)
{
    return (link == HIGH)
           ? scheme[row].oneLink .dst
           : scheme[row].zeroLink.dst;
}
