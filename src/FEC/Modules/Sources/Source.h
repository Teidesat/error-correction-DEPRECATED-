#ifndef ERROR_CORRECTION_SOURCE_H
#define ERROR_CORRECTION_SOURCE_H

#include <FEC/Modules/Module.h>

#include <utility>

namespace FEC {
    class Source : public Module {
    public:
        explicit Source(size_t data_block_size) : Module(), data_block_size(data_block_size) {};

        bool read(size_t data_blocks);

        void read_all();

    protected:
        /**
         * This method will be executed every time a new data block is needed from the source.
         * @param data_block the data block to be filled (output)
         * @return true if end of source is reached, else otherwise
         */
        virtual bool read_data_block(DataBlock &data_block) = 0;

    private:
        size_t data_block_size;

        void on_new_data_block(const DataBlock &data_block, DataBlock &output) final {};

        void send_data_block(DataBlock &data_block);
    };
}

#endif //ERROR_CORRECTION_SOURCE_H