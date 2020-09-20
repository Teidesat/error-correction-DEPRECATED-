//
// Created by jsier on 20/09/2020.
//

#include <utility>
#include <vector>
#include "Viterbi.h"

Viterbi::Viterbi(uint32_t n_states, size_t bytes, std::vector<TransitionPair> transitions)
    : transitions(std::move(transitions))
    , dists(n_states, bytes * 4 + 1, Viterbi::MAX_DIST)
    , parents(n_states, bytes * 4 + 1, -1)
    , n_states(n_states)
    , col(0)
{
    dists[0][0] = 0;
}

void Viterbi::decodePair(uint8_t pair) {
    for (size_t state = 0; state < n_states; ++state) {
        unsigned int dist = dists[state][col];
        if (dist >= 0) {
            for (const auto& t : transitions[state]) {
                unsigned int hamming = hammingDist(t.out, pair) + dist;
                if (dists[t.to][col + 1] > hamming) {
                    dists[t.to][col + 1] = hamming;
                    parents[t.to][col + 1] = t.from;
                }
            }
        }
    }
    col++;
}

std::vector<uint8_t> Viterbi::resolve() {
    size_t current = 0;
    size_t col_max = col;
    std::vector<uint8_t> out(col_max / 8);

    // Find lowest hamming dist in output
    for (size_t state = 0; state < n_states; ++state) {
        if (dists[state][col_max] < dists[current][col_max]) {
            current = state;
        }
    }

    // Backtrack path
    for (size_t i = 0; i < col_max; ++i) {
        auto prev = parents[current][col_max - i];
        auto bit = transitions[prev][0].to == current ? 0U : 1U;
        auto pos = i % 8U;
        auto index = col_max / 8 - i / 8 - 1;
        out[index] = (out[index] & ~(1UL << pos)) | (bit << pos);
        current = prev;
    }

    return std::move(out);
}
