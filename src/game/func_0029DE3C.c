#include "b22_types.h"
void func_0029DE3C(B22Mtx *d, B22Mtx *a, B22Mtx *b)
{
    B22Mtx tmp;
    s32 i;
    f32 *dp, *ap, *bp;
    if (d == a) {
        tmp = *d;
        if (a == b) {
            b = &tmp;
        }
        a = &tmp;
    } else if (d == b) {
        tmp = *d;
        b = &tmp;
    }
    ap = &a->m[0][0];
    dp = &d->m[0][0];
    bp = &b->m[0][0];
    for (i = 0; i < 4; i++) {
        dp[0] = ap[0] * bp[0] + ap[4] * bp[1] + ap[8] * bp[2] + ap[12] * bp[3];
        dp[1] = ap[1] * bp[0] + ap[5] * bp[1] + ap[9] * bp[2] + ap[13] * bp[3];
        dp[2] = ap[2] * bp[0] + ap[6] * bp[1] + ap[10] * bp[2] + ap[14] * bp[3];
        dp[3] = ap[3] * bp[0] + ap[7] * bp[1] + ap[11] * bp[2] + ap[15] * bp[3];
        dp += 4;
        bp += 4;
    }

}

