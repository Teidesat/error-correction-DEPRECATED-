#include "Pipe.h"
#include <FEC/Modules/Module.h>

#include <utility>

namespace FEC {

    template <size_t N>
    void Pipe<N>::set_output(Module<N> &new_output) {
        this->output = &new_output;
    }

    template <size_t N>
    void Pipe<N>::send_data(std::shared_ptr<DataBlock<N>> data_block) {
        if (this->output != nullptr) this->output->process(data_block);
    }
}
