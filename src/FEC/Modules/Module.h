#ifndef ERROR_CORRECTION_MODULE_H
#define ERROR_CORRECTION_MODULE_H

#include <FEC/Pipe.h>

#include <map>
#include <vector>

namespace FEC {

    using Parameters = std::map<std::string, float>;

    /**
     * Base class of all components.
     * @tparam N the size in bytes of the input data block
     * @tparam K the size in bytes of the output data block, by default K = N
     */
    template<size_t N, size_t K>
    class Module {
    public:
        Module() {};

        explicit Module(const Parameters &parameters) : parameters(parameters) {};

        [[nodiscard]] Pipe<K> &get_pipe();

        [[nodiscard]] Parameters &get_parameters();

        void process(std::shared_ptr<DataBlock<N>> data_block);

    protected:
        /**
         * Virtual method that must be implemented in every module, it will be called when a new data block is received.
         * @param data_block the received data block
         * @param output the processed data block
         */
        virtual void on_new_data_block(const DataBlock<N> &data_block, DataBlock<K> &output) = 0;

    private:
        Pipe<K> pipe;

        Parameters parameters;
    };
}

#include "Module.tcc"

#endif //ERROR_CORRECTION_MODULE_H