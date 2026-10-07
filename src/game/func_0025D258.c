
#include "b13_types.h"

s32 func_00265570(void *tab, s32 n, s16 key, s32 *lo, s32 *hi);
s32 func_00274544(void);

s32 func_0025D258(SndFx *fx, s32 key, s32 last) {
    s32 lo;
    s32 hi;
    s32 total = 0;
    s32 i;
    s32 r;
    if (func_00265570(fx->owner->unk2B60, fx->owner->unk2B64, key, &lo, &hi) == 0) {
        return -1;
    }
    if (lo != hi) {
        for (i = lo; i <= hi; i++) {
            total += 100;
        }
        r = func_00274544() % total;
        total = 0;
        for (i = lo; i < hi; i++) {
            total += 100;
            if (total >= r) {
                break;
            }
        }
        if ((s16)last != 0 && i == (s16)last) {
            if (i == hi) {
                i--;
            } else {
                i++;
            }
        }
        return i;
    }
    return lo;
}

