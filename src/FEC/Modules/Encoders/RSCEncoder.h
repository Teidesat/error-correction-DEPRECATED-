#ifndef ERROR_CORRECTION_RSCENCODER_H
#define ERROR_CORRECTION_RSCENCODER_H

#include <FEC/Modules/Encoders/Encoder.h>

#include <utility>

namespace FEC {

    using Generator = std::vector<bool>;
    using Generators = std::vector<Generator>;

    class RSCEncoder : public Encoder {
    public:
        explicit RSCEncoder(Generators generators, size_t constraint_length) : Encoder(),
                                                                               generators(std::move(generators)),
                                                                               constraint_length(constraint_length),
                                                                               registers(std::vector<bool>(this->get_registers(), 0)) {
            validate_config();
        };

        [[nodiscard]] float get_code_rate() const;

        [[nodiscard]] size_t get_outputs() const;

        [[nodiscard]] size_t get_registers() const;

    private:
        Generators generators;
        size_t constraint_length;
        std::vector<bool> registers;

        void on_new_data_block(const DataBlock &data_block, DataBlock &output) override;

        void validate_config() const;

        void initialize_registers();

        [[nodiscard]] bool calculate_output(size_t input, size_t generator) const;

        void shift_registers(bool input);
    };
}

#endif //ERROR_CORRECTION_RSCENCODER_H
