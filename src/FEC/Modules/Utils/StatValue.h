#ifndef ERROR_CORRECTION_STATVALUE_H
#define ERROR_CORRECTION_STATVALUE_H


#include <vector>

namespace FEC {
    class StatValue {
    public:
        StatValue();
        explicit StatValue(const std::vector<double> &v);

        void from(const std::vector<double> &v);

        double getMean() const;
        double getStdDev() const;
        double getMax() const;
        double getMin() const;
        size_t size() const;

    private:
        size_t elements;
        double mean;
        double stddev;
        double max;
        double min;
    };
}


#endif //ERROR_CORRECTION_STATVALUE_H
