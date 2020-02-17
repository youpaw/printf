#include "UnpackDouble.h"
#include "BigInt.h"
#include "DoubleUnpacked.h"
#include "DoubleRepresentation.h"
#include "DoubleClassifier.h"

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
	double_bit_t fract = ( (mantiss << (EXPONENT_SIZE_BITS + 2)) & representationMask() ) << LEFT_SHIFT_BITS;
	CalcFractional(fractional, fract, EXPONENT_BIAS - 1, 1);
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

int classify(double_bit_t rep, BigInt* integer, BigInt* fractional)
{
    int class;

    class = 0;

    if ( isZero(rep) )
    {
        bigIntFromInt(integer, 0);
        bigIntFromInt(fractional, 0);
    }
    else if ( isInf(rep) )
        class = DOUBLE_INF;
    else if ( isNan(rep) )
        class = DOUBLE_NAN;
    else if ( isInd(rep) )
        class = DOUBLE_NAN_IND;
    else if ( isNanSig(rep) )
        class = DOUBLE_NAN_SIG;
    else if ( isDenormal(rep) )
        unpackDenormal(integer, fractional, mantiss(rep));
    else
        unpackNormal(integer, fractional, rep, mantiss(rep));

    return class;
}


DoubleUnpacked unpackDouble(long double d)
{
	double_bit_t rep;
	BigInt fractional;
	BigInt integer;
	int special;

	bigIntCreate(&fractional);
	bigIntCreate(&integer);
	rep = getRepresentation(d);

    special = classify(rep, &integer, &fractional);

	return assignDoubleUnpacked(sign(rep), &integer, &fractional, special);
}
