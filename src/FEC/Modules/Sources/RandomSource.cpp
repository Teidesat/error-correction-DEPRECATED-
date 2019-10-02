#include "RandomSource.h"

#include <functional>
#include <random>

namespace FEC {
    bool RandomSource::read_data_block(DataBlock &data_block) {
        static auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
        for (size_t i = 0; i < data_block.size(); i++) {
            data_block.set(i, gen());
        }
        return false;
    }
}