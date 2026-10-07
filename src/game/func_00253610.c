#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
void func_00254D44(s32 a, B12Node *n);

void func_00253610(s32 unused, B12Node *n) {
    u32 mask;
    u32 m2;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_00254D44(0, n);
    n->refs++;
    n->flags |= 0x100;
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
