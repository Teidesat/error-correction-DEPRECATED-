#include "DataBlock.h"

namespace FEC {
    DataBlock::DataBlock(size_t bits_size) {
        this->bits_size = bits_size;
        this->data_block = std::vector<bool>(bits_size, 0);
    }

    void DataBlock::set() noexcept {
        for (size_t i = 0; i < this->size(); i++) {
            this->set(i, 1);
        }
    }

    void DataBlock::reset() noexcept {
        for (size_t i = 0; i < this->size(); i++) {
            this->set(i, 0);
        }
    }

    void DataBlock::set(size_t pos, bool value) {
        this->data_block.at(pos) = value;
    }

    size_t DataBlock::size() const {
        return this->bits_size;
    }

    void DataBlock::resize(size_t new_bits_size) {
        this->data_block.resize(new_bits_size);
        this->bits_size = new_bits_size;
    }

    bool DataBlock::at(size_t pos) const {
        return this->data_block.at(pos);
    }

    bool DataBlock::operator[](size_t pos) const {
        return this->data_block[pos];
    }
}