#include <iostream>
#include <Config.h>

#include <FEC/Modules/Sources/RandomSource.h>
#include <FEC/Modules/Utils/Printer.h>
#include <FEC/Modules/Utils/StatValue.h>
#include <FEC/Modules/Interleavers/BlockInterleaver.h>
#include <FEC/Modules/Encoders/RSCEncoder.h>
#include <FEC/Modules/Encoders/TurboEncoder.h>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <cmath>

const int TEST_REPS = 50;
const int TEST_N    = 1048576; // 2^20
const int TEST_STEP = 65536;   // 2^16

int main() {
    std::cout << "Version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

    FEC::Generators generators;
    generators.push_back(FEC::Generator{1, 1});
    generators.push_back(FEC::Generator{1, 0});

    FEC::BlockInterleaver interleaver(4);
    FEC::RSCEncoder rsc_encoder1(generators, 2);
    FEC::RSCEncoder rsc_encoder2(generators, 2);

    auto encoders = FEC::Encoders{&rsc_encoder1, &rsc_encoder2};
    auto interleavers = FEC::Interleavers{&interleaver};

    std::cout << "size[n],duration[ms],duration[std],duration[max],duration[min]" << std::endl;

    for (int n = TEST_STEP; n <= TEST_N; n += TEST_STEP) {
        std::vector<double> duration(TEST_REPS);

        for (int i = 0; i < TEST_REPS; ++i) {
            FEC::RandomSource random_source(n);
            FEC::TurboEncoder turbo_encoder(encoders, interleavers);
            random_source.get_pipe().set_output(turbo_encoder);

            auto t1 = std::chrono::high_resolution_clock::now();
            random_source.read(1);
            auto t2 = std::chrono::high_resolution_clock::now();
            duration[i] = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
        }

        FEC::StatValue va(duration);
        std::cout << n << ',' << va.getMean() << ',' << va.getStdDev() << ',' << va.getMax() << ',' << va.getMean() << std::endl;
    }

    return 0;
}
