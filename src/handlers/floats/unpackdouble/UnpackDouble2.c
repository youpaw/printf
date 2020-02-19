#include "BigInt.h"
#include "Utils.h"
#include "DoubleRepresentation.h"

void CalcFractional(BigInt* fractional, double_bit_t fract, int initialPow, int denormal)
{
	int width;
	BigInt pow;
	BigInt pow1;

	width = bitWidth(fract) + initialPow;
	nPowY(&pow, 10, width);
	nPowY(&pow1, 10, width);
	bigIntCreate(fractional);
	if (initialPow)
	{
		while (initialPow--)
			bigIntDivide(&pow, 2);
		if (!denormal)
			bigIntAdd(fractional, &pow);
	}
	while (fract)
	{
		bigIntDivide(&pow, 2);
		if ( msb(fract) )
			bigIntAdd(fractional, &pow);
		fract <<= 1;
	}
	bigIntAdd(fractional, &pow1);
}


void unpackBelowOne(BigInt* integer, BigInt* fractional, uint32_t e, double_bit_t m)
{
	double_bit_t fract;

	e = EXPONENT_BIAS - e;
	fract = ((m << (EXPONENT_SIZE_BITS + IMAGINARY_BIT_PRESENT + 1)) & representationMask()) << LEFT_SHIFT_BITS;
	CalcFractional(fractional, fract, e, 0);
	bigIntFromInt(integer, 0);
}

void unpackAverage(BigInt* integer, BigInt* fractional, uint32_t e, double_bit_t m)
{
	double_bit_t fract;

	m = addImaginaryBit(m);
	bigIntFromInt(integer, m >> (MANTISS_SIZE_BITS - IMAGINARY_BIT_PRESENT - e));
 	fract = ((m << (EXPONENT_SIZE_BITS + IMAGINARY_BIT_PRESENT + 1 + e)) & representationMask()) << LEFT_SHIFT_BITS;
	CalcFractional(fractional, fract, 0, 0);
}

void unpackHuge(BigInt* integer, BigInt* fractional, uint32_t e, double_bit_t m)
{
	BigInt mantiss;
	BigInt pow;

	(void)fractional;
	m = addImaginaryBit(m);
	bigIntFromInt(&mantiss, m);
	nPowY(&pow, 2, e - MANTISS_SIZE_BITS + IMAGINARY_BIT_PRESENT);
	bigIntMultiplyBig(integer, &pow, &mantiss);
}
