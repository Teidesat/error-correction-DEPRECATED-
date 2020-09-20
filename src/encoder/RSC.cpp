//
// Created by jsier on 08/08/2020.
//

#include <cassert>
#include "../other/common.h"
#include "RSC.h"
#include "../other/CMatrix.h"
#include "Viterbi.h"


RSC::RSC(uint32_t g1, uint32_t g2, uint32_t state_size)
    : g1(g1)
    , g2(g2)
    , state_size(state_size)
    , state(0)
    , n_states(1U << state_size)
{}

void RSC::clear() {
    state = 0;
}

uint8_t RSC::encodeBit(State &any_state, uint8_t bit) const {
    uint8_t sum = bit ^ PARITY(g1 & any_state);
    any_state |= sum << state_size;
    uint8_t par = PARITY(g2 & any_state);
    any_state >>= 1U;
    return par;
}

std::vector<uint8_t> RSC::encodeMem(const uint8_t *data, size_t bytes) {
    auto out = std::vector<uint8_t>(bytes * 2, 0);

    for (size_t i = 0; i < bytes; ++i) {
        #pragma unroll
        for (uint8_t b = 7; b < 8; --b) { // Bits from MSB to LSB
            uint8_t bit = (data[i] >> b) & 1U;
            uint8_t par = encodeBit(state, bit);
            out[i * 2 + 1 - b / 4] |= bit << (b * 2U % 8U + 1);
            out[i * 2 + 1 - b / 4] |= par << (b * 2U % 8U);
        }
    }
    return std::move(out);
}

std::vector<uint8_t> RSC::decodeMemViterbi(const uint8_t *data, size_t bytes) {
    assert(bytes % 2 == 0);

    Viterbi v(n_states, bytes, getTransitions());
    for (size_t b = 0; b < bytes; ++b) {
        v.decodePair((data[b] >> 6U) & 0b11U);
        v.decodePair((data[b] >> 4U) & 0b11U);
        v.decodePair((data[b] >> 2U) & 0b11U);
        v.decodePair((data[b] >> 0U) & 0b11U);
    }
    return v.resolve();
}

std::vector<TransitionPair> RSC::getTransitions() const {
    std::vector<TransitionPair> transitions;

    transitions.reserve(n_states);
    for (State s = 0; s < n_states; ++s) {
        auto state_low = s;
        auto state_high = s;
        auto output_low = encodeBit(state_low, 0); // No need to append input if its 0
        auto output_high = encodeBit(state_high, 1) | 0x2U; // Append the input

        transitions.emplace_back(s, state_low, state_high, output_low, 0x2U | output_high);
    }

    return transitions;
}

std::string RSC::graphvizStr() const {
    auto transitions = getTransitions();
    State offset = n_states; // Offset for the name of the destination state os graphviz adds two nodes
    std::string str;

    str += "digraph G {\n";
    for (State s = 0; s < n_states; ++s) {
        str += format("    {} [label=\"{}\" pos=\"0,{}!\"]\n", s, binToStr(s, state_size), s * 0.8);
        str += format("    {} [label=\"{}\" pos=\"6,{}!\"]\n", s + offset, binToStr(s + offset, state_size), s * 0.8);
    }
    for (const auto& pair : transitions) {
        for (const auto& t : pair) {
            str += format("    {}->{}", t.from, t.to + offset);
            str += format(" [label=\"{}/{}\"{}]\n", (int) t.in, binToStr(t.out, 2), t.in ? "" : " style=\"dotted\"");
        }
    }
    str += "}\n";
    return str;
}

std::string RSC::transitionsStr() const {
    auto transitions = getTransitions();
    std::string str;

    for (const auto& pair : transitions) {
        for (const auto& t : pair) {
            str += format("{}---{}/{}-->{}\n", t.from, (int)t.in, binToStr(t.out, 2), t.to);
        }
    }
    return str;
}
