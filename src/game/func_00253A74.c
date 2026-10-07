#include "b12_types.h"

extern B12Mgr D_80103F70;
extern s32 D_8010515C;

s32 func_00253A74(void) {
    u32 mask;
    u32 m2;
    s32 r;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    r = D_80103F70.tbl628[D_80103F70.f638];
    D_80103F70.f638 = -1;
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    return r;
}
