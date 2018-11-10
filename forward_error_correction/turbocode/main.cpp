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
    RSCDecoder decoder(6);
    RSCEncoder encoder(6, 0b011111, 0b100001);

    std::srand(std::time(nullptr));
    for (double noiseLevel = 0; noiseLevel <= 1; noiseLevel += 0.01) {
        std::vector<double> decError;

        for (int its = 0; its < 50; ++its) {
            Block input = Block::random(1024);
            Block encoded;
            Block decoded;
            Block noise;

            encoded = encoder.encode(input);
            noise   = Block(encoded);
            //noise.addNoise(noiseLevel);
            noise.addEraserNoise(noiseLevel);
            decoded = decoder.decode(noise);
            decError.push_back(input.diffs(decoded) * 1.0 / input.size());
        }

        std::vector<double>& v = decError;
        double sum = std::accumulate(std::begin(v), std::end(v), 0.0);
        double m =  sum / v.size();

        double accum = 0.0;
        std::for_each (std::begin(v), std::end(v), [&](const double d) {
            accum += (d - m) * (d - m);
        });

        double stdev = sqrt(accum / (v.size()-1));
        printf("%.3f,%.4f,%.4f\n", noiseLevel, m, stdev);
    }

    return 0;
}
