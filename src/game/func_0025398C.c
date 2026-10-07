#include "b12_types.h"

extern B12Mgr D_80103F70;
extern s32 D_8010515C;

void func_0025398C(s32 unused, s32 idx) {
    u32 mask;
    u32 m2;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    D_80103F70.f638 = idx;
    D_80103F70.tbl628[idx] = 1;
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
