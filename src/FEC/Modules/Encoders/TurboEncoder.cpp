#include "TurboEncoder.h"

#include <cassert>

namespace FEC {
    void TurboEncoder::on_new_data_block(const DataBlock &data_block, DataBlock &output) {
        this->encoders.at(0)->process(data_block, output);

        for (size_t i = 1; i < this->encoders.size(); i++) {
            Interleaver *interleaver = this->interleavers.at(i - 1);
            RSCEncoder *rsc_encoder = this->encoders.at(i);

            DataBlock temp_db1(data_block.size()), temp_db2(data_block.size());
            interleaver->process(data_block, temp_db1);
            rsc_encoder->process(temp_db1, temp_db2);
            temp_db2.remove_first(temp_db2.size() / rsc_encoder->get_outputs());
            output.concatenate(temp_db2);
        }
    }

    void TurboEncoder::validate_config() const {
        assert(this->encoders.size() > 1);
        assert(this->interleavers.size() == this->encoders.size() - 1);
    }
}
