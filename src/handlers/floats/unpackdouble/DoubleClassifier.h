//
// Created by alina on 17.02.2020.
//

#ifndef FT_PRINTF_DOUBLECLASSIFIER_H
#define FT_PRINTF_DOUBLECLASSIFIER_H

#include <stdint.h>

#include "DoubleRepresentation.h"

typedef struct
{
    uint8_t sign;
    uint32_t exponent;
    uint8_t bit63;
    uint8_t bits63_62;
    uint64_t bits62_0;
    uint64_t bits61_0;
} DoubleParts;

DoubleParts getDoubleParts(double_bit_t d);

#endif //FT_PRINTF_DOUBLECLASSIFIER_H
