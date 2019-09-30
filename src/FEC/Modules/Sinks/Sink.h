#ifndef ERROR_CORRECTION_SINK_H
#define ERROR_CORRECTION_SINK_H

#include <FEC/Modules/Module.h>

namespace FEC {
    template <size_t N>
    class Sink : public Module<N> {
    public:
        Sink() : Module<N>() {};

        explicit Sink(const Parameters &parameters) : Module<N>(parameters) {};
    };
}

#endif //ERROR_CORRECTION_SINK_H
