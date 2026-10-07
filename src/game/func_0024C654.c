#include "b11_types.h"

extern B11PlayerList D_80145040[];
extern u8 D_800CFB04[];
extern u8 *D_800D0680[];

u8 *func_0024C654(Obj *a) {
    u32 t = a->def->type;
    s32 i;
    if (t >= 15) {
        return 0;
    }
    if (t == 11) {
        for (i = 0; i < D_80145040->count; i++) {
            u8 *p = D_80145040->head + i * 0x16E8;
            if (p == (u8 *)a) {
                return 0;
            }
            if (p + 0x2E8 == (u8 *)a) {
                return D_800CFB04;
            }
        }
    }
    return D_800D0680[t];
}
