#ifndef ERROR_CORRECTION_BLOCKINTERLEAVER_H
#define ERROR_CORRECTION_BLOCKINTERLEAVER_H

#include <FEC/Modules/Interleaves/Interleaver.h>

namespace FEC {
    template <size_t N>
    class BlockInterleaver : public Interleaver<N> {
    public:
        BlockInterleaver() : Interleaver<N>() {};

        explicit BlockInterleaver(const Parameters &parameters) : Interleaver<N>(parameters) {};

    private:
        void on_new_data_block(const DataBlock<N> &data_block, DataBlock<N> &output) override;
    };
}

#include "BlockInterleaver.tcc"

#endif //ERROR_CORRECTION_BLOCKINTERLEAVER_H
