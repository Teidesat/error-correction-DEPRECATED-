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

        void set() noexcept;

        void reset() noexcept;

        void set(size_t pos, bool value = true);

        [[nodiscard]] size_t size() const;

        void resize(size_t new_bits_size);

        [[nodiscard]] bool at(size_t pos) const;

        [[nodiscard]] bool operator[](size_t pos) const;

        friend std::ostream &operator<<(std::ostream &os, const DataBlock &db) {
            for (size_t i = 0; i < db.size(); i++) {
                os << (db.at(i) ? "1" : "0");
            }
            return os;
        }

    private:
        size_t bits_size;
        std::vector<bool> data_block;
    };
}

#endif //ERROR_CORRECTION_DATABLOCK_H
