#include "veu3n10_types.h"
#include "s1009_types.h"
extern void func_00265904(char *dst, u8 *fmt, s32 a);
extern s32 func_auto_00442EE0(S10Item *a);
extern u8 D_auto_800E23A4[], D_auto_800E23B4[], D_auto_800E2364[], D_auto_800E2374[], D_auto_800E2384[], D_eu_800E2394[];
extern u8 D_auto_80152789;

/* "NN" text of a 2-digit option value (EU: the line index is added through D_80152789) */
s32 func_auto_0043F074(S10Item *a, S10Menu *m) {
    s32 n = m->ctx->sub->b83;
    if (n == 0) {
        a->f14 = D_auto_800E23A4;
    } else if (n == 10) {
        a->f14 = D_auto_800E23B4;
    } else {
        char *s;
        switch (m->ctrl->port) {
        case 0:
        default:
            a->f14 = D_auto_800E2364;
            break;
        case 1:
            a->f14 = D_auto_800E2374;
            break;
        case 2:
            a->f14 = D_auto_800E2384;
            break;
        case 3:
            a->f14 = D_eu_800E2394;
            break;
        }
        s = ((char **)a->f14)[D_auto_80152789];
        func_00265904(s + (func_auto_00442EE0(a) - 2), "%02d", n);
    }
    return 0;
}
