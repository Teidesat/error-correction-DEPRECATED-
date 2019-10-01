#include "Module.h"

namespace FEC {
    Pipe &Module::get_pipe() {
        return this->pipe;
    }

    void Module::process(const std::shared_ptr<DataBlock>& data_block) {
        auto output = std::make_shared<DataBlock>((*data_block).size());
        this->on_new_data_block(*data_block, *output);
        this->get_pipe().send_data(output);
    }

    void Module::process(const DataBlock &data_block, DataBlock &output) {
        output.resize(data_block.size());
        this->on_new_data_block(data_block, output);
    }
}