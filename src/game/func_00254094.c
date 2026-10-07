#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u8 D_800C8F90[];
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *h, s32 i);
void func_00254930(s32 a, s32 **n);

s32 **func_00254094(s32 unused, s32 **out, s32 id, void *arg3, s32 arg4) {
    u32 mask;
    u32 m2;
    s32 **n;
    s32 cnt;
    n = func_002518DC(0, id, id, 4, 0, 0, 0, D_800C8F90, arg4);
    if (!n) {
        return 0;
    }
    cnt = **n;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_00254930(0, n);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    n = func_002518DC(0, id, id, ((cnt * 4) + 0xF) & ~7, 0, 0, 0, arg3, arg4);
    if (!n) {
        return 0;
    }
    *out = *n;
    return n;
}
