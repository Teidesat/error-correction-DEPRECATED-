#ifndef ERROR_CORRECTION_BLOCKINTERLEAVER_H
#define ERROR_CORRECTION_BLOCKINTERLEAVER_H

#include <FEC/Modules/Interleaves/Interleaver.h>

namespace FEC {
    class BlockInterleaver : public Interleaver {
    public:
        explicit BlockInterleaver(size_t columns) : Interleaver(), columns(columns) {};

    private:
        size_t columns;
        size_t rows = 1;

        void on_new_data_block(const DataBlock &data_block, DataBlock &output) override;

        void calculate_matrix_size(size_t bits_size);
    };
}

#endif //ERROR_CORRECTION_BLOCKINTERLEAVER_H
