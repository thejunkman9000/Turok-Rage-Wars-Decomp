#include "b03_types.h"

extern s32 (**D_800CE000[])(BrainB *);

void func_00211020(BrainB *b) {
    u32 st = b->state;
    s32 (**tbl)(BrainB *);
    s32 (*fn)(BrainB *);

    if (st >= 14) {
        b->state = 0;
    }
    tbl = D_800CE000[b->state];
    if (tbl != NULL && ((fn = tbl[b->unk220]) != NULL || (b->unk220 = 0, (fn = tbl[0]) != NULL))) {
        if (fn(b) != 0) {
            b->unk220++;
        }
        if (b->state != st) {
            b->unk220 = 0;
        }
    }
}
