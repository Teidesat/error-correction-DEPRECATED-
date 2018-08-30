#include <iostream>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <numeric>
#include <algorithm>
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
    RSCDecoder decoder(3);
    RSCEncoder encoder(3, 0b011, 0b101);
    const double noiseLevel = 0;

    //Block input = Block::random(3);
//    Block input = Block(std::vector<Bit>({0, 0, 1}));
//    Block encoded;
//    Block decoded;
//    Block noise;

//    encoded = encoder.encode(input);
//    noise   = Block(encoded);
//    noise.addNoise(noiseLevel);
//    decoded = decoder.decode(noise);

//    print("Input:   ", input);
//    print("Decoded: ", decoded);
//    print("Noised:  ", noise);
//    print("Encoded: ", encoded);
//    std::cout << "Decoded error: " << (input.diffs(decoded) * 100.0 / input.size()) << "%  ";
//    std::cout << "Noise (Bit swap rate): " << (noiseLevel * 100.0) << "%" << std::endl;


    //std::srand(std::time(nullptr));
    std::srand(10);
    for (double noiseLevel = 0; noiseLevel <= 0.001; noiseLevel += 0.05) {
        std::vector<double> decError;

        for (int its = 0; its < 20; ++its) {
            Block input = Block::random(3);
            Block encoded;
            Block decoded;
            Block noise;

            encoded = encoder.encode(input);
            noise   = Block(encoded);
            //noise.addNoise(noiseLevel);
            decoded = decoder.decode(noise);
            //std::cout << "Decoded error: " << (input.diffs(decoded) * 100.0 / input.size()) << "%  ";
            //std::cout << "Noise (Bit swap rate): " << (noiseLevel * 100.0) << "%" << std::endl;
            double error = input.diffs(decoded) * 1.0 / input.size();
            decError.push_back(error);
            if (error > 0) {
                print("Input:   ", input);
                print("Decoded: ", decoded);
                //print("Noised:  ", noise);
                print("Encoded: ", encoded);
                std::cout << its << " " << error << std::endl;
            }
        }

        std::vector<double>& v = decError;
        double sum = std::accumulate(std::begin(v), std::end(v), 0.0);
        double m =  sum / v.size();

        double accum = 0.0;
        std::for_each (std::begin(v), std::end(v), [&](const double d) {
            accum += (d - m) * (d - m);
        });

        double stdev = sqrt(accum / (v.size()-1));
        printf("Noise: %.3f AvgError: %.4f StdDev: %.4f\n", noiseLevel, m, stdev);
    }

    return 0;
}
