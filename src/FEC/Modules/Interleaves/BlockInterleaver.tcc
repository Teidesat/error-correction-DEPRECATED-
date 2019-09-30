#include "BlockInterleaver.h"

namespace FEC {
    template <size_t N>
    void BlockInterleaver<N>::on_new_data_block(const DataBlock<N> &data_block, DataBlock<N> &output) {
        size_t columns = (this->get_parameters().count("columns") == 0 ? data_block.size() / 2 : (size_t) this->get_parameters().at("columns"));
        if (columns == 0) columns = 1;
        size_t rows = (data_block.size() % columns != 0 ? (data_block.size() / columns) + 1 : data_block.size() / columns);

        if (data_block.size() <= columns) {
            columns = data_block.size();
            rows = 1;
        }

        size_t k = 0;
        for (size_t j = 0; j < columns; j++) {
            for (size_t i = 0; i < rows; i++) {
                size_t p = i * columns + j;
                if (p < data_block.size()) {
                    output.set(k++, data_block.at(p));
                }
            }
        }
    }
}