#ifndef ERROR_CORRECTION_DECODER_H
#define ERROR_CORRECTION_DECODER_H

#include <FEC/Modules/Module.h>

namespace FEC {
    class Decoder : public Module {
    public:
        Decoder() : Module() {};
    };
}

#endif //ERROR_CORRECTION_DECODER_H
