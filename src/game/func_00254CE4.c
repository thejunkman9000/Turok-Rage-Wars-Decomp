#include "b12_types.h"
extern u32 D_800D0920;
extern B12Mgr D_80103F70;

void func_00254CE4(s32 unused, s32 type) {
    u32 mask = type ? ~0x400 : ~0x200;
    u32 i;
    u32 n = D_800D0920;
    for (i = 0; i < n; i++) {
        D_80103F70.nodes[i].flags &= mask;
    }
    D_80103F70.tbl11C4[type] = 0;
}
