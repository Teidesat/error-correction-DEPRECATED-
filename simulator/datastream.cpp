#include "datastream.h"


DataStream::DataStream()
    : QVector<quint8>()
{}

DataStream::DataStream(const QString &string)
    : QVector<quint8>()
{
    fromString(string);
}

void DataStream::fromString(const QString &string)
{
    clear();
    reserve(string.size());
    for (int i = 0; i < string.size(); ++i) {
        push_back(string[i] == '1');
    }
}

void DataStream::addNoise(double noise)
{
    assert(noise <= 1.0 && noise >= 0.0);
    for (int i = 0; i < size(); ++i) {
        if (randomNormal() < noise) {
            operator[](i) = (operator[](i) == 1) ? 0 : 1;
        }
    }
}

double DataStream::onesPercent() const
{
    int ones = 0;
    for (int i = 0; i < size(); ++i) {
        if (operator[](i) == 1)
            ones++;
    }
    return double(ones) / size();
}

QString DataStream::toString() const
{
    QString string;
    string.reserve(size());
    for (int i = 0; i < size(); ++i) {
        string.push_back('0' + operator[](i));
    }
    return string;
}
