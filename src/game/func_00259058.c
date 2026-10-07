

#include "b13_types.h"

s32 func_00265570(void *tab, s32 n, s16 key, s32 *lo, s32 *hi);
s32 func_00274544(void);

s32 func_00259058(SndMgr *m, s32 key, s32 last) {
    s32 lst;
    s32 lo;
    s32 hi;
    s32 total = 0;
    s32 i;
    s32 r;
    s32 j;
    lst = last;
    if (m->unk2B54 != 0) {
        if (func_00265570(m->unk2B58, m->unk2B54, key, &lo, &hi) != 0) {
            if (lo != hi) {
                for (j = lo; j <= hi; j++) {
                    total += m->unk2B5C[j] * 10;
                }
                r = func_00274544() % total;
                total = 0;
                for (i = lo; i < hi; i++) {
                    total += m->unk2B5C[i] * 10;
                    if (total >= r) {
                        break;
                    }
                }
                if ((s16)lst != 0 && i == m->unk130) {
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
        return -1;
    }
    return -1;
}

