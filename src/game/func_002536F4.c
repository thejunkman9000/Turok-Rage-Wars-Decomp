#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;

void func_002536F4(s32 unused, B12Node *n) {
    u32 mask;
    u32 m2;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    n->refs--;
    if (n->refs == 0) {
        n->flags &= ~0x100;
    }
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
