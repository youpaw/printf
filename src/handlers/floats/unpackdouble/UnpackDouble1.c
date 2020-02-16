#include "UnpackDouble.h"
#include "BigInt.h"
#include "DoubleUnpacked.h"
#include "DoubleRepresentation.h"

DoubleUnpacked assignDoubleUnpacked(int sign, BigInt* integer, BigInt* fractional, int special)
{
	DoubleUnpacked result;

	result.sign = sign;
	result.integer = *integer;
	result.fractional = *fractional;
	result.special = special;

	return result;
}

void unpackDenormal(BigInt* integer, BigInt* fractional, double_bit_t mantiss)
{
	bigIntFromInt(integer, 0);
	double_bit_t fract = mantiss << (EXPONENT_SIZE_BITS + 1);
	CalcFractional(fractional, fract, 1022, 1);
}

void unpackNormal(BigInt* integer, BigInt* fractional, double_bit_t representation, double_bit_t m)
{
	uint32_t e;

	e = exponent(representation);
	if (e < EXPONENT_BIAS)
		unpackBelowOne(integer, fractional, e, m);
	else {
		e -= EXPONENT_BIAS;
		if (e <= MANTISS_SIZE_BITS)
			unpackAverage(integer, fractional, e, m);
		else
			unpackHuge(integer, fractional, e, m);
	}
}

DoubleUnpacked unpackDouble(long double d)
{
	double_bit_t rep;
	BigInt fractional;
	BigInt integer;
	int special;

	bigIntCreate(&fractional);
	bigIntCreate(&integer);
	special = 0;
	rep = getRepresentation(d);
	if (rep == 0x0 || rep == 0x8000000000000000)
	{
		bigIntFromInt(&integer, 0);
		bigIntFromInt(&fractional, 0);
	}
	else if (rep == 0x7FF0000000000000 || rep == 0xFFF0000000000000) // inf
		special = DOUBLE_INF;
	else if ((rep & 0xFFF0000000000000) == 0x7FF0000000000000 || (rep & 0xFFF0000000000000) == 0xFFF0000000000000) // NaN
		special = DOUBLE_NAN;
	else if ((rep & 0xFFF0000000000000) == 0x8000000000000000 || (rep & 0xFFF0000000000000) == 0) //denormalized
		unpackDenormal(&integer, &fractional, mantiss(rep));
	else
		unpackNormal(&integer, &fractional, rep, mantiss(rep));
	return assignDoubleUnpacked(sign(rep), &integer, &fractional, special);
}
