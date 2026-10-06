#include "p2_types.h"

extern WeaponInfo2 *D_800D052C[];
extern u8 D_80121990[];
s32 func_002831FC(void *a, Player *p);

s32 func_0022EAFC(Player *p, s32 idx) {
    WeaponInfo2 *w = D_800D052C[idx];

    switch (idx) {
    case 1: case 2: case 5: case 6: case 7: case 8: case 9: case 10:
    case 11: case 13: case 14: case 15:
        return p->s5F4[w->req->idx] >= w->req->min;
    case 3:
        return p->s5F4[0] >= 3;
    case 4:
        return p->s5F4[0] >= 5;
    case 12:
        if (p->s5F4[2] != 0) {
    case 0: case 18: case 19: case 20: case 21:
            return 1;
        }
        return func_002831FC(D_80121990, p);
    case 16: case 17:
    default:
        return 0;
    }
}