#include "o03_types.h"
extern O3Pk *D_800E3590;
extern O3Tbl D_800E3594[];
extern u8 D_800E14F8[];
extern u8 D_80102B4A[];
s32 func_00265670(void *p, s32 i);
void func_0041D9D0(void) {
    s32 i;
    i = 0;
    if (D_800E3590->cur == 0) {
        D_800E3590->tgt->txt = D_800E14F8 + 4;
    } else {
        for (; i < 0x32; i++) {
            if (D_800E3594[i].key == D_800E3590->cur->id) {
                if (func_00265670(D_80102B4A + D_800E3590->slot * 0x190, i) == 1) {
                    D_800E3590->tgt->txt = (void *)*D_800E3594[i].val;
                } else {
                    D_800E3590->tgt->txt = D_800E14F8 + 4;
                }
                break;
            }
        }
    }
}