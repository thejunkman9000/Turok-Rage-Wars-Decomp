#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;

void func_00253E04(s32 unused, B12Node **p, B12Node *n) {
    u32 mask;
    u32 m2;
    B12Node *a;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    a = p[0];
    if (a) {
        a->refs--;
        if (a->refs == 0) {
            a->flags &= ~0x100;
        }
    }
    a = p[1];
    if (a) {
        a->refs--;
        if (a->refs == 0) {
            a->flags &= ~0x100;
        }
    }
    p[0] = n;
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
