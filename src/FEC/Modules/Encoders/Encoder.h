#ifndef ERROR_CORRECTION_ENCODER_H
#define ERROR_CORRECTION_ENCODER_H

#include <FEC/Modules/Module.h>

namespace FEC {
    class Encoder : public Module {
    public:
        Encoder() : Module() {};

        [[nodiscard]] virtual float get_code_rate() const = 0;

        [[nodiscard]] virtual size_t get_outputs() const = 0;
    };
}

#endif //ERROR_CORRECTION_ENCODER_H
