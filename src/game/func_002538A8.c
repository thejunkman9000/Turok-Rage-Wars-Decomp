#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
void func_0025114C(s32 a);
s32 func_00254AF8(s32 a, s32 b, s32 c);
void func_00251590(s32 a, s32 b);

void func_002538A8(void) {
    u32 mask;
    u32 m2;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_0025114C(0);
    while (func_00254AF8(0, 0, 0)) {
    }
    func_00251590(0, 1);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
