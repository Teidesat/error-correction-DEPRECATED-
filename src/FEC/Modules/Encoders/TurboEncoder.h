#ifndef ERROR_CORRECTION_TURBOENCODER_H
#define ERROR_CORRECTION_TURBOENCODER_H

#include <FEC/Modules/Interleavers/Interleaver.h>

#include <utility>
#include "RSCEncoder.h"

namespace FEC {

    using Encoders = std::vector<RSCEncoder *>;
    using Interleavers = std::vector<Interleaver *>;

    class TurboEncoder : public Encoder {
    public:
        explicit TurboEncoder(Encoders encoders, Interleavers interleavers)
                : Encoder(), encoders(std::move(encoders)), interleavers(std::move(interleavers)) {
            validate_config();
        };

    private:
        Encoders encoders;
        Interleavers interleavers;

        void on_new_data_block(const DataBlock &data_block, DataBlock &output) override;

        void validate_config() const;
    };
}


#endif //ERROR_CORRECTION_TURBOENCODER_H
