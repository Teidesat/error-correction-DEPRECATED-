//
// Created by jsier on 20/09/2020.
//

#ifndef TSAT_TC_VITERBI_H
#define TSAT_TC_VITERBI_H


#include <cstdint>
#include "../other/CMatrix.h"
#include "Transition.h"

class Viterbi {
    // TODO only keep n paths max
    // TODO soft output
    // TODO We dont need to store all matrix just last col for dists (maybe it's needed for soft outputs?)
public:
    Viterbi(uint32_t n_states, size_t bytes, std::vector<TransitionPair> transitions);
    void decodePair(uint8_t pair);
    std::vector<uint8_t> resolve();
private:
    const std::vector<TransitionPair> transitions;
    CMatrix<unsigned int> dists;
    CMatrix<int> parents;
    size_t n_states;
    size_t col;

    static const unsigned int MAX_DIST = 9999;
};


#endif //TSAT_TC_VITERBI_H
