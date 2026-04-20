#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    uint16_t num = *reg;
    uint16_t zero_bit = num & 1;
    uint16_t two_bit = (num & (1 << 2)) / 4;
    uint16_t three_bit = (num & (1 << 3)) / 8;
    uint16_t five_bit = (num & (1 << 5)) / 32;

    uint16_t complement = ((zero_bit ^ two_bit) ^ three_bit) ^ five_bit;

    *reg = (*reg >> 1) | (complement << 15);
    return;
}

