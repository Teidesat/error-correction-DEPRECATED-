#ifndef ERROR_CORRECTION_DECODER_H
#define ERROR_CORRECTION_DECODER_H

#include <FEC/Modules/Module.h>

namespace FEC {
    template<size_t N, size_t K>
    class Decoder : public Module<N, K> {
    public:
        Decoder() : Module<N, K>() {};

        explicit Decoder(const Parameters &parameters) : Module<N, K>(parameters) {};
    };
}

#endif //ERROR_CORRECTION_DECODER_H
