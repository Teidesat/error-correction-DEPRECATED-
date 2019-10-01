#ifndef ERROR_CORRECTION_MODULE_H
#define ERROR_CORRECTION_MODULE_H

#include <FEC/Pipe.h>

namespace FEC {
    /**
     * Base class of all components.
     */
    class Module {
    public:
        Module() = default;

        [[nodiscard]] Pipe &get_pipe();

        void process(const std::shared_ptr<DataBlock>& data_block);

    protected:
        /**
         * Virtual method that must be implemented in every module, it will be called when a new data block is received.
         * @param data_block the received data block
         * @param output the processed data block
         */
        virtual void on_new_data_block(const DataBlock &data_block, DataBlock &output) = 0;

    private:
        Pipe pipe;
    };
}

#endif //ERROR_CORRECTION_MODULE_H