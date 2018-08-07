#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <QVector>
#include <QRandomGenerator>
#include "utils.h"

class DataStream : public QVector<quint8>
{
public:
    DataStream();
    explicit DataStream(const QString& string);

    void fromString(const QString& string);
    void addNoise(double noise);
    double onesPercent() const;
    QString toString() const;
};

#endif // DATASTREAM_H
