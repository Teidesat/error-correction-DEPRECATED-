#ifndef ERROR_CORRECTION_RANDOMSOURCE_H
#define ERROR_CORRECTION_RANDOMSOURCE_H

#include "Source.h"

namespace FEC {
    template<size_t N>
    class RandomSource : public Source<N> {
    public:
        RandomSource() : Source<N>() {};

        explicit RandomSource(const Parameters &parameters) : Source<N>(parameters) {};

    private:
        bool read_data_block(DataBlock<N> &data_block) override;
    };
}

#include "RandomSource.tcc"

#endif //ERROR_CORRECTION_RANDOMSOURCE_H