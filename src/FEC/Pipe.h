#ifndef ERROR_CORRECTION_PIPE_H
#define ERROR_CORRECTION_PIPE_H

#include "DataBlock.h"

#include <memory>

namespace FEC {
    template<size_t N, size_t K = N>
    class Module;

    /**
     * Abstract construction to connect two modules, allowing one module to send data blocks to other module.
     */
    template<size_t N>
    class Pipe {
    public:
        explicit Pipe() : output(nullptr) {};

        void set_output(Module<N> &new_output);

        void send_data(std::shared_ptr<DataBlock<N>> data_block);

    private:
        Module<N> *output;
    };
}

#include "Pipe.tcc"

#endif //ERROR_CORRECTION_PIPE_H
