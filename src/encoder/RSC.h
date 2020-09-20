//
// Created by jsier on 08/08/2020.
//

#ifndef TSAT_TC_RSC_H
#define TSAT_TC_RSC_H

#include <string>
#include <cstdint>
#include <vector>
#include <tuple>
#include "Transition.h"

class RSC {
public:

    RSC(uint32_t g1, uint32_t g2, uint32_t state_size = 4);

    void clear();
    [[nodiscard]] std::vector<uint8_t> encodeMem(const uint8_t* data, size_t bytes);
    [[nodiscard]] std::vector<uint8_t> decodeMemViterbi(const uint8_t* data, size_t bytes);
    [[nodiscard]] std::vector<TransitionPair> getTransitions() const;
    [[nodiscard]] std::string graphvizStr() const;
    [[nodiscard]] std::string transitionsStr() const;

private:
    const uint32_t g1;
    const uint32_t g2;
    const uint32_t state_size;
    State state;
    State n_states;

    [[nodiscard]] uint8_t encodeBit(State &any_state, uint8_t bit) const;
};


#endif //TSAT_TC_RSC_H
