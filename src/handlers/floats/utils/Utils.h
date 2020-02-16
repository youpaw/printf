#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>
#include <stdlib.h>
#include "DoubleRepresentation.h"

size_t myMax(size_t a, size_t b);
int intDecimalSize(int i);
int toInt(char ch);
int bitWidth(double_bit_t bits);
void strShiftLeft(char* str);

#endif