#ifndef ERROR_CORRECTION_PRINTER_H
#define ERROR_CORRECTION_PRINTER_H

#include <FEC/Modules/Module.h>

#include <utility>

namespace FEC {
    class Printer : public Module {
    public:
        explicit Printer(std::string caption = "") : Module(), caption(std::move(caption)) {};

    private:
        std::string caption;

        void on_new_data_block(const DataBlock &data_block, DataBlock &output) override;
    };
}

#endif //ERROR_CORRECTION_PRINTER_H