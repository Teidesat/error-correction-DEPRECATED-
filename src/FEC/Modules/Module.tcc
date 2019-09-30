#include "Module.h"

namespace FEC {

    template<size_t N, size_t K>
    Pipe<K> &Module<N, K>::get_pipe() {
        return this->pipe;
    }

    template<size_t N, size_t K>
    Parameters &Module<N, K>::get_parameters() {
        return this->parameters;
    }

    template<size_t N, size_t K>
    void Module<N, K>::process(std::shared_ptr<DataBlock<N>> data_block) {
        auto output = std::make_shared<DataBlock<K>>();
        this->on_new_data_block(*data_block, *output);
        this->get_pipe().send_data(output);
    }
}