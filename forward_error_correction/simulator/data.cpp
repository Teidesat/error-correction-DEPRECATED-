#include "data.h"

Data::Data()
    : QVector<quint8>()
{}

Data::Data(const QString &str)
    : Data()
{
    fromString(str);
}

void Data::fromString(const QString &str)
{
    clear();
    reserve(str.size());
    for (int i = 0; i < str.size(); ++i) {
        push_back((str[i] == '1') ? 1 : 0);
    }
}

QString Data::toString() const
{
    QString str = "";
    for (int i = 0; i < QVector<quint8>::size(); ++i) {
        str += (at(i) == 1) ? '1' : '0';
    }
    return str;
}

void Data::appendFromString(const QString &str)
{
    append(Data(str));
}

void Data::addNoise(double noiseRate)
{
    for (int i = 0; i < QVector<quint8>::size(); ++i) {
        if (randomNormal() < noiseRate) {
            operator[](i) = (operator[](i) == 1) ? 0 : 1;
        }
    }
}

int Data::size() const
{
    return QVector<quint8>::size();
}

int Data::diffs(const Data &data) const
{
    int count = 0;
    for (int i = 0; (i < size()) && (i < data.size()); ++i) {
        if (at(i) != data[i])
            count++;
    }
    return count;
}
