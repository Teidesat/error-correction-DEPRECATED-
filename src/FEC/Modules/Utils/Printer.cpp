#include "Printer.h"

#include <iostream>

namespace FEC {
    void Printer::on_new_data_block(const DataBlock &data_block, DataBlock &output) {
        output = data_block;
        if (this->caption.empty()) {
            std::cout << data_block << std::endl;
        } else {
            std::cout << caption << " " << data_block << std::endl;
        }
    }
}
