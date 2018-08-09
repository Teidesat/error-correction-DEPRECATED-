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
    for (int i = 0; i < size(); ++i) {
        str += (at(i) == 1) ? '1' : '0';
    }
    return str;
}

void Data::appendFromString(const QString &str)
{
    append(Data(str));
}
