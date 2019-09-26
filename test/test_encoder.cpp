#include <catch.hpp>
#include <FEC/Encoder.h>

TEST_CASE("Encoder is instantiable", "[encoder]") {
    FEC::Encoder encoder;
    REQUIRE(dynamic_cast<FEC::Encoder*>(&encoder));
}