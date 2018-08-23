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
    RSCEncoder encoder(3, 0b101, 0b111);

    Block input(std::vector<Bit>({0, 1, 0, 1, 1, 1}));
    Block encoded;
    Block decoded;
    Block noise;

    encoded = encoder.encode(input);
    noise   = Block(encoded);
    //noise.addNoise(0.0);
    decoded = decoder.decode(noise);

    print("Input:   ", input);
    print("Decoded: ", decoded);
    print("Noised:  ", noise);
    print("Encoded: ", encoded);

    return 0;
}
