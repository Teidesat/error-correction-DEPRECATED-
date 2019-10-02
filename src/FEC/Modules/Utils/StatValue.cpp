//
// Created by jsier on 02/10/2019.
//

#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "StatValue.h"

FEC::StatValue::StatValue()
    : elements(0), mean(0), stddev(0), max(0), min(0)
{}

FEC::StatValue::StatValue(const std::vector<double> &v)
    : StatValue()
{
    from(v);
}

void FEC::StatValue::from(const std::vector<double> &v) {
    max = *max_element(v.begin(), v.end());
    min = *min_element(v.begin(), v.end());
    elements = v.size();
    mean = std::accumulate(v.begin(), v.end(), 0.0) / v.size();

    std::vector<double> diff(v.size());
    std::transform(v.begin(), v.end(), diff.begin(), [=](double x) { return x - mean; });
    double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    stddev = std::sqrt(sq_sum / v.size());
}

double FEC::StatValue::getMean() const {
    return mean;
}

double FEC::StatValue::getStdDev() const {
    return stddev;
}

double FEC::StatValue::getMax() const {
    return max;
}

double FEC::StatValue::getMin() const {
    return min;
}

size_t FEC::StatValue::size() const {
    return 0;
}
