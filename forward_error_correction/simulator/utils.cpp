#include "utils.h"

double randomNormal()
{
    return double(QRandomGenerator::global()->generate()) / QRandomGenerator::global()->max();
}
