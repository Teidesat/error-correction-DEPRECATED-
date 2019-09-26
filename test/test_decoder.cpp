#include <catch.hpp>
#include <FEC/Decoder.h>

TEST_CASE("Decoder is instantiable", "[decoder]") {
    FEC::Decoder decoder;
    REQUIRE(dynamic_cast<FEC::Decoder*>(&decoder));
}