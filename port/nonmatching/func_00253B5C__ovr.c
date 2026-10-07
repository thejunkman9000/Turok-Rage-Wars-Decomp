#include "b12_types.h"
#include "libaudio.h"

extern B12Mgr D_80103F70;
extern OSMesgQueue D_80105140;
extern s32 D_8010515C;

void func_00253B5C(s32 unused, B12Node *n) {
    if (!n) return;   /* port: audio objects are not created yet */
    u32 mask;
    u32 m2;
    s32 idx = D_80103F70.f638;
    u32 bit;
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    if (D_80103F70.tbl628[idx]) {
        if (idx) {
            bit = 0x400;
        } else {
            bit = 0x200;
        }
        if (!(n->flags & bit)) {
            n->flags |= bit;
            D_80103F70.tbl11C4[idx]++;
        }
    }
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
