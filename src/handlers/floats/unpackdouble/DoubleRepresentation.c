//
// Created by alina on 16.02.2020.
//

#include "DoubleRepresentation.h"

#ifdef DOUBLE_EXTENDED // 128-bit double
    double_bit_t mantiss(double_bit_t d)
    {
        double_bit_t v = 0x0000FFFFFFFFFFFF;
        double_bit_t vv = (v << 16) | 0xFFFFFFFFFFFFFFFF;
        return d & vv;
    }

    uint32_t exponent(double_bit_t d)
    {
        double_bit_t v = 0x7FFF000000000000;
        double_bit_t vv = v << 16;
        return (int32_t)((d & vv) >> MANTISS_SIZE_BITS);
    }

    int msb(double_bit_t d)
    {
        return d >> (UNDERLYING_TYPE_SIZE - 1);
    }

    double_bit_t addImaginaryBit(double_bit_t d)
    {
        return d; // no imaginary bit in extended precision
    }

    double_bit_t representationMask()
    {
        double_bit_t v = 0xFFFFFFFFFFFFFFFF;
        double_bit_t vv = (v << 16) | 0xFFFF;
        return vv;
    }
#else // 64-bit double
    double_bit_t getRepresentation(long double d)
    {
        union DoubleView dw;

        dw.ld = d;
        return dw.view;
    }

    double_bit_t mantiss(double_bit_t d)
    {
        return d & 0x000FFFFFFFFFFFFF;
    }

    uint32_t exponent(double_bit_t d)
    {
        return (int32_t)((d & 0x7FF0000000000000) >> MANTISS_SIZE_BITS);
    }

    int msb(double_bit_t d)
    {
        return d & 0x8000000000000000;
    }

    double_bit_t addImaginaryBit(double_bit_t d)
    {
        return d | 0x0010000000000000;
    }

    double_bit_t representationMask()
    {
        return 0xFFFFFFFFFFFFFFFF;
    }
#endif

union DoubleView{
    long double ld;
    double_bit_t view;
};

double_bit_t getRepresentation(long double d)
{
    union DoubleView dw;

    dw.ld = d;
    return dw.view;
}

int sign(double_bit_t d)
{
    return d >> (EXPONENT_SIZE_BITS + MANTISS_SIZE_BITS);
}