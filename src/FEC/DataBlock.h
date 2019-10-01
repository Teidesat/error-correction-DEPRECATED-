#ifndef ERROR_CORRECTION_DATABLOCK_H
#define ERROR_CORRECTION_DATABLOCK_H

#include <vector>
#include <ostream>

namespace FEC {
    /**
     * Data block, used in forward error correction modules.
     */
    class DataBlock {
    public:
        explicit DataBlock(size_t bits_size = 32768);

        DataBlock(std::initializer_list<bool> initializer_list);

        void set() noexcept;

        void reset() noexcept;

        void set(size_t pos, bool value = true);

        void push_back(bool value);

        void remove_first(size_t n_bits);

        void remove_last(size_t n_bits);

        [[nodiscard]] size_t size() const;

        void resize(size_t new_bits_size);

        void concatenate(const DataBlock &db);

        [[nodiscard]] bool at(size_t pos) const;

        [[nodiscard]] bool operator[](size_t pos) const;

        friend std::ostream &operator<<(std::ostream &os, const DataBlock &db);

        bool operator==(const DataBlock &rhs) const;

        bool operator!=(const DataBlock &rhs) const;

    private:
        size_t bits_size;
        std::vector<bool> data_block;
    };
}

#endif //ERROR_CORRECTION_DATABLOCK_H
