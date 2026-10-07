#include "b06_types.h"

s32 func_00274544();

void func_00229444(Plr *a, Plr *b) {
    s32 amount;
    s32 idx;
    s16 v;
    s32 t;
    if (b->unk5A8 == 0) {
        amount = 0xF;
        idx = func_00274544() % 3;
        v = a->unk5F4[idx];
        if (v < 0x10) {
            amount = v;
        }
        if (amount == 0) {
            func_00274544();

            for (idx = 0; idx < 3; idx++) {
                v = a->unk5F4[idx];
                if (v > 0) {
                    t = v;
                    if (amount < t) {
                        t = amount;
                    }
                    amount = t;
                }
            }
            idx = 2;
            if (amount == 0) {
                return;
            }
        }
        a->unk5F4[idx] -= amount;
        b->unk5A4 = idx;
        b->unk5A8 = amount;
    }
}
