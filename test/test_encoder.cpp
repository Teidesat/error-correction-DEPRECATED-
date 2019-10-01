#include <catch.hpp>
#include <FEC/Modules/Encoders/Encoder.h>
#include <FEC/Modules/Encoders/RSCEncoder.h>
#include <FEC/Modules/Interleavers/BlockInterleaver.h>
#include <FEC/Modules/Encoders/TurboEncoder.h>

TEST_CASE("RSCEncoder works for r=1/2 and K=2", "[encoder]") {
    FEC::DataBlock input{0, 1, 0, 0, 1, 0, 0, 1}, output(16);

    FEC::Generators generators;
    generators.push_back(FEC::Generator{1, 1});
    generators.push_back(FEC::Generator{1, 0});

    FEC::RSCEncoder rsc_encoder(generators, 2);
    rsc_encoder.process(input, output);

    REQUIRE(output == FEC::DataBlock{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1});
}

TEST_CASE("RSCEncoder works for r=1/2 and K=3", "[encoder]") {
    FEC::DataBlock input{0, 1, 0, 0, 1, 0, 0, 1}, output(16);

    FEC::Generators generators;
    generators.push_back(FEC::Generator{1, 1, 1});
    generators.push_back(FEC::Generator{1, 0, 1});

    FEC::RSCEncoder rsc_encoder(generators, 3);
    rsc_encoder.process(input, output);

    REQUIRE(output == FEC::DataBlock{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1});
}

TEST_CASE("TurboEncoder works for r=1/3 with two K=2 encoders", "[encoder]") {
    FEC::DataBlock input{0, 1, 0, 0, 1, 0, 0, 1}, output(24);

    FEC::Generators generators;
    generators.push_back(FEC::Generator{1, 1});
    generators.push_back(FEC::Generator{1, 0});

    FEC::BlockInterleaver interleaver(4);
    FEC::RSCEncoder rsc_encoder1(generators, 2);
    FEC::RSCEncoder rsc_encoder2(generators, 2);

    FEC::TurboEncoder turbo_encoder(FEC::Encoders{&rsc_encoder1, &rsc_encoder2}, FEC::Interleavers{&interleaver});

    turbo_encoder.process(input, output);

    REQUIRE(output == FEC::DataBlock{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1});
}