#ifndef ERROR_CORRECTION_SOURCE_H
#define ERROR_CORRECTION_SOURCE_H

#include <FEC/Modules/Module.h>

#include <utility>

namespace FEC {
    template<size_t N>
    class Source : public Module<N> {
    public:
        Source() : Module<N>() {};

        explicit Source(const Parameters &parameters) : Module<N>(parameters) {};

        bool read(size_t data_blocks);

        void read_all();

    protected:
        /**
         * This method will be executed every time a new data block is needed from the source.
         * @param data_block the data block to be filled (output)
         * @return true if end of source is reached, else otherwise
         */
        virtual bool read_data_block(DataBlock<N> &data_block) = 0;

    private:
        void on_new_data_block(const DataBlock<N> &data_block, DataBlock<N> &output) final {};

        void send_data_block(DataBlock<N> &data_block);
    };
}

#include "Source.tcc"

#endif //ERROR_CORRECTION_SOURCE_H