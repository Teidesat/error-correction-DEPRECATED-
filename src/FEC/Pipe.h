#ifndef ERROR_CORRECTION_PIPE_H
#define ERROR_CORRECTION_PIPE_H

#include "DataBlock.h"

#include <memory>

namespace FEC {
    class Module;

    /**
     * Abstract construction to connect two modules, allowing one module to send data blocks to other module.
     */
    class Pipe {
    public:
        explicit Pipe() : output(nullptr) {};

        void set_output(Module &new_output);

        void send_data(std::shared_ptr<DataBlock> data_block);

    private:
        Module *output;
    };
}

#endif //ERROR_CORRECTION_PIPE_H
