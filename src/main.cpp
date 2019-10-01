#include <iostream>
#include <Config.h>

#include <FEC/Modules/Sources/RandomSource.h>
#include <FEC/Modules/Utils/Printer.h>
#include <FEC/Modules/Interleavers/BlockInterleaver.h>
#include <FEC/Modules/Encoders/RSCEncoder.h>
#include <FEC/Modules/Encoders/TurboEncoder.h>

int main() {
    std::cout << "Version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

    FEC::Generators generators;
    generators.push_back(FEC::Generator{1, 1});
    generators.push_back(FEC::Generator{1, 0});

    FEC::BlockInterleaver interleaver(4);
    FEC::RSCEncoder rsc_encoder1(generators, 2);
    FEC::RSCEncoder rsc_encoder2(generators, 2);

    FEC::RandomSource random_source(8);
    FEC::Printer printer1("Source:");
    FEC::TurboEncoder turbo_encoder(FEC::Encoders{&rsc_encoder1, &rsc_encoder2}, FEC::Interleavers{&interleaver});
    FEC::Printer printer2("Encoded source:");

    random_source.get_pipe().set_output(printer1);
    printer1.get_pipe().set_output(turbo_encoder);
    turbo_encoder.get_pipe().set_output(printer2);

    random_source.read(1);
    return 0;
}
