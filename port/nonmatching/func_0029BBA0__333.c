#include "b22_types.h"
extern double D_800CA850;
#define HI(x) (((u32 *)&(x))[0])
#define LO(x) (((u32 *)&(x))[1])
double func_0029BBA0(double x, s32 n);
double func_0029BBA0(double x, s32 n)
{
    u32 hx, k, t;
    hx = HI(x);
    k = (hx >> 20) & 0x7FF;
    if (k != 0) {
        if (k < 0x7FF) {
            k += n;
            if (k != 0) {
                if (k < 0x7FF) {
                    HI(x) = (hx & 0x800FFFFF) | ((k & 0x7FF) << 20);
                    return x;
                }
                if (n >= 0) {
                    goto overflow;
                }
                if (k < (u32)-0x35) {
                    HI(x) = 0;
                    LO(x) = 0;
                    HI(x) = HI(x) & 0x7FFFFFFF;
                    HI(x) = HI(x) | ((hx >> 31) << 31);
                    return x;
                }
            }
            k = k - 1;
            HI(x) = (HI(x) & 0x800FFFFF) | 0x100000;
            x = x * func_0029BBA0(1.0, k);
            return x;
        }
        if ((hx & 0xFFFFF) != 0 || LO(x) != 0) {
            return x;
        }
        if (n >= 0) {
overflow:
            t = HI(x);
            x = D_800CA850;
            HI(x) = (t & 0x7FFFFFFF) | ((hx >> 31) << 31);
            return D_800CA850;
        }
        HI(x) = hx & 0x7FFFFFFF;
        HI(x) = HI(x) | ((hx >> 31) << 31);
        return x;
    }
    if ((hx & 0xFFFFF) == 0 && LO(x) == 0) {
        return x;
    }
    return func_0029BBA0(x * func_0029BBA0(1.0, 0x35), n - 0x35);
}
