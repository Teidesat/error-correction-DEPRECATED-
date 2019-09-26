#include <catch.hpp>
#include <FEC/Channel.h>

TEST_CASE("Channel is instantiable", "[channel]") {
    FEC::Channel channel;
    REQUIRE(dynamic_cast<FEC::Channel*>(&channel));
}