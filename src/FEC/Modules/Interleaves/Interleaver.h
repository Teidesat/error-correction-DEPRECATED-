#ifndef ERROR_CORRECTION_INTERLEAVER_H
#define ERROR_CORRECTION_INTERLEAVER_H

#include <FEC/Modules/Module.h>

namespace FEC {
    template <size_t N>
    class Interleaver : public Module<N> {
    public:
        Interleaver() : Module<N>() {};

        explicit Interleaver(const Parameters &parameters) : Module<N>(parameters) {};
    };
}

#endif //ERROR_CORRECTION_INTERLEAVER_H
