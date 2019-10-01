#include <catch.hpp>
#include <FEC/Modules/Interleavers/BlockInterleaver.h>

TEST_CASE("Block interleaver works when matrix is full", "[interleaver]") {
    FEC::DataBlock input{0, 1, 0, 0, 1, 0, 0, 1}, output(8);

    FEC::BlockInterleaver interleaver(4);
    interleaver.process(input, output);

    REQUIRE(output == FEC::DataBlock{0, 1, 1, 0, 0, 0, 0, 1});
}

TEST_CASE("Block interleaver works when matrix has empty spaces", "[interleaver]") {
    FEC::DataBlock input{0, 1, 0, 0, 1, 0, 0, 1}, output(8);

    FEC::BlockInterleaver interleaver(3);
    interleaver.process(input, output);

    REQUIRE(output == FEC::DataBlock{0, 0, 0, 1, 1, 1, 0, 0});
}