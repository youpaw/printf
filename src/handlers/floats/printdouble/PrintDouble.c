#include <stdlib.h>
#include "str.h"
#include "DoubleUnpacked.h"
#include "UnpackDouble.h"

char* correctTotalWidth(char* str, int totalWidth, int leftAlign)
{
	int size;
	char* newStr;

	size = strLen(str);
	if (totalWidth <= size)
		return str;

	newStr = strCreate(totalWidth);
	strFill(newStr, totalWidth, ' ');
	if(!leftAlign)
        strCopy(newStr + totalWidth - size, str);
	else
	{
        strCopy(newStr, str);
        newStr[size] = ' ';
    }
	free(str);

	return newStr;
}

const char* special2text(int special)
{
    if(special == DOUBLE_NAN)
        return "nan";
    if(special == DOUBLE_NAN_SIG)
        return "nan(sig)";
    if(special == DOUBLE_NAN_IND)
        return "nan(ind)";
    if(special == DOUBLE_INF)
        return "nan(inf)";
}


char* printDoubleUnpacked(const DoubleUnpacked* du, int totalWidth, int fracWidth, int leftAlign)
{
	char* str;

	if (du->special == DOUBLE_NAN || du->special == DOUBLE_INF)
	{
		str = strCreate(20);
		str[0] = '-';
		strCopy( str + du->sign, special2text(du->special) );
	}
	else
		str = printDoubleUnpackedNormal(du, fracWidth);

	str = correctTotalWidth(str, totalWidth, leftAlign);
	return str;
}

char* printDouble(long double d, int totalWidth, int fractionalWidth, int leftAlign)
{
	DoubleUnpacked du;

	du = unpackDouble(d);
	return printDoubleUnpacked(&du, totalWidth, fractionalWidth, leftAlign);
}