#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
B12Node *func_00254858(s32 a, s32 b, u32 c, s32 d);

B12Node *func_002533DC(s32 unused, s32 a1, u32 a2, s32 a3) {
    u32 mask;
    u32 m2;
    B12Node *r;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    r = func_00254858(0, a1, a2, a3);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    return r;
}
