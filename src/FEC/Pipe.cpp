#include "Pipe.h"
#include <FEC/Modules/Module.h>

namespace FEC {
    void Pipe::set_output(Module &new_output) {
        this->output = &new_output;
    }

    void Pipe::send_data(std::shared_ptr<DataBlock> data_block) {
        if (this->output != nullptr) this->output->process(data_block);
    }
}
