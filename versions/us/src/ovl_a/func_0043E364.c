#include "s1009_types.h"
extern void func_00265904(char *dst, u8 *fmt, s32 a);
extern s32 func_00442158(S10Item *a);
extern u8 *D_800D7670[];
extern u8 *D_800D7674[];
extern u8 *D_800D7678[];
extern u8 *D_800D767C[];
extern u8 *D_800D7680[];
extern u8 *D_800D7684[];
extern u8 D_800E2320[];
s32 func_0043E364(S10Item *a, S10Menu *m) {
    s32 n = m->ctx->sub->b83;
    if (n == 0) {
        a->f14 = D_800D7680;
    } else if (n == 10) {
        a->f14 = D_800D7684;
    } else {
        char *s;
        switch (m->ctrl->port) {
        case 0:
        default:
            a->f14 = D_800D7670;
            break;
        case 1:
            a->f14 = D_800D7674;
            break;
        case 2:
            a->f14 = D_800D7678;
            break;
        case 3:
            a->f14 = D_800D767C;
            break;
        }
        s = *(char **)a->f14;
        func_00265904(s + (func_00442158(a) - 2), D_800E2320, n);
    }
    return 0;
}
