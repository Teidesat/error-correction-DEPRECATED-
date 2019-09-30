#ifndef ERROR_CORRECTION_PRINTER_H
#define ERROR_CORRECTION_PRINTER_H

#include <FEC/Modules/Module.h>

namespace FEC {
    template<size_t N>
    class Printer : public Module<N> {
    public:
        Printer() : Module<N>() {};

        explicit Printer(const Parameters &parameters) : Module<N>(parameters) {};

    private:
        void on_new_data_block(const DataBlock<N> &data_block, DataBlock<N> &output) override;
    };
}

#include "Printer.tcc"

#endif //ERROR_CORRECTION_PRINTER_H