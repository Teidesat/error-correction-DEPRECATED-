#include "Source.h"

namespace FEC {
    bool Source::read(size_t data_blocks) {
        bool end_reached = false;
        for (size_t i = 0; i < data_blocks && !end_reached; i++) {
            DataBlock data_block(this->data_block_size);
            end_reached = this->read_data_block(data_block);
            if (!end_reached) send_data_block(data_block);
        }
        return !end_reached;
    }

    void Source::read_all() {
        bool end_reached = false;
        while (!end_reached) {
            DataBlock data_block(this->data_block_size);
            end_reached = this->read_data_block(data_block);
            if (!end_reached) send_data_block(data_block);
        }
    }

    void Source::send_data_block(DataBlock &data_block) {
        auto db = std::make_shared<DataBlock>(data_block);
        this->get_pipe().send_data(db);
    }
}
