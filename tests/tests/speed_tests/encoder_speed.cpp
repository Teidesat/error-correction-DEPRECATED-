//
// Created by jsier on 20/09/2020.
//

#include <chrono>
#include <numeric>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "gtest/gtest.h"
#include "../../../src/encoder/RSC.h"
#include "../../../src/other/common.h"

template<typename Functor>
uint64_t measure_time(Functor functor) {
    auto t1 = std::chrono::high_resolution_clock::now();
    functor();
    auto t2 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}

template<class T>
std::pair<double, double> avg_std(const std::vector<T>& v) {
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    double mean = sum / v.size();
    double sq_sum = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / v.size() - mean * mean);
    return std::make_pair(mean, stdev);
}

template<class T>
void matplotlib(const std::vector<T>& x,
                const std::vector<T>& y,
                const std::vector<T>& e,
                const std::string& title = "",
                const std::string& xlabel = "",
                const std::string& ylabel = "") {
    std::string str;

    str += "python -c \"import matplotlib.pyplot as plt;import numpy as np;";
    str += "x=[";
    for (const auto& i : x) {
        str += format("{},", i);
    }
    str += "];";
    str += "y=[";
    for (const auto& i : y) {
        str += format("{},", i);
    }
    str += "];";
    str += "e=[";
    for (const auto& i : e) {
        str += format("{},", i);
    }
    str += "];";
    str += format("plt.title('{}');plt.xlabel('{}');plt.ylabel('{}');", title, xlabel, ylabel);
    str += e.size() > 0 ? "plt.errorbar(x, y, yerr=e, marker='o');" :
                          "plt.plot(x, y);";
    str += "plt.show();\"";
    system(str.c_str());
}

TEST(SpeedTests, Encoding) {
    const int g1 = 0b11001; // 0o31
    const int g2 = 0b10111; // 0o27
    const int REPEATS = 10;

    std::vector<uint64_t> measurements(REPEATS);
    std::string output;

    for (int state_size = 2; state_size <= 16; ++state_size) {
        percentageBar(state_size - 2, 14);

        for (int bytes = 1; bytes <= 4096; ++bytes) {
            output += format("{},{}", state_size, bytes);
            for (int r = 0; r < REPEATS; ++r) {
                auto input = randomVector(bytes);
                RSC rsc(g1, g2, state_size);
                auto t = measure_time([&](){
                    auto tmp = rsc.encodeMem(input.data(), input.size());
                });
                output += format(",{}", t);
            }
            output += '\n';
        }
    }

    std::ofstream out("encoder_speed.csv");
    out << output;
    out.close();

    EXPECT_TRUE(true);
}

TEST(SpeedTests, DecodingViterbi) {
    const int g1 = 0b11001; // 0o31
    const int g2 = 0b10111; // 0o27
    const int REPEATS = 10;

    std::vector<uint64_t> measurements(REPEATS);
    std::string output;

    for (int state_size = 9; state_size <= 16; ++state_size) {
        percentageBar(state_size - 2, 14);

        for (int bytes = 1; bytes <= 256; ++bytes) {
            output += format("{},{}", state_size, bytes);
            for (int r = 0; r < REPEATS; ++r) {
                auto input = randomVector(bytes);
                RSC rsc(g1, g2, state_size);
                auto enc = rsc.encodeMem(input.data(), input.size());
                auto t = measure_time([&](){
                    auto tmp = rsc.decodeMemViterbi(enc.data(), enc.size());
                });
                output += format(",{}", t);
            }
            output += '\n';
        }
    }

    std::ofstream out("decoder_speed.csv");
    out << output;
    out.close();

    EXPECT_TRUE(true);
}

TEST(PerformanceTests, Encoding) {
    const int g1 = 0b11001; // 0o31
    const int g2 = 0b10111; // 0o27
    const int state_size = 4;
    const int BYTES = 128;
    const int REPEATS = 100;

    std::vector<float> repeat(REPEATS);
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> e;
    for (float p = 0; p <= 1.01; p += 0.05) {
        std::cout << p << std::endl;
        for (int r = 0; r < REPEATS; ++r) {
            auto input = randomVector(BYTES);
            RSC rsc(g1, g2, state_size);
            auto enc = addNoise(input, p);
            repeat[r] = ber(enc, input);
        }
        auto pair = avg_std(repeat);
        e.push_back(pair.second);
        y.push_back(pair.first);
        x.push_back(p);
    }
    matplotlib(x, y, e, "", "p_b", "BER");
    EXPECT_TRUE(true);
}