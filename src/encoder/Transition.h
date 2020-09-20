//
// Created by jsier on 20/09/2020.
//

#ifndef TSAT_TC_TRANSITION_H
#define TSAT_TC_TRANSITION_H

#include <vector>
#include "../other/common.h"

struct Transition {
    State from;
    State to;
    uint8_t in;
    uint8_t out;
};

class TransitionPair : public std::vector<Transition> {
public:
    TransitionPair(State from, State to_low, State to_high, uint8_t out_low, uint8_t out_high)
        : std::vector<Transition>({{from, to_low, 0, out_low},
                                   {from, to_high, 1, out_high}})
    {}
    const Transition& operator[](uint8_t bit) const {
        return bit
            ? std::vector<Transition>::operator[](1)
            : std::vector<Transition>::operator[](0);
    }
};


#endif //TSAT_TC_TRANSITION_H
