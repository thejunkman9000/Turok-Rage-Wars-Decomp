#include "b14_types.h"


s32 func_00265508(u32 *a, s32 n, u32 key) {
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
