#ifndef ERROR_CORRECTION_ENCODER_H
#define ERROR_CORRECTION_ENCODER_H

#include <FEC/Modules/Module.h>

namespace FEC {
    template<size_t N, size_t K>
    class Encoder : public Module<N, K> {
    public:
        Encoder() : Module<N, K>() {};

        explicit Encoder(const Parameters &parameters) : Module<N, K>(parameters) {};
    };
}

#endif //ERROR_CORRECTION_ENCODER_H
