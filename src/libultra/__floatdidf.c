#include "common.h"

#define WORD_SIZE 32
#define HIGH_WORD_COEFF (((u64) 1) << WORD_SIZE)
#define HIGH_HALFWORD_COEFF (((u64) 1) << (WORD_SIZE / 2))

f64 __floatdidf(s64 u) {
    register f64 d;
    s32 negate = 0;

    if (u < 0)
        u = -u, negate = 1;

    d = (u32)(u >> WORD_SIZE);
    d *= HIGH_HALFWORD_COEFF;
    d *= HIGH_HALFWORD_COEFF;
    d += (u32)(u & (HIGH_WORD_COEFF - 1));

    return (negate ? -d : d);
}

