//
// Created by alina on 17.02.2020.
//

#include "DoubleRepresentation.h"

#ifdef DOUBLE_EXTENDED // 128-bit double
#else // 64-bit double
int isZero(double_bit_t d)
    {
        return (rep == 0x0 || rep == 0x8000000000000000);
    }

    int isDenormal(double_bit_t d)
    {
        return ((rep & 0xFFF0000000000000) == 0x8000000000000000 || (rep & 0xFFF0000000000000) == 0);
    }

    int isInf(double_bit_t d)
    {
        return (rep == 0x7FF0000000000000 || rep == 0xFFF0000000000000);
    }

    int isNanSig(double_bit_t d)
    {
        return 0;
    }

    int isInd(double_bit_t d)
    {
        return 0;
    }
#endif
