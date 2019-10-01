#include <iostream>
#include <Config.h>

#include <FEC/Modules/Sources/RandomSource.h>
#include <FEC/Modules/Utils/Printer.h>
#include <FEC/Modules/Interleaves/BlockInterleaver.h>
#include <FEC/Modules/Encoders/RSCEncoder.h>

int main() {
    std::cout << "Version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

    FEC::Generators generators;
    generators.push_back(FEC::Generator{1,1});
    generators.push_back(FEC::Generator{1,0});

    FEC::RandomSource random_source(8);
    FEC::Printer printer1("Source:");
    FEC::BlockInterleaver interleaver(4);
    FEC::Printer printer2("Interleaved source:");
    FEC::RSCEncoder rsc_encoder(generators, 2);
    FEC::Printer printer3("Encoded source:");

    random_source.get_pipe().set_output(printer1);
    printer1.get_pipe().set_output(interleaver);
    interleaver.get_pipe().set_output(printer2);
    printer2.get_pipe().set_output(rsc_encoder);
    rsc_encoder.get_pipe().set_output(printer3);

    random_source.read(1);
    return 0;
}
