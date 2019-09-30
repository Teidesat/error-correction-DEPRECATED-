#ifndef ERROR_CORRECTION_DATABLOCK_H
#define ERROR_CORRECTION_DATABLOCK_H

#include <bitset>
#include <ostream>

namespace FEC {
    /**
     * Data block, used in forward error correction modules.
     * @tparam N block size in bytes
     */
    template<size_t N = 4096>
    class DataBlock {
    public:
        DataBlock();

        void set() noexcept;

        void set(size_t pos, bool value = true);

        [[nodiscard]] size_t size() const;

        [[nodiscard]] bool at(size_t pos) const;

        [[nodiscard]] bool operator[](size_t pos) const;

        friend std::ostream &operator<<(std::ostream &os, const DataBlock<N> &db) {
            for (size_t i = 0; i < db.size(); i++) {
                os << (db.at(i) ? "1" : "0");
            }
            return os;
        }

    private:
        std::bitset<N * 8> data_block;
    };
}

#include "DataBlock.tcc"

#endif //ERROR_CORRECTION_DATABLOCK_H
