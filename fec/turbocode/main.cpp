#include <iostream>
#include <bitset>
#include "rscencoder.h"
#include "rscdecoder.h"

void print(const char* name, const Block& block) {
    std::cout << name;
    for (Bit value : block) {
        std::cout << std::bitset<1>(value) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    RSCDecoder decoder(2);
    RSCEncoder encoder(2);

    Block input(std::vector<Bit>({0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1}));
    Block encoded;
    Block decoded;

    encoded = encoder.encode(input);
    decoded = decoder.decode(encoded);

    print("Input:   ", input);
    print("Decoded: ", decoded);
    print("Encoded: ", encoded);

    return 0;
}
