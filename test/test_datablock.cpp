#include <catch.hpp>
#include <FEC/DataBlock.h>

#include <iostream>

TEST_CASE("DataBlock is instantiable", "[datablock]") {
    FEC::DataBlock dataBlock;
    REQUIRE(dynamic_cast<FEC::DataBlock*>(&dataBlock));
}

TEST_CASE("DataBlock is filled with 0 on instantiation", "[datablock]") {
    FEC::DataBlock dataBlock;
    bool one_found = false;
    for (size_t i = 0; i < dataBlock.size() && !one_found; i++) {
        if (dataBlock[i]) one_found = true;
    }
    REQUIRE(!one_found);
}