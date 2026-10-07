#include "b12_types.h"
extern u32 D_800D0920;
extern B12Mgr D_80103F70;
extern s32 D_80105134;


void func_00254F3C(s32 unused, s32 type) {
    u32 mask;
    u32 i;
    u32 n;
    if (D_80103F70.tbl630[type]) {
        D_80103F70.tbl630[type] = 0;
        osSendMesg(&D_80103F70.q11F0, 0, 1);
    }
    if (type) {
        mask = ~0x400;
    } else {
        mask = ~0x200;
    }
    n = D_800D0920;
    for (i = 0; i < n; i++) {
        D_80103F70.nodes[i].flags &= mask;
    }
    *(&D_80105134 + type) = 0;
}
