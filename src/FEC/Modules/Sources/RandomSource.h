#ifndef ERROR_CORRECTION_RANDOMSOURCE_H
#define ERROR_CORRECTION_RANDOMSOURCE_H

#include "Source.h"

namespace FEC {
    class RandomSource : public Source {
    public:
        explicit RandomSource(size_t data_block_size) : Source(data_block_size) {};

    private:
        bool read_data_block(DataBlock &data_block) override;
    };
}

#endif //ERROR_CORRECTION_RANDOMSOURCE_H