#include "RSCEncoder.h"

#include <cassert>

namespace FEC {
    void RSCEncoder::on_new_data_block(const DataBlock &data_block, DataBlock &output) {
        output.resize(data_block.size() * this->get_outputs());

        // Registers initialization
        this->initialize_registers();

        // Systematic output g[1,0,0,...,0]
        for (size_t i = 0; i < data_block.size(); i++) {
            output.set(i, data_block.at(i));
        }

        for (size_t i = 0; i < data_block.size(); i++) {
            // Feedback input using first generator
            bool feedback_input = this->calculate_output(data_block.at(i), 0);

            // Process generators
            for (size_t g = 1; g < generators.size(); g++) {
                bool out = this->calculate_output(feedback_input, g);
                output.set(data_block.size() * g + i, out);
            }

            // Shift registers
            this->shift_registers(feedback_input);
        }
    }

    float RSCEncoder::get_code_rate() const {
        return 1.0f / this->get_outputs();
    }

    size_t RSCEncoder::get_outputs() const {
        return this->generators.size();
    }

    size_t RSCEncoder::get_registers() const {
        return this->constraint_length - 1;
    }

    void RSCEncoder::validate_config() const {
        assert(this->constraint_length >= 1);
        for (const auto &generator : generators) {
            assert(generator.size() == this->constraint_length);
        }
    }

    void RSCEncoder::initialize_registers() {
        for (size_t i = 0; i < this->get_registers(); i++) {
            this->registers.at(i) = 0;
        }
    }

    bool RSCEncoder::calculate_output(size_t input, size_t generator) const {
        bool output = 0;
        for (size_t m = 0; m < this->constraint_length; m++) {
            if (this->generators.at(generator).at(m) == 1) {
                if (m == 0) {
                    output = input;
                } else {
                    output = output xor registers.at(m - 1);
                }
            }
        }
        return output;
    }

    void RSCEncoder::shift_registers(bool input) {
        for (size_t r = registers.size() - 1; r > 0; r--) {
            registers.at(r) = registers.at(r - 1);
        }
        registers.at(0) = input;
    }
}