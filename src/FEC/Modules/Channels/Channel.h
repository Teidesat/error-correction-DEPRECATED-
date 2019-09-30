#ifndef ERROR_CORRECTION_CHANNEL_H
#define ERROR_CORRECTION_CHANNEL_H

#include <FEC/Modules/Module.h>

namespace FEC {
    template<size_t N>
    class Channel : public Module<N> {
    public:
        Channel() : Module<N>() {};

        explicit Channel(const Parameters &parameters) : Module<N>(parameters) {};
    };
}

#endif //ERROR_CORRECTION_CHANNEL_H
