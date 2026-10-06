#include "b23_types.h"
s32 func_002A10B0(s32 *out, u8 *base, s32 n, void *key, s32 size, s32 (*cmp)(void *, void *)) {
    s32 lo = 0, mid = 0, hi = n - 1;
    u8 *p, *q;
    s32 r, t;
    if (out != 0) {
        *out = 0;
    }
    if (n == 0) {
        return 0;
    }
    while (lo <= hi) {
        mid = (hi - lo) >> 1;
        p = base + (lo + mid) * size;
        r = cmp(key, p);
        if (r >= 0) {
            if (r == 0) {
                for (q = p - size; base < q; q -= size) {
                    if (cmp(key, q) != 0) {
                        break;
                    }
                    mid--;
                }
                if (out != 0) {
                    *out = lo + mid;
                }
                return 1;
            } else {
                lo += 1 + mid;
            }
        } else {
            hi -= 1 + mid;
        }
    }
    if (out != 0) {
        *out = lo + mid;
    }
    return 0;

}
