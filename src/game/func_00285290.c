#include "common.h"
void func_00285484(u8 *, u8 *, u32, s32 (*)(), void (*)());
void func_00285290(u8 *base, u32 n, u32 size, s32 (*cmp)(), void (*swap)()) {
    u8 *lo;
    u8 *hi;
    u8 *i;
    u8 *j; u8 *lo1;
    s32 sp;
    u32 cnt;
    u8 *stk_lo[30];
    u8 *stk_hi[30];
    if (n < 2) return;
    if (size == 0) return;
    sp = 0;
    lo = base;
    hi = lo + size * (n - 1);
top:
    cnt = (hi - lo) / size + 1;
    if (cnt < 9) {
        func_00285484(lo, hi, size, cmp, swap);
    } else {
        swap(lo + (cnt >> 1) * size, lo);
        i = lo;
        j = hi + size;
        for (;;) {
            do { i += size; } while (i <= hi && cmp(i, lo) <= 0);
            do { j -= size; } while (j > lo && cmp(j, lo) >= 0);
            if (j < i) break;
            swap(i, j);
        }
        swap(lo, j); lo1 = lo + 1;
        if (!((j - lo1) < (hi - i))) { 
            if (lo + size < j) {
                stk_lo[sp] = lo;
                stk_hi[sp] = j - size;
                sp++;
            }
            if (i < hi) {
                lo = i;
                goto top;
            }
        } else {
            if (i < hi) {
                stk_lo[sp] = i;
                stk_hi[sp] = hi;
                sp++;
            }
            if (lo + size < j) {
                hi = j - size;
                goto top;
            }
        }
    }
    sp--;
    if (sp < 0) return;
    lo = stk_lo[sp];
    hi = stk_hi[sp];
    goto top;
}
