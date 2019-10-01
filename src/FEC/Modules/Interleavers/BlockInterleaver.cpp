#include "BlockInterleaver.h"

namespace FEC {
    void BlockInterleaver::on_new_data_block(const DataBlock &data_block, DataBlock &output) {
        this->calculate_matrix_size(data_block.size());
        size_t k = 0;
        for (size_t j = 0; j < this->columns; j++) {
            for (size_t i = 0; i < this->rows; i++) {
                size_t p = i * this->columns + j;
                if (p < data_block.size()) output.set(k++, data_block.at(p));
            }
        }
    }

    void BlockInterleaver::calculate_matrix_size(size_t bits_size) {
        this->rows = bits_size / this->columns;
        if (bits_size % this->columns != 0) this->rows += 1;

        if (bits_size <= this->columns) {
            this->columns = bits_size;
            this->rows = 1;
        }
    }
}