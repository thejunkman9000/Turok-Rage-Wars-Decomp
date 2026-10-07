#include "o03_types.h"
extern O3Pm *D_800E4400;
O3Spr *func_0040ECB0(void *p, s32 id);
void func_004215D8();
void func_00421844(void) {
    O3Spr *a;
    O3Spr *it;
    s32 t;
    t = D_800E4400->timer - 1;
    D_800E4400->timer = t;
    if (t <= 0) {
        a = func_0040ECB0(D_800E4400->w8, 0x3B8);
        D_800E4400->item->f16 = D_800E4400->item->f16 - 1;
        it = D_800E4400->item;
        if (it->f16 + a->f1A < 0) {
            it->f16 = 2;
            func_004215D8(it, D_800E4400);
        }
        D_800E4400->timer = 1;
    }
}
