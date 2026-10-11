#include "common.h"

#define WORD_SIZE 32
#define HIGH_WORD_COEFF (((u64) 1) << WORD_SIZE)
#define HIGH_HALFWORD_COEFF (((u64) 1) << (WORD_SIZE / 2))

f32 __floatdisf(s64 u) {
    f64 f;
    s32 negate = 0;

    if (u < 0)
        u = -u, negate = 1;

    if ((u64)u >= ((u64)1 << 53)) {
        if ((u32)u & (((u64)1 << 11) - 1))
            u |= ((u64)1 << 11);
    }
    f = (u32)(u >> WORD_SIZE);
    f *= HIGH_HALFWORD_COEFF;
    f *= HIGH_HALFWORD_COEFF;
    f += (u32)(u & (HIGH_WORD_COEFF - 1));

    return (negate ? -f : f);
}
