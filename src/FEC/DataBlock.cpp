#include "DataBlock.h"

namespace FEC {
    DataBlock::DataBlock(size_t bits_size) {
        this->bits_size = bits_size;
        this->data_block = std::vector<bool>(bits_size, 0);
    }

    DataBlock::DataBlock(std::initializer_list<bool> initializer_list) {
        this->bits_size = initializer_list.size();
        this->data_block = std::vector<bool>(initializer_list);
    }

    void DataBlock::set() noexcept {
        for (size_t i = 0; i < this->size(); i++) {
            this->set(i, 1);
        }
    }

    void DataBlock::remove_first(size_t n_bits) {
        std::vector<bool> new_data_block;
        for (size_t i = n_bits; i < this->size(); i++) {
            new_data_block.push_back(this->at(i));
        }
        this->data_block = new_data_block;
        this->bits_size = new_data_block.size();
    }

    void DataBlock::remove_last(size_t n_bits) {
        this->resize(this->size() - n_bits);
    }

    void DataBlock::reset() noexcept {
        for (size_t i = 0; i < this->size(); i++) {
            this->set(i, 0);
        }
    }

    void DataBlock::set(size_t pos, bool value) {
        this->data_block.at(pos) = value;
    }

    void DataBlock::push_back(bool value) {
        this->data_block.push_back(value);
        this->bits_size++;
    }

    size_t DataBlock::size() const {
        return this->bits_size;
    }

    void DataBlock::resize(size_t new_bits_size) {
        this->data_block.resize(new_bits_size);
        this->bits_size = new_bits_size;
    }

    void DataBlock::concatenate(const DataBlock &db) {
        for (size_t i = 0; i < db.size(); i++) {
            this->push_back(db.at(i));
        }
    }

    bool DataBlock::at(size_t pos) const {
        return this->data_block.at(pos);
    }

    bool DataBlock::operator[](size_t pos) const {
        return this->data_block[pos];
    }

    std::ostream &operator<<(std::ostream &os, const DataBlock &db) {
        for (size_t i = 0; i < db.size(); i++) {
            os << (db.at(i) ? "1" : "0");
        }
        return os;
    }

    bool DataBlock::operator==(const DataBlock &rhs) const {
        return data_block == rhs.data_block;
    }

    bool DataBlock::operator!=(const DataBlock &rhs) const {
        return !(rhs == *this);
    }
}