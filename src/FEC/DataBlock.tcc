#include "DataBlock.h"

namespace FEC {
    template<size_t N>
    DataBlock<N>::DataBlock() {
        this->data_block.reset();
    }

    template<size_t N>
    void DataBlock<N>::set() noexcept {
        this->data_block.set();
    }

    template<size_t N>
    void DataBlock<N>::set(size_t pos, bool value) {
        this->data_block.set(pos, value);
    }

    template<size_t N>
    size_t DataBlock<N>::size() const {
        return this->data_block.size();
    }

    template<size_t N>
    bool DataBlock<N>::at(size_t pos) const {
        return this->data_block[pos];
    }

    template<size_t N>
    bool DataBlock<N>::operator[](size_t pos) const {
        return this->data_block[pos];
    }
}