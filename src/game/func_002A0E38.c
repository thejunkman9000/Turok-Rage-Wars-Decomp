
#include "common.h"

#define THRESH 4
#define MTHRESH 6

extern s32 D_8014D0C0;
extern s32 D_8014D0C4;
extern s32 D_8014D0C8;
extern s32 (*D_8014D0CC)();

#define qsz D_8014D0C0
#define thresh D_8014D0C4
#define mthresh D_8014D0C8
#define qcmp D_8014D0CC

void func_002A0B74(char *base, char *max);

void func_002A0E38(char *base, s32 n, s32 size, s32 (*compar)())
{
    register char *i, *j, *lo, *hi, *min;
    register char c;
    char *max;

    if (n <= 1) {
        return;
    }
    qsz = size;
    qcmp = compar;
    thresh = qsz * THRESH;
    mthresh = qsz * MTHRESH;
    max = base + n * qsz;
    if (n >= THRESH) {
        func_002A0B74(base, max);
        hi = base + thresh;
    } else {
        hi = max;
    }
    for (j = lo = base; (lo += qsz) < hi; ) {
        if ((*qcmp)(j, lo) > 0) {
            j = lo;
        }
    }
    if (j != base) {
        for (i = base, hi = base + qsz; i < hi; ) {
            c = *j;
            *j++ = *i;
            *i++ = c;
        }
    }
    for (min = base; (hi = min += qsz) < max; ) {
        while ((*qcmp)(hi -= qsz, min) > 0) {
            ;
        }
        if ((hi += qsz) != min) {
            for (lo = min + qsz; --lo >= min; ) {
                c = *lo;
                for (i = j = lo; (j -= qsz) >= hi; i = j) {
                    *i = *j;
                }
                *i = c;
            }
        }
    }
}

