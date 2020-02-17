//
// Created by alina on 15.02.2020.
//

#ifndef FT_PRINTF_DOUBLEREPRESENTATION_H
#define FT_PRINTF_DOUBLEREPRESENTATION_H

#include <stdint.h>

#ifdef DOUBLE_EXTENDED // 80-bit double
    #define EXPONENT_SIZE_BITS 15
    #define MANTISS_SIZE_BITS 64
    #define EXPONENT_BIAS 16383
    #define IMAGINARY_BIT_PRESENT 1
    #define UNDERLYING_TYPE_SIZE 128
    #define DOUBLE_SIZE 80
    #define LEFT_SHIFT_BITS UNDERLYING_TYPE_SIZE - DOUBLE_SIZE
    typedef unsigned __int128 double_bit_t;
#else // 64-bit double
    #define EXPONENT_SIZE_BITS 11
    #define MANTISS_SIZE_BITS 52
    #define EXPONENT_BIAS 1023
    #define IMAGINARY_BIT_PRESENT 0
    #define UNDERLYING_TYPE_SIZE 64
    #define DOUBLE_SIZE 64
    #define LEFT_SHIFT UNDERLYING_TYPE_SIZE - DOUBLE_SIZE
    typedef uint64_t double_bit_t;
#endif

double_bit_t mantiss(double_bit_t d);
uint32_t exponent(double_bit_t d);
int msb(double_bit_t d);
double_bit_t addImaginaryBit(double_bit_t d);
int sign(double_bit_t d);
double_bit_t getRepresentation(long double d);
double_bit_t representationMask();
int isZero(double_bit_t d);
int isDenormal(double_bit_t d);
int isInf(double_bit_t d);
int isNanSig(double_bit_t d);
int isInd(double_bit_t d);
int isNan(double_bit_t d);
int isNormal(double_bit_t d);

#endif //FT_PRINTF_DOUBLEREPRESENTATION_H
