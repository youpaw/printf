//
// Created by alina on 17.02.2020.
//

#include "DoubleRepresentation.h"
#include "DoubleClassifier.h"

#ifdef DOUBLE_EXTENDED // 128-bit double
int isNan(double_bit_t d)
{
    DoubleParts dp;

    dp = getDoubleParts(d);
    return dp.exponent == 0x7FFF && dp.bits63_62 == 0x3 && dp.bits61_0 != 0;
}

int isNormal(double_bit_t d)
{
    DoubleParts dp;

    dp = getDoubleParts(d);
    return dp.exponent != 0x7FFF && dp.exponent != 0x0;
}

DoubleParts getDoubleParts(double_bit_t d)
{
    DoubleParts dp;

    dp.sign = d >> DOUBLE_SIZE;
    dp.bit63 = (d >> 63) & 0x1;
    dp.bits63_62 = (d >> 62) & 0x11;
    dp.bits62_0 = d & 0x7FFFFFFFFFFFFFFF;
    dp.bits61_0 = d & 0x3FFFFFFFFFFFFFFF;
    dp.exponent = (d >> 64) & 0x7FFF;

    return dp;
}
#else // 64-bit double
int isNan(double_bit_t d)
    {
        return ((rep & 0xFFF0000000000000) == 0x7FF0000000000000 || (rep & 0xFFF0000000000000) == 0xFFF0000000000000);
    }

    int isNormal(double_bit_t d)
    {
        retun 1;
    }
#endif
