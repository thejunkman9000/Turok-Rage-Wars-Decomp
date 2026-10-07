#include "b14_types.h"
static inline s32 b14_bsearch(u32 *a, s32 n, u32 key) {
    u32 lo, hi, mid;
    if (n != 0) {
        hi = n - 1;
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (a[mid] < key) { lo = mid + 1; } else { hi = mid; }
        }
        if (a[lo] == key) { return lo; }
        return -1;
    }
    return -1;
}
s32 func_00265570(u32 *a, s32 n, u32 key, s32 *first, s32 *last) {
    s32 idx = b14_bsearch(a, n, key);
    s32 j, k;
    if (idx == -1) {
        return 0;
    }
    for (j = idx - 1; j != -1 && a[j] == key; j--) {
    }
    *first = j + 1;
    for (k = idx + 1; k < n && a[k] == key; k++) {
    }
    *last = k - 1;
    return 1;
}
