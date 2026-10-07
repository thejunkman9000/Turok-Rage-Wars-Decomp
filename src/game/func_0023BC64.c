#include "b09_types.h"
extern B09SlotA D_80103F28[];
extern B09LNode D_80103B50[];
extern B09SlotCtl D_80103FA0;

s32 func_0023BC64(void) {
    s16 idx = D_80103FA0.cur++;
    if ((s16)D_80103FA0.cur >= 0x18) {
        D_80103FA0.cur = D_80103FA0.start;
    }
    if (D_80103F28[idx].a != 0xFF) {
        D_80103B50[D_80103F28[idx].a].tlb = 0xFF;
        D_80103F28[idx].a = 0xFF;
    }
    if (D_80103F28[idx].b != 0xFF) {
        D_80103B50[D_80103F28[idx].b].tlb = 0xFF;
        D_80103F28[idx].b = 0xFF;
    }
    return idx;
}
