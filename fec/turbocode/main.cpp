#include <iostream>
#include <bitset>
#include "rscencoder.h"
#include "rscdecoder.h"

void print(const char* name, const Block& block) {
    std::cout << name;

    if (block.size() > 50) {
        std::cout << " [...] size: " << block.size();
    } else {
        for (Bit value : block) {
            std::cout << std::bitset<1>(value) << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    RSCDecoder decoder(2);
    RSCEncoder encoder(3, 0b011, 0b101);

    Block input = Block::random(100);
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

    std::cout << "Decoded error: " << (double(input.diffs(decoded)) / input.size()) << "%" << std::endl;

    return 0;
}
