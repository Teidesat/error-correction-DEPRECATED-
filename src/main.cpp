#include <iostream>
#include <Config.h>

#include <FEC/Modules/Sources/RandomSource.h>
#include <FEC/Modules/Utils/Printer.h>
#include <FEC/Modules/Interleaves/BlockInterleaver.h>

int main() {
    std::cout << "Version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

    FEC::RandomSource<1> random_source;
    FEC::Printer<1> printer1;
    FEC::BlockInterleaver<1> interleaver;
    FEC::Printer<1> printer2;

    interleaver.get_parameters().emplace("columns", 4);

    random_source.get_pipe().set_output(printer1);
    printer1.get_pipe().set_output(interleaver);
    interleaver.get_pipe().set_output(printer2);

    random_source.read(1);
    return 0;
}
