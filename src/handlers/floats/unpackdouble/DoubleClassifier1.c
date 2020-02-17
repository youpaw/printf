//
// Created by alina on 17.02.2020.
//

#include "DoubleRepresentation.h"
#include "DoubleClassifier.h"

#ifdef DOUBLE_EXTENDED // 128-bit double
int isZero(double_bit_t d)
{
    DoubleParts dp;

    dp = getDoubleParts(d);
    return dp.exponent == 0 && dp.bit63 == 0 && dp.bits62_0 == 0;
}

int isDenormal(double_bit_t d)
{
    DoubleParts dp;

    dp = getDoubleParts(d);
    return dp.exponent == 0 && dp.bit63 == 0 && dp.bits62_0 != 0;
}

int isInf(double_bit_t d)
{
    DoubleParts dp;

    dp = getDoubleParts(d);
    return dp.exponent == 0x7FFF && dp.bits63_62 == 0x2 && dp.bits61_0 == 0;
}

int isNanSig(double_bit_t d)
{
    DoubleParts dp;

    dp = getDoubleParts(d);
    return dp.exponent == 0x7FFF && dp.bits63_62 == 0x2 && dp.bits61_0 != 0;
}

int isInd(double_bit_t d)
{
    DoubleParts dp;

    dp = getDoubleParts(d);
    return dp.exponent == 0x7FFF && dp.bits63_62 == 0x3 && dp.bits61_0 == 0;
}
#else // 64-bit double
#endif

