#include "s1012_types.h"

/* reverb.c: derive the gain and the 16 coefficients of the low-pass section from its cutoff (also written out inline
   in alFxNew: the SDK build was -O3 and inlined this function there). */

void init_lpfilter(ALLowPassFx *lp) {
    s32 i, temp;
    s16 fc;
    f64 ffc, fcoef;

    temp = lp->fc * 16384;
    fc = temp >> 15;
    lp->fgain = 16384 - fc;

    lp->first = 1;
    for (i = 0; i < 8; i++)
        lp->fcoef[i] = 0;

    lp->fcoef[i++] = fc;
    fcoef = ffc = (f64)fc * 0.00006103515625;

    for (; i < 16; i++) {
        fcoef *= ffc;
        lp->fcoef[i] = (s16)(fcoef * 16384.0);
    }
}
