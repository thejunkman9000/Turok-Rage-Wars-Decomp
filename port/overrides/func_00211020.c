/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "b03_types.h"

extern s32 (**D_800CE000[])(BrainB *);

void func_00211020(BrainB *b, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    u32 st = b->state;
    s32 (**tbl)(BrainB *);
    s32 (*fn)(BrainB *);

    if (st >= 14) {
        b->state = 0;
    }
    tbl = D_800CE000[b->state];
    if (tbl != NULL && ((fn = tbl[b->unk220]) != NULL || (b->unk220 = 0, (fn = tbl[0]) != NULL))) {
        if (((s32 (*)(BrainB *, u32, u32, u32))fn)(b, pt_a1, pt_a2, pt_a3) != 0) {
            b->unk220++;
        }
        if (b->state != st) {
            b->unk220 = 0;
        }
    }
}
