#include "b12_types.h"

extern B12Mgr D_80103F70;
extern s32 D_8010515C;
extern OSMesgQueue D_80105140;
void func_00251590(s32 a, s32 b);

void func_auto_002532D4(void) {
    u32 mask;
    u32 m2;
    s32 i;
    if (D_80103F70.f120C != 0) {
        D_80103F70.f120C--;
    }
    D_80103F70.stamp++;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    i = 0;
    do {
        func_00251590(0, 0);
        i++;
    } while (i < 10);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
