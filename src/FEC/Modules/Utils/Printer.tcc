#include "Printer.h"

#include <iostream>

namespace FEC {
    template <size_t N>
    void Printer<N>::on_new_data_block(const DataBlock<N> &data_block, DataBlock<N> &output) {
        output = data_block;
        std::cout << data_block << std::endl;
    }
}
