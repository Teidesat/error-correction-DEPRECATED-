#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "utils.h"

class Data : private QVector<quint8>
{
public:
    explicit Data(const QString& str);
    Data();

    void fromString(const QString& str);
    QString toString() const;
    void appendFromString(const QString& str);
    void addNoise(double noiseRate);
    int size() const;
    int diffs(const Data& data) const;
};

#endif // DATA_H
