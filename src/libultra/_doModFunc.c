#include "s1013_types.h"

/* _doModFunc (libaudio reverb.c): advance the chorus sawtooth by rsinc per sample, wrap it from +2.0 (RANGE), fold
   it into a triangle and return it scaled by rsgain.  The ternary spelling is what the ROM has (the if-statement
   version is one insn shorter: no mov.s copies). */
f32 _doModFunc(S13Delay *d, s32 count)
{
    f32 val;

    d->rsval += d->rsinc * count;
    d->rsval = (d->rsval > 2.0f) ? d->rsval - 4.0f : d->rsval;
    val = d->rsval;
    val = (val < 0) ? -val : val;
    val -= 1.0f;
    return d->rsgain * val;
}
