
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

void func_002A0B74(char *base, char *max)
{
    register char *i, *j, *jj, *mid, *tmp;
    s32 ii, lo, hi;
    char c;

    lo = max - base;
    do {
        mid = i = base + qsz * ((u32)(lo / qsz) >> 1);
        if (lo >= mthresh) {
            j = ((*qcmp)((jj = base), i) > 0 ? jj : i);
            if ((*qcmp)(j, (tmp = max - qsz)) > 0) {
                j = (j == jj ? i : jj);
                if ((*qcmp)(j, tmp) < 0) {
                    j = tmp;
                }
            }
            if (j != i) {
                ii = qsz;
                do {
                    c = *i;
                    *i++ = *j;
                    *j++ = c;
                } while (--ii);
            }
        }
        for (i = base, j = max - qsz; ; ) {
            while (i < mid && (*qcmp)(i, mid) <= 0) {
                i += qsz;
            }
            while (j > mid) {
                if ((*qcmp)(mid, j) <= 0) {
                    j -= qsz;
                    continue;
                }
                tmp = i + qsz;
                if (i == mid) {
                    mid = jj = j;
                } else {
                    jj = j;
                    j -= qsz;
                }
                goto swap;
            }
            if (i == mid) {
                break;
            } else {
                jj = mid;
                tmp = mid = i;
                j -= qsz;
            }
swap:
            ii = qsz;
            do {
                c = *i;
                *i++ = *jj;
                *jj++ = c;
            } while (--ii);
            i = tmp;
        }
        i = (j = mid) + qsz;
        if ((lo = j - base) <= (hi = max - i)) {
            if (lo >= thresh) {
                func_002A0B74(base, j);
            }
            base = i;
            lo = hi;
        } else {
            if (hi >= thresh) {
                func_002A0B74(i, max);
            }
            max = j;
        }
    } while (lo >= thresh);
}

